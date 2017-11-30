#pragma once
class CPoder
{
	protected:
		int x, y, lado;
	public:
		CPoder(int x, int y);
		~CPoder();
		virtual void pintar(Graphics ^g, Bitmap ^img)=0;
		int getx();
		int gety();
		int getlado();
};

