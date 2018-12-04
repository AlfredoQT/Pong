#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "..\Public\COGShape.h"
#include "..\Public\COGPhysics.h"
#include "Game\Public\COGPaddleController.h"

World::World(exEngineInterface* pEngine)
{
	mEngine = pEngine;
}

void World::Initialize()
{
	for (GameObject* pGameObject : mGameObjects)
	{
		pGameObject->Initialize();
	}
}

void World::Destroy()
{
	for (GameObject* pGameObject : mGameObjects)
	{
		delete pGameObject;
	}

	mGameObjects.clear();
}

void World::Update(float fDeltaT)
{
	// run simulation first
	for (COGPhysics* pPhysics : COGPhysics::mPhysicsComponents)
	{
		pPhysics->Update(fDeltaT);
	}

	// then render everything
	for (COGShape* pShape : COGShape::mShapeComponents)
	{
		pShape->Render();
	}

	// Controllers
	for (COGPaddleController* pC : COGPaddleController::mPaddleControllerComponents)
	{
		pC->Update(fDeltaT);
	}
}

void World::Add(GameObject * pGO)
{
	mGameObjects.push_back(pGO);
}

exEngineInterface * World::Engine() const
{
	return mEngine;
}
