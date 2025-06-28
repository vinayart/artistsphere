#include "ProfileWindow.h"
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QProcess>
#include <QApplication>  // ✅ REQUIRED for QApplication::quit

ProfileWindow::ProfileWindow(const QString &username, QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("User Profile");
    resize(300, 200);

    nameLabel = new QLabel("Name: ");
    emailLabel = new QLabel("Email: ");
    profileLabel = new QLabel("Profile: ");
    continueButton = new QPushButton("Continue");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(nameLabel);
    layout->addWidget(emailLabel);
    layout->addWidget(profileLabel);
    layout->addWidget(continueButton);
    setLayout(layout);

    loadProfile(username);

    connect(continueButton, &QPushButton::clicked, this, &ProfileWindow::handleContinue);
}

void ProfileWindow::loadProfile(const QString &username) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/webtech/login_register/build/users.db");

    if (!db.open()) {
        nameLabel->setText("❌ Failed to open database");
        emailLabel->setText("DB Error: " + db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT username, password, profile FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        QString name = query.value(0).toString();
        QString email = query.value(1).toString();
        currentProfile = query.value(2).toString();

        nameLabel->setText("Username: " + name);
        emailLabel->setText("Password: " + email);
        profileLabel->setText("Profile: " + currentProfile);
        continueButton->setText("Continue to (" + currentProfile + ") dashboard");
    } else {
        nameLabel->setText("User not found");
        emailLabel->setText("Query Error: " + query.lastError().text());
        profileLabel->setText("");
    }

    db.close();
}

void ProfileWindow::handleContinue() {
    qDebug() << "🚀 Launching profile:" << currentProfile;

    QString exePath;

    if (currentProfile == "artist") {
        exePath = "C:\\webtech\\artist\\build\\artist.exe";
    } else if (currentProfile == "customer") {
        exePath = "C:/webtech/customer/build/customer.exe";
    } else {
        QMessageBox::warning(this, "Error", "Unknown profile type: " + currentProfile);
        return;
    }

    if (!QFile::exists(exePath)) {
        QMessageBox::warning(this, "Executable Not Found", "Could not find: " + exePath);
        return;
    }

    QProcess::startDetached(exePath);
}
