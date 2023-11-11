/*
    Nombre del archivo: Practica4.c
    Autor: Lizeth Barrios Retana
    Fecha de creación: 20 de septiembre de 2023
    Descripción: programa que contiene un menu donde hay 3 opciones: uno que hace los numero de fibonacci sin recursion, fibonacci con recursion y el triangulo de pascal.
*/
#include <stdio.h>
#include "BRL.h"

int calcularFibonacciRecursion(int num);
void calcularFibonacci(int num);
int Coeficiente(int n, int k);
void generarTrianguloPascal(int num);

int main()
{
    int op;
    int menu = 0;
    int num;

    do
    {
        op = validarnumeros("\nQue actividad desea hacer?\n1. Fibonacci sin recursion\n2. Fibonacci con recursion\n3. Triangulo de Pascal\n4. Salir\n", 1, 4);
        switch (op)
        {
        case 1:
            num = validarnumeros("Ingresa la posicion del numero de la serie de Fibonacci que deseas conocer: ", 0, 100000000);
            calcularFibonacci(num);
            menu = 1;
            break;
        case 2:
            num = validarnumeros("Ingresa la posicion del numero de la serie de Fibonacci que deseas conocer: ", 0, 100000000);
            for (int i = 1; i <= num; i++)
            {
                printf("%d ", calcularFibonacciRecursion(i));
            }
            printf("\n");
            menu = 1;
            break;
        case 3:
            num = validarnumeros("Ingrese el numero de filas del Triangulo de Pascal: ", 0, 100000000);
            generarTrianguloPascal(num);
            menu = 1;
            break;
        case 4:
            system("cls");
            printf("FIN DEL PROGRAMA");

            return 0;
            break;
        }
    } while (menu);
}

/*
   Función: calcularFibonacci
   Descripción: calcula los numero de fibonacci.
   Parámetros:
     - num1: El primer número de la sucesion.
     - num2: El segundo número de la sucesion.
     - res: la suma del num1 y num2.
   Valor de retorno: solo imprime los numeros.
*/

void calcularFibonacci(int num)
{
    int num1 = 0, num2 = 1, res;
    int i;
    for (i = 0; i < num; i++)
    {
        res = num1 + num2;
        printf("%d ", res);
        num2 = num1;
        num1 = res;
    }
}

/*
   Función: calcularFibonacciRecursion
   Descripción: calcula los numero de fibonacci con recursion.
   Parámetros:
     - num: es el numero que ingresa el usuario.
   Valor de retorno: retorna los numeros de de la sucesion.
*/

int calcularFibonacciRecursion(int num)
{
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return calcularFibonacciRecursion(num - 1) + calcularFibonacciRecursion(num - 2);
    }
}

/*
   Función: factorial
   Descripción: calcula el factorial para el triangulo de pascal.
   Parámetros:
     - n: el numero que contiene i.
   Valor de retorno: i modificada.
*/

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

/*
   Función: coeficiente
   Descripción: calcula el coeficiente para el triangulo de pascal.
   Parámetros:
     - n: el numero que contiene i.
     - k: el numero que contiene k.
   Valor de retorno: operacion realizada con la funcion de factorial.
*/

int Coeficiente(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*
   Función: generarTrianguloPascal
   Descripción: genera el triangulo.
   Parámetros:
     - num: es el numero que ingresa el usiario.
     - i: recorre los numeros para las lineas.
     - j: recorre los numeros para imprimir.
     - k: recorre el valor para imprimir los numeros.
   Valor de retorno: los numeros y las filas del triangulo.
*/

void generarTrianguloPascal(int num)
{
    int i, j, k;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j <= num - i - 2; j++)
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("%d ", Coeficiente(i, k));
        }
        printf("\n");
    }
}
