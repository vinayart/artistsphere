#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QCompleter>
#include <QStringListModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QProcess>
#include <QFile>


#include "Trie.h"

class CustomerWindow : public QWidget {
    Q_OBJECT

public:
    explicit CustomerWindow(QWidget *parent = nullptr);

private slots:
    void performSearch();
    void addToFavorites();
    void viewArtwork(QListWidgetItem *item);
    void updateSuggestions(const QString &text);
    void handleSuggestionClicked(const QString &artistName); 
    void openArtistViewer(const QString &artistName);


private:
    QLabel *titleLabel;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QListWidget *searchResults;
    QPushButton *favoriteButton;
    QListWidget *favoritesList;

    Trie trie;
    QCompleter *completer;
    QStringListModel *model;

    void loadArtistsFromDatabase();
};

#endif // CUSTOMERWINDOW_H
