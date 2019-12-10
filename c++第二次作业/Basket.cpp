// Copyright [2019] <Copyright zhengxin>
#include <iostream>
#include <memory>
#include <set>
#include "Quote.h"
#include "Basket.h"

using namespace std;

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;

    for (auto iter = items.cbegin(); iter != items.cend(); iter=items.upper_bound(*iter))
    {
        sum += print_total (os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return  sum;
}
