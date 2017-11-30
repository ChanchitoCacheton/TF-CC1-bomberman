#pragma once
class CPoderBomba : public CPoder
{
	public:
		CPoderBomba(int x, int y);
		~CPoderBomba();
		void pintar(Graphics ^g, Bitmap ^img);
};

