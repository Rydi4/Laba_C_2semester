# Лабораторна робота №11. Вступ до показчиків.

### Вимоги:

- Розробник: Руденко Олександр.
- Загальне завдання: Реалізувати програму з використанням показчиків.
- Идивідуальне завдання: Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням.
### Опис програми:

- Функціональне призначення: Сортування цілих чисел у двумерному масиві.

- Опис логічної структури:

  * Функція 'main'. Передає значення аргуменів функції 'orderliness'.
  * Функція 'orderliness'. Сортурує двумерний масив.
  * Функція 'compare'. Порівнює елементи масива.

 ![block_shema](https://github.com/Rydi4/Laba_C/blob/master/Laba11/doc/assets/Блок-схема.png)
 
- Структура програми:

```
├── dist
│   └── main.bin
├── doc
│   ├── assets
│   │   └── Блок-схема.png
│   └── lab11.md
├── Doxyfile
├── Makefile
├── README.md
└── src
    └── main.c
```

- Код програми:

```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);  // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
int orderliness(int number[4][4])   
{
    int i;  
    int decrease[(int)sizeof(number)];
    int count = (int)sizeof(number);
    for (i = 0; i < count; i++) 
    {
        decrease[i] = number[i][i];
    }
    qsort(decrease, count, sizeof(int), compare);   // сортируем массив чисел
    for (int ix = 0; ix < count; ix++)
        printf("%d ", decrease[ix]);
        return 0;
}
int main()
{
    int number[4][4] = {
        {16, 58, 49, 36},
        {3, 25, 48, 25},
        {18, 32, 6, 56},
        {23, 54, 48, 5}
    };
    orderliness(number);
    return 0;
}

```

### Висновки:

Навчився використовувати показчики.












