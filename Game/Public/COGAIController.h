#pragma once

#include "..\Public\COGPaddleController.h"
#include "..\Public\Vector2.h"

class COGPhysics;
class COGBoxShape;
class COGTransform;

// COGPhysics - lets move around
class COGAIController : public COGPaddleController
{
public:

	COGAIController(GameObject* pGO);

	void SetBall(COGTransform* pBall);

	virtual ComponentType GetType() const override;

	virtual void Update(float fDeltaT) override;

private:

	COGTransform* mBall;

};

