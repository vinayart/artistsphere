#ifndef REELFEEDWINDOW_H
#define REELFEEDWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QKeyEvent>

class ReelFeedWindow : public QWidget {
    Q_OBJECT

public:
    explicit ReelFeedWindow(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void nextReel();
    void prevReel();

private:
    QStackedWidget *stackedWidget;
    QPushButton *nextButton;
    QPushButton *prevButton;

    void loadVideos();
};

#endif // REELFEEDWINDOW_H
