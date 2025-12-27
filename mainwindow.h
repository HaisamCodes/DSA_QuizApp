#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quizmanager.h"
#include <QTimer>



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

private:
    Ui::MainWindow *ui;

    QuizManager quiz;
    Question currentQuestion;

    QTimer *timer;
    int timeLeft;

private slots:
    void on_nextButton_clicked();
     void updateTimer();

private:
    void resetRadioButtons();

};
#endif // MAINWINDOW_H
