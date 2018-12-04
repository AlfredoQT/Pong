#include "..\Public\COGAIController.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\COGBoxShape.h"
#include "Engine\Public\EngineInterface.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\Debug.h"

COGAIController::COGAIController(GameObject * pGO)
	: COGPaddleController(pGO)
{
}

void COGAIController::SetBall(COGTransform * pBall)
{
	mBall = pBall;
}

ComponentType COGAIController::GetType() const
{
	return ComponentType::AIController;
}

void COGAIController::Update(float fDeltaT)
{
	// Dead simple AI
	bool up = mTransform->GetPosition().y >= mBall->GetPosition().y;
	bool down = mTransform->GetPosition().y < mBall->GetPosition().y;

	// Wall collisions
	bool onTop = mTransform->GetPosition().y - mBoxShape->GetHeight() / 2.0f <= 0.0f;
	bool onBottom = mTransform->GetPosition().y + mBoxShape->GetHeight() / 2.0f >= kViewportHeight;

	// Don't make it move in case of collision
	up = up && !onTop;
	down = down && !onBottom;

	// Same as the player controller
	Vector2& newVelocity = mPhysics->GetVelocity();
	newVelocity.y = up ? -150.0f : down ? 150.0f : 0.0f;
}
