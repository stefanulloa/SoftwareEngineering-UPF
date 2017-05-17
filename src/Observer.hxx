#ifndef _OBSERVER_HXX_
#define _OBSERVER_HXX_
#include "MailStub.hxx"

class Observer {
			
public:

	Observer()
	{
	}		

		virtual void update(std::string work, std::string author) = 0;
	
};

#endif
