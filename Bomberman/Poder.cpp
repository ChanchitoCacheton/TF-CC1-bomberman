#include "stdafx.h"

CPoder::CPoder(int x, int y)
{
	this->x = x;
	this->y = y;
}
CPoder::~CPoder()
{}
int CPoder::getx()
{
	return x;
}
int CPoder::gety()
{
	return y;
}
int CPoder::getlado()
{
	return lado;
}
