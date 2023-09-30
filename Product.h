#ifndef PRODUCT_H
#define PRODUCT_H

#include "IProduct.h"

class Product : public IProduct {
public:
    Product(const QString& name, double price);
    QString name() const override;
    double price() const override;

private:
    QString name_;
    double price_;
};

#endif // PRODUCT_H
