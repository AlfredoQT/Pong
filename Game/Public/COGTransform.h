#pragma once

#include "..\Public\Component.h"
#include "..\Public\Vector2.h"

// COGTransform - where we are in space
class COGTransform : public Component
{
public:

	COGTransform(GameObject* pGO);

	virtual ComponentType GetType() const override;

	Vector2& GetPosition();

private:

	Vector2 mPosition;

};
