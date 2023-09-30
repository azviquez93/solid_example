#ifndef PRODUCT_H
#define PRODUCT_H
#include "IProduct.h"

class Product : public IProduct {
public:
    Product(const QString& name, double price)
        : name_(name), price_(price) {}

    QString name() const override { return name_; }
    double price() const override { return price_; }

private:
    QString name_;
    double price_;
};

#endif // PRODUCT_H
