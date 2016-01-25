#include "document.hpp"

namespace R {
	
	Document::Document(string title):title(title) {
		this->root = Node();
	}

	Document::Document(Node & root):root(root) {
	}
	
	Document::~Document() {
		for (auto it : nodes) {
			delete it;
		}
	}
	
	void Document::load(string path) {
		
		this->path = path;
		
		ifstream ifs(path);
		
		string line;
		getline(ifs, line);
		auto pos = line.find(">");
		cout << line.substr(0, pos) << endl;
	}

	Node * Document::createNode(string name) {
		Node * ptr_node = new Node(name);
		nodes.push_back(ptr_node);
		return ptr_node;
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
		string output = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
		output += "<!DOCTYPE fcpxml>\n";
		output += root.toXML() + '\n';
		return output;
	}
}

