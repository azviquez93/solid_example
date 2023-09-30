#ifndef PRODUCTLISTWIDGET_H
#define PRODUCTLISTWIDGET_H

#include <QListWidget>
#include <QPushButton>  // Include for QPushButton
#include "ProductListView.h"

class ProductListWidget : public QListWidget, public ProductListView {
    Q_OBJECT
public:
    ProductListWidget();
    void displayProducts(const std::vector<std::shared_ptr<IProduct>>& products) override;
};

#endif // PRODUCTLISTWIDGET_H
