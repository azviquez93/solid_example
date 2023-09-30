#ifndef PRODUCTLISTWIDGET_H
#define PRODUCTLISTWIDGET_H

#include <QListWidget>
#include <vector>
#include <memory>
#include "IProduct.h"

class ProductListWidget : public QListWidget {
public:
    ProductListWidget(QWidget* parent = nullptr);
    void displayProducts(const std::vector<std::shared_ptr<IProduct>>& products);
};

#endif // PRODUCTLISTWIDGET_H
