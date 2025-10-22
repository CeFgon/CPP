//
// Created by cefgo on 22/10/2025.
//

#ifndef QUIZGAME_H
#define QUIZGAME_H

#include <iostream>
#include "user.h"
#include "Quiz.h"

using namespace std;

class QuizGame {
    User* u;
    Quiz* q;
    vector<Quiz> qs;
public:
    QuizGame(User *u, vector<Quiz> q);
    void run(User *u, Quiz *q);
    void runQuizzes();
};

#endif //QUIZGAME_H
