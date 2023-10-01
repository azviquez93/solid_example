#include "ProductRepository.h"

#include "Product.h"

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
    query.bindValue(0, product->getName());
    query.bindValue(1, product->getPrice());

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
                               return product->getName() == name;
                           }),
            products_.end());
    } else {
        qDebug() << "Error al eliminar el producto de la base de datos.";
    }
}

void ProductRepository::updateProduct(const QString& oldName, const QString& newName, double newPrice) {
    QSqlQuery query;
    query.prepare("UPDATE products SET name = ?, price = ? WHERE name = ?");
    query.bindValue(0, newName);
    query.bindValue(1, newPrice);
    query.bindValue(2, oldName);

    if (query.exec()) {
        // Update the product in the products_ vector if needed
        for (auto& product : products_) {
            if (product->getName() == oldName) {
                product->setName(newName);
                product->setPrice(newPrice);
                break;
            }
        }
    } else {
        qDebug() << "Error updating the product in the database.";
    }
}


std::vector<std::shared_ptr<IProduct>> ProductRepository::getAllProducts() const {
    std::vector<std::shared_ptr<IProduct>> allProducts;

    QSqlQuery query("SELECT name, price FROM products");
    while (query.next()) {
        QString name = query.value(0).toString();
        double price = query.value(1).toDouble();
        allProducts.push_back(std::make_shared<Product>(name, price));
    }

    return allProducts;
}

std::vector<std::shared_ptr<IProduct>> ProductRepository::findProductsByKeyword(const QString& keyword) const {
    std::vector<std::shared_ptr<IProduct>> foundProducts;
    for (const auto& product : products_) {
        if (product->getName().contains(keyword, Qt::CaseInsensitive)) {
            foundProducts.push_back(product);
        }
    }
    return foundProducts;
}

std::shared_ptr<IProduct> ProductRepository::getProductByName(const QString& name) const {
    QSqlQuery query;
    query.prepare("SELECT name, price FROM products WHERE name = ?");
    query.bindValue(0, name);

    if (query.exec() && query.next()) {
        QString productName = query.value("name").toString();
        double productPrice = query.value("price").toDouble();

        // Create a new product with the retrieved data
        return std::make_shared<Product>(productName, productPrice);
    } else {
        qDebug() << "Error getting the product by name from the database.";
        return nullptr; // Return nullptr if the product is not found or an error occurs.
    }
}
