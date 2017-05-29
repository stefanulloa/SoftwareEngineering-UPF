#ifndef _TOPIC_HXX_
#define _TOPIC_HXX_
#include "Client.hxx"
#include "Subject.hxx"

class Topic : public Subject{

protected: std::string _theme;
			
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
			Client *subscriptor = new Client(name, email);
			addObserver(subscriptor);
		}
		
};

#endif
 
