// Copyright [2019] <Copyright zhengxin>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
 
int main() {
	int a[10] = {0,1,2,3,5,3,5,6,9,8};
	vector<int> vec(a,a+10);
	cout<<"元素之和为："<<accumulate(vec.begin(),vec.end(),0);
	return 0;
}
