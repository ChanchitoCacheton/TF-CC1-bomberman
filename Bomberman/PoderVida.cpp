#include "stdafx.h"

CPoderVida::CPoderVida(int x, int y) : CPoder(x, y)
{}
CPoderVida::~CPoderVida()
{}
void CPoderVida::pintar(Graphics ^g, Bitmap ^img)
{
	lado = img->Width;
	lado = img->Height;

	Rectangle porcionAusar = Rectangle(0, 0, lado, lado);
	Rectangle pintarEn = Rectangle(x, y, lado, lado);

	g->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
}