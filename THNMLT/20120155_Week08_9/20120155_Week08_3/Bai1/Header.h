#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;
void nhapMatran(int matrix[][50], int& n);
void xuatMatran(int matrix[][50], int n);
int tinhTong(int matrix[][50], int n);
int dem_solanXuathien_x(int matrix[][50], int n,int x);
bool check_Prime(int x);
int dem_solanXuathien_SNT(int matrix[][50], int n);
int tinhTong_SokhongAm(int matrix[][50], int n);
int tinhTong_Phantu_duongCheochinh(int matrix[][50], int n);
bool kiemTra_duongCheochinh_Tangdan(int matrix[][50], int n);
int tinhTong_Phantu_duongCheophu(int matrx[][50], int n);
void sapXep_tangDan_Tungdong(int matrix[][50], int n);
void tim_Max_dong_cot_matran(int matrix[][50], int maxtungdong[], int maxtungcot[], int n);
void tim_Min_dong_cot_matran(int matrix[][50], int mintungdong[], int mintungcot[], int n);
void tim_Max_duave_duongCheochinh(int matrix[][50], int n);
#endif