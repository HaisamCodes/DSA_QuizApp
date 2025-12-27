#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timeLeft = 10;

    ui->timeBar->setValue(10);
    ui->timerLabel->setText("Time: 10s");

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000); // 1 second

}

MainWindow::~MainWindow()
{
    currentQuestion = quiz.getNextQuestion();

    ui->questionLabel->setText(currentQuestion.statement);
    ui->radioA->setText(currentQuestion.options[0]);
    ui->radioB->setText(currentQuestion.options[1]);
    ui->radioC->setText(currentQuestion.options[2]);
    ui->radioD->setText(currentQuestion.options[3]);

    ui->scoreLabel->setText("Score: 0");

}
void MainWindow::on_nextButton_clicked()
{
    QChar userAnswer;

    if (ui->radioA->isChecked()) userAnswer = 'A';
    else if (ui->radioB->isChecked()) userAnswer = 'B';
    else if (ui->radioC->isChecked()) userAnswer = 'C';
    else if (ui->radioD->isChecked()) userAnswer = 'D';
    else {
        QMessageBox::warning(this, "Warning", "Please select an option!");
        return;
    }

    bool correct = quiz.checkAnswer(userAnswer, currentQuestion.correct);

    if (correct)
        QMessageBox::information(this, "Result", "✔ Correct Answer!");
    else
        QMessageBox::information(this, "Result",
                                 "✘ Wrong Answer!\nCorrect: " + QString(currentQuestion.correct));

    ui->scoreLabel->setText("Score: " + QString::number(quiz.getScore()));

    // ✅ RESET USING CORRECT METHOD
    resetRadioButtons();

    if (quiz.hasMoreQuestions()) {

        currentQuestion = quiz.getNextQuestion();

        ui->questionLabel->setText(currentQuestion.statement);
        ui->radioA->setText(currentQuestion.options[0]);
        ui->radioB->setText(currentQuestion.options[1]);
        ui->radioC->setText(currentQuestion.options[2]);
        ui->radioD->setText(currentQuestion.options[3]);
    }
    else {
        ui->questionLabel->setText("🎉 Quiz Completed!");
        ui->nextButton->setEnabled(false);

        QMessageBox::information(this, "Final Score",
                                 "Your Final Score: " + QString::number(quiz.getScore()));
    }
}


void MainWindow::updateTimer()
{
    timeLeft--;

    ui->timeBar->setValue(timeLeft);
    ui->timerLabel->setText("Time: " + QString::number(timeLeft) + "s");

    if (timeLeft == 0) {
        timer->stop();
        QMessageBox::information(this, "Time Up", "Time is over!");

        quiz.checkAnswer('X', currentQuestion.correct);
        ui->scoreLabel->setText("Score: " + QString::number(quiz.getScore()));

        on_nextButton_clicked();
        timeLeft = 10;
        ui->timeBar->setValue(10);
        ui->timerLabel->setText("Time: 10s");
        timer->start(1000);
        resetRadioButtons();


    }

}
void MainWindow::resetRadioButtons()
{
    ui->radioA->setAutoExclusive(false);
    ui->radioB->setAutoExclusive(false);
    ui->radioC->setAutoExclusive(false);
    ui->radioD->setAutoExclusive(false);

    ui->radioA->setChecked(false);
    ui->radioB->setChecked(false);
    ui->radioC->setChecked(false);
    ui->radioD->setChecked(false);

    ui->radioA->setAutoExclusive(true);
    ui->radioB->setAutoExclusive(true);
    ui->radioC->setAutoExclusive(true);
    ui->radioD->setAutoExclusive(true);
}


