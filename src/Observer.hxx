#ifndef _OBSERVER_HXX_
#define _OBSERVER_HXX_
#include "MailStub.hxx"

class Observer {

public:

	Observer()
	{
	}

	virtual ~Observer()
	{
	}

		virtual void update(std::string work, std::string author) = 0;
		virtual const std::string name() = 0;

};

#endif
