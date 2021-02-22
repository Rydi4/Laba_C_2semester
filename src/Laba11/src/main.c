#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/**
* @file main.c виконати завдання 4
*
* Сортування цілих чисел у двумерному масиві.
*/

/**
* Функція 'compare'. Порівнює елементи масива.
*/
int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);  // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

/**
* @param decrease - одномерный массив с числами из главной диагонали
* @param count - количество аргументов в массиве
*/

/**
* Функція 'orderliness'. Сортурує двумерний масив.
*/
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
/**
* Функція 'main'. Передає значення аргуменів функції 'orderliness'.
*/
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
