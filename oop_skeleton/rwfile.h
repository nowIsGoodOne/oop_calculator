//
//  rwfile.h
//  oop_skeleton
//
//  Created by Lousie Nayeong Koh on 11/16/24.
//

#ifndef RWFILE_H
#define RWFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;


namespace GradeSystem{

class Student {
private:
    string name;
    int id;
    double grade;

public:
    Student(string n, int i, double g) : name(n), id(i), grade(g) {}

    void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << "\n";
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getGrade() const { return grade; }

    void setGrade(double g) { grade = g; }

    string toString() const {
        return name + " " + to_string(id) + " " + to_string(grade);
    }
};

class GradeManager {
private:
    map<int, string> studentGrades; // 학생 ID를 기준으로 성적 저장
    vector<Student> students;
    const string filename = "grades.txt";

public:
    void addStudent(const Student& s, int id, double grade) {
        students.push_back(s);
        studentGrades[id] = s + ": " + to_string(grade);
    }

    void saveGrades() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& s : students) {
                file << s.toString() << "\n";
            }
            file.close();
            cout << "성적 저장 성공.\n";
        } else {
            cout << "성적 저장 실패.\n";
        }
    }

    void loadGrades() {
        students.clear();
        ifstream file(filename);
        string name;
        int id;
        double grade;

        if (file.is_open()) {
            while (file >> name >> id >> grade) {
                students.emplace_back(name, id, grade);
            }
            file.close();
            cout << "성적 불러오기 성공.\n";
        } else {
            cout << "성적 불러오기 실패.\n";
        }
    }

    void displayAllStudents() const {
        cout << "모든 학생의 성적을 출력합니다." << endl;
        for (auto& s : students) {
            s.displayInfo();
        }
    }
};

} // namespace GradeSystem

#endif // RWFILE_H
