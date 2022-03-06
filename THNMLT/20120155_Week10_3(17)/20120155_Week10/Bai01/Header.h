#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>


using namespace std;
struct PS {
	int tu = 0;
	int mau = 0;
};
void InputFraction(PS &ps);
void OutputFraction(PS ps);
PS SumFraction(PS ps1, PS ps2);
PS MinusFraction(PS ps1, PS ps2);
PS MutipliYFraction(PS ps1, PS ps2);
PS DivideFraction(PS ps1, PS ps2);
int UCLN(int a, int b);
PS rutgon(PS ps);
int Sosanh_PS(PS a, PS b);
void Sort_Increasing(PS arr[],int n);
void InputFraction_Arr(PS arr[], int &n);
void OutputFraction_Arr(PS arr[], int n);
void thaiYThe_mangToigian(PS arr[], int n);
PS ArrSum_Fraction(PS arr[], int n);
int Tim_phanSo(PS arr[], int n, PS k);
#endif