// Copyright [2019] <Copyright zhengxin>
#include <iostream>
#include <memory>
#include <set>
#include "Quote.h"

using namespace std;

class Basket
{
public:
    void add_item(const shared_ptr<Quote> &sales)
    {
        items.insert(sales);
    }
    double total_receipt (std::ostream&) const;     // ��ӡÿ������ܼۺ͹���������������ܼ�
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset���������ۣ�����compare��Ա����
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};
