#pragma once

#include "Singleton.h"

class World;
class GameObject;
struct Vector2;

class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObject * CreatePaddle(World* pWorld, float pWidth, float pHeight, int pPlayerIndex, Vector2 pInitialPosition, bool pIsAI);

	GameObject * CreateBall(World*pWorld, float pRadius, Vector2 pInitialPosition, Vector2 pInitialVelocity);

	GameObject * CreateWall(World*pWorld, float pWidth, float pHeight, Vector2 pInitialPosition, bool pIsScorer);

};
