#ifndef IPRODUCTREPOSITORY_H
#define IPRODUCTREPOSITORY_H

#include "IProduct.h"
class IProductRepository
{
public:
    virtual ~IProductRepository() = default;
    virtual void addProduct(const std::shared_ptr<IProduct>& product) = 0;
    virtual void removeProduct(const QString& name) = 0;
    virtual std::vector<std::shared_ptr<IProduct>> getAllProducts() const = 0;
    virtual std::vector<std::shared_ptr<IProduct>> findProductsByKeyword(const QString& keyword) const = 0;
};

#endif // IPRODUCTREPOSITORY_H
