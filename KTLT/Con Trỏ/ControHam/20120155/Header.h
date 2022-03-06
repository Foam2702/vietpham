#pragma once
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
using namespace std;

struct FRACTION {
	int tu;
	int mau;
};
typedef struct FRACTION PS;
//void InputFraction(PS ps);
//void OutputFraction(PS ps);
void XuLyMenu(PS(*standard)( PS, PS), PS ps1, PS ps2);
istream& operator>>(istream& is, PS& ps);
ostream& operator<<(ostream& os,const PS& ps);
//PS operator+(PS ps1, PS ps2);
//PS operator -(PS& ps1, PS& ps2);
//PS operator *(PS& ps1, PS& ps2);
//PS operator /(PS& ps1, PS& ps2);
PS* TaoPS();
PS SumFraction(PS ps1,PS ps2);
PS MinusFraction(PS ps1, PS ps2);
PS MutiplyFraction(PS ps1, PS ps2);
PS DivideFraction(PS ps1, PS ps2);

#endif