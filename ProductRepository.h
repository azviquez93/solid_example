#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include <QtSql>
#include "IProductRepository.h"

class ProductRepository : public IProductRepository {
public:
    ProductRepository();
    void addProduct(const std::shared_ptr<IProduct>& product) override;
    void removeProduct(const QString& name) override;
    void updateProduct(const QString& oldName, const QString& newName, double newPrice) override;
    std::shared_ptr<IProduct> getProductByName(const QString& name) const override;
    std::vector<std::shared_ptr<IProduct>> getAllProducts() const override;
    std::vector<std::shared_ptr<IProduct>> findProductsByKeyword(const QString& keyword) const override;

private:
    QSqlDatabase db_;
    std::vector<std::shared_ptr<IProduct>> products_;
};

#endif // PRODUCTREPOSITORY_H
