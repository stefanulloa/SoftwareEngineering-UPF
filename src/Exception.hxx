#ifndef _EXCEPTION_HXX_
#define _EXCEPTION_HXX_
#include <iostream>
#include <exception>
using namespace std;

class exceptionInexistentWork: public exception
{
	public:
	 exceptionInexistentWork()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The work does not exist";
	}

};

class exceptionInexistentAuthor: public exception
{
	public:
	 exceptionInexistentAuthor()
	{
	}
	virtual const char* what() const throw()
	{		
		return "red";
	}

};

#endif
