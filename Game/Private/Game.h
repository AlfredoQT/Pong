//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game\Public\Singleton.h"
#include <vector>

class COGScorer;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface, public Singleton<MyGame>
{
public:

	MyGame();
	virtual						~MyGame();

	virtual void				Initialize(exEngineInterface* pEngine);

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor(exColor& color) const;

	virtual void				OnEvent(SDL_Event* pEvent);
	virtual void				OnEventsConsumed();

	virtual void				Run(float fDeltaT);

private:

	class World* mWorld;

	// Scores
	COGScorer* mLeftScorer;
	COGScorer* mRightScorer;

	// To draw some simple UI
	void DrawUI() const;

	// Font
	int mFontID;

};
