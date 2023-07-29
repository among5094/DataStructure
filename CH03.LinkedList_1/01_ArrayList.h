/* 리스트는 구현방법에 따라서 2가지로 나뉘는데 
배열을 기반으로 구현된 순차 리스트, 
메모리의 동적 할당을 기반으로 구현된 연결 리스트 이렇게 2가지이다. 
*/
//배열을 기반으로 리스트 구현하기 -> 헤더파일 정의하기
#include <stdio.h>

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1 //'참'을 표현하기 위한 매크로 정의
#define FALSE 0 // '거짓'을 표현하기 위한 매크로 정의

#define LIST_LEN 100
typedef int LData; //LData에 대해 typedef 선언(리스트의 다양한 종류의 데이터를 저장하기 위해)

typedef struct __ArrayList //배열기반 리스트를 정의한 구조체
{
    LData arr[LIST_LEN]; //데이터의 저장공간이 배열로 선언됨
    int numOfData; //저장된 데이터의 수
    int curPosition; //현재 배열의 인덱스값 저장됨
}ArrayList;

typedef ArrayList List; // List는 연결 기반 리스트임

//초기화
void ListInit(List* plist)
{
    (plist->numOfData)==0; //리스트에 저장된 데이터의 수는 0개
    (plist->curPosition)=-1; //현재 아무 위치도 가리키지 않고 있다는 뜻.
}

//데이터 저장
void LInsert(List* plist, LData data)
{
    //더 이상 저장할 공간이 없다면?
    if(plist->numOfData >= LIST_LEN){//데이터의 개수가 배열의 길이를 초과했는지 검사
        puts("저장이 불가능합니다.");
        return;
    }

    //저장할 공간이 있다면?
    plist->arr[plist->numOfData] == data; //데이터 저장
    (plist->numOfData)++; //위에서 데이터를 저장했으니, 저장된 데이터의 개수 증가
} 

//첫 데이터 참조
// LFirst함수는 curPosition에 저장된 값을 0으로 재설정함으로써 데이터의 참조가 앞에서부터 다시 진행되도록 하는 역할
int LFirst(List* plist, LData* pdata)
{
    //저장된 데이터가 하나도 없으면?
    if(plist->numOfData == 0)
        return FALSE;
    
    //저장된 데이터가 있다면?
    (plist->curPosition)=0; //참조 위치 초기화 <-데이터의 참조가 앞에서부터 다시 진행되도록 하는 역할
    *pdata = plist->arr[0]; //pdata가 가리키는 공간에 데이터 저장
    return TRUE;
}

// 두 번째 이후 데이터 참조
// LNext함수는 curPosition의 값을 증가시켜서 순서대로 데이터를 참조할 수 있도록 한다. 
int LNext(List* plist, LData* pdata)
{
    // 더 이상 참조할 데이터가 없다면?
    if(plist->curPosition >= (plist->numOfData)-1 ) 
        return FALSE;

    //참조할 데이터가 있다면?
    (plist->curPosition)++; //현재 위치 증가시킴 <- 순서대로 데이터를 참조할 수 있도록 하기위해
    *pdata=plist->arr[plist->curPosition];
    return TRUE;
}

// 참조한 데이터 삭제
//1. 삭제할 데이터의 위치를 참조하는 방식
//2. 삭제를 위한 데이터의 이동과정(중간에 데이터가 삭제되면 데이터를 이동시켜서 그 공간을 메워야한다.)
LData LRemove(List* plist) //최근에 조회된 데이터 삭제
{
    int rpos=plist->curPosition; //삭제할 데이터의 인덱스 값 참조
    int num=plist->numOfData; //저장된 데이터의 개수
    int i;
    LData rdata=plist->arr[rpos]; //삭제할 데이터를 임시로 저장

    //삭제를 위한 데이터의 이동을 진행하는 반복문(2번 진행)
    for(i=rpos; i<num-1; i++)
        plist->arr[i]=plist->arr[i+1];//한 칸 앞에 있는 데이터가 한 칸 뒤에 있는 데이터로 이동됨

    (plist->numOfData)--; //데이터의 수 감소
    (plist->curPosition)--; //참조위치를 배열 기준 왼쪽으로 옮기기.
    //curPosition에는 최근에 참조가 이루어진 데이터를 담아야 하는데,
    //이 코드가 없으면 데이터 삭제로 인해 비는 공간을 왼쪽으로 밀어줄 때의 데이터를 가리키고 있기 때문!
    
    return rdata; //삭제된 데이터 반환
}

//저장된 데이터의 수를 기록하기 위한 멤버 존재
int LCount(List* plist)
{

}

#endif

