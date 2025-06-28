#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include "ArtistViewerWindow.h"

QString getUsernameFromSession() {
    QFile file("session.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return {};
    }

    QByteArray data = file.readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError || !doc.isObject()) {
        return {};
    }

    QJsonObject obj = doc.object();
    return obj.value("username").toString();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString username = getUsernameFromSession();
    if (username.isEmpty()) {
        QMessageBox::critical(nullptr, "Error", "No artist username found in session.json.");
        return 1;
    }

    ArtistViewerWindow viewer(username);
    viewer.show();

    return app.exec();
}
