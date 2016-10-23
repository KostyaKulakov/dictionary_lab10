#pragma once
#include <QString>
#include <QFile>
#include <QMap>
#include <QTextStream>

#include <QMessageBox> // for debug

enum WordLanguage{ENG, RUS};

class Dictionary
{
public:
    Dictionary();
    Dictionary(QString filename);
    Dictionary(QFile& fin);
	
    QMap<QString, QString> getDictonary();

    void init(QFile& fin);
    void init(QString filename);

    void write(QFile& fout);
    void write(QString filename);

    QString translate(QString word, WordLanguage lang);

    void addWord(QString eng, QString rus);
    void deleteWord(QString key);
	
private:
    QMap<QString, QString> dict;
};

