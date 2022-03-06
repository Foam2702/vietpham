#pragma once
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
using namespace std;


int* CreateArr(int& n);
void InputArr(int* a, int n);
void OutputArr(int* a, int n);
bool SNT(int x);
void CountSNT(int* a, int n);

#endif