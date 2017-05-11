

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char direcion[20];
    int long long tarjeta;
    int estado;
} ePropietario;

typedef struct
{
    char patente[10];
    char marca[15];
    int id;
    int hora;
} eAuto;

void inicializarEstado(ePropietario persona[], int tam);
int espacio(ePropietario persona[], int tam);
void menu();
void alta(ePropietario duenio[]);
void ingreso(ePropietario duenio[], eAuto autos[]);
void baja(ePropietario duenio[]);
void modificar(ePropietario duenio[]);
void egreso(eAuto autos[], ePropietario duenio[]);
int validarInt(int numero, int mini, int maxi);
int buscarDuenio(int aux, ePropietario duenio[]);
int buscarAuto(char aux[], eAuto autos[]);
void ticket(eAuto autos[], ePropietario duenio[], int lugar, int estadia);
void informar(ePropietario duenio[], eAuto autos[]);
void ordenar(eAuto autos[]);
void mostrar(ePropietario duenio[], eAuto autos[]);
