#include <stdio.h>
using namespace System;
using namespace System::Drawing;
// TODO: mencionar aquí los encabezados adicionales que el programa necesita

#include "Piedra.h"
#include "PiedraI.h"
#include "PiedraII.h"
#include "Enemigo.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include "Poder.h"
#include "PoderPatear.h"
#include "PoderBomba.h"
#include "PoderFlama.h"
#include "PoderVida.h"
#include "Bomba.h"
#include "Jugador.h"
#include "Artificio.h"
#include "Juego.h"

//constructor 

CArtificio::CArtificio(int x, int y)
{
	this->x = x;
	this->y = y;
}
CArtificio::~CArtificio()
{}

//validar parametros de ancho y alto
void CArtificio::pintar_artificio(Graphics ^g, Bitmap ^img)
{
	int a = img->Width;
	int h = img->Height;

	g->DrawImage(img, x, y, a, h);
}


int CArtificio::getx()
{
	return x;
}
int CArtificio::gety()
{
	return y;
}

