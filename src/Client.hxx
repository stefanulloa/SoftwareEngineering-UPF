#ifndef _CLIENT_HXX_
#define _CLIENT_HXX_
#include <string>
#include "Observer.hxx"
#include "SendStrategy.hxx"
#include "SendSms.hxx"
#include "SendWhatsapp.hxx"
#include "SendEmail.hxx"

class Client : public Observer{

private: std::string _name;
	std::string _email;
	std::string _preference;
	std::string _number;
	SendStrategy* _sendStrategy = NULL; 
			
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
			
			std::string user;
			if(_preference == "SMS"){
				user = number();
				_sendStrategy = new SendSms();
				_sendStrategy->send(work, author, user);
				//delete(_sendStrategy);
			}
			else if(_preference == "Whatsapp"){
				user = number();
				_sendStrategy = new SendWhatsapp();
				_sendStrategy->send(work, author, user);
				//delete(_sendStrategy);
			}
			else {
				user = name() + " " + "<" + email() + ">";
				_sendStrategy = new SendEmail();
				_sendStrategy->send(work, author, user);
				//delete(_sendStrategy);
			}
			
			delete _sendStrategy;
		}

		
};

#endif
