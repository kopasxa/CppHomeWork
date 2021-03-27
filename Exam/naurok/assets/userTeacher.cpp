#include "userTeacher.h"

void userTeacher::SetPos( int x, int y ) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
}

bool userTeacher::createTest() {
	system( "cls" );
	SetPos( 47, 0 );
	cout << "Создание теста\n";
	cout << "Введите название теста: ";
	string testName;
	getline(cin, testName);

	if (testFile) {
		string nameOfTest, status;
		bool is = false;

		testFile.open( pathToTests );

		while (testFile >> nameOfTest >> status) {
			if (nameOfTest == testName) {
				is = true;
			}
		}
		testFile.close();

		testFile.open( pathToTests, ios::app );

		if (!is) {
			testFile << testName << " stoped \n";
		}
		testFile.close();
	}

	//vector<question> questions;
	cout << "Добавить вопрос к тесту (нажмите A) \nУдалить вопрос с теста (нажмите D) \nЗапустить тест (нажмите S)\n";

	int quantityQuestion;
	quantityQuestion = quantityQ( testName );

	while (!_kbhit());
	int option = _getch();

	if (option == 97) {
		addQuestion( quantityQuestion++, testName );
	}
	else if (option == 100) {
		allQuestion( testName );
		cout << "Выберите какой вопрос удалить: ";
		int num;
		cin >> num;

		delQuestion( num, testName );
	}
	else if (option == 115) {

	}

	return true;
}

int userTeacher::quantityQ( string testName ) {
	int quantityQuestion = 0;

	testQuestion.open( pathToQuestion );

	long file_size;
	testQuestion.seekg( 0, ios::end );
	file_size = testQuestion.tellg();

	if ( testQuestion ) {
		if (!file_size == 0) {
			string nameTest, qName, answ;
			int id, qAnsw;
			float weight;
			testQuestion.seekg( 0, 0 );

			while (!testQuestion.eof()) {
				testQuestion >> nameTest >> id >> qAnsw;
				getline(testQuestion, qName);
				getline( testQuestion, qName );

				for (int i = 0; i < qAnsw; i++) {
					testQuestion >> answ >> weight;
				}

				if (nameTest == testName) {
					quantityQuestion++;
				}
			}

			testQuestion.close();
			return quantityQuestion;
		}
		else {
			return 0;
		}
	}
	else {
		cout << "Error to open file (\n";
		return quantityQuestion;
	}
}

