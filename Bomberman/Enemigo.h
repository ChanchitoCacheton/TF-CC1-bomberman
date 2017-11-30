#pragma once




class CEnemigo
{
	protected:
		int x, y, dx, dy;
		int ind, lado, lado2, limx, limy, dir, indm;
		int resistencia;
		bool golpeado;
		bool murio;
	public:
		CEnemigo(int x, int y, int dx, int dy, int dir, int limx, int limy);
		~CEnemigo();
		virtual void pintar(Graphics ^g, Bitmap ^img, Bitmap ^img1) abstract;
		virtual void mover(int limite_Y) abstract;
		void setdir(int dir);
		void setdx(int dx);
		void setdy(int dy);
		void setresistencia(int resistencia);
		void setgolpeado(bool golpeado);
		void setmurio(bool murio);
		int getx();
		int gety();
		int getlado();
		int getlado2();
		int getdir();
		int getdx();
		int getdy();
		int getresistencia();
		int getindm();
		bool getmurio();
		bool getgolpeado();
};

