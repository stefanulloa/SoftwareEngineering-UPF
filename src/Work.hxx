#ifndef _WORK_HXX_
#define _WORK_HXX_
#include "Topic.hxx"
#include "Exception.hxx"

typedef std::list<Topic*> TopicList;

class Work {

private: std::string _author;
		 std::string _title;
		 int _isbn;
		 std::string _originalFile;
		 std::string _aText;
		 TopicList _topics;
			
public:
	Work() 
		: _title ("-- Untitled --"),
		 _isbn (-1),
		 _originalFile (""),
		 _aText("-1, '-- Untitled --', ''")
		 
	{
				
	} 

	Work(const std::string &title, const int &isbn, const std::string &originalFile) 
		: _title (title),
		 _isbn (isbn),
		 _originalFile (originalFile),
		 _aText("")
		 
	{
	
	}
	
	Work(const std::string &author, const std::string &title, const int &isbn, const std::string &originalFile) 
		: _author(author),
		 _title (title),
		 _isbn (isbn),
		 _originalFile (originalFile),
		 _aText("")
		 
	{
	
	}

	~Work(){
	TopicList::iterator it = _topics.begin();
		while(it != _topics.end()){
			Topic *pEliminarTopic = (*it);
			delete pEliminarTopic;
			it++;
		}
	}
		 
		const std::string author() const {  
			return _author;
		}
		
		void author( const std::string &author) {
			_author = author;
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
		
		void addTopic(const std::string theme){
			Topic *topic = new Topic(theme);
			_topics.push_back(topic);	
		}		

		const std::string topics() {
        		std::string a;
        		std::stringstream aw;
        		for(TopicList::iterator it = _topics.begin(); it != _topics.end(); it++){
           			aw << "\t\t'" << (*it)->theme()<< "'\n red";
            			a = aw.str();
        		}
            		return a;
    		}
		
};

#endif
