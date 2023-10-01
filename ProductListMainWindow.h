#ifndef PRODUCTLISTMAINWINDOW_H
#define PRODUCTLISTMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "ProductListWidget.h"
#include "ProductListController.h"

class ProductListMainWindow : public QMainWindow {
    Q_OBJECT
public:
    ProductListMainWindow(ProductListController& controller, ProductListWidget* listWidget, QWidget* parent = nullptr);

public slots:
    void handleAddProduct();
    void handleEditProduct();
    void handleDeleteProduct();

private:
    ProductListController& controller;
    ProductListWidget* listWidget;
    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* deleteButton;
};

#endif // PRODUCTLISTMAINWINDOW_H
