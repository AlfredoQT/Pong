#pragma once

#include <string>

namespace Debug
{

	void exOutputWindows(const char* output);

	template <typename T>
	void exOutputLine(T text)
	{
		std::string temp(std::to_string(text) + "\n");
		const char* finalChar = temp.c_str();
		exOutputWindows(finalChar);
	}

}
