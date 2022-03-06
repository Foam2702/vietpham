#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>

using namespace std;

void nhapMatran(float matrix[][50], int& dong, int& cot);
void xuatMatran(float matrix[][50], int dong, int cot);
bool check_Cucdai(float matrix[][50], int dong, int cot, int m, int n);
void tim_Cucdai(float matrix[][50], int dong, int cot);
#endif