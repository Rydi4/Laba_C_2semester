
#include <iostream>
#include <locale.h>

int сalculating(int number, int i, float calc, int answer) 
{
    calc = number % i;
    if (calc == 0) 
    {
        answer += i;
    }
    else 
    {
        calc = 0;
    }
    printf("%d %d\n", answer, number);
    return answer;
}
int conclusion(int answer, int number) 
{
    if (answer == number) 
    {
        printf("Число совершенное");
    }
    else 
    {
        printf("Число не совершенное");
    }
    return 0;
}
int func1(int number, int i, float calc, int answer) 
{
    if (number > 1) 
    {
        while (i < number) 
        {
            answer = сalculating(number, i, calc, answer);
            i++;
        }
        conclusion(answer, number);
    }
    else 
    {
        printf("Не подходит условию");
    }
    return 0;
}
int func2(int number, int i, float calc, int answer) 
{
    if (number > 1) 
    {
        do 
        {
            answer = сalculating(number, i, calc, answer);
            i++;
        } while (i < number);
        conclusion(answer, number);
    }
    else 
    {
        printf("Не подходит условию");
    }
    return 0;
}
int func3(int number, int i, float calc, int answer) {
    if (number > 1) 
    {
        for (int i = 1; i < number; i++) 
        {
            answer = сalculating(number, i, calc, answer);
        }
        conclusion(answer, number);
    }
    else 
    {
        printf("Не подходит условию");
    }
    return 0;
}
int main() 
{
    setlocale(LC_ALL, "Rus");
    int number;
    int i = 1; // делитель
    float calc = 0; // Результат деления
    int answer = 0;
       printf("Заданное число = ");
       scanf_s("%d", &number);
       func1(number, i, calc, answer);
    return 0;
}