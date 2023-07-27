#include <stdio.h>
//재귀함수 예제3: 피보나치 수열(앞엣것 두 개 더해서 현재의 수를 만들어가는 수열) 코딩하기
//두 번째 시도 이후부터는 탐색 대상을 찾을 때까지 동일한 패턴을 반복할 뿐이다. 

//피보나치 수열의 n번째 값 반환
int Fibo(int n)
{
    if(n==1) //첫 번째 값
        return 0;
    else if(n == 2)// 두 번째 값
        return 1;
    else //세 번째 이후의 값
        return Fibo(n-1)+Fibo(n-2);
}

int main(void)
{
    int i;
    for(i=1; i<15; i++)
        printf("%d ", Fibo(i));

    return 0;

}