#include "SignupWindow.h"
#include "DatabaseManager.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

SignupWindow::SignupWindow(QWidget *parent)
    : QWidget(parent) {
    usernameEdit = new QLineEdit();
    usernameEdit->setPlaceholderText("Choose a username");
    passwordEdit = new QLineEdit();
    passwordEdit->setPlaceholderText("Choose a password");
    passwordEdit->setEchoMode(QLineEdit::Password);
    profileEdit = new QLineEdit();
    profileEdit->setPlaceholderText("Choose your profile");

    QPushButton *signupButton = new QPushButton("Signup");
    connect(signupButton, &QPushButton::clicked, this, &SignupWindow::handleSignup);

    statusLabel = new QLabel();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(profileEdit);
    layout->addWidget(signupButton);
    layout->addWidget(statusLabel);
    

    setLayout(layout);
}

void SignupWindow::handleSignup() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QString profile = profileEdit->text();

    if (DatabaseManager::instance().addUser(username, password,profile)) {
        statusLabel->setText("✅ Signup successful!");
    } else {
        statusLabel->setText("⚠️ Username already exists.");
    }
}
