// EditProductDialog.cpp
#include "EditProductDialog.h"
#include <QVBoxLayout>

EditProductDialog::EditProductDialog(const QString& currentName, double currentPrice, QWidget* parent)
    : QDialog(parent) {
    setWindowTitle("Edit Product");

    nameLineEdit = new QLineEdit(this);
    priceSpinBox = new QDoubleSpinBox(this);
    priceSpinBox->setMinimum(minValue);
    priceSpinBox->setMaximum(maxValue);
    updateButton = new QPushButton("Update", this);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(nameLineEdit);
    layout->addWidget(priceSpinBox);
    layout->addWidget(updateButton);

    connect(updateButton, &QPushButton::clicked, this, &EditProductDialog::accept);

    // Set the initial values based on the current product details
    nameLineEdit->setText(currentName);
    priceSpinBox->setValue(currentPrice);

    setLayout(layout);
}

QString EditProductDialog::getNewName() const {
    return nameLineEdit->text();
}

double EditProductDialog::getNewPrice() const {
    return priceSpinBox->value();
}
