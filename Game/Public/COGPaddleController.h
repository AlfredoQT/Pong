#pragma once

#include "..\Public\Component.h"
#include "..\Public\Vector2.h"

class COGPhysics;
class COGBoxShape;
class COGTransform;

class COGPaddleController : public Component
{
public:

	static std::vector<COGPaddleController*> mPaddleControllerComponents;

public:

	COGPaddleController(GameObject* pGO);

	virtual ComponentType GetType() const override;

	virtual void Initialize() override;

	virtual void Destroy() override;

	virtual void Update(float fDeltaT) = 0;

protected:

	COGPhysics * mPhysics;
	COGBoxShape * mBoxShape;
	COGTransform * mTransform;

};

