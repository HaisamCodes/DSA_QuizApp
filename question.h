#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

struct Question {
    QString statement;
    QString options[4];
    QChar correct;
};

#endif
