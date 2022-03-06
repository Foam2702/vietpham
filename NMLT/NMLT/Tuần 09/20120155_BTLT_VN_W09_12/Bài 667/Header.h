#pragma once

#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;

struct Tinh {
	short matinh = 0;
	char tentinh[30]="";
	int danso = 0;
	double dientich = 0;
};


void ReadFile(ifstream& in, Tinh mang_tinh[], int& n);
void WriteFile(ofstream& out, Tinh mang_tinh[],int n);
void Output(ofstream& out, Tinh tinh);
Tinh Dientich_Lonnhat(Tinh mang_tinh[], int n);
void Sapxep_Dientich_Giamdan(Tinh mang_tinh[], int n);

#endif
