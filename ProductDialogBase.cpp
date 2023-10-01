#include "ProductDialogBase.h"
#include <QVBoxLayout>

ProductDialogBase::ProductDialogBase(const QString& windowTitle, QWidget* parent)
    : QDialog(parent) {
    setWindowTitle(windowTitle);

    nameLineEdit = new QLineEdit(this);
    priceSpinBox = new QDoubleSpinBox(this);
    priceSpinBox->setMinimum(minValue);
    priceSpinBox->setMaximum(maxValue);
    actionButton = new QPushButton(this);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(nameLineEdit);
    layout->addWidget(priceSpinBox);
    layout->addWidget(actionButton);

    connect(actionButton, &QPushButton::clicked, this, &ProductDialogBase::accept);

    setLayout(layout);
}

QString ProductDialogBase::getName() const {
    return nameLineEdit->text();
}

double ProductDialogBase::getPrice() const {
    return priceSpinBox->value();
}
