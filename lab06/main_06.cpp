#include <iostream>
#include <fstream>

#include "QuizGame.h"
#include "QuizItem.h"

using namespace std;

//befejezni, lekezelni a dolgokat/hibakat, megirni jobban/helyesebben

//jovoheten kicsifelmero, 8-ik heten parcialis
int main() {
    //std::cout << "Hello, Lab_06" << std::endl;

    User u("'Bela");
    vector<Quiz> qs;
    vector<string>

    for (int i=0; i < ; ++i)
    {
    ifstream fin("quiz.txt");
    if (!fin.is_open()) {
        return 404;
    }

    vector<QuizItem> items;
    string question;
    vector<string> answers;
    int correctIndex;

    while (!fin.eof()) {
        string temp;
        getline(fin,temp);
        if (temp[0] == 'Q') {
            question = temp.substr(2);
        }
        else if (temp[0] == 'A') {
            answers.push_back(temp.substr(2));
        }
        else {
            correctIndex = stoi(temp);
            QuizItem *qi = new QuizItem(question,answers,correctIndex);
            items.push_back(*qi);
            answers.clear();
        }
    }
    User u("Bela");
    Quiz q1(items,"Quiz1");


    QuizGame game(&u,qs);
    game.runQuizzes();
    return 0;
}