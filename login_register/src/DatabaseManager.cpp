#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if (!db.open()) {
        qDebug() << "❌ Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY, password TEXT,profile TEXT)");
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::addUser(const QString &username, const QString &password,const QString &profile) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password,profile) VALUES (:username, :password,:profile)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":profile",profile);
    return query.exec();
}

bool DatabaseManager::checkCredentials(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    return query.exec() && query.next();
}
// DatabaseManager.cpp
QMap<QString, QString> DatabaseManager::getUserProfile(const QString &username) {
    QMap<QString, QString> profile;
    QSqlQuery query;
    query.prepare("SELECT name, email, age FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        profile["name"] = query.value("name").toString();
        profile["email"] = query.value("email").toString();
        profile["age"] = query.value("age").toString();
    }
    return profile;
}

