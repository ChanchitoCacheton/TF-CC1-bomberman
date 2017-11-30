#pragma once
class CPoderPatear : public CPoder
{
	public:
		CPoderPatear(int x, int y);
		~CPoderPatear();
		void pintar(Graphics ^g, Bitmap ^img);
};

