#ifndef _SENDSTRATEGY_HXX_
#define _SENDSTRATEGY_HXX_
#include <string>
#include "MailStub.hxx"

class SendStrategy {
			
public:

	SendStrategy()	
	{
	}

	virtual ~SendStrategy()	
	{
	}		 
		virtual void send(std::string work, std::string author, std::string user) = 0;

		
};

#endif
