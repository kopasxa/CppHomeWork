#pragma once 

#include <iostream>
#include <string>
#include <fstream>
#define sizeList 30

using namespace std;

int countList = 0;

struct todo {
    string name;
    int prioritet;
    string desc;
    struct date {
        int month;
        int day;
        string time;
    } date;
};

void printList( todo arr[] );
bool addTo( todo arr[] );
bool edit( todo arr[] );
void add( todo arr[], int point );
bool search( todo arr[] );
bool deleteQ( todo arr[] );
void inFile( todo arr[] );
void outFile( todo arr[] );
void resultFind( todo arr[], int point );

void printList( todo arr[] ) {
    cout << "\t\t LIST ITEMS" << endl;

    if (::countList != 0) {
        int sort;

        cout << "�������� ������� �����������: " << endl;
        cout << "1. �� ����������" << endl;
        cout << "2. �� ���� ����������" << endl;
        cout << "3. ������ �� ����" << endl;
        cout << "4. ������ �� ������" << endl;
        cout << "5. ������ �� �����" << endl;

        cin >> sort;

        cout << "������� ����������� ����: " << endl;
        cout << "Month: ";
        int month;
        cin >> month;
        cout << "Day: ";
        int day;
        cin >> day;

        if (sort == 1) {
            cout << "�������� / �������� / ��������� / �������" << endl;

            todo temp;

            for (int i = 0; i < countList; i++) {
                for (int j = 0; j < countList - i; j++) {
                    if (arr[j].prioritet < arr[j + 1].prioritet) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < countList; i++) {
                cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
            }
        }
        else if (sort == 2) {
            todo temp;

            for (int i = 0; i < countList; i++) {
                for (int j = 0; j < countList - i; j++) {
                    if (arr[j].date.month < arr[j + 1].date.month && arr[j].date.day < arr[j + 1].date.day && arr[j].date.time < arr[j + 1].date.time) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < countList; i++) {
                cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
            }
        }
        else if (sort == 3) {
            for (int i = 0; i < countList; i++) {
                if (arr[i].date.day == day) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                }
            }
        }
        else if (sort == 4) {
            int newDay = day + 7;
            month--;
            for (int i = 0; i < countList; i++) {
                if (newDay >= arr[i].date.day ) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                }
            }
        }
        else if (sort == 5) {
            for (int i = 0; i < countList; i++) {
                if (arr[i].date.month == month) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                }
            }
        }
    }
    else {
        cout << "������ ��� �� ��������� (" << endl;
    }
}

bool addTo( todo arr[] ) {
    if (::countList < sizeList) {
        add( arr, ::countList );

        ::countList++;

        return true;
    }
    else {
        return false;
    }
}

bool edit( todo arr[] ) {
    if (::countList != 0) {
        cout << "\t\t �������������� �����" << endl << endl;

        cout << "��������� ������: " << endl;

        for (int i = 0; i < countList; i++) {
            cout << i + 1 << ". " << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
        }

        cout << endl << "�������� ����� ������������� ������: ";
        int edit;
        cin >> edit;

        cout << edit << ". " << arr[edit - 1].name << "\t" << arr[edit - 1].desc << "\t" << arr[edit - 1].prioritet << "\t" << arr[edit - 1].date.month << "." << arr[edit - 1].date.day << "  " << arr[edit - 1].date.time << endl;

        add( arr, edit - 1 );

        return true;
    }
    else {
        return false;
    }
}

void add( todo arr[], int point ) {
    cout << "������� �������� ������: ";
    cin.ignore();
    getline( cin, arr[point].name );

    cout << "������� �������� ������: ";
    getline( cin, arr[point].desc );

    cout << "������� ��������� ������: ";
    cin >> arr[point].prioritet;

    cout << "������� (����): " << endl;
    cout << "Month: ";
    cin >> arr[point].date.month;
    cout << "Day: ";
    cin >> arr[point].date.day;

    cout << endl << "������� (�����): ";
    cin.ignore();
    getline( cin, arr[point].date.time );
}

