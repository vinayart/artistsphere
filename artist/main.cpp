#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "ArtistWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString username;

    QFile file("C:/webtech/session.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        username = obj["username"].toString();
        file.close();
    }

    if (username.isEmpty()) {
        qDebug() << "❌ No session found. Please login first.";
        return 1;
    }

    ArtistWindow window(username);
    window.show();

    return app.exec();
}
