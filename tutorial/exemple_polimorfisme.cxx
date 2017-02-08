#include <list>
#include "animals.hxx"

typedef std::list<Animal*> Animals;
typedef std::list<Jaula*> Zoo;

int main(void)
{
	Animals animals;
        Zoo jaulas;

        Jaula Uno;
        Jaula Dos;
        Jaula Tres;
        
        Uno.nom("JualaUno");
        Dos.nom("JaulaDos");
        Tres.nom("JaulaTres");
        
        jaulas.push_back(&Uno);
        jaulas.push_back(&Dos);
        jaulas.push_back(&Tres);
        
	Animal unAnimal;
	unAnimal.nom("Pikatxu");
	animals.push_back(&unAnimal);

	Elefant unElefant;
	unElefant.nom("Jumbo l'Orellut");
	animals.push_back(&unElefant); 

	Granota unaGranota;
	unaGranota.nom("Gustavo el Reporter");
	animals.push_back(&unaGranota);

	Gat unGat;
	unGat.nom("Gat Amb Botes");
	animals.push_back(&unGat);

        Uno.enjaular(unAnimal);
        Dos.enjaular(unElefant);
        Uno.enjaular(unaGranota);
        Tres.enjaular(unGat);
        
	for (Zoo::iterator it=jaulas.begin(); it!=jaulas.end(); it++)
	{
		std::cout << "La " << (*it)->nom() << " contiene ";
                (*it)->nombrar();
	}

	return 0;
}
