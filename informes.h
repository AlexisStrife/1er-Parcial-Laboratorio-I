/**
 * Ordena los elementos de la lista
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 */
void ordenarProd(eProducto prod[], int cantidad);

/**
 * Lista un submenu para informar distintos datos segun se elija
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 */
void informarProd(eProducto prod[], int cantidad, eProveedor prov[]);

/**
 * Lista un submenu para listar distintos datos segun se elija
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores
 */
void listarProd(eProducto prod[], int cantidad, eProveedor prov[]);

/**
 * Lista un submenu para listar distintos datos segun se elija
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores
 */
void listaProvxProd(eProducto prod, int cantidad, eProveedor prov);

/**
 * Lista el proveedor pasado por parametro y sus productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores
 */
void listaProv(eProducto prod[], int cantidad, eProveedor prov);

/**
 * Lista todos los proveedores y sus productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores
 */
 void listaProdProv(eProducto prod[], int cantidad, eProveedor prov[]);

 /**
 * Calcula el precio mas caro/barato del array
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que calcular
 * @param prov el array se pasa como parametro
 */
 void calculaPrecio(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);

/**
 * Calcula el promedio de precios de los productos del array
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que calcular
 */
void calculaPromedio(eProducto prod[], int cantidad, int opcion);

/**
 * Calcula la cantidad total de productos segun stock
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que calcular
 * @param prov el array de proveedores
 */
void calculaCantidad(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);

/**
 * Lista los productos
 * @param prod el array se pasa como parametro
 */
void toStringProd(eProducto prod);

/**
 * Lista los proveedores
 * @param prod el array se pasa como parametro
 */
void toStringProv(eProveedor prov);

/**
 * Lista los proveedores con mayor y menor productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que calcular
 * @param prov el array de proveedores
 */
void listaMayMenProv(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);
