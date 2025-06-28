#include "LoginWindow.h"
#include "DatabaseManager.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent) {
    usernameEdit = new QLineEdit();
    usernameEdit->setPlaceholderText("Username");
    passwordEdit = new QLineEdit();
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Login");
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);

    statusLabel = new QLabel();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(statusLabel);

    setLayout(layout);
}

#include <QFile>
#include <QTextStream>
#include <QProcess>

#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QJsonObject>
#include <QJsonDocument>

void LoginWindow::handleLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (DatabaseManager::instance().checkCredentials(username, password)) {
        statusLabel->setText("✅ Login successful!");

        // 🔍 Fetch full profile
        QMap<QString, QString> profile = DatabaseManager::instance().getUserProfile(username);

        // 📝 Save profile to session.json
        QJsonObject json;
        json["username"] = username;
        json["name"] = profile["profile"];  // assuming profile["profile"] contains full name

        QJsonDocument doc(json);

        QFile file("C:/webtech/session.json");
        if (file.open(QIODevice::WriteOnly)) {
            file.write(doc.toJson());
            file.close();
        }

        // 🚀 Launch ProfileApp
        bool started = QProcess::startDetached("C:/webtech/profile/build/ProfileApp.exe");
        if (!started) {
            statusLabel->setText("❌ Failed to start ProfileApp.exe");
        } else {
            close();
        }
    } else {
        statusLabel->setText("❌ Invalid credentials.");
    }
}


