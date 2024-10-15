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

class FilmWindow : public QWidget {
public:
    FilmWindow(const Film& film, QWidget* parent = nullptr) : QWidget(parent), film(film) {
        setWindowTitle("Sample Film");

        QVBoxLayout* filmLayout = new QVBoxLayout;

        videoWidget = new QVideoWidget;
        mediaPlayer = new QMediaPlayer;

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setSource(QUrl::fromLocalFile(QString::fromStdString(film.getFilePath())));

        filmLayout->addWidget(videoWidget);

        QPushButton* playButton = new QPushButton("Play Film");
        filmLayout->addWidget(playButton);

        connect(playButton, &QPushButton::clicked, [this, film]() {
            film.play();
        });

        setLayout(filmLayout);
    }

private:
    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
    Film film; // Store the Film object
};

class VideoWindow : public QWidget {
public:
    VideoWindow(const Video& video, QWidget* parent = nullptr) : QWidget(parent), video(video) {
        setWindowTitle("Sample Video");

        QVBoxLayout* videoLayout = new QVBoxLayout;

        videoWidget = new QVideoWidget;
        mediaPlayer = new QMediaPlayer;

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setSource(QUrl::fromLocalFile(QString::fromStdString(video.getFilePath())));

        videoLayout->addWidget(videoWidget);

        QPushButton* playButton = new QPushButton("Play Video");
        videoLayout->addWidget(playButton);

        connect(playButton, &QPushButton::clicked, [this, video]() {
            video.play();
        });

        setLayout(videoLayout);
    }

private:
    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
    Video video; // Store the Video object
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

    // Create a vector of pointers to Multimedia objects
    std::vector<Multimedia*> multimediaList;

    // Add Photo, Video, and Film objects to the list
    Photo* photo = new Photo("Photo", "../sample_photo.jpg", 37.7749, 122.4194);
    Video* video = new Video("Video", "../sample_video.mp4", 10);
    int chapters[] = {10, 20, 30};
    Film* film = new Film("Film", "../sample_film.mp4", 60, chapters, 3);

    multimediaList.push_back(photo);
    multimediaList.push_back(video);
    multimediaList.push_back(film);

    // Create groups
    Group photoGroup("Photo Group");
    photoGroup.push_back(photo);

    Group videoGroup("Video Group");
    videoGroup.push_back(video);

    Group mixedGroup("Mixed Group");
    mixedGroup.push_back(photo);
    mixedGroup.push_back(video);
    mixedGroup.push_back(film);

    // Display groups
    photoGroup.display(std::cout);
    videoGroup.display(std::cout);
    mixedGroup.display(std::cout);

    // Create windows for Photo, Video, and Film
    QWidget* photoWindow = createPhotoWindow(*photo);
    VideoWindow* videoWindow = new VideoWindow(*video);
    FilmWindow* filmWindow = new FilmWindow(*film);

    // Add windows to the layout
    layout->addWidget(photoWindow);
    layout->addWidget(videoWindow);
    layout->addWidget(filmWindow);

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
        const int* chapters = film->getChapters();
        for (int i = 0; i < film->getNumChapters(); ++i) {
            std::cout << chapters[i] << " ";
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