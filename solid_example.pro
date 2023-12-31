QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddProductDialog.cpp \
    EditProductDialog.cpp \
    Product.cpp \
    ProductDialogBase.cpp \
    ProductListController.cpp \
    ProductListMainWindow.cpp \
    ProductListWidget.cpp \
    ProductRepository.cpp \
    main.cpp

HEADERS += \
    AddProductDialog.h \
    EditProductDialog.h \
    IProduct.h \
    IProductRepository.h \
    Product.h \
    ProductDialogBase.h \
    ProductListController.h \
    ProductListMainWindow.h \
    ProductListView.h \
    ProductListWidget.h \
    ProductRepository.h

FORMS +=

QT += sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
