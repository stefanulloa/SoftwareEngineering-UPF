#ifndef _CLIENT_HXX_
#define _CLIENT_HXX_
#include <string>
#include "MailStub.hxx"
#include "Observer.hxx"

class Client : public Observer{

private: std::string _name;
	std::string _email;
	std::string _preference;
	std::string _number;
			
public:

	Client()
		: _preference ("email")
	{
	}		
	
	Client(const std::string &name, const std::string &email) 
		: _name(name), _email(email)		 
	{				
	} 

		const std::string name() {  
			return _name;
		}
		
		void name(const std::string &name) {
			_name = name;
		}

		const std::string email() {  
			return _email;
		}
		
		void email(const std::string &email) {
			_email = email;
		}

		const std::string preference() {
			return _preference;
		}

		const std::string number(){
			return _number;
		}

		void setPreference(const std::string preference, const std::string number){
			_preference = preference;
			_number = number;
		}

		void update(std::string work, std::string author){
			if(preference() == "SMS"){
				std::string to = number();
			std::string subject = "red[MeltingPot] new work " + work + " by " + author;
			SmsStub::theInstance().sendSms(to, subject);
			}
			else if(preference() == "Whatsapp"){
			std::string to = number();
			std::string subject = "red[MeltingPot] new work " + work + " by " + author;
			WhatsappStub::theInstance().sendWhatsapp(to, subject);
			}
			else {
			std::string to = name() + " " + "<" + email() + ">";
			std::string subject = "new work " + work + " by " + author;
			MailStub::theInstance().sendMail(to, subject);
			}
		}

		
};

#endif
