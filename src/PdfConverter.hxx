#ifndef _PDFCONVERTER_HXX_
#define _PDFCONVERTER_HXX_
#include "libLibreOffice2Pdf.hxx"
#include "Exception.hxx"
#include "Converter.hxx"

class PdfConverter {
	
	private: 
		std::string watermarkString;
		
	public:
		PdfConverter()
		{	
		} 
		
		void convert(const std::string &originalFileName, const std::string &generatedFileName) {
			
			std::string convertedName = generatedFileName + " [printable].pdf";
			LibreOfficeTools::convertToPdf(
			originalFileName, convertedName, watermarkString = "");
	
		}		

};

#endif
