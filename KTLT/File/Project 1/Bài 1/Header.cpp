#include"Header.h"

list<string> fReadfile(string FileName)
{	
	list<string> doc;
	string line;
	fstream f;
	if(f.is_open()){
		if (false) {
			f.close();
			f.open(FileName);
		}
	}
	else {
		f.open(FileName);
	}
	if (f.is_open()) {
		cout << "SUCCESSFUL CONNECTION !!";
		do {
			getline(f, line);
			doc.push_back(line);
		} while (!f.eof());
	}
	f.close();
	return doc;
}
void fWritefile(string FileName, list<string>Lines) {
	fstream f;
	if (f.is_open()) {
		if (false) {
			f.close();
			f.open(FileName,fstream::out);
		}
	}
	else {
		f.open(FileName,fstream::out);
	}
	if (f.is_open()) {
		f << fListString_to_String(Lines);
	}
	f.close();
}
string fListString_to_String(list<string> Lines) {
	string str = "";
	for (list<string>::iterator temp = Lines.begin(); temp != Lines.end(); temp++) {
		str = str + *temp + "\n";
	}
	return  str.substr(0, str.size() - 1);
}
list<string> fSplit(string str,char ch) {
	list<string> lines;
	string s = "";
	stringstream ss;
	if (str != "") {
		ss << str;
		while (getline(ss,s,ch) ) {
			lines.push_back(s);
		}
	}
	return lines;
}
void fReplace(list<string>&lines,string oldstr,string newstr) {
	if (lines.size() != 0) {
		for (list<string>::iterator temp = lines.begin(); temp != lines.end(); temp++) {
			if (*temp != "") {
				int index = temp->find(oldstr);
				if (index > -1) {
					*temp=temp->replace(index, oldstr.length(), newstr);
				}
			}
		}
	}
}

