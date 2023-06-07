#include <stdio.h>
int sumDigitsUsingRecursion(int data)
{
    static int sum = 0;
    if (data == 0)
    {
        return;
    }
    else
    {
        sum += data % 10;
        sumDigitsUsingRecursion(data / 10);
        return sum;
    }
}

void main()
{
    int data;

    printf("Enter an integer: ");
    scanf("%d", &data);

    // sumDigitsUsingRecursion(data);
    printf("Sum of digits: %d\n", sumDigitsUsingRecursion(data));
}