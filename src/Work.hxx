#ifndef _WORK_HXX_
#define _WORK_HXX_

class Work {

private: std::string _title;
		 int _isbn;
		 std::string _originalFile;
		 std::string _aText;
			
public:
	Work() 
		: _title ("-- Untitled --"),
		 _isbn (-1),
		 _originalFile (""),
		 _aText("-1, '-- Untitled --', ''")
		 
	{
				
	} 

		const std::string title() const {  
			return _title;
		}
		
		void title( const std::string &title) {
			_title = title;
		}
		
		 const int isbn() const{
            return _isbn;
        }
        
        void isbn( const int &isbn) {
			_isbn = isbn;
		}
		
		const std::string originalFile() const {
			return _originalFile;
		}
		
		void originalFile( const std::string &originalFile) {
			_originalFile = originalFile;
		}
		
		const std::string aText() {
			std::stringstream ss;
			ss << _isbn << ", " << "'" << _title << "'" << ", " << "'" << _originalFile << "'"; 
			return ss.str();;
		}
		
};

#endif
