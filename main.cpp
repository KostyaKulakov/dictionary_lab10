#include "mainwindow.h"
#include "Dictionary.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *utfcodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utfcodec);

    QApplication a(argc, argv);

    Dictionary d("/home/konstantin/Загрузки/Dictionary.txt");
    d.write("/home/konstantin/Загрузки/Dictionary_new.txt");

    MainWindow w;
    w.show();

    return a.exec();
}
