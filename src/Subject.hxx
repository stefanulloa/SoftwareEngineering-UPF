#ifndef _SUBJECT_HXX_
#define _SUBJECT_HXX_
#include "MailStub.hxx"

typedef std::list<Observer*> ObserverList;

class Subject {

private:  ObserverList _observers;
			
public:

	Subject()
	{
	}

	virtual ~Subject()
	{
	}		

		void addObserver( Observer * observer ) {
			_observers.push_back( observer );
		}

		void notify(std::string work, std::string author) {
			for ( ObserverList::iterator it = _observers.begin();	it != _observers.end(); ++it){
				(*it)->update(work, author);
			}
		}

		
};

#endif
