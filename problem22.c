#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int detectAndRemoveLoop(Node *head){
  Node *slow = head, *fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) break;
  }

  if(!fast || !fast->next) return 1;

  slow = head;
  if(slow == fast){
    while(fast->next != slow)
      fast = fast->next;
  }
  else{
    while(slow->next != fast->next){
      slow = slow->next;
      fast = fast->next;
    }
  }

  fast->next = NULL;
  return 1;  
}


void createLoop(Node *head, int pos){
  if(pos <= 0) return;

  Node *loopNode = NULL;
  Node *temp = head;
  int count = 1;

  while(temp->next){
    if(count == pos) loopNode = temp;
    temp = temp->next;
    count++;
  }
  if(loopNode)
    temp->next = loopNode;
}

int main(){
  Node *head = NULL, *tail = NULL;
  char buffer[100];
  int value;

  printf("Enter node values: ");

  while(fgets(buffer, sizeof(buffer), stdin)){
    if(buffer[0] == '\n') break;
    if(sscanf(buffer, "%d", &value) != 1) break;

    Node *newNode = createNode(value);

    if(!head) 
      head = tail = newNode;
    else{
      tail->next = newNode;
      tail = newNode;
    }
  }

  if(!head){
    printf("False\n");
    return 0;
  }

  int pos;
  printf("Position = ");
  scanf("%d", &pos);

  createLoop(head, pos);

  int result = detectAndRemoveLoop(head);
  printf(result ? "true\n" : "false\n");

  return 0;
}
