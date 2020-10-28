#include "functions.h"

int main()
{
    short n,m;
    string name;
    /*Programa de codificacin de archivos, se debe resibir un numero entreo n que sera la semilla
    de codificacion, y un número par seleccionar el método de codificacíon*/
    cout << "\n\n\tCODIFICACION DE ARCHVIOS\n\n";
    cout << "\tIngrese el nombre del archivo a codificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";
    cout << "\tIngrese un numero semilla para la generacion del archivos\n\n\t --> "; cin >> n ; cout << "\n\n";
    cout << "\tIngrese el medotodo a usar\n\n\t1) Metodo 1 (CHAR)\n\n\t2) Metodo 2 (STRING) \n\n\t -- > ";cin >> m ; cout << "\n\n";

    name = "../Practica_3/documents/" + name + ".txt";
    cout << name << "\n\n";
    fstream doc (name, fstream :: out);



    return 0;
}
