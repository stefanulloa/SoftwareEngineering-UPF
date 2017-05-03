#ifndef _MELTINGPOTONLINE_HXX_
#define _MELTINGPOTONLINE_HXX_
#include "Author.hxx"
#include "Work.hxx"
#include "Exception.hxx"
#include "ConverterGroup.hxx"
#include "Topic.hxx"

typedef std::list<Author*> AuthorList;
typedef std::list<Topic*> TopicList;

class MeltingPotOnline{
	private: AuthorList _escritores;
			 ConverterGroup _converters;
			 TopicList _topicos;
			
	
	public:
		MeltingPotOnline()
		{	
			_converters.add( "html" );
			_converters.add( "pdf_print" );
			_converters.add( "pdf_mark" );
		} 
		
		~MeltingPotOnline(){
		
		AuthorList::iterator ib = _escritores.begin();
		while(ib != _escritores.end()){
			Author *pEliminarAutor = (*ib);
			delete pEliminarAutor;
			ib++;
		}
		
		TopicList::iterator it = _topicos.begin();
		while(it != _topicos.end()){
			Topic *pEliminarTopic = (*it);
			delete pEliminarTopic;
			it++;
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
			
			std::string commonPrefix = "generated/" + author + " - " + title;
			
			_converters.convert(fileName.c_str(), commonPrefix.c_str());
			
		}
		
		void addTopic(const std::string &theme){
			Topic * topic = new Topic(theme);
			_topicos.push_back(topic);
		}
		
		const std::string listTopics(){
			std::string tops;
			//for(TopicList::iterator ito = _topicos.begin(); ito != _topicos.end(); ito++){
				TopicList::iterator ito = _topicos.begin();
				tops += (*ito)->theme();
				tops += "\n";
			//}
			return tops;
		}

};

#endif
