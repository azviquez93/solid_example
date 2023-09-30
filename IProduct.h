#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <QString>
class IProduct {
public:
    virtual ~IProduct() = default;
    virtual QString name() const = 0;
    virtual double price() const = 0;
};

#endif // IPRODUCT_H
