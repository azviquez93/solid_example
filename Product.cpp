#include "Product.h"

Product::Product(const QString& name, double price)
    : name_(name), price_(price) {}

QString Product::name() const {
    return name_;
}

double Product::price() const {
    return price_;
}
