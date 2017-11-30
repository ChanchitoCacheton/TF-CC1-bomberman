#include "stdafx.h"

CJugador::CJugador()
{

	//validacion de comportamientos no controlados por jugador 
	Random ^g = gcnew Random();
	a = 35; h = 35;
	x = 35, y = 35;
	ind = 3;
	ind1 = 0;
	aux = 0;
	maxb = 1;
	expb = 1;

	B = 0;
	bomba = NULL;
	ind_ex1 = ind_ex2 = ind_ex3 = ind_ex4 = 0;
	ind_ex5 = ind_ex6 = ind_ex7 = ind_ex8 = 0;
	ind_ex9 = 0;

	muerto = false;
	baila = false;
	baile = 0;
	cont = 0;
	vidas = 2;
	ind2 = 0;
	temp = 0;

	exp1 = true;
	exp2 = true;
	exp3 = true;
	exp4 = true;
}
CJugador::~CJugador()
{}
void CJugador::patear_bomba()
{
	for (int i = 0; i < B; i++){
		if (y == bomba[i]->gety() && (x + a >= bomba[i]->getx() && x + a < bomba[i]->getx() + 35)){
			bomba[i]->setdir(1);
		}
	}
}
void CJugador::pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	if (!muerto){
		if (!baila){
			lado = img->Width / 12;
			lado = img->Height;

			Rectangle porcionAusar = Rectangle(lado*ind, 0, lado, lado);
			Rectangle pintarEn = Rectangle(x, y, lado, lado);

			r->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);
		}
		else{
			int a = img2->Width / 2;
			int h = img2->Height;

			Rectangle porcionAusar = Rectangle(a*ind2, 0, a, h);
			Rectangle pintarEn = Rectangle(x, y, a, h);

			r->DrawImage(img2, pintarEn, porcionAusar, GraphicsUnit::Pixel);

			if (temp % 4 == 0)
				ind2++;
			temp++;
			if (ind2 > 1)
				ind2 = 0;
			baile++;
		}
	}
	else{
		int width = img1->Width / 8;
		int height = img1->Height;

		Rectangle porcionAusar = Rectangle(width*ind1, 0, width, height);
		Rectangle pintarEn = Rectangle(x, y, width, height);

		r->DrawImage(img1, pintarEn, porcionAusar, GraphicsUnit::Pixel);

		ind1++;
		if (ind1 > 8)
			ind1 = 9;
	}
}
bool CJugador::revive()
{
	if (ind1 == 9){
		if (vidas >= 0){
			if (vidas > 0){
				x = 35;
				y = 35;
				muerto = false;
				ind1 = 0;
			}
			ind = 3;
			vidas--;
			return true;
		}
		else
			return false;
	}
	else
		return true;
}
void CJugador::mover(Graphics ^r, int dx, int dy, int t, int PI, int PII, CPiedra **vec)
{
	for (int i = 0; i < PI + PII; i++)
	{
		if (x + lado + dx > vec[i]->getx() && x + dx < (vec[i]->getx() + vec[i]->getlado())){
			if (y + lado + dy > vec[i]->gety() && y + dy < (vec[i]->gety() + vec[i]->getlado())){
				dx = 0;
				dy = 0;
			}
		}
	}

	for (int i = 0; i < B; i++)
	{
		if (t == 1 && x + lado == bomba[i]->getx() && y == bomba[i]->gety()){
			dx = 0;
			bomba[i]->setdir(1);
		}
		if (t == 2 && x == bomba[i]->getx() + 35 && y == bomba[i]->gety()){
			dx = 0;
			bomba[i]->setdir(2);
		}
		if (t == 3 && y + lado == bomba[i]->gety() && x == bomba[i]->getx()){
			dy = 0;
			bomba[i]->setdir(3);
		}
		if (t == 4 && y == bomba[i]->gety() + 35 && x == bomba[i]->getx()){
			dy = 0;
			bomba[i]->setdir(4);
		}
	}

	if (!muerto && !baila){
		if (x + dx >= 35 && x + dx + lado <= r->VisibleClipBounds.Width - 115)
			x += dx;
		if (y + dy >= 35 && y + dy + lado <= r->VisibleClipBounds.Height - 35)
			y += dy;

		switch (t)
		{
			case 0:
				switch (aux)
				{
					case
						1: ind = 3; break;
					case 2: ind = 9; break;
					case 3: ind = 6; break;
					case 4: ind = 0; break;
				}
				break;
				//derecha
			case 1:
				aux = 1;
				if (ind > 2 && ind < 5)
					ind++;
				else
					ind = 3;
				break;
			case 2://izquierda
				aux = 2;
				if (ind > 8 && ind < 11)
					ind++;
				else
					ind = 9;
				break;
			case 3://abajo
				aux = 3;
				if (ind > 5 && ind < 8)
					ind++;
				else
					ind = 6;
				break;
			case 4://arriba
				aux = 4;
				if (ind < 2)
					ind++;
				else
					ind = 0;
				break;
		}
	}
}
int CJugador::getx()
{
	return x;
}
int CJugador::gety()
{
	return y;
}
int CJugador::getlado()
{
	return lado;
}
int CJugador::geta()
{
	return a;
}
int CJugador::geth()
{
	return h;
}
int CJugador::Vidas()
{
	return vidas;
}
int CJugador::MAXB()
{
	return maxb;
}
int CJugador::EXPB()
{
	return expb;
}
int CJugador::BAILE()
{
	return baile;
}
bool CJugador::BAILA()
{
	return baila;
}
void CJugador::IND1(int ind1)
{
	this->ind2 = ind2;
}

