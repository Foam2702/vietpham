#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<sstream>
using namespace std;

struct Vehicle {
	string type = "";
	string brand = "";
	string capacity = "";
	string code = "";
};
list<string> fReadFile(string FileName) {
	list<string> listStr;
	string line = "";
	fstream f;
	if (f.is_open()) {
		f.close();
		f.open(FileName);
	}
	else {
		f.open(FileName);
	}
	if (f.is_open()) {
		cout << "CONNECTION SUCCESSFUL";
		do {
			getline(f, line);
			listStr.push_back(line);
		} while (!f.eof());

	}
	f.close();
	return listStr;
}
void fWritefile(string FileName, list<string>ListStr) {
	fstream f;
	if (f.is_open()) {
			f.close();
			f.open(FileName, fstream::app); //out là ghi đè,app là ghi tiếp
	}
	else {
		f.open(FileName, fstream::app);
	}
	if (f.is_open()) {
		for (list<string>::iterator index = ListStr.begin(); index != ListStr.end(); index++) {
			f << *index<<"\n";
		}
	}
	f.close();
}
list<string>f_Split(string Str, char Ch) {
	list<string> listStr;
	if (Str != "") {
		string str = "";
		stringstream ss;
		ss << Str;
		while (getline(ss,str,Ch)) {
			listStr.push_back(str);
		}
	}
	return listStr;
}
string f_ListString_toString(list<string> ListStr,char Ch) {
	string str = "";
	for (list<string>::iterator index = ListStr.begin(); index != ListStr.end(); index++) {
		str = str + *index + Ch;
	}
	return str.substr(0,str.size() - 1);

}
Vehicle* f_String_toVehicle(string Str) {
	if (Str != "") {
		Vehicle* veh = new Vehicle;
		list<string>listStr = f_Split(Str, ';');
		list<string>::iterator index;
		index = next(listStr.begin(), 0);
		veh->type = *index;
		index = next(listStr.begin(), 1);
		veh->brand = *index;
		index = next(listStr.begin(), 2);
		veh->capacity = *index;
		index = next(listStr.begin(), 3);
		veh->code = *index;
		return veh;

	}
	else {
		return nullptr;
	}
}
string f_Vehicle_toString(Vehicle veh) {
	string str = "";
	str = str + veh.type + ";";
	str = str + veh.brand + ";";
	str = str + veh.capacity + ";";
	str = str + veh.code;
	return str;

}
Vehicle* f_InputVehicle() {
	Vehicle* veh;
	string str = "";
	getline(cin, str);
	cin.ignore();
	cin.clear();
	veh = f_String_toVehicle(str);
	return veh;
}
list<Vehicle> f_Input_ListVehicle() {
	list<Vehicle> listVeh;
	Vehicle* veh;
	char check = 'n';
	int count = 1;
	cout << "Nhap danh sach xe:" << endl;
	do {
		cout << "Nhap xe:" << count << ":";
		veh = f_InputVehicle();
		if (veh != nullptr) {
			listVeh.push_back(*veh);
			cout << "Do you want input? (y/n):";
			cin >> check;
			count++;
		}

	} while (check != 'n');
}
list<string>f_ListVeh_toListString(list<Vehicle> ListVeh) {
	
	list<string> listStr;
	if (ListVeh.empty() != true) {
		
		for (list<Vehicle>::iterator index=ListVeh.begin();index!=ListVeh.end();index++){
			listStr.push_back(f_Vehicle_toString(*index));
		}
	}
	return listStr;
}
list<Vehicle> f_ListString_to_ListVehicle(list<string>ListStr) {
	list<Vehicle> ListVeh;
	if (ListStr.empty() != true) {
		for (list<string>::iterator index = ListStr.begin(); index != ListStr.end(); index++) {
			ListVeh.push_back(*(f_String_toVehicle(*index)));
		}
	}
	return ListVeh;
}
int main() {
	/*list<Vehicle> ListVeh;
	cout<<f_Vehicle_toString(*f_InputVehicle());*/
	list<string>ListStrInfoVeh = fReadFile("Vehicle.txt");
	cout << f_ListString_toString(ListStrInfoVeh,'\n');
	list<Vehicle>ListVeh;
	cout<< f_Vehicle_toString(*f_InputVehicle());

	
}
