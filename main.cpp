#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <iostream>
#include <QDir>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaManager.h"

class FilmWindow : public QWidget {
public:
    FilmWindow(const std::shared_ptr<Film>& film, QWidget* parent = nullptr)
        : QWidget(parent), film(film) {
        setWindowTitle("Sample Film");

        QVBoxLayout* filmLayout = new QVBoxLayout;

        videoWidget = new QVideoWidget;
        mediaPlayer = new QMediaPlayer;

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setSource(QUrl::fromLocalFile(QString::fromStdString(film->getFilePath())));

        filmLayout->addWidget(videoWidget);

        QPushButton* playButton = new QPushButton("Play Film");
        filmLayout->addWidget(playButton);

        connect(playButton, &QPushButton::clicked, [this]() {
            mediaPlayer->play();
        });

        setLayout(filmLayout);
    }

private:
    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
    std::shared_ptr<Film> film;
};

class VideoWindow : public QWidget {
public:
    VideoWindow(const std::shared_ptr<Video>& video, QWidget* parent = nullptr)
        : QWidget(parent), video(video) {
        setWindowTitle("Sample Video");

        QVBoxLayout* videoLayout = new QVBoxLayout;

        videoWidget = new QVideoWidget;
        mediaPlayer = new QMediaPlayer;

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setSource(QUrl::fromLocalFile(QString::fromStdString(video->getFilePath())));

        videoLayout->addWidget(videoWidget);

        QPushButton* playButton = new QPushButton("Play Video");
        videoLayout->addWidget(playButton);

        connect(playButton, &QPushButton::clicked, [this]() {
            mediaPlayer->play();
        });

        setLayout(videoLayout);
    }

private:
    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
    std::shared_ptr<Video> video;
};

QWidget* createPhotoWindow(const Photo& photo) {
    QWidget* photoWindow = new QWidget;
    photoWindow->setWindowTitle("Sample Photo");

    QVBoxLayout* photoLayout = new QVBoxLayout;
    QLabel* photoLabel = new QLabel;
    photoLabel->setPixmap(QPixmap::fromImage(QImage(photo.getFilePath().c_str())));
    photoLayout->addWidget(photoLabel);

    photoWindow->setLayout(photoLayout);
    return photoWindow;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Multimedia Player");

    QVBoxLayout* layout = new QVBoxLayout;

    MultimediaManager manager;

    // Create multimedia objects and groups
    auto photo = manager.createPhoto("Photo", "../sample_photo.jpg", 37.7749, 122.4194);
    auto video = manager.createVideo("Video", "../sample_video.mp4", 10);
    std::vector<int> chapters = {10, 20, 30};
    auto film = manager.createFilm("Film", "../sample_film.mp4", 60, chapters);

    auto photoGroup = manager.createGroup("Photo Group");
    photoGroup->push_back(photo);

    auto videoGroup = manager.createGroup("Video Group");
    videoGroup->push_back(video);

    auto mixedGroup = manager.createGroup("Mixed Group");
    mixedGroup->push_back(photo);
    mixedGroup->push_back(video);
    mixedGroup->push_back(film);

    // Display groups
    manager.displayGroup("Photo Group");
    manager.displayGroup("Video Group");
    manager.displayGroup("Mixed Group");

    // Create buttons
    QPushButton* photoButton = new QPushButton("Show Photo Coordinates");
    QPushButton* videoButton = new QPushButton("Show Video Duration");
    QPushButton* filmButton = new QPushButton("Show Film Chapters Durations");

    // Connect buttons to slots
    QObject::connect(photoButton, &QPushButton::clicked, [photo]() {
        std::cout << "Photo Coordinates: (" << photo->getLatitude() << ", " << photo->getLongitude() << ")" << std::endl;
    });

    QObject::connect(videoButton, &QPushButton::clicked, [video]() {
        std::cout << "Video Duration: " << video->getDuration() << " seconds" << std::endl;
    });

    QObject::connect(filmButton, &QPushButton::clicked, [film]() {
        std::cout << "Film Duration: " << film->getDuration() << " seconds" << std::endl;
        std::cout << "Chapters Durations: ";
        const std::vector<int>& chapters = film->getChapters();
        for (int chapter : chapters) {
            std::cout << chapter << " ";
        }
        std::cout << std::endl;
    });

    // Add buttons to the layout
    layout->addWidget(photoButton);
    layout->addWidget(videoButton);
    layout->addWidget(filmButton);

    window.setLayout(layout);
    window.setGeometry(100, 100, 800, 600); // Set the size of the main window
    window.show();

    return app.exec();
}