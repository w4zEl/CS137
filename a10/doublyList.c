#include <stdlib.h>
typedef struct dlnode {
    int data;
    struct dlnode *next, *prev;
} dlnode;
typedef struct ndlst {
    dlnode *head, *tail;
    int len;
} ndlst;
ndlst* dlistCreate(void) {
    return calloc(1, sizeof(ndlst));
}
void dlistDestroy(ndlst *lst) {
    for (dlnode *curr = lst->head, *next; curr; curr = next) next = curr->next, free(curr);
    free(lst);
}
int dlistLength(ndlst *lst) {
    return lst->len;
}
static void link(dlnode *n1, dlnode *n2) {
    if (n1) n1->next = n2;
    if (n2) n2->prev = n1;
}
void dlistRemoveElem(ndlst *lst, int n) {
    dlnode *target = lst->head;
    while (--n) target = target->next;
    link(target->prev, target->next);
    if (!target->prev) lst->head = target->next;
    if (!target->next) lst->tail = target->prev;
    free(target);
    --lst->len;
}
void dlistAddToFront(ndlst *lst, int elem) {
    dlnode *d = calloc(1, sizeof *d);
    d->data = elem;
    link(d, lst->head);
    lst->head = d;
    if(!lst->len++) lst->tail = d;
}
void dlistAddToEnd(ndlst *lst, int elem) {
    dlnode *d = calloc(1, sizeof *d);
    d->data = elem;
    link(lst->tail, d);
    lst->tail = d;
    if(!lst->len++) lst->head = d;
}
void dlistSort(ndlst *lst) {
    for (int i = 1, t; i < lst->len; ++i)
        for (dlnode *n = lst->head; n->next; n = n->next)
            if (n->data > n->next->data) t = n->data, n->data = n->next->data, n->next->data = t;
}
void dlistRotateLeft(ndlst *lst, int n) {
    while (n--) dlistAddToEnd(lst, lst->head->data), dlistRemoveElem(lst, 1);
}
void dlistRotateRight(ndlst *lst, int n) {
    dlistRotateLeft(lst, lst->len - n % lst->len);
}