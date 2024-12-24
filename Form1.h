/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>

#pragma once

#include "carre.h"

namespace tpcarrewineleve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 est une fenêtre avec un carré rouge
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			// instanciation dans le tas managé du carré numéro 1 
			pcarre1 = gcnew CCarre();
			pcarre1->SetColor(Color::Red);
			
			
			// A COMPLETER /////////////////////////////////////////////////////////////////////////////////



			this->timer1->Enabled = true;
			largeur = this->ClientRectangle.Width;
			hauteur = this->ClientRectangle.Height;

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Le Carré numéro 1.
		/// </summary>
		CCarre ^pcarre1;
		/// <summary>
		/// Largeur de la fenêtre
		/// </summary>
		int largeur;
		/// <summary>
		/// Hauteur de la fenêtre
		/// </summary>
		int hauteur;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// Appelé périodiquement pour redessiner les carrés dans la fenetre
		/// </summary>
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				// A COMPLETER ////////////////////////////////////////////////////////////////////////
				pcarre1->Dessiner(this);
				//		 pcarre1->Effacer(this);
				 
			 
			 }
	};
}

