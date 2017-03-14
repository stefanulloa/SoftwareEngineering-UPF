#ifndef _AUTHOR_HXX_
#define _AUTHOR_HXX_
#include "Work.hxx"

typedef std::list<Work> WorkList;

class Author{
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
		
	const std::string getName() const {
		return _name;
	}	
	void setName(const std::string &name){
	_name = name;
	}
	bool isEmployed(){
		return _isEmployed;
	}
	void hire() {
		_isEmployed = true;
	}
	void fire() {
		_isEmployed = false;
	}
	const std::string catalogue() { //const delante de funcion() impide modificar las variables dentro de la funcion o llamar funciones que no sean iguales con const
        std::string a;
        std::stringstream aw;
        for(WorkList::iterator it = _catalogue.begin(); it != _catalogue.end(); it++){
            aw << "\t" << (it)->isbn()<< ", " << "'" << (it)->title() << "'" << ", " << "'" << "originals/" << (it)->originalFile() << "'" << "\n";
            a += aw.str();
        }
            return a;
    }
	void addWork(const std::string &title, const int &isbn, const std::string &originalFile){
        Work obra;
        obra.title(title);
        obra.isbn(isbn);
        obra.originalFile(originalFile);
        _catalogue.push_back(obra);
    }
	
};

#endif
