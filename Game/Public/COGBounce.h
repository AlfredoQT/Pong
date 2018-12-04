#pragma once

#include "..\Public\Component.h"
#include "..\Public\IPhysicsCollisionEvent.h"

struct Vector2;

// COGBounce - where we make the ball bounce
class COGBounce : public Component, public IPhysicsCollisionEvent
{
public:

	COGBounce(GameObject* pGO);

	virtual ComponentType GetType() const;

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther, CollisionInfo pInfo) override;

};
