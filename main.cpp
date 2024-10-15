#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <iostream>
#include <QDir>
#include <vector>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

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

    // Add Photo and Video objects to the list
    Photo* photo = new Photo("Photo", "../sample_photo.jpg", 37.7749, 122.4194);
    Video* video = new Video("Video", "../sample_video.mp4", 10);

    multimediaList.push_back(photo);
    multimediaList.push_back(video);

    // Create windows for Photo and Video
    QWidget* photoWindow = createPhotoWindow(*photo);
    VideoWindow* videoWindow = new VideoWindow(*video);

    // Add windows to the layout
    layout->addWidget(photoWindow);
    layout->addWidget(videoWindow);

    window.setLayout(layout);
    window.setGeometry(100, 100, 800, 600); // Set the size of the main window
    window.show();

    return app.exec();
}