/*
 * @Author: Nimrod
 * @Date: 2018-04-29 00:01:06
 */

#include <memory>
#include <set>
#include "15_15.h"

class Basket {
public:
    Basket() = default;
    Basket(Basket &&) = default;
    Basket(const Basket &) = default;
    Basket &operator=(Basket &&) = default;
    Basket &operator=(const Basket &) = default;

    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }

    ~Basket() = default;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->Isbn() > rhs->Isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};