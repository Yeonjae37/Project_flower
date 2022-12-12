#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//재고 저장 구조체 선언
typedef struct _item {
    char name[30];
    int stock;
    int price;
    struct _item* next;
}Item;

Item* head; //재고 저장 헤드 노드
int numOfData = 0; //재고 개수
int cart[100] = { 0, }; //카트 배열 최대 100;
int money; //사용자 입력 소지 돈

//연결리스트 초기화 함수
void init() {
    head = (Item*)malloc(sizeof(Item));
    head->next = NULL;
}
