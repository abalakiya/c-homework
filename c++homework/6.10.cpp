// Copyright [2019] <Copyright zhengxin>
#include <iostream>

int exchange(int *x, int *y) {
	int z;
	z = *x;
	*x = *y;
	*y = z;
	return 0;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	exchange(&a, &b);
	std::cout << " a=" << a << " b=" << b << std::endl;
	return 0;
}

