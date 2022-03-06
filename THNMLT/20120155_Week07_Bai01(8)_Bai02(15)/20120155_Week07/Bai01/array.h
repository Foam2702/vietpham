#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void Input(int arr[], int& n);
void Output(int arr[], int n);
int FindMax(int arr[], int n);
int Tong_soKhongam(int arr[], int n);
int Tong_viTrichan(int arr[], int n);
bool check_Prime(int x);
int Count_Prime(int arr[], int n);
int Tim_phantuAmLonNhat(int arr[], int n);
int Tim_phantuKhongAmNhonhat(int arr[], int n);
bool Check_Increasing(int arr[], int n);
bool Check_soChinhphuong(int x);
int Tong_soChinhphuong(int arr[], int n);

#endif