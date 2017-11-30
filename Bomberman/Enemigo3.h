#pragma once
class CEnemigo3 : public CEnemigo
{
public:
		CEnemigo3(int x, int y, int dx, int dy, int dir, int limx, int limy);
		~CEnemigo3();
		void pintar(Graphics ^r, Bitmap ^img, Bitmap ^img1);
		void mover(int limite_Y);
};

