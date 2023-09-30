#include "ProductRepository.h"

ProductRepository::ProductRepository() {
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("products.db");

    if (!db_.open()) {
        qDebug() << "Error al abrir la base de datos.";
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS products (name TEXT, price REAL)");
}

void ProductRepository::addProduct(const std::shared_ptr<IProduct>& product) {
    QSqlQuery query;
    query.prepare("INSERT INTO products (name, price) VALUES (?, ?)");
    query.bindValue(0, product->name());
    query.bindValue(1, product->price());

    if (query.exec()) {
        products_.push_back(product);
    } else {
        qDebug() << "Error al agregar el producto a la base de datos.";
    }
}

void ProductRepository::removeProduct(const QString& name) {
    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE name = ?");
    query.bindValue(0, name);

    if (query.exec()) {
        products_.erase(
            std::remove_if(products_.begin(), products_.end(),
                           [&name](const std::shared_ptr<IProduct>& product) {
                               return product->name() == name;
                           }),
            products_.end());
    } else {
        qDebug() << "Error al eliminar el producto de la base de datos.";
    }
}

std::vector<std::shared_ptr<IProduct>> ProductRepository::getAllProducts() const {
    return products_;
}

std::vector<std::shared_ptr<IProduct>> ProductRepository::findProductsByKeyword(const QString& keyword) const {
    std::vector<std::shared_ptr<IProduct>> foundProducts;
    for (const auto& product : products_) {
        if (product->name().contains(keyword, Qt::CaseInsensitive)) {
            foundProducts.push_back(product);
        }
    }
    return foundProducts;
}
