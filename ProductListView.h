#ifndef PRODUCTLISTVIEW_H
#define PRODUCTLISTVIEW_H

#include "IProduct.h"

class ProductListView {
public:
    virtual ~ProductListView() = default;
    virtual void displayProducts(const std::vector<std::shared_ptr<IProduct>>& products) = 0;
};

#endif // PRODUCTLISTVIEW_H
