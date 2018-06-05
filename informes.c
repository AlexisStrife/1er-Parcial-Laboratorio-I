#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "proveedores.h"
#include "productos.h"
#include "informes.h"
#include "input.h"

void ordenarProd(eProducto prod[], int cantidad)
{
    int j, k;
    eProducto aux;

    for (j=0; j<cantidad-1; j++)
        {
            for(k=j+1; k<cantidad; k++)
                {
                    if (prod[j].importe < prod[k].importe){
                        aux = prod[j];
                        prod[j] = prod[k];
                        prod[k] = aux;
                    }
                    else if (prod[j].importe == prod[k].importe)
                    {
                        if (strcmp(prod[j].descripcion, prod[k].descripcion) > 0)
                        {
                            aux = prod[j];
                            prod[j] = prod[k];
                            prod[k] = aux;
                        }
                    }
                }
        }
}

void informarProd(eProducto prod[], int cantidad, eProveedor prov[])
{
    char seguir='s';
    char auxOpcion[1];
    int opcion=0;
    int validado, i;
    int hayDatos = 0;


    system("cls");
    for(i = 0; i < cantidad; i++)
    {
        if(prod[i].estado == 1)
        {
            hayDatos = 1;
            break;
        }
    }
    if(hayDatos == 1)
    {
        while(seguir=='s')
        {
            printf("1- Total y Promedio de Importes y cuantos productos lo superan\n");
            printf("2- Total y Promedio de Importes y cuantos productos NO lo superan\n");
            printf("3- Cantidad Productos STOCK menos o igual a 10\n");
            printf("4- Cantidad Productos STOCK mayor a 10\n\n");
            printf("5- Volver al menu principal\n\n");
            do
            {
                fflush(stdin);
                scanf("%s", auxOpcion);
                validado = validaNumero(auxOpcion);
            }
            while(validado == 0);

            opcion = atoi(auxOpcion);

            switch(opcion)
            {
                case 1:
                    system("cls");
                    calculaPromedio(prod, cantidad, opcion);
                    break;
                case 2:
                    system("cls");
                    calculaPromedio(prod, cantidad, opcion);
                    break;
                case 3:
                    system("cls");
                    calculaCantidad(prod, cantidad, opcion, prov);
                    break;
                case 4:
                    system("cls");
                    calculaCantidad(prod, cantidad, opcion, prov);
                    break;
                case 5:
                    seguir = 'n';
                    system("cls");
                    break;
            }
        }
    }
    else
    {
        printf("No hay datos que mostrar.\n\n");
    }
}

