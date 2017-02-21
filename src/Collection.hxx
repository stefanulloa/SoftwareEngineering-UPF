#ifndef _COLLECTION_HXX_
#define _COLLECTION_HXX_

class Collection{

private: std::string _title;
			bool _isPublished;

public:
	Collection()
	:_title ("-- Untitled --"),
	_isPublished (false)
	
	{
	}
	
	const std::string title() const {
		return _title;
	}
	
	void title( const std::string &title) {
			_title = title;
		}
	
	bool isPublished(){
		return _isPublished;
	}
	void publish() {
		
	}
};

#endif
