#include "..\Public\COGTransform.h"

COGTransform::COGTransform(GameObject * pGO)
	: Component(pGO)
{
}

ComponentType COGTransform::GetType() const
{
	return ComponentType::Transform;
}

Vector2 & COGTransform::GetPosition()
{
	return mPosition;
}
