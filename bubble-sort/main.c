#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100    
#define MIN 1        
#define MAX 10000    

int generate_random_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    srand(time(NULL));
    
    int numbers[SIZE]; 

    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = generate_random_number(MIN, MAX);
    }

    for (int i = 0; i < SIZE - 1; i++)
    {
        int swapped = 0; 

        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }

    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
        if ((i + 1) % 10 == 0) 
        {
            printf("\n");
        }
    }

    return 0;
}