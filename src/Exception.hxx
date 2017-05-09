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
		return "The author does not exist";
	}

};

class exceptionInexistentOriginalFile: public exception
{
	public:
	 exceptionInexistentOriginalFile()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The original file does not exist";
	}

};

class exceptionHtmlConversionInexistentOriginalFile: public exception
{
	public:
	 exceptionHtmlConversionInexistentOriginalFile()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The original file does not exist";
	}

};

class exceptionUnsupportedFormat: public exception
{
	public:
	 exceptionUnsupportedFormat()
	{
	}
	virtual const char* what() const throw()
	{		
		return "Unsupported format";
	}

};

class exceptionInexistentTopic: public exception
{
	public:
	 exceptionInexistentTopic()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The topic does not exist";
	}

};

class exceptionInexistentClient: public exception
{
	public:
	 exceptionInexistentClient()
	{
	}
	virtual const char* what() const throw()
	{		
		return "The client does not exist";
	}

};

#endif
