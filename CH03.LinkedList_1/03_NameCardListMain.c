#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include "03_NameCard.h"
#include "01_ArrayList.h"

//메인함수가 선언된 소스파일

int main(void){

    List list;
    NameCard* pcard;
    ListInit(&list); 

    //총 3명의 이름,전번 저장
    pcard=MakeNameCard("이진수", "010-1111-1111");
    LInsert(&list, pcard);

    pcard=MakeNameCard("한지영", "010-2222-2222");
    LInsert(&list, pcard);

    pcard=MakeNameCard("조수진", "010-3333-3333");
    LInsert(&list, pcard);

    //한지영 정보 조회(이름 조회) 후 출력
    if(LFirst(&list, &pcard))
    {

        //정보 조회에 실패했다면?
        if(!NameCompare(pcard, "한지영"))
            ShowNameCardInfo(pcard);
        else{
            while(LNext(&list, &pcard)){
                if(!NameCompare(pcard, "한지영")){
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
        
    }

    //이진수 정보 조회(번호 조회) 후 변경
    if(LFirst(&list, &pcard))
    {

        //정보 조회에 실패했다면?
        if(!NameCompare(pcard, "이진수")) //이름보고
            ChangePhoneNum(pcard, "010-9999-9999");
        else{
            while(LNext(&list, &pcard)){
                if(!NameCompare(pcard, "이진수")){
                    ChangePhoneNum(pcard, "010-9999-9999");
                    break;
                }
            }
        }
        
    }

    //조수진 정보 조회 후 삭제
    if(LFirst(&list, &pcard))
    {

        //정보 조회에 실패했다면?
        if(!NameCompare(pcard, "조수진")) //이름보고
        {
            pcard=LRemove(&list);
            free(pcard); //삭제할 때는 동적 할당 해제
        }
        else
        {
            while(LNext(&list, &pcard))
            {
                if(!NameCompare(pcard, "조수진"))
                {
                    pcard=LRemove(&list);
                    free(pcard); //삭제할 때는 동적 할당 해제
                    break;
                }
            }
        }
        
    }

    //모든 사람 정보 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if(LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
            ShowPointPos(pcard);
    }

}