void CJugador::BAILE(int baile)
{
	this->baile = baile;
}
void CJugador::IND(int ind)
{
	this->ind = ind;
}
void CJugador::BAILA(bool baila)
{
	this->baila = baila;
}
void CJugador::Vidas(int vidas)
{
	this->vidas = vidas;
}
void CJugador::MAXB(int maxb)
{
	this->maxb = maxb;
}
void CJugador::EXPB(int expb)
{
	this->expb = expb;
}
void CJugador::setx(int x)
{
	this->x = x;
}
void CJugador::sety(int y)
{
	this->y = y;
}
bool CJugador::EXP1()
{
	return exp1;
}
bool CJugador::EXP2()
{
	return exp2;
}
bool CJugador::EXP3()
{
	return exp3;
}
bool CJugador::EXP4()
{
	return exp4;
}
void CJugador::EXP1(bool exp1)
{
	this->exp1 = exp1;
}
void CJugador::EXP2(bool exp2)
{
	this->exp2 = exp2;
}
void CJugador::EXP3(bool exp3)
{
	this->exp3 = exp3;
}
void CJugador::EXP4(bool exp4)
{
	this->exp4 = exp4;
}
void CJugador::MUERTO(bool muerto)
{
	this->muerto = muerto;
}
//agregar item bomba al comportamiento morir
void CJugador::agregarbomba(int cont)
{
	if (maxb - 1 >= B && !muerto)
	{
		CBomba **temp = new CBomba*[B + 1];

		for (int i = 0; i < B; i++)
			temp[i] = bomba[i];

		if (bomba != NULL)
			delete[]bomba;

		bomba = temp;

		bomba[B] = new CBomba(x, y, 50, 0);

		B++;
	}
}
void CJugador::pintarbomba(Graphics ^g, Bitmap ^img)
{
	for (int i = 0; i < B; i++){
		bomba[i]->pintar(g, img);
	}
}
void CJugador::moverbomba(Graphics ^r, int PI, int PII, CPiedra **vec, int E1, int E2, CEnemigo**vec1)
{
	for (int i = 0; i < B; i++){
		bomba[i]->mover(r);
	}
	detener_bomba(PI, PII, vec, E1, E2, vec1);
}
void CJugador::detener_bomba(int PI, int PII, CPiedra **vec, int E1, int E2, CEnemigo**vec1)
{
	for (int j = 0; j < B; j++){
		int dx = 0;
		int dy = 0;
		switch (bomba[j]->getdir())
		{
			case 1: dy = 0; dx = 7; break;
			case 2: dy = 0; dx = -7; break;
			case 3: dx = 0; dy = 7; break;
			case 4: dx = 0; dy = -7; break;
		}
		for (int i = 0; i < PI + PII; i++){
			if (bomba[j]->getx() + 35 + dx > vec[i]->getx() && bomba[j]->getx() + dx < vec[i]->getx() + vec[i]->getlado()){
				if (bomba[j]->gety() + 35 + dy > vec[i]->gety() && bomba[j]->gety() + dy < vec[i]->gety() + vec[i]->getlado()){
					bomba[j]->setdir(0);
				}
			}
		}
		
	}
}

bool CJugador::explotabomba()
{
	if (B > 0)
	{
		for (int i = 0; i < B; i++)
		{
			if (bomba[i]->getcont() <= 0)
				return true;
		}
	}

	return false;

}

