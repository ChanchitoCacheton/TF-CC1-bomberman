#include "stdafx.h"

CJuego::CJuego(int anchop, int altop)
{
	Random ^g = gcnew Random();

	piedras = NULL;
	poder = NULL;
	artificio = NULL;
	enemigo = NULL;
	jugador = new CJugador();

	P1 = 64;
	P2 = 1;
	capacidad_maxima = 173;

	D1 = 0;
	D2 = 0;
	D3 = 0;

	E1 = 1;
	E2 = 1;
	E3 = 1;

	A = 64;
	dic = g->Next(1, 5);
	an = g->Next(100, anchop - 41);
	al = g->Next(100, altop - 41);
	stage = 0;

	X_piedra = new int[capacidad_maxima];
	Y_piedra = new int[capacidad_maxima];
	Ind_Piedra = new int[capacidad_maxima];
	x_enemigo = new int[50];
	y_enemigo = new int[50];
	Ind = new int[50];
	Pos = new int[50];
	cont2 = 0;
	cont = 0;

	puntaje = 0;
	nivel = 1;
}
CJuego::~CJuego()
{}
void CJuego::patear_bomba()
{
	jugador->patear_bomba();
}
//instrumentos del constructor juego
void CJuego::setA(int A){
	this->A = A;
}

//instrumentos del constructor fase
void CJuego::FASE(int fase)
{
	this->stage = fase;
}
int CJuego::FASE()
{
	return stage;
}
int CJuego::Puntaje()
{
	return puntaje;
}
int CJuego::Nivel()
{
	return nivel;
}
void CJuego::Nivel(int nivel)
{
	this->nivel = nivel;
}
void CJuego::Limpiar_mapa()
{
	if (E1 + E2){
		CEnemigo **temp = new CEnemigo*[E1 + E2 - (E1 + E2)];

		for (int i = 0; i < E1 + E2; i++){
			temp[i] = enemigo[i];
		}

		if (enemigo != NULL){
			delete[]enemigo;
		}

		enemigo = temp;

		E1 -= E1;
		E2 -= E2;
	}
	if (P1 + P2 > 0){
		CPiedra **temp = new CPiedra*[P1 + P2 - P2];

		for (int i = 0; i < P1; i++){
			temp[i] = piedras[i];
		}

		if (piedras != NULL){
			delete[]piedras;
		}

		piedras = temp;

		P2 -= P2;
	}
	if (D1 + D2 + D3 > 0){
		CPoder **temp = new CPoder*[D1 + D2 + D3 - (D1 + D2 + D3)];

		for (int i = 0; i < D1 + D2 + D3; i++){
			temp[i] = poder[i];
		}

		if (poder != NULL){
			delete[]poder;
		}

		poder = temp;

		D1 -= D1;
		D2 -= D2;
		D3 -= D3;
	}
}

