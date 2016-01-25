#include "document.hpp"

namespace R {
	
	Document::Document():title("Untitled") {
		this->root = Node();
	}
	
	Document::Document(string title):title(title) {
		this->root = Node();
	}
	Document::~Document() {
		
	}
	
	void Document::load(string path) {
		cout << "Loading " << path << "..." << endl;
	}
	string Document::getTitle() const {
		return title;
	}
	ostream & operator<< (ostream & os, Document & doc) {
		os << doc.root.toString() << endl;
		return os;
	}
}

