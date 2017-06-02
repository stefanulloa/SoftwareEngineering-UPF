#ifndef _SENDSMS_HXX_
#define _SENDSMS_HXX_
#include <string>
#include "SendStrategy.hxx"

class SendSms : public SendStrategy {
			
public:

	SendSms()	
	{
	}		 

		void send(std::string work, std::string author, std::string user){
			std::string to = user;
			std::string subject = "[MeltingPot] new work " + work + " by " + author;
			SmsStub::theInstance().sendSms(to, subject);
		};

		
};

#endif
