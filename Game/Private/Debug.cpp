#include "..\Public\Debug.h"
#include "windows.h"

void Debug::exOutputWindows(const char * output)
{
	OutputDebugString(output);
}
