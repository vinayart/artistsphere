#include <QApplication>
#include "CustomerWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CustomerWindow window;
    window.setWindowTitle("Customer Dashboard");
    window.resize(1000, 700);
    window.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    window.show();

    return app.exec();
}
