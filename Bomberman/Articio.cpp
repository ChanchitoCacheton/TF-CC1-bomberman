#include "stdafx.h"

CArticio::CArticio(int x, int y)
{
	this->x = x;
	this->y = y;
}
CArticio::~CArticio()
{}
void CArticio::pintar_artificio(Graphics ^g, Bitmap ^img)
{
	int a = img->Width;
	int h = img->Height;

	g->DrawImage(img, x, y, a, h);
}
int CArticio::getx()
{
	return x;
}
int CArticio::gety()
{
	return y;
}

