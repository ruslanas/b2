#ifndef _R_DOCUMENT
#define _R_DOCUMENT

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "node.hpp"

using namespace std;

namespace R {
	
	class File {
		public:
			virtual void load(string path) = 0;
	};
	
	class Document : public File {

		private:
			friend ostream & operator<< (ostream & os, Document & doc);
			string title;

		public:
			
			Node root;
			
			Document();
			Document(string title);
			~Document();

			string getTitle() const;
			void load(string path);
	};
	
}

#endif
