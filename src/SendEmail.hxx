#ifndef _SENDEMAIL_HXX_
#define _SENDEMAIL_HXX_
#include <string>
#include "SendStrategy.hxx"

class SendEmail : public SendStrategy {
			
public:

	SendEmail()	
	{
	}		 

		void send(std::string work, std::string author, std::string user){
			std::string to = user;
			std::string subject = "new work " + work + " by " + author;
			MailStub::theInstance().sendMail(to, subject);
		};

		
};

#endif
