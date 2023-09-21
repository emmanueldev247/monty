#include<stdio.h>
#include<stdlib.h>
#define LIMIT 10

/* Global declaration of variables */
int cqueue[LIMIT];
int choice, item, count;
int front, rear;

void insert(); // Function to insert the element in the queue
void delet(); // Function to delete the element in the queue
void display(); // Function to display the element in the queue

int main()
{
	printf("Welcome to DataFlair tutorials!\n\n");
	printf ("ARRAY IMPLEMENTATION OF QUEUES\n\n");
	count =0;
	front = rear = -1; // It indicates the queue is empty

	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Sorry, invalid choice!\n");
				break;
		}
	} while(choice!=4);
	return 0;
}

void insert()
{
	 if (count == LIMIT) {
        printf("Queue Overflow\n");
        return;
    }

	if((front == 0 && rear == LIMIT-1) || (front == rear+1))
	{
		printf("Queue Overflow\n");
	}

	if (front == -1)  //If the queue is empty
	{
		front = rear = 0;
	}
	printf("Enter the element to be inserted in queue: ");
	scanf("%d", &item);
	cqueue[rear] = item ;

	if(rear == LIMIT-1) // When rear is at the last position of the queue
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	count++;
}

void delet()
{
	if (count == 0) {
        printf("Queue Underflow\n");
        return;
    }

if (front == -1)
{
printf("Queue Underflow\n");
}
if(front!= -1)
printf("Element deleted from queue is : %d\n",cqueue[front]);
if(front == rear) /* queue has only one element */
{
front = rear = -1;
}
else
{
if(front == LIMIT-1)
{
front = 0;
}
else
front++;
}
 count--;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("The elements of the queue are:\n");

    int i = front;

    if (front <= rear)
    {
        while (i <= rear)
        {
            printf("%d >> %d\n", i, cqueue[i]);
            i++;
        }
    }
    else
    {
        while (i <= LIMIT - 1)
        {
            printf("%d\n", cqueue[i]);
            i++;
        }

        i = 0;
        while (i <= rear)
        {
            printf("%d\n", cqueue[i]);
            i++;
        }
    }
}

