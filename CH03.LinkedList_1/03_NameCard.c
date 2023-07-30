#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include "03_NameCard.h"

//정답코드


//NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard* MakeNameCard(char* name, char* phone)
{
    //메모리 동적할당
    NameCard* p1=(NameCard*)malloc(sizeof(NameCard));

    //초기화 
    strcpy(p1->name, name);
    strcpy(p1->phone, phone);

    //주소 값 반환
    return p1;

}


///NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pcard)
{
    printf("이름: %s\n", pcard->name);
    printf("이름: %s\n", pcard->phone);
}

//이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard* pcard, char* name)
{
    return strcmp(pcard->name, name); //strcmp는 같으면 0반환
    //가리키고 있는 이름과 원본의 이름이 같으면 0반환
}

//전화번호 정보 변경
void ChangePhoneNum(NameCard* pcard, char* phone)
{
    strcmp(pcard->phone, phone);
}
