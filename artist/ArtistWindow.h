// ArtistWindow.h
#ifndef ARTISTWINDOW_H
#define ARTISTWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QStringListModel>
#include <QCompleter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QHeaderView>
#include <QFileInfo>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QTimer>
#include "Trie.h"

class ArtistWindow : public QWidget {
    Q_OBJECT

public:
    explicit ArtistWindow(const QString &username, QWidget *parent = nullptr);
    ~ArtistWindow();

private slots:
    void addMedia();
    void updateMedia();
    void deleteMedia();
    void searchArtists();
    void updateSuggestions(const QString &text);
    void handleSuggestionClicked(const QString &artistName);
    void openReelApp();

private:
    QString username;

    QTabWidget *tabWidget;

    QWidget *mediaTab;
    QLineEdit *mediaSearchInput;
    QTableWidget *mediaTable;

    QWidget *searchTab;
    QLineEdit *searchInput;
    QCompleter *completer;
    QStringListModel *model;
    Trie *trie;

    QWidget *reelTab;
    QPushButton *reelButton;
    QVideoWidget *reelVideoWidget;
    QMediaPlayer *reelPlayer;

    void loadMedia();
    void loadArtistsForSearch();
    void updateMediaTable(const QString &artistFilter = QString());
};

#endif // ARTISTWINDOW_H