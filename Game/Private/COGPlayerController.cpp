#include "..\Public\COGPlayerController.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGBoxShape.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\Input.h"
#include "Engine\Public\EngineInterface.h"

COGPlayerController::COGPlayerController(GameObject * pGO, int pPlayerIndex)
	: COGPaddleController(pGO)
{
	mPlayerIndex = pPlayerIndex;
}

ComponentType COGPlayerController::GetType() const
{
	return ComponentType::PlayerController;
}

void COGPlayerController::Update(float fDeltaT)
{
	Vector2& velocity = mPhysics->GetVelocity();

	bool up = false;
	bool down = false;

	// Input based on player controller index
	if (mPlayerIndex == 0)
	{
		up = Input::Instance()->IsKeyDown(KeyCode::W);
		down = Input::Instance()->IsKeyDown(KeyCode::S);
	}
	else if (mPlayerIndex == 1)
	{
		up = Input::Instance()->IsKeyDown(KeyCode::UpArrow);
		down = Input::Instance()->IsKeyDown(KeyCode::DownArrow);
	}

	// Wall collisions
	bool onTop = mTransform->GetPosition().y - mBoxShape->GetHeight() / 2.0f <= 0.0f;
	bool onBottom = mTransform->GetPosition().y + mBoxShape->GetHeight() / 2.0f >= kViewportHeight;

	// Only listen if not colliding
	up = up && !onTop;
	down = down && !onBottom;

	// Update velocity
	velocity.y = up ? -150.0f : down ? 150.0f : 0.0f;
}
