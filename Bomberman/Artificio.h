#pragma once
using namespace System::Drawing;
class CArtificio
{
	private:
		int x, y;
	public:
		CArtificio(int x, int y);
		~CArtificio();
		void pintar_artificio(Graphics ^g, Bitmap ^img);
		int getx();
		int gety();
};

