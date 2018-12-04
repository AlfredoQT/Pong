#pragma once

#include "..\Public\Component.h"

class COGTransform;

// COGShape - our baseclass for shapes
class COGShape : public Component
{
public:

	static std::vector<COGShape*> mShapeComponents;

public:

	COGShape(GameObject* pGO);

	virtual void Initialize() override;

	virtual void Destroy() override;

	virtual void Render() = 0;

protected:

	COGTransform * mTransform;

	// TODO - add a color variable here!

};

