#include <stdio.h>
#include <assert.h>
typedef struct dlnode {
    int data;
    struct dlnode *next, *prev;
} dlnode;
typedef struct ndlst {
    dlnode *head, *tail;
    int len;
} ndlst;
void dlistPrint(ndlst* lst) {
    for (dlnode* node = lst->head; node; node = node->next)
        printf("%d ", node->data);
    printf("\n");
}
void dlistPrintReverse(ndlst* lst) {
    for (dlnode* node = lst->tail; node; node = node->prev)
        printf("%d ", node->data);
    printf("\n");
}
ndlst* dlistCreate(void);
void dlistDestroy(ndlst *lst);
int dlistLength(ndlst *lst);
void dlistRemoveElem(ndlst *lst, int n);
void dlistAddToFront(ndlst *lst, int elem);
void dlistAddToEnd(ndlst *lst, int elem);
void dlistSort(ndlst *lst);
void dlistRotateLeft(ndlst *lst, int n);
void dlistRotateRight(ndlst *lst, int n);
int main(void) {
    ndlst* lst1 = dlistCreate();
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 0);
    dlistAddToEnd(lst1, 10);
    dlistAddToFront(lst1, -20);
    dlistAddToFront(lst1, 0);
    dlistAddToEnd(lst1, 9);
    dlistAddToFront(lst1, -9);
    dlistAddToFront(lst1, 7);
    dlistAddToEnd(lst1, 40);
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 7);
    dlistPrint(lst1);
    dlistPrintReverse(lst1);
    dlistRemoveElem(lst1, 5);
    dlistRemoveElem(lst1, 1);
    dlistRemoveElem(lst1, 5);
    dlistAddToEnd(lst1, 100);
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 5);
    dlistPrint(lst1);
    dlistPrintReverse(lst1);
    dlistSort(lst1);
    dlistPrint(lst1);
    dlistRotateLeft(lst1, 2);
    dlistPrint(lst1);
    dlistRotateRight(lst1, 3);
    dlistPrint(lst1);
    dlistDestroy(lst1);
    return 0;
}