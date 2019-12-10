// Copyright [2019] <Copyright zhengxin>
#include <vector>
#include <iostream>
#include "Foo.h"

int main() {
    Foo().sorted(); // call "&&"
    Foo f;
    f.sorted(); // call "const &"
}
