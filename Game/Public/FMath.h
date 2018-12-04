#pragma once

#include <math.h>

// A library of static methods for moi
struct FMath
{
	template<class T>
	static T Max(const T a, const T b)
	{
		return a > b ? a : b;
	}

	template<class T>
	static T Min(const T a, const T b)
	{
		return a < b ? a : b;
	}

	template<class T>
	static T Clamp(const T value, const T min, const T max)
	{
		return Max(min, Min(value, max));
	}

	// I did not want to implement my own cosine function for this assignment
	template<class T>
	static T Cos(const T angle)
	{
		return cos(angle);
	}

	// I did not want to implement my own sine function for this assignment
	template<class T>
	static T Sin(const T angle)
	{
		return sin(angle);
	}

	template<class T>
	static T Atan2(const T y, const T x)
	{
		return atan2(y, x);
	}

};
