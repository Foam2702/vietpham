#include "CStudent.h"

string CStudent::Name() { 
	return _name; 
}
void CStudent::setName(string name) {
	this->_name = name;
}
double CStudent::Math() {
	return _math;
}
void CStudent::setMath(double math) {
	this->_math = math;
}
double CStudent::Literature() {
	return _literature;
}
void CStudent::setLiterature(double literature) {
	this->_literature = literature;
}
CStudent::CStudent() {
	this->_name = " ";
	this->_math = 0;
	this->_literature = 0;
}
CStudent::CStudent(string name, double math, double literature) {
	this->_name = name;
	this->_math = math;
	this->_literature = literature;
}
CStudent CStudent::Input() {
	CStudent student;
	string name;
	double math, literature;
	cout << "------INPUT------" << endl;
	cout << "Enter name:";
	getline(cin, name);
	setName(name);
	cout << "Enter Math score:";
	cin >> math;
	setMath(math);
	cout << "Enter Literature score:";
	cin >> literature;
	setLiterature(literature);
	cin.clear(); cin.ignore();
	return student;
}
double CStudent::AVR(CStudent student) {
	return (student.Math() + student.Literature()) / 2;
}
string CStudent::toString() {
	string result;
	stringstream builder;
	cout << "------OUTPUT------"<<endl;
	builder << "Name:" << _name << ",Math:" << _math << ",Literature:" << _literature << endl;

	result = builder.str();
	return result;
}

string CStudent::Ranked(CStudent student) {
	string result;
	stringstream builder;
	double avr = CStudent::AVR(student);
	if (avr >= 9) {
		builder << "Xep loai:Xuat sac" << endl;
	}
	else if (avr >= 8) {
		builder << "Xep loai:Gioi" << endl;
	}
	else if (avr >= 6.5) {
		builder << "Xep loai:Kha" << endl;
	}
	else if (avr >= 5.0) {
		builder << "Xep loai:Trung binh" << endl;
	}
	else {
		builder << "Xep loai:Yeu" << endl;
	}
	result = builder.str();
	return result;
}