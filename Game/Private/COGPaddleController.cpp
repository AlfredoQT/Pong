#include "..\Public\COGPaddleController.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGBoxShape.h"
#include "Game\Public\COGTransform.h"

std::vector<COGPaddleController*> COGPaddleController::mPaddleControllerComponents;

COGPaddleController::COGPaddleController(GameObject * pGO)
	: Component(pGO)
{
}

ComponentType COGPaddleController::GetType() const
{
	return ComponentType::PaddleController;
}

void COGPaddleController::Initialize()
{
	mPhysics = mGO->FindComponent<COGPhysics>(ComponentType::Physics);
	mBoxShape = mGO->FindComponent<COGBoxShape>(ComponentType::BoxShape);
	mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);

	AddToComponentVector(mPaddleControllerComponents);
}

void COGPaddleController::Destroy()
{
	RemoveFromComponentVector(mPaddleControllerComponents);
}
