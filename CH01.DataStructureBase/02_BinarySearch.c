//이진 탐색(Binary Search)구현과 "시간복잡도"계산
//조건: 정렬된 상태라는 가정이 있어야 한다. 
#include <Stdio.h>

int BSearch(int arr[], int len, int target)//target==탐색대상
{
    int first=0;    //target의 시작 인덱스 값
    int last=len-1; //target의 마지막 인덱스 값
    int mid;


    while(first<=last)
    {
        //탐색의 중앙값 찾기
        mid=(first+last)/2;

        //중앙에 저장된 데이터가 target이라면?
        if(target==arr[mid])
            return mid; // ->탐색완료
        else
        {

            if(target<arr[mid])
                last = mid-1; //target이 mid를 기준으로 왼쪽에 있고
            else
                first=mid+1; //target이 mid를 기준으로 오른쪽에 있다는 뜻이니까
            
            //last=mid-1과 first=mid+1을 하는 이유 2가지 
            //1. mid의 탐색대상이 저장되어 있는지에 대한 검사는 위에서 끝났기 때문에 불필요한 데이터는 넣지 않는다.
            //2. while문의 종료조건 first>last를 위해서
        }

    }//while문

    return -1; //탐색 실패를 의미하는 값 -1
}

int main(void)
{
    int arr[]={1,3,5,7,9}; //정렬된 상태라는 가정이 있어야됨
    int index;

    //target=7일 때 (탐색대상이 배열에 존재할 때)
    index=BSearch(arr, sizeof(arr)/sizeof(int), 7); 

    if(index==-1) printf("탐색 실패\n");
    else printf("타겟이 저장된 인덱스: %d\n", index);
    
    //target=4일 때 (탐색대상이 배열에 존재하지 않을 때)
    index=BSearch(arr, sizeof(arr)/sizeof(int), 4); 

    if(index==-1) printf("탐색 실패\n");
    else printf("타겟이 저장된 인덱스: %d\n", index);

    return 0;
}

/*
이진 탐색 알고리즘의 최악의 경우 시간복잡도 계산하기

첫 번째: n
두 번째: n/2
세 번째: n/4
네 번째: n/8
...
마지막 연산1일 때

비교횟수를 k라고 할 때,
여기까지 생각하면 T(n)= k+1
n*(1/2)^k=1이니까 식을 풀면 n*(2^-k)=1이라면 n=2^k가 된다. 
양쪽에 밑이 2인 로그를 취하면 log₂n=log₂2^k니까 log₂n=k가 된다. 

∴ T(n)= log₂n
+1은 별로 중요하지 않다. 시간복잡도를 구하는 이유는 데이터 수가 증가함에 따른 연산횟수의 변화를 파악하는 것이기 때문에
중요한 것은 n∝log₂n이라는 사실이다. 

*/
