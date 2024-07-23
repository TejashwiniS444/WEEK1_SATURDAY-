//C PROGRAM TO MERGE TWO LINKED LIST OBJECTS AND RETURN A SINGLE OBJECT
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, m, value;

    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the first linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&list1, value);
    }

    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &m);
    printf("Enter the elements of the second linked list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertAtEnd(&list2, value);
    }

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged and sorted linked list: ");
    printList(mergedList);

    return 0;
}

