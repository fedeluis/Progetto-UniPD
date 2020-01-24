// Federico Luisetto    1187521
#include <iostream>
#include <string>
#include <fstream>
#include "Model.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Model mod;
    /**
     * lettura file
     */
    FILE *fd;
    char buf[100];
    char *res;


	/* apre il file */
    fd=fopen("files/lavatrice.dat", "r");
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
    /* chiude il file */
    fclose(fd);
    mod.print_component();
    return 0;
}