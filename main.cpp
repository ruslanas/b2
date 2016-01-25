#include "document.hpp"

using namespace std;
using namespace R;

int main(int argc, char * argv[]) {

	Document doc("App");
	
	if(argc > 1) {
		doc.load(argv[1]);
	}
	
	Node child = Node("todo");
	doc.root.append(child);
	
	doc.root.setAttribute("title", "B2");
	doc.root.setAttribute("version", "1.0");
	
	Node t1 = Node("task");
	child.append(t1);
	t1.setAttribute("description");
	Node f = Node("attachment");
	f.setAttribute("file", "todo.b2");
	t1.append(f);

	// don't forget to clean up heap
	Node * ptr_el = t1.append(new Node("attach"));
	
	ptr_el->setAttribute("data");
	
	Node * ptr_section = doc.root.firstChild();

	Node t2 = Node("task");
	ptr_section->append(t2);
	
	t2.setAttribute("description", "pretty-print");
	t2.setAttribute("completed", "true");
	
	cout << doc.getTitle() << endl;	
	cout << doc.toXML();
	
	try {
		doc.save();
	} catch (const char* msg) {
		cout << msg << endl;
	} catch (...) {
		cout << "Excepcellent" << endl;
	}
	
	delete ptr_el;
	
    return 0;
}

