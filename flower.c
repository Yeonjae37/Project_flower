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

//상품 등록 주요 기능 함수
void append(char name[30], int stock, int price) {
    //연결리스트 append 원리로 작동
    Item* newItem = (Item*)malloc(sizeof(Item));
    Item* cur = head;
    strcpy(newItem->name, name);
    newItem->stock = stock;
    newItem->price = price;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    newItem->next = cur->next;
    cur->next = newItem;
    numOfData++;
}

//파일로부터 데이터 불러오는 함수
void load_data() {
    char name[30];
    int stock, price;
    FILE* fp = fopen("Data.txt", "r");
    //Data.txt파일로부터 한줄씩 데이터를 읽고 append함수 호출
    while (!feof(fp)) {
        fscanf(fp, "%s %d %d\n", name, &stock, &price);
        append(name, stock, price);
    }
    fclose(fp);
}

//상품 삭제 주요 기능 함수
void delete(char name[30]) {
    Item* cur = head->next;
    Item* prev = head;
    //while문을 통해 name과 동일한 이름의 상품 탐색
    while (cur->next != NULL && strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }
    //찾지 못했다면 오류문구 출력
    if (strcmp(cur->name, name) != 0) {
        printf("\n\n%s가 목록에 없습니다.\n\n", name);
    }
    //찾았다면 삭제
    else {
        prev->next = cur->next;
        free(cur);
        printf("\n\n삭제가 완료되었습니다.\n\n");
    }
}

//상품 수정 주요 기능 함수
void edit(char from_name[30], char to_name[30]) {
    //Delete랑 똑같은 원리로 작동
    Item* cur = head->next;
    while (cur->next != NULL && strcmp(cur->name, from_name) != 0) {
        cur = cur->next;
    }
    if (strcmp(cur->name, from_name) != 0) {
        printf("\n\n%s가 목록에 없습니다.\n\n", from_name);
    }
    //찾았을경우 해당 정보 수정
    else {
        strcpy(cur->name, to_name);
        printf("\n\n수정이 완료되었습니다.\n\n");
    }

}

//재고 현황 출력 함수
void show_stock() {
    Item* cur = head->next;
    printf("\n\n");
    //연결리스트 끝까지가면서 전부 출력
    while (cur != NULL) {
        printf("%-10s %-4d개\t각%-4d원\n", cur->name, cur->stock, cur->price);
        cur = cur->next;
    }
    printf("\n\n");
}
//상품 등록 함수
void register_item() {
    char name[30];
    int stock;
    int price;
    char op;

    //상품 정보 입력
    show_stock();
    printf("꽃 이름과 수량을 입력하세요<취소:0>\n\n");
    printf("꽃 이름: ");
    scanf("%s", name);
    if (strcmp(name, "0") == 0)
        return;
    printf("\n수 량: ");
    scanf("%d", &stock);
    printf("\n가 격: ");
    scanf("%d", &price);
    printf("\n정말로 상품을 등록 하시겠습니까? (y/n): ");
    getchar();
    op = getchar();
    if (op == 'n')
        return;
    //y입력시 등록
    else if (op == 'y') {
        append(name, stock, price);
        printf("\n정상적으로 등록되었습니다.\n\n");
        printf("\n\n");
    }
}

//상품 삭제 함수
void delete_item() {
    char name[30];
    char op;
    //삭제할 상품명 입력
    show_stock();
    printf("삭제하실 꽃의 이름을 입력하세요<취소:0>\n\n");
    printf("상품명: ");
    scanf("%s", name);
    if (strcmp(name, "0") == 0)
        return;
    printf("\n\n%s 를 정말로 삭제합니까?(y/n): ", name);
    getchar();
    op = getchar();
    if (op == 'n')
        return;
    //y입력시 삭제
    else if (op == 'y') {
        delete(name);
        printf("\n\n");
    }
}

//상품관리 페이지
void item_manage() {
    int op;
    while (1) {
        system("cls");
        print_item_menu();
        scanf("%d", &op);
        if (op == 1) {
            register_item();
        }
        else if (op == 2) {
            delete_item();
        }
        else if (op == 3) {
            printf("\n\n-- 재고 현황 입니다 --\n\n");
            show_stock();
            printf("\n\n");
        }
        else if (op == 4) {
            break;
        }
    }
}

//파일 저장 기능
void save() {
    FILE* fp = fopen("Data.txt", "w");
    Item* cur = head->next;
    //연결리스트를 끝까지 돌면서 내용 저장
    while (cur->next != NULL) {
        fprintf(fp, "%s %d %d\n", cur->name, cur->stock, cur->price);
        cur = cur->next;
    }
    fprintf(fp, "%s %d %d\n", cur->name, cur->stock, cur->price);
    fclose(fp);
}

//관리자 페이지로 이동
void admin_menu_page() {
    int op;
    while (1) {
        system("cls");
        print_admin_menu();
        scanf("%d", &op);
        if (op == 1) {
            item_manage();
        }
        else if (op == 2) {
            printf("\n\n-- 재고 현황 입니다 --\n\n");
            show_stock();
            printf("\n\n");
        }
        else if (op == 3) {
            break;
        }
    }
}