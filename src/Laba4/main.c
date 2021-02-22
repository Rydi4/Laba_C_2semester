#include <iostream>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Rus");
    float x;                // Координата Х
    printf("Координата x = ");
        scanf_s("%f", &x);  

    if (x < -1) {
        printf("Координата y = %f\n", -1/x);   // Находим значение Y = -1/x
    }
    else if (x > -1 && x < 1) {
            printf("Координата y = %.6f\n", pow (x, 2));  // Находим значение Y = x * x
        }
     else if (x = -1 || x >= 1) {
            printf("Координата y = 1 \n");  // Функция Y = 1
    }
    
 return 0;
}