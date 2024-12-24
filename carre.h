/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>

using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carré de couleur
/// </summary>
ref class CCarre
{
private:
	int cote;   // Côté du carré
	int sx;     // Position X du carré
	int sy;     // Position Y du carré
	Color color; // Couleur du carré
	int dx;     // Déplacement horizontal
	int dy;     // Déplacement vertical

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
	/// Initialise m_sx privé
	/// </summary>
	/// <param name="x">Position x du carré</param>
	void Setsx(int x1)
	{
		sx = x1;
	}

	/// <summary>
	/// Retourne m_sx privé
	/// </summary>
	/// <returns>Position x du carré</returns>
	int Getsx()
	{
		return sx;
	}

	/// <summary>
	/// Initialise m_sy privé
	/// </summary>
	/// <param name="y">Position y du carré</param>
	void Setsy(int y1)
	{
		sy = y1;
	}

	/// <summary>
	/// Retourne m_sy privé
	/// </summary>
	/// <returns>Position y du carré</returns>
	int Getsy()
	{
		return sy;
	}

	/// <summary>
	/// Initialise m_color privé
	/// </summary>
	/// <param name="couleur">Couleur du carré</param>
	void SetColor(Color couleur)
	{
		color = couleur;
	}

	/// <summary>
	/// Initialise m_cote privé
	/// </summary>
	/// <param name="cote">Côté du carré</param>
	void SetCote(int cote)
	{
		this->cote = cote;
	}

	/// <summary>
	/// Retourne m_cote privé
	/// </summary>
	/// <returns>Côté du carré</returns>
	int GetCote()
	{
		return cote;
	}

	/// <summary>
	/// Déplace le carré suivant un vecteur déplacement dx et dy
	/// </summary>
	/// <param name="dx">Valeur dx du déplacement</param>
	/// <param name="dy">Valeur dy du déplacement</param>
	void Deplacer(int dx, int dy)
	{
		sx += dx; // Incrémente la position X
		sy += dy; // Incrémente la position Y
	}

	/// <summary>
	/// Anime le carré, en gérant son déplacement et les collisions
	/// </summary>
	/// <param name="form">Formulaire dans lequel le carré est animé</param>
	/// <param name="largeur">Largeur de la fenêtre</param>
	/// <param name="hauteur">Hauteur de la fenêtre</param>
	void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur)
	{
		// Efface le carré à la position actuelle
		Effacer(form);

		// Déplace le carré en fonction de dx et dy
		Deplacer(dx, dy);

		// Vérifie les collisions avec les bords de la fenêtre
		if (sx < 0 || sx + cote > largeur) {
			dx = -dx; // Inverse la direction horizontale si le carré touche un bord
		}
		if (sy < 0 || sy + cote > hauteur) {
			dy = -dy; // Inverse la direction verticale si le carré touche un bord
		}

		// Redessine le carré à la nouvelle position
		Dessiner(form);
	}

	/// <summary>
	/// Dessine le carré 
	/// </summary>
	/// <param name="form">Pointeur sur la fenêtre dans laquelle on dessine.</param>
	void Dessiner(System::Windows::Forms::Form^ form)
	{
		Graphics^ g = form->CreateGraphics();
		g->FillRectangle(gcnew SolidBrush(color), sx, sy, cote, cote);
	}

	/// <summary>
	/// Efface le carré 
	/// </summary>
	/// <param name="form">Pointeur sur la fenêtre dans laquelle on dessine.</param>
	void Effacer(System::Windows::Forms::Form^ form)
	{
		Graphics^ g = form->CreateGraphics();
		g->FillRectangle(gcnew SolidBrush(form->BackColor), sx, sy, cote, cote);
	}
};

/// <summary>
/// Classe de gestion de plusieurs carrés animés
/// </summary>
ref class CAnimation
{
private:
	CCarre^ carre1; // Premier carré
	CCarre^ carre2; // Deuxième carré

public:
	CAnimation()
	{
		// Créer les carrés avec des tailles et couleurs différentes
		carre1 = gcnew CCarre(); // Carré rouge par défaut
		carre1->SetColor(Color::Red);
		carre1->SetCote(30); // Carré plus petit

		carre2 = gcnew CCarre(); // Carré bleu
		carre2->SetColor(Color::Blue);
		carre2->SetCote(50); // Carré plus grand
		carre2->Setsx(100); // Position initiale différente
		carre2->Setsy(100);
		carre2->dx = 2; // Déplacement plus rapide
		carre2->dy = 2;
	}

	/// <summary>
	/// Anime les deux carrés dans le formulaire
	/// </summary>
	/// <param name="form">Formulaire dans lequel les carrés sont animés</param>
	/// <param name="largeur">Largeur de la fenêtre</param>
	/// <param name="hauteur">Hauteur de la fenêtre</param>
	void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur)
	{
		// Anime les deux carrés
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
