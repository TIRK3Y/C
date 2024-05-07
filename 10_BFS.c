#include <stdio.h>

#define SIZE 10

struct node
{
    int data;
    int data_2;
};

struct node hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int data)
{
    int key = hashFunction(data);
    int i = 0;
    
    // Perform linear probing until an empty slot is found or a collision occurs.
    while(hashTable[(key + i) % SIZE].data_2 == 1) 
    {
        // Check for a collision.
        if(hashTable[(key + i) % SIZE].data == data) 
        {
            printf("\nCollision! %d already exists in the hash table\n", data);
            return;
        }
        i++;
    }

    // Insert data into the next available slot.
    hashTable[(key + i) % SIZE].data = data;
    hashTable[(key + i) % SIZE].data_2 = 1;
    printf("\n%d inserted at slot %d\n", data, (key + i) % SIZE);
}

void search(int data)
{
    int key = hashFunction(data);
    int i = 0;
    
    // Perform linear probing until the data is found or an empty slot is encountered.
    while(hashTable[(key + i) % SIZE].data_2 == 1) 
    {
        if(hashTable[(key + i) % SIZE].data == data) 
        {
            printf("\n%d found at slot %d\n", data, (key + i) % SIZE);
            return;
        }
        i++;
    }
    // Data item not found.
    printf("\n%d not found\n", data);
}

int main() 
{
    int choice, data;

    for(int i = 0; i < SIZE; i++)
	{
        hashTable[i].data_2 = 0;
    }

    do
	{
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
		{
            case 1: printf("\nEnter the data to insert: ");
                    scanf("%d", &data);
                    insert(data);
                    break;

            case 2: printf("\nEnter the data to search: ");
                    scanf("%d", &data);
                    search(data);
                    break;

            case 3: printf("\nExiting...\n");
                    printf("\n");
                    break;

            default: printf("\nInvalid choice!, Re-enter again.\n");
                     break;
        }
    } 
	while(choice != 3);

    return 0;
}