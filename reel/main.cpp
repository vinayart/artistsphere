#include <QApplication>
#include "ReelFeedWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ReelFeedWindow window;
    window.resize(720, 480);
    window.show();
    return app.exec();
}
