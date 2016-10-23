#include "Dictionary.h"

Dictionary::Dictionary()
{

}

Dictionary::Dictionary(QString filename)
{
    this->init(filename);
}

Dictionary::Dictionary(QFile &fin)
{
    this->init(fin);
}

QMap<QString, QString> Dictionary::getDictonary()
{
    return this->dict;
}

void Dictionary::init(QFile &fin)
{
    this->dict.clear();

    if(!fin.isOpen())
        return;

    while (!fin.atEnd())
    {
        QByteArray baline = fin.readLine();
        QString line = QString::fromUtf8(baline);

        QStringList words = line.split(' ');

        if(words.size() < 2)
            continue;

        QString eng, rus;
        eng = words.at(0);
        rus = words.at(1);

        if(rus.at(rus.length()-1) == '\n')
            rus.remove(rus.length()-1, 1); // clean of '\n'

        this->addWord(eng, rus);
    }
}

void Dictionary::init(QString filename)
{
    QFile fin(filename);
    fin.open(QIODevice::ReadOnly);

    this->init(fin);

    fin.close();
}

void Dictionary::write(QFile &fout)
{
    if(!fout.isOpen())
        return;

    QMapIterator<QString, QString> i(this->dict);

    while (i.hasNext())
    {
        i.next();
        QString line = QString(i.key()) + QString(' ') + QString(i.value()) + QString('\n');
        fout.write(line.toUtf8());
    }

    fout.close();
}

void Dictionary::write(QString filename)
{
    QFile fout(filename);
    fout.open(QIODevice::WriteOnly | QIODevice::Text);

    this->write(fout);

    fout.close();
}

QString Dictionary::translate(QString word, WordLanguage lang)
{
    return (lang == WordLanguage::ENG) ? this->dict.value(word) : this->dict.key(word);
}

void Dictionary::addWord(QString eng, QString rus)
{
    this->dict.insert(eng, rus);
}

void Dictionary::deleteWord(QString key)
{
    this->dict.remove(key);
}
