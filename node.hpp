#ifndef _R_NODE_H
#define _R_NODE_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

namespace R {

	class Node {
		
		private:
			string name;
			vector<Node *> children;
			map<string,string> attr;
		
		public:
			
			Node();
			Node(string name);
			~Node();
			
			void append(Node & node);
			Node * append(Node * ptr_node);
			
			void setAttribute(string name, string value);
			void setAttribute(string name);
			
			string getAttribute(string name);
			Node * firstChild();
			string toString(int margin = 0) const;
			string toXML(int margin = 0);
	
	};
	
}

#endif
