#pragma once
class CPiedraI : public CPiedra
{
	public:
		CPiedraI(int x, int y);
		~CPiedraI();
		void pintar(Graphics ^r, Bitmap ^img);
};

