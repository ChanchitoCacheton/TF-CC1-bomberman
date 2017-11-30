#pragma once
#include "stdafx.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int contfondo;
		CJuego *juego;
		int mov;
		int aux1, aux2;
		int contexp;
		int contexp2;
		int min, seg;
	private: System::Windows::Forms::Button^  btnIniciar;
	private: System::Windows::Forms::Button^  btnInstrucciones;
	private: System::Windows::Forms::Button^  btnSalir;
	private: System::Windows::Forms::PictureBox^  fondoinicio;
	private: System::Windows::Forms::PictureBox^  bomba;
	private: System::Windows::Forms::PictureBox^  explota3;
	private: System::Windows::Forms::PictureBox^  explota2;
	private: System::Windows::Forms::PictureBox^  explota1;
	private: System::Windows::Forms::Timer^  DetonaBomba;

	private: System::Windows::Forms::Timer^  Nivel2;
	private: System::Windows::Forms::Timer^  Nivel3;
	private: System::Windows::Forms::Timer^  Nivel4;
	private: System::Windows::Forms::PictureBox^  flame;
	private: System::Windows::Forms::PictureBox^  bomb;
	private: System::Windows::Forms::PictureBox^  life;
	private: System::Windows::Forms::PictureBox^  Niv2;
	private: System::Windows::Forms::PictureBox^  Niv3;


	private: System::Windows::Forms::PictureBox^  FONDO;
	private: System::Windows::Forms::PictureBox^  FINALMAP;
	private: System::Windows::Forms::PictureBox^  foca;
	private: System::Windows::Forms::PictureBox^  fantasma;
	private: System::Windows::Forms::PictureBox^  EnemigoMuerte;
	private: System::Windows::Forms::PictureBox^  Destruccion_Piedra;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Timer^  Tiempo;
	private: System::Windows::Forms::PictureBox^  bombermanWin;
	private: System::Windows::Forms::PictureBox^  EnemigoMuerte2;
	private: System::Windows::Forms::PictureBox^  hammer;
	private: System::Windows::Forms::PictureBox^  EnemigoMuerte3;
	private: System::Windows::Forms::PictureBox^  Lose;
	private: System::Windows::Forms::Button^  btnReiniciar;
	private: System::Windows::Forms::Button^  btnSalir2;





			 bool moverse;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//variables que van a correr en los timer
			contfondo = 0;
			juego = new CJuego(this->ClientSize.Width, this->ClientSize.Height);
			mov = 0;
			moverse = true;
			contexp = contexp2 = 0;
			min = 0;
			seg = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  Juego;
	private: System::Windows::Forms::PictureBox^  bomberman;
	private: System::Windows::Forms::PictureBox^  piedra;
	private: System::Windows::Forms::PictureBox^  muertebomberman;
	private: System::Windows::Forms::PictureBox^  ladrillo;
	private: System::Windows::Forms::PictureBox^  Mapa1;
	private: System::Windows::Forms::PictureBox^  murio1;
	private: System::Windows::Forms::PictureBox^  vida1;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:

		//validacion de todos los picturebox
		Bitmap ^Bomberman_Trans;
		Bitmap ^imgtrans2;
		Bitmap ^Piedra_Trans;
		Bitmap ^Ladrillo_Trans;
		Bitmap ^BombermanM_Trans;
		Bitmap ^Bomba_Trans;
		Bitmap ^ExplosionCentro_Trans;
		Bitmap ^ExplosionLimite_Trans;
		Bitmap ^ExplosionCuerpo_Trans;
		Bitmap ^Enemigo1_Trans;
		Bitmap ^Enemigo2_Trans;
		Bitmap ^Enemigo3_Trans;
		Bitmap ^Enemigo1M_Trans;
		Bitmap ^Enemigo2M_Trans;
		Bitmap ^Enemigo3M_Trans;
		Bitmap ^DestruccionPiedra_Trans;
		Bitmap ^BombermanW_Trans;
	private: System::Windows::Forms::PictureBox^  Nivel1;
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: void GameOver()
	{
		if (juego->GameOver()){
			seg = min = 0;
			juego->setXJugador(35);
			juego->setYJugador(35);
			AgregarObjetos(64, 65, juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel());
			contfondo = 0;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
		}
	}

			 //la explosion tendra que obtener posiciones para realizar el comportamiento de eliminar , antes de eso siempre tendra un contador
	private: void ExplosionBomba(Graphics ^g)
	{
		if (juego->getB() > 0)
		{
			aux1 = juego->getbomba_x(0);
			aux2 = juego->getbomba_y(0);
		}
		else
			contexp = 0;
		if (juego->explotabomba())
		{
			juego->empieza_explosion(g, aux1, aux2, ExplosionLimite_Trans, ExplosionCuerpo_Trans, ExplosionCentro_Trans);
			contexp2++;
		}
		if (contexp2 == 5)
		{
			contexp2 = 0;
			juego->eliminabomba();
			juego->destruye(aux1, aux2);
		}
	}
	private: void AgregarObjetos(int P1, int P2, int E1, int E2, int E3, int D1, int D2, int D3)
	{

		//por orden
		juego->agregar_artificio();
		juego->setPI(P1);
		juego->setPII(P2);
		juego->agregar_piedras();
		juego->setE1(E1);
		juego->setE2(E2);
		juego->setE3(E3);
		juego->agregar_enemigo();
		juego->setDI(D1);
		juego->setDII(D2);
		juego->setDIII(D3);
		juego->agregar_poder();
	}
	private: void Tablero_Mapa(Graphics ^g, int gWidth, int gHeight)
	{
		switch (juego->Nivel())
		{
			case 1: g->DrawImage(this->Mapa1->Image, 0, 0, gWidth - 80, gHeight); break;
			case 2: g->DrawImage(this->FONDO->Image, 0, 0, gWidth - 80, gHeight); break;
			case 3: g->DrawImage(this->FINALMAP->Image, 0, 0, gWidth - 80, gHeight); break;
			case 4: g->DrawImage(this->Mapa1->Image, 0, 0, gWidth - 80, gHeight); break;
		}

		label4->Text = juego->Puntaje().ToString();
		label4->Left = 565 - label4->Width / 2;
		label5->Text = min.ToString() + ":" + seg.ToString();
		label5->Left = 568 - label5->Width / 2;
	}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->bomberman = (gcnew System::Windows::Forms::PictureBox());
			this->piedra = (gcnew System::Windows::Forms::PictureBox());
			this->muertebomberman = (gcnew System::Windows::Forms::PictureBox());
			this->ladrillo = (gcnew System::Windows::Forms::PictureBox());
			this->Mapa1 = (gcnew System::Windows::Forms::PictureBox());
			this->murio1 = (gcnew System::Windows::Forms::PictureBox());
			this->vida1 = (gcnew System::Windows::Forms::PictureBox());
			this->Nivel1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->fondoinicio = (gcnew System::Windows::Forms::PictureBox());
			this->bomba = (gcnew System::Windows::Forms::PictureBox());
			this->explota3 = (gcnew System::Windows::Forms::PictureBox());
			this->explota2 = (gcnew System::Windows::Forms::PictureBox());
			this->explota1 = (gcnew System::Windows::Forms::PictureBox());
			this->DetonaBomba = (gcnew System::Windows::Forms::Timer(this->components));
			this->Nivel2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Nivel3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Nivel4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->flame = (gcnew System::Windows::Forms::PictureBox());
			this->bomb = (gcnew System::Windows::Forms::PictureBox());
			this->life = (gcnew System::Windows::Forms::PictureBox());
			this->Niv2 = (gcnew System::Windows::Forms::PictureBox());
			this->Niv3 = (gcnew System::Windows::Forms::PictureBox());
			this->FONDO = (gcnew System::Windows::Forms::PictureBox());
			this->FINALMAP = (gcnew System::Windows::Forms::PictureBox());
			this->foca = (gcnew System::Windows::Forms::PictureBox());
			this->fantasma = (gcnew System::Windows::Forms::PictureBox());
			this->EnemigoMuerte = (gcnew System::Windows::Forms::PictureBox());
			this->Destruccion_Piedra = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Tiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->bombermanWin = (gcnew System::Windows::Forms::PictureBox());
			this->EnemigoMuerte2 = (gcnew System::Windows::Forms::PictureBox());
			this->hammer = (gcnew System::Windows::Forms::PictureBox());
			this->EnemigoMuerte3 = (gcnew System::Windows::Forms::PictureBox());
			this->Lose = (gcnew System::Windows::Forms::PictureBox());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->btnSalir2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomberman))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedra))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->muertebomberman))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ladrillo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Mapa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->murio1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vida1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Nivel1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fondoinicio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomba))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->flame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->life))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Niv2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Niv3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FONDO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FINALMAP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->foca))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fantasma))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Destruccion_Piedra))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bombermanWin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hammer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lose))->BeginInit();
			this->SuspendLayout();
			
			// Juego
			 
			this->Juego->Enabled = true;
			this->Juego->Interval = 47;
			this->Juego->Tick += gcnew System::EventHandler(this, &MyForm::Juego_Tick);
			 
			//player
			 
			this->bomberman->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bomberman.Image")));
			this->bomberman->Location = System::Drawing::Point(12, 12);
			this->bomberman->Name = L"bomberman";
			this->bomberman->Size = System::Drawing::Size(420, 35);
			this->bomberman->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->bomberman->TabIndex = 1;
			this->bomberman->TabStop = false;
			this->bomberman->Visible = false;
			// 
			// piedra
			// 
			this->piedra->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"piedra.Image")));
			this->piedra->Location = System::Drawing::Point(445, 12);
			this->piedra->Name = L"piedra";
			this->piedra->Size = System::Drawing::Size(35, 35);
			this->piedra->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->piedra->TabIndex = 3;
			this->piedra->TabStop = false;
			this->piedra->Visible = false;
			// 
			//  llamado del sprite "muerte"
			// 
			this->muertebomberman->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"muertebomberman.Image")));
			this->muertebomberman->Location = System::Drawing::Point(12, 53);
			this->muertebomberman->Name = L"muertebomberman";
			this->muertebomberman->Size = System::Drawing::Size(281, 35);
			this->muertebomberman->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->muertebomberman->TabIndex = 15;
			this->muertebomberman->TabStop = false;
			this->muertebomberman->Visible = false;
			
			// ladrillo p1
		
			this->ladrillo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ladrillo.Image")));
			this->ladrillo->Location = System::Drawing::Point(486, 12);
			this->ladrillo->Name = L"ladrillo";
			this->ladrillo->Size = System::Drawing::Size(35, 35);
			this->ladrillo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->ladrillo->TabIndex = 16;
			this->ladrillo->TabStop = false;
			this->ladrillo->Visible = false;
			
			// Mapa1
			
			this->Mapa1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Mapa1.Image")));
			this->Mapa1->Location = System::Drawing::Point(12, 464);
			this->Mapa1->Name = L"Mapa1";
			this->Mapa1->Size = System::Drawing::Size(100, 50);
			this->Mapa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Mapa1->TabIndex = 20;
			this->Mapa1->TabStop = false;
			this->Mapa1->Visible = false;
			// 
			// murio1
			// 
			this->murio1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"murio1.Image")));
			this->murio1->Location = System::Drawing::Point(563, 12);
			this->murio1->Name = L"murio1";
			this->murio1->Size = System::Drawing::Size(30, 30);
			this->murio1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->murio1->TabIndex = 34;
			this->murio1->TabStop = false;
			this->murio1->Visible = false;
			// 
			// vida1
			// 
			this->vida1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->vida1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vida1.Image")));
			this->vida1->Location = System::Drawing::Point(527, 12);
			this->vida1->Name = L"vida1";
			this->vida1->Size = System::Drawing::Size(30, 30);
			this->vida1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->vida1->TabIndex = 35;
			this->vida1->TabStop = false;
			this->vida1->Visible = false;
			
			// Nivel1
			
			this->Nivel1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Nivel1.Image")));
			this->Nivel1->Location = System::Drawing::Point(118, 464);
			this->Nivel1->Name = L"Nivel1";
			this->Nivel1->Size = System::Drawing::Size(100, 50);
			this->Nivel1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Nivel1->TabIndex = 36;
			this->Nivel1->TabStop = false;
			this->Nivel1->Visible = false;
			 
			
			// inicializar
			this->btnIniciar->BackColor = System::Drawing::Color::MediumOrchid;
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnIniciar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnIniciar->Location = System::Drawing::Point(388, 332);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(189, 48);
			this->btnIniciar->TabIndex = 37;
			this->btnIniciar->Text = L"Juega!";
			this->btnIniciar->UseVisualStyleBackColor = false;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MyForm::btnIniciar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::SystemColors::Control;
			this->btnInstrucciones->Location = System::Drawing::Point(388, 398);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(189, 48);
			this->btnInstrucciones->TabIndex = 38;
			this->btnInstrucciones->Text = L"Acerca de";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MyForm::btnInstrucciones_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::DarkTurquoise;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSalir->Location = System::Drawing::Point(388, 455);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(189, 48);
			this->btnSalir->TabIndex = 39;
			this->btnSalir->Text = L"Nos vemos!";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MyForm::btnSalir_Click);
			// 
			// fondoinicio
			// 
			this->fondoinicio->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"fondoinicio.Image")));
			this->fondoinicio->Location = System::Drawing::Point(224, 464);
			this->fondoinicio->Name = L"fondoinicio";
			this->fondoinicio->Size = System::Drawing::Size(100, 50);
			this->fondoinicio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->fondoinicio->TabIndex = 40;
			this->fondoinicio->TabStop = false;
			this->fondoinicio->Visible = false;
			// 
			// bomba
			// 
			this->bomba->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bomba.Image")));
			this->bomba->Location = System::Drawing::Point(275, 357);
			this->bomba->Name = L"bomba";
			this->bomba->Size = System::Drawing::Size(210, 35);
			this->bomba->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->bomba->TabIndex = 41;
			this->bomba->TabStop = false;
			this->bomba->Visible = false;
			// 
			// explota3
			// 
			this->explota3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"explota3.Image")));
			this->explota3->Location = System::Drawing::Point(12, 217);
			this->explota3->Name = L"explota3";
			this->explota3->Size = System::Drawing::Size(35, 175);
			this->explota3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->explota3->TabIndex = 42;
			this->explota3->TabStop = false;
			this->explota3->Visible = false;
			// 
			// explota2
			// 
			this->explota2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"explota2.Image")));
			this->explota2->Location = System::Drawing::Point(53, 217);
			this->explota2->Name = L"explota2";
			this->explota2->Size = System::Drawing::Size(70, 175);
			this->explota2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->explota2->TabIndex = 43;
			this->explota2->TabStop = false;
			this->explota2->Visible = false;
			// 
			// explota1
			// 
			this->explota1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"explota1.Image")));
			this->explota1->Location = System::Drawing::Point(129, 217);
			this->explota1->Name = L"explota1";
			this->explota1->Size = System::Drawing::Size(140, 175);
			this->explota1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->explota1->TabIndex = 44;
			this->explota1->TabStop = false;
			this->explota1->Visible = false;
			// 
			// DetonaBomba
			// 
			this->DetonaBomba->Enabled = true;
			this->DetonaBomba->Interval = 50;
			this->DetonaBomba->Tick += gcnew System::EventHandler(this, &MyForm::ExpBomba_Tick);
			// 
			// Nivel2
			// 
			this->Nivel2->Interval = 55;
			this->Nivel2->Tick += gcnew System::EventHandler(this, &MyForm::Nivel2_Tick);
			// 
			// Nivel3
			// 
			this->Nivel3->Interval = 55;
			this->Nivel3->Tick += gcnew System::EventHandler(this, &MyForm::Nivel3_Tick);
			// 
			// Nivel4
			// 
			this->Nivel4->Interval = 55;
			this->Nivel4->Tick += gcnew System::EventHandler(this, &MyForm::Nivel4_Tick);
			// 
			// flame
			// 
			this->flame->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"flame.Image")));
			this->flame->Location = System::Drawing::Point(563, 48);
			this->flame->Name = L"flame";
			this->flame->Size = System::Drawing::Size(35, 35);
			this->flame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->flame->TabIndex = 52;
			this->flame->TabStop = false;
			this->flame->Visible = false;
			// 
			// bomb
			// 
			this->bomb->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bomb.Image")));
			this->bomb->Location = System::Drawing::Point(563, 89);
			this->bomb->Name = L"bomb";
			this->bomb->Size = System::Drawing::Size(35, 35);
			this->bomb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->bomb->TabIndex = 53;
			this->bomb->TabStop = false;
			this->bomb->Visible = false;
			// 
			// life
			// 
			this->life->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->life->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"life.Image")));
			this->life->Location = System::Drawing::Point(563, 130);
			this->life->Name = L"life";
			this->life->Size = System::Drawing::Size(35, 35);
			this->life->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->life->TabIndex = 54;
			this->life->TabStop = false;
			this->life->Visible = false;
			// 
			// Niv2
			// 
			this->Niv2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Niv2.Image")));
			this->Niv2->Location = System::Drawing::Point(12, 408);
			this->Niv2->Name = L"Niv2";
			this->Niv2->Size = System::Drawing::Size(100, 50);
			this->Niv2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Niv2->TabIndex = 55;
			this->Niv2->TabStop = false;
			this->Niv2->Visible = false;
			// 
			// Niv3
			// 
			this->Niv3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Niv3.Image")));
			this->Niv3->Location = System::Drawing::Point(118, 408);
			this->Niv3->Name = L"Niv3";
			this->Niv3->Size = System::Drawing::Size(100, 50);
			this->Niv3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Niv3->TabIndex = 56;
			this->Niv3->TabStop = false;
			this->Niv3->Visible = false;
			// 
			// FONDO
			// 
			this->FONDO->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"FONDO.Image")));
			this->FONDO->Location = System::Drawing::Point(224, 408);
			this->FONDO->Name = L"FONDO";
			this->FONDO->Size = System::Drawing::Size(100, 50);
			this->FONDO->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->FONDO->TabIndex = 57;
			this->FONDO->TabStop = false;
			this->FONDO->Visible = false;
			// 
			// FINALMAP
			// 
			this->FINALMAP->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"FINALMAP.Image")));
			this->FINALMAP->Location = System::Drawing::Point(330, 408);
			this->FINALMAP->Name = L"FINALMAP";
			this->FINALMAP->Size = System::Drawing::Size(100, 50);
			this->FINALMAP->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->FINALMAP->TabIndex = 58;
			this->FINALMAP->TabStop = false;
			this->FINALMAP->Visible = false;
			// 
			// foca
			// 
			this->foca->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"foca.Image")));
			this->foca->Location = System::Drawing::Point(12, 94);
			this->foca->Name = L"foca";
			this->foca->Size = System::Drawing::Size(420, 35);
			this->foca->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->foca->TabIndex = 59;
			this->foca->TabStop = false;
			this->foca->Visible = false;
			// 
			// fantasma
			// 
			this->fantasma->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"fantasma.Image")));
			this->fantasma->Location = System::Drawing::Point(12, 135);
			this->fantasma->Name = L"fantasma";
			this->fantasma->Size = System::Drawing::Size(420, 35);
			this->fantasma->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->fantasma->TabIndex = 60;
			this->fantasma->TabStop = false;
			this->fantasma->Visible = false;
			// 
			// EnemigoMuerte
			// 
			this->EnemigoMuerte->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EnemigoMuerte.Image")));
			this->EnemigoMuerte->Location = System::Drawing::Point(299, 53);
			this->EnemigoMuerte->Name = L"EnemigoMuerte";
			this->EnemigoMuerte->Size = System::Drawing::Size(140, 35);
			this->EnemigoMuerte->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->EnemigoMuerte->TabIndex = 61;
			this->EnemigoMuerte->TabStop = false;
			this->EnemigoMuerte->Visible = false;
			// 
			// Destruccion_Piedra
			// 
			this->Destruccion_Piedra->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Destruccion_Piedra.Image")));
			this->Destruccion_Piedra->Location = System::Drawing::Point(275, 316);
			this->Destruccion_Piedra->Name = L"Destruccion_Piedra";
			this->Destruccion_Piedra->Size = System::Drawing::Size(210, 35);
			this->Destruccion_Piedra->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->Destruccion_Piedra->TabIndex = 62;
			this->Destruccion_Piedra->TabStop = false;
			this->Destruccion_Piedra->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(543, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 19);
			this->label1->TabIndex = 63;
			this->label1->Text = L"Vidas";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(539, 287);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 19);
			this->label2->TabIndex = 64;
			this->label2->Text = L"Score";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Violet;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(539, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 19);
			this->label3->TabIndex = 65;
			this->label3->Text = L"Time";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(559, 332);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 19);
			this->label4->TabIndex = 66;
			this->label4->Text = L"0";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Violet;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(538, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 19);
			this->label5->TabIndex = 67;
			this->label5->Text = L"00:00";
			this->label5->Visible = false;
			// 
			// Tiempo
			// 
			this->Tiempo->Enabled = true;
			this->Tiempo->Interval = 1000;
			this->Tiempo->Tick += gcnew System::EventHandler(this, &MyForm::Tiempo_Tick);
			// 
			// bombermanWin
			// 
			this->bombermanWin->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bombermanWin.Image")));
			this->bombermanWin->Location = System::Drawing::Point(445, 53);
			this->bombermanWin->Name = L"bombermanWin";
			this->bombermanWin->Size = System::Drawing::Size(70, 35);
			this->bombermanWin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->bombermanWin->TabIndex = 68;
			this->bombermanWin->TabStop = false;
			this->bombermanWin->Visible = false;
			// 
			// EnemigoMuerte2
			// 
			this->EnemigoMuerte2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EnemigoMuerte2.Image")));
			this->EnemigoMuerte2->Location = System::Drawing::Point(275, 217);
			this->EnemigoMuerte2->Name = L"EnemigoMuerte2";
			this->EnemigoMuerte2->Size = System::Drawing::Size(140, 35);
			this->EnemigoMuerte2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->EnemigoMuerte2->TabIndex = 69;
			this->EnemigoMuerte2->TabStop = false;
			this->EnemigoMuerte2->Visible = false;
			// 
			// hammer
			// 
			this->hammer->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"hammer.Image")));
			this->hammer->Location = System::Drawing::Point(12, 176);
			this->hammer->Name = L"hammer";
			this->hammer->Size = System::Drawing::Size(420, 35);
			this->hammer->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->hammer->TabIndex = 70;
			this->hammer->TabStop = false;
			this->hammer->Visible = false;
			// 
			// EnemigoMuerte3
			// 
			this->EnemigoMuerte3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"EnemigoMuerte3.Image")));
			this->EnemigoMuerte3->Location = System::Drawing::Point(275, 258);
			this->EnemigoMuerte3->Name = L"EnemigoMuerte3";
			this->EnemigoMuerte3->Size = System::Drawing::Size(140, 35);
			this->EnemigoMuerte3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->EnemigoMuerte3->TabIndex = 71;
			this->EnemigoMuerte3->TabStop = false;
			this->EnemigoMuerte3->Visible = false;
			// 
			// Lose
			// 
			this->Lose->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Lose.Image")));
			this->Lose->Location = System::Drawing::Point(330, 464);
			this->Lose->Name = L"Lose";
			this->Lose->Size = System::Drawing::Size(100, 50);
			this->Lose->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Lose->TabIndex = 72;
			this->Lose->TabStop = false;
			this->Lose->Visible = false;
			// 
			// btnReiniciar
			// 
			this->btnReiniciar->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnReiniciar->Enabled = false;
			this->btnReiniciar->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnReiniciar->ForeColor = System::Drawing::Color::LightSteelBlue;
			this->btnReiniciar->Location = System::Drawing::Point(213, 135);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(189, 48);
			this->btnReiniciar->TabIndex = 73;
			this->btnReiniciar->Text = L"Reiniciar";
			this->btnReiniciar->UseVisualStyleBackColor = false;
			this->btnReiniciar->Visible = false;
			this->btnReiniciar->Click += gcnew System::EventHandler(this, &MyForm::btnReiniciar_Click);
			// 
			// btnSalir2
			// 
			this->btnSalir2->BackColor = System::Drawing::Color::IndianRed;
			this->btnSalir2->Enabled = false;
			this->btnSalir2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnSalir2->ForeColor = System::Drawing::Color::Red;
			this->btnSalir2->Location = System::Drawing::Point(213, 217);
			this->btnSalir2->Name = L"btnSalir2";
			this->btnSalir2->Size = System::Drawing::Size(189, 48);
			this->btnSalir2->TabIndex = 74;
			this->btnSalir2->Text = L"Salir";
			this->btnSalir2->UseVisualStyleBackColor = false;
			this->btnSalir2->Visible = false;
			this->btnSalir2->Click += gcnew System::EventHandler(this, &MyForm::btnSalir2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 525);
			this->Controls->Add(this->btnSalir2);
			this->Controls->Add(this->btnReiniciar);
			this->Controls->Add(this->Lose);
			this->Controls->Add(this->bombermanWin);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->EnemigoMuerte);
			this->Controls->Add(this->fantasma);
			this->Controls->Add(this->foca);
			this->Controls->Add(this->FINALMAP);
			this->Controls->Add(this->FONDO);
			this->Controls->Add(this->Niv3);
			this->Controls->Add(this->Niv2);
			this->Controls->Add(this->life);
			this->Controls->Add(this->bomb);
			this->Controls->Add(this->flame);
			this->Controls->Add(this->explota2);
			this->Controls->Add(this->explota3);
			this->Controls->Add(this->fondoinicio);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->Nivel1);
			this->Controls->Add(this->vida1);
			this->Controls->Add(this->murio1);
			this->Controls->Add(this->Mapa1);
			this->Controls->Add(this->ladrillo);
			this->Controls->Add(this->muertebomberman);
			this->Controls->Add(this->piedra);
			this->Controls->Add(this->bomberman);
			this->Controls->Add(this->explota1);
			this->Controls->Add(this->bomba);
			this->Controls->Add(this->Destruccion_Piedra);
			this->Controls->Add(this->EnemigoMuerte2);
			this->Controls->Add(this->EnemigoMuerte3);
			this->Controls->Add(this->hammer);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomberman))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedra))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->muertebomberman))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ladrillo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Mapa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->murio1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vida1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Nivel1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fondoinicio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomba))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->explota1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->flame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bomb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->life))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Niv2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Niv3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FONDO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FINALMAP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->foca))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fantasma))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Destruccion_Piedra))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bombermanWin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hammer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EnemigoMuerte3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Lose))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{

		//por orden comportamiento de sprites y maketransparent
		AgregarObjetos(64, 65, juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel());
		Bomberman_Trans = gcnew Bitmap(bomberman->Image);
		Bomberman_Trans->MakeTransparent(Bomberman_Trans->GetPixel(1, 1));
		Piedra_Trans = gcnew Bitmap(piedra->Image);
		Piedra_Trans->MakeTransparent(Piedra_Trans->GetPixel(1, 1));
		Ladrillo_Trans = gcnew Bitmap(ladrillo->Image);
		BombermanM_Trans = gcnew Bitmap(muertebomberman->Image);
		BombermanM_Trans->MakeTransparent(BombermanM_Trans->GetPixel(1, 1));


		//declaracion del comportamiento bomba
		Bomba_Trans = gcnew Bitmap(this->bomba->Image);
		Bomba_Trans->MakeTransparent(Bomba_Trans->GetPixel(1, 1));
		ExplosionCentro_Trans = gcnew Bitmap(this->explota3->Image);
		ExplosionCentro_Trans->MakeTransparent(ExplosionCentro_Trans->GetPixel(0, 0));
		ExplosionLimite_Trans = gcnew Bitmap(this->explota1->Image);
		ExplosionLimite_Trans->MakeTransparent(ExplosionLimite_Trans->GetPixel(0, 0));
		ExplosionCuerpo_Trans = gcnew Bitmap(this->explota2->Image);
		ExplosionCuerpo_Trans->MakeTransparent(ExplosionCuerpo_Trans->GetPixel(0, 0));
		ExplosionCentro_Trans = gcnew Bitmap(this->explota3->Image);
		//comportamiento enemigos
		Enemigo1_Trans = gcnew Bitmap(this->foca->Image);
		Enemigo1_Trans->MakeTransparent(Enemigo1_Trans->GetPixel(1, 1));
		Enemigo2_Trans = gcnew Bitmap(this->fantasma->Image);
		Enemigo2_Trans->MakeTransparent(Enemigo2_Trans->GetPixel(1, 1));
		Enemigo3_Trans = gcnew Bitmap(this->hammer->Image);
		Enemigo3_Trans->MakeTransparent(Enemigo3_Trans->GetPixel(1, 1));
		Enemigo1M_Trans = gcnew Bitmap(this->EnemigoMuerte->Image);
		Enemigo1M_Trans->MakeTransparent(Enemigo1M_Trans->GetPixel(1, 1));
		Enemigo2M_Trans = gcnew Bitmap(this->EnemigoMuerte2->Image);
		Enemigo2M_Trans->MakeTransparent(Enemigo2M_Trans->GetPixel(1, 1));
		Enemigo3M_Trans = gcnew Bitmap(this->EnemigoMuerte3->Image);
		Enemigo3M_Trans->MakeTransparent(Enemigo3M_Trans->GetPixel(1, 1));
		//comportamiento colision
		DestruccionPiedra_Trans = gcnew Bitmap(this->Destruccion_Piedra->Image);
		DestruccionPiedra_Trans->MakeTransparent(DestruccionPiedra_Trans->GetPixel(1, 1));

		BombermanW_Trans = gcnew Bitmap(this->bombermanWin->Image);
		BombermanW_Trans->MakeTransparent(BombermanW_Trans->GetPixel(0, 0));
	}
	private: System::Void Juego_Tick(System::Object^  sender, System::EventArgs^  e) 
	{

		//motor del juego 
		Graphics ^s = this->CreateGraphics();
		int gWidth = (int)s->VisibleClipBounds.Width;
		int gHeight = (int)s->VisibleClipBounds.Height;
		BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
		espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
		BufferedGraphics ^buffer = espacioBuffer->Allocate(s, Drawing::Rectangle(0, 0, gWidth, gHeight));

		//se entiende por fase la instancia en la que se encuentra el usuario dentro del juego
		if (juego->FASE() == 0){
			buffer->Graphics->DrawImage(this->fondoinicio->Image, 0, 0, gWidth, gHeight);
		}
		if (juego->FASE() == 1)
		{
			buffer->Graphics->DrawImage(this->Nivel1->Image, 0, 0, gWidth, gHeight);
			switch (juego->Nivel())
			{
				case 1: buffer->Graphics->DrawImage(this->Nivel1->Image, 0, 0, gWidth, gHeight); break;
				case 2: buffer->Graphics->DrawImage(this->Niv2->Image, 0, 0, gWidth, gHeight); break;
				case 3: buffer->Graphics->DrawImage(this->Niv3->Image, 0, 0, gWidth, gHeight); break;
				case 4: buffer->Graphics->DrawImage(this->Nivel1->Image, 0, 0, gWidth, gHeight); break;
			}
			if (contfondo > 15)
			{
				juego->FASE(2);
				label1->Visible = true;
				label2->Visible = true;
				label3->Visible = true;
				label4->Visible = true;
				label5->Visible = true;
			}
			else
				contfondo++;
		}
		if (juego->FASE() == 2){

			Tablero_Mapa(buffer->Graphics, gWidth, gHeight);

			juego->cojer_poder();

			juego->choca_con_enemigo();

			juego->mover_jugador(buffer->Graphics, mov);

			juego->moverbomba(buffer->Graphics);

			juego->moverenemigo(buffer->Graphics);

			juego->pintar_poder(buffer->Graphics, gcnew Bitmap(this->bomb->Image), gcnew Bitmap(this->flame->Image), gcnew Bitmap(this->life->Image));

			juego->pintarbomba(buffer->Graphics, Bomba_Trans);

			ExplosionBomba(buffer->Graphics);

			juego->pintar_piedras(buffer->Graphics, Piedra_Trans, Ladrillo_Trans, DestruccionPiedra_Trans);

			juego->pintarenemigo(buffer->Graphics, Enemigo1_Trans, Enemigo1M_Trans, Enemigo2_Trans, Enemigo2M_Trans, Enemigo3_Trans, Enemigo3M_Trans);
			
			juego->pintar_jugador(buffer->Graphics, Bomberman_Trans, BombermanM_Trans, BombermanW_Trans);

			juego->Pintar_Vidas(buffer->Graphics, gcnew Bitmap(this->vida1->Image), gcnew Bitmap(this->murio1->Image));

			GameOver();
		}
		if (juego->FASE() == 3){
			delete label1;
			delete label2;
			delete label3;
			delete label4;
			delete label5;

			btnReiniciar->Enabled = true; btnReiniciar->Visible = true;
			btnSalir2->Enabled = true; btnSalir2->Visible = true;

			buffer->Graphics->DrawImage(this->Lose->Image, 0, 0, gWidth, gHeight);
		}
		
		buffer->Render(s);
		delete buffer;
		delete espacioBuffer;
		delete s;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Right){
			mov = 1;
		}
		if (e->KeyCode == Keys::Left){
			mov = 2;
		}
		if (e->KeyCode == Keys::Down){
			mov = 3;
		}
		if (e->KeyCode == Keys::Up){
			mov = 4;
		}
	}
