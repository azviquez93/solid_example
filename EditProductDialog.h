// EditProductDialog.h
#ifndef EDITPRODUCTDIALOG_H
#define EDITPRODUCTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

class EditProductDialog : public QDialog {
    Q_OBJECT

public:
    EditProductDialog(const QString& currentName, double currentPrice, QWidget* parent = nullptr);

    QString getNewName() const;
    double getNewPrice() const;

private:
    QLineEdit* nameLineEdit;
    QDoubleSpinBox* priceSpinBox;
    QPushButton* updateButton;

    static constexpr double minValue = 0.0;
    static constexpr double maxValue = 9999999.0;
};

#endif // EDITPRODUCTDIALOG_H
