#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;

//cau 540
struct ToaDo {
	double x;
	double y;
};


void Input_Tinh(ToaDo& toado);
void Output_Tinh(ToaDo toado);
double KhoangCach2ToaDo(ToaDo a, ToaDo b);

#endif 
