#include "..\Public\COGBounce.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\COGTransform.h"

COGBounce::COGBounce(GameObject * pGO)
	: Component(pGO)
{
}

ComponentType COGBounce::GetType() const
{
	return ComponentType::Bounce;
}

void COGBounce::OnCollision(COGPhysics * pMe, COGPhysics * pOther, CollisionInfo pInfo)
{
	Vector2& newVelocity = pMe->GetVelocity();

	// Move the object using the penetration depth so that the velocity, which is set using the reflection equation, allows it to escape
	Vector2& newPosition = pMe->GetOwner()->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
	newPosition = newPosition - pInfo.penetrationDepth;

	float dotProductVN = newVelocity | pInfo.normal;

	// This case happens when the paddle hits the ball, instead of the ball bouncing with the paddle
	if (dotProductVN > 0)
	{
		// Flip the normal
		Vector2 newNormal = Vector2(pInfo.normal.y, pInfo.normal.x);

		// Super awesome bounce
		newVelocity = newVelocity - newNormal * 2.0f * (newVelocity | newNormal);

		Vector2 rV = pOther->GetVelocity() - pMe->GetVelocity();

		return;
	}

	// Super awesome bounce
	newVelocity = newVelocity - pInfo.normal * 2.0f * (newVelocity | pInfo.normal);
	
}
