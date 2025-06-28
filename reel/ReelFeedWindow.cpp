#include "ReelFeedWindow.h"
#include "ReelWidget.h"

#include <QDir>
#include <QFileInfoList>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

ReelFeedWindow::ReelFeedWindow(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    stackedWidget = new QStackedWidget(this);
    nextButton = new QPushButton("Next", this);
    prevButton = new QPushButton("Previous", this);

    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(prevButton);
    controlsLayout->addWidget(nextButton);

    mainLayout->addWidget(stackedWidget);
    mainLayout->addLayout(controlsLayout);
    setLayout(mainLayout);

    connect(nextButton, &QPushButton::clicked, this, &ReelFeedWindow::nextReel);
    connect(prevButton, &QPushButton::clicked, this, &ReelFeedWindow::prevReel);

    loadVideos();
}

void ReelFeedWindow::loadVideos() {
    QString assetsPath = QCoreApplication::applicationDirPath() + "/assets";
    QDir dir(assetsPath);
    QStringList filters = {"*.mp4", "*.avi", "*.mkv", "*.mov"};
    QFileInfoList files = dir.entryInfoList(filters, QDir::Files | QDir::Readable);

    for (const QFileInfo &fileInfo : files) {
        ReelWidget *reel = new ReelWidget(fileInfo.absoluteFilePath());
        stackedWidget->addWidget(reel);
    }

    if (stackedWidget->count() > 0) {
        stackedWidget->setCurrentIndex(0);
        ReelWidget *widget = qobject_cast<ReelWidget *>(stackedWidget->currentWidget());
        if (widget) widget->play();
    }
}

void ReelFeedWindow::nextReel() {
    int current = stackedWidget->currentIndex();
    if (current < stackedWidget->count() - 1) {
        stackedWidget->setCurrentIndex(current + 1);
        ReelWidget *widget = qobject_cast<ReelWidget *>(stackedWidget->currentWidget());
        if (widget) widget->play();
    }
}

void ReelFeedWindow::prevReel() {
    int current = stackedWidget->currentIndex();
    if (current > 0) {
        stackedWidget->setCurrentIndex(current - 1);
        ReelWidget *widget = qobject_cast<ReelWidget *>(stackedWidget->currentWidget());
        if (widget) widget->play();
    }
}

void ReelFeedWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_Right)
        nextReel();
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Left)
        prevReel();
}
