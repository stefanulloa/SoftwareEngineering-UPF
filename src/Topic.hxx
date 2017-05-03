#ifndef _TOPIC_HXX_
#define _TOPIC_HXX_

class Topic {

private: std::string _theme;
			
public:
	Topic() 
		: _theme ("")
		 
	{
				
	} 
 
		const std::string theme() {  
			return "red";
		}
		
		void theme( const std::string &theme) {
			_theme = theme + "\n";
		}
		
};

#endif
