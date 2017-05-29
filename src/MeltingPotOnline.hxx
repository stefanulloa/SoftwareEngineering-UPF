#ifndef _MELTINGPOTONLINE_HXX_
#define _MELTINGPOTONLINE_HXX_
#include "Author.hxx"
#include "Work.hxx"
#include "Exception.hxx"
#include "ConverterGroup.hxx"
#include "Topic.hxx"
#include "Client.hxx"

typedef std::list<Author*> AuthorList;
typedef std::list<Topic*> TopicList;
typedef std::list<Client*> ClientList;

class MeltingPotOnline{
	private: AuthorList _escritores;
			 ConverterGroup _converters;
			 TopicList _topicos;
			 ClientList _clientes;
			
	
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

		ClientList::iterator ic = _clientes.begin();
		while(ic != _clientes.end()){
			Client *pEliminarClient = (*ic);
			delete pEliminarClient;
			ic++;
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
			
			autorEncontrado->notify("Ensayo sobre la ceguera", "Saramago");
			
		}
		
		void addTopic(const std::string &theme){
			Topic * topic = new Topic(theme);
			_topicos.push_back(topic);
		}
		
		const std::string listTopics(){
			std::string tops;
			for(TopicList::iterator ito = _topicos.begin(); ito != _topicos.end(); ito++){
				tops += (*ito)->theme();
				tops += "\n";
			}
			return tops;
		}
		
		void associateTopicWithWork( const std::string &topic, const std::string &author, const std::string &title){
		if (_topicos.empty()){
			throw exceptionInexistentTopic();
		}else{
			for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
				if( (*it)->name()==author ){
					Work * work = &((*it)->findWork(title));
					if(work){
					work->addTopic(topic);
					for(TopicList::iterator ito = _topicos.begin(); ito != _topicos.end(); ito++){
						if( (*ito)->theme()==topic){
							(*ito)->notify(title, author);
						}
					}
					}
				}
			} 

		}
		}

		void addClient(const std::string &name, const std::string &email){
			Client *cliente = new Client(name, email);
			_clientes.push_back(cliente);
		}

		const std::string listClients(){
			std::string clientInfo;
			for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
				clientInfo += (*ic)->name() + " <" + (*ic)->email() + ">" + "\n";
			}
			return clientInfo;
		}

		void subscribeClientToTopic(const std::string &client, const std::string topic){
			for(TopicList::iterator ito = _topicos.begin(); ito != _topicos.end(); ito++){
				if((*ito)->theme()==topic){
					for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
						if((*ic)->name()==client){
							(*ito)->subscribeClient(client,(*ic)->email());
							return;
						}
					}throw exceptionInexistentClient();
				}
			}throw exceptionInexistentTopic();
		}

		const std::string listSubscribedToTopic(const std::string &topic){
			for(TopicList::iterator ito = _topicos.begin(); ito != _topicos.end(); ito++){
				if((*ito)->theme()==topic){
					return (*ito)->listSubscribed();
				}
			}
		}
		
		void subscribeClientToAuthor(const std::string &client, const std::string author){
			for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
				if((*ic)->name()==client){
					for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
						if((*it)->name()==author){
							(*it)->subscribeClient(client,(*ic)->email());
							return;
						}
					}
				}
			}
		}

};

#endif
