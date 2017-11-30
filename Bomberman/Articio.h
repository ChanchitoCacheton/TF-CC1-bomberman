#pragma once

class CArticio
{
	private:
		int x, y;
	public:
		CArticio(int x, int y);
		~CArticio();
		void pintar_artificio(Graphics ^g, Bitmap ^img);
		int getx();
		int gety();
};

