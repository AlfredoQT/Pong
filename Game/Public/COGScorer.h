#pragma once

#include "..\Public\Component.h"

class COGScorer: public Component
{
public:

	COGScorer(GameObject* pGO);

	virtual ComponentType GetType() const;

	// I know, I know
	int& GetScore();

private:

	int mScore;

};

