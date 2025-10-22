//
// Created by cefgo on 22/10/2025.
//

#include "Quiz.h"

int Quiz::count = 0;
Quiz::Quiz(const vector<QuizItem> &quiz_items, const string &quiz_name){
    this->quizId = count;
    count++;
    this->items = items;
    this->quizName = quiz_name;
}

void Quiz::addQuizItem(QuizItem i) {
    if (this->isReady == false) {

    }
    else {

    }
}

void Quiz::finalize() {
    this->isReady = true;
}

int Quiz::get_quiz_id() const {
    return quizId;
}

string Quiz::get_quiz_name() const {
    return quizName;
}

vector<QuizItem> Quiz::get_items() const {
    return items;
}

bool Quiz::is_is_ready() const {
    return isReady;
}
