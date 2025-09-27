#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_writeButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}


void MainWindow::on_readButton_clicked()
{
    QString fileText;
    if(ui->textEdit->toPlainText().isEmpty())
    {
        QString fileName =QFileDialog::getOpenFileName(this, "Open File");
        if(fileName.isEmpty())
            return;

        QFile file(fileName);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        QString line = in.readLine();

        while(!line.isNull())
        {
            fileText.append(line + '\n');
            line = in.readLine();
        }

        file.close();
        ui->textEdit->clear();
        ui->textEdit->setPlainText(fileText);
    }
    else
    {
        // нет провеки изменения
        QString fileName =QFileDialog::getOpenFileName(this, "Open File");
        if(fileName.isEmpty())
            return;

        QFile file(fileName);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        QString line = in.readLine();

        while(!line.isNull())
        {
            fileText.append(line + '\n');
            line = in.readLine();
        }

        file.close();
        ui->textEdit->clear();
        ui->textEdit->setPlainText(fileText);
    }

}


void MainWindow::on_encodeButton_clicked()
{

}


void MainWindow::on_decodeButton_clicked()
{

}

QChar MainWindow::shiftChar(QChar ch, int shift)
{
    auto shiftInAlphabet = [shift](const QString &alphabet, QChar c)-> QChar
    {
        int len = alphabet.size();
        int idx = alphabet.indexOf(c);
        if(idx < 0) return c;
        int n = (idx + (shift % len)+len)%len;
        return alphabet.at(n);
    };

    if(RU_LOW.contains(ch))
        return shiftInAlphabet(RU_LOW, ch);
}