void resultFind( todo arr[], int point ) {
    ofstream out;
    out.open( "searchResult.txt", ios::app );
    if (out.is_open()) {

        for (int i = 0; i < ::countList; i++) {
            if (point == i) {
                out << "Name: " << arr[i].name << endl
                    << "Desc: " << arr[i].desc << endl
                    << "Data/Time: " << arr[i].date.day << "." << arr[i].date.month << " " << arr[i].date.time << endl
                    << "Prior: " << arr[i].prioritet << endl << endl;
            }
        }
    }

    out.close();
}

bool search( todo arr[] ) {
    cout << "\t\tSEARCH" << endl;

    bool isFind = false;

    if (::countList != 0) {
        cout << "�������� �������� ������: " << endl;
        cout << "1. �������� ������" << endl;
        cout << "2. ���������" << endl;
        cout << "3. ��������" << endl;
        cout << "4. �� ��������" << endl;

        int menu;
        cin >> menu;



        if (menu == 1) {
            cout << "����� �� ��������: " << endl;
            string findStr;
            cout << "������� ��������: ";
            cin.ignore();
            getline( cin, findStr );

            for (int i = 0; i < countList; i++) {
                if (arr[i].name.find( findStr ) != -1) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                    resultFind( arr, i );
                    isFind = true;
                }
            }
        }
        else if (menu == 2) {
            cout << "����� �� ����������: " << endl;
            int findStr;
            cout << "������� ��������: ";
            cin.ignore();
            cin >> findStr;

            for (int i = 0; i < countList; i++) {
                if (arr[i].prioritet == findStr) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                    resultFind( arr, i );
                    isFind = true;
                }
            }
        }
        else if (menu == 3) {
            cout << "����� �� ��������: " << endl;
            string findStr;
            cout << "������� ��������: ";
            cin.ignore();
            getline( cin, findStr );

            for (int i = 0; i < countList; i++) {
                if (arr[i].desc.find( findStr ) != -1) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                    resultFind( arr, i );
                    isFind = true;
                }
            }
        }
        else if (menu == 4) {
            cout << "����� �� ��� ����������: " << endl;
            int findStr;
            cout << "������� ��������: ";

            cin >> findStr;

            for (int i = 0; i < countList; i++) {
                if (arr[i].date.day == findStr) {
                    cout << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
                    resultFind( arr, i );
                    isFind = true;
                }
            }
        }

        return isFind;
    }
    else {
        return isFind;
    }
}

bool deleteQ( todo arr[] ) {
    cout << "\t\tDELETING" << endl;

    if (::countList != 0) {
        cout << "��������� ������: " << endl;

        for (int i = 0; i < countList; i++) {
            cout << i + 1 << ". " << arr[i].name << "\t" << arr[i].desc << "\t" << arr[i].prioritet << "\t" << arr[i].date.month << "." << arr[i].date.day << "  " << arr[i].date.time << endl;
        }

        cout << "\n�������� ��������� �������: ";
        int delItem;
        cin >> delItem;

        if (delItem > 0) {
            for (int i = delItem - 1; i < countList - 1; i++) {
                arr[i] = arr[i + 1];
            }

            return true;
        }
        else
            return false;
    }
    else {
        return false;
    }
}

void inFile( todo arr[] ) {
    ofstream out;          
    out.open( "data.txt", ios::app );
    if (out.is_open()) {
        /*add( arr, ::countList );*/

        for (int i = 0; i < ::countList; i++) {
            out << "Name: " << arr[i].name << endl
                << "Desc: " << arr[i].desc << endl
                << "Data/Time: " << arr[i].date.day << "." << arr[i].date.month << " " << arr[i].date.time << endl
                << "Prior: " << arr[i].prioritet << endl << endl;
        }
    }

    out.close();
}

void outFile( todo arr[] ) {
    string line;
    
    ifstream in;
    in.open( "data.txt" );
    if (in.is_open()) {
        while (getline( in, line )) {
            cout << line << endl;
        }
    }

    in.close();
}
