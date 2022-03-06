#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(int matrix[][50], int& dong, int& cot);
void xuatMatran(int matrix[][50], int dong, int cot);
int tong_kxk(int matrix[][50], int i1, int j1, int k);
int tong(int matrix[][50], int dong, int cot, int k);
#endif // !_HEADER_
