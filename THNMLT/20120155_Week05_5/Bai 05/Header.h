#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

bool LaNgayHopLe(int ngay, int thang, int nam);
bool laNamNhuan(int nam);
int ThuTuNgayTrongNam(int ngay, int thang, int nam);
int ThuTuNgayTrongTuan(int ngay, int thang, int nam);
void ngaySau(int ngay, int thang, int nam, int& ngaySau, int& thangSau, int& namSau);
void NgayTruoc(int ngay, int thang, int nam, int& ngayTruoc, int& thangTruoc, int& namTruoc);

#endif