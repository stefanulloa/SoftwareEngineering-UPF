#ifndef _MELTINGPOTONLINE_HXX_
#define _MELTINGPOTONLINE_HXX_
#include "Author.hxx"

typedef std::list<Author*> AuthorList;

class MeltingPotOnline{
	private: AuthorList _escritores;
	
	public:
		MeltingPotOnline()
		{
		}
		
		~MeltingPotOnline(){
		
		AuthorList::iterator ib = _escritores.begin();
		while(ib != _escritores.end()){
			Author *pEliminarAutor = (*ib);
			delete pEliminarAutor;
			ib++;
		}

		}
		const std::string catalogue() {
			std::string a;
			for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
            a = (*it)->name();
            if (!(*it)->isEmployed()){
			a += "";
			}
        }
            return a;
		}
		void addAuthor(const std::string &title, bool isEmployed){
			Author *autor = new Author(title, isEmployed);
			_escritores.push_back(autor);
		}

};

#endif
