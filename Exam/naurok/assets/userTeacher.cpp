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
			testFile << "\n" << testName << " stoped";
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
		allQuestion();
		cout << "Выберите какой вопрос удалить: ";
		int num;
		cin >> num;

		delQuestion( num, testName );
	}
	else if (option == 115) {

	}

	return true;
}

bool userTeacher::readResults() {
	system( "cls" );
	printTests();
	cout << "Выберите тест: ";
	int num;
	cin >> num;

	string nameTest = qById( num );
	//answerStudent answ;
	//vector<answerStudent> answers;
	string login, testName;
	float appraisal;
	int sizeArr, numLogin;
	string answers, headerQ;
	string itsLogin;

	cout << "Посмотреть все результаты (1)\nПосмотреть результаты одного пользователя (2)\n";
	cin >> num;

	if (num > 2 || num < 1) {
		cout << "Не найдено :(\n";
	}

	if (num == 2) {
		result.open( pathToResults );

		if (result) {
			for (int i = 0; !result.eof(); i++) {
				result >> login >> testName >> appraisal >> sizeArr;
				for (int j = 0; j < sizeArr; j++) {
					if (j == 0) {
						getline( result, headerQ );
					}
					getline( result, headerQ );
					getline( result, answers );
				}
				
				cout << i + 1 << ". " << login << endl;
			}

			cout << "Выберите студента: ";
			cin >> numLogin;

			result.clear();
			result.seekg( 0, ios::beg );

			for (int i = 0; !result.eof(); i++) {
				result >> login >> testName >> appraisal >> sizeArr;
				for (int j = 0; j < sizeArr; j++) {
					if (j == 0) {
						getline( result, headerQ );
					}
					getline( result, headerQ );
					getline( result, answers );
				}

				if (i == numLogin - 1) {
					itsLogin = login;
				}
			}

			result.close();
		}
		else {
			cout << "Error 404: обратитесь к администратору\n";
			return false;
		}
	}

	result.open( pathToResults );

	if ( result ) {
		while (!result.eof()) {
			result >> login >> testName >> appraisal >> sizeArr;

			if (num == 1) {
				cout << login << ": {\n";
			}

			for (int i = 0; i < sizeArr; i++) {
				if (i == 0) {
					getline( result, headerQ );
				}
				getline( result, headerQ );
				getline( result, answers );


				if (num == 1) {
					cout << "   " << headerQ << ": " << answers << ",\n";
				}
				else if (num == 2) {
					if (login == itsLogin) {
						cout << headerQ << ": " << answers << "\n";
					}
				}
		}

			if (login == itsLogin) {
				if (num == 1) {
					cout << "}\n";
				}
			}	
		}
	}

	cout << "Чтобы продолжить нажмите любую клавишу...\n";
	while (!_kbhit());

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
			int id, qAnsw, variantQ;
			float weight;
			testQuestion.seekg( 0, 0 );

			while (!testQuestion.eof()) {
				testQuestion >> nameTest >> id >> qAnsw >> variantQ;
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

string userTeacher::qById( int id ) {
	testFile.open( pathToTests );
	string testName, status;

	if ( testFile ) {
		for (int i = 0; !testFile.eof(); i++) {
			testFile >> testName >> status;
			
			if (id == i + 1) {
				testFile.close();
				return testName;
			}
		}
	}
	else {
		return testName;
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

					testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 1 << "\n" << quest.header;

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

					testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 2 << "\n" << quest.header;

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

				testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 3 << "\n" << quest.header;

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

question userTeacher::addQuestion( question quest, string nameTest ) {
	int id = quantityQ(nameTest) + 1;
	testQuestion.open( pathToQuestion, ios::app );

	if (testQuestion.is_open()) {
		long file_size;
		testQuestion.seekg( 0, ios::end );
		file_size = testQuestion.tellg();

		if (!file_size == 0) {
			testQuestion << "\n\n";
		}

		int quantityQuestions = quest.answers.size();

		testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << quest.variantQ << "\n" << quest.header;

		for (int i = 0; i < quest.answers.size(); i++) {
			testQuestion << "\n" << quest.answers.at( i ).answerStr << " " << quest.answers.at( i ).weight;
		}

		return quest;
		testQuestion.close();
	}
	else {
		cout << "\nНе удалось загрузить в файл, попробуйте позже (\n";
		question r;
		return r;
	}
}

question userTeacher::addQuestion( string nameTest ) {
	int id = quantityQ( nameTest );

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
				getline( cin, quest.str.answerStr );

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

				if (testQuestion.is_open()) {
					long file_size;
					testQuestion.seekg( 0, ios::end );
					file_size = testQuestion.tellg();

					if (!file_size == 0) {
						testQuestion << "\n\n";
					}

					int quantityQuestions = quest.answers.size();

					testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 1 << "\n" << quest.header;

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
						corrAnsw.push_back( count );
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
				quest.answers.at( i ).weight = correctsAnswers;
			}

			correctsAnswers = 0;

			for (int i = 0; i < quest.answers.size(); i++) {
				if (quest.answers.at( i ).weight != 0) {
					correctsAnswers += quest.answers.at( i ).weight;
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

					testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 2 << "\n" << quest.header;

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

				testQuestion << nameTest << " " << id << " " << quantityQuestions << " " << 3 << "\n" << quest.header;

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

void userTeacher::qAddTo() {
	int numQ, numT;
	allQuestion();
	cout << "Выберите вопрос который хотите добавить в тест: ";
	cin >> numQ;
	question newQ = findQ(numQ);
	cout << endl;

	printTests();
	cout << "Выберите тест в который хотите добавить вопрос: ";
	cin >> numT;
	cout << endl;
	string nameTest = qById(numT);

	if (addQuestion( newQ, nameTest ).header != "") {
		cout << "Успешно добавлено! \n";
		Sleep(2000);
	}
}

bool userTeacher::delQuestion( int id, string nameTest ) {
	testQuestion.open( pathToQuestion );
	testQuestionTemp.open( pathToQuestionTemp, ios::app );

	long file_size;
	testQuestionTemp.seekg( 0, ios::end );

	if (testQuestion) {
		string nameTest1, qName;
		int thisId, qAnsw, variantQ;

		struct answer {
			string answ;
			float weight;
		};
		answer answer1;

		vector<answer> answers;

		while (!testQuestion.eof()) {
			testQuestion >> nameTest1 >> thisId >> qAnsw >> variantQ;
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

					testQuestionTemp << nameTest1 << " " << thisId << " " << qAnsw << " " << variantQ << "\n" << qName;

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

question userTeacher::findQ(int id) {
	question newQuestion;
	string testName;
	int qAnsw;
	testQuestion.open( pathToQuestion );

	if (testQuestion) {

		for (int i = 0; !testQuestion.eof(); i++) {
			testQuestion >> testName >> newQuestion.id >> qAnsw >> newQuestion.variantQ;
			getline( testQuestion, newQuestion.header );
			getline( testQuestion, newQuestion.header );

			for (int j = 0; j < qAnsw; j++) {
				testQuestion >> newQuestion.str.answerStr >> newQuestion.str.weight;
				if (i + 1 == id) {
					newQuestion.answers.push_back( newQuestion.str );
				}
			}

			if (i + 1 == id) {
				testQuestion.close();

				return newQuestion;
			}
		}
	}
	else {
		return newQuestion;
	}
}

void userTeacher::allQuestion() {
	testQuestion.open( pathToQuestion );

	if (testQuestion) {
		string nameTest1, qName, answ;
		int thisId, qAnsw, variantQ;
		float weight;

		while (!testQuestion.eof()) {
			testQuestion >> nameTest1 >> thisId >> qAnsw >> variantQ;
			getline( testQuestion, qName );
			getline( testQuestion, qName );

			cout << thisId << ". " << qName << "\n";

			for (int i = 0; i < qAnsw; i++) {
				testQuestion >> answ >> weight;
				/*cout << answ << ":" << weight << endl;*/
			}
		}

		testQuestion.close();
	}
	else {
		cout << "I can't open file (\n";
	}
}

void userTeacher::printTests() {
	cout << endl;
	string nameTest, status;
	testFile.open( pathToTests );

	if ( testFile ) {
		for (int i = 0; !testFile.eof(); i++) {
			testFile >> nameTest >> status;
			cout << i + 1 << ". " << nameTest << "\n";
		}
	}
	cout << endl;

	testFile.close();
}

bool userTeacher::printTests( bool trueS ) {
	bool is = false;
	cout << endl;
	string nameTest, status;
	testFile.open( pathToTests );

	if (testFile) {
		for (int i = 0; !testFile.eof(); i++) {
			testFile >> nameTest >> status;
			if (status == "worked") {
				cout << i + 1 << ". " << nameTest << "\n";
				is = true;
			}
		}
	}
	cout << endl;

	testFile.close();
	return is;
}

bool userTeacher::changeStatusTest() {
	string nameTest, status;
	printTests();
	cout << "Выберите тест, статус которого хотите изменить: ";
	int num;
	cin >> num;
	cout << "Открыть (1) / закрыть (0)\n";
	int num2;
	cin >> num2;

	testFile.open( pathToTests );
	testFileTemp.open( pathToTestsTemp, ios::app );

	if (testFile) {
		for (int i = 0; !testFile.eof(); i++) {
			testFile >> nameTest >> status;
			
			if ( num == i + 1 ) {
				if (num2 == 1) {
					testFileTemp << "\n" << nameTest << " worked";
				}
				else if (num2 == 0) {
					testFileTemp << "\n" << nameTest << " stoped";
				}
				else {
					cout << "Статус не был изменён, попробуйте ещё раз\n";
				}
			}
			else {
				testFileTemp << "\n" << nameTest << " " << status;
			}
		}

		testFile.close();
		testFileTemp.close();

		remove( pathToTests );
		rename( pathToTestsTemp, pathToTests );
	
		return true;
	}
	else {
		return false;
	}
}
