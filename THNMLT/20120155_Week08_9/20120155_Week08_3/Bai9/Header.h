#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(int matrix[][50], int& dong, int& cot);
void xuatMatran(int matrix[][50], int dong, int cot);
void sapXep_cotTang(int matrix[][50], int dong, int cot, int k);
void sapXep_dongGiam(int matrix[][50], int dong, int cot, int k);
void sapXep_maTran(int matrix[][50], int dong, int cot);
#endif 
