#pragma once
#ifndef HEADER1
#define HEADER1

#include<iostream>
#include<string>
using namespace std;


struct SinhVien {
	string HoTen;
	string NgaySinh;
	bool GioiTinh;
};
void Nhap(SinhVien *SV);
void Xuat(SinhVien *SV);
SinhVien* TaoSV();

#endif