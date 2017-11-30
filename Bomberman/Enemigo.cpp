#include "stdafx.h"

CEnemigo::CEnemigo(int x, int y, int dx, int dy, int dir, int limx, int limy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->dir = dir;
	this->limx = limx;
	this->limy = limy;
	ind = 0;

	//hay un bug
	resistencia = 30;
	golpeado = false;
	murio = false;
	indm = 0;
}
CEnemigo::~CEnemigo()
{}
void CEnemigo::setdir(int dir)
{
	this->dir = dir;
}
void CEnemigo::setdx(int dx)
{
	this->dx = dx;
}
void CEnemigo::setdy(int dy)
{
	this->dy = dy;
}
void CEnemigo::setresistencia(int resistencia)
{
	this->resistencia = resistencia;
}
void CEnemigo::setgolpeado(bool golpeado)
{
	this->golpeado = golpeado;
}
void CEnemigo::setmurio(bool murio)
{
	this->murio = murio;
}
int CEnemigo::getx()
{
	return x;
}
int CEnemigo::gety()
{
	return y;
}
int CEnemigo::getlado()
{
	return lado;
}
int CEnemigo::getlado2()
{
	return lado2;
}
int CEnemigo::getdir()
{
	return dir;
}
int CEnemigo::getdx()
{
	return dx;
}
int CEnemigo::getdy()
{
	return dy;
}
int CEnemigo::getresistencia()
{
	return resistencia;
}
int CEnemigo::getindm()
{
	return indm;
}
bool CEnemigo::getmurio()
{
	return murio;
}
bool CEnemigo::getgolpeado()
{
	return golpeado;
}
