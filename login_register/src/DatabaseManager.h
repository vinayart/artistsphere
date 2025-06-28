#pragma once
#include <QString>
#include <QSqlDatabase>

class DatabaseManager {
public:
    static DatabaseManager& instance();

    bool addUser(const QString &username, const QString &password,const QString &profile);
    bool checkCredentials(const QString &username, const QString &password);
    QMap<QString, QString> getUserProfile(const QString &username);


private:
    DatabaseManager();
    QSqlDatabase db;
};
