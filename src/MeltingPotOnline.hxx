#ifndef _MELTINGPOTONLINE_HXX_
#define _MELTINGPOTONLINE_HXX_
#include "Author.hxx"
#include "Work.hxx"
#include "Exception.hxx"

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
            a += (*it)->name();
            if (!(*it)->isEmployed()){
			a += " [external]\n";
			}
			else{
			a += " [contracted]\n";
			}
			a += (*it)->catalogue();
        }
            return a;
		}
		void addAuthor(const std::string &title, bool isEmployed){
			Author *autor = new Author(title, isEmployed);
			_escritores.push_back(autor);
			
		}
		
		Author& findAuthor(const std::string &author){
			for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
				if((*it)->name()==author){
					return *(*it);
				}
			} 
		throw exceptionInexistentAuthor();
		}
		
		void generatedConversions(const std::string &author, const std::string &title){
		
		std::string commonPrefix = "generated/" + author + " - " + title;
			
			const char * fakeGenerated [] = {
				
				(commonPrefix + " [multiple HTML files].war").c_str(),
				(commonPrefix + " [printable].pdf").c_str(),
				(commonPrefix + " [watermark].pdf").c_str(),
				
				0 //  This  zero  i s  needed  to  stop  the  loop
			};
			
			for ( int i = 0; fakeGenerated[i]; i++ )
				std::ofstream newfile( fakeGenerated[i] );
		
		} 
		
		void addWork(const std::string &author, const std::string &title, const int &isbn, const std::string &originalFile){
			
			std::string fileName = "originals/" + originalFile;
			std::ifstream file (fileName.c_str());
			
			Author *autorEncontrado = &findAuthor(author);

			autorEncontrado->addWork(title, isbn, originalFile);
	
			if (!file) throw exceptionInexistentOriginalFile();
			
			generatedConversions(author, title);
			
		}

};

#endif
