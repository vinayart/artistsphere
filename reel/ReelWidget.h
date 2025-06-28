#ifndef REELWIDGET_H
#define REELWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

class ReelWidget : public QWidget {
    Q_OBJECT

public:
    explicit ReelWidget(const QString &videoPath, QWidget *parent = nullptr);
    void play();

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QString path;
};

#endif // REELWIDGET_H
