#include "stdafx.h"

CPiedra::CPiedra(int x, int y)
{
	this->x = x;
	this->y = y;
}
CPiedra::~CPiedra()
{
}
int CPiedra::getlado()
{
	return lado;
}
int CPiedra::getx()
{
	return x;
}
int CPiedra::gety()
{
	return y;
}