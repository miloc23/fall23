#include "hw1.h"

unsigned int absolute_value(int x)
{
    if (x >= 0)
        return (unsigned int)x;
    else
        return (unsigned int)(-1 * x);
}

unsigned int sum_of_squares(int numbers[], int number_of_numbers)
{
    unsigned int sum = 0;
    
    for (int i = 0; i < number_of_numbers; i++) {
        sum += numbers[i] * numbers[i];
    }
    return sum;
}

int find_biggest(int numbers[], int number_of_numbers, enum odd_or_even o_o_e)
{
    int biggest = INT_MIN;

    for (int i = 0; i < number_of_numbers; i++) {
       if (numbers[i] < biggest)
           continue;
       if (o_o_e == EVEN && absolute_value(numbers[i]) % 2 == 0) 
           biggest = numbers[i];
       else if (o_o_e == ODD && absolute_value(numbers[i]) % 2 == 1)
           biggest = numbers[i];
    }
    return biggest;
}
       


        
