#include "quizmanager.h"

QuizManager::QuizManager() {
    score = 0;
    questionNumber = 1;
    loadQuestions();
}

void QuizManager::loadQuestions()
{
    Question q1 = {"Binary Search complexity?",
                     {"O(n)", "O(log n)", "O(n log n)", "O(1)"},
                     'B'};

    Question q2 = {"FIFO belongs to?",
                   {"Stack", "Queue", "Tree", "Graph"},
                   'B'};

    Question q3 = {"Which DS uses LIFO?",
                   {"Queue", "Array", "Stack", "Tree"},
                   'C'};

    Question q4 = {"C++ supports?",
                   {"Procedural", "OOP", "Functional", "All"},
                   'D'};

    Question q5 = {"Which STL stores key-value?",
                   {"vector", "map", "list", "queue"},
                   'B'};

    // q6: Linked List
    Question q6 = {"Which linked list has no NULL at the end?",
                   {"Singly", "Doubly", "Circular", "Linear"},
                   'C'};

    // q7: Sorting Complexity
    Question q7 = {"Worst-case complexity of Bubble Sort?",
                   {"O(n log n)", "O(n)", "O(n^2)", "O(log n)"},
                   'C'};

    // q8: Heap Property
    Question q8 = {"Which DS is used to implement Priority Queue?",
                   {"Stack", "Queue", "Heap", "Tree"},
                   'C'};

    // q9: Graph Traversal
    Question q9 = {"Which algorithm uses a Stack for traversal?",
                   {"BFS", "DFS", "Binary Search", "Dijkstra"},
                   'B'};

    // q10: Tree Definition
    Question q10 = {"A tree with at most 2 children is called?",
                    {"Ternary Tree", "Binary Tree", "B-Tree", "AVL Tree"},
                    'B'};

    // q11: Memory Management
    Question q11 = {"Which operator is used to free memory in C++?",
                    {"free()", "delete", "remove", "clear"},
                    'B'};

    // q12: Array Indexing
    Question q12 = {"What is the index of the last element in array 'a' of size N?",
                    {"N", "N+1", "N-1", "0"},
                    'C'};

    // q13: Hashing
    Question q13 = {"Which technique resolves hash collisions?",
                    {"Chaining", "Searching", "Sorting", "Indexing"},
                    'A'};

    // q14: Recursion
    Question q14 = {"Which DS is used by the system during recursion?",
                    {"Queue", "Stack", "Map", "Linked List"},
                    'B'};

    // q15: OOP Basics
    Question q15 = {"Concept of deriving a class from another class?",
                    {"Encapsulation", "Polymorphism", "Inheritance", "Abstraction"},
                    'C'};

    // Inhein queue mein push karein
    quizQueue.push(q1);
    quizQueue.push(q2);
    quizQueue.push(q3);
    quizQueue.push(q4);
    quizQueue.push(q5);
    quizQueue.push(q6);
    quizQueue.push(q7);
    quizQueue.push(q8);
    quizQueue.push(q9);
    quizQueue.push(q10);
    quizQueue.push(q11);
    quizQueue.push(q12);
    quizQueue.push(q13);
    quizQueue.push(q14);
    quizQueue.push(q15);
}


Question QuizManager::getNextQuestion() {
    Question q = quizQueue.front();
    quizQueue.pop();
    questionNumber++;
    return q;
}

bool QuizManager::hasMoreQuestions() {
    return !quizQueue.empty();
}

bool QuizManager::checkAnswer(QChar userAnswer, QChar correctAnswer)
{
    if (userAnswer == correctAnswer) {
        score += 4;
        return true;
    } else {
        score -= 1;
        return false;
    }
}


int QuizManager::getScore() const {
    return score;
}
