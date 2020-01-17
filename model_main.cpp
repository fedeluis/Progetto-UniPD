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
        if(first_row) {
            //ricavo id e name
            bool id_found = false;
            bool name_found = false;
            for(int i=0; i<100; i++) {
                if(!id_found && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //inserisco id
                    mod.set_id(stoi(tmp));  // stoi: converte stringa in intero
                    id_found = true;        // ho trovato id
                }
                if(!name_found && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //inserisco id
                    mod.set_name(tmp);  //inserisco nome
                    name_found = true;    // ho trovato id
                }
            }
            first_row = false;
        }
        else {
            //variabili di controllo e parametri
            bool id_found = false;
            bool name_found = false;
            bool qnt_found = false;
            int id, qnt;
            string name;

            for(int i=0; i<100; i++) {
                if(!id_found && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //salvo id
                    id = stoi(tmp);  // stoi: converte stringa in intero
                    id_found = true; // ho trovato id
                }
                if(!name_found && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //salvo name
                    name = tmp;
                    name_found = true; // ho trovato name
                }
                if(!qnt_found && buf[i]=='[') {
                    i++;
                    string tmp = "";
                    while(buf[i]!=']') {
                        tmp += buf[i];
                        i++;
                    }
                    //salvo qnt
                    qnt = stoi(tmp);  // stoi: converte stringa in intero
                    qnt_found = true; // ho trovato id
                }
            }
            mod.add_component(id,name,qnt);
        }
    }

    /* chiude il file */
    fclose(fd);
    cout << "id: " << mod.get_m_id() << "\nname: " << mod.get_m_name() << endl;
    cout << mod.print_component();
    return 0;
}