#ifndef animals_hxx
#define animals_hxx

#include <iostream>
#include <string>


class Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "...indefinida..." << std::endl;
	}
	void nom(std::string elNom)
	{
		_nom = elNom;
	}
	std::string& nom()
	{
		return _nom;
	}

private:
	std::string _nom;
};

class Elefant : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "elefant" << std::endl;
	}
};

class Granota : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "granota" << std::endl;
	}
};

class Gat : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "gat" << std::endl;
	}
};

#endif

typedef std::list<Animal*> Animals;

class Jaula
{
    
public: virtual void nom(std::string elNom)
        {
		_nom = elNom;
	}
	std::string& nom()
	{
		return _nom;
	}
        void enjaular(Animal animal){
            animalesEnJaula.push_back(&animal);
        }
        void nombrar(){
            for (Animals::iterator it=animalesEnJaula.begin(); it!=animalesEnJaula.end(); it++){
                std::cout << "" << (*it)->nom() << ", ";
            }
        }
    
private:
	std::string _nom;
        Animals animalesEnJaula;
        
};

typedef std::list<Jaula*> Zoo;
