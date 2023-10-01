#include "AddProductDialog.h"

AddProductDialog::AddProductDialog(QWidget* parent)
    : ProductDialogBase("Add Product", parent) {
    actionButton->setText("Add");
}
