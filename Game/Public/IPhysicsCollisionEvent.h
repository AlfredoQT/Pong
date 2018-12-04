#pragma once

#include "Vector2.h"

// Store the information of the collision
struct CollisionInfo
{
	Vector2 normal;
	Vector2 penetrationDepth;
};

// our interface that allows COGPhysics to talk to anyone
class COGPhysics;

class IPhysicsCollisionEvent
{
public:

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther, CollisionInfo pInfo) = 0;

};
