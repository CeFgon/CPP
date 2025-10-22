//
// Created by cefgo on 22/10/2025.
//

#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <vector>
#include <string>

using namespace std;
class QuizItem {
public:
    int get_id() const;

    string get_question() const;

    vector<string> get_answers() const;

    int get_correct_answer() const;

private:
    static int count;
    int id;
    string question;
    vector<string> answers;
    int correctAnswer;
public:
    QuizItem(const string question, const vector<string> answers,const int correctAnswer);
};

#endif //QUIZITEM_H
