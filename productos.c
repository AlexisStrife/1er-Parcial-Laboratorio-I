#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "proveedores.h"
#include "productos.h"
#include "informes.h"
#include "input.h"

void inicializarProd(eProducto prod[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        prod[i].estado = 0;
    }
}

int obtenerEspacioLibreProd(eProducto prod[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(prod[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

void altaProd(eProducto prod[], int cantidad){
    int i;
    int validoImp, validoCant, validoCodProv;
    system("cls");
    printf("---Alta de producto---\n\n");
    i = obtenerEspacioLibreProd(prod, cantidad);
    if(i == -1)
    {
        printf("No hay espacio libre para dar de alta.\n");
    }
    else
    {
        prod[i].codigo = i;
        printf("Codigo: %d\nDescripcion: ", i);
        fflush(stdin);
        scanf("%s", prod[i].descripcion);

        do{
            validoCodProv = getInt(&prod[i].codProv,"Codigo Proveedor: ","Rango valido [1 - 1000]",1,1000);
        }
        while(validoCodProv == -1);

        do{
            validoImp = getFloat(&prod[i].importe,"Importe: ","Rango valido [0 - 9999]",0,9999);
        }
        while(validoImp == -1);

        do{
            validoCant = getInt(&prod[i].cant,"Cantidad: ","Rango valido [1 - 1000]",1,1000);
        }
        while(validoCant == -1);
        prod[i].estado = 1;
    }
    printf("\n");
}

int buscarPorCodigoProd(eProducto prod[], int cantidad, int codigo)
{
    int indice = -1;
    int i;

    for(i=0; i < cantidad; i++)
    {
        if(prod[i].estado == 1 && prod[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarProducto(eProducto prod)
{
    printf("\nCodigo: %d   Descripcion: %s   Importe: %.2f   Cantidad: %d \n", prod.codigo, prod.descripcion, prod.importe, prod.cant);
}

void bajaProd(eProducto prod[], int cantidad)
{
    int codigo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Producto---\n\n");
    printf("Ingrese Codigo: ");
    scanf("%d", &codigo);

    esta = buscarPorCodigoProd(prod, cantidad, codigo);

    if(esta == -1)
    {
        printf("\nEl Codigo %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {
        mostrarProducto(prod[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            prod[esta].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
}

void modificarProd(eProducto prod[], int cantidad)
{
    int codigo;
    int esta, validoImp, validoCant;

    system("cls");
    printf("---Modificar Producto---\n\n");

    printf("Ingrese Codigo: ");
    scanf("%d", &codigo);

    esta = buscarPorCodigoProd(prod, cantidad, codigo);

    if(esta == -1)
    {
        printf("\nEl Codigo %d no se encuentra en el sistema\n\n", codigo);
    }
    else
    {
        mostrarProducto(prod[esta]);
        printf("\n---Nuevos datos---\nCodigo: %d\nNueva Descripcion: ", esta);
        fflush(stdin);
        scanf("%s", prod[esta].descripcion);

        do{
            validoImp = getFloat(&prod[esta].importe,"Nuevo Importe: ","Rango valido [0 - 9999]",0,9999);
        }
        while(validoImp == -1);

        do{
            validoCant = getInt(&prod[esta].cant,"Nueva Cantidad: ","Rango valido [1 - 1000]",1,1000);
        }
        while(validoCant == -1);

        prod[esta].estado = 1;
    }
}

void hardCodeProd(eProducto prod[], int cantidad)
{
    prod[0].codigo = 0;
    strcpy(prod[0].descripcion, "Coca");
    prod[0].importe = 25.50;
    prod[0].cant = 30;
    prod[0].codProv = 1;
    prod[0].estado = 1;

    prod[1].codigo = 1;
    strcpy(prod[1].descripcion, "Pepsi");
    prod[1].importe = 22;
    prod[1].cant = 20;
    prod[1].codProv = 2;
    prod[1].estado = 1;

    prod[2].codigo = 2;
    strcpy(prod[2].descripcion, "Fanta");
    prod[2].importe = 22;
    prod[2].cant = 10;
    prod[2].codProv = 1;
    prod[2].estado = 1;

    prod[3].codigo = 3;
    strcpy(prod[3].descripcion, "Manaos");
    prod[3].importe = 10;
    prod[3].cant = 5;
    prod[3].codProv = 1;
    prod[3].estado = 1;

    prod[4].codigo = 4;
    strcpy(prod[4].descripcion, "Satur");
    prod[4].importe = 16.25;
    prod[4].cant = 7;
    prod[4].codProv = 2;
    prod[4].estado = 1;

    prod[5].codigo = 5;
    strcpy(prod[5].descripcion, "Pitusa");
    prod[5].importe = 12.50;
    prod[5].cant = 3;
    prod[5].codProv = 3;
    prod[5].estado = 1;
}
