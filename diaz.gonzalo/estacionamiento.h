

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char direcion[20];
    int long tarjeta;
    int estado;
} ePropietario;

typedef struct
{
    char patente[10];
    int marca;
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
int validarInt(int numero, int mini, int maxi);
int buscarDuenio(ePropietario duenio[], eAuto autos[]);
