#include "EditProductDialog.h"

EditProductDialog::EditProductDialog(const QString& currentName, double currentPrice, QWidget* parent)
    : ProductDialogBase("Edit Product", parent) {
    actionButton->setText("Update");

    // Set the initial values based on the current product details
    nameLineEdit->setText(currentName);
    priceSpinBox->setValue(currentPrice);
}

QString EditProductDialog::getNewName() const {
    return nameLineEdit->text();
}

double EditProductDialog::getNewPrice() const {
    return priceSpinBox->value();
}
