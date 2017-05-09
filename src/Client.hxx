#ifndef _CLIENT_HXX_
#define _CLIENT_HXX_

class Client {

private: std::string _name;
	std::string _email;
			
public:

	Client()
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
		
};

#endif