question userTeacher::addQuestion(int id, string nameTest) {
	question quest;

	cout << "\nВыберите вариант вопроса\n1. С один правильным вариантом\n2. С несколькими правильными вариантами\n3. Без вариантов\n(нажмите кнопку на клавиатуре)\n\n";

	while (true) {
		while (!_kbhit());

		int button = _getch();

		if (!(button == 49 || button == 50 || button == 51)) {
			cout << "Попробуйте ещё раз\n";
			break;
		}

		quest.id = id;
		cout << "Введите вопрос: ";
		getline( cin, quest.header );

		if (button == 49) {
			while (true) {
				cout << "Введите вариант ответа (0 чтобы закончить ввод)\n";
				getline(cin, quest.str.answerStr );

				if (quest.str.answerStr != "0") {
					quest.answers.push_back( quest.str );
				}
				else {
					break;
				}
			}

			cout << endl;

			for (int i = 0; i < quest.answers.size(); i++) {
				cout << i + 1 << ". " << quest.answers.at( i ).answerStr << endl;
			}

			int correctAnswer;
			cout << "Введите правильный вариант ответа: ";
			cin >> correctAnswer;

			if (correctAnswer > 0 && correctAnswer <= quest.answers.size()) {
				quest.answers.at( correctAnswer - 1 ).weight = 100;
			
				testQuestion.open( pathToQuestion, ios::app );

				if ( testQuestion.is_open() ) {
					long file_size;
					testQuestion.seekg( 0, ios::end );
					file_size = testQuestion.tellg();

					if (!file_size == 0) {
						testQuestion << "\n\n";
					}

					int quantityQuestions = quest.answers.size();

					testQuestion << nameTest << " " << id << " " << quantityQuestions << "\n" << quest.header;

					for (int i = 0; i < quest.answers.size(); i++) {
						testQuestion << "\n" << quest.answers.at(i).answerStr << " " << quest.answers.at(i).weight;
					}

					testQuestion.close();
				}
				else {
					cout << "\nНе удалось загрузить в файл, попробуйте позже (\n";
				}
			}
			else {
				cout << "\nТакого варианта не найдено (\n";
			}
		}
		else if (button == 50) {
			int count = 0;
			int yesNo;
			vector<int> corrAnsw;

			while (true) {
				cout << "Введите вариант ответа (0 чтобы закончить ввод)\n";
				getline( cin, quest.str.answerStr );
				quest.str.weight = 0;

				if (quest.str.answerStr != "0") {
					cout << "Этот вариант правильный? (y / n)\n";
					
					while (!_kbhit());
					yesNo = _getch();

					if (yesNo == 121) {
						corrAnsw.push_back(count);
					}

					quest.answers.push_back( quest.str );
					count++;
				}
				else {
					break;
				}
			}

			float correctsAnswers = 100 / (float)corrAnsw.size();

			for (int i = 0; i < corrAnsw.size(); i++) {
				quest.answers.at(i).weight = correctsAnswers;
			}

			correctsAnswers = 0;

			for (int i = 0; i < quest.answers.size(); i++) {
				if (quest.answers.at(i).weight != 0) {
					correctsAnswers += quest.answers.at(i).weight;
				}
			}

			if (correctsAnswers == 100) {
				testQuestion.open( pathToQuestion, ios::app );

				if (testQuestion.is_open()) {
					long file_size;
					testQuestion.seekg( 0, ios::end );
					file_size = testQuestion.tellg();

					if (!file_size == 0) {
						testQuestion << "\n\n";
					}

					int quantityQuestions = quest.answers.size();

					testQuestion << nameTest << " " << id << " " << quantityQuestions << "\n" << quest.header;

					for (int i = 0; i < quest.answers.size(); i++) {
						testQuestion << "\n" << quest.answers.at( i ).answerStr << " " << quest.answers.at( i ).weight;
					}

					testQuestion.close();
				}
				else {
					cout << "\nНе удалось загрузить в файл, попробуйте позже (\n";
				}
			}
		}
		else if (button == 51) {
			while (true) {
				cout << "Введите все возможные варианты ответа (0 чтобы закончить ввод)\n";
				getline( cin, quest.str.answerStr );
				quest.str.weight = 100;

				if (quest.str.answerStr != "0") {
					quest.answers.push_back( quest.str );
				}
				else {
					break;
				}
			}

			testQuestion.open( pathToQuestion, ios::app );

			if (testQuestion.is_open()) {
				long file_size;
				testQuestion.seekg( 0, ios::end );
				file_size = testQuestion.tellg();

				if (!file_size == 0) {
					testQuestion << "\n\n";
				}

				int quantityQuestions = quest.answers.size();

				testQuestion << nameTest << " " << id << " " << quantityQuestions << "\n" << quest.header;

				for (int i = 0; i < quest.answers.size(); i++) {
					testQuestion << "\n" << quest.answers.at( i ).answerStr << " " << quest.answers.at( i ).weight;
				}

				testQuestion.close();
			}
			else {
				cout << "\nНе удалось загрузить в файл, попробуйте позже (\n";
			}
		}
		else {
			cout << "Попробуйте ещё раз\n";
			break;
		}

		return quest;
	}

	question q;

	return q;
}

bool userTeacher::delQuestion( int id, string nameTest ) {
	testQuestion.open( pathToQuestion );
	testQuestionTemp.open( pathToQuestionTemp, ios::app );

	long file_size;
	testQuestionTemp.seekg( 0, ios::end );

	if (testQuestion) {
		string nameTest1, qName;
		int thisId, qAnsw;

		struct answer {
			string answ;
			float weight;
		};
		answer answer1;

		vector<answer> answers;

		while (!testQuestion.eof()) {
			testQuestion >> nameTest1 >> thisId >> qAnsw;
			getline( testQuestion, qName );
			getline( testQuestion, qName );

			for (int i = 0; i < qAnsw; i++) {
				testQuestion >> answer1.answ >> answer1.weight;
				answers.push_back( answer1 );
			}
			 
			if (nameTest1 == nameTest) {
				if (thisId != id) {
					file_size = testQuestionTemp.tellg();
					if (!file_size == 0) {
						testQuestion << "\n\n";
					}

					testQuestionTemp << nameTest1 << " " << thisId << " " << qAnsw << "\n" << qName;

					for (int i = 0; i < qAnsw; i++) {
						testQuestionTemp << "\n" << answers.at( i ).answ << " " << answers.at( i ).weight;
					}
				}
			}
		}
		testQuestionTemp.close();
		testQuestion.close();
	
		remove( pathToQuestion );
		rename( pathToQuestionTemp, pathToQuestion );

		return true;
	}
	else {
		return false;
	}
}

void userTeacher::allQuestion( string nameTest ) {
	testQuestion.open( pathToQuestion );

	if (testQuestion) {
		string nameTest1, qName, answ;
		int thisId, qAnsw;
		float weight;

		while (!testQuestion.eof()) {
			testQuestion >> nameTest1 >> thisId >> qAnsw;
			getline( testQuestion, qName );
			getline( testQuestion, qName );

			cout << thisId << ". " << qAnsw << "\n";

			for (int i = 0; i < qAnsw; i++) {
				testQuestion >> answ >> weight;
				cout << answ << ":" << weight << endl;
			}
		}
		
		testQuestion.close();
	}
	else {
		cout << "I can't open file (\n";
	}
}
