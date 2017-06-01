#ifndef _CHANNEL_HXX_
#define _CHANNEL_HXX_
#include "Observer.hxx"

class Channel : public Observer{

private: std::string _title;
	std::string _description;

public:

	Channel(const std::string &title, const std::string &description)
		: _title(title), _description(description)
	{
	}

		const std::string title() {
			return _title;
		}

		void title(const std::string &title) {
			_title = title;
		}

		const std::string description() {
			return _description;
		}

		void description(const std::string &description) {
			_description = description;
		}

		const std::string listThematicChannel(){
			std::string channel;
			channel = title() + "\n" + "\t" + description() + "\n";
			return channel;
		}

		const std::string name(){return "any";} //implement abstract method

		void update(std::string work, std::string author){
		}




};

#endif
