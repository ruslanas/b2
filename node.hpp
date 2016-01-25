#ifndef _R_NODE_H
#define _R_NODE_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

namespace R {

	class Node {
		
		private:
			string name;
			string value;
			vector<Node *> children;
			map<string,string> attr;

		public:
			
			Node();
			Node(string name);
			~Node();
			
			void append(Node & node);
			Node * append(Node * ptr_node);
			Node * append(string name);
			void setAttribute(string name, string value);
			void setAttribute(string name, int value);
			void setAttribute(string name);
			void setValue(string val);

			string getAttribute(string name);
			Node * firstChild();
			string toString(int margin = 0) const;
			string toXML(int margin = 0);
	
	};
	
	typedef Node* PtrNode;
}

#endif
