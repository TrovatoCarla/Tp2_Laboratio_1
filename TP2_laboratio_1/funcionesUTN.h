#define MAXIMO_CARACTER 100

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *resultado);
int getFloat(char *mensaje,char *mensajeError,float maximo,float minimo,int reintentos,float *resultado);
int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int getString(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int getName(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int getApellido(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado);

int iniciarlizarArrays(char arrayStr [] [MAXIMO_CARACTER], int limite);
int muestraArray(char arrayStr[][MAXIMO_CARACTER],int limite);
int encuentraPosVacia(char arrayStr [] [MAXIMO_CARACTER],int* posicionDisponible, int limite);
int buscaSiYaExiste(char arrayStr [] [MAXIMO_CARACTER],char* nombre,int* posicionNombreExistente,int limite);
int ordenarArray(char arrayStr[] [MAXIMO_CARACTER],int limite);
