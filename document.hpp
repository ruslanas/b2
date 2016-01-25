#ifndef _R_DOCUMENT_H
#define _R_DOCUMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

#include "node.hpp"

using namespace std;

namespace R {
	
	class File {
		protected:
			string path;
			
		public:
			virtual void load(string path) = 0;
			virtual void save() = 0;
	};
	
	class Document : public File {

		private:
			friend ostream & operator<< (ostream & os, Document & doc);
			string title;

		public:
			
			Node root;
			
			Document(string title = "Untitled");
			~Document();

			string getTitle() const;
			void load(string path);
			void save();
	};
	
}

#endif
