//
//  login.h
//  oop_skeleton
//
//  Created by Lousie Nayeong Koh on 11/16/24.
//

#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip> // for std::setprecision
using namespace std;


namespace UserSystem {
// 접근 거부 예외 클래스
class AccessDeniedError : public runtime_error {
public:
    AccessDeniedError(const string& message) : runtime_error(message) {}
};

// 사용자 기본 클래스
class User {
protected:
    string name;
    string studentID;
    string major;

public:
    User(const string& name, const string& studentID, const string& major)
        : name(name), studentID(studentID), major(major) {}

    string getName() const { return name; }
    string getID() const { return studentID; }
    string getMajor() const { return major; }
    virtual void viewGrades() const = 0;
};

// 학생 클래스
class StudentUser : public User {
public:
    StudentUser(const string& name, const string& studentID, const string& major)
        : User(name, studentID, major) {}

    void viewGrades() const override {
        cout << "Viewing grades for student: " << name << endl;
        // 성적 조회 로직 추가
    }
};

// 관리자 클래스
class Administrator : public User {
private:
    unordered_map<std::string, vector<double>> grades;

public:
    Administrator(const string& name, const string& studentID, const string& major)
        : User(name, studentID, major) {}

    void inputGrades(const string& subject, const vector<double>& scores) {
        grades[subject] = scores;
        cout << "Grades input for subject: " << subject << endl;
    }

    void viewGrades() const override {
        cout << "Viewing grades for administrator: " << name << endl;
        for (const auto& pair : grades) {
            cout << "Subject: " << pair.first << " | Grades: ";
            for (const auto& grade : pair.second) {
                cout << fixed << std::setprecision(2) << grade << " ";
            }
            cout << endl;
        }
    }

    void selectSubject() {
        // 과목 선택 로직 추가
    }

    void inputEvaluation() {
        // 평가 항목 및 비율 입력 로직 추가
    }

    void saveState() {
        // 현재 상태 저장 로직 추가
    }

    void loadState() {
        // 상태 불러오기 로직 추가
    }
};

// 접근 권한을 체크
void checkAccess(bool userPermission) {
    if (!userPermission) {
        throw AccessDeniedError("Access Denied");  // 예외 발생
    }
}
} // namespace UserSystem

#endif // LOGIN_H
