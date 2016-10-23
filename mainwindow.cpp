#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->loadDict, &QAction::triggered, this, &MainWindow::loadDictionary);
    connect(this->ui->saveDict, &QAction::triggered, this, &MainWindow::saveDictionary);
    connect(this->ui->listWidget_Eng, &QListWidget::itemSelectionChanged, this, &MainWindow::setFocusDict);
    connect(this->ui->addWordButton, &QPushButton::clicked, this, &MainWindow::addWord);
    connect(this->ui->addWord, &QAction::triggered, this, &MainWindow::addWord);
    connect(this->ui->exit, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDictionary()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите словарь"));

    if(!fileName.isEmpty())
        this->dict.init(fileName);

    reloadDictLists();
}

void MainWindow::setFocusDict()
{
    for(int i = 0; i < ui->listWidget_Eng->count(); ++i)
        if(ui->listWidget_Eng->item(i)->isSelected())
            ui->listWidget_Rus->item(i)->setSelected(true);

}

void MainWindow::saveDictionary()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить словарь", "", ".txt");

    if(!fileName.isEmpty())
        this->dict.write(fileName + ".txt");
}

void MainWindow::reloadDictLists()
{
    QMap<QString, QString> d = dict.getDictonary();

    ui->listWidget_Eng->clear();
    ui->listWidget_Rus->clear();

    QMapIterator<QString, QString> i(d);
    while (i.hasNext())
    {
        i.next();
        ui->listWidget_Eng->addItem(i.key());
        ui->listWidget_Rus->addItem(i.value());
    }
}

void MainWindow::on_removeWordButton_clicked()
{
    for(int i = 0; i < ui->listWidget_Eng->count(); ++i)
        if(ui->listWidget_Eng->item(i)->isSelected())
            this->dict.deleteWord(ui->listWidget_Eng->item(i)->text());

    reloadDictLists();
}

void MainWindow::on_translateButton_clicked()
{
    QMessageBox* mb = new QMessageBox();

    mb->setWindowTitle("Перевод слова");

    QString word = ui->lineWordTranslate->text();

    if(word.isEmpty())
        mb->setText("Введите слово для перевода");
    else
    {
        if(this->dict.translate(word, WordLanguage::ENG).isEmpty() &&  this->dict.translate(word, WordLanguage::RUS).isEmpty())
            mb->setText("Слово: " + word + " не найдено в словаре!");
        else
            mb->setText("Слово: " + word + " переводится как: " + (this->dict.translate(word, WordLanguage::ENG).isEmpty() ? this->dict.translate(word, WordLanguage::RUS) : this->dict.translate(word, WordLanguage::ENG)));
    }
    mb->exec();
}

void MainWindow::addWord()
{
    this->addWordUi = new AddDialog();
    addWordUi->exec();

    if(!addWordUi->eng.isEmpty() && !addWordUi->rus.isEmpty())
        dict.addWord(addWordUi->eng, addWordUi->rus);

    reloadDictLists();

    delete this->addWordUi;
}
