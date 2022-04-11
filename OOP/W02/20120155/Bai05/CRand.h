#pragma once
#include<iostream>
#include<time.h>
using namespace std;

class CRand
{
public:
	CRand();
public:
	int next();
	int next(int);
	int next(int, int);
};

