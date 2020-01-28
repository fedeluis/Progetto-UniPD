// Federico Luisetto    1187521
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
    string reader;
    ifstream file{"files/models.dat"}; //apre il file models.dat
	
    if(!file) 
        throw Model::invalid_file();

    //legge ogni riga e la salva
    do {
        file>>reader;
        nomi.push_back("files/"+reader);
        getline(file,reader);
    } while(file);

    // chiude il file models.dat
    file.close();


    /**
     * leggo ed inserisco modelli
     */
    for(int index=0; index<nomi.size(); index++) {
        Model mod;
        int id, qnt;    //componente
        string name;    //componente
        /**
        * lettura file
        */
        ifstream file{nomi[index]}; //apre il file salvato in nomi[]

        if(!file)
            throw Model::invalid_file();

        bool first_row = true; //differenzia lettura righe

        /* legge e stampa ogni riga */
    
        do {
            //id
            file>>reader;
            if(first_row)
                mod.set_id(stoi(reader));
            else
                id = stoi(reader);
            
            //name
            file>>reader;
            if(first_row)
                mod.set_name(reader);
            else
                name = reader;

            //price or quantity needed
            file>>reader;
            if(first_row)
                mod.set_price(stoi(reader));
            else
                qnt = stoi(reader);
            
            if(first_row)   //dopo una lettura first_row=false
                first_row = false;
            else    //da seconda riga inserisco componenti
                mod.add_component(id,name,qnt);

            getline(file,reader);
        } while(file);

        // chiudo il file di indice index
        file.close();

        //inserisco nella lista modello letto
        output.push_back(mod);
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