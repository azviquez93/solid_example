#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <QString>
class IProduct {
public:
    virtual ~IProduct() = default;
    virtual QString getName() const = 0;
    virtual void setName(const QString& newName) = 0;
    virtual double getPrice() const = 0;
    virtual void setPrice(double newPrice) = 0;
};

#endif // IPRODUCT_H
