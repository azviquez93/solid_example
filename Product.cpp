#include "Product.h"

Product::Product(const QString& name, double price)
    : name_(name), price_(price) {}

QString Product::getName() const {
    return name_;
}

void Product::setName(const QString& newName) {
    name_ = newName;
}

double Product::getPrice() const {
    return price_;
}

void Product::setPrice(double newPrice) {
    price_ = newPrice;
}
