#pragma once

class CEnemigo1 : public CEnemigo
{
	public:
		CEnemigo1(int x, int y, int dx, int dy, int dir, int limx, int limy);
		~CEnemigo1();
		void pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1);
		void mover(int limite_Y);
};

