//
// Created by cefgo on 22/10/2025.
//

#include "QuizItem.h"

int QuizItem::count = 0;

QuizItem::QuizItem(const string question, const vector<string> answers, int correctAnswer) {
    this->id = count;
    count++;
    this->question = question;
    this->answers = answers;
    this->correctAnswer = correctAnswer;
}

int QuizItem::get_id() const {
    return id;
}

string QuizItem::get_question() const {
    return question;
}

vector<string> QuizItem::get_answers() const {
    return answers;
}

int QuizItem::get_correct_answer() const {
    return correctAnswer;
}

