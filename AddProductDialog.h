// AddProductDialog.h
#ifndef ADDPRODUCTDIALOG_H
#define ADDPRODUCTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

class AddProductDialog : public QDialog {
    Q_OBJECT

public:
    AddProductDialog(QWidget* parent = nullptr);

    QString getName() const;
    double getPrice() const;

private:
    QLineEdit* nameLineEdit;
    QDoubleSpinBox* priceSpinBox;
    QPushButton* addButton;
};

#endif // ADDPRODUCTDIALOG_H
