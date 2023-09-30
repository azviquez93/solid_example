#include "ProductListController.h"

ProductListController::ProductListController(IProductRepository* repository, ProductListView* view)
    : repository_(repository), view_(view) {}

void ProductListController::initialize() {
    refreshList();
}

void ProductListController::refreshList() {
    view_->displayProducts(repository_->getAllProducts());
}
