#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

char CQ[SIZE];
int front = -1, rear = -1;
int ch;

void CQ_Insert();
void CQ_Delet();
void CQ_Display();

void main() {
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1) {
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                CQ_Insert();
                break;
            case 2:
                CQ_Delet();
                break;
            case 3:
                CQ_Display();
                break;
            case 4:
                exit(0);
        }
    }
}

void CQ_Insert() {
    char ele;
    if (front == (rear + 1) % SIZE) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (front == -1)
        front++;
    printf("\nEnter the element to be inserted\n");
    scanf("\n%c", &ele);
    rear = (rear + 1) % SIZE;
    CQ[rear] = ele;
}

void CQ_Delet() {
    char item;
    if (front == -1) {
        printf("Circular Queue Underflow\n");
        return;
    } else if (front == rear) {
        item = CQ[front];
        printf("Deleted element is: %c\n", item);
        front = -1;
        rear = -1;
    } else {
        item = CQ[front];
        printf("Deleted element is: %c\n", item);
        front = (front + 1) % SIZE;
    }
}

void CQ_Display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is Empty\n");
    } else {
        printf("Elements of the circular queue are..\n");
        for (i = front; i <= rear; i = (i + 1) % SIZE) {
            printf("%c\t", CQ[i]);
        }
    }
}
