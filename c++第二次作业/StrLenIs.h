// Copyright [2019] <Copyright zhengxin>
#ifndef STRLENIS_H
#define STRLENIS_H

#include <string>
#include <iostream>
using namespace std;

class StrLenIs
{
public:
	StrLenIs(int len) : len(len) { }
	bool operator()(const string &str) { return str.length() == len; }
 
private:
	int len;
};

#endif
