#ifndef _COLLECTION_HXX_
#define _COLLECTION_HXX_

class Collection{

private: std::string _title;

public:
	Collection()
	:_title ("-- Untitled --")
	
	{
	}
	
	const std::string title() const {
		return _title;
	}
	
	void title( const std::string &title) {
			
		}
};

#endif
