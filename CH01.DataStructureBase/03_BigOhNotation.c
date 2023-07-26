// O(log₂n)인 이진 탐색 알고리즘을 대상으로 비교연산 횟수 확인해보기

#include <stdio.h>

int BSearch(int arr[], int len, int target)
{
    int first=0;
    int last=len-1;
    int mid;
    int opCount=0;  //비교연산의 횟수 기록하는 변수

    while(first<=last)
    {
        mid=(first+last)/2;

        if(target==arr[mid])
            return mid; 
        else{
            if(target<arr[mid])
                last = mid-1;
            else
                first=mid+1;
        }

        //비교가 끝났다면? 비교연산의 횟수 1증가    
        opCount +=1;

    }//while문 닫기

    printf("비교연산횟수:%d\n", opCount); //탐색실패 시 연산횟수 출력
    return -1;

}

int main(void)
{
    //모든 요소 0으로 초기화
    int arr1[500]={0,};
    int arr2[5000]={0,};
    int arr3[50000]={0,};
    int index;

    //배열 arr1일 때, 저장되지 않은 정수 1을 찾으라고 명령하기 
    index=BSearch(arr1, sizeof(arr1)/sizeof(int), 1); 
    if(index==-1)
        printf("탐색 실패\n");
    else 
        printf("타겟이 저장된 인덱스: %d\n", index);

    //배열 arr2일 때, 저장되지 않은 정수 2을 찾으라고 명령하기 
    index=BSearch(arr2, sizeof(arr2)/sizeof(int), 2); 
    if(index==-1)
        printf("탐색 실패\n");
    else 
        printf("타겟이 저장된 인덱스: %d\n", index);


    //배열 arr3일 때, 저장되지 않은 정수 3을 찾으라고 명령하기 
    index=BSearch(arr3, sizeof(arr3)/sizeof(int), 3); 
    if(index==-1)
        printf("탐색 실패\n");
    else 
        printf("타겟이 저장된 인덱스: %d\n", index);

    return 0;
}

/*

데이터의 수가 커졌을 때, 순차 탐색 알고리즘의 O(n)과 이진 탐색 알고리즘의 O(log₂n)의 성능비교
순차 탐색은 500,5000,50000이지만,
이진 탐색은 9,13,16이다. 

따라서, 데이터의 수가 많아질수록 O(n)과 O(log₂n)의 성능은 크게 차이난다.

*/