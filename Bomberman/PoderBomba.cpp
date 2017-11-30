#include "stdafx.h"

CPoderBomba::CPoderBomba(int x, int y) : CPoder(x, y)
{}
CPoderBomba::~CPoderBomba()
{}
void CPoderBomba::pintar(Graphics ^g, Bitmap ^img)
{
	lado = img->Width;
	lado = img->Height;

	Rectangle porcionAusar = Rectangle(0, 0, lado, lado);
	Rectangle pintarEn = Rectangle(x, y, lado, lado);

	g->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
}