//순차 탐색(LinearSearch)알고리즘의 구현 + "시간복잡도(Time Complexity) 분석"하기
#include <stdio.h>

//순차 탐색 알고리즘이 적용된 함수 LSearch
int LSearch(int arr[], int len, int target)//target은 찾고자하는 목표 데이터
{
    int i;
    for(int i=0; i<len; i++)
    {
        //찾고자 하는 데이터를 찾았다면?
        if(arr[i]==target)
            return i; //찾는 대상의 인덱스를 반환
    }

    //찾고자 하는 대상을 찾지 못했다면?
    return -1; //탐색실패를 의미하는 값 반환

}

int main(void)
{
    int arr[]={3,5,2,4,9};
    int index;

    //찾고 싶은 데이터가 4일 때
    index=LSearch(arr, sizeof(arr)/sizeof(int), 4);

    //탐색 실패했다면?
    if(index==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", index);


    //찾고 싶은 데이터가 7일 때
    index = LSearch(arr, sizeof(arr)/sizeof(int), 7);

    if(index==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", index);


    return 0;
}

/*
시간 복잡도 분석하기: 데이터의수 n에 대한 연산횟수 함수T(n) 구하기 

위 알고리즘에서 사용된 연산은 <,++,== 인데, == 연산을 적게 수행하는 탐색 알고리즘이 좋은 탐색 알고리즘이다. 
핵심은 동등비교하는 연산인 것이다. 
왜냐하면 ==비교연산과 <,++연산은 비례관계이기 때문이다. => 다른 연산들(<,++)은 ==연산에 의존적이다. 


--- 시간복잡도(Time Complexity) 구하기 ---

최선의 경우(best case) <- 관심대상이 아님.
평균의 경우(average case) <- 구하기 어려움
최악의 경우(worst case) <- 관심대상

-순차 탐색 알고리즘의 최악의 경우는 T(n)=n
-평균의 경우는 T(n)=(3/4)*n <- 구하는데 고려해야 하는 상황도 많고 복잡하다



*/