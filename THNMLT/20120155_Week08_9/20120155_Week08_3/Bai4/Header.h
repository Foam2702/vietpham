#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(int matrix[][50], int& dong, int& cot);
void xuatMatran(int matrix[][50], int dong, int cot);
int Min(int matrix[][50], int dong, int cot);
int Max(int matrix[][50], int dong, int cot);
void diem_Yenngua(int matrix[][50], int dong, int cot);
#endif 
