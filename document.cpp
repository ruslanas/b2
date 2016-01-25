#include "document.hpp"

namespace R {
	
	Document::Document(string title):title(title) {
		this->root = Node();
	}
	
	Document::~Document() {
		
	}
	
	void Document::load(string path) {
		
		this->path = path;
		
		ifstream ifs(path);
		
		string line;
		getline(ifs, line);
		auto pos = line.find(">");
		cout << line.substr(0, pos) << endl;
	}
	void Document::save() {
		ofstream ofs("temp.xml");
		ofs << this->toXML();
	}
	string Document::getTitle() const {
		return title;
	}
	ostream & operator<< (ostream & os, Document & doc) {
		os << doc.root.toString() << endl;
		return os;
	}
	string Document::toXML() {
		return "<?xml>\n" + root.toXML();
	}
}

