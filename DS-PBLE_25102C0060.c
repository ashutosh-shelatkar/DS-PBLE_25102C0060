#include <stdio.h>
#include <string.h>

#define MAX 20

struct Patient {
    int id;
    char name[50];
};

struct Patient queue[MAX];
int front = -1, rear = -1;


void enqueue() {
    if (rear == MAX - 1) {
        printf("\nQueue is FULL (No more patients can be added)\n");
        return;
    }

    struct Patient p;
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Patient Name: ");
    scanf("%s", p.name);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = p;

    printf("Patient added successfully.\n");
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is EMPTY (No patients waiting)\n");
        return;
    }

    printf("\nPatient Treated:\n");
    printf("ID: %d\nName: %s\n", queue[front].id, queue[front].name);

    front++;
}


void display() {
    if (front == -1 || front > rear) {
        printf("\nNo patients in waiting list.\n");
        return;
    }
	
	int i;
    printf("\nWaiting Patients:\n");
    	for (i = front; i <= rear; i++) {
        printf("ID: %d | Name: %s\n", queue[i].id, queue[i].name);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Hospital Patient Record System ---\n");
        printf("1. Add Patient\n2. Treat Patient\n3. Display Patients\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
