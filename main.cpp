#include <QApplication>
#include "ProductListMainWindow.h"
#include "ProductListController.h"
#include "ProductRepository.h"
#include "ProductListWidget.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    ProductRepository* productRepository = new ProductRepository();
    ProductListWidget* listWidget = new ProductListWidget();
    ProductListController controller(productRepository, listWidget);
    ProductListMainWindow mainWindow(controller, listWidget);

    controller.initialize();

    mainWindow.show();

    return app.exec();
}
