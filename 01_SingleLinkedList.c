//단일 연결 리스트 코딩해보기 , Single Linked List 코딩하기

#include <stdio.h>

//구조체 선언
typedef struct NODE{

    //관리될 데이터
    int nData; 

    //데이터 관리를 위한 포인터
    struct NODE* next; 
}NODE;


// 메인함수
int main()
{
    //연결리스트로 배열 만들어보기
    NODE list[5] = {0}; //초기화 시키기

    //연결리스트 연결해주기 
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL;
    //NULL: 주소라고 생각한다면 접근할 수 없는 영역
    //어설프게 살아있는 것보다 NULL을 채워넣는 것이 안전하다. 

    //데이터넣기
    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;

    //배열로 출력하기
    for(int i=0; i<5; i++)
        printf("list[%d]: %d \n", i, list[i].nData);

    //포인터로 출력하기
    NODE *pTmp = &list[0]; //연결리스트의 첫 번째 주소 넣기
    
    while(pTmp != NULL)
    {
        printf("%p: %d \n", pTmp, pTmp->nData);
        pTmp = pTmp->next; //현재 노드에서 다음 노드로 넘어가기
        //pTmp가 가리키는 값을 넣어주기
        //현재 가리키고 있는 pTmp의 nData를 overwrite
    }

    return 0;
}

