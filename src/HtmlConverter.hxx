#ifndef _HTMLCONVERTER_HXX_
#define _HTMLCONVERTER_HXX_
#include "libLibreOffice2Html.hxx"
#include "Exception.hxx"

class HtmlConverter{
	
	public:
		HtmlConverter()
		{	
		} 
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName) {
			
			std::string convertedName = generatedFileName + " [multiple HTML files].war";
			if (OO_WarGeneration( originalFileName.c_str(), convertedName.c_str() ) != 0)
				throw exceptionHtmlConversionInexistentOriginalFile();
		
		}		

};

#endif
