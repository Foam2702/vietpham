#include"Header.h"

string fReadfile(string FileName)
{
	string doc="";
	string line="";
	fstream f;
	if (f.is_open()) {
		if (false) {
			f.close();
			f.open(FileName);
		}
	}
	else {
		f.open(FileName);
	}
	if (f.is_open()) {
		cout << "SUCCESSFUL CONNECTION !!"<<endl;
		do {
			getline(f, line);
			doc = doc + line + '\n';
		} while (!f.eof());
		
	}
	f.close();
	doc = doc.substr(0, doc.length() - 2);
	return doc;
}
void fWritefile(string FileName, list<string>Lines) {
	fstream f;
	if (f.is_open()) {
		if (false) {
			f.close();
			f.open(FileName, fstream::out);
		}
	}
	else {
		f.open(FileName, fstream::out);
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
	return  str;
}
list<string> fSplit(string str, char ch) {
	list<string> lines;
	string s = "";
	stringstream ss;
	if (str != "") {
		ss << str;
		while (getline(ss, s, ch)) {
			lines.push_back(s);
		}
	}
	return lines;
}
void fReplace(list<string>& lines, string oldstr, string newstr) {
	if (lines.size() != 0) {
		for (list<string>::iterator temp = lines.begin(); temp != lines.end(); temp++) {
			if (*temp != "") {
				int index = temp->find(oldstr);
				if (index > -1) {
					*temp = temp->replace(index, oldstr.length(), newstr);
				}
			}
		}
	}
}
list<Vehicle>StrtoListVehicle(string Str) {
	list<Vehicle> value;
	list<string> tempStr;
	list<string> temp;
	tempStr=fSplit(Str, '\n');
	for (list<string>::iterator s = tempStr.begin(); s != tempStr.end(); s++) {
		temp=fSplit(*s, ';');
		list<string>::iterator index = temp.begin();
		Vehicle veh;
		veh.type = index.operator*();
		veh.brand = index++.operator*(); 
		veh.capacity = index++.operator*();
		veh.code = index++.operator*();
		value.push_back(veh);
	}
	return value;
}
list<Vehicle>GroupByVehicle(list<Vehicle> ListVeh) {
	list<Vehicle> value;
	string compare = "";
	do {
		compare = ListVeh.begin().operator*().type;
		for (list<Vehicle>::iterator veh = ListVeh.begin(); veh != ListVeh.end();) {
			if (compare == veh.operator*().type) {
				value.push_back(*veh);
				list<Vehicle>::iterator del = veh;
				if (veh != ListVeh.end()) {
					veh++;
				}
				ListVeh.erase(del);
			}
			else {
				if (veh != ListVeh.end()) {
					veh++;
				}
			}
		}

	} while (ListVeh.empty() != true);
	// 
	do {
		compare = value.begin().operator*().brand;
		for (list<Vehicle>::iterator veh = value.begin(); veh != value.end();) {
			if (compare == veh.operator*().brand) {
				ListVeh.push_back(*veh);
				list<Vehicle>::iterator del = veh;
				if (veh != value.end()) {
					veh++;
				}
				value.erase(del);
			}
			else {
				if (veh != value.end()) {
					veh++;
				}
			}
		}
	} while (value.empty() != true);
	return ListVeh;
}
list<string> ListVehtoListString(list<Vehicle> ListVeh) {
	list<string> value;
	for (list<Vehicle>::iterator veh = ListVeh.begin(); veh != ListVeh.end(); veh++) {
		string s = veh.operator*().type + ";" + veh.operator*().brand + ";" + veh.operator*().capacity + ";" + veh.operator*().code;
		value.push_back(s);
	}
	return value;
}




