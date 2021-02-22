#include <iostream>
#include <locale.h>
/**
* @file main.c виконати завдання 4
*
* Знаходження чисел у тексті
*/

/**
* Функція 'check'. Знаходить числа у тексті.
*/

int check(char text[100]) 
{
	for (int i = 0; i < strlen(text); i++) 
	{
		if (isdigit(text[i]) != 0)
		{
			printf("%c ", text[i]);
		}
	}
	return 0;
}

/**
* Функція 'main'. Передає значення строки функції 'check'.
*/

int main()
{
	setlocale(LC_ALL, "Rus");
	char text[100];
	printf("Текст: ");
	gets_s(text);
	check(text);
	return 0;
}
