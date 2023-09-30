#include "ProductListWidget.h"

ProductListWidget::ProductListWidget(QWidget* parent)
    : QListWidget(parent) {
}

void ProductListWidget::displayProducts(const std::vector<std::shared_ptr<IProduct>>& products) {
    clear();
    for (const auto& product : products) {
        addItem(product->name());
    }
}
