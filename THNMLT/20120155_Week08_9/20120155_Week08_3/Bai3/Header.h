#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(float matrix[][50], int& dong, int& cot);
void xuatMatran(float matrix[][50], int dong, int cot);
void sapXep(int arr[], int n);
void sapXep_Mangphu(float matrix[][50], int dong, int cot);
void sapXep_koMangphu(float matrix[][50], int dong, int cot);
#endif 