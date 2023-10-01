#include "ProductListMainWindow.h"
#include "AddProductDialog.h"
#include "Product.h"

ProductListMainWindow::ProductListMainWindow(ProductListController& ctrl, ProductListWidget* listWidget, QWidget* parent)
    : QMainWindow(parent), controller(ctrl), listWidget(listWidget) {

    // Create an "Add" button
    addButton = new QPushButton("Add Product", this);

    // Connect the "Add" button's clicked signal to a slot that handles adding a product
    connect(addButton, &QPushButton::clicked, this, &ProductListMainWindow::handleAddProduct);

    // Add the QListWidget and "Add" button to the main window's layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(listWidget);
    layout->addWidget(addButton);

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

        // Create a new product and add it to the repository
        std::shared_ptr<IProduct> product = std::make_shared<Product>(productName, productPrice);
        controller.addProduct(product);

        // Refresh the product list
        controller.refreshList();
    }
}
