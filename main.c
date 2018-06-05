#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"
#include "productos.h"
#include "informes.h"
#include "input.h"

#define TAM 10

int main()
{
    char seguir='s';
    char auxOpcion[2];
    int opcion=0;
    int validado;
    eProducto prod[TAM]; //{{0, "Coca", 20.50, 100, 1, 1},{1, "Pepsi", 18.50, 50, 2, 1},{2, "Fanta", 18,75, 3, 1}}
    eProveedor prov[TAM] = {{1, "Coca-Cola"}, {2, "Pepsico"}, {3, "Fantasia"}, {4, "Man"}, {5, "Pitusas"}, {6, "Rocklets"}};
    inicializarProd(prod, TAM);
    hardCodeProd(prod, TAM);
    //hardCodeProv(prov);

    while(seguir=='s')
    {
        menu();
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
                altaProd(prod, TAM);
                break;
            case 2:
                modificarProd(prod, TAM);
                break;
            case 3:
                bajaProd(prod, TAM);
                break;
            case 4:
                informarProd(prod, TAM, prov);
                break;
            case 5:
                listarProd(prod, TAM, prov);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Opcion no valida.\n\n");
        }
    }
    return 0;
}
