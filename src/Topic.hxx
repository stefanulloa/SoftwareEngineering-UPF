#ifndef Topic_hxx
#define Topic_hxx
#include "Subject.hxx"

class Topic : public Subject{

protected: std::string _theme;

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

		void subscribeClient(Client *subscriptor){
				addObserver(subscriptor);
		}

		void subscribeChannel(Channel *subscriptor){
				//addObserver(subscriptor);
		}

};

#endif