//panel pero no es panel :D
void CJuego::Pintar_Vidas(Graphics ^g, Bitmap ^img, Bitmap ^img1)
{
	for (int i = 2; i >= 0; i--){
		g->DrawImage(img1, 550, 113 + img1->Height - (img1->Height + 10)*i, img1->Width, img1->Height);
	}
	for (int i = jugador->Vidas(); i >= 0; i--){
		g->DrawImage(img, 550, 113 + img->Height - (img->Height + 10)*i, img->Width, img->Height);
	}
}
bool CJuego::destruye(int aux1, int aux2)
{
	jugador->EXP1(true);
	jugador->EXP2(true);
	jugador->EXP3(true);
	jugador->EXP4(true);
	bool elimina = false;

	for (int j = 1; j < jugador->EXPB() + 1; j++)
	{
		for (int i = 0; i < jugador->getB(); i++){
			if (aux2 == jugador->getbomba_y(i) && aux1 + 35 * j == jugador->getbomba_x(i) && jugador->EXP2()){
				jugador->EXP2(false);
			}
			if (aux2 == jugador->getbomba_y(i) && aux1 - 35 * j == jugador->getbomba_x(i) && jugador->EXP4()){
				jugador->EXP4(false);
			}
			if (aux2 + 35 * j == jugador->getbomba_y(i) && aux1 == jugador->getbomba_x(i) && jugador->EXP3()){
				jugador->EXP3(false);
			}
			if (aux2 - 35 * j == jugador->getbomba_y(i) && aux1 == jugador->getbomba_x(i) && jugador->EXP2()){
				jugador->EXP2(false);
			}
		}
		//sobre eliminar las piedras colision
		for (int i = 0; i < P1 + P2; i++)
		{
			bool borra = false;
			if (aux2 == piedras[i]->gety() && aux1 + 35 * j == piedras[i]->getx() && jugador->EXP2())
			{
				jugador->EXP2(false);
				borra = true;
			}
			if (aux2 == piedras[i]->gety() && aux1 - 35 * j == piedras[i]->getx() && jugador->EXP4())
			{
				jugador->EXP4(false);
				borra = true;
			}
			if (aux2 + 35 * j == piedras[i]->gety() && aux1 == piedras[i]->getx() && jugador->EXP3())
			{
				jugador->EXP3(false);
				borra = true;
			}
			if (aux2 - 35 * j == piedras[i]->gety() && aux1 == piedras[i]->getx() && jugador->EXP1())
			{
				jugador->EXP1(false);
				borra = true;
			}
			if (borra && i >= P1)
			{
				X_piedra[cont] = piedras[i]->getx();
				Y_piedra[cont] = piedras[i]->gety();
				Ind_Piedra[cont] = 6;
				cont++;
				eliminapiedra(i);
				puntaje += 100;
				i--;
			}
		}
		for (int i = 0; i < E1 + E2 + E3; i++)
		{
			bool borra = false;
			if (aux1 + 35 * j >= enemigo[i]->getx() && aux1 + 35 * j <= enemigo[i]->getx() + jugador->geta() && jugador->EXP2())
			{
				if (aux2 >= enemigo[i]->gety() && aux2 < enemigo[i]->gety() + jugador->geth())
					borra = true;
				if (aux2 + jugador->geth() > enemigo[i]->gety() && aux2 + jugador->geth() <= enemigo[i]->gety() + jugador->geth())
					borra = true;
			}
			if (aux1 - 35 * j >= enemigo[i]->getx() && aux1 - 35 * j <= enemigo[i]->getx() + jugador->geta() && jugador->EXP4())
			{
				if (aux2 >= enemigo[i]->gety() && aux2 < enemigo[i]->gety() + jugador->geth())
					borra = true;
				if (aux2 + jugador->geth() > enemigo[i]->gety() && aux2 + jugador->geth() <= enemigo[i]->gety() + jugador->geth())
					borra = true;
			}
			if (aux2 + 35 * j >= enemigo[i]->gety() && aux2 + 35 * j <= enemigo[i]->gety() + jugador->geth() && jugador->EXP3())
			{
				if (aux1 >= enemigo[i]->getx() && aux1 < enemigo[i]->getx() + jugador->geta())
					borra = true;
				if (aux1 + jugador->geta() > enemigo[i]->getx() && aux1 + jugador->geta() <= enemigo[i]->getx() + jugador->geta())
					borra = true;
			}
			if (aux2 - 35 * j >= enemigo[i]->gety() && aux2 - 35 * j <= enemigo[i]->gety() + jugador->geth() && jugador->EXP1())
			{
				if (aux1 >= enemigo[i]->getx() && aux1 < enemigo[i]->getx() + jugador->geta())
					borra = true;
				if (aux1 + jugador->geta() > enemigo[i]->getx() && aux1 + jugador->geta() <= enemigo[i]->getx() + jugador->geta())
					borra = true;
			}
			if (borra)
			{
				Pos[cont2] = i;
				x_enemigo[Pos[cont2]] = enemigo[i]->getx();
				y_enemigo[Pos[cont2]] = enemigo[i]->gety();
				Ind[Pos[cont2]] = 0;
				enemigo[i]->setmurio(true);
				cont2++;
				
			}
		}





		//se aplica el comportamiento de eliminar el poder cuando la bomba cambia de sprite
		for (int i = 0; i < D1 + D2 + D3; i++)
		{
			bool borra = false;
			if (aux2 == poder[i]->gety() && aux1 + 35 * j == poder[i]->getx() && jugador->EXP2())
			{
				jugador->EXP2(false);
				borra = true;
			}
			if (aux2 == poder[i]->gety() && aux1 - 35 * j == poder[i]->getx() && jugador->EXP4())
			{
				jugador->EXP4(false);
				borra = true;
			}
			if (aux2 + 35 * j == poder[i]->gety() && aux1 == poder[i]->getx() && jugador->EXP3())
			{
				jugador->EXP3(false);
				borra = true;
			}
			if (aux2 - 35 * j == poder[i]->gety() && aux1 == poder[i]->getx() && jugador->EXP1())
			{
				jugador->EXP1(false);
				borra = true;
			}
			if (borra)
			{
				eliminapoder(i);
				i--;
			}
		}
	}

	return false;
}

