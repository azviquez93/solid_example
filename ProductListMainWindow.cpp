#include "ProductListMainWindow.h"

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

}
