// AddProductDialog.cpp
#include "AddProductDialog.h"
#include <QVBoxLayout>

AddProductDialog::AddProductDialog(QWidget* parent)
    : QDialog(parent) {
    setWindowTitle("Add Product");

    nameLineEdit = new QLineEdit(this);
    priceSpinBox = new QDoubleSpinBox(this);
    priceSpinBox->setMinimum(minValue);
    priceSpinBox->setMaximum(maxValue);
    addButton = new QPushButton("Add", this);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(nameLineEdit);
    layout->addWidget(priceSpinBox);
    layout->addWidget(addButton);

    connect(addButton, &QPushButton::clicked, this, &AddProductDialog::accept);

    setLayout(layout);
}

QString AddProductDialog::getName() const {
    return nameLineEdit->text();
}

double AddProductDialog::getPrice() const {
    return priceSpinBox->value();
}
