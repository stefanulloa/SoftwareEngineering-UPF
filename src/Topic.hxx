#ifndef _TOPIC_HXX_
#define _TOPIC_HXX_
#include "Client.hxx"

class Topic {

private: std::string _theme;
	 Client _subscriptor;
			
public:
	Topic() 
		: _theme ("")
		 
	{				
	} 
	
	Topic(const std::string &theme) 
		: _theme(theme)
	{	
	} 
 
		const std::string theme() {  
			return _theme;
		}
		
		void theme( const std::string &theme) {
			_theme = theme;
		}

		void subscribeClient(const std::string &name, const std::string email){
			_subscriptor.name(name);
			_subscriptor.email(email);
		}

		const std::string listSubscribed(){
			std::string name;
			name = _subscriptor.name() + "red";
			return name;
		}
		
};

#endif
