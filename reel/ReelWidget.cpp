#include "ReelWidget.h"

ReelWidget::ReelWidget(const QString &videoPath, QWidget *parent)
    : QWidget(parent), path(videoPath) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    videoWidget = new QVideoWidget(this);
    layout->addWidget(videoWidget);

    player = new QMediaPlayer(this);
    player->setVideoOutput(videoWidget);
    player->setSource(QUrl::fromLocalFile(videoPath));

    // 🔁 Connect media status changed to loop handler
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &ReelWidget::handleMediaStatusChanged);

    player->play();
}

void ReelWidget::play() {
    if (player) {
        player->stop();
        player->setSource(QUrl::fromLocalFile(path));
        player->play();
    }
}

void ReelWidget::handleMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::EndOfMedia) {
        player->stop();
        player->setSource(QUrl::fromLocalFile(path));
        player->play(); // 🔁 Loop the video
    }
}
