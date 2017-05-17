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

		void addObserver( Observer * observer ) {
			_observers.push_back( observer );
		}

		void notify() {
			for ( ObserverList::iterator it = _observers.begin();	it != _observers.end(); ++it){
				(*it)->update(work, author);
			}
		}

		
};

#endif
