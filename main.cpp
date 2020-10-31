#include "functions.h"

int main()
{
    short n,m;
    string name,name_save;
    /*Programa de codificacion de archivos, se debe resibir un numero entreo n que sera la semilla
    de codificacion, y un número par seleccionar el método de codificacíon*/

    while (true){

        cout << "\n\n\tCODIFICACION-DECODIFICACION-APLICACION DE ARCHVIOS\n\n";
        cout << "\tQue desea realizar ?\n\n\t1) CODIFICACION\n\n\t2) DECODIFICACION \n\n\t3) SALIR\n\n\t -- > ";cin >> m ; cout << "\n\n";

        if (m == 1) {

            while (true){

                cout << "\tIngrese el nombre del archivo a codificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";


                string binario = "../Practica_3/documents/codificados/" + name + "_bi.dat";
                string name_1 = "../Practica_3/documents/" + name + ".txt";

                fstream doc(name_1.c_str(), fstream :: in);
                if (doc.fail()) {
                    cout << "\n\n\tERROR! el archivo no existe\n\n";
                    break;
                }
                doc.close();

                con_bin(name_1,binario);

                cout << "\tIngrese un numero semilla para la generacion del archivos\n\n\t --> "; cin >> n ; cout << "\n\n";
                cout << "\tIngrese el medotodo a usar\n\n\t1) Metodo 1 (CHAR)\n\n\t2) Metodo 2 (STRING) \n\n\t -- > ";cin >> m ; cout << "\n\n";

                if (m == 1){

                    string save = "../Practica_3/documents/codificados/" + name + "_save.dat";
                    string name_2 = "../Practica_3/documents/codificados/" + name + "_bi.dat";

                    metodo_1_codi(name_2,n,save);


                    name = "../Practica_3/documents/codificados/" + name + "_1.dat";
                    cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                    cambio(save,name);
                    cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                    cout << "\n\n\t\t Codificacion Completada\n\n";
                    break;
                }
                else if (m == 2){

                    string save = "../Practica_3/documents/codificados/" + name + "_save.dat";
                    string name_2 = "../Practica_3/documents/codificados/" + name + "_bi.dat";

                    metodo_2_codi(name_2,n,save);


                    name = "../Practica_3/documents/codificados/" + name + "_2.dat";
                    cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                    cambio(save,name);
                    cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                    cout << "\n\n\t\t Codificacion Completada\n\n";
                    break;
                }
                else {
                    cout << "\n\n\tValor Inconcluzo\n\n";
                    break;
                }
            }
        }

        else if (m == 2){

            while (true){

                cout << "\tIngrese un numero semilla para la generacion del archivos\n\n\t --> "; cin >> n ; cout << "\n\n";

                cout << "\tIngrese el medotodo a usar\n\n\t1) Metodo 1 (CHAR)\n\n\t2) Metodo 2 (STRING) \n\n\t -- > ";cin >> m ; cout << "\n\n";


                if (m == 1){

                    cout << "\tIngrese el nombre del archivo a decodificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";

                    string name_24 = "../Practica_3/documents/codificados/" + name + "_1.dat";
                    string save = "../Practica_3/documents/codificados/" + name + "_save.dat";

                    fstream doc(name_24.c_str(), fstream :: in);
                    if (doc.fail()) {
                        cout << "\n\n\tERROR! el archivo no existe\n\n";
                        break;
                    }
                    doc.close();

                    retorno(name_24,save);



                    string bi = "../Practica_3/documents/codificados/" + name + "_bi.dat";
                    string name_2 = "../Practica_3/documents/codificados/" + name + "_save.dat";
                    metodo_1_deco(name_2,n,bi);

                }
                else if (m == 2){

                    cout << "\tIngrese el nombre del archivo a decodificar (sin .txt)\n\n\t --> "; cin >> name ; cout << "\n\n";

                    string name_24 = "../Practica_3/documents/codificados/" + name + "_2.dat";
                    string save = "../Practica_3/documents/codificados/" + name + "_save.dat";

                    fstream doc(name_24.c_str(), fstream :: in);
                    if (doc.fail()) {
                        cout << "\n\n\tERROR! el archivo no existe\n\n";
                        break;
                    }
                    doc.close();

                    retorno(name_24,save);

                    string bi = "../Practica_3/documents/codificados/" + name + "_bi.dat";
                    string name_2 = "../Practica_3/documents/codificados/" + name + "_save.dat";

                    metodo_2_deco(name_2,n,bi);

                }
                else {
                    cout << "\n\n\tValor Inconcluzo\n\n";
                    break;
                }


                string deco = "../Practica_3/documents/" + name + ".txt";
                name = "../Practica_3/documents/codificados/" + name + "_bi.dat";


                cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                bin_tex (name,deco);
                cout << "\n\n\n_____________________________________________________________________________\n\n\n";
                cout << "\n\n\t\t Decodificacion Completada\n\n";
                break;

            }


        }

        else if (m == 3) break;

        else cout << "\n\n\tValor impreciso reintente\n\n";

    }



    return 0;
}
