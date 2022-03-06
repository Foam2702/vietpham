#pragma once
#ifndef __HEADER__H__
#define __HEADER__H__
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<sstream>
using namespace std;
struct XE {
	string Dongxe;
	string Hang;
	string Loi;
	string Maso;
};
list<string> DocFile(string TenFile);
void GhiFile(string TenFile, list<string>DSchuoi);
string DSchuoi_thanh_Chuoi(list<string> DSchuoi, char Ch);
list<string>Cat(string chuoi, char Ch);
XE* Chuoi_thanh_Xe(string chuoi);
void XuatBaoCao(list<string> DSchuoi);

#endif