#ifndef _CONVERTERGROUP_HXX_
#define _CONVERTERGROUP_HXX_
#include "Converter.hxx"
#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"

class ConverterGroup {
	
	protected:
	std::list<HtmlConverter*> _converterGroup;
	
	public:
		ConverterGroup():_converterGroup(0)
		{	
		} 

		~ConverterGroup()
		{
			while(!_converterGroup.empty()) delete _converterGroup.front(), _converterGroup.pop_front();
		}	
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName){
			
			HtmlConverter html = *_converterGroup.front();
			html.convert(originalFileName, generatedFileName);
			//*_converterGroup->front()->convert(originalFileName, generatedFileName);
			
			};
		
		void add(const std::string type){
			if(type == "html"){
				HtmlConverter * htmlConvert = new HtmlConverter;
				_converterGroup.push_back(htmlConvert);
			}
		};
		
};

#endif
