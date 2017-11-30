#include "stdafx.h"

CEnemigo2::CEnemigo2(int x, int y, int dx, int dy, int dir, int limx, int limy) : CEnemigo(x, y, dx, dy, dir, limx, limy)
{}
CEnemigo2::~CEnemigo2()
{}
void CEnemigo2::pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1)
{
	Rectangle porcionAusar;
	Rectangle pintarEn;
	if (!murio){
		lado = img->Width / 12;
		lado2 = img->Height;
		porcionAusar = Rectangle(lado*ind, 0, lado, lado2);
		pintarEn = Rectangle(x, y, lado, lado2);
		r->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
	}
	else{
		lado = img1->Width / 4;
		lado2 = img1->Height;
		porcionAusar = Rectangle(lado*indm, 0, lado, lado2);
		pintarEn = Rectangle(x, y, lado, lado2);
		if (indm > 3)
			indm = 4;
		indm++;
		r->DrawImage(img1, pintarEn, porcionAusar, GraphicsUnit::Pixel);
	}
}
void CEnemigo2::mover(int limite_Y)
{
	if (!murio){
		switch (dir)
		{
		case 1:
			x += dx;
			if (ind > 2 && ind < 5)
				ind++;
			else
				ind = 3;
			break;
		case 2:
			x -= dx;
			if (ind > 8 && ind < 11)
				ind++;
			else
				ind = 9;
			break;
		case 3:
			y += dy;
			if (ind > 5 && ind < 8)
				ind++;
			else
				ind = 6;
			break;
		case 4:
			y -= dy;
			if (ind < 2)
				ind++;
			else
				ind = 0;
		}
	}
}
