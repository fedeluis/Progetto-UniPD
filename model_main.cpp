// Federico Luisetto    1187521
#include <iostream>
#include <fstream>
#include <vector>
#include "Model.h"

using namespace std;

list<Model> scan_files() {
    list<Model> output; //contiene tutti gli elettrodomestici
    vector<string> nomi;    //contiene nomi file
    /**
     * lettura file
     */
    FILE *fd;
    char buf1[50];  //buffer per models.dat
    char buf[100];  //buffer per modelli
    char *res;


	//apre il file models.dat
    fd=fopen("files/models.dat", "r");
    if( fd==NULL ) {
        perror("Errore in apertura del file");
        exit(1);
    }
    //legge ogni riga e la salva
    while(1) {
        res=fgets(buf1, 50, fd);
        if( res==NULL )
            break;

        for(int i=0; i<50; i++) {
            if(buf1[i]=='[') {
                i++;
                string tmp = "files/";
                while(buf1[i]!=']') {
                    tmp += buf1[i];
                    i++;
                }
                //salvo nome in vettore
                nomi.push_back(tmp);
                cout << tmp <<endl; // PROVA OUTPUT PER TESTING
            }
        }
    }
    // chiude il file models.dat
    fclose(fd);


    /**
     * leggo ed inserisco modelli
     */
    for(int index=0; index<nomi.size(); index++) {
        Model mod;
        /**
        * lettura file
        */

	    // apre il file di indice index
        fd=fopen(nomi[index].c_str(), "r"); // <string>.c_str() converte stringa in const char*
        if( fd==NULL ) {
            perror("Errore in apertura del file");
            exit(1);
        }

        bool first_row = true; //differenzia lettura righe

        /* legge e stampa ogni riga */
    
        while(1) {
            res=fgets(buf, 100, fd);
            if( res==NULL )
                break;
        
            //variabili di controllo e parametri
            bool found1 = false;
            bool found2 = false;
            bool found3 = false;
            int id, qnt;
            string name;

            for(int i=0; i<100; i++) {
                if(!found1 && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //salvo id modello o componente
                    if(first_row)
                        mod.set_id(stoi(tmp));  // stoi: converte stringa in intero
                    else
                        id = stoi(tmp);
                    found1 = true; // ho trovato id
                }
                if(!found2 && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //salvo name modello o componenete
                    if(first_row)
                        mod.set_name(tmp);
                    else
                        name = tmp;
                    found2 = true; // ho trovato name
                }
                if(!found3 && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    if(first_row)   //inserisco prezzo
                        mod.set_price(stod(tmp));   // stod: converte stringa in double
                    else    //salvo qnt
                        qnt = stoi(tmp);  // stoi: converte stringa in intero
                    found3 = true; // ho trovato id
                }
            }
            if(first_row)   //dopo una lettura first_row=false
                first_row = false;
            else
                mod.add_component(id,name,qnt);
        }
        // chiudo il file di indice index
        fclose(fd);

        //inserisco nella lista modello letto
        output.push_back(mod);
        cout << "numero " << index << endl; // PROVA OUTPUT PER TESTING
        mod.print_component();  // PROVA OUTPUT PER TESTING
    }

    return output;
}

int main(int argc, char const *argv[])
{
    list<Model> mod = scan_files();
    for(int i=0; i<mod.size(); i++) {
        mod.front().print_component();
        mod.push_back(mod.front());
        mod.pop_front();
    }
    return 0;
}