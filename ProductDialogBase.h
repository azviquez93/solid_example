#ifndef PRODUCTDIALOGBASE_H
#define PRODUCTDIALOGBASE_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

class ProductDialogBase : public QDialog {
    Q_OBJECT

public:
    ProductDialogBase(const QString& windowTitle, QWidget* parent = nullptr);

    QString getName() const;
    double getPrice() const;

protected:
    QLineEdit* nameLineEdit;
    QDoubleSpinBox* priceSpinBox;
    QPushButton* actionButton;

    static constexpr double minValue = 0.0;
    static constexpr double maxValue = 9999999.0;
};

#endif // PRODUCTDIALOGBASE_H
