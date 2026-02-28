#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* new() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}
int size(struct Node* head) {
    int count = 1;
    for (struct Node* temp = head;temp->next != NULL;temp=temp->next) {
        count++;
    }
    return count;
}
int get(struct Node* head,int index) {
    int count = 0;
    struct Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}
int add(struct Node** head,int data,int index) {
    struct Node* newNode = new();
    newNode->data = data;
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return 0;
    } else {
        struct Node *temp = *head;
        for (int i = 0; i + 1 < index;i++) {
            temp = temp->next;
        }
        struct Node* temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
        return 0;
    }
}
int delete(struct Node** head,int index) {
    if (index == 0) {
        struct Node* head2 = (*head)->next;
        free(*head);
        *head = head2;
        return 0;
    }
    else {
        struct Node* temp = *head;
        for (int i = 0;i + 1 < index; i++) {
            temp = temp->next;
        }
        struct Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        return 0;
    }
}