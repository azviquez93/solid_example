#include "ProductListWidget.h"

ProductListWidget::ProductListWidget() : QListWidget() {}

void ProductListWidget::displayProducts(const std::vector<std::shared_ptr<IProduct>>& products) {
    clear();
    for (const auto& product : products) {
        QString itemText = QString("%1 - $%2").arg(product->name()).arg(product->price());
        addItem(itemText);
    }
}
