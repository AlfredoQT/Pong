#include "..\Public\COGPhysics.h"
#include "..\Public\GameObject.h"
#include "..\Public\COGTransform.h"
#include "..\Public\COGBoxShape.h"
#include "..\Public\COGCircleShape.h"
#include "..\Public\IPhysicsCollisionEvent.h"
#include "Game\Public\COGBounce.h"
#include "Engine\Public\EngineInterface.h"
#include "Game\Public\World.h"
#include "Game\Public\FMath.h"

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;

COGPhysics::COGPhysics(GameObject * pGO, bool bGenerateCollisionEvents)
	: Component(pGO)
	, mGenerateCollisionEvents(bGenerateCollisionEvents)
{
}

ComponentType COGPhysics::GetType() const
{
	return ComponentType::Physics;
}

void COGPhysics::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	mBoxShape = mGO->FindComponent<COGBoxShape>(ComponentType::BoxShape);
	mCircleShape = mGO->FindComponent<COGCircleShape>(ComponentType::CircleShape);

	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update(float fDeltaT)
{
	// integrate velocity
	Vector2& myPosition = mTransform->GetPosition();

	myPosition.x += mVelocity.x * fDeltaT;
	myPosition.y += mVelocity.y * fDeltaT;

	// check collisions
	if (mGenerateCollisionEvents)
	{
		for (COGPhysics* pPhysicsOther : COGPhysics::mPhysicsComponents)
		{
			// do not collide with self
			if (pPhysicsOther == this)
			{
				continue;
			}

			CollisionInfo info;

			const bool bResult = IsColliding(pPhysicsOther, info);

			if (bResult)
			{
				for (IPhysicsCollisionEvent* pCollisionEventListener : mCollisionEventListeners)
				{
					pCollisionEventListener->OnCollision(this, pPhysicsOther, info);
				}
			}
		}
	}
}

bool COGPhysics::IsColliding(COGPhysics * pOther, CollisionInfo& pInfo)
{
	if (mCircleShape != nullptr && pOther->mBoxShape != nullptr)
	{
		// Get the position of other
		Vector2 otherPosition = pOther->mTransform->GetPosition();

		// Find the point of the box closest to the center of the circle
		float nearestX = FMath::Clamp(mTransform->GetPosition().x, otherPosition.x - pOther->mBoxShape->GetWidth() / 2.0f, otherPosition.x + pOther->mBoxShape->GetWidth() / 2.0f);
		float nearestY = FMath::Clamp(mTransform->GetPosition().y, otherPosition.y - pOther->mBoxShape->GetHeight() / 2.0f, otherPosition.y + pOther->mBoxShape->GetHeight() / 2.0f);

		// Check if the point is inside the circle
		Vector2 centerToClosest = Vector2(nearestX, nearestY) - mTransform->GetPosition();

		bool colliding = centerToClosest.SizeSquared() < mCircleShape->GetRadius() * mCircleShape->GetRadius();

		// Update the normal
		Vector2 dir = centerToClosest.Normalized();
		pInfo.normal = colliding ? dir * -1.0f : Vector2();

		/// Penetration depth stuff, I don't know if this is the right way to do it, but this is the way I figure it out. I feel like a genius btw

		// The same as centerToClosest, but its just clamp the circumference of the ballss
		Vector2 centerToClosestClampedToCircumference = centerToClosest.Normalized() * mCircleShape->GetRadius();

		// Compute the penetration info
		pInfo.penetrationDepth = colliding ? centerToClosestClampedToCircumference - centerToClosest : Vector2();

		return colliding;
	}

	// we don't cover the other cases
	// maybe assert here?

	return false;
}

void COGPhysics::AddCollisionEvent(IPhysicsCollisionEvent * event)
{
	mCollisionEventListeners.push_back(event);
}

Vector2 & COGPhysics::GetVelocity()
{
	return mVelocity;
}
