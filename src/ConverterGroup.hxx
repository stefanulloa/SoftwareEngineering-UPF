#ifndef _CONVERTERGROUP_HXX_
#define _CONVERTERGROUP_HXX_
#include "Converter.hxx"
#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"

class ConverterGroup {
	
	protected:
	std::list<Converter*> _converterGroup;
	
	public:
		ConverterGroup():_converterGroup(0)
		{	
		} 

		~ConverterGroup()
		{
			while(!_converterGroup.empty()) delete _converterGroup.front(), _converterGroup.pop_front();
		}	
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName){
			
			if(!_converterGroup.empty()){
				
				Converter * converter = _converterGroup.front();
				converter->convert(originalFileName, generatedFileName);
			
			}else{}
			
			};
		
		void add(const std::string type){
			if(type == "html"){
				Converter * htmlConvert = new HtmlConverter;
				_converterGroup.push_back(htmlConvert);
			}
			if(type == "pdf_print"){
				Converter * pdfPrintableConvert = new PdfConverter;
				_converterGroup.push_back(pdfPrintableConvert);
			}
			if(type == "pdf_mark"){
				Converter * pdfPrintableConvert = new PdfConverter;
				pdfPrintableConvert->activeWatermark("any_string");
				_converterGroup.push_back(pdfPrintableConvert);
			}
		};
		
};

#endif