//pequeña colision
void CJuego::choca_con_enemigo()
{
	for (int i = 0; i < E1 + E2; i++){
		if (!enemigo[i]->getmurio()){
			if (jugador->getx() + jugador->geta() > enemigo[i]->getx() && jugador->getx() < enemigo[i]->getx() + enemigo[i]->getlado() &&
				jugador->gety() + jugador->geth() > enemigo[i]->gety() && jugador->gety() < enemigo[i]->gety() + enemigo[i]->getlado2()){
				jugador->MUERTO(true);
			}
		}
	}

	for (int i = 0; i < E1 + E2 + E3; i++){
		if (enemigo[i]->getindm() == 5)
			eliminarenemigo(i);
	}
}

//instancia game over
bool CJuego::GameOver()
{
	if (E1 + E2 + E3 == 0){
		if (!jugador->BAILA()){
			jugador->BAILA(true);
			jugador->IND1(0);
		}
		else{
			if (jugador->BAILE() == 80){
				if (nivel < 4){
					nivel++;
					stage = 1;
					jugador->BAILA(false);
					jugador->BAILE(0);
					jugador->IND(9);
					return true;
				}
			}
		}
	}

	return false;
}
void CJuego::cojer_poder()
{
	for (int i = 0; i < D1 + D2 + D3; i++){
		bool destruye = false;
		if (jugador->getx() + jugador->geta() > poder[i]->getx() && jugador->getx() < poder[i]->getx() + poder[i]->getlado() &&
			jugador->gety() + jugador->geth() > poder[i]->gety() && jugador->gety() < poder[i]->gety() + poder[i]->getlado()){
			if (dynamic_cast<CPoderBomba*>(poder[i])){
				jugador->MAXB(jugador->MAXB() + 1);
				destruye = true;
			}
			if (dynamic_cast<CPoderFlama*>(poder[i])){
				jugador->EXPB(jugador->EXPB() + 1);
				destruye = true;
			}
			if (dynamic_cast<CPoderVida*>(poder[i])){
				jugador->Vidas(jugador->Vidas() + 1);
				destruye = true;
			}
			if (dynamic_cast<CPoderPatear*>(poder[i])){
				jugador->MOVBOMBA(i, true);
				destruye = true;
			}
		}

		if (destruye){
			eliminapoder(i);
			i--;
		}
	}
}
//pintar player
void CJuego::pintar_jugador(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	jugador->pintar(g, img, img1, img2);
	if (!jugador->revive()){
		stage = 3;
	}
}
void CJuego::mover_jugador(Graphics ^g, int t)
{switch (t)
	{
		case 0: jugador->mover(g, 0, 0, t, P1, P2, piedras);  break;
		case 1: jugador->mover(g, 7, 0, t, P1, P2, piedras);  break;
		case 2: jugador->mover(g, -7, 0, t, P1, P2, piedras); break;
		case 3: jugador->mover(g, 0, 7, t, P1, P2, piedras);  break;
		case 4: jugador->mover(g, 0, -7, t, P1, P2, piedras); break;
	}
}
void CJuego::setXJugador(int x)
{
	jugador->setx(x);
}
void CJuego::setYJugador(int y)
{
	jugador->sety(y);
}
//funcion de las piedras

