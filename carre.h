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
