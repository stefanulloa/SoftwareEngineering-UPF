#ifndef _COLLECTION_HXX_
#define _COLLECTION_HXX_
#include "Work.hxx"

typedef std::list<Work*> WorkList;

class Collection{

private: std::string _title;
			bool _isPublished;
			WorkList _workList;

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
		_isPublished = true;
	}
	void withdraw() {
		_isPublished = false;
	}
	const std::string workList() {
		std::string a;
        std::stringstream aw;
        int cont = 1;
        for(WorkList::iterator it = _workList.begin(); it != _workList.end(); it++, cont++){
            aw << cont << ":" << (*it)->isbn()<< ", " << "'" << (*it)->title() << "'" << ", " << "'" << "originals/" << (*it)->originalFile() << "'" << "\n";
            a = aw.str();
        }
            return a;
	}
	void addWork(Work & obra){
        _workList.push_back(&obra);
    }
	
};

#endif
