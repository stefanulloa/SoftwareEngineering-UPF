#ifndef _CONVERTER_HXX_
#define _CONVERTER_HXX_
#include "Converter.hxx"

class Converter {
	
	public:
		Converter()
		{	
		} 

		virtual ~Converter()
		{
		}	
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName){};

};

#endif
