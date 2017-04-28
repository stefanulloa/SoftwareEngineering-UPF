#ifndef _HTMLCONVERTER_HXX_
#define _HTMLCONVERTER_HXX_
#include "libLibreOffice2Html.hxx"

class HtmlConverter{
	
	public:
		HtmlConverter()
		{	
		} 
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName) {
			
			std::string convertedName = generatedFileName + " [multiple HTML files].war";
			OO_WarGeneration( originalFileName.c_str(), convertedName.c_str() );
			
		}		

};

#endif
