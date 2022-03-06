#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;
//bai 581
struct ToaDo {
	double x = 0;
	double y = 0;
};


struct TamGiac {
	ToaDo A;
	ToaDo B;
	ToaDo C;
};

void NhapToado(ToaDo& toado);
void XuatToaDo(ToaDo toado);
double KhoangCach2ToaDo(ToaDo a, ToaDo b);
bool KiemTraTamGiac(TamGiac TG);
void NhapTamGiac(TamGiac& TG);
void XuatTamGiac(TamGiac TG);
double ChuViTamGiac(TamGiac TG);
void Nhap_MangTamGiac(TamGiac TG[], int& n);
void Xuat_MangTamGiac(TamGiac TG[], int n);
void tamgiac_Chuvi_Lonnhat(TamGiac TG[], int n);

#endif 
