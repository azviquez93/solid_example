#ifndef EDITPRODUCTDIALOG_H
#define EDITPRODUCTDIALOG_H

#include "ProductDialogBase.h"

class EditProductDialog : public ProductDialogBase {
    Q_OBJECT

public:
    EditProductDialog(const QString& currentName, double currentPrice, QWidget* parent = nullptr);
    QString getNewName() const;
    double getNewPrice() const;
};

#endif // EDITPRODUCTDIALOG_H
