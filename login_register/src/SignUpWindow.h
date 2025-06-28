#pragma once
#include <QWidget>

class QLineEdit;
class QPushButton;
class QLabel;

class SignupWindow : public QWidget {
    Q_OBJECT

public:
    SignupWindow(QWidget *parent = nullptr);

private slots:
    void handleSignup();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *profileEdit;
    QLabel *statusLabel;
};
