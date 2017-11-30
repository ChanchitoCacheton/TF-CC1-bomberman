#pragma once
class CPoderFlama : public CPoder
{
	public:
		CPoderFlama(int x, int y);
		~CPoderFlama();
		void pintar(Graphics ^g, Bitmap ^img);
};

