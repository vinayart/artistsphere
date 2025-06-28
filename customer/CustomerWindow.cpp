#include "CustomerWindow.h"
#include<QProcess>
#include<QFile>

CustomerWindow::CustomerWindow(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Customer Dashboard - Explore Art");
    resize(1000, 700);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    titleLabel = new QLabel("Welcome to the Artist Gallery", this);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 10px;");

    searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("Search artists or artworks...");

    completer = new QCompleter(this);
    model = new QStringListModel(this);
    completer->setModel(model);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    searchBar->setCompleter(completer);

    searchButton = new QPushButton("Search", this);
    searchResults = new QListWidget(this);
    favoriteButton = new QPushButton("Add to Favorites", this);
    favoritesList = new QListWidget(this);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(searchButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(new QLabel("Search Results:"));
    mainLayout->addWidget(searchResults);
    mainLayout->addWidget(favoriteButton);
    mainLayout->addWidget(new QLabel("Favorites:"));
    mainLayout->addWidget(favoritesList);
    setLayout(mainLayout);

    connect(searchButton, &QPushButton::clicked, this, &CustomerWindow::performSearch);
    connect(favoriteButton, &QPushButton::clicked, this, &CustomerWindow::addToFavorites);
    connect(searchResults, &QListWidget::itemClicked, this, &CustomerWindow::viewArtwork);
    connect(searchBar, &QLineEdit::textChanged, this, &CustomerWindow::updateSuggestions);
    connect(completer, QOverload<const QString &>::of(&QCompleter::activated),
        this, &CustomerWindow::handleSuggestionClicked);


    loadArtistsFromDatabase(); // load on start
}

void CustomerWindow::loadArtistsFromDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/webtech/login_register/build/users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Could not open DB: " + db.lastError().text());
        return;
    }

    QSqlQuery query("SELECT username FROM users");
    QStringList artistList;
    while (query.next()) {
        QString name = query.value(0).toString();
        artistList << name;
        trie.insert(name);
    }

    db.close();
}

void CustomerWindow::updateSuggestions(const QString &text) {
    if (text.isEmpty()) {
        model->setStringList({});
        return;
    }

    std::vector<QString> suggestions = trie.searchPrefix(text);
   QStringList qList = QStringList::fromVector(QVector<QString>(suggestions.begin(), suggestions.end()));
    model->setStringList(qList);
}

void CustomerWindow::performSearch() {
    QString query = searchBar->text().trimmed();
    searchResults->clear();

    if (!query.isEmpty()) {
        std::vector<QString> results = trie.searchPrefix(query);
        for (const QString &artist : results) {
            searchResults->addItem("Artwork by " + artist);
        }
    } else {
        QMessageBox::information(this, "Input Required", "Please enter a keyword to search.");
    }
}

void CustomerWindow::addToFavorites() {
    QListWidgetItem *item = searchResults->currentItem();
    if (item) {
        favoritesList->addItem(item->text());
        QMessageBox::information(this, "Added", item->text() + " added to favorites.");
    } else {
        QMessageBox::warning(this, "No Selection", "Please select an item from search results to add.");
    }
}

void CustomerWindow::viewArtwork(QListWidgetItem *item) {
    if (item) {
        QString text = item->text();  // e.g., "Artwork by ravi"
        QString artistName = text.section("Artwork by ", 1);  // Extract the name

        if (!artistName.isEmpty()) {
            openArtistViewer(artistName);
        }
    }
}


void CustomerWindow::handleSuggestionClicked(const QString &artistName) {
    QString exePath = "C:\\webtech\\artist_viewer\\build\\artist.exe";  // ❗ UPDATE to your actual path

    if (!QFileInfo::exists(exePath)) {
        QMessageBox::critical(this, "Error", "artist.exe not found at: " + exePath);
        return;
    }

    // Launch the exe and pass artist name as argument
    QProcess::startDetached(exePath, QStringList() << artistName);
}
void CustomerWindow::openArtistViewer(const QString &artistName) {
    QString exePath = "C:\\webtech\\artist_viewer\\build\\artist.exe";  // 🔁 Update if different
    if (!QFile::exists(exePath)) {
        QMessageBox::warning(this, "Error", "Artist viewer executable not found.");
        return;
    }

    QProcess::startDetached(exePath, QStringList() << artistName);
}
