#ifndef _CHANNEL_HXX_
#define _CHANNEL_HXX_
#include "Observer.hxx"

struct novelty{
	std::string workNovelty;
	std::string authorNovelty;
};

typedef std::list<novelty> NoveltyList;

class Channel : public Observer{

private: std::string _title;
	std::string _description;
	NoveltyList _novelties;

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
				novelty nov;
				nov.workNovelty = work;
				nov.authorNovelty = author;
				_novelties.push_back(nov);
		}

		const std::string workNovelty(novelty nov){
			return nov.workNovelty;
		}

		const std::string authorNovelty(novelty nov){
			return nov.authorNovelty;
		}

		const std::string listItems(){
			std::string items;
			for(NoveltyList::iterator in = _novelties.begin(); in != _novelties.end(); in++){
				items += "<item>\n<title>Novelty: '" + workNovelty((*in)) + "' by '" + authorNovelty((*in)) + "'</title>\n<link>http://www.meltingpotonline.com/infoWork?author='" + authorNovelty((*in)) + "'&title='" + workNovelty((*in)) + "'</link>\n</item>\n";
				items = "red";
			}
			return items;
		}




};

#endif
