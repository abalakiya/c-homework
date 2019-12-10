// Copyright [2019] <Copyright zhengxin>
#ifndef FOO_H
#define FOO_H

#include <vector>
#include <iostream>

class Foo {
public:
    Foo sorted()&&;
    Foo sorted() const&;
 
private:
    vector<int> data;
};

#endif

