#include "document.hpp"

using namespace std;
using namespace R;

int main(int argc, char * argv[]) {

	Node fcp_root = Node("fcpxml");
	Document doc(fcp_root);
	
	Node resources = Node("resources");
	doc.root.append(resources);
	doc.root.setAttribute("version", "1.5");
	
	Node lib = Node("library");
	doc.root.append(lib);
	lib.setAttribute("location");
	
	Node evt = Node("event");
	evt.setAttribute("name", "event_name");
	evt.setAttribute("uid");
	lib.append(evt);
	Node project = Node("project");
	lib.append(project);
	
	PtrNode seq = project.append("sequence"); // dynamically allocates memory!
	PtrNode spine = seq->append("spine");
	PtrNode gap = spine->append("gap");

	// read subs from std

	bool start = true;
	int ln = 0;
	while (!cin.eof()) {
		string line;

		getline(cin, line);

		if (line.empty()) {
			start = true;
			continue;
		}

		if (start) {
			// skip first line
			ln = 0;
			start = false;
			continue;
		}

		ln++;
		PtrNode titleNode = doc.createNode("title");
		titleNode->setAttribute("lane", ln);
		PtrNode txt = doc.createNode("text");
		PtrNode txtStyle = doc.createNode("text-style");
		PtrNode txtStyleDef = doc.createNode("text-style-def");

		titleNode->setAttribute("name", "Basic Title");
		titleNode->append(txt);
		titleNode->append(txtStyleDef);

		txt->append(txtStyle);
		txtStyle->setValue(line);
		gap->append(titleNode);
		
	}

	Node format = Node("format");
	resources.append(format);
	format.setAttribute("id", "r1");

	Node f = Node("effect");
	f.setAttribute("id", "r2");
	resources.append(f);

	cout << doc.toXML();
	
	delete seq;
	delete spine;
	delete gap;

    return 0;
}

