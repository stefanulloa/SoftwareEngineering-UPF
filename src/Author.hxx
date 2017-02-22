#ifndef _AUTHOR_HXX_
#define _AUTHOR_HXX_

class Author{
	private: std::string _name;

public:
	Author()
	:_name ("Pedro")
	{
	}
		
	const std::string getName() const {
		return _name;
	}	
	void setName(const std::string &name){
	_name = name;
	}
	bool isEmployed(){
		return true;
	}
	
};

#endif
