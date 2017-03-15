#ifndef _EXCEPTION_HXX_
#define _EXCEPTION_HXX_
#include <iostream>
#include <exception>
using namespace std;

class Exception: public exception
{
	public:
	 Exception()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The work does not exist";
	}

};

#endif
