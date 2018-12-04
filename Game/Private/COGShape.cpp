#include "..\Public\COGShape.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\GameObject.h"

std::vector<COGShape*> COGShape::mShapeComponents;

COGShape::COGShape(GameObject * pGO)
	: Component(pGO)
{
}

void COGShape::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	
	AddToComponentVector(mShapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(mShapeComponents);
}
