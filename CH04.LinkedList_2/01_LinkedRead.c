#include <stdio.h>
#include <stdlib.h>
//연결리스트 구현

// 연결 리스트 구조체
typedef struct _node{
    int data;
    struct _node* next;
}Node;

int main(void){

    //초기화
    Node* head=NULL;
    Node* tail=NULL;
    Node* cur=NULL;

    Node* newNode=NULL;
    int readData;

    //데이터 입력받기
    while(1){
        printf("자연수 입력: ");
        scanf("%d", &readData);
        
        //데이터가 0이하이면 종료
        if(readData<1) break;

        //노드 추가과정
        newNode=(Node*)malloc(sizeof(Node)); //동적할당
        newNode->data=readData;
        newNode->next=NULL;

        if(head==NULL)
            head=newNode;
        else
            tail->next=newNode;
        
        tail=newNode;
    }//while닫기
    printf("\n");


    //입력받은 데이터의 출력과정 
    printf("입력 받은 데이터의 전체 출력!\n");
    
    if(head==NULL)
        printf("저장된 자연수가 존재하지 않습니다. \n");
    else{
        cur=head;
        printf("%d ", cur->data); //첫 번째 출력데이터

        //두 번째 이후 데이터 출력
        while(cur->next != NULL){
            cur = cur->next;
            printf("%d ", cur->data);

        }
    }
    printf("\n\n");


    //메모리 해제
    if(head==NULL)
        return 0;
    else{
        Node* delNode=head;
        Node* delNextNode=head->next;

        printf("%d을(를) 삭제합니다.\n", head->data);
        free(delNode); //첫 번째 노드 삭제 
        
        while(delNextNode != NULL){
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }
    return 0;
}