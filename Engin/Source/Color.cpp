#pragma once
#include "Color.h"
namespace project {
	const project::Color& project::Color::Red = Color(uchar(255), uchar(0), uchar(0), uchar(255));
	const project::Color& project::Color::Green = Color(uchar(0), uchar(255), uchar(0), uchar(255));
	const project::Color& project::Color::Blue = Color(uchar(0), uchar(0), uchar(255), uchar(255));
	const project::Color& project::Color::Black = Color(uchar(0), uchar(0), uchar(0), uchar(255));
	const project::Color& project::Color::White = Color(uchar(255), uchar(255), uchar(255), uchar(255));
	Color::Color(uchar red, uchar green, uchar blue, uchar alpha) 
		:red(red), green(green), blue(blue), alpha(alpha)
	{
	}



}