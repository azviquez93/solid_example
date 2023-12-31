#ifndef PRODUCTLISTCONTROLLER_H
#define PRODUCTLISTCONTROLLER_H

#include "IProductRepository.h"
#include "ProductListView.h"

class ProductListController {
public:
    ProductListController(IProductRepository* repository, ProductListView* view);
    void initialize();
    void refreshList();
    void addProduct(const std::shared_ptr<IProduct>&);
    void editProduct(const QString& oldName, const QString& newName, double newPrice);
    void deleteProduct(const QString& productName);

private:
    IProductRepository* repository_;
    ProductListView* view_;
};

#endif // PRODUCTLISTCONTROLLER_H
