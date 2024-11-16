//
//  skeleton.cpp
//  oop_skeleton
//
//  Created by Lousie Nayeong Koh on 11/16/24.
//

#include "login.h"
#include "rwfile.h"

int main() {
    // &&&&&&&&&&&& 프로그램 진입 시 로그인 &&&&&&&&&&&&&&&&&&&&
    try {
        bool userPermission = false;  // 권한이 없음
        UserSystem::checkAccess(userPermission); // 사용자 권한 체크

        // 관리자와 학생 객체 생성 예시
        UserSystem::Administrator admin("Professor Smith", "A001", "Advertising");
        UserSystem::StudentUser student("Duke Lee", "S001", "Advertising");

        // 관리자 성적 입력
        admin.inputGrades("Marketing", {85.0, 90.0, 78.5});
        admin.inputGrades("Advertising", {92.0, 88.0, 80.5});

        // 학생 성적 조회
        student.viewGrades();
        
        // 관리자 성적 조회
        admin.viewGrades();

    } catch (const UserSystem::AccessDeniedError& e) {
        std::cerr << e.what() << std::endl; // 오류 메시지 출력
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
