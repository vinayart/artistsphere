#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

class ProfileWindow : public QWidget {
    Q_OBJECT

public:
    explicit ProfileWindow(const QString &username, QWidget *parent = nullptr);

private slots:
    void handleContinue();

private:
    void loadProfile(const QString &username);

    QLabel *nameLabel;
    QLabel *emailLabel;
    QLabel *profileLabel;
    QPushButton *continueButton;
    QString currentProfile;
};

#endif // PROFILEWINDOW_H
