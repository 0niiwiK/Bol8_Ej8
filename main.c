/* Se desea diseñar un programa que obtenga el salario neto semanal de n trabajadores de acuerdo a los siguientes puntos:
• Las 38 primeras horas semanales se cobran a la tarifa ordinaria.
• Cualquier hora extra a 1,5 veces la tarifa ordinaria.
• Los 200 primeros euros están libres de impuestos; los siguientes 300 tienen un impuesto del 25 % y los restantes del 45 %.
• La tarifa ordinaria es de 12 euros /hora.
El programa deberá pedir el código del empleado y el número de horas que ha trabajado, y a continuación
deberá mostrar de forma detallada el salario neto semanal.
El usuario decidirá tras el cálculo para un trabajador si desea continuar con el programa o si desea salir del mismo. */

//PROTOTIPOS
float calcula_impuestos (float sal);
float calcula_salario_horas (int h);
float calcular_salario (int h,float *i);
void escribir_resultados (int cod, int horas, float sal, float imp);
void leer_horas (int *horas);
void leer_opcion (char *o);
void leer_codigo (int *cod);

#include <stdio.h>

int main() {
    float impuestos, salario;
    int horas, codigo;
    char opcion;
    do {
        leer_codigo(&codigo);
        leer_horas(&horas);
        salario=calcular_salario(horas,&impuestos);
        escribir_resultados(codigo,horas,salario,impuestos);
        leer_opcion(&opcion);
    } while (opcion==('s'|'S'));
    return 0;
}

float calcula_impuestos (float sal){
    float impuestos=0;
    if (sal>200){
        if (sal<=500)
            impuestos=((sal - 200) * 0.25);
        else
            impuestos=(75 + ((sal - 500) * 0.45));
    }
    return impuestos;
}

float calcula_salario_horas (int h){
    float sal=0;
    if (h<=38)
        sal=h*12;
    else
        sal=(38*12)+((h-38)*1.5*12);
    return sal;
}

float calcular_salario (int h,float *i){
    float sal=0;
    sal=calcula_salario_horas(h);
    *i=calcula_impuestos(sal);
    return sal;
}

void escribir_resultados (int cod, int horas, float sal, float imp){
    printf("Salario bruto (%d horas) = %.2f\n",horas,sal);
    printf("Impuestos: %.2f euros\n",imp);
    printf("Salario neto del empleado %d: %.2f euros\n",cod,sal-imp);
}

void leer_horas (int *horas){
    do {
        printf("Introduzca el numero de horas: ");
        scanf("%d",horas);
        fflush(stdin);
    } while (*horas<1);
}

void leer_opcion (char *o) {
    char opcion;
    printf("¿Desea continuar con el siguiente empleado (s/n)?: ");
    fflush(stdin);
    scanf("%c", &opcion);
    fflush(stdin);
    *o=opcion;
}

void leer_codigo (int *cod){
    int codigo;
    do {
        printf("\nIntroduzca el codigo de empleado: ");
        scanf("%d",&codigo);
        fflush(stdin);
    } while (codigo<1);
    *cod=codigo;
}