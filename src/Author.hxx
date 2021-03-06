#ifndef _AUTHOR_HXX_
#define _AUTHOR_HXX_
#include "Work.hxx"
#include "Exception.hxx"
#include "Subject.hxx"
#include <sstream>

typedef std::list<Work*> WorkList;

class Author : public Subject{
	private: std::string _name;
				bool _isEmployed;
			std::string _oneWork;
			 WorkList _catalogue;

public:
	Author()
	:_name ("-- Unnamed --"),
	_isEmployed (false),
	_oneWork ("")
	{
	}

	Author(const std::string &title, const bool &isEmployed)
	:_name (title),
	_isEmployed (isEmployed)
	{
	}

	~Author(){

		WorkList::iterator ib = _catalogue.begin();
		while(ib != _catalogue.end()){
			Work *pEl = (*ib);
			delete pEl;
			ib++;
		}

	}

	const std::string name() const {
		return _name;
	}
	void name(const std::string &name){
	_name = name;
	}
	bool isEmployed(){
		return _isEmployed;
	}
	void contract() {
		_isEmployed = true;
	}
	void fire() {
		_isEmployed = false;
	}
	const std::string catalogue() { //const delante de funcion() impide modificar las variables dentro de la funcion o llamar funciones que no sean iguales con const
        std::string a;
        std::stringstream aw;
        for(WorkList::iterator it = _catalogue.begin(); it != _catalogue.end(); it++){
            aw << "\t" << (*it)->isbn()<< ", " << "'" << (*it)->title() << "'" << ", " << "'" << "originals/" << (*it)->originalFile() << "'" << "\n" << (*it)->topics();
            a = aw.str();

        }
            return a;
    }
	void addWork(const std::string &title, const int &isbn, const std::string &originalFile){
        Work *obra = new Work(title, isbn, originalFile);
        _catalogue.push_back(obra);
    }
    Work & findWork(const std::string &title){
		for(WorkList::iterator it = _catalogue.begin(); it != _catalogue.end(); it++){
            if((*it)->title() == title){
			return *(*it);
			}
        }
        throw exceptionInexistentWork();
	}
	const std::string description(){
		std::string a = this->name();
		if(!this->isEmployed()){
        std::string b = a + " [external]\n";
        b = b + catalogue();
        return b;
		}
        else{
		std::string b = a + " [contracted]\n";
		b = b + catalogue();
		return b;
		}
	}

	void subscribeClient(Client *subscriptor){
			addObserver(subscriptor);
	}

	void subscribeChannel(Channel *subscriptorChannel){
			addObserver(subscriptorChannel);
	}

};

#endif
