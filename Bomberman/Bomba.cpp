#include "stdafx.h"

CBomba::CBomba(int x, int y, int cont, int limit)
{
	this->x = x;
	this->y = y;
	this->cont = cont;
	this->limit = limit;
	ind = 0;
	lado = 35;
	dx = 7;
	dy = 7;
	this->cont = cont;
	dir = 0;
	movbomba = false;
}
CBomba::~CBomba()
{}
void CBomba::pintar(Graphics ^r, Bitmap ^img)
{
	Rectangle porcionAusar = Rectangle(lado*ind, 0, lado, lado);
	Rectangle pintarEn = Rectangle(x, y, lado, lado);

	r->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);

	ind++;
	if (ind > 5)
		ind = 0;
	if (dir == 0)
		cont--;
}
void CBomba::mover(Graphics ^r)
{
	if (movbomba){
		int anchop = r->VisibleClipBounds.Width;
		int altop = r->VisibleClipBounds.Height;
		switch (dir)
		{
		case 1: if (x + dx + 35 <= anchop - 115){ x += dx; }
				else{
					dir = 0;
				} break;
		case 2: if (x - dx >= 35){ x -= dx; }
				else{
					dir = 0;
				} break;
		case 3: if (y + dy + 35 <= altop - 35){ y += dy; }
				else{
					dir = 0;
				} break;
		case 4: if (y - dy >= 35){ y -= dy; }
				else{
					dir = 0;
				} break;
		}
	}
}
void CBomba::setdir(int dir)
{
	if (movbomba)
		this->dir = dir;
}
void CBomba::setcont(int cont)
{
	this->cont = cont;
}
void CBomba::setx(int x)
{
	this->x = x;
}
void CBomba::sety(int y)
{
	this->y = y;
}
void CBomba::setdx(int dx)
{
	this->dx = dx;
}
void CBomba::setdy(int dy)
{
	this->dy = dy;
}
void CBomba::movBomba(bool movbomba)
{
	this->movbomba = movbomba;
}

int CBomba::getdir()
{
	return dir;
}
int CBomba::getx()
{
	return x;
}
int CBomba::gety()
{
	return y;
}
int CBomba::getcont()
{
	return cont;
}
