#include "..\Public\Crossfade.h"

float Crossfade::Arch2(float pTime)
{
	return 4.0f * pTime * (1.0f - pTime);
}

float Crossfade::Mix(float(*pFunctionOne)(float), float(*pFunctionTwo)(float), float pWeightBlend)
{
	// Compute the interpolation
	return pFunctionOne(pWeightBlend) + (pFunctionTwo(pWeightBlend) - pFunctionOne(pWeightBlend)) * pWeightBlend;
}
