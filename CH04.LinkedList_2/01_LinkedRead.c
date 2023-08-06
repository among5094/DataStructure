#include <stdio.h>
#include <stdlib.h>
//연결리스트 구현

// 연결 리스트 구조체
typedef struct _node{
    int data;
    struct _node* next;
}Node;

int main(void){

    //초기화 - 구조체 Node의 포인터 변수 head와 tail이 각각 NULL을 가리키고 있다. 
    /*  head -> NULL
        tail -> NULL 이 상태임 */
    Node* head=NULL; //리스트의 머리를 가리키는 포인터 변수
    Node* tail=NULL; //리스트의 꼬리를 가리키는 포인터 변수
    Node* cur=NULL; //저장된 데이터의 조회에 사용되는 포인터 변수

    Node* newNode=NULL;
    int readData;

    //데이터 입력받기
    while(1){
        printf("자연수 입력: ");
        scanf("%d", &readData);
        
        //데이터가 0이하이면 종료
        if(readData<1) break;

        //노드 추가과정
        newNode=(Node*)malloc(sizeof(Node)); //노드(바구니) 생성
        newNode->data=readData; //노드에 데이터 저장
        newNode->next=NULL; //노드의 next를 NULL로 초기화

        // 첫 번째 노드라면?
        if(head==NULL)
            head=newNode; // 첫 번째 노드를 head가 가리키게 함
        else // 두 번째 이후 노드라면?
            tail->next=newNode;
        
        tail=newNode; //노드의 끝을 tail이 가리키게 함.
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