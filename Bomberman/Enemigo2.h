#pragma once
class CEnemigo2 : public CEnemigo
{
	public:
		CEnemigo2(int x, int y, int dx, int dy, int dir, int limx, int limy);
		~CEnemigo2();
		void pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1);
		void mover(int limite_Y);
};

