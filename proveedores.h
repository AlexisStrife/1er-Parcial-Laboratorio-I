/**
 * Estructura de proveedores
 */
typedef struct {

    int codigo;
    char descripcion[50];

}eProveedor;

/**
 * ingresa datos hardcodeados en cada elemento de la lista para pruebas
 * @param lista el array que se llena con datos hardcodeados.
 */
void hardCodeProv(eProveedor prov[]);

/**
 * Ingresa un nuevo elemento en la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void altaProv(eProveedor prov[], int);

/**
 * inhabilita un elemento de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void bajaProv(eProveedor prov[], int);

/**
 * modifica un elemento de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void modificarProv(eProveedor prov[], int);

/**
 * Lista los elementos en la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void listarProv(eProveedor prov[], int);

/**
 * Ordena los elementos de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void ordenarProv(eProveedor prov[], int);

/**
 * inicializa en estado 0(sin datos) todos los elementos de la lista
 * @param lista el array se pasa como parametro, int cantidad de elementos en el array.
 */
void inicializarProv(eProveedor prov[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibreProv(eProveedor prov[], int cantidad);

/**
 * Obtiene el indice que coincide con el codigo pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param codigo el codigo a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro codigo
 */
int buscarPorCodigoProv(eProveedor prov[], int cant, int cod);
