#include <locale.h>
#include <iostream>
#include <stdarg.h>м

/**
* @file main.c виконати завдання 4
*
* порівняти пари чисел у котрих перше число менше наступного
*/

/**
* виконати завдання за допомогою функції з вариативною кількістю аргументів
* @param answer - відповідь;
* @param number1 - перше число;
* @param numer2 - друге число;
*/

/**
 Функція 'comparison_of_numbers'. Порівнює пари чисел.
*/

int comparison_of_numbers(int num, ...)
{
    va_list calculation;
	int answer = 0; 
	int number1 = 0; 
	int number2 = 0; 
	if (num % 2 != 0)
	{
		num--;
	}
	va_start(calculation, num); 
	for (int i = 0; i < num; i++) 
	{
		if (i % 2 == 0)
		{
			number1 = va_arg(calculation, int);
		}
		else
		{
			number2 = va_arg(calculation, int);
		}
		if (number1 < number2 && number2 != 0) 
		{
			answer++;
		}
			number2 = 0;
	}
	va_end(calculation); 
	printf("%d\n", answer);
	return 0;
}
/**
 Функція main: Передає значення аргуменів функції 'comparison_of_numbers'.
*/
int main()
{
	comparison_of_numbers(3, 29, 48, 36); 
	comparison_of_numbers(5, -89, 56, 25, -48, 36);
	comparison_of_numbers(2, 23, 56);

}
