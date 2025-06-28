#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "ProfileWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString username;

    QFile file("C:/webtech/session.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            username = obj["username"].toString();
            qDebug() << "✅ Loaded session username:" << username;
        }
    }

    if (username.isEmpty()) {
        qWarning("❌ Username not found in session.json");
        return 1;
    }

    ProfileWindow window(username);
    window.setWindowTitle("User Profile");
    window.show();

    return app.exec();
}
