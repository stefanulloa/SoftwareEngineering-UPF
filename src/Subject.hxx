#ifndef _SUBJECT_HXX_
#define _SUBJECT_HXX_
#include "MailStub.hxx"
#include "Observer.hxx"
#include "Client.hxx"
#include "Channel.hxx"

typedef std::list<Observer*> ObserverList;

class Subject {

private:

ObserverList _observers;

public:

	Subject()
	{
	}

	virtual ~Subject(){

		/*ObserverList::iterator ic = _observers.begin();
		while(ic != _observers.end()){
			Observer *pEliminarObserver = (*ic);
			delete pEliminarObserver;
			ic++;
		}*/
		//No hace falta porque como se pasa por puntero cada Observer, estos se eliminan en los destructores de las clases que los pasan

		}

		void addObserver( Observer * observer ) {
			_observers.push_back( observer );
		}

		virtual void notify(std::string work, std::string author) {
			for ( ObserverList::iterator it = _observers.begin();	it != _observers.end(); ++it){
				(*it)->update(work, author);
			}
		}

		virtual const std::string listSubscribed(){
			std::string names;
			for(ObserverList::iterator ic = _observers.begin(); ic != _observers.end(); ic++){
				names += (*ic)->name() + "\n";
			}
			return names;
		}


};

#endif
