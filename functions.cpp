#include "functions.h"

void con_bin(string name,string binario, int *bit_neg)
{

    short num;
    short int num_bi[8];
    //cout << name << "\n\n";

    fstream doc (name.c_str(), fstream :: in);
    char carac;

    if (!doc.fail()){
        fstream bi (binario.c_str(), fstream ::out | fstream::binary);
        short cont = -1,lugar = 0;

        while (!doc.eof()){

            cont ++;

            doc.get(carac);
            num = int (carac);

            //cout << num << "\t\t" << carac << "\t\t";
            if (num < 0){
                //num *= -1;
                bit_neg[lugar] = cont;
                lugar++;
            }

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

        }
        bit_neg[lugar]= '\0';
        //cout << char (10);
        bi.close();
    }
    else cout << "ERROR!! En la lectura del archivo\n\n\n";

    doc.close();
}

void metodo_1_codi(string name, short n,string save){

    fstream doc (name.c_str(), fstream :: in | fstream::ate);

    char carac;
    long long int num_caracteres = doc.tellg();
    int s1,s0,step;
    doc.seekg(0);
    //cout << carac << "\t " << num_caracteres << " HOLA\n\n\n";

    if (!doc.fail()){
        fstream codi(save.c_str(), fstream ::out | fstream::binary);

        for (int i = 0; i < n;i++){
            doc.get(carac);
            if (carac == '0') codi << '1';
            else if (carac == '1') codi << '0';
        }

        while(true){
            s1 = 0;
            s0 = 0;
            num_caracteres = doc.tellg();
            num_caracteres -= n;
            //cout << "\n\n"<< num_caracteres <<"\n\n";
            doc.seekg(num_caracteres);
            for (int a = 0; a < n;a++){
                doc.get(carac);
                if (carac == '0') s0 ++;
                else if (carac == '1') s1++;
            }


            if (s1 == s0){
                for (int a = 0; a < n;a++){
                    doc.get(carac);
                    if (carac == '0') codi << '1';
                    else if (carac == '1') codi << '0';
                    if (doc.eof()) break;
                }
            }
            else if (s0 > s1){
                step = 0;
                for (int a = 0; a < n;a++){
                    if (step != 1){
                        doc.get(carac);
                        codi << carac;
                        step++;
                    }
                    else {
                        doc.get(carac);
                        if (carac == '0') codi << '1';
                        else if (carac == '1') codi << '0';
                        step = 0;
                    }
                    if (doc.eof()) break;
                }
            }
            else if(s1>s0){
                step = 0;
                for (int a = 0; a < n;a++){
                    if (step != 2){
                        doc.get(carac);
                        codi << carac;
                        step++;
                    }
                    else {
                        doc.get(carac);
                        if (carac == '0') codi << '1';
                        else if (carac == '1') codi << '0';
                        step = 0;
                    }
                    if (doc.eof()) break;
                }
            }

            if (doc.eof()) break;
        }
        codi.close();
    }
    else cout << "ERROR!! En la lectura del archivo\n\n\n";

    doc.close();
    remove (name.c_str());
}

void metodo_1_deco(string name, short n,string bi)
{
    fstream doc (name.c_str(), fstream :: in);

    char carac;
    int s1,s0,step;
    //cout << carac << "\t " << num_caracteres << " HOLA\n\n\n";
    int vec[n];

    if (!doc.fail()){
        fstream codi(bi.c_str(), fstream ::out | fstream::binary);

        for (int i = 0; i < n;i++){
            doc.get(carac);
            if (carac == '0') {
                codi << '1';
                vec[i] = 1;
            }
            else if (carac == '1') {
                codi << '0';
                vec[i] = 0;
            }
        }

        while (true){

            s1 = 0;
            s0 = 0;
            for (int a = 0; a < n;a++){
                if (vec[a] == 0) s0 ++;
                else if (vec[a] == 1) s1++;
            }
            if (s1 == s0){
                for (int a = 0; a < n;a++){
                    doc.get(carac);
                    if (carac == '0') {
                        codi << '1';
                        vec[a] = 1;
                    }
                    else if (carac == '1') {
                        codi << '0';
                        vec[a] = 0;
                    }
                    if (doc.eof()) break;
                }
            }
            else if (s0 > s1){
                step = 0;
                for (int a = 0; a < n;a++){
                    if (step != 1){

                        doc.get(carac);
                        codi << carac;
                        if (carac == '0') vec[a] = 0;
                        else if (carac == '1') vec[a] = 1;
                        step++;
                    }
                    else {

                        doc.get(carac);
                        if (carac == '0') {
                            codi << '1';
                            vec[a] = 1;
                        }
                        else if (carac == '1') {
                            codi << '0';
                            vec[a] = 0;
                        }
                        step = 0;
                    }
                    if (doc.eof()) break;
                }
            }
            else if(s1>s0){
                step = 0;
                for (int a = 0; a < n;a++){
                    if (step != 2){

                        doc.get(carac);
                        codi << carac;
                        if (carac == '0') vec[a] = 0;
                        else if (carac == '1') vec[a] = 1;
                        step++;
                    }
                    else {

                        doc.get(carac);
                        if (carac == '0') {
                            codi << '1';
                            vec[a] = 1;
                        }
                        else if (carac == '1') {
                            codi << '0';
                            vec[a] = 0;
                        }
                        step = 0;
                    }
                    if (doc.eof()) break;
                }
            }
            //cout << doc.tellg() << "\n";
            if (doc.eof()) break;
        }
        codi.close();
    }
    else cout << "ERROR!! En la lectura del archivo\n\n\n";

    doc.close();
    remove (name.c_str());
}

void bin_tex(string name, string deco, int *bit_neg)
{
    fstream doc(name.c_str(), fstream :: in);

    fstream de(deco.c_str(), fstream ::out);

    char carac;
    int mul,num,cont = 0,lugar=0;
    int vec[8];
    bool ava = true;
    doc.seekg(0);


    while(!doc.eof()){
        mul = 128;
        num = 0;

        cout << cont << "\t\t" << bit_neg[lugar] << endl;

        if (cont == bit_neg[lugar]) {
            ava = false;
            lugar++;
        }


        for (int a = 0; a < 8;a++){
            doc.get(carac);
            if (carac == '0') vec[a] = 0;
            else if (carac == '1') vec[a] = 1;
        }
        for (int a = 0; a < 8;a++){
            if (vec[a] == 1) {
                num += mul;
            }
            mul /= 2;
        }

        if (ava == false){
            //cout << num*-1 << "\t\t" << char(num*-1) << "\n";
            num *= -1;
            ava = true;
        }

        carac = char (num);

        de << carac;
        cont ++;
    }

    doc.close();
    de.close();

   //remove (name.c_str());

}
