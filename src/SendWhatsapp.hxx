#ifndef _SENDWHATSAPP_HXX_
#define _SENDWHATSAPP_HXX_
#include <string>
#include "SendStrategy.hxx"

class SendWhatsapp : public SendStrategy {
			
public:

	SendWhatsapp()	
	{
	}		 

		void send(std::string work, std::string author, std::string user){
			std::string to = user;
			std::string subject = "[MeltingPot] new work " + work + " by " + author;
			WhatsappStub::theInstance().sendWhatsapp(to, subject);
		};

		
};

#endif
