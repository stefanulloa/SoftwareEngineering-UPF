#ifndef _CONVERTERGROUP_HXX_
#define _CONVERTERGROUP_HXX_
#include "Converter.hxx"
#include "HtmlConverter.hxx"
#include "PdfConverter.hxx"
#include "Exception.hxx"

class ConverterGroup {
	
	protected:
	std::list<Converter*> _converterGroup;
	
	public:
		ConverterGroup():_converterGroup(0)
		{	
		} 

		~ConverterGroup()
		{
			for(std::list<Converter*>::iterator ib = _converterGroup.begin(); ib!=_converterGroup.end(); ++ib){
			delete (*ib);
			}
		}
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName){
			
			if(!_converterGroup.empty()){
				
				for(std::list<Converter*>::iterator it = _converterGroup.begin(); it!=_converterGroup.end(); ++it){
				(*it)->convert(originalFileName, generatedFileName);
				}
			
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
			if(!(type == "html" || type == "pdf_print" || type == "pdf_mark")){
				throw exceptionUnsupportedFormat();
			}
		};
		
};

#endif
