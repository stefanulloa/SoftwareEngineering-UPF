#ifndef _CONVERTERGROUP_HXX_
#define _CONVERTERGROUP_HXX_
#include "Converter.hxx"
#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"

class ConverterGroup {
	
	protected:
	HtmlConverter _oneHtmlConverter;
	
	public:
		ConverterGroup()
		{	
		} 

		~ConverterGroup()
		{
		}	
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName){
			_oneHtmlConverter.convert(originalFileName, generatedFileName);
			};
		
		void add(const std::string type){
			if(type == "html"){
				HtmlConverter convert;
				_oneHtmlConverter = convert;
			}
		};
		
};

#endif
