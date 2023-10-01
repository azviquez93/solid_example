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

void ProductListController::editProduct(const QString& oldName, const QString& newName, double newPrice) {
    // First, find the product with the old name in the repository
    std::shared_ptr<IProduct> productToEdit = repository_->getProductByName(oldName);

    if (!productToEdit) {
        // Handle the case where the product to edit is not found.
        return;
    }

    // Update the product's name and price
    productToEdit->setName(newName);
    productToEdit->setPrice(newPrice);

    // Now, update the product in the repository
    repository_->updateProduct(oldName, newName, newPrice);

    // Refresh the product list
    refreshList();
}
