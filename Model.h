// Federico Luisetto    1187521
#include <iostream>
#include <list>

using namespace std;

class Model {
   
    public:
        /**
         * errori
         */
        class invalid_id{};     //id errato
        class invalid_name{};   //name errato
        class invalid_qnt{};    //quantita' errata
        class invalid_index{};  //indice errato
        class invalid_price{};  //prezzo errato
        class invalid_file{};   //file in apertura non valido
        /**
         * costruttore di default
         */
        Model();
        /**
         * costruttore con parametri
         * in: (id,name,price)
         */
        Model(int,string,double);
        /**
         * distruttore
         */
        virtual ~Model();
        /**
         * funzione che aggiunge id all'elettrodomestico
         * in: (id)
         */
        void set_id(int);
        /**
         * funzione che aggiunge name all'elettrodomestico
         * in: (name)
         */
        void set_name(string);
        /**
         * funzione che aggiunge un componente alla lista in coda
         * in: (c_id,c_name,qnt)
         */
        void add_component(int,string,int);
        /**
         * funzione che aggiunge prezzo all'elettrodomestico
         * in: (price)
         */
        void set_price(double);
        /**
         * funzioni get model
         * in: non servono parametri
         */
        int get_m_id();
        string get_m_name();
        double get_m_price();
        /**
         * funzioni get component
         * in: index lista
         */
        int get_c_id(int);
        string get_c_name(int);
        int get_c_qnt(int);
        /**
         * funzione che ritorna numero di componenti
         */
        int get_num_c();
        /**
         * stampa tutte le specifiche dei componenti
         */
        void print_component();

        //lista di componenti
        typedef struct {

            int c_id;
            string c_name;
            int qnt;    //quantita' necessaria
        } component;

    private:
        //variabili
        int id;
        string name;
        list<component> comp;    //lista componenti
        double price;
        //  http://www.cplusplus.com/reference/list/list/
};