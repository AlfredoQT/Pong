#include "..\Public\GameObjectFactory.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\COGBoxShape.h"
#include "Game\Public\COGCircleShape.h"
#include "Game\Public\COGAIController.h"
#include "Game\Public\COGPlayerController.h"
#include "Game\Public\COGBounce.h"
#include "Game\Public\COGReset.h"
#include "Game\Public\COGScorer.h"
#include "Game\Public\World.h"

// Singleton
GameObjectFactory* Singleton<GameObjectFactory>::mSingleton = nullptr;

GameObject * GameObjectFactory::CreatePaddle(World* pWorld, float pWidth, float pHeight, int pPlayerIndex, Vector2 pInitialPosition, bool pIsAI)
{
	GameObject* pPaddle = new GameObject(pWorld);

	COGTransform* pTransform = new COGTransform(pPaddle);
	pPaddle->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pPaddle, pWidth, pHeight);
	pPaddle->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pPaddle, false);
	pPaddle->AddComponent(pPhysics);

	if (pIsAI)
	{
		pPaddle->AddComponent(new COGAIController(pPaddle));
	}
	else
	{

		pPaddle->AddComponent(new COGPlayerController(pPaddle, pPlayerIndex));
	}

	Vector2& position = pTransform->GetPosition();
	position = pInitialPosition;

	pWorld->Add(pPaddle);

	return pPaddle;
}

GameObject * GameObjectFactory::CreateBall(World* pWorld, float pRadius, Vector2 pInitialPosition, Vector2 pInitialVelocity)
{

	GameObject* pBall = new GameObject(pWorld);

	COGTransform* pTransform = new COGTransform(pBall);
	pBall->AddComponent(pTransform);

	COGCircleShape* pCircleShape = new COGCircleShape(pBall, pRadius);
	pBall->AddComponent(pCircleShape);

	COGPhysics* pPhysics = new COGPhysics(pBall, true);
	pBall->AddComponent(pPhysics);

	Vector2& position = pTransform->GetPosition();
	position = pInitialPosition;

	Vector2& velocity = pPhysics->GetVelocity();
	velocity = pInitialVelocity;

	// Add the collision listeners
	pPhysics->AddCollisionEvent(new COGBounce(pBall));
	pPhysics->AddCollisionEvent(new COGReset(pBall));

	pWorld->Add(pBall);

	return pBall;
}

GameObject * GameObjectFactory::CreateWall(World* pWorld, float pWidth, float pHeight, Vector2 pInitialPosition, bool pIsScorer)
{
	GameObject* pWall = new GameObject(pWorld);

	COGTransform* pTransform = new COGTransform(pWall);
	pWall->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pWall, pWidth, pHeight);
	pWall->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pWall, false);
	pWall->AddComponent(pPhysics);

	Vector2& position = pTransform->GetPosition();
	position = pInitialPosition;

	// Scorer
	if (pIsScorer)
	{
		COGScorer* scorer = new COGScorer(pWall);
		pWall->AddComponent(scorer);
	}

	pWorld->Add(pWall);

	return pWall;
}
