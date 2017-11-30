#include "stdafx.h"

CPiedraII::CPiedraII(int x, int y) : CPiedra(x, y)
{}
CPiedraII::~CPiedraII()
{}
void CPiedraII::pintar(Graphics ^r, Bitmap ^img)
{
	lado = img->Width;
	lado = img->Height;

	r->DrawImage(img, x, y, lado, lado);
}
