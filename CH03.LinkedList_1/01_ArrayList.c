#include <stdio.h>
#include "01_ArrayList.h" //헤더파일 불러오기

//배열 기반 리스트 구현 하나로 묶기

void ListInit(List* plist)
{
    (plist->numOfData)=0;
    (plist->curPosition)= -1;
}

void LInsert(List* plist, LData data)
{
    if(plist->numOfData >= LIST_LEN){
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
    return plist->numOfData;
}