private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	mov = 0;
}
private: System::Void btnIniciar_Click(System::Object^  sender, System::EventArgs^  e) {
	juego->FASE(1);
	delete btnIniciar;
	delete btnInstrucciones;
	delete btnSalir;
}
private: System::Void btnInstrucciones_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btnSalir_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void ExpBomba_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (juego->getB() >= 0)
		contexp++;
}
private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (juego->FASE() == 2){
		if (e->KeyChar == ' '){
			juego->agregarbomba(contexp);
			juego->ubica_bomba_en_X();
			juego->ubica_bomba_en_Y();
		}

		if (juego->Nivel() < 4 && e->KeyChar == '1'){
			seg = min = 0;
			juego->setXJugador(35);
			juego->setYJugador(35);
			juego->Nivel(juego->Nivel() + 1);
			AgregarObjetos(64, 65, juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel(), juego->Nivel());
			juego->FASE(1);
			contfondo = 0;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
		}
	}
}
private: System::Void Nivel2_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^s = this->CreateGraphics();
	int gWidth = (int)s->VisibleClipBounds.Width;
	int gHeight = (int)s->VisibleClipBounds.Height;
	BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
	espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
	BufferedGraphics ^buffer = espacioBuffer->Allocate(s, Drawing::Rectangle(0, 0, gWidth, gHeight));

	buffer->Render(s);
	delete buffer;
	delete espacioBuffer;
	delete s;

}
private: System::Void Nivel3_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^s = this->CreateGraphics();
	int gWidth = (int)s->VisibleClipBounds.Width;
	int gHeight = (int)s->VisibleClipBounds.Height;
	BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
	espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
	BufferedGraphics ^buffer = espacioBuffer->Allocate(s, Drawing::Rectangle(0, 0, gWidth, gHeight));

	
	buffer->Render(s);
	delete buffer;
	delete espacioBuffer;
	delete s;

}
private: System::Void Nivel4_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics ^s = this->CreateGraphics();
	int gWidth = (int)s->VisibleClipBounds.Width;
	int gHeight = (int)s->VisibleClipBounds.Height;
	BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
	espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
	BufferedGraphics ^buffer = espacioBuffer->Allocate(s, Drawing::Rectangle(0, 0, gWidth, gHeight));

	buffer->Render(s);
	delete buffer;
	delete espacioBuffer;
	delete s;

}
private: System::Void Tiempo_Tick(System::Object^  sender, System::EventArgs^  e) {

	if (juego->FASE() == 2){
		seg++;
		if (seg > 59)
		{
			seg = 0;
			min++;
		}
	}
}
private: System::Void btnReiniciar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Restart();
}
private: System::Void btnSalir2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	delete juego;
}
};
}
//fin :D