#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class CStudent
{
private:
	string _name;
	double _math;
	double _literature;
public:
	string Name();
	void setName(string name);
	double Math();
	void setMath(double math);
	double Literature();
	void setLiterature(double literature);
public:
	CStudent();
	CStudent(string, double, double);
	CStudent Input();
	double AVR(CStudent student);
	string Ranked(CStudent student);
	string toString();

	
};

