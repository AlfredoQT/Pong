#pragma once

#include "..\Public\Component.h"
#include "..\Public\Vector2.h"

class COGTransform;
class COGBoxShape;
class COGCircleShape;
class IPhysicsCollisionEvent;

struct CollisionInfo;

// COGPhysics - lets move around
class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

public:

	COGPhysics(GameObject* pGO, bool bGenerateCollisionEvents);

	virtual ComponentType GetType() const override;

	virtual void Initialize() override;

	virtual void Destroy() override;

	virtual void Update(float fDeltaT);

	bool IsColliding(COGPhysics* pOther, CollisionInfo& pInfo);

	void AddCollisionEvent(IPhysicsCollisionEvent* event);

	Vector2& GetVelocity();

private:

	COGTransform* mTransform;
	COGBoxShape* mBoxShape;
	COGCircleShape* mCircleShape;

	Vector2 mVelocity;

	bool mGenerateCollisionEvents;
	std::vector<IPhysicsCollisionEvent*> mCollisionEventListeners;

};
