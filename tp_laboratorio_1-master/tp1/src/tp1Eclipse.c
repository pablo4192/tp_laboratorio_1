/*
 ============================================================================
 Name        : tp1Eclipse.c
 Author      : Estanguet Pablo; Div: 1G; TP1, Calculadora.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1EclipseLib.h"//en el main solo se carga el archivo.h

int main(void)//se agrega void en eclipse
{
	setbuf(stdout,NULL);

	float numero1=0;//declaro e inicializo variable 1er numero en 0
    float numero2=0;//declaro e inicializo variable 2do numero en 0
    float suma;//declaro variable para realizar la suma y guardar el resultado en su direccion de memoria
    float resta;
    float division;
    float multiplicacion;
    long int factorialA;
    long int factorialB;
    int flagNumero1=0;//flags para validar que se ingresen los datos en el orden correcto
    int flagNumero2=0;
    int flagCalcular=0;
    char salir;
    char seguir;//variable de control del bucle

    seguir='s';//mientras sea =='s' vuelve al bucle, cuando sea !='s' sale.

    do
    {
        switch(menuDeOpciones(numero1,numero2))//acciones a seguir segun opcion elegida, le paso a funcion menu los operandos a mostras en pantalla.
        {
        case 1:
            if(flagCalcular==0)
            {
                //system("cls");//limpio pantalla de menu y dejo solamente a la vista ingresar el dato (en codeblocks..)
                printf("Escogio opcion 1)\n");
                printf("Por favor ingrese 1er operando: ");//entrada 1er dato por el usuario
                scanf("%f", &numero1);//guardo dato en direccion de memoria
                flagNumero1=1;
            }
            else
            {
                //system("cls");
                printf("Ya realizo el calculo de dos operandos, para concluir con esta operacion muestre resultados en opcion 4),\n y luego si lo desea ingrese nuevos parametros\n");
                system("pause");
            }

            break;
        case 2:
            if(flagCalcular==0)
            {
                //system("cls");
                printf("Escogio opcion 2)\n");
                printf("Por favor ingrese 2do operando: ");//entrada 2do dato por el usuario
                scanf("%f", &numero2);//guardo dato en direccion de memoria
                flagNumero2=1;
            }
            else
            {
                //system("cls");
                printf("Ya realizo el calculo de dos operandos, para concluir con esta operacion muestre resultados en opcion 4),\n y luego si lo desea ingrese nuevos parametros\n");
                system("pause");
            }

            break;
        case 3:
            if(flagNumero1==1 && flagNumero2==1)//valido si las banderas de num1 y num2 estan levantadas para entrar y hacer las operaciones.
            {
                //system("cls");
                suma=sumarTp1(numero1,numero2);//llamada a funcion sumarTp1, pasandole los parametros.
                resta=restaTp1(numero1,numero2);//llamada a funcion restarTp1
                if(numero2!=0)//valido si el 2do numero es !=0, asi si es 0 ni siquiera la hace la operacion
                {
                    division=divisionTp1(numero1,numero2);//llamada a funcion divisionTp1
                }
                multiplicacion=multiplicacionTp1(numero1,numero2);//llamada a funcion multiplicacioTp1
                printf("Las operaciones fueron calculadas.\nIngrese opcion 4) para mostrar resultados.\n\n");
                if(numero1>=0)//valido asi si es negativo el numero, que ni se gaste en hacer el factorial.
                {
                    factorialA=factorialTp1(numero1);//llamada a funcion factorialTp1
                }
                if(numero2>=0)
                {
                    factorialB=factorialTp1(numero2);//llamada a funcion factorialTp1
                }
                flagCalcular=1;
            }
            else
            {
                //system("cls");
                printf("No se pueden hacer calculos antes de ingresar los dos operandos.\nPor favor ingrese los datos en las opciones 1) y 2)\n\n");
            }

            system("pause");//hace una pausa esperando el enter para seguir con el flujo.
            break;
        case 4:
            if(flagCalcular==1)//valido si la bandera de 3)calcular esta levantada para poder mostrar los resultados.
            {
                //system("cls");
                printf("El resultado de la suma es: %.2f\n", suma);
                printf("El resultado de la resta es: %.2f\n", resta);
                if(numero2!=0)//valido para mostrar la division
                {
                    printf("El resultado de la division es: %.2f\n", division);
                }
                else
                {
                    printf("No es posible dividir por 0\n");
                }
                printf("El resultado de la multiplicacion es: %.2f\n", multiplicacion);
                if(numero1>=0)//valido si es positivo que muestre el resultado
                {
                    printf("El resultado del factorial de A es: %ld\n", factorialA);
                }
                else//si es negativo que informe al usuario que no se pudo hacer la operacion
                {
                    printf("No se puede realizar el factorial de numeros negativos.\n\n");
                }

                if(numero2>=0)
                {
                    printf("El resultado del factorial de B es: %ld\n\n", factorialB);
                }
                else
                {
                    printf("No se puede realizar el factorial de numeros negativos.\n\n");
                }
            numero1=0;//cuando muestro los resultados se reinician los valores de los parametros.
            numero2=0;
            flagCalcular=0;//reinicio la bandera de calcular asi puedo ingresar nuevos parametros.
            flagNumero1=0;//reinicio bandera de numeros una vez que muestro el resultado asi si ingresan nuevamente opcion 3) no vuelvo a calcular lo ya calculado. (cuando ingresen nuevos parametros voy a poder calcular nuevamente).
            flagNumero2=0;
            }
            else//si la bandera calcular esta baja le pido al usuario los pasos correctos del flujo del programa.
            {
                //system("cls");
                printf("No hay resultados para mostrar.\nPor favor primero calcule las operaciones en la opcion 3)\n\n");
            }
            system("pause");
            break;
        case 5:
            printf("Esta seguro que desea salir?\n(Ingrese: s para SALIR / cualquier otra tecla para CANCELAR)\n");
            fflush(stdin);//limpio el buffer ya que ingreso un caracter
            scanf("%c", &salir);//guardo el valor en la direccion de memoria de salir
            salir=tolower(salir);//si ingresan mayuscula lo paso a minuscula
            if(salir=='s')//valido para confirmar salida o cancelar salida, si no entra al if sigue..
            {
                seguir='n';//cambio el valor de seguir para salir del bucle.
            }
            break;
        }

    }while(seguir=='s');

    return 0;
}

/*Enunciado.
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:

1. Ingresar 1er operando (A=x)  ok
2. Ingresar 2do operando (B=y)  ok
3. Calcular todas las operaciones

a) Calcular la suma (A+B)   ok
b) Calcular la resta (A-B)  ok
c) Calcular la division (A/B)   ok
d) Calcular la multiplicacion (A*B  ok
e) Calcular el factorial (A!) ok

4. Informar resultados  ok

a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir    ok

� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,    ok
que contenga las funciones para realizar las cinco operaciones.

� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B  ok
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)

� Deber�n contemplarse los casos de error (divisi�n por cero, etc)  ok

� Documentar todas las funciones    ok
*/
