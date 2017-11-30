#pragma once

class CJugador
{
	private:
		CBomba **bomba;
		int x, y, lado, ind, a, h, aux, ind2;
		bool exp1, exp2, exp3, exp4, muerto, baila;
		int B, cont, ind1, vidas, maxb, expb, baile, temp;
		int ind_ex1, ind_ex2, ind_ex3, ind_ex4, ind_ex5, ind_ex6, ind_ex7, ind_ex8, ind_ex9;
	public:
		CJugador();
		~CJugador();
		void patear_bomba();
		void pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void mover(Graphics ^r, int dx, int dy, int t, int PI, int PII, CPiedra **vec);
		bool revive();
		int getx();
		int gety();
		int getlado();
		int geta();
		int geth();
		int Vidas();
		int MAXB();
		int EXPB();
		int BAILE();
		bool BAILA();
		void BAILE(int baile);
		void IND1(int ind1);
		void IND(int ind);
		void BAILA(bool baila);
		void Vidas(int vidas);
		void MAXB(int maxb);
		void EXPB(int expb);
		void setx(int x);
		void sety(int y);
		bool EXP1();
		bool EXP2();
		bool EXP3();
		bool EXP4();
		void EXP1(bool exp1);
		void EXP2(bool exp2);
		void EXP3(bool exp3);
		void EXP4(bool exp4);
		void MUERTO(bool muerto);
		//**** Bomba ****//
		void agregarbomba(int cont);
		void pintarbomba(Graphics ^g, Bitmap ^img);
		void moverbomba(Graphics ^r, int PI, int PII, CPiedra **vec, int E1, int E2, CEnemigo**vec1);
		void detener_bomba(int PI, int PII, CPiedra **vec, int E1, int E2, CEnemigo**vec1);
		void eliminabomba();
		bool explotabomba();
		int getbomba_x(int i);
		int getbomba_y(int i);
		int getB();
		void empieza_explosion(Graphics ^r, int px, int py, Bitmap ^img, Bitmap ^img1, Bitmap ^img2, int PI, int PII, CPiedra **Pvec, int DI, int DII, int DIII, CPoder **poder);
		void ubica_bomba_en_X();
		void ubica_bomba_en_Y();
		void MOVBOMBA(int pos, bool movbomba);
};

