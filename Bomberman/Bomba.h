#pragma once
class CBomba
{
	private:
		bool movbomba;
		int x, y, cont, lado, ind, dx, dy, limit;
		int dir;
	public:
		CBomba(int x, int y, int cont, int limit);
		~CBomba();
		void pintar(Graphics ^r, Bitmap ^img);
		void mover(Graphics ^r);
		int getdir();
		int getx();
		int gety();
		int getcont();
		void setdir(int dir);
		void setcont(int cont);
		void setx(int x);
		void sety(int y);
		void setdx(int dx);
		void setdy(int dy);
		void movBomba(bool movbomba);
};

