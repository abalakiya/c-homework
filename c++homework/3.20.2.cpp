// Copyright [2019] <Copyright Ö£öÎ>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	int a, sum, n = 0;
	while (std::cin >> a)
	{
		v.push_back(a);
		n++;
	}
	for (int i = 0; i < n / 2; i++)
	{
		sum = v[i] + v[n - i];
		std::cout << sum << " ";
	}
	return(0);
}
