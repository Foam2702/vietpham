#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;

void Input(int arr[], int& n);
void Output(int arr[], int n);
void XoaViTri(int arr[], int& n, int k);
void XoakPhantu(int arr[], int& n, int k, int i);
void Dem_In_phanTuKhacnhau(int arr[], int n);
void Dem_In_phanTuKhacnhauTrongDoan(int arr[], int n, int x, int y);
int phanTu_Lonthu2(int arr[], int n);
int CountMax(int arr[], int n, int x);
int Xuathien_Max(int arr[], int n);
int timMin_trongDoan(int arr[], int n, int x, int y);
int kPhantuLientiep_Max(int arr[], int n, int k);
void daoNguoc_Mang(int arr[], int n);
void sapXep_chanle(int arr[], int n);
bool check_soChinhphuong(int x);
void sapXep_chinhPhuong_Tangdan(int arr[], int n);
void doiCho_2doan_mangMoi(int arr[], int &n, int &m);
bool check_Decreasing(int arr[], int n);
bool check_Increasing(int arr[], int n);
void check_IncreasingLienTuc(int arr[], int n);
void DayConTangLienTiep(int arr[], int n);
bool SoNguyenTo(int x);
int SoNguyenToNhoNhat(int arr[], int n);
#endif 