#pragma once
class CPoderVida : public CPoder
{
	public:
		CPoderVida(int x, int y);
		~CPoderVida();
		void pintar(Graphics ^g, Bitmap ^img);
};

