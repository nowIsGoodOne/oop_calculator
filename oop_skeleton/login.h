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
class AccessDeniedError : public exception {
public:
    const char* what() const noexcept override {
        return "접근이 거부되었습니다.";
    }
};

// 사용자 기본 클래스
class User {
protected:
    string name;
    string id;
    string password;
public:
    User(string name, string id, string password)
        : name(name), id(id), password(password) {}

    virtual void viewGrades() = 0; // 성적 조회 기능
};

// 학생 클래스
class StudentUser : public User {
public:
    StudentUser(string name, string id, string password)
        : User(name, id, password) {}

    void viewGrades() override {
        cout << name << " 학생님의 성적을 조회합니다." << endl;
        // 본인이 수강하는 과목에 대한 성적만 조회 가능
        cout << "수강 과목: 수학, 성적: 95점" << endl;
    }
};

// 교수 클래스
class Professor : public User {
public:
    Professor(string name, string id, string password)
        : User(name, id, password) {}

    void viewGrades() override {
        cout << name << " 교수님의 강의 성적을 조회합니다." << endl;
        // 교수님은 강의하는 과목 성적을 조회 가능
        cout << "강의 과목: 광고학, 성적: 90점" << endl;
    }

    void inputGrades(string course, const vector<double>& grades) {
        // 교수님이 강의하는 과목에 대한 성적 입력
        cout << course << " 과목의 성적을 입력합니다." << endl;
        for (double grade : grades) {
            cout << "성적: " << grade << endl;
        }
    }
};

// 관리자 클래스
class Administrator : public User {
public:
    Administrator(string name, string id, string password)
        : User(name, id, password) {}

    void viewGrades() override {
        cout << name << " 관리자의 권한으로 모든 성적을 조회합니다." << endl;
        // 모든 과목의 성적을 조회
        cout << "모든 과목의 성적: 수학 95점, 광고학 90점" << endl;
    }

    void inputGrades(string course, const vector<double>& grades) {
        // 관리자가 성적을 입력
        cout << course << " 과목에 대한 성적을 입력합니다." << endl;
        for (double grade : grades) {
            cout << "성적: " << grade << endl;
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

// 접근 권한 검사
void checkAccess(bool userPermission) {
    if (!userPermission) {
        throw AccessDeniedError();
    }
}
} // namespace UserSystem

#endif // LOGIN_H
