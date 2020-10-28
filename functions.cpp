#include "functions.h"

void con_bin(string name)
{
    string binario = "../Practica_3/documents/codificados/" + name + "_save.dat";
    name = "../Practica_3/documents/" + name + ".txt";

    short num;
    short int num_bi[8];
    //cout << name << "\n\n";

    fstream doc (name.c_str(), fstream :: in);

    fstream bi (binario.c_str(), fstream ::out | fstream::binary);

    char carac;

    if (!doc.fail()){
        doc.get(carac);

        while (!doc.eof()){

            num = int (carac);
            //cout << num << "\t\t" << carac << "\t\t";

            for (int i = 7; i >= 0 ;i--){
                //cout << num%2 << "\n";
                if (num%2 > 0){
                    num_bi[i] = 1;
                    num /=2;
                }
                else {
                    num_bi[i] = 0;
                    num /=2;
                }
                //cout << num_bi[i];
            }
            //for (int i = 0; i < 8 ;i++) cout << num_bi[i];
            //cout << endl;

            for (int i = 0; i < 8 ;i++) bi << num_bi[i];

            doc.get(carac);
        }
        //cout << char (10);
    }
    else cout << "ERROR!! En la lectura del archivo \n";
    bi.close();
    doc.close();
}
