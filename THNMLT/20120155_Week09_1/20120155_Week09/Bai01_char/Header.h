#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<stdio.h>
using namespace std;
int strlen(char str[]);
void dem_khoangTrang_kySo_laTin_kyTukhac(char str[]);
int dem_Tu(char str[]);
void tu_Dainhat(char str[]);
void tu_Ngannhat(char str[]);
void XoaKyTu(char s[], int vitrixoa);

void XoaTatCaKhoangTrangODau(char s[]);
void XoaTatCaKhoangTrangOCuoi(char s[]);
void VietHoaKyTuDauTienConLaiVietThuongCuaMoiTu(char s[]);
void ChuanHoaChuoi(char s[]);
#endif