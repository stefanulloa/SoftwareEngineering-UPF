#ifndef _PDFCONVERTER_HXX_
#define _PDFCONVERTER_HXX_
#include "libLibreOffice2Pdf.hxx"
#include "Exception.hxx"
#include "Converter.hxx"

class PdfConverter : public Converter {
	
	private: 
		std::string _watermarkString;
		
	public:
		PdfConverter()
		:_watermarkString("")
		{	
		} 
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName) {
			
			std::string convertedName;
			
			try{
			if (_watermarkString == ""){
			convertedName = generatedFileName + " [printable].pdf";
			}
			else {
			convertedName = generatedFileName + " [watermark].pdf";
			}
			LibreOfficeTools::convertToPdf(originalFileName, convertedName, _watermarkString);
			}
			catch ( ... ){
				//throw exceptionInexistentOriginalFile();
			}
		}	
		
		void activeWatermark(const std::string &any){
			_watermarkString = any;
		};	

};

#endif
