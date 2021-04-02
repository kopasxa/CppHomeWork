#include "userStudent.h"

void userStudent::startTest( string testName, string login ) {
    clock_t t0 = clock();
    questionSt quest;
    vector<questionSt> questions;
    vector<answerStudent> answers;
    string nameTest, answer;
    int colvo;
    int allQuestions = 0;

    question.open( pathToQuestion );

    if ( question ) {
        while (!question.eof()) {
            question >> nameTest >> quest.id >> colvo >> quest.variantQ;
            getline( question, quest.header );
            getline( question, quest.header );

            for (int i = 0; i < colvo; i++) {
                question >> quest.str.answerStr >> quest.str.weight;
                quest.answers.push_back(quest.str);
            }
        
            if (nameTest == testName) {
                questions.push_back( quest );
                allQuestions++;
            }

            quest.answers.clear();
        }

        for (int i = 0; i < questions.size(); i++) {
            cout << endl;
            if (questions.at( i ).variantQ == 1) {
                cout << "Выберите правильный ответ (один правильный ответ)";
            }
            else if (questions.at( i ).variantQ == 2) {
                cout << "Выберите правильный ответ (несколько правильных, напишите через пробел)";
            }
            else if (questions.at( i ).variantQ == 3) {
                cout << "Напишите ваш вариант ответа";
            }

            cout << endl;
            cout << i + 1 << ". " << questions.at(i).header << endl;
            if (questions.at( i ).variantQ != 3) {
                cout << "Варианты ответа: " << endl;

                for (int j = 0; j < questions.at( i ).answers.size(); j++) {
                    cout << "\t" << j + 1 << ". " << questions.at( i ).answers.at( j ).answerStr << "\n";
                }
            }

            cout << "Ваш ответ: ";
            if (i == 0) {
                cin.ignore();
            }
            getline(cin, answer);
            
            answerStudent answ;

            answ.headerQ = questions.at( i ).header;

            if (answer.empty()) {
                answ.answer.push_back( "null" );
                answ.appraisal = 0;
            }
            else {
                if (questions.at( i ).variantQ == 1) {
                    for (int k = 0; k < questions.at( i ).answers.size(); k++) {
                        if (k + 1 == atoi(answer.c_str())) {
                            answ.appraisal = questions.at( i ).answers.at( k ).weight / 100;
                            answ.answer.push_back( questions.at( i ).answers.at( k ).answerStr );
                        }
                    }
                }
                else if (questions.at( i ).variantQ == 2) {
                    while (answer.size() > 0) {
                        int st = answer.find( " " );
                        if (st != answer.npos) { 
                            string newSt = answer.substr( st + 1 );
                            int thisAnsw = atoi( answer.erase( st ).c_str() );

                            for (int k = 0; k < questions.at( i ).answers.size(); k++) {
                                if (k + 1 == thisAnsw) {
                                    answ.appraisal += questions.at( i ).answers.at( k ).weight / 100;
                                    answ.answer.push_back( questions.at( i ).answers.at( k ).answerStr );
                                }
                            }
                            answer = newSt;
                        }
                        else {
                            int thisAnsw = atoi( answer.c_str() );

                            for (int k = 0; k < questions.at( i ).answers.size(); k++) {
                                if (k + 1 == thisAnsw) {
                                    answ.appraisal += questions.at( i ).answers.at( k ).weight / 100;
                                    answ.answer.push_back( questions.at( i ).answers.at( k ).answerStr );
                                }
                            }
                            
                            answer.clear();
                        }
                    }
                }
                else if (questions.at( i ).variantQ == 3) {
                    for (int k = 0; k < questions.at( i ).answers.size(); k++) {
                        if (questions.at( i ).answers.at( k ).answerStr == answer) {
                            answ.appraisal = 1;
                            answ.answer.push_back( questions.at( i ).answers.at( k ).answerStr );
                        }
                    }
                }
                answers.push_back( answ );
                answ.appraisal = 0;
            }
        }

        clock_t t1 = clock();
        cout << "\nВремя: " << ((double)(t1 - t0) / CLOCKS_PER_SEC)  << endl << "Оценка: ";
        float appraisal = 0;
        for (int k = 0; k < answers.size(); k++) {
            appraisal += answers.at( k ).appraisal;
        }
        cout << appraisal << " / " << allQuestions << endl;

        question.close();
    
        cout << "\nЧтобы посмотреть свои ответы нажмите Enter...\n";
        while (!_kbhit());
        int button = _getch();

        if (button == 13) {
            printResult( answers );
        }

        writeResults( answers, login, testName, appraisal );

        cout << "Чтобы продолжить нажмите любую клавишу...\n";
        while (!_kbhit());
    }
    else {
        cout << "Error 404: обратитесь к администратору\n";
    }
}

bool userStudent::writeResults( vector<answerStudent> answers, string login, string testName, float appraisal ) {
    result.open( pathToResults, ios::app );

    if ( result ) {
        result << "\n\n" << login << " " << testName << " " << appraisal << " " << answers.size();
        for (int i = 0; i < answers.size(); i++) {
            result << endl << answers.at( i ).headerQ << endl;
            
            for (int j = 0; j < answers.at( i ).answer.size(); j++) {
                result << answers.at( i ).answer.at( j );
                if (j != answers.at( i ).answer.size() - 1) {
                    result << " ";
                }
            }
        }

        result.close();
    }
    else {
        return false;
    }

    return true;
}

void userStudent::printResult( vector<answerStudent> answers ) {
    for (int k = 0; k < answers.size(); k++) {
        cout << k + 1 << ". " << answers.at( k ).headerQ << "\nYou answer: ";
        for (int i = 0; i < answers.at( k ).answer.size(); i++) {
            cout << answers.at( k ).answer.at( i );
            if (answers.at( k ).answer.size() - 1 != i) {
                cout << ", ";
            }
            else {
                cout << endl;
            }
        }
        cout << "Your appraisal: " << answers.at( k ).appraisal << endl << endl;
    }
}
