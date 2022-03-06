#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;

struct Xe
{
	char nhanhieu[30]="";
	char mausac ;
	int diem = 0;
};




void Input_1Xe(Xe &xe);
void Input_DsXe(Xe list[], int n);
void Output_1Xe(Xe xe);
void Output_DsXe(Xe list[], int n);
void Dem_Xuat_Toyota_8(Xe list[], int n);
void Sapxep_Mausac(Xe list[], int n);
void Sapxep_Alphabet(Xe list[], int n);
#endif
