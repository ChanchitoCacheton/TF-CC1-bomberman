#pragma once
#include "Artificio.h"

class CJuego
{
	private:
		int P1, P2, capacidad_maxima;
		int D1, D2, D3;
		int E1, E2, E3;
		int A, dic, dic2, an, al, an2, al2;
		int *X_piedra, *Y_piedra, *Ind_Piedra, cont;
		int *x_enemigo, *y_enemigo, *Ind, *Pos, cont2;
		int puntaje, nivel, stage;
		CPiedra **piedras;
		CJugador *jugador;
		CPoder **poder;
		CEnemigo **enemigo;
		CArtificio **artificio;
	public:

		
		//variables para la deteccion de la ventana (ancho y alto maximo)
		CJuego(int anchop, int altop);
		~CJuego();



		//funciones del jugador
		void pintar_jugador(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void mover_jugador(Graphics ^g, int t);
		void setXJugador(int x);
		void setYJugador(int y);

		//funciones de las piedras y colisiones
		void setPI(int PI);
		void setPII(int PII);
		void agregar_piedras();
		void pintar_piedras(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void eliminapiedra(int pos);
		void destruirse(Graphics ^r, Bitmap ^img);


		// funciones de comportamiento del juego
		void setA(int A);
		void Limpiar_mapa();
		//variables int
		int FASE();
		int Puntaje();
		int Nivel();

		//funciones de comportamiento sobre los mapas 
		void FASE(int stage);
		void Nivel(int nivel);

		//funciones de comportamiento sobre el jugador , pared , enemigo
		void Pintar_Vidas(Graphics ^g, Bitmap ^img, Bitmap ^img1);
		bool destruye(int aux1, int aux2);
		void cojer_poder();
		//pequeña colision
		void choca_con_enemigo();
		//application exit
		bool GameOver();



		
		//funciones de las bombas
		int getB();
		int getbomba_x(int i);
		int getbomba_y(int i);
		void agregarbomba(int cont);
		void pintarbomba(Graphics ^g, Bitmap ^img);
		void moverbomba(Graphics ^r);
		void eliminabomba();
		bool explotabomba();
		void empieza_explosion(Graphics ^r, int px, int py, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void ubica_bomba_en_X();
		void ubica_bomba_en_Y();

		/* Accion de comportamiento sobre la bomba y el jugador */
		void patear_bomba();



		//funciones para el enemigo
		void agregar_enemigo();
		void pintarenemigo(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2, Bitmap ^img3, Bitmap ^img4, Bitmap ^img5);
		void moverenemigo(Graphics ^r);
		void eliminarenemigo(int pos);
		bool muere_enemigo(Graphics ^r, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void setE1(int E1);
		void setE2(int E2);
		void setE3(int E3);
		int getE1();
		int getE2();
		int getE3();

		//funciones para los poderes y ubicaciones de estos

		void setDI(int D1);
		void setDII(int D2);
		void setDIII(int D3);
		void pintar_poder(Graphics ^g, Bitmap ^img, Bitmap ^img1, Bitmap ^img2);
		void agregar_poder();
		void eliminapoder(int pos);


		//el artificio
		void agregar_artificio();
};

