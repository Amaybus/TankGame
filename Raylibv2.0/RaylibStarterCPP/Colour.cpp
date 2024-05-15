#include "Colour.h"

using namespace MathClasses;

Colour::Colour()
{
	colour = 0xff;
}

Colour::Colour(Byte red, Byte green, Byte blue, Byte alpha)
{
	colour = (red << 24) | (green << 16) | (blue << 8) | alpha;
}

Byte Colour::GetRed() const
{
	return colour >> 24;
}

void Colour::SetRed(Byte red)
{
	unsigned int v = (unsigned int)red << 24;
	colour = colour & 0x00ffffff;
	colour = colour | v;
}

Byte Colour::GetGreen() const
{
	return colour >> 16;
}

void Colour::SetGreen(Byte green)
{
	unsigned int v = (unsigned int)green << 16;
	colour = colour & 0xff00ffff;
	colour = colour | v;
}

Byte Colour::GetBlue() const
{
	return colour >> 8;
}

void Colour::SetBlue(Byte blue)
{
	unsigned int v = (unsigned int)blue << 8;
	colour = colour & 0xffff00ff;
	colour = colour | v;
}

Byte Colour::GetAlpha() const
{
	return colour & 0xff;
}

void Colour::SetAlpha(Byte alpha)
{
	unsigned int v = (unsigned int)alpha;
	colour = colour & 0xffffff00;
	colour = colour | v;
}

std::string Colour::ToString() const
{
	return std::string();
}

void MathClasses::Colour::RedToGreen(Byte red)
{
}

bool MathClasses::operator==(Colour a, Colour b)
{
	return a.colour == b.colour;
}

bool MathClasses::operator!=(Colour a, Colour b)
{
	return !(a == b);
}