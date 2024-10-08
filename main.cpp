#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>
#include <QDir>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

QWidget* createPhotoWindow(const Photo& photo) {
    QWidget* photoWindow = new QWidget;
    photoWindow->setWindowTitle("Sample Photo");
    photoWindow->setGeometry(100, 100, 400, 200);

    QVBoxLayout* photoLayout = new QVBoxLayout;
    QLabel* photoLabel = new QLabel;
    photoLabel->setPixmap(QPixmap::fromImage(QImage(photo.getFilePath().c_str())));
    photoLayout->addWidget(photoLabel);

    photoWindow->setLayout(photoLayout);
    return photoWindow;
}

QWidget* createVideoWindow(const Video& video) {
    QWidget* videoWindow = new QWidget;
    videoWindow->setWindowTitle("Sample Video");
    videoWindow->setGeometry(100, 100, 400, 200);

    QVBoxLayout* videoLayout = new QVBoxLayout;
    QLabel* videoLabel = new QLabel;
    videoLabel->setText("Click the button to play the video");
    videoLayout->addWidget(videoLabel);

    QPushButton* videoButton = new QPushButton("Play Video");
    videoLayout->addWidget(videoButton);

    QObject::connect(videoButton, &QPushButton::clicked, [&video]() {
        video.play();
    });

    videoWindow->setLayout(videoLayout);
    return videoWindow;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Multimedia Player");
    window.setGeometry(100, 100, 400, 200);

    QVBoxLayout* layout = new QVBoxLayout;

    Photo photo("Photo", "../sample_photo.jpg", 37.7749, 122.4194);
    QWidget* photoWindow = createPhotoWindow(photo);
    layout->addWidget(photoWindow);

    Video video("Video", "../sample_video.mp4", 10);
    QWidget* videoWindow = createVideoWindow(video);
    layout->addWidget(videoWindow);

    window.setLayout(layout);
    window.show();

    return app.exec();
}