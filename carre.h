/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>

using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carr� de couleur
/// </summary>
ref class CCarre
{
private:
	int cote;   // C�t� du carr�
	int sx;     // Position X du carr�
	int sy;     // Position Y du carr�
	Color color; // Couleur du carr�
	int dx;     // D�placement horizontal
	int dy;     // D�placement vertical

public:
	// Constructeur
	CCarre()
	{
		sx = 10;
		sy = 10;
		cote = 20;
		color = Color::Red;
		dx = 1;
		dy = 1;
	}

	/// <summary>
	/// Initialise m_sx priv�
	/// </summary>
	/// <param name="x">Position x du carr�</param>
	void Setsx(int x1)
	{
		sx = x1;
	}

	/// <summary>
	/// Retourne m_sx priv�
	/// </summary>
	/// <returns>Position x du carr�</returns>
	int Getsx()
	{
		return sx;
	}

	/// <summary>
	/// Initialise m_sy priv�
	/// </summary>
	/// <param name="y">Position y du carr�</param>
	void Setsy(int y1)
	{
		sy = y1;
	}

	/// <summary>
	/// Retourne m_sy priv�
	/// </summary>
	/// <returns>Position y du carr�</returns>
	int Getsy()
	{
		return sy;
	}

	/// <summary>
	/// Initialise m_color priv�
	/// </summary>
	/// <param name="couleur">Couleur du carr�</param>
	void SetColor(Color couleur)
	{
		color = couleur;
	}

	/// <summary>
	/// Initialise m_cote priv�
	/// </summary>
	/// <param name="cote">C�t� du carr�</param>
	void SetCote(int cote)
	{
		this->cote = cote;
	}

	/// <summary>
	/// Retourne m_cote priv�
	/// </summary>
	/// <returns>C�t� du carr�</returns>
	int GetCote()
	{
		return cote;
	}

	/// <summary>
	/// D�place le carr� suivant un vecteur d�placement dx et dy
	/// </summary>
	/// <param name="dx">Valeur dx du d�placement</param>
	/// <param name="dy">Valeur dy du d�placement</param>
	void Deplacer(int dx, int dy)
	{
		sx += dx; // Incr�mente la position X
		sy += dy; // Incr�mente la position Y
	}

	/// <summary>
	/// Anime le carr�, en g�rant son d�placement et les collisions
	/// </summary>
	/// <param name="form">Formulaire dans lequel le carr� est anim�</param>
	/// <param name="largeur">Largeur de la fen�tre</param>
	/// <param name="hauteur">Hauteur de la fen�tre</param>
	void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur)
	{
		// Efface le carr� � la position actuelle
		Effacer(form);

		// D�place le carr� en fonction de dx et dy
		Deplacer(dx, dy);

		// V�rifie les collisions avec les bords de la fen�tre
		if (sx < 0 || sx + cote > largeur) {
			dx = -dx; // Inverse la direction horizontale si le carr� touche un bord
		}
		if (sy < 0 || sy + cote > hauteur) {
			dy = -dy; // Inverse la direction verticale si le carr� touche un bord
		}

		// Redessine le carr� � la nouvelle position
		Dessiner(form);
	}

	/// <summary>
	/// Dessine le carr� 
	/// </summary>
	/// <param name="form">Pointeur sur la fen�tre dans laquelle on dessine.</param>
	void Dessiner(System::Windows::Forms::Form^ form)
	{
		Graphics^ g = form->CreateGraphics();
		g->FillRectangle(gcnew SolidBrush(color), sx, sy, cote, cote);
	}

	/// <summary>
	/// Efface le carr� 
	/// </summary>
	/// <param name="form">Pointeur sur la fen�tre dans laquelle on dessine.</param>
	void Effacer(System::Windows::Forms::Form^ form)
	{
		Graphics^ g = form->CreateGraphics();
		g->FillRectangle(gcnew SolidBrush(form->BackColor), sx, sy, cote, cote);
	}
};

/// <summary>
/// Classe de gestion de plusieurs carr�s anim�s
/// </summary>
ref class CAnimation
{
private:
	CCarre^ carre1; // Premier carr�
	CCarre^ carre2; // Deuxi�me carr�

public:
	CAnimation()
	{
		// Cr�er les carr�s avec des tailles et couleurs diff�rentes
		carre1 = gcnew CCarre(); // Carr� rouge par d�faut
		carre1->SetColor(Color::Red);
		carre1->SetCote(30); // Carr� plus petit

		carre2 = gcnew CCarre(); // Carr� bleu
		carre2->SetColor(Color::Blue);
		carre2->SetCote(50); // Carr� plus grand
		carre2->Setsx(100); // Position initiale diff�rente
		carre2->Setsy(100);
		carre2->dx = 2; // D�placement plus rapide
		carre2->dy = 2;
	}

	/// <summary>
	/// Anime les deux carr�s dans le formulaire
	/// </summary>
	/// <param name="form">Formulaire dans lequel les carr�s sont anim�s</param>
	/// <param name="largeur">Largeur de la fen�tre</param>
	/// <param name="hauteur">Hauteur de la fen�tre</param>
	void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur)
	{
		// Anime les deux carr�s
		carre1->Animer(form, largeur, hauteur);
		carre2->Animer(form, largeur, hauteur);
	}

	CAnimation^ animation;

	void Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
	{
		animation = gcnew CAnimation();
		Timer^ timer = gcnew Timer();
		timer->Interval = 16;
		timer->Tick += gcnew EventHandler(this, &Form1::Timer_Tick);
		timer->Start();
	}

	void Form1::Timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		animation->Animer(this, this->ClientSize.Width, this->ClientSize.Height);
	}
};
