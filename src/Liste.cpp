#include "../header/Liste.h"
#include <iostream>

using namespace std;

Liste::Liste()
{
	this->prem = NULL;
	this->last = NULL;
}

void Liste::afficherDroiteGauche() const
{
	Cellule* actu = this->last;
	if (actu != NULL)
	{
		actu->precedent = this->last->precedent;
		actu->suivant = this->last->suivant;
		while (actu != NULL)
		{
			cout << actu->info << endl;
			actu = actu->precedent;
		}
		delete actu;
	}
	else
	{
		cout << "Liste Vide" << endl;
	}
}

void Liste::afficherGaucheDroite() const
{
	Cellule* actu = this->prem;
	if (actu != NULL)
	{
		actu->precedent = this->prem->precedent;
		actu->suivant = this->prem->suivant;
		while (actu != NULL)
		{
			cout << actu->info << endl;
			actu = actu->suivant;
		}
		delete actu;
	}
	else
	{
		cout << "Liste Vide" << endl;
	}

	
}

bool Liste::estVide() const
{
	return(prem == NULL);
}

void Liste::ajouterEnTete(ElementL E)
{
	Cellule* n = new Cellule;
	n->info = E;
	n->precedent = NULL;
	if (this->estVide())
	{
		this->last = n;
		n->suivant = NULL;
	}
	else
	{
		this->prem->precedent = n;
		n->suivant = this->prem;
	}
	this->prem = n;

	n = NULL;
	delete n;



}

void Liste::ajouterEnQueue(ElementL E)
{
	Cellule* n = new Cellule;
	n->info = E;
	if (this->estVide())
	{
		this->prem = n;
		n->precedent = NULL;
		
	}
	else
	{
		n->precedent = this->last;
		this->last->suivant = n;
	}

	n->suivant = NULL;
	this->last = n;
	n = NULL;
	delete n;
}

void Liste::supprimerTete() {
	if (prem == NULL || last == NULL) {
		cout << "liste vide" << endl;
	}
	if (prem->suivant == NULL) {
		prem = NULL;
		last = NULL;
	}
	else 
	{
		Cellule* aux = new Cellule;
		prem->precedent = NULL;
		aux = prem->suivant;
		delete prem;
		prem = aux;
		delete aux;
	}
}

void Liste::vider()
{
	
	while (!this->estVide())
	{
		supprimerTete();
	}
}

unsigned int Liste::nbElements() const
{
	int i = 0;
	Cellule* temp = this->prem;
	while (temp != NULL)
	{
		i++;
		temp = temp->suivant;
	}
	delete temp;
	return i;
}

ElementL Liste::iemeElement(unsigned int index) const
{
	if (index < this->nbElements())
	{
		Cellule* temp = prem;
		for (int i = 0; i < index; i++)
		{
			temp = temp->suivant;
		}
		ElementL x = temp->info;
		temp = NULL;
		delete temp;
		return x;
	}
	else
	{
		cerr << "INDEX SUPERIEUR AU NOMBRE D'ELEMENT DANS LA LISTE FiemeE, throw -1" << endl;
		return -1;
	}
	
}

void Liste::modifierIemeElement(unsigned int index, ElementL e)
{
	if (index < this->nbElements())
	{
		Cellule* temp = prem;
		for (int i = 0; i < index; i++)
		{	
			temp = temp->suivant;
			temp->info = e;
		}
		temp = NULL;
		delete temp;
	}
	else
	{
		cerr << "INDEX SUPERIEUR AU NOMBRE D'ELEMENT DANS LA LISTE FmodifIeme" << endl;
	}
}

Liste& Liste::operator=(const Liste & L)
{
	this->vider();
	Cellule* l = L.prem;
	Cellule* t = new Cellule;
	Liste R;
	while (l != NULL)
	{
		t->info = l->info;
		if (l->precedent == NULL)
		{
			t->precedent = NULL;
			R.prem = t;

			Cellule* d = new Cellule;
			d->precedent = t;
			t = d;

		}
		else if (l->suivant == NULL)
		{
			t->suivant == NULL;
			R.last = t;
		}
		else
		{
			Cellule* d = new Cellule;
			d->precedent = t;
			t = d;
		}
		

		l = l->suivant;

	}

	l = NULL;
	t = NULL;
	delete l;
	delete t;

	return R;
}

void Liste::insererElement(ElementL e, unsigned int index)
{
	if (index < this->nbElements())
	{
		Cellule* temp = prem;
		for (int i = 0; i < index; i++)
		{
			temp = temp->suivant;
		}
		Cellule* New = new Cellule;
		if (temp->precedent == NULL || index == 0)
		{
			this->ajouterEnTete(e);
		}
		else
		{
			temp->precedent->suivant = New;
			New->precedent = temp->precedent;
			New->suivant = temp;
			temp->precedent = New;
			New->info = e;
		}
		

		New = NULL;
		temp = NULL;
		delete New;
		delete temp;
	}
	else
	{
		cerr << "INDEX SUPERIEUR AU NOMBRE D'ELEMENT DANS LA LISTE FinsereElement" << endl;
	}
}

void Liste::trier()
{
	int n = this->nbElements();
	for (int i = 1; i < n-1; i++)
	{
		ElementL x = iemeElement(i);
		int j = i;
		while (j > 0 && x < iemeElement(j - 1))
		{
			j--;
		}
		insererElement(x, j);
		
	}
}

Liste::~Liste()
{
	this->vider();
	delete prem;
	delete last;
}