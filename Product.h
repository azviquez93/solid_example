#ifndef PRODUCT_H
#define PRODUCT_H

#include "IProduct.h"

class Product : public IProduct {
public:
    Product(const QString& name, double price);

    // Implement the new getter and setter methods
    QString getName() const override;
    void setName(const QString& newName) override;
    double getPrice() const override;
    void setPrice(double newPrice) override;

private:
    QString name_;
    double price_;
};

#endif // PRODUCT_H
