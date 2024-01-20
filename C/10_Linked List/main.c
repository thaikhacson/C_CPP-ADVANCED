#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct Node{
  int data;
  struct Node* next;   
}Node;

Node* createNode(int data) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void push_back(Node** head, int data) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;

  if (*head == NULL) {
    *head = temp;
    return;
  }

  Node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = temp;
}

void push_front(Node** head, int data) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  if(*head != NULL) {
    temp->next = *head;
  }
  *head = temp;
}

void pop_back(Node** head) {
  Node* temp1 = *head;

  if(temp1 == NULL) {
    printf("Error: List empty!\n");
    return;
  }

  if(temp1->next == NULL) {
    free(temp1);
    *head = NULL;
    return;
  }

  Node* temp2 = NULL;

  while(temp1->next != NULL) {
    temp2 = temp1;
    temp1 = temp1->next;
  }
  temp2->next = NULL;
  free(temp1);
}

void pop_front(Node** head) {
  Node* temp = *head;

  if(temp == NULL) {
    printf("Error: List empty!\n");
    return;
  }

  *head = temp->next;
  free(temp);
}

int front(Node** head) {
  Node* temp = *head;

  if(temp == NULL) {
    printf("Error: List empty!\n");
    return 0;
  }

  return temp->data;
}

int back(Node** head) {
  Node* temp = *head;

  if(temp == NULL) {
    printf("Error: List empty!\n");
    return 0;
  }

  while(temp->next != NULL) {
    temp = temp->next;
  }

  return temp->data;
}

void insert(Node** head, int data, int n) {
  Node *temp1 = (Node*)malloc(sizeof(Node));
  temp1->data = data;
  temp1->next = NULL;
  if(n == 1) {
    temp1->next = *head;
    *head = temp1;
    return;
  }
  Node* temp2 = *head;
  for(int i = 0; i < n - 2; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void delete(Node** head, int pos) {
  Node* temp1 = *head;

  if(pos == 1) {
    *head = temp1->next;
    free(temp1);
    return;
  }

  for(int i = 0; i < pos - 2; i++) {
    temp1 = temp1->next;
  }

  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
}

int size(Node** head) {
  Node* temp = *head;
  int count = 0;

  while(temp != NULL) {
    count++;
    temp = temp->next; 
  }

  return count;
}

int get(Node** head, int pos) {
  Node* temp = *head;

  if(pos > size(head)) {
    printf("Error: List has less element!");
    return 0;
  }

  if(temp == NULL) {
    printf("Error: List empty!");
    return 0;
  }

  if(pos == 1) {
    return temp->data;
  }

  for(int i = 0; i < pos - 1; i++) {
    temp = temp->next;
  }

  return temp->data;
}

bool empty(Node** head) {
  if((*head) == NULL) {
    printf("Error: List empty!");
    return true;
  } 

  return false;
}

void reverse(Node** head) {
    Node *curr, *prev, *next;
    curr = *head;
    prev = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }
    *head = prev;
}

void print(Node* head) {
  if(head == NULL) return;
  printf("%d ", head->data);
  print(head->next);
}

int main() {
    Node* head = NULL;

    push_front(&head, 7);
    push_back(&head, 9);
    push_back(&head, 8);
    push_front(&head, 5);
    insert(&head, 10, 3);
    printf("Linked List: ");
    print(head);
    reverse(&head);
    printf("\nLinked List New: ");
    print(head);
  return 0;
}


