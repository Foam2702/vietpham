#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;
void nhapMatran(int matrix[][50], int& dong, int& cot);
void xuatMatran(int matrix[][50], int dong, int cot);
void CongMaTran(int matrix1[][50], int matrix2[][50], int dong1, int cot1, int dong2, int cot2);
void TichMaTran(int matrix1[][50], int matrix2[][50], int dong1, int cot1, int dong2, int cot2);
#endif 