void listarProd(eProducto prod[], int cantidad, eProveedor prov[])
{
    char seguir='s';
    char auxOpcion[2];
    int opcion=0;
    int validado, i;
    int hayDatos = 0;


    system("cls");
    for(i = 0; i < cantidad; i++)
    {
        if(prod[i].estado == 1)
        {
            hayDatos = 1;
            break;
        }
    }
    if(hayDatos == 1)
    {
        while(seguir=='s')
        {
            int flag = 0, codigo;

            printf("1- Listar ordenados\n");
            printf("2- Productos cuya cantidad es menor o igual a 10\n");
            printf("3- Productos cuya cantidad es mayor a 10\n");
            printf("4- Productos que superan el promedio de importes\n");
            printf("5- Productos que no superan el promedio de importes\n");
            printf("6- Proveedores cuyos productos es menor o igual a 10\n");
            printf("7- Productos provistos por cada proveedor\n");
            printf("8- Productos provistos por determinado proveedor\n");
            printf("9- Proveedor con mas productos y sus productos\n");
            printf("10- Proveedor con menos productos y sus productos\n");
            printf("11- Proveedor con el producto mas caro y el producto\n");
            printf("12- Proveedor con el producto mas barato y el producto\n");
            printf("13- Volver al menu principal\n\n");
            do
            {
                fflush(stdin);
                scanf("%s", auxOpcion);
                validado = validaNumero(auxOpcion);
            }
            while(validado == 0);

            opcion = atoi(auxOpcion);

            switch(opcion)
            {
                case 1:
                    system("cls");
                    ordenarProd(prod, cantidad);
                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\n");
                    for(i=0; i<cantidad; i++){
                        if(prod[i].estado == 1){
                            toStringProd(prod[i]);
                        }
                    }
                    printf("\n");
                    break;
                case 2:
                    system("cls");
                    flag = 0;
                    for (i=0; i<cantidad; i++){
                        if(prod[i].estado == 1){
                            if(prod[i].cant <= 10){
                                if (flag == 0){
                                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\n");
                                    flag = 1;
                                }
                                toStringProd(prod[i]);
                            }
                        }
                    }
                    printf("\n");
                    break;
                case 3:
                    system("cls");
                    flag = 0;
                    for (i=0; i<cantidad; i++){
                        if(prod[i].estado == 1){
                            if(prod[i].cant > 10){
                                if (flag == 0){
                                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\n");
                                    flag = 1;
                                }
                                toStringProd(prod[i]);
                            }
                        }
                    }
                    printf("\n");
                    break;
                case 4:
                    system("cls");
                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\n");
                    calculaPromedio(prod, cantidad, opcion);
                    printf("\n");
                    break;
                case 5:
                    system("cls");
                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\n");
                    calculaPromedio(prod, cantidad, opcion);
                    printf("\n");
                    break;
                case 6:
                    system("cls");
                    printf("Listado de Proveedores:\n\nCodigo\tDescripcion\n");
                    calculaCantidad(prod, cantidad, opcion, prov);
                    printf("\n");
                    break;
                case 7:
                    system("cls");
                    printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
                    listaProductosProveedores(prod, cantidad, prov);
                    printf("\n");
                    break;
                case 8:
                    system("cls");
                    int cont = 0, j;
                    printf("Ingrese el codigo de proveedor a listar:\n");
                    scanf("%d", &codigo);
                    for(i=0; i<cantidad; i++)
                    {
                        if(prov[i].codigo == codigo && codigo != 0)
                        {
                            for(j=0; j<cantidad; j++)
                            {
                                if(prod[j].codProv == prov[i].codigo)
                                {
                                    cont++;
                                }
                            }
                            if(cont > 0)
                            {
                                printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
                                listaProveedor(prod, cantidad, prov[i]);
                                flag = 1;
                                break;
                            }
                            else
                            {
                                printf("Dicho proveedor no tiene productos\n");
                                flag = 1;
                            }
                        }
                    }
                    if(flag == 0)
                    {
                        printf("No existe proveedor con ese codigo.\n");
                    }
                    printf("\n");
                    break;
                case 9:
                    system("cls");
                    listaMayMenProv(prod, cantidad, opcion, prov);
                    printf("\n");
                    break;
                case 10:
                    system("cls");
                    listaMayMenProv(prod, cantidad, opcion, prov);
                    printf("\n");
                    break;
                case 11:
                    system("cls");
                    calculaPrecio(prod, cantidad, opcion, prov);
                    break;
                case 12:
                    system("cls");
                    calculaPrecio(prod, cantidad, opcion, prov);
                    break;
                case 13:
                    seguir = 'n';
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("Opcion no valida.\n\n");
                    break;
            }
        }
    }
    else
    {
        printf("No hay datos que mostrar.\n\n");
    }
}

void calculaPromedio(eProducto prod[], int cantidad, int opcion)
{
    float importeTotal = 0, promedio = 0;
    int cantProdsMay = 0, cantProdsMen = 0, cantImportes = 0, i;
    for(i=0; i<cantidad; i++){
        if(prod[i].estado == 1){
            importeTotal = importeTotal + prod[i].importe;
            cantImportes++;
        }
    }
    promedio = importeTotal / cantImportes;

    for(i=0; i<cantidad; i++){
        if(prod[i].estado == 1){
            if(prod[i].importe > promedio){
                if(opcion == 4)
                {
                    toStringProd(prod[i]);
                }
                cantProdsMay++;
            }
            if(prod[i].importe < promedio){
                if(opcion == 5)
                {
                    toStringProd(prod[i]);
                }
                cantProdsMen++;
            }
        }
    }
    if(opcion == 1)
    {
        printf("Importe Total: %.2f\nPromedio Importes: %.2f\nProductos con importe mayor al promedio: %d\n\n", importeTotal, promedio, cantProdsMay);
    }
    else if (opcion == 2)
    {
        printf("Importe Total: %.2f\nPromedio Importes: %.2f\nProductos con importe menor al promedio: %d\n\n", importeTotal, promedio, cantProdsMen);
    }
}

void calculaCantidad(eProducto prod[], int cantidad, int opcion, eProveedor prov[])
{
    int cantProdsMen = 0, cantProdsMay = 0, i, j;
    for(i=0; i<cantidad; i++){
        if(prod[i].estado == 1)
        {
            if(prod[i].cant <= 10){
                if(opcion == 6)
                {
                    for(j=0; j<cantidad; j++)
                    {
                        if(prov[j].codigo == prod[i].codProv)
                        {
                            toStringProv(prov[j]);
                            break;
                        }
                    }
                }
                cantProdsMen++;
            }
            if(prod[i].cant > 10){
                cantProdsMay++;
            }
        }
    }
    if (opcion == 3)
    {
        printf("Cantidad de productos con stock menor o igual a 10: %d\n\n", cantProdsMen);
    }
    else if (opcion == 4)
    {
        printf("Cantidad de productos con stock mayor a 10: %d\n\n", cantProdsMay);
    }
}

