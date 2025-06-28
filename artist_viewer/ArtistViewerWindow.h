#ifndef ARTISTVIEWERWINDOW_H
#define ARTISTVIEWERWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QString>
#include <QVBoxLayout>

class ArtistViewerWindow : public QWidget {
    Q_OBJECT

public:
    explicit ArtistViewerWindow(const QString &artistUsername, QWidget *parent = nullptr);

private:
    QString artistUsername;
    QTableWidget *mediaTable;

    void loadArtworks();
};

#endif // ARTISTVIEWERWINDOW_H
