#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(int matrix[][50], int& dong, int& cot);
void xuatMatran(int matrix[][50], int dong, int cot);
void swapDong(int matrix[][50], int dong, int cot, int m, int n);
int Tongdong(int matrix[][50], int dong, int cot, int k);
void SapXepDongMaTran(int matrix[][50], int dong, int cot);
#endif 
