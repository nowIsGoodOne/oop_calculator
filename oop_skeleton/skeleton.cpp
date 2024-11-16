//
//  skeleton.cpp
//  oop_skeleton
//
//  Created by Lousie Nayeong Koh on 11/16/24.
//

#include "login.h"
#include "rwfile.h"

int main() {
    cout << "************************************************************" << endl;
    cout << "광고홍보학과 성적 관리 시스템" << endl;
    cout << "************************************************************" << endl;
    cout << "로그인을 진행합니다." << endl;
    cout << "1. 학생" << endl;
    cout << "2. 교수" << endl;
    cout << "3. 관리자" << endl;
    
    int userType; // 사용자 신분을 입력받을 변수
    cout << "로그인할 계정의 신분을 선택해 번호를 입력하세요. ";
    cin >> userType;
    
    // &&&&&&&&&&&& 프로그램 진입 시 로그인 &&&&&&&&&&&&&&&&&&&&
    try {
        string id, pw;
        bool userPermission = false;  // Default: 권한이 없음
        
        cout << "ID:";
        cin >> id;
        cout << "PW:";
        cin >> pw;
        
        UserSystem::checkAccess(userPermission, id, pw);

        // 로그인된 사용자에 따른 객체 생성
        if (userType == 1 && userPermission) {  // 학생 로그인
            UserSystem::StudentUser student("Duke Lee", "S001", "Advertising");
            student.viewGrades();  // 학생 성적 조회
        } else if (userType == 2 && userPermission) {  // 교수 로그인
            UserSystem::Professor professor("Professor Smith", "P001", "Advertising");
            professor.viewGrades();  // 교수 성적 조회
        } else if (userType == 3 && userPermission) {  // 관리자 로그인
            UserSystem::Administrator admin("Administrator Kim", "A001", "Advertising");
            admin.viewGrades();  // 관리자 성적 조회
        } else {
            throw invalid_argument("유효하지 않은 선택입니다.");
        }

    } catch (const UserSystem::AccessDeniedError& e) {
        cerr << e.what() << endl; // 오류 메시지 출력
    } catch (const exception& e) {
        cerr << e.what() << endl; // 잘못된 입력 처리
    }

    // &&&&&&&&&&&& 학생 성적 저장 및 확인 &&&&&&&&&&&&&&&&&&&&
    GradeSystem::GradeManager manager;

    // 학생 추가
    manager.addStudent(GradeSystem::Student("Alice", 1, 95.5));
    manager.addStudent(GradeSystem::Student("Bob", 2, 87.0));

    // 성적 저장
    manager.saveGrades();

    // 저장된 성적 불러오기 및 출력
    manager.loadGrades();
    manager.displayAllStudents();

    return 0;
}
