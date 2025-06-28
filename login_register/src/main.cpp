#include <QApplication>
#include "LoginSignupWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    DatabaseManager::instance();  // Initialize DB

    LoginSignupWindow window;
    window.show();

    return app.exec();
}
