#include "LoginSignupWindow.h"
#include "LoginWindow.h"
#include "SignupWindow.h"
#include <QTabWidget>
#include <QVBoxLayout>

LoginSignupWindow::LoginSignupWindow(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Login / Signup");

    QTabWidget *tabs = new QTabWidget(this);
    tabs->addTab(new LoginWindow(), "Login");
    tabs->addTab(new SignupWindow(), "Signup");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabs);

    setLayout(layout);
    setFixedSize(320, 200);
}
