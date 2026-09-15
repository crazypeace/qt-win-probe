#include <QApplication>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QSvgRenderer>
#include <QtConcurrent/QtConcurrentRun>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Qt 6.11.2 static link test");
    QNetworkAccessManager nam;
    QSvgRenderer svg;

    auto future = QtConcurrent::run([] { return 42; });
    if (future.get() != 42) {
        return 1;
    }
    return 0;
}
