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
public:
    virtual void viewGrades() = 0;  // 성적 조회
};

// 학생 클래스
class StudentUser : public User {
public:
    StudentUser(string name, string id, string department)
    : name(name), id(id), department(department) {}
    
    void viewGrades() override {
        cout << name << " (학생)님의 성적을 조회합니다." << endl;
    }
private:
    string name;
    string id;
    string department;
};

// 교수 클래스
class Professor : public User {
public:
    Professor(string name, string id, string department)
    : name(name), id(id), department(department) {}
    
    void viewGrades() override {
        cout << name << " (교수)님의 성적을 조회합니다." << endl;
    }
private:
    string name;
    string id;
    string department;
};

// 관리자 클래스
class Administrator : public User {
public:
    Administrator(string name, string id, string department)
    : name(name), id(id), department(department) {}
    
    void viewGrades() override {
        cout << name << " (관리자)님의 성적을 조회합니다." << endl;
    }
private:
    string name;
    string id;
    string department;
    
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
void checkAccess(bool& userPermission, const string& id, const string& pw) {
    // 학생, 교수, 관리자 신분 별로 ID와 PW 설정
    struct UserInfo {
        string id;
        string pw;
        string role;
    };
    
    UserInfo users[] = {
        {"student", "student123", "학생"},
        {"professor", "professor123", "교수"},
        {"admin", "admin123", "관리자"}
    };
    
    for (const auto& user : users) {
        if (user.id == id && user.pw == pw) {
            userPermission = true;
            cout << user.role << "으로 로그인되었습니다." << endl;
            return;
        }
    }
    
    throw AccessDeniedError("유효하지 않은 계정입니다.");
}
} // namespace UserSystem

#endif // LOGIN_H
