#ifndef _TOPIC_HXX_
#define _TOPIC_HXX_

class Topic {

private: std::string _theme;
			
public:
	Topic() 
		: _theme ("")
		 
	{				
	} 
	
	Topic(const std::string &theme) 
		: _theme(theme)
	{	
	} 
 
		const std::string theme() {  
			return _theme;
		}
		
		void theme( const std::string &theme) {
			_theme = theme;
		}
		
};

#endif
