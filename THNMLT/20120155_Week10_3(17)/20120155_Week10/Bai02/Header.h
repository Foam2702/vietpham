#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
using namespace std;

struct Diem2D
{
	float iX=0;
	float iY=0;
};
struct TamGiac {
	Diem2D A;
	Diem2D B;
	Diem2D C;
};
void Input(Diem2D diem);
void Output(Diem2D diem);
double Khoangcach_haidiem(Diem2D diem1, Diem2D diem2);
float ChuViTamGiac(TamGiac a);
float DientichTamGiac(TamGiac a);
void GocPhanTuTrongMatPhang(Diem2D a);
bool KiemTraTamGiac(TamGiac a);
void InputTamGiac(TamGiac& a);
void OutputTamGiac(TamGiac a);
int DiemTrongTamGiac(Diem2D d, Diem2D a, Diem2D b, Diem2D c);
#endif
