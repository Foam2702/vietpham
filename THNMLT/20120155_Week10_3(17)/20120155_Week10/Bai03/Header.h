#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

struct HocSinh {
	char hoten[30];
	float diem;
};
typedef HocSinh hs;

struct Ten {
	char ten[30];
};

void Input(hs a[], int& n);
void Output(hs a[], int n);
void Output1(hs a[], int n);
void strcpy(char A[], char B[]);
void Tach(char hoten[], char ten[]);
int strcmp(char a[], char b[]);
void Sapxep(hs a[], int n);
void locTen(hs a[], int n);
void FindMax(hs a[], int n);
#endif


