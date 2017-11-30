#include "stdafx.h"

CPoderFlama::CPoderFlama(int x, int y) : CPoder(x, y)
{}
CPoderFlama::~CPoderFlama()
{}
void CPoderFlama::pintar(Graphics ^g, Bitmap ^img)
{
	lado = img->Width;
	lado = img->Height;

	Rectangle porcionAusar = Rectangle(0, 0, lado, lado);
	Rectangle pintarEn = Rectangle(x, y, lado, lado);

	g->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
}
