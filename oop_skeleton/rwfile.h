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
    vector<Student> students;
    const string filename = "grades.txt";

public:
    void addStudent(const Student& s) {
        students.push_back(s);
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
        for (const auto& s : students) {
            s.displayInfo();
        }
    }
};

} // namespace GradeSystem

#endif // RWFILE_H
