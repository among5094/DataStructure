#include <stdio.h>
/*

하노이 타워의 문제 코딩하기(재귀함수의 대표적인 예)
문제를 일반화 한다면?

1단계: 맨 아래의 원반을 제외한 나머지 원반을 A에서 B로 이동
2단계: 제일 아래있는 원반 1개를 A에서 C로 이동
3단계: 1단계에서 옮겨진 원반 n-1개를 B에서 C로 이동
탈출조건: 이동해야 하는 원반의 개수가 1개일 때 <-탈출조건도 반드시 생각해야함

*/

//from에 꽂혀있는 num개의 원반을 by를 거쳐서 to로 이동(from은 A막대, by가 B막대, to가 C막대)
void HanoiTowerMove(int num, char from, char by, char to){

    //재귀함수 탈출조건: 이동해야 할 원반이 1개인 경우
    if(num==1)
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
    else{
        HanoiTowerMove(num-1, from, to, by); //1단계
        printf("원반 %d을(를) %c에서 %c로 이동\n", num, from, to); //2단계
        HanoiTowerMove(num-1, by, from, to); //3단계
    }
    
}

int main(void){
    //막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;

}
