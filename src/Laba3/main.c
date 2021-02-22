#include <iostream>
#include <locale.h>


int change_number_system(int number, int number_system, int degree);

void main() {
    setlocale(LC_ALL, "Rus");

    int number;
    int number_system = 8;
    int degree = 0;

    printf("Введите число: ");
    scanf_s("%d", &number);

    printf("В восьмеричной: %d\n", number);

    change_number_system(number, number_system, degree);
    

}
int change_number_system(int number, int number_system, int degree) {
        
    int result = 0;

    while (number > 0) {

       result += number % 10 * pow(number_system, degree);
       degree++;
       number /= 10; // Убираем последнее число 

     }

       printf("В десятичной: %d", result);

       return result;
    }

   