void CJugador::eliminabomba()
{
	if (B > 0)
	{
		CBomba **temp = new CBomba*[B - 1];

		for (int i = 0; i < B - 1; i++)
			temp[i] = bomba[i + 1];

		delete bomba[0];

		if (bomba != NULL)
			delete[]bomba;

		bomba = temp;

		B--;
	}
}

int CJugador::getbomba_x(int i)
{
	return bomba[i]->getx();
}
int CJugador::getbomba_y(int i)
{
	return bomba[i]->gety();
}
int CJugador::getB()
{
	return B;
}
void CJugador::empieza_explosion(Graphics ^r, int px, int py, Bitmap ^img, Bitmap ^img1, Bitmap ^img2, int PI, int PII, CPiedra **Pvec, int DI, int DII, int DIII, CPoder **poder)
{
	exp1 = true;
	exp2 = true;
	exp3 = true;
	exp4 = true;

	int anchoimg, altoimg;
	anchoimg = img->Width / 4;
	altoimg = img->Height / 5;

	int anchoimg2, altoimg2;
	anchoimg2 = img1->Width / 2;
	altoimg2 = img1->Height / 5;

	int anchoimg3, altoimg3;
	anchoimg3 = img2->Width;
	altoimg3 = img2->Height / 5;

	//radio de explosion mediante los sprites (el cambio de sprite afecta la colision)
	Rectangle porcionAusar2 = Rectangle(0, altoimg3*ind_ex9, anchoimg3, altoimg3);
	Rectangle pintarEn2 = Rectangle(px, py, anchoimg3, altoimg3);
	r->DrawImage(img2, pintarEn2, porcionAusar2, GraphicsUnit::Pixel);
	ind_ex9++;
	if (ind_ex9 > 4)
		ind_ex9 = 0;
	for (int i = 1; i < expb; i++)
	{
		for (int j = 0; j < PI + PII; j++)
		{
			if (j == PI + PII)
				break;
			if (px - 35 * i == Pvec[j]->getx() && py == Pvec[j]->gety())
			{
				exp4 = false;
				break;
			}
		}
		for (int j = 0; j < B; j++)
		{
			if (j == B)
				break;
			if (px - 35 * i == bomba[j]->getx() && py == bomba[j]->gety())
			{
				exp4 = false;
				break;
			}
		}
		for (int j = 0; j < DI + DII + DIII; j++){
			if (j == DI + DII + DIII){
				break;
			}
			if (px - 35 * i == poder[j]->getx() && py == poder[j]->gety())
			{
				exp4 = false;
				break;
			}
		}
		if (px - 35 * i >= x && px - 35 * i < x + a && exp4){
			if (py >= y && py < y + h){
				muerto = true;
			}
			if (py + h > y && py + h <= y + h){
				muerto = true;
			}
		}
		if (px - 35 * (expb) >= x && px - 35 * (expb) < x + a && exp4){
			if (py >= y && py < y + h){
				muerto = true;
			}
			if (py + h > y && py + h <= y + h){
				muerto = true;
			}
		}
		
			if (px - 35 * i > 0 && exp4)
			{
				Rectangle porcionAusar1 = Rectangle(anchoimg2, altoimg2*ind_ex8, anchoimg2, altoimg2);
				Rectangle PintarEn1 = Rectangle(px - 35 * i, py, a, h);
				r->DrawImage(img1, PintarEn1, porcionAusar1, GraphicsUnit::Pixel);
			}
		
	}
	if (px - 35 * (expb) >= x && px - 35 * (expb) < x + a && exp4){
		if (py >= y && py < y + h){
			muerto = true;
		}
		if (py + h > y && py + h <= y + h){
			muerto = true;
		}
	}
	ind_ex8++;
	if (ind_ex8 > 4)
		ind_ex8 = 0;

	for (int i = 1; i < expb; i++)
	{
		for (int j = 0; j < PI + PII; j++)
		{
			if (j == PI + PII)
				break;
			if (px + 35 * i == Pvec[j]->getx() && py == Pvec[j]->gety())
			{
				exp2 = false;
				break;
			}
		}
		for (int j = 0; j < B; j++)
		{
			if (j == B)
				break;
			if (px + 35 * i == bomba[j]->getx() && py == bomba[j]->gety())
			{
				exp2 = false;
				break;
			}
		}
		for (int j = 0; j < DI + DII + DIII; j++){
			if (j == DI + DII + DIII){
				break;
			}
			if (px + 35 * i == poder[j]->getx() && py == poder[j]->gety())
			{
				exp2 = false;
				break;
			}
		}
		if (px + 35 * i >= x && px + 35 * i <= x + a && exp2){
			if (py >= y && py < y + h){
				muerto = true;
			}
			if (py + h > y && py + h <= y + h){
				muerto = true;
			}
		}
		if (px + 35 * (expb + 1) >= x && px + 35 * (expb + 1) <= x + a && exp2){
			if (py >= y && py < y + h){
				muerto = true;
			}
			if (py + h > y && py + h <= y + h){
				muerto = true;
			}
		}
		
			if (px + 35 * i < r->VisibleClipBounds.Width - 115 && exp2)
			{
				Rectangle porcionAusar2 = Rectangle(anchoimg2, altoimg2*ind_ex7, anchoimg2, altoimg2);
				Rectangle PintarEn2 = Rectangle(px + 35 * i, py, a, h);
				r->DrawImage(img1, PintarEn2, porcionAusar2, GraphicsUnit::Pixel);
			}
		
	}
	if (px + 35 * (expb + 1) >= x && px + 35 * (expb + 1) <= x + a && exp2){
		if (py >= y && py < y + h){
			muerto = true;
		}
		if (py + h > y && py + h <= y + h){
			muerto = true;
		}
	}
	ind_ex7++;
	if (ind_ex7 > 4)
		ind_ex7 = 0;

	for (int i = 1; i < expb; i++)
	{
		for (int j = 0; j < PI + PII; j++)
		{
			if (j == PI + PII)
				break;
			if (px == Pvec[j]->getx() && py - 35 * i == Pvec[j]->gety())
			{
				exp1 = false;
				break;
			}
		}
		for (int j = 0; j < B; j++)
		{
			if (j == B)
				break;
			if (px == bomba[j]->getx() && py - 35 * i == bomba[j]->gety())
			{
				exp1 = false;
				break;
			}
		}
		for (int j = 0; j < DI + DII + DIII; j++){
			if (j == DI + DII + DIII){
				break;
			}
			if (px == poder[j]->getx() && py - 35 * i == poder[j]->gety())
			{
				exp1 = false;
				break;
			}
		}
		if (py - 35 * i >= y && py - 35 * i < y + h && exp1){
			if (px >= x && px < x + a){
				muerto = true;
			}
			if (px + 35 > x && px + 35 <= x + a){
				muerto = true;
			}
		}
		if (py - 35 * (expb) >= y && py - 35 * (expb) < y + h && exp1){
			if (px >= x && px < x + a){
				muerto = true;
			}
			if (px + 35 > x && px + 35 <= x + a){
				muerto = true;
			}
		}
		
			if (py - 35 * i > 0 && exp1)
			{
				Rectangle porcionAusar1 = Rectangle(0, altoimg2*ind_ex6, anchoimg2, altoimg2);
				Rectangle PintarEn1 = Rectangle(px, py - 35 * i, a, h);
				r->DrawImage(img1, PintarEn1, porcionAusar1, GraphicsUnit::Pixel);
			}
		
	}
	if (py - 35 * (expb) >= y && py - 35 * (expb) < y + h && exp1){
		if (px >= x && px < x + a){
			muerto = true;
		}
		if (px + 35 > x && px + 35 <= x + a){
			muerto = true;
		}
	}
	ind_ex6++;
	if (ind_ex6 > 4)
		ind_ex6 = 0;

	for (int i = 1; i < expb; i++)
	{
		for (int j = 0; j < PI + PII; j++)
		{
			if (j == PI + PII)
				break;
			if (px == Pvec[j]->getx() && py + 35 * i == Pvec[j]->gety())
			{
				exp3 = false;
				break;
			}
		}
		for (int j = 0; j < B; j++)
		{
			if (j == B)
				break;
			if (px == bomba[j]->getx() && py + 35 * i == bomba[j]->gety())
			{
				exp3 = false;
				break;
			}
		}
		for (int j = 0; j < DI + DII + DIII; j++){
			if (j == DI + DII + DIII){
				break;
			}
			if (px == poder[j]->getx() && py + 35 * i == poder[j]->gety())
			{
				exp3 = false;
				break;
			}
		}
		if (py + 35 * i >= y && py + 35 * i <= y + h && exp3){
			if (px >= x && px < x + a){
				muerto = true;
			}
			if (px + a > x && px + a <= x + a){
				muerto = true;
			}
		}
		if (py + 35 * (expb + 1) >= y && py + 35 * (expb + 1) <= y + h && exp3){
			if (px >= x && px < x + a){
				muerto = true;
			}
			if (px + 35 > x && px + 35 <= x + a){
				muerto = true;
			}
		}
		
			if (py + 35 * i < r->VisibleClipBounds.Height - 35 && exp3)
			{
				Rectangle porcionAusar1 = Rectangle(0, altoimg2*ind_ex5, anchoimg2, altoimg2);
				Rectangle PintarEn1 = Rectangle(px, py + 35 * i, a, h);
				r->DrawImage(img1, PintarEn1, porcionAusar1, GraphicsUnit::Pixel);
			}
		
	}
	if (py + 35 * (expb + 1) >= y && py + 35 * (expb + 1) <= y + h && exp3){
		if (px >= x && px < x + a){
			muerto = true;
		}
		if (px + 35 > x && px + 35 <= x + a){
			muerto = true;
		}
	}
	ind_ex5++;
	if (ind_ex5 > 4)
		ind_ex5 = 0;
	if (x + a > px && x < px + 35 && y + h > py && y < py + 35){
		muerto = true;
	}
	if (px - 35 * expb > 0 && exp4)//sprite izquierda
	{
		Rectangle porcionUsar_left = Rectangle(3 * anchoimg, altoimg*ind_ex1, anchoimg, altoimg);
		Rectangle PintarEn_left = Rectangle(px - 35 * expb, py, a, h);
		r->DrawImage(img, PintarEn_left, porcionUsar_left, GraphicsUnit::Pixel);
		ind_ex1++;
		if (ind_ex1 > 4)
			ind_ex1 = 0;
	}
	if (px + 35 * expb < r->VisibleClipBounds.Width - 115 && exp2)//sprite derecha
	{
		Rectangle porcionUsar_right = Rectangle(anchoimg, altoimg*ind_ex2, anchoimg, altoimg);
		Rectangle PintarEn_right = Rectangle(px + 35 * expb, py, a, h);
		r->DrawImage(img, PintarEn_right, porcionUsar_right, GraphicsUnit::Pixel);
		ind_ex2++;
		if (ind_ex2 > 4)
			ind_ex2 = 0;
	}
	if (py - 35 * expb > 0 && exp1)//sprite arriba
	{
		Rectangle porcionUsar_up = Rectangle(0, altoimg*ind_ex3, anchoimg, altoimg);
		Rectangle PintarEn_up = Rectangle(px, py - 35 * expb, a, h);
		r->DrawImage(img, PintarEn_up, porcionUsar_up, GraphicsUnit::Pixel);
		ind_ex3++;
		if (ind_ex3 > 4)
			ind_ex3 = 0;
	}
	if (py + 35 * expb < r->VisibleClipBounds.Height - 35 && exp3)//sprite abajo
	{
		Rectangle porcionUsar_down = Rectangle(2 * anchoimg, altoimg*ind_ex4, anchoimg, altoimg);
		Rectangle PintarEn_down = Rectangle(px, py + 35 * expb, a, h);
		r->DrawImage(img, PintarEn_down, porcionUsar_down, GraphicsUnit::Pixel);
		ind_ex4++;
		if (ind_ex4 > 4)
			ind_ex4 = 0;
	}
}
void CJugador::ubica_bomba_en_X()
{
	int a1, a2, pos = -1;
	for (int i = 0; i < B; i++)
	{
		for (int c = 0; c < 16; c++)
		{
			if (bomba[i]->getx() < c * 35 && bomba[i]->getx() + 35 > c * 35)
			{
				pos = i;
				a1 = (c * 35) - (bomba[i]->getx());
				a2 = (bomba[i]->getx() + 35) - (c * 35);
			}
		}
	}
	if (pos != -1)
	{
		if (a1 > a2)
			bomba[pos]->setx(bomba[pos]->getx() - a2);
		else
			bomba[pos]->setx(bomba[pos]->getx() + a1);
	}
}
void CJugador::ubica_bomba_en_Y()
{
	int h1, h2, pos = -1;
	for (int i = 0; i < B; i++)
	{
		for (int f = 0; f < 16; f++)
		{
			if (bomba[i]->gety() < f * 35 && bomba[i]->gety() + 35 > f * 35)
			{
				pos = i;
				h1 = (f * 35) - (bomba[i]->gety());
				h2 = (bomba[i]->gety() + 35) - (f * 35);
			}
		}
	}
	if (pos != -1)
	{
		if (h1 > h2)
			bomba[pos]->sety(bomba[pos]->gety() - h2);
		else
			bomba[pos]->sety(bomba[pos]->gety() + h1);
	}
}
void CJugador::MOVBOMBA(int pos, bool movbomba)
{
	bomba[pos]->movBomba(movbomba);
}