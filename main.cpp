#include "functions.h"

int main()
{
    short n,m;
    string name,name_save;
    /*Programa de codificacion de archivos, se debe resibir un numero entreo n que sera la semilla
    de codificacion, y un número par seleccionar el método de codificacíon*/

    while (true){

        cout << "\n\n\tCODIFICACION-DECODIFICACION-APLICACION DE ARCHVIOS\n\n";
        cout << "\tQue desea realizar ?\n\n\t1) CODIFICACION\n\n\t2) DECODIFICACION \n\n\t3) APLICACION \n\n\t4) SALIR\n\n\t -- > ";cin >> m ; cout << "\n\n";

        if (m == 1) {

            cout << "\tIngrese el nombre del archivo a codificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";
            cout << "\tIngrese un numero semilla para la generacion del archivos\n\n\t --> "; cin >> n ; cout << "\n\n";
            cout << "\tIngrese el medotodo a usar\n\n\t1) Metodo 1 (CHAR)\n\n\t2) Metodo 2 (STRING) \n\n\t -- > ";cin >> m ; cout << "\n\n";
            con_bin (name);

        }

        else if (m == 2){

            cout << "\tIngrese el nombre del archivo a decodificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";
            cout << "\tIngrese un numero semilla para la generacion del archivos\n\n\t --> "; cin >> n ; cout << "\n\n";
            cout << "\tIngrese el medotodo a usar\n\n\t1) Metodo 1 (CHAR)\n\n\t2) Metodo 2 (STRING) \n\n\t -- > ";cin >> m ; cout << "\n\n";
            con_bin (name);

        }

        else if (m == 3){

        }

        else if (m == 4){

            break;

        }

        else cout << "\n\n\tValor impreciso reintente\n\n";

    }



    return 0;
}
