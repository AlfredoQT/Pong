#include "..\Public\COGReset.h"
#include "Game\Public\COGScorer.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Engine\Public\EngineInterface.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Random.h"

COGReset::COGReset(GameObject * pGO)
	: Component(pGO)
{
}

ComponentType COGReset::GetType() const
{
	return ComponentType::Reset;
}

void COGReset::OnCollision(COGPhysics * pMe, COGPhysics * pOther, CollisionInfo pInfo)
{	
	COGScorer* scorer = pOther->GetOwner()->FindComponent<COGScorer>(ComponentType::Scorer);
	// Check if the other has a scorer
	if (scorer == nullptr)
	{
		return;
	}

	// Reset ball position
	Vector2& bPosition = pMe->GetOwner()->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
	bPosition = Vector2(kViewportWidth / 2.0f, kViewportHeight / 2.0f);

	// Reset ball velocity
	Vector2& bVelocity = pMe->GetVelocity();
	bVelocity = Vector2(Random::Instance()->NextFloat(-1.0f, 1.0f), Random::Instance()->NextFloat(-1.0f, 1.0f)).Normalized() * 400.0f;

	// Update score
	int& score = scorer->GetScore();
	++score;
}
