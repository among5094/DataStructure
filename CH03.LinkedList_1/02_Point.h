
// Point.h -> 구조체 Point 선언

#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
    int xpos; //x좌표
    int ypos; //y좌표
}Point;

//Point 변수의 xpos,ypos의 값 설정
void SetPointPos(Point* ppos, int xpos, int ypos);//구조체 변수에 값을 저장하는 함수

//Point 변수의 xpos, ypos 정보 출력
void ShowPointPos(Point* ppos); //이렇게 저장된 값의 정보를 출력하는 함수

// 두 Point 변수의 비교 
int PointComp(Point* pos1, Point* pos2); //두 구조체 변수에 저장된 값을 비교하고 그 결과를 반환하는 함수

#endif