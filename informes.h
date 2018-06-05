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
 * @param prov el array se pasa como parametro
 */
void informarProd(eProducto prod[], int cantidad, eProveedor prov[]);

/**
 * Lista un submenu para listar distintos datos segun se elija
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores se pasa como parametro
 */
void listarProd(eProducto prod[], int cantidad, eProveedor prov[]);

/**
 * Lista los productos del proveedor pasado por parametro
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores se pasa como parametro
 */
void listaProductosxProveedor(eProducto prod, int cantidad, eProveedor prov);

/**
 * Lista el proveedor pasado por parametro y sus productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores se pasa como parametro
 */
void listaProveedor(eProducto prod[], int cantidad, eProveedor prov);

/**
 * Lista todos los proveedores y sus productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param prov el array proveedores se pasa como parametro
 */
 void listaProductosProveedores(eProducto prod[], int cantidad, eProveedor prov[]);

 /**
 * Calcula el precio mas caro/barato del array
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que mostrar
 * @param prov el array se pasa como parametro
 */
 void calculaPrecio(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);

/**
 * Calcula el promedio de precios de los productos del array
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que mostrar
 */
void calculaPromedio(eProducto prod[], int cantidad, int opcion);

/**
 * Calcula la cantidad total de productos segun stock
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que calcular
 * @param prov el array de proveedores se pasa como parametro
 */
void calculaCantidad(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);

/**
 * Lista el producto pasado como parametro
 * @param prod el array se pasa como parametro
 */
void toStringProd(eProducto prod);

/**
 * Lista el proveedor pasado como parametro
 * @param prod el array se pasa como parametro
 */
void toStringProv(eProveedor prov);

/**
 * Lista los proveedores con mayor y menor productos
 * @param prod el array se pasa como parametro
 * @param cantidad de productos en el array
 * @param opcion seleccionada sobre que mostrar
 * @param prov el array de proveedores se pasa como parametro
 */
void listaMayMenProv(eProducto prod[], int cantidad, int opcion, eProveedor prov[]);
