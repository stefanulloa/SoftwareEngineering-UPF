#ifndef _AUTHOR_HXX_
#define _AUTHOR_HXX_

class Author{
	private: std::string _name;
				bool _isEmployed;

public:
	Author()
	:_name ("Pedro"),
	_isEmployed (false)
	{
	}
		
	const std::string getName() const {
		return _name;
	}	
	void setName(const std::string &name){
	_name = name;
	}
	bool isEmployed(){
		return _isEmployed;
	}
	void hire() {
		_isEmployed = true;
	}
	void fire() {
		
	}
	
};

#endif
