#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <conio.h>

char *mayuscula(char cadena[]);
int validarNumeros(char mensaje[], int ri, int rf);
int random(int ri, int rf);
char *validarletras(char mensaje[], char cadena[]);
int contador(char cadena[]);
int validarnumeros(char mensaje[], int ri, int rf);

char *mayuscula(char cadena[])
{
    int i, x;
    x = contador(cadena);

    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
    return cadena;
}

int validarNumeros(char mensaje[], int ri, int rf)
{
    char entrada[100];
    int num;
    do
    {
        printf("%s", mensaje);
        fgets(entrada, sizeof(entrada), stdin);
        num = atoi(entrada);
        if (num < ri || num > rf)
        {
            printf("\nINGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}

int random(int ri, int rf)
{
    int r;
    r = (rf - ri) + 1;
    return (rand() % r) + ri;
}

char *validarletras(char mensaje[], char cadena[])
{
    int x, i, salida;
    wchar_t letras;
    i = 0;
    salida = 0;
    printf("%s", mensaje);
    do
    {
        salida = 0;
        fflush(stdin);
        gets(cadena);
        x = contador(cadena);
        mayuscula(cadena);
        for (i = 0; i < x; i++)
        {
            letras = (wchar_t)cadena[i];
            if (!iswalpha(letras) && cadena[i] != ' ')
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
            }

            if (cadena[i] == ' ' && cadena[i + 1] == ' ')
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
                i = x;
            }
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
                i = x;
            }
        }
        if (cadena[0] == ' ' || cadena[x - 1] == ' ')
        {
            printf("ESPACIOS AL INICIO O FINAL\n");
            salida = 1;
            i = x;
        }
    } while (salida == 1);
    return cadena;
}

int contador(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != 0)
    {
        i++;
    }
    return i;
}

int validarnumeros(char mensaje[], int ri, int rf)
{
    char menu[100];
    int num, salida = 0, con, i;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(menu);
        con = contador(menu);
        for (i = 0; i < con; i++)
        {
            if (menu[i] >= '0' && menu[i] <= '9')
            {
                salida = 1;
                break;
            }
            else
            {
                salida = 0;
                break;
            }
        }
        num = atoi(menu);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf || salida == 0);
    return num;
}