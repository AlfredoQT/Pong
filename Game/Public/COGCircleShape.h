#pragma once

#include "..\Public\COGShape.h"

// COGCircleShape - circle
class COGCircleShape : public COGShape
{
public:

	COGCircleShape(GameObject* pGO, float pRadius);

	virtual ComponentType GetType() const override;

	virtual void Render() override;

	float GetRadius() const;

private:

	float mRadius;

};
