#include "ProductListMainWindow.h"
#include "AddProductDialog.h"
#include "EditProductDialog.h"
#include "Product.h"
#include <QMessageBox>

ProductListMainWindow::ProductListMainWindow(ProductListController& ctrl, ProductListWidget* listWidget, QWidget* parent)
    : QMainWindow(parent), controller(ctrl), listWidget(listWidget) {

    setWindowTitle("Products list");

    // Create an "Add" button
    addButton = new QPushButton("Add Product", this);

    // Connect the "Add" button's clicked signal to a slot that handles adding a product
    connect(addButton, &QPushButton::clicked, this, &ProductListMainWindow::handleAddProduct);

    // Create an "Edit" button
    editButton = new QPushButton("Edit Product", this);

    // Connect the "Edit" button's clicked signal to a slot that handles editing a product
    connect(editButton, &QPushButton::clicked, this, &ProductListMainWindow::handleEditProduct);

    // Create a "Delete" button
    deleteButton = new QPushButton("Delete Product", this);

    // Connect the "Delete" button's clicked signal to a slot that handles product deletion
    connect(deleteButton, &QPushButton::clicked, this, &ProductListMainWindow::handleDeleteProduct);

    // Add the QListWidget, "Add" button, and "Edit" button to the main window's layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(listWidget);
    layout->addWidget(addButton);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);


    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}


void ProductListMainWindow::handleAddProduct() {
    // Create an instance of the AddProductDialog
    AddProductDialog dialog(this);

    // Show the dialog and wait for user input
    if (dialog.exec() == QDialog::Accepted) {
        // Get the product details from the dialog
        QString productName = dialog.getName();
        double productPrice = dialog.getPrice();

        // Perform input validation
        if (productName.isEmpty()) {
            QMessageBox::critical(this, "Validation Error", "Product name cannot be empty.");
            return; // Don't add the product if the name is empty.
        }

        if (productPrice < 0) {
            QMessageBox::critical(this, "Validation Error", "Product price must be non-negative.");
            return; // Don't add the product if the price is negative.
        }

        // Create a new product and add it to the repository
        std::shared_ptr<IProduct> product = std::make_shared<Product>(productName, productPrice);
        controller.addProduct(product);

        // Refresh the product list
        controller.refreshList();
    }
}

void ProductListMainWindow::handleEditProduct() {
    QListWidgetItem* selectedItem = listWidget->currentItem();
    if (!selectedItem || !selectedItem->isSelected()) {
        QMessageBox::information(this, "Edit Product", "Please select a product to edit.");
        return;
    }

    QString currentName = selectedItem->text().split(" - $")[0];
    double currentPrice = selectedItem->text().split(" - $")[1].toDouble();

    // Create an instance of the EditProductDialog
    EditProductDialog dialog(currentName, currentPrice, this);

    // Show the dialog and wait for user input
    if (dialog.exec() == QDialog::Accepted) {
        // Get the new product details from the dialog
        QString newName = dialog.getNewName();
        double newPrice = dialog.getNewPrice();

        // Perform input validation
        if (newName.isEmpty()) {
            QMessageBox::critical(this, "Validation Error", "Product name cannot be empty.");
            return; // Don't update the product if the name is empty.
        }

        if (newPrice < 0) {
            QMessageBox::critical(this, "Validation Error", "Product price must be non-negative.");
            return; // Don't update the product if the price is negative.
        }

        // Update the product in the repository (you need to implement this method in ProductRepository)
        controller.editProduct(currentName, newName, newPrice);

        // Refresh the product list
        controller.refreshList();
    }
}

void ProductListMainWindow::handleDeleteProduct() {
    QListWidgetItem* selectedItem = listWidget->currentItem();
    if (!selectedItem || !selectedItem->isSelected()) {
        QMessageBox::information(this, "Delete Product", "Please select a product to delete.");
        return;
    }

    QString productName = selectedItem->text().split(" - $")[0];

    // Ask the user for confirmation before deleting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Product", "Are you sure you want to delete the selected product?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Delete the product from the repository (you need to implement this method in ProductRepository)
        controller.deleteProduct(productName);

        // Refresh the product list
        controller.refreshList();
    }
}

