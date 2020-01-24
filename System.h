// Federico Luisetto    1187521
#include <iostream>
#include <string>
#include <list>

using namespace std;

class System {

    public:
        /**
         * errori
         */
        class no_such_component{};  //non vi sono abbastanza componenti
        class invalid_id{};     //id errato
        class invalid_name{};   //name errato
        class invalid_qnt{};    //quantita' errata
        class invalid_month{};  //mese errato
        /**
         * costruttore
         */
        System();
        /**
         * distruttore
         */
        virtual ~System();
        /**
         * inserisce nuovi componenti ordinati
         * ordinamento in base al mese
         * in: (component_id, quantity, month)
         */
        void add_c_shop(int,int,int);
        /**
         * inserisce nuovi componenti in magazzino
         * quando arrivano i componenti si aggiungono automaticamente
         * in: (component_id, quantity)
         */
        void add_c_stock(int, int);
        /**
         * inserisce in lista gli ordini evasi
         * in: (model_name, quantity)
         */
        void add_m_sold(string, int);
        /**
         * toglie un mese ad ogni componente della lista c_ord
         */
        void add_month();
        /**
         * toglie i componenti necessari alla produzione dal magazzino
         * e ritorna la disponibilita' del magazzino
         * in: (component_id, quantity)
         * out: bool
         */
        bool catch_from_stock(int, int);
        /**
         * stampa lo stato corrente quando un ordine e' evaso
         * out: (c_ord, c_stock, m_done)
         */
        void print_current_status();

        //definizione strutture
        /**
         * componenti ordinati e non ancora arrivati
         * month indica il mese di arrivo dei componenti
         */
        typedef struct {
            int component_id;
            int quantity;
            int month;
        } shop_done;
        /**
         * componenti arrivati in magazzino ma non ancora usati
         * quantity e' quantita' totale di un componente
         */
        typedef struct {
            int component_id;
            int quantity;
        } stock;
        /**
         * ordini evasi
         */
        typedef struct {
            string model_name;
            int quantity;
        } order_sold;

    private:
        list<shop_done> c_ord;
        list<stock> c_stock;
        list<order_sold> m_done;
};