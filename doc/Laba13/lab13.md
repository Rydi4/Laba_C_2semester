# Лабораторна робота №13. Строки (Null-terminated C Strings).

### Вимоги:

- Розробник: Руденко Олександр.
- Загальне завдання: Реалізувати програму з використанням строк.
- Идивідуальне завдання: Знайти всі числа, які зустрічаються у тексті.
### Опис програми:

- Функціональне призначення: Сортування цілих чисел у двумерному масиві.

- Опис логічної структури:

  * Функція 'main'. Передає значення строки функції 'check'.
  * Функція 'check'. Знаходить числа у тексті.

 ![block_shema](https://github.com/Rydi4/Laba_C/blob/master/Laba13/doc/assets/Блок-схема.png)
 
- Структура програми:

```
├── dist
│   └── main.bin
├── doc
│   ├── assets
│   │   └── Блок-схема.png
│   └── lab13.md
├── Doxyfile
├── Makefile
├── README.md
└── src
    └── main.c
```

- Код програми:

```
#include <iostream>
#include <locale.h>

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
int main()
{
	setlocale(LC_ALL, "Rus");
	char text[100];
	printf("Текст: ");
	gets_s(text);
	check(text);
	return 0;
}

```

### Висновки:

Навчився працювати з строками.












