#pragma once
class CPiedra
{
	protected:
		int x, y, lado;
	public:
		CPiedra(int x, int y);
		~CPiedra();
		virtual void pintar(Graphics ^r, Bitmap ^img)=0;
		int getlado();
		int getx();
		int gety();
};

