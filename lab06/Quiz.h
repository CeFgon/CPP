//
// Created by cefgo on 22/10/2025.
//

#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include "QuizItem.h"

class Quiz {
private:
    static int count;
    int quizId;
    string quizName;
    vector<QuizItem> items;
    bool isReady;

public:
    Quiz(const vector<QuizItem> &items,const string &quizName);
    void addQuizItem(QuizItem i);
    void finalize();

    int get_quiz_id() const;

    string get_quiz_name() const;

    vector<QuizItem> get_items() const;

    bool is_is_ready() const;
};

#endif //QUIZ_H
