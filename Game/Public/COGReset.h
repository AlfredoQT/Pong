#pragma once

#include "..\Public\Component.h"
#include "..\Public\IPhysicsCollisionEvent.h"

struct Vector2;

// COGReset - Where we reset ball and updated some score
class COGReset : public Component, public IPhysicsCollisionEvent
{
public:

	COGReset(GameObject* pGO);

	virtual ComponentType GetType() const;

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther, CollisionInfo pInfo) override;

};

