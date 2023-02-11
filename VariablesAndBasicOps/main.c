#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char name[] = "Numcy";
    float valueOne;
    float valueTwo;
    float answer;
    char op;
    printf("Welcome! My name is %s and I will be your friendly calculator today.\nPlease enter your operation:", name);
    scanf("%f %c %f", &valueOne, &op, &valueTwo);
    //printf("This -> \" <- is how we render special characters.");
    switch(op)
    {
    case '/':
        if (valueTwo == 0)
        {
        printf("You cannot divide by zero!!\n");
        goto fail;
        }
        answer = valueOne/valueTwo;
        break;
    case '*':
        answer = valueOne*valueTwo;
        break;
    case '+':
        answer = valueOne+valueTwo;
        break;
    case '-':
        answer = valueOne-valueTwo;
        break;
    case '^':
        answer = pow(valueOne,valueTwo);
        break;
    default:
        goto fail;
    }
    printf("%.9g %c %.9g = %.6g\n", valueOne, op, valueTwo, answer);
    return 0;

    fail:
        printf("Epic fail.\n");
        exit(EXIT_FAILURE);
}