void toStringProd(eProducto prod)
{
    printf("%d\t%s\t\t%.2f\t%d\n", prod.codigo, prod.descripcion, prod.importe, prod.cant);
}

void toStringProv(eProveedor prov)
{
    printf("%d\t%s\n", prov.codigo, prov.descripcion);
}

void listaProductosProveedores(eProducto prod[], int cantidad, eProveedor prov[])
{
    int i, j;
    for(i=0; i<cantidad; i++)
    {
        for(j=0; j<cantidad; j++)
        {
            if(prod[i].codProv == prov[j].codigo)
            {
                printf("%d\t%s\t\t%.2f\t%d\t\t%s\n", prod[i].codigo, prod[i].descripcion, prod[i].importe, prod[i].cant, prov[j].descripcion);
                break;
            }
        }
    }
}

void listaProveedor(eProducto prod[], int cantidad, eProveedor prov)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(prod[i].codProv == prov.codigo)
        {
            printf("%d\t%s\t\t%.2f\t%d\t\t%s\n", prod[i].codigo, prod[i].descripcion, prod[i].importe, prod[i].cant, prov.descripcion);
        }
    }
}

void listaProductosxProveedor(eProducto prod, int cantidad, eProveedor prov)
{
    printf("%d\t%s\t\t%.2f\t%d\t\t%s\n", prod.codigo, prod.descripcion, prod.importe, prod.cant, prov.descripcion);
}

void calculaPrecio(eProducto prod[], int cantidad, int opcion, eProveedor prov[])
{
    int i, j, masCaro, masBarato, flag = 0, indexCaroProd = 0, indexBaratoProd = 0, indexCaroProv = 0, indexBaratoProv = 0;
    for(i=0; i<cantidad; i++){
        if(prod[i].estado == 1)
        {
            if(flag==0)
            {
                masCaro = prod[i].importe;
                masBarato = prod[i].importe;
                indexCaroProd = i;
                indexBaratoProd = i;
                flag = 1;
            }
            if(prod[i].importe > masCaro)
            {
                for(j=0; j<cantidad; j++)
                {
                    if(prov[j].codigo == prod[i].codProv)
                    {
                        indexCaroProv = j;
                        break;
                    }
                }
                masCaro = prod[i].importe;
                indexCaroProd = i;
            }
            if(prod[i].importe < masBarato && prod[i].importe > 0)
            {
                for(j=0; j<cantidad; j++)
                {
                    if(prov[j].codigo == prod[i].codProv)
                    {
                        indexBaratoProv = j;
                        break;
                    }
                }
                masBarato = prod[i].importe;
                indexBaratoProd = i;
            }
        }
    }
    if (opcion == 11)
    {
        printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
        listaProductosxProveedor(prod[indexCaroProd], cantidad, prov[indexCaroProv]);
        printf("\n");
    }
    else if (opcion == 12)
    {
        printf("Listado de Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
        listaProductosxProveedor(prod[indexBaratoProd], cantidad, prov[indexBaratoProv]);
        printf("\n");
    }
}

void listaMayMenProv(eProducto prod[], int cantidad, int opcion, eProveedor prov[])
{
    int i, j, flag = 0, flag2 = 0, indexMayorProv, indexMenorProv, mayorProv, menorProv, totProv = 0;
    for(i=0; i<cantidad; i++)
    {
        for(j=0; j<cantidad; j++)
        {
            if(prod[j].estado == 1)
            {
                if(prov[i].codigo == prod[j].codProv)
                {
                    if(flag == 0)
                    {
                        indexMayorProv = i;
                        indexMenorProv = i;
                        flag = 1;
                    }
                    totProv++;
                }
            }
        }
        if(flag2 == 0 && totProv > 0)
        {
            mayorProv = totProv;
            menorProv = totProv;
            flag2 = 1;
        }
        if(totProv > mayorProv)
        {
            indexMayorProv = i;
        }
        if(totProv < menorProv && totProv > 0)
        {
            indexMenorProv = i;
        }
        totProv = 0;
    }
    if(opcion == 9)
    {
        printf("Proveedor con mas Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
        listaProveedor(prod, cantidad, prov[indexMayorProv]);
    }
    else if(opcion == 10)
    {
        printf("Proveedor con menos Productos:\n\nCodigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
        listaProveedor(prod, cantidad, prov[indexMenorProv]);
    }
}


