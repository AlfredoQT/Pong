#pragma once

#include "..\Public\COGPaddleController.h"
#include "..\Public\Vector2.h"

class COGPhysics;
class COGBoxShape;
class COGTransform;

// COGPhysics - lets move around
class COGPlayerController : public COGPaddleController
{
public:

	COGPlayerController(GameObject* pGO, int pPlayerIndex);

	virtual ComponentType GetType() const override;

	virtual void Update(float fDeltaT) override;

private:

	int mPlayerIndex;

};
