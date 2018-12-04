#include "..\Public\COGBoxShape.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\EngineInterface.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGTransform.h"

COGBoxShape::COGBoxShape(GameObject * pGO, float fWidth, float fHeight)
	: COGShape(pGO)
	, mWidth(fWidth)
	, mHeight(fHeight)
{
}

ComponentType COGBoxShape::GetType() const
{
	return ComponentType::BoxShape;
}

void COGBoxShape::Render()
{
	// Some white for now
	exColor white;
	white.mColor[0] = 255;
	white.mColor[1] = 255;
	white.mColor[2] = 255;
	white.mColor[3] = 255;

	// Position is always at center
	mGO->GetWorld()->Engine()->DrawBox(Vector2(mTransform->GetPosition().x - mWidth / 2.0f, mTransform->GetPosition().y - mHeight / 2.0f),
		Vector2(mTransform->GetPosition().x + mWidth / 2.0f, mTransform->GetPosition().y + mHeight / 2.0f), white, 0);
}

float COGBoxShape::GetWidth() const
{
	return mWidth;
}

float COGBoxShape::GetHeight() const
{
	return mHeight;
}
