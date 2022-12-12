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

//메인메뉴 출력 함수
void print_menus() {
    printf("\n\t     꽃집\n");
    printf("============================\n");
    printf("\t1. 관리자 메뉴\n");
    printf("\t2. 구매자 메뉴\n");
    printf("\t3. 프로그램 종료\n");
    printf("============================\n");
    printf("\n>>>원하시는 메뉴 숫자를 입력하세요: ");
}

//관리자메뉴 출력 함수
void print_admin_menu() {
    printf("\n\t관리자 메뉴\n");
    printf("============================\n");
    printf("\t1. 꽃 관리\n");
    printf("\t2. 꽃 재고 현황\n");
    printf("\t3. 메인 메뉴\n");
    printf("============================\n");
    printf("\n>>>원하시는 메뉴 숫자를 입력하세요: ");
}

//상품관리메뉴 출력 함수
void print_item_menu() {
    printf("\n\t꽃 관리 메뉴\n");
    printf("============================\n");
    printf("\t1. 꽃 등록\n");
    printf("\t2. 꽃 삭제\n");
    printf("\t3. 꽃 재고 현황\n");
    printf("\t4. 관리자 메뉴\n");
    printf("============================\n");
    printf("\n>>>원하시는 메뉴 숫자를 입력하세요: ");
}

//사용자 메뉴 출력 함수
void print_user_menu() {
    printf("\n\t사용자 메뉴\n");
    printf("============================\n");
    printf("\t1. 꽃다발에 꽃 추가\n");
    printf("\t2. 꽃다발 삭제\n");;
    printf("\t3. 꽃다발 목록 조회\n");
    printf("\t4. 결제\n");
    printf("============================\n");
    printf("\n>>>원하시는 메뉴 숫자를 입력하세요: ");
}
