#include <iostream>
#include "../header/Liste.h"
using namespace std;

int main(void)
{
	Liste* a = new Liste;

	a->ajouterEnQueue(2);
	a->ajouterEnQueue(17);
	a->ajouterEnQueue(8);
	a->ajouterEnQueue(34);
	a->ajouterEnQueue(3);
	a->ajouterEnQueue(6144);
	a->ajouterEnQueue(128);
	a->ajouterEnQueue(2565);

	a->afficherGaucheDroite();
	cout << endl;

	//a->insererElement(42, 3);

	a->trier();

	a->afficherGaucheDroite();

	//a.~Liste();
	
	return 0;
}