void CJuego::setPI(int PI)
{
	this->P1 = PI;
}
void CJuego::setPII(int PII)
{
	this->P2 = PII;
}
void CJuego::agregar_piedras()
{
	if (P2 > capacidad_maxima)
		P2 = capacidad_maxima;
	Random ^g = gcnew Random();

	int *bloque_x = new int[P1];   int *bloque_y = new int[P1];
	int *ladrillo_x = new int[P1];  int *ladrillo_y = new int[P2];

	bool colocar = true;
	int f = 1;
	int c = 1;

	for (int i = 0; i < P1; i++)
	{
		bloque_x[i] = 70 * f;
		bloque_y[i] = 70 * c;

		f++;
		if (f > 6)
		{
			f = 1;
			c++;
			if (c > 6)
				c = 1;
		}
	}
	ladrillo_x[0] = 3 * 35;	ladrillo_y[0] = 35;
	ladrillo_x[1] = 35;		ladrillo_y[1] = 3 * 35;
	for (int i = 2; i < P2; i++)
	{
		do
		{
			colocar = true;
			ladrillo_x[i] = 35 * (g->Next(1, 14));
			ladrillo_y[i] = 35 * (g->Next(1, 14));
			if (ladrillo_x[i] == jugador->getx() && ladrillo_y[i] == jugador->gety())
				colocar = false;
			if (ladrillo_x[i] == jugador->getx() + 35 && ladrillo_y[i] == jugador->gety())
				colocar = false;
			if (ladrillo_x[i] == jugador->getx() && ladrillo_y[i] == jugador->gety() + 35)
				colocar = false;
			for (int j = 0; j < P1; j++)
				if (bloque_x[j] == ladrillo_x[i] && bloque_y[j] == ladrillo_y[i])
					colocar = false;
			for (int j = 0; j < i; j++)
				if (ladrillo_x[j] == ladrillo_x[i] && ladrillo_y[j] == ladrillo_y[i])
					colocar = false;
		} while (!colocar);
	}

	piedras = new CPiedra*[P1 + P2];
	for (int i = 0; i < P1; i++)
		piedras[i] = new CPiedraI(bloque_x[i], bloque_y[i]);
	for (int i = P1; i < P1 + P2; i++)
		piedras[i] = new CPiedraII(ladrillo_x[i - P1], ladrillo_y[i - P1]);
}
void CJuego::pintar_piedras(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	for (int i = 0; i < P1; i++){
		piedras[i]->pintar(g, img);
	}
	for (int i = P1; i < P1 + P2; i++){
		piedras[i]->pintar(g, img1);
	}

	destruirse(g, img2);
}
void CJuego::eliminapiedra(int pos)
{
	int j = 0;
	if (P1 + P2 > 0)
	{
		CPiedra **temp = new CPiedra*[P1 + P2 - 1];

		for (int i = 0; i < P1 + P2; i++)
		{
			if (i != pos)
			{
				temp[j] = piedras[i];
				j++;
			}
			else
				delete piedras[pos];
		}

		if (piedras!= NULL)
			delete[]piedras;

		piedras = temp;

		P2--;
	}

}
void CJuego::destruirse(Graphics ^r, Bitmap ^img)
{
	int a = img->Width / 6;
	int h = img->Height;

	for (int i = 0; i < cont; i++)
	{
		Rectangle porcionAusar = Rectangle(Ind_Piedra[i] * a, 0, a, h);
		Rectangle pintarEn = Rectangle(X_piedra[i], Y_piedra[i], a, h);
		r->DrawImage(img, pintarEn, porcionAusar, GraphicsUnit::Pixel);

		if (Ind_Piedra[i] != -1)
			Ind_Piedra[i]--;
	}
}
//obtener posicion de la bomba 

void CJuego::empieza_explosion(Graphics ^r, int px, int py, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	jugador->empieza_explosion(r, px, py, img, img1, img2, P1, P2, piedras, D1, D2, D3, poder);
}
void CJuego::ubica_bomba_en_X()
{
	jugador->ubica_bomba_en_X();
}
void CJuego::ubica_bomba_en_Y()
{
	jugador->ubica_bomba_en_Y();
}
int CJuego::getB()
{
	return jugador->getB();
}
int CJuego::getbomba_x(int i)
{
	return jugador->getbomba_x(i);
}
int CJuego::getbomba_y(int i)
{
	return jugador->getbomba_y(i);
}
void CJuego::agregarbomba(int cont)
{
	jugador->agregarbomba(cont);
}
void CJuego::pintarbomba(Graphics ^g, Bitmap ^img)
{
	jugador->pintarbomba(g, img);
}
void CJuego::moverbomba(Graphics ^r)
{
	jugador->moverbomba(r, P1, P2, piedras, E1, E2, enemigo);
}
void CJuego::eliminabomba()
{
	jugador->eliminabomba();
}
bool CJuego::explotabomba()
{
	return jugador->explotabomba();
}
//Poder 
void CJuego::setDI(int D1)
{
	this->D1 = D1;
}
void CJuego::setDII(int D2)
{
	this->D2 = D2;
}
void CJuego::setDIII(int D3)
{
	this->D3 = D3;
}
void CJuego::pintar_poder(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	for (int i = 0; i < D1 + D2 + D3; i++){
		if (dynamic_cast<CPoderBomba*>(poder[i])){
			poder[i]->pintar(g, img);
		}
		if (dynamic_cast<CPoderFlama*>(poder[i])){
			poder[i]->pintar(g, img1);
		}
		if (dynamic_cast<CPoderVida*>(poder[i])){
			poder[i]->pintar(g, img2);
		}
	}
}
void CJuego::agregar_poder()
{
	Random ^g = gcnew Random();

	int *poder1_x = new int[D1];  int *poder1_y = new int[D1];
	int *poder2_x = new int[D2];  int *poder2_y = new int[D2];
	int *poder3_x = new int[D3];  int *poder3_y = new int[D3];

	bool COLOCA = true;
	int f = 1;
	int c = 1;

	for (int i = 0; i < D1; i++)
	{
		do
		{
			COLOCA = true;
			int posladri2 = g->Next(P1, P1 + P2);
			poder1_x[i] = piedras[posladri2]->getx();
			poder1_y[i] = piedras[posladri2]->gety();
			for (int j = 0; j < i; j++)
				if (poder1_x[j] == poder1_x[i] && poder1_y[j] == poder1_y[i])
					COLOCA = false;
		} while (!COLOCA);
	}
	for (int i = 0; i < D2; i++)
	{
		do
		{
			COLOCA = true;
			int posladri2 = g->Next(P1, P1 + P2);
			poder2_x[i] = piedras[posladri2]->getx();
			poder2_y[i] = piedras[posladri2]->gety();
			for (int j = 0; j < D1; j++)
				if (poder1_x[j] == poder2_x[i] && poder1_y[j] == poder2_y[i])
					COLOCA = false;
			for (int j = 0; j < i; j++)
				if (poder2_x[j] == poder2_x[i] && poder2_y[j] == poder2_y[i])
					COLOCA = false;
		} while (!COLOCA);
	}
	for (int i = 0; i < D3; i++)
	{
		do
		{
			COLOCA = true;
			int posladri2 = g->Next(P1, P1 + P2);
			poder3_x[i] = piedras[posladri2]->getx();
			poder3_y[i] = piedras[posladri2]->gety();
			for (int j = 0; j < D1; j++)
				if (poder1_x[j] == poder3_x[i] && poder1_y[j] == poder3_y[i])
					COLOCA = false;
			for (int j = 0; j < D2; j++)
				if (poder2_x[j] == poder3_x[i] && poder2_y[j] == poder3_y[i])
					COLOCA = false;
			for (int j = 0; j < i; j++)
				if (poder3_x[j] == poder3_x[i] && poder3_y[j] == poder3_y[i])
					COLOCA = false;
		} while (!COLOCA);
	}

	poder = new CPoder*[D1 + D2 + D3];
	for (int i = 0; i < D1; i++)
		poder[i] = new CPoderBomba(poder1_x[i], poder1_y[i]);
	for (int i = D1; i < D1 + D2; i++)
		poder[i] = new CPoderFlama(poder2_x[i - D1], poder2_y[i - D1]);
	for (int i = D1 + D2; i < D1 + D2 + D3; i++)
		poder[i] = new CPoderVida(poder3_x[i - (D1 + D2)], poder3_y[i - (D1 + D2)]);
}
void CJuego::eliminapoder(int pos)
{
	int j = 0;
	if (D1 + D2 + D3 > 0)
	{
		CPoder **temp = new CPoder*[D1 + D2 + D3 - 1];

		for (int i = 0; i < D1 + D2 + D3; i++)
		{
			if (i != pos)
			{
				temp[j] = poder[i];
				j++;
			}
			else
				delete poder[pos];
		}
		if (poder != NULL)
			delete[]poder;

		poder = temp;

		if (pos < D1)
			D1--;
		else
			if (pos < D2)
				D2--;
			else
				D3--;
	}
}
// Enemigo 
void CJuego::agregar_enemigo()
{
	Random ^g = gcnew Random();
	bool pone;
	int *enemigo1_x = new int[E1];   int *enemigo1_y = new int[E1];
	int *enemigo2_x = new int[E2];   int *enemigo2_y = new int[E2];
	int *enemigo3_x = new int[E3];   int *enemigo3_y = new int[E3];

	for (int i = 0; i < E1; i++)
	{
		do
		{
			pone = true;

			enemigo1_x[i] = 35 * (g->Next(3, 13));
			enemigo1_y[i] = 35 * (g->Next(3, 13));
			if (enemigo1_x[i] == jugador->getx() && enemigo1_y[i] == jugador->gety())
				pone = false;
			for (int b = 0; b < P1 + P2; b++)
				if (piedras[b]->getx() == enemigo1_x[i] && piedras[b]->gety() == enemigo1_y[i])
					pone = false;
			for (int d = 0; d < i; d++)
				if (enemigo1_x[i] == enemigo1_x[d] && enemigo1_y[d] == enemigo1_y[d])
					pone = false;
		} while (!pone);
	}
	for (int i = 0; i < E2; i++)
	{
		do
		{
			pone = true;
			enemigo2_x[i] = 35 * (g->Next(3, 13));
			enemigo2_y[i] = 35 * (g->Next(3, 13));
			if (enemigo2_x[i] == jugador->getx() && enemigo2_y[i] == jugador->gety())
				pone = false;
			for (int a = 0; a < E1; a++)
				if (enemigo2_x[i] == enemigo1_x[a] && enemigo2_y[i] == enemigo1_y[a])
					pone = false;
			for (int c = 0; c < P1 + P2; c++)
				if (piedras[c]->getx() == enemigo2_x[i] && piedras[c]->gety() == enemigo2_y[i])
					pone = false;
			for (int b = 0; b < i; b++)
				if (enemigo2_x[i] == enemigo2_x[b] && enemigo2_y[i] == enemigo2_y[b])
					pone = false;
		} while (!pone);
	}
	for (int i = 0; i < E3; i++)
	{
		do
		{
			pone = true;
			enemigo3_x[i] = 35 * (g->Next(3, 13));
			enemigo3_y[i] = 35 * (g->Next(3, 13));
			if (enemigo3_x[i] == jugador->getx() && enemigo3_y[i] == jugador->gety())
				pone = false;
			for (int a = 0; a < E1 + E2; a++)
				if (enemigo3_x[i] == enemigo1_x[a] && enemigo3_y[i] == enemigo1_y[a])
					pone = false;
			for (int c = 0; c < P1 + P2; c++)
				if (piedras[c]->getx() == enemigo3_x[i] && piedras[c]->gety() == enemigo3_y[i])
					pone = false;
			for (int b = 0; b < i; b++)
				if (enemigo3_x[i] == enemigo3_x[b] && enemigo2_y[i] == enemigo3_y[b])
					pone = false;
		} while (!pone);
	}

	enemigo = new CEnemigo*[E1 + E2 + E3];
	for (int i = 0; i < E1; i++)
		enemigo[i] = new CEnemigo1(enemigo1_x[i], enemigo1_y[i], 5, 5, dic, an, al);
	for (int i = E1; i < E1 + E2; i++)
		enemigo[i] = new CEnemigo2(enemigo2_x[i - E1], enemigo2_y[i - E1], 5, 5, dic, an, al);
	for (int i = E1 + E2; i < E1 + E2 + E3; i++)
		enemigo[i] = new CEnemigo3(enemigo3_x[i - (E1 + E2)], enemigo3_y[i - (E1 + E2)], 5, 5, dic, an, al);
}
void CJuego::pintarenemigo(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2, Bitmap ^img3, Bitmap ^img4, Bitmap ^img5)
{
	for (int i = 0; i < E1 + E2 + E3; i++){
		if (dynamic_cast<CEnemigo1*>(enemigo[i])){
			enemigo[i]->pintar(r, img, img1);
		}
		if (dynamic_cast<CEnemigo2*>(enemigo[i])){
			enemigo[i]->pintar(r, img2, img3);
		}
		if (dynamic_cast<CEnemigo3*>(enemigo[i])){
			enemigo[i]->pintar(r, img4, img5);
		}
	}
}
void CJuego::moverenemigo(Graphics ^r)
{
	bool mov;
	Random ^a = gcnew Random(DateTime::Now.Ticks);
	Random ^g = gcnew Random(DateTime::Now.Ticks);
	int limite_Y = 0;

	for (int j = 0; j < E1 + E2 + E3; j++)
	{
		int cont = 0;
		mov = true;
		do
		{
			if (!mov || enemigo[j]->getdir() == 0)
				enemigo[j]->setdir(g->Next(1, 5));

			if (cont > 10)
			{
				enemigo[j]->setdir(cont - 10);
				if (cont - 10 == 5)
					enemigo[j]->setdir(0);
			}
			mov = true;

			for (int i = 0; i < A; i++)
			{
				if (artificio[i]->getx() == enemigo[j]->getx() && artificio[i]->gety() == enemigo[j]->gety() && enemigo[j]->getdir() == 1)//DERECHA
				{
					int cambia = a->Next(0, 2);
					if (cambia == 1)
						enemigo[j]->setdir(g->Next(1, 5));
				}
				if (artificio[i]->getx() == enemigo[j]->getx() && artificio[i]->gety() == enemigo[j]->gety() && enemigo[j]->getdir() == 2)//IZQUIERDA
				{
					int cambia = a->Next(0, 2);
					if (cambia == 1)
						enemigo[j]->setdir(g->Next(1, 5));
				}
				if (artificio[i]->getx() == enemigo[j]->getx() && artificio[i]->gety() == (enemigo[j]->gety()) && enemigo[j]->getdir() == 3)//ABAJO
				{
					int cambia = a->Next(0, 2);
					if (cambia == 1)
						enemigo[j]->setdir(g->Next(1, 5));
				}
				if (artificio[i]->getx() == enemigo[j]->getx() && artificio[i]->gety() == (enemigo[j]->gety()) && enemigo[j]->getdir() == 4)//ARRIBA
				{
					int cambia = a->Next(0, 2);
					if (cambia == 1)
						enemigo[j]->setdir(g->Next(1, 5));
				}
			}
			for (int i = 0; i < P1 + P2; i++)
			{
				if (piedras[i]->getx() == (enemigo[j]->getx() + 35) && piedras[i]->gety() == enemigo[j]->gety() && enemigo[j]->getdir() == 1)
					mov = false;
				if (piedras[i]->getx() == (enemigo[j]->getx() - 35) && piedras[i]->gety() == enemigo[j]->gety() && enemigo[j]->getdir() == 2)
					mov = false;
				if (piedras[i]->getx() == enemigo[j]->getx() && piedras[i]->gety() == (enemigo[j]->gety() + 35) && enemigo[j]->getdir() == 3)
					mov = false;
				if (piedras[i]->getx() == enemigo[j]->getx() && piedras[i]->gety() == (enemigo[j]->gety() - 35) && enemigo[j]->getdir() == 4)
					mov = false;
			}

			if (enemigo[j]->getx() + enemigo[j]->getlado() >= r->VisibleClipBounds.Width - 115 && enemigo[j]->getdir() == 1)//DERECHA
				mov = false;
			if (enemigo[j]->getx() <= 35 && enemigo[j]->getdir() == 2)//IZQUIERDA
				mov = false;
			if (enemigo[j]->gety() + enemigo[j]->getlado() >= r->VisibleClipBounds.Height - 37 && enemigo[j]->getdir() == 3)//ABAJO
				mov = false;
			if (enemigo[j]->gety() <= 35 && enemigo[j]->getdir() == 4)//ARRIBA
				mov = false;

			for (int k = 0; k < jugador->getB(); k++)
			{
				if (enemigo[j]->getx() == jugador->getbomba_x(k) - 35 && enemigo[j]->gety() == jugador->getbomba_y(k) && enemigo[j]->getdir() == 1)
					mov = false;
				if (enemigo[j]->getx() == jugador->getbomba_x(k) + 35 && enemigo[j]->gety() == jugador->getbomba_y(k) && enemigo[j]->getdir() == 2)
					mov = false;
				if (enemigo[j]->getx() == jugador->getbomba_x(k) && enemigo[j]->gety() == jugador->getbomba_y(k) - 35 && enemigo[j]->getdir() == 3)
					mov = false;
				if (enemigo[j]->getx() == jugador->getbomba_x(k) && enemigo[j]->gety() == jugador->getbomba_y(k) + 35 && enemigo[j]->getdir() == 4)
					mov = false;
			}
			cont++;
		} while (!mov);
	}
	for (int i = 0; i < E1 + E2 + E3; i++){
		enemigo[i]->mover(limite_Y);
	}
}
void CJuego::eliminarenemigo(int pos)
{
	int j = 0;
	if (E1 + E2 + E3 > 0)
	{
		CEnemigo **temp = new CEnemigo*[E1 + E2 + E3- 1];

		for (int i = 0; i < E1 + E2 + E3; i++)
		{
			if (i != pos)
			{
				temp[j] = enemigo[i];
				j++;
			}
			else
				delete enemigo[pos];
		}

		if (enemigo != NULL)
			delete[]enemigo;

		enemigo = temp;

		if (pos < E1)
			E1--;
		else
			if (pos < E1 + E2)
				E2--;
			else
				if (pos < E1 + E2 + E3)
					E3--;
	}
}

//cuando el enemigo muere y variables de retorno
bool CJuego::muere_enemigo(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2)
{
	return 1;
}
void CJuego::setE1(int E1)
{
	this->E1 = E1;
}
void CJuego::setE2(int E2)
{
	this->E2 = E2;
}
void CJuego::setE3(int E3)
{
	this->E3 = E3;
}
int CJuego::getE1()
{
	return E1;
}
int CJuego::getE2()
{
	return E2;
}
int CJuego::getE3()
{
	return E3;
}
//Artificio
void CJuego::agregar_artificio()
{
	Random ^g = gcnew Random();
	int f, c;
	int *artificio_x = new int[A];    int *artificio_y = new int[A];
	
	f = c = 0;
	for (int i = 0; i < A; i++)
	{
		artificio_x[i] = 35 + 70 * f;
		artificio_y[i] = 35 + 70 * c;

		f++;
		if (f > 6)
		{
			f = 0;
			c++;
			if (c > 6)
				c = 0;
		}
	}

	artificio = new CArtificio*[A];
	for (int i = 0; i < A; i++)
		artificio[i] = new CArtificio(artificio_x[i], artificio_y[i]);
}
