#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

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
    const QString key = ui->keyLineEdit->toPlainText();
    QString text = ui->textEdit->toPlainText();

    if(key.isEmpty())
    {
        QMessageBox::warning(this, "Ключ пуст", "В ключе нет символов");
        return;
    }

    const QString enc = vigenere(text, key, false);
    ui->textEdit->setPlainText(enc);
}


void MainWindow::on_decodeButton_clicked()
{
    const QString key = ui->keyLineEdit->toPlainText();
    QString text = ui->textEdit->toPlainText();

    if(key.isEmpty())
    {
        QMessageBox::warning(this, "Ключ пуст", "В ключе нет символов");
        return;
    }

    const QString enc = vigenere(text, key, true);
    ui->textEdit->setPlainText(enc);
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

    if(RU_UP.contains(ch))
        return shiftInAlphabet(RU_UP, ch);

    if(EN_LOW.contains(ch))
        return shiftInAlphabet(EN_LOW, ch);

    if(EN_UP.contains(ch))
        return shiftInAlphabet(EN_UP, ch);

    return ch;
}


QString MainWindow::vigenere(const QString &text, const QString &key, bool decrypt)
{
    QVector<int> keyRU, keyEN;

    for (QChar kc:key)
    {
        if(kc.isNull())
            continue;

        int idx = RU_LOW.indexOf(kc);
        if (idx >= 0)
        {
            keyRU.push_back(idx);
            continue;
        }
        idx = RU_UP.indexOf(kc);
        if (idx >= 0)
        {
            keyRU.push_back(idx);
            continue;
        }


        idx = EN_LOW.indexOf(kc);
        if (idx >= 0)
        {
            keyEN.push_back(idx);
            continue;
        }
        idx = EN_UP.indexOf(kc);
        if (idx >= 0)
        {
            keyEN.push_back(idx);
            continue;
        }
    }

    if(keyRU.isEmpty() && keyEN.empty())
    {
        QMessageBox::warning(this, "Ключ пуст", "В ключе нет символов");
    }

    QString out;
    out.reserve(text.size());

    int curRU{0};
    int curEN{0};

    for(QChar ch: text)
    {
        if (RU_LOW.contains(ch) || RU_UP.contains(ch))
        {
            if (keyRU.isEmpty())
            {
                out.append(ch);
                continue;
            }
            int shift = keyRU[curRU % keyRU.size()];

            if (decrypt)
                shift = -shift;

            out.append(shiftChar(ch, shift));
            curRU++;
        }

        else if (EN_LOW.contains(ch) || EN_UP.contains(ch))
        {
            if (keyEN.isEmpty())
            {
                out.append(ch);
                continue;
            }
            int shift = keyEN[curEN % keyEN.size()];

            if (decrypt)
                shift = -shift;

            out.append(shiftChar(ch, shift));
            curEN++;
        }
        else
        {
            out.append(ch);
        }
    }
    return out;
}
