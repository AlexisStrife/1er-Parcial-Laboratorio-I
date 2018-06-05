#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "proveedores.h"
#include "productos.h"
#include "informes.h"
#include "input.h"

void hardCodeProv(eProveedor prov[]){
    prov[0].codigo = 0;
    strcpy(prov[0].descripcion, "A");

    prov[1].codigo = 1;
    strcpy(prov[1].descripcion, "B");

    prov[2].codigo = 2;
    strcpy(prov[2].descripcion, "C");

    prov[3].codigo = 3;
    strcpy(prov[3].descripcion, "D");
}
