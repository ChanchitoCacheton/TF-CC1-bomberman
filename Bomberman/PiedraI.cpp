#include "stdafx.h"

CPiedraI::CPiedraI(int x, int y) : CPiedra(x, y)
{}
CPiedraI::~CPiedraI()
{
}
void CPiedraI::pintar(Graphics ^r, Bitmap ^img)
{
	lado = img->Width;
	lado = img->Height;

	r->DrawImage(img, x, y, lado, lado);
}
