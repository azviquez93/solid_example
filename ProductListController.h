#ifndef PRODUCTLISTCONTROLLER_H
#define PRODUCTLISTCONTROLLER_H

#include "IProductRepository.h"
#include "ProductListView.h"

class ProductListController {
public:
    ProductListController(IProductRepository* repository, ProductListView* view);
    void initialize();
    void refreshList();

private:
    IProductRepository* repository_;
    ProductListView* view_;
};

#endif // PRODUCTLISTCONTROLLER_H
