#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "question.h"
#include <queue>
#include <stack>
#include <unordered_map>

class QuizManager {
public:
    QuizManager();

    void loadQuestions();
    Question getNextQuestion();
    bool hasMoreQuestions();
    bool checkAnswer(QChar userAnswer, QChar correctAnswer);

    int getScore() const;

private:
    std::queue<Question> quizQueue;
    std::stack<int> scoreStack;
    std::unordered_map<int, QChar> answerKey;

    int score;
    int questionNumber;
};

#endif
