#include "..\Public\COGCircleShape.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\EngineInterface.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGTransform.h"

COGCircleShape::COGCircleShape(GameObject * pGO, float pRadius)
	: COGShape(pGO)
	, mRadius(pRadius)
{
}

ComponentType COGCircleShape::GetType() const
{
	return ComponentType::CircleShape;
}

void COGCircleShape::Render()
{
	// Some white for now
	exColor white;
	white.mColor[0] = 255;
	white.mColor[1] = 255;
	white.mColor[2] = 255;
	white.mColor[3] = 255;

	// Position is always at center
	mGO->GetWorld()->Engine()->DrawCircle(mTransform->GetPosition(), mRadius, white, 0);
}

float COGCircleShape::GetRadius() const
{
	return mRadius;
}

