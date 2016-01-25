#include "node.hpp"

namespace R {

	Node::Node():name("document") {
		cerr << "<" + this->name + ">" << endl;
	}
	Node::Node(string name):name(name) {
		cerr << "Node <" << this->name << "> created" << endl;
	}
	
	Node::~Node() {
		cerr << "Node <" << this->name << "> destroyed" << endl;
	}
	
	Node * Node::firstChild() {
		return this->children[0];
	}
	
	void Node::append(Node & node) {
		this->children.push_back(&node);
	}
	Node * Node::append(Node * ptr_node) {
		this->children.push_back(ptr_node);
		return ptr_node;
	}
	
	string Node::getAttribute(string name) {
		return this->attr[name];
	}
	void Node::setAttribute(string name, string value) {
		this->attr[name] = value;
	}
	void Node::setAttribute(string name) {
		this->attr[name] = "";
	}
	
	string Node::toString(int margin) const {
		
		string out = this->name + " [";

		for(auto it = attr.begin();it != attr.end();++it) {
			out += " " + it->first + "=\"" + it->second + "\"";
		}
		out += " ]\n";
				
		for(auto it = children.begin();it != children.end();++it) {
			Node * node = *it;
			char c;
			
			if(distance(it, children.end()) == 1) {
				c = char(192);
			} else {
				c = char(195);
			}
			
			out += string(margin, ' ') + c + node->toString(margin + 2);
		}
		
		return out;
	}
	
	
}

