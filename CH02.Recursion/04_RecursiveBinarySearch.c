#include <stdio.h>

//재귀함수 활용: 이진탐색 알고리즘을 재귀함수 기반으로 재구현해보기

int BSearchRecur(int arr[], int first, int last, int target)
{
    int mid;

    //탐색 실패 조건 
    if(first>last)
        return -1; //-1반환은 탐색 실패를 의미
    
    mid=(first+last)/2; //탐색대상의 중앙값 찾기
    
    //중앙값이 타겟값일 때
    if(target==arr[mid])
        return mid;
    else if(target<arr[mid])
        return BSearchRecur(arr,first,mid-1,target);
    else
        return BSearchRecur(arr,first,mid+1,target);

}

int main(void)
{
    int array[]={1,3,5,7,9};
    int idx;

    //타겟값이 7일 때(해당 배열에 있는 값일 때)
    idx=BSearchRecur(array, 0,sizeof(array)/sizeof(int)-1,7);
    
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);


    //타겟값이 4일 때(해당 배열에 없는 값일 때)
    idx=BSearchRecur(array, 0,sizeof(array)/sizeof(int)-1, 4);

    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    return 0;

}