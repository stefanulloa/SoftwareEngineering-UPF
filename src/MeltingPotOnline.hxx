#ifndef _MELTINGPOTONLINE_HXX_
#define _MELTINGPOTONLINE_HXX_
#include "Author.hxx"
#include "Work.hxx"
#include "Exception.hxx"
#include "ConverterGroup.hxx"
#include "Topic.hxx"
#include "Client.hxx"
#include "Channel.hxx"

typedef std::list<Author*> AuthorList;
typedef std::list<Topic*> TopicList;
typedef std::list<Client*> ClientList;
typedef std::list<Channel*> ChannelList;

class MeltingPotOnline{
	private: AuthorList _escritores;
			 ConverterGroup _converters;
			 TopicList _topicos;
			 ClientList _clientes;
			 ChannelList _canales;


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

		ChannelList::iterator ich = _canales.begin();
		while(ich != _canales.end()){
			Channel *pEliminarCanal = (*ich);
			delete pEliminarCanal;
			ich++;
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

			autorEncontrado->notify(title, author);

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
							(*ito)->subscribeClient((*ic));
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
			} return "return this string"; //line defined to avoid warning control reaches end of non-void function, it could also be an exception
		}

		void subscribeClientToAuthor(const std::string &client, const std::string author){
			for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
				if((*ic)->name()==client){
					for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
						if((*it)->name()==author){
							(*it)->subscribeClient((*ic));
							return;
						}
					}
				}
			}
		}

		void addChannel(const std::string &title, const std::string &description){
			Channel *canal = new Channel(title, description);
			_canales.push_back(canal);
		}

		const std::string listThematicChannels(){
			std::string channels;
			for(ChannelList::iterator it = _canales.begin(); it != _canales.end(); it++){
				channels += (*it)->listThematicChannel();
			}
			return channels;
		}

		const std::string rssByChannel(const std::string channel){

			std::string rss;
			for(ChannelList::iterator it = _canales.begin(); it != _canales.end(); it++){
				if((*it)->title()==channel){
					rss = "<?xml version='1.0' encoding='UTF-8' ?>\n<rss version='2.0'>\n<channel>\n<title>MeltingPotOnline: " + (*it)->title() + "</title>\n<link>http://www.meltingpotonline.com/" + (*it)->title() + "</link>\n<description>" + (*it)->description() + "</description>\n";
					rss += (*it)->listItems();
					rss += "</channel>\n</rss>\n";

					return rss;
				}
			}throw exceptionInexistentChannel();
		}

		void subscribeChannelToAuthor(const std::string &channel, const std::string author){
			for(ChannelList::iterator ic = _canales.begin(); ic != _canales.end(); ic++){
				if((*ic)->title()==channel){
					for(AuthorList::iterator it = _escritores.begin(); it != _escritores.end(); it++){
						if((*it)->name()==author){
							(*it)->subscribeChannel((*ic));
							return;
						}
					}
				}
			}
		}

		void subscribeChannelToTopic(const std::string &channel, const std::string topic){
			for(ChannelList::iterator ic = _canales.begin(); ic != _canales.end(); ic++){
				if((*ic)->title()==channel){
					for(TopicList::iterator it = _topicos.begin(); it != _topicos.end(); it++){
						if((*it)->theme()==topic){
							(*it)->subscribeChannel((*ic));
							return;
						}
					}
				}
			}
		}

		void clientPrefersSms(const std::string &name, const std::string number){
			for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
				if((*ic)->name()==name){
					(*ic)->setPreference("SMS", number);				}
			}
		}

		void clientPrefersWhatsapp(const std::string &name, const std::string number){
			for(ClientList::iterator ic = _clientes.begin(); ic != _clientes.end(); ic++){
				if((*ic)->name()==name){
					(*ic)->setPreference("Whatsapp", number);				}
			}
		}

};

#endif
