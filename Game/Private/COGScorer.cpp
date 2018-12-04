#include "..\Public\COGScorer.h"

COGScorer::COGScorer(GameObject * pGO)
	: Component(pGO)
	, mScore(0)
{
}

ComponentType COGScorer::GetType() const
{
	return ComponentType::Scorer;
}

int & COGScorer::GetScore()
{
	// TODO: insert return statement here
	return mScore;
}
