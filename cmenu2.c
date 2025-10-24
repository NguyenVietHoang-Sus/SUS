#include <stdio.h>
#include <stdlib.h> // system("cls");
#include <string.h>
#include <math.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *makeNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Khong du bo nho !");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(node **head, int x) {
    node* newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(node **head, int x){
    node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode; return;
    }
    node* tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int size(node *head) {
    int cnt = 0;
    while(head != NULL) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

int countEven(node *head) {
    int cnt = 0;
    for (node *p = head; p != NULL; p = p->next) {
        if (p->data % 2 == 0 && p->data > 0) cnt++;
    }
    return cnt;
}

double average(node *head) {
    long long sum = 0;
    int cnt = 0;
    for (node *p = head; p != NULL; p = p->next) {
        sum += p->data;
        cnt++;
    }
    return (double)sum / (double)cnt;
}

double averageEven(node *head) {
    long long sum = 0;
    int cnt = 0;
    for (node *p = head; p != NULL; p = p->next) {
        if (p->data % 2 == 0 && p->data > 0) {
            sum += p->data;
            cnt++;
        }
    }
    return (double)sum / (double)cnt;
}

void insert(node **head, int k, int x){
    int n = size(*head);
    if(k < 1 || k > n){
        printf("Vi tri chen khong hop le !\n");
        return;
    }
    if(k == 1){
        pushFront(head, x); return;
    }
    node *temp = *head;
    for(int i = 1; i < k - 1; i++){
        temp = temp->next;
    }
    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

int Prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt((double)n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int countPrime(node *head) {
    int cnt = 0;
    for (node *p = head; p != NULL; p = p->next) {
        if (Prime(p->data))
            cnt++;
    }
    return cnt;
}

int Perfect(int n) {
    if (n <= 0)
        return 0;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            sum += i;
    return sum == n;
}

void listPerfectNumbers(node *head) {
    int found = 0;
    printf("Cac phan tu la so hoan hao trong danh sach: ");
    for (node *p = head; p != NULL; p = p->next) {
        if (Perfect(p->data)) {
            printf("%d ", p->data);
            found = 1;
        }
    }
    if (!found)
        printf("Khong co");
    printf("\n");
}

void deletePrimeNumbers(node **head) {
    node **cur = head;
    while (*cur) {
        if (Prime((*cur)->data)) {
            node *tmp = *cur;
            *cur = (*cur)->next;
            free(tmp);
        } else {
            cur = &(*cur)->next;
        }
    }
}

void checkArithmeticProgression(node *head) {
    int pos = 1;
    int found = 0;
    for (node *p = head; p != NULL && p->next != NULL && p->next->next != NULL; p = p->next) {
        int a = p->data;
        int b = p->next->data;
        int c = p->next->next->data;
        if ((b - a) == (c - b)) {
            printf("Ba phan tu lien ke tai cac vi tri %d, %d, %d lap thanh cap so cong\n", pos, pos + 1, pos + 2);
            found = 1;
        }
        pos++;
    }
    if (!found)
        printf("Khong ton tai ba phan tu lien ke nao lap thanh cap so cong.\n");
}

void sort(node **head){
    for(node *i = *head; i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(j->data < min->data){
                min = j;
            }
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

void printList(node *head) {
    node *temp = head;
    printf("Danh sach hien tai : ");
    while(temp != NULL) {
        printf("%d ", temp->data);\
        temp = temp->next;
    }
    printf("\n");
}

void freeList(node **head) {
    node *p = *head;
    while(p != NULL) {
        node *tmp = p->next;
        free(p);
        p = tmp;
    }
    *head = NULL;
}

void createList(node **head) {
    freeList(head);
    char a[100];
    int x;
    printf("Nhap cac so nguyen ( Nhap # de ket thuc qua trinh nhap ) : ");
    while (1) {
        scanf(" %99s", a);
        if (strcmp(a, "#") == 0) break;
        x = atoi(a);
        pushBack(head, x);
    }
}

int main(){
    node *head = NULL;
    int choice, x, i;
    do {
        system("cls");  // Xoa man hinh

        //Hien thi menu
        printList(head);
        printf("===Menu===\n");
        printf("1.Tao danh sach so\n");
        printf("2.Them 1 phan tu vao dau danh sach\n");
        printf("3.Them 1 phan tu vao cuoi danh sach\n");
        printf("4.Them phan tu vao vi tri thu i ( i duoc nhap tu ban phim )\n");
        printf("5.Dem cac phan tu co gia tri la so chan duong. Tinh trung binh cong cac so\n");
        printf("6.Dem cac so nguyen to xuat hien trong danh sach\n");
        printf("7.Liet ke ra man hinh tat ca cac phan tu la so hoan hao\n");
        printf("8.Xoa tat ca cac so nguyen to trong danh sach\n");
        printf("9.In ra cac vi tri co 3 phan tu dung lien ke nhau lap thanh cap so cong\n");
        printf("10.Sap xep danh sach theo thu tu tang dan(Selection Sort)\n");
        printf("11.Thoat\n");
        printf("Vui long nhap lua chon : ");
        scanf("%d",&choice);    // Nhap lua chon

        switch (choice) {
            case 1 :
                system("cls");
                createList(&head);
                break;
            case 2 :
                system("cls");
                printf("Nhap phan tu can them vao dau danh sach : ");
                scanf("%d", &x);
                pushFront(&head, x);
                printf("Hoan thanh !");
                break;
            case 3 :
                system("cls");
                printf("Nhap phan tu can them vao cuoi danh sach : ");
                scanf("%d", &x);
                pushBack(&head, x);
                printf("Hoan thanh !");
                break;
            case 4 :
                system("cls");
                printf("NHap vi tri can them phan tu vao danh sach : ");
                scanf("%d", &i);
                printf("Nhap phan tu can them vao vi tri thu %d cua danh sach : ", i);
                scanf("%d",&x);
                insert(&head, i, x);
                printf("Hoan thanh !");
                break;
            case 5 :
                system("cls");
                printf("So phan tu chan duong trong danh sach la : %d\n", countEven(head));
                printf("Trung binh cong cac phan tu trong danh sach la : %.4lf\n", average(head));
                printf("Trung binh cong cac phan tu chan duong trong danh sach la : %.4lf\n", averageEven(head));
                break;
            case 6 :
                system("cls");
                printf("So phan tu la so nguyen to xuat hien trong danh sach la : %d\n", countPrime(head));
                break;
            case 7 :
                system("cls");
                listPerfectNumbers(head);
                break;
            case 8 :
                system("cls");
                deletePrimeNumbers(&head);
                printf("Da xoa tat ca so nguyen to trong danh sach.\n");
                break;
            case 9 :
                system("cls");
                checkArithmeticProgression(head);
                break;
            case 10 :
                system("cls");
                sort(&head);
                printf("Da sap xep thanh cong !");
                break;
            case 11 :
                system("cls");
                freeList(&head);
                printf("\nThoat chuong trinh...\n");
                break;
            default :
                system("cls");
                printf("\nLua chon khong hop le ! Vui long thu lai.\n");
        }

        // Pause truoc khi quay tro lai menu
        if (choice != 11) {
            printf("\nNhan phim bat ki de tiep tuc...\n");
            getchar();      // Pause lan 1
            getchar();      // Doi nguoi dung nhan phim
        }
    }while (choice != 11);      // Lap lai cho den khi nguoi dung chon thoat
}
