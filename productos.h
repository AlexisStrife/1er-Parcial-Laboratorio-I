/**
 * Estructura de productos
 */
typedef struct {

    int codigo;
    char descripcion[50];
    float importe;
    int cant;
    int codProv;
    int estado;

}eProducto;

/**
 * Ingresa un nuevo elemento en la lista
 * @param prod el array se pasa como parametro, int cantidad de elementos en el array.
 */
void altaProd(eProducto prod[], int);

/**
 * inhabilita un elemento de la lista
 * @param prod el array se pasa como parametro, int cantidad de elementos en el array.
 */
void bajaProd(eProducto prod[], int);

/**
 * modifica un elemento de la lista
 * @param prod el array se pasa como parametro, int cantidad de elementos en el array.
 */
void modificarProd(eProducto prod[], int);

/**
 * inicializa en estado 0(sin datos) todos los elementos de la lista
 * @param prod el array se pasa como parametro, int cantidad de elementos en el array.
 */
void inicializarProd(eProducto prod[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param prod el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibreProd(eProducto prod[], int cantidad);

/**
 * Obtiene el indice que coincide con el codigo pasado por parametro.
 * @param prod el array se pasa como parametro.
 * @param codigo el codigo a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro codigo
 */
int buscarPorCodigoProd(eProducto prod[], int cant, int cod);

/**
 * ingresa datos hardcodeados en cada elemento de la lista para pruebas
 * @param lista el array que se llena con datos hardcodeados.
 */
void hardCodeProd(eProducto prod[], int cantidad);
