#ifndef _TOPIC_HXX_
#define _TOPIC_HXX_
#include "Client.hxx"

typedef std::list<Client*> ClientList;

class Topic {

private: std::string _theme;
	 ClientList _subscriptores;
			
public:
	Topic() 
		: _theme ("")
		 
	{				
	} 
	
	Topic(const std::string &theme) 
		: _theme(theme)
	{	
	} 

	~Topic(){

		ClientList::iterator ic = _subscriptores.begin();
		while(ic != _subscriptores.end()){
			Client *pEliminarClient = (*ic);
			delete pEliminarClient;
			ic++;
		}

		}
 
		const std::string theme() {  
			return _theme;
		}
		
		void theme( const std::string &theme) {
			_theme = theme;
		}

		void subscribeClient(const std::string &name, const std::string email){
			Client *subscriptor = new Client(name, email);
			_subscriptores.push_back(subscriptor);
		}

		const std::string listSubscribed(){
			std::string names;
			for(ClientList::iterator ic = _subscriptores.begin(); ic != _subscriptores.end(); ic++){
				names += (*ic)->name() + "\n";
			}
			return names;
		}

		void notify(std::string work, std::string author){
			for(ClientList::iterator ic = _subscriptores.begin(); ic != _subscriptores.end(); ic++){
				(*ic)->update("red", author);
			}
		}
		
};

#endif
