#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

//구조체 복습1 -> 학생 구조체 선언하기

//학생에 대한 구조체
struct student {

    int number; //학번
    char name[30]; //이름
    double grade; //학점
};


int main(void){

    struct student s; //구조체 student의 변수s 생성됨. 

    //구조체 변수 s의 멤버에 값들 대입하기
    s.number = 20200255;
    strcpy(s.name, "홍길동");//name="이름"; <-불가능함!
    s.grade = 4.2;

    printf("학번: %d\n",s.number);
    printf("이름: %s\n",s.name);
    printf("학점: %lf\n",s.grade);


    return 0;
}