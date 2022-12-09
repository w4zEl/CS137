#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct dlnode{
	int data;
	struct dlnode *next;
	struct dlnode *prev;

} dlnode;

typedef struct {
	dlnode *head;	//points to the first element otherwise NULL
	dlnode *tail;	//points to the last element otherwise NULL
	int len;	// number of elements
} ndlst;

//Pre: None
//Post: Creates a null list
struct ndlst *dlistCreate(void)
{
	ndlst *ret = malloc(sizeof(ndlst));
	ret->head = NULL;
	ret->tail = NULL;
	ret->len = 0;
	return ret;
}

//Pre: lst is a valid list 
//Post: Destroys the list
void dlistDestroy(ndlst *lst)
{
	
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst)
{
	return lst->len;
}

//Pre: lst is a valid list with length of at least n>=1
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n)
{
	
}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem)
{
	
}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem)
{
	
}

//Pre: lst is valid
//prints the items in the list from start to end.
// Do not submit
void dlistPrint(ndlst *lst)
{
	dlnode *node = lst->head;
	// iterate over the nodes (items) until node is NULL 
	// and print the data
	for (; node; node = node->next)
		printf("%d  ", node->data);
	printf("\n");
}


//Do not submit
void dlistPrintReverse(ndlst *lst)
{
	dlnode *node = lst->tail;
	// iterate over the nodes (items) until node is NULL 
	// and print the data
	for (; node; node = node->prev)
		printf("%d  ", node->data);
	printf("\n");
}


// lst is a valid list to be sorted in ascending order
void dlistSort(ndlst *lst)
{
	
}

// rotate the list n times to the left, assume, lst not empty
void dlistRotateLeft(ndlst *lst, int n)
{
	
}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n)
{
	
}

int main(void)
{
	ndlst *lst1 = dlistCreate();
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

     // should add more tests
	return 0;
}
