//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\Debug.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGAIController.h"
#include "Game\Public\COGScorer.h"
#include "Game\Public\GameObjectFactory.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\Random.h"
#include <string>

// Game singleton
MyGame* Singleton<MyGame>::mSingleton = nullptr;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mFontID(-1)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
	mWorld = new World(pEngine);

	mFontID = pEngine->LoadFont("04B_20.ttf", 32);

	GameObject* fPaddle = GameObjectFactory::Instance()->CreatePaddle(mWorld, 15.0f, 125.0f, 0, Vector2(70.0f, kViewportHeight / 2.0f), false);
	GameObject* sPaddle = GameObjectFactory::Instance()->CreatePaddle(mWorld, 15.0f, 125.0f, 1, Vector2(kViewportWidth - 70.0f, kViewportHeight / 2.0f), false);

	Vector2 ballVelocity = Vector2(Random::Instance()->NextFloat(-1.0f, 1.0f), Random::Instance()->NextFloat(-1.0f, 1.0f)).Normalized() * 400.0f;
	GameObject* ball = GameObjectFactory::Instance()->CreateBall(mWorld, 12.0f, Vector2(kViewportWidth / 2.0f, kViewportHeight / 2.0f), ballVelocity);

	// Transform of ball
	COGTransform* bTransform = ball->FindComponent<COGTransform>(ComponentType::Transform);

	// Setup AI controllers
	COGAIController* fPAI = fPaddle->FindComponent<COGAIController>(ComponentType::AIController);
	if (fPAI != nullptr) { fPAI->SetBall(bTransform); }
	COGAIController* sPAI = sPaddle->FindComponent<COGAIController>(ComponentType::AIController);
	if (sPAI != nullptr) { sPAI->SetBall(bTransform); }

	GameObject* tWall = GameObjectFactory::Instance()->CreateWall(mWorld, kViewportWidth, 1.0f, Vector2(kViewportWidth / 2.0f, 0.0f), false);
	GameObject* rWall = GameObjectFactory::Instance()->CreateWall(mWorld, 1.0f, kViewportHeight, Vector2(kViewportWidth, kViewportHeight / 2.0f), true);
	GameObject* dWall = GameObjectFactory::Instance()->CreateWall(mWorld, kViewportWidth, 1.0f, Vector2(kViewportWidth / 2.0f, kViewportHeight), false);
	GameObject* lWall = GameObjectFactory::Instance()->CreateWall(mWorld, 1.0f, kViewportHeight, Vector2(0.0f, kViewportHeight / 2.0f), true);

	// Setup the scorers
	mLeftScorer = lWall->FindComponent<COGScorer>(ComponentType::Scorer);
	mRightScorer = rWall->FindComponent<COGScorer>(ComponentType::Scorer);

	mWorld->Initialize();
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor(exColor& color) const
{
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent(SDL_Event* pEvent)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
	// Update the input manager
	InputManager::Instance()->Update();

	// Update the world
	mWorld->Update(fDeltaT);

	// Draw the UI, I could've put this in a UI manager but it's so simple
	DrawUI();

	// This will cause the delay and keep outdated versions of current mouse buttons' states inside prev mouse buttons' states
	InputManager::Instance()->LateUpdate();
}

void MyGame::DrawUI() const
{
	/// The dividing rectangle
	Vector2 center = Vector2(kViewportWidth / 2.0f, kViewportHeight / 2.0f);

	exColor white;
	white.mColor[0] = 255;
	white.mColor[1] = 255;
	white.mColor[2] = 255;
	white.mColor[3] = 255;

	mWorld->Engine()->DrawBox(Vector2(center.x - 5.0f, 15.0f), Vector2(center.x + 5.0f, kViewportHeight - 15.0f), white, 0);

	/// The scores
	mWorld->Engine()->DrawText(mFontID, Vector2(center.x - 100.0f, 20.0f), std::to_string(mRightScorer->GetScore()).c_str(), white, 0);
	mWorld->Engine()->DrawText(mFontID, Vector2(center.x + 50.0f, 20.0f), std::to_string(mLeftScorer->GetScore()).c_str(), white, 0);

}
