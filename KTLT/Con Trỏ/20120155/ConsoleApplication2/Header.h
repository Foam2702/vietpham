#pragma once
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
using namespace std;
int** CreateArr(int& n, int& m);
void InputArr(int** a, int n,int m);
void OutputArr(int** a, int n,int m);
void FreeArr(int** a, int n);
#endif