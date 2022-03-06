#pragma once
#ifndef __HEADER__H__
#define __HEADER__H__
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

string fReadfile(string FileName);
void fWritefile(string FileName, list<string>Lines);
string fListString_to_String(list<string> Lines);
list<string> fSplit(string str, char ch);
void fReplace(list<string>& lines, string oldstr, string newstr);
list<Vehicle>StrtoListVehicle(string Str);
list<Vehicle>GroupByVehicle(list<Vehicle> ListVeh);
list<string> ListVehtoListString(list<Vehicle> ListVeh);
#endif // !__HEADER__H__
