#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    string group;
    vector<string> subjects;
    vector<double> grades;
public:
    Student(string& name, string& group) : name(name), group(group) {}

    void addGrade(string& subject, bool grade) {
        subjects.push_back(subject);
        grades.push_back(grade);
    }
    void displayGrades(){
        cout << "Студент: " << name << ", Группа: " << group << endl;
        cout << "Оценки:" << endl;
        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << "Предмет: " << subjects[i] << ", Оценка: " << grades[i] << endl;
        }
    }
    string getName() {
        return name;
    }
    string getGroup() {
        return group;
    }

};


class Journal {
private:
    vector<Student> students;
public:
    void addStudent(string& name, string& group) {
        students.push_back(Student(name, group));
    }

    void addGrade(string& name, string& subject, double grade) {
        for (auto student : students) {
            if (student.getName() == name) {
                student.addGrade(subject, grade);
                return;
            }
        }
        cout << "Студент с именем '" << name << "' не найден." << endl;
    }

    void displayStudentGrades(const string& name) {
        for (auto student : students) {
            if (student.getName() == name) {
                student.displayGrades();
                return;
            }
        }
        cout << "Студент с именем '" << name << "' не найден." << endl;
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "Студентов нет." << endl;
            return;
        }

        cout << "Список всех студентов:" << endl;
        for (auto student : students) {
            cout << "Имя: " << student.getName() << ", Группа: " << student.getGroup() << endl;
        }
    }

};

int main() {
    setlocale(LC_ALL, "rus");

    Journal journal;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Добавить оценку студенту" << endl;
        cout << "3. Показать оценки студента" << endl;
        cout << "4. Вывести всех студентов" << endl;
        cout << "5. Выйти" << endl;

        int number;
        cin >> number;
        if (number == 1) {
            string name, group;
            cin.ignore();
            cout << "Введите имя студента: ";
            getline(cin, name);
            cout << "Введите номер группы: ";
            getline(cin, group);
            journal.addStudent(name, group);
        }
        else if (number == 2) {
            string name, subject;
            double grade;
            cin.ignore();
            cout << "Введите имя студента: ";
            getline(cin, name);
            cout << "Введите предмет: ";
            getline(cin, subject);
            cout << "Введите оценку: ";
            cin >> grade;
            journal.addGrade(name, subject, grade);
        }
        else if (number == 3) {
            string name;
            cin.ignore();
            cout << "Введите имя студента: ";
            getline(cin, name);
            journal.displayStudentGrades(name);
        }
        else if (number == 4) {
            journal.displayAllStudents();
        }
        else if (number == 5) {
            break;
        }
        else {
            cout << "Неверный выбор. Попробуйте снова."<<endl;
        }
    }
}