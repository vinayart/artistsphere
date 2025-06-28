
// ArtistWindow.cpp
#include "ArtistWindow.h"

ArtistWindow::ArtistWindow(const QString &username, QWidget *parent)
    : QWidget(parent), username(username) {

    trie = new Trie();
    model = new QStringListModel(this);
    completer = new QCompleter(model, this);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    connect(completer, QOverload<const QString &>::of(&QCompleter::activated),
            this, &ArtistWindow::handleSuggestionClicked);

    setWindowTitle("🎨 Artist Dashboard");
    resize(1000, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QLabel *welcome = new QLabel("👋 Welcome, " + username);
    welcome->setStyleSheet("font-size: 18px; font-weight: bold;");
    mainLayout->addWidget(welcome);

    tabWidget = new QTabWidget(this);
    mainLayout->addWidget(tabWidget);

    // Media Tab
    mediaTab = new QWidget();
    QVBoxLayout *mediaLayout = new QVBoxLayout(mediaTab);
    mediaSearchInput = new QLineEdit();
    mediaSearchInput->setPlaceholderText("🔍 Filter your media by title...");
    mediaLayout->addWidget(mediaSearchInput);

    mediaTable = new QTableWidget();
    mediaTable->setColumnCount(4);
    mediaTable->setHorizontalHeaderLabels({"Title", "Description", "File", "Preview"});
    mediaTable->horizontalHeader()->setStretchLastSection(true);
    mediaLayout->addWidget(mediaTable);

    QHBoxLayout *mediaButtons = new QHBoxLayout();
    QPushButton *addBtn = new QPushButton("➕ Add Media");
    QPushButton *updateBtn = new QPushButton("✏️ Update Media");
    QPushButton *deleteBtn = new QPushButton("🗑️ Delete Media");
    mediaButtons->addWidget(addBtn);
    mediaButtons->addWidget(updateBtn);
    mediaButtons->addWidget(deleteBtn);
    mediaLayout->addLayout(mediaButtons);

    tabWidget->addTab(mediaTab, "🎞️ Media Manager");

    connect(addBtn, &QPushButton::clicked, this, &ArtistWindow::addMedia);
    connect(updateBtn, &QPushButton::clicked, this, &ArtistWindow::updateMedia);
    connect(deleteBtn, &QPushButton::clicked, this, &ArtistWindow::deleteMedia);
    connect(mediaSearchInput, &QLineEdit::textChanged, this, [this](const QString &filter) {
        updateMediaTable(filter);
    });

    // Search Tab
    searchTab = new QWidget();
    QVBoxLayout *searchLayout = new QVBoxLayout(searchTab);
    searchInput = new QLineEdit();
    searchInput->setPlaceholderText("Search other artists...");
    searchInput->setCompleter(completer);
    QPushButton *searchBtn = new QPushButton("🔍 Search");
    QHBoxLayout *searchBarLayout = new QHBoxLayout();
    searchBarLayout->addWidget(searchInput);
    searchBarLayout->addWidget(searchBtn);
    searchLayout->addLayout(searchBarLayout);

    QTableWidget *artistMediaTable = new QTableWidget();
    artistMediaTable->setColumnCount(3);
    artistMediaTable->setHorizontalHeaderLabels({"Title", "Description", "File"});
    searchLayout->addWidget(artistMediaTable);

    connect(searchBtn, &QPushButton::clicked, this, [=]() {
        artistMediaTable->setRowCount(0);
        QSqlQuery query(QSqlDatabase::database("artist_connection"));
        query.prepare("SELECT title, description, filepath FROM media WHERE username LIKE ?");
        query.addBindValue("%" + searchInput->text().trimmed() + "%");
        query.exec();
        while (query.next()) {
            int row = artistMediaTable->rowCount();
            artistMediaTable->insertRow(row);
            for (int i = 0; i < 3; ++i)
                artistMediaTable->setItem(row, i, new QTableWidgetItem(query.value(i).toString()));
        }
    });

    tabWidget->addTab(searchTab, "🔎 Search Artists");

    // Reel Tab
    reelTab = new QWidget();
    QVBoxLayout *reelLayout = new QVBoxLayout(reelTab);
    QLabel *info = new QLabel("🎬 Click below to open the Reel editing system:");
    reelLayout->addWidget(info);
    reelButton = new QPushButton("🎝️ Open Reel Editor");
    reelLayout->addWidget(reelButton);
    connect(reelButton, &QPushButton::clicked, this, &ArtistWindow::openReelApp);
    tabWidget->addTab(reelTab, "🎬 Reel Editor");

    if (!QSqlDatabase::contains("artist_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "artist_connection");
        db.setDatabaseName("C:/webtech/login_register/build/users.db");
        if (!db.open()) {
            QMessageBox::critical(this, "DB Error", db.lastError().text());
            return;
        }
    }

    loadMedia();
    loadArtistsForSearch();
}

ArtistWindow::~ArtistWindow() {
    delete trie;
}

void ArtistWindow::openReelApp() {
    QString path = "C:/webtech/reel/build/reel_feed.exe";
    if (!QFileInfo::exists(path)) {
        QMessageBox::warning(this, "Missing File", "reel.exe not found at: " + path);
        return;
    }
    QProcess::startDetached(path);
}

void ArtistWindow::loadMedia() {
    updateMediaTable();
}

void ArtistWindow::updateMediaTable(const QString &filter) {
    mediaTable->setRowCount(0);
    QSqlQuery query(QSqlDatabase::database("artist_connection"));
    QString sql = "SELECT title, description, filepath FROM media WHERE username = ?";
    if (!filter.isEmpty()) {
        sql += " AND title LIKE ?";
    }
    query.prepare(sql);
    query.addBindValue(username);
    if (!filter.isEmpty()) {
        query.addBindValue("%" + filter + "%");
    }

    if (query.exec()) {
        while (query.next()) {
            int row = mediaTable->rowCount();
            mediaTable->insertRow(row);
            for (int i = 0; i < 3; ++i)
                mediaTable->setItem(row, i, new QTableWidgetItem(query.value(i).toString()));
            mediaTable->setItem(row, 3, new QTableWidgetItem("Preview N/A"));
        }
    }
}

void ArtistWindow::addMedia() {
    QString title = QInputDialog::getText(this, "Add Media", "Title:");
    QString description = QInputDialog::getText(this, "Add Media", "Description:");
    QString filePath = QFileDialog::getOpenFileName(this, "Select Media File");

    if (title.isEmpty() || filePath.isEmpty()) return;

    QSqlQuery query(QSqlDatabase::database("artist_connection"));
    query.prepare("INSERT INTO media (username, title, description, filepath) VALUES (?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(title);
    query.addBindValue(description);
    query.addBindValue(filePath);
    query.exec();
    loadMedia();
}

void ArtistWindow::updateMedia() {
    int row = mediaTable->currentRow();
    if (row < 0 || !mediaTable->item(row, 0)) return;

    QString title = mediaTable->item(row, 0)->text();
    QString newTitle = QInputDialog::getText(this, "Update Media", "New Title:", QLineEdit::Normal, title);
    if (newTitle.isEmpty()) return;

    QSqlQuery query(QSqlDatabase::database("artist_connection"));
    query.prepare("UPDATE media SET title = ? WHERE username = ? AND title = ?");
    query.addBindValue(newTitle);
    query.addBindValue(username);
    query.addBindValue(title);
    query.exec();
    loadMedia();
}

void ArtistWindow::deleteMedia() {
    int row = mediaTable->currentRow();
    if (row < 0 || !mediaTable->item(row, 0)) return;

    QString title = mediaTable->item(row, 0)->text();
    QSqlQuery query(QSqlDatabase::database("artist_connection"));
    query.prepare("DELETE FROM media WHERE username = ? AND title = ?");
    query.addBindValue(username);
    query.addBindValue(title);
    query.exec();
    loadMedia();
}

void ArtistWindow::loadArtistsForSearch() {
    QSqlQuery query("SELECT DISTINCT username FROM users", QSqlDatabase::database("artist_connection"));
    QStringList artistList;
    trie->clear();
    while (query.next()) {
        QString artistName = query.value(0).toString();
        trie->insert(artistName);
        artistList << artistName;
    }
    model->setStringList(artistList);
}

void ArtistWindow::updateSuggestions(const QString &text) {
    if (text.isEmpty()) {
        model->setStringList({});
        return;
    }
    std::vector<QString> suggestions = trie->searchPrefix(text);
    QStringList qList;
    for (const QString &s : suggestions)
        qList << s;
    model->setStringList(qList);
}

void ArtistWindow::handleSuggestionClicked(const QString &artistName) {
    QString exePath = "C:/webtech/artist/build/artist.exe";
    if (!QFileInfo::exists(exePath)) {
        QMessageBox::critical(this, "Error", "artist.exe not found at: " + exePath);
        return;
    }
    QProcess::startDetached(exePath, QStringList() << artistName);
}

void ArtistWindow::searchArtists() {
    // handled inside constructor lambda
}