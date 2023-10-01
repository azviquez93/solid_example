#include "ProductListController.h"

ProductListController::ProductListController(IProductRepository* repository, ProductListView* view)
    : repository_(repository), view_(view) {}

void ProductListController::initialize() {
    refreshList();
}

void ProductListController::refreshList() {
    view_->displayProducts(repository_->getAllProducts());
}

void ProductListController::addProduct(const std::shared_ptr<IProduct>& product) {
    repository_->addProduct(product);
}
