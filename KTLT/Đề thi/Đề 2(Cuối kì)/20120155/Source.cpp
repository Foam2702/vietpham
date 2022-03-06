#include"Header.h"


list<string> DocFile(string TenFile) {
	list<string> listStr;
	string line = "";
	fstream f;
	if (f.is_open()) {
		f.close();
		f.open(TenFile);
	}
	else {
		f.open(TenFile);
	}
	if (f.is_open()) {
		cout << "KET NOI THANH CONG"<<endl;
		do {
			getline(f, line);
			listStr.push_back(line);
		} while (!f.eof());

	}
	f.close();
	return listStr;
}
void GhiFile(string TenFile, list<string>DSchuoi) {
	fstream f;
	if (f.is_open()) {
		f.close();
		f.open(TenFile, fstream::out); 
	}
	else {
		f.open(TenFile, fstream::out);
	}
	if (f.is_open()) {
		for (list<string>::iterator index = DSchuoi.begin(); index != DSchuoi.end(); index++) {
			f << *index << "\n";
		}
	}
	f.close();
}
string DSchuoi_thanh_Chuoi(list<string> DSchuoi, char Ch) {
	string str = "";
	for (list<string>::iterator index = DSchuoi.begin(); index != DSchuoi.end(); index++) {
		str = str + *index + Ch;
	}
	return str.substr(0, str.size() - 1);

}
list<string>Cat(string chuoi, char Ch) {
	list<string> DSXe;
	if (chuoi != "") {
		string str = "";
		stringstream ss;
		ss << chuoi;
		while (getline(ss, str, Ch)) {
			DSXe.push_back(str);
		}
	}
	return DSXe;
}
XE* Chuoi_thanh_Xe(string chuoi) {
	if (chuoi != "") {
		XE* xe = new XE;
		list<string>DSXe = Cat(chuoi, ';');
		list<string>::iterator index;
		index = next(DSXe.begin(), 0);
		xe->Dongxe = *index;
		index = next(DSXe.begin(), 1);
		xe->Hang = *index;
		index = next(DSXe.begin(), 2);
		xe->Loi = *index;
		index = next(DSXe.begin(), 3);
		xe->Maso = *index;
		return xe;

	}
	else {
		return nullptr;
	}
}
void XuatBaoCao_1Xe(XE xe) {
	cout << xe.Hang << ":" << xe.Loi;
	cout << endl;
}
void XuatBaoCao_DSXe(list<string> DSXe) {

}

