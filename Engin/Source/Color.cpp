#pragma once
#include "Color.h"

namespace project {
	const Color& Color::Red = Color(uchar(255), uchar(0), uchar(0), uchar(255));
	const Color& Color::Green = Color(uchar(0), uchar(255), uchar(0), uchar(255));
	const Color& Color::Blue = Color(uchar(0), uchar(0), uchar(255), uchar(255));
	const Color& Color::Black = Color(uchar(0), uchar(0), uchar(0), uchar(255));
	const Color& Color::White = Color(uchar(255), uchar(255), uchar(255), uchar(255));
	
	
	Color::Color(uchar red, uchar green, uchar blue, uchar alpha) 
		:red(red), green(green), blue(blue), alpha(alpha)
	{
	}



}