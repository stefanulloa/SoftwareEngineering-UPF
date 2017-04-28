#ifndef _HTMLCONVERTER_HXX_
#define _HTMLCONVERTER_HXX_

class HtmlConverter{
	
	public:
		HtmlConverter()
		{	
		} 
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName) {
			
			std::string convertedName = generatedFileName + " [multiple HTML files].war";
			std::ofstream generatedFile( convertedName.c_str() );
			generatedFile << "War file generated from 'originals/Original.odt'\n";
			
		}		

};

#endif
