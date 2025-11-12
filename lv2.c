#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct OE_ {
    int x;
    struct OE_ *sljedeci;
} OE_;




void gen(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
}

OE_* createNode(int value) {
    OE_* newNode = (OE_*)malloc(sizeof(OE_));
    newNode->x = value;
    newNode->sljedeci = NULL;
    return newNode;
}

OE_* createList(int v[], int n) {
    if (n <= 0) return NULL;

    OE_* headNode = createNode(v[0]);
    OE_* currentNode = headNode;

    for (int i = 1; i < n; i++) {
        currentNode->sljedeci = createNode(v[i]);
        currentNode = currentNode->sljedeci;
    }

    return headNode;
}

int linArr(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x)
            return 1;
    }
    return -1;
}

int linList(OE_* node, int x) {
    while (node != NULL) {
        if (node->x == x)
            return 1;
        node = node->sljedeci;
    }
    return -1;
}


void freeList(OE_* head) {
    OE_* temp;
    while (head != NULL) {
        temp = head;          // zapamti trenutni čvor
        head = head->sljedeci; // idi na sljedeći
        free(temp);           // oslobodi trenutni
    }
}


int main() {
    int n, x;
    clock_t t1, t2, t3, t4, t5, t6, t7, t8;

    srand(time(NULL));
    printf("Unesite n: ");
    scanf("%d", &n);

    int v[n];

    t1 = clock();
    gen(v, n);
    t2 = clock();

    printf("Generirani niz:\n");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");

    t3 = clock();
    OE_* headNode = createList(v, n);
    t4 = clock();

    printf("Unesite broj za pretragu: ");
    scanf("%d", &x);

    t5 = clock();
    int valueArr = linArr(v, n, x);
    t6 = clock();

    t7 = clock();
    int valueList = linList(headNode, x);
    t8 = clock();

    if (valueArr == 1 && valueList == 1)
        printf("Ima vrijednosti\n");
    else
        printf("Nema vrijednosti\n");

    printf("Vrijeme stvaranja niza: %.3f ms\n", (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC);
    printf("Vrijeme stvaranja liste: %.3f ms\n", (double)(t4 - t3) * 1000 / CLOCKS_PER_SEC);
    printf("Vrijeme pretrage niza: %.3f ms\n", (double)(t6 - t5) * 1000 / CLOCKS_PER_SEC);
    printf("Vrijeme pretrage liste: %.3f ms\n", (double)(t8 - t7) * 1000 / CLOCKS_PER_SEC);

    freeList(headNode);
    return 0;
}

