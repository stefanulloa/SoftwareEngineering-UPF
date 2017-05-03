#ifndef _CONVERTER_HXX_
#define _CONVERTER_HXX_

class Converter {
	
	public:
		Converter()
		{	
		} 

		virtual ~Converter()
		{
		}	
		
		virtual void convert(const std::string &originalFileName, const std::string &generatedFileName) = 0;

		virtual void activeWatermark(const std::string &any) {};
};

#endif
