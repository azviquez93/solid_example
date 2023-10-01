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

private:
    ProductListController& controller;
    ProductListWidget* listWidget;
    QPushButton* addButton;
};

#endif // PRODUCTLISTMAINWINDOW_H
