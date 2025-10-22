//
// Created by cefgo on 22/10/2025.
//

#include "QuizGame.h"

QuizGame::QuizGame(User *u, vector<Quiz> q) {
    this->u = u;
    this->qs = q;
}

void QuizGame::run(User *u, Quiz* q) {
    int nrCorrectAnswer = 0, totalAnswer = 0;
    vector<QuizItem> qi = this->q->get_items();
    for (QuizItem i : qi) {
        cout << i.get_question();
        int nr = 0;
        for (string a : i.get_answers()) {
            cout << nr << ". " << a << endl;
            nr++;
        }
        cout << "Add meg a valasz sorszamat:";
        int answer;
        cin >> answer;
        if (answer == i.get_correct_answer()) {
            nrCorrectAnswer++;
        }
        totalAnswer++;
    }
    cout << "Helyes valaszok szama: " << nrCorrectAnswer;
    double nrPoints = nrCorrectAnswer/totalAnswer;
    cout << "Pontszam: " << nrPoints;
    //kell meg valami
}

void QuizGame::runQuizzes() {
    for (auto i : qs) {
        run(u,&i);
    }
}
