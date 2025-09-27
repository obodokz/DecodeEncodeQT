#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_writeButton_clicked();

    void on_readButton_clicked();

    void on_encodeButton_clicked();

    void on_decodeButton_clicked();

private:

    QString vigenere(const QString &text, const QString &key, bool decrypt);

    QChar shiftChar(QChar ch, int shift);

    const QString RU_LOW = QStringLiteral("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    const QString RU_UP = QStringLiteral("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    const QString EN_LOW = QStringLiteral("abcdefghijklmnopqrstuvwxyz");
    const QString EN_UP = QStringLiteral("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
