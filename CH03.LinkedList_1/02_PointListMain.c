//메인함수가 있는 소스파일
#include <stdio.h>
#include <stdlib.h>
#include "01_ArrayList.h"
#include "02_Point.h"

int main(void)
{
    List list;
    Point compPos;
    Point* ppos; //구조체 포인터 선언

    ListInit(&list); //초기화
    
    // 4개의 데이터 저장
    ppos=(Point*)malloc(sizeof(Point)); //메모리 동적 할당
    SetPointPos(ppos, 2,1);  //(2,1) 저장
    LInsert(&list, (int)ppos); 

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2); //(2,2) 저장
    LInsert(&list, (int)ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1); //(3,1) 저장
    LInsert(&list, (int)ppos); 

     ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2); //(3,2) 저장
    LInsert(&list, (int)ppos);


    // 저장된 데이터 출력
    printf("현재 데이터의 수: \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
        
    }
    printf("\n");


    //xpos가 2인 모든 데이터 삭제
    compPos.xpos=2;
    compPos.ypos=0;

    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compPos)==1)
        {
            ppos=LRemove(&list); //데이터가 삭제되었으니
            free(ppos); // 동적 할당 해제
        }
    }


    // 데이터 삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    printf("\n");
    return 0;

}