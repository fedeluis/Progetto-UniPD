//Federico Luisetto 1187521
#include <iostream>
#include <string>
#include "System.h"

using namespace std;
/**
 * 
 * WARNING
 * 
 * CONTROLLO INPUT NON FATTO !!!
 * 
 * 
 */

//costruttore
System::System()
    : c_ord{}, c_stock{}, m_done{}
    {}
//distruttore
System::~System() {
    c_ord.clear();
    c_stock.clear();
    m_done.clear();
}
void System::add_c_shop(int cid, int mon, int qnt) {
    shop_done new_c = {cid,mon,qnt};    //componenete da aggiungere alla lista ordini
    
    /**
     * CODICE DA MIGLIORARE!
     */
    int count = 0;
    while(c_ord.front().component_id < cid) {   //metto in coda tutti i componenti che arrivano prima
        c_ord.push_back(c_ord.front());
        c_ord.pop_front();
        count++;
    }
    c_ord.push_front(new_c);    //inserisco nuovo componente in arrivo
    while(count>0) {    //metto in testa tutti i componenti che arrivano prima
        c_ord.push_front(c_ord.back());
        c_ord.pop_back();
        count--;
    }
}
void System::add_c_stock(int cid, int qnt) {
    /**
     * CODICE DA MIGLIORARE!
     */

    int size = c_stock.size();  //salvo grandezza lista

    //controllo se componente è già inserito
    while(size>0) {
        if(c_stock.front().component_id == cid) {
            c_stock.front().quantity += qnt;
            break;
        }
        c_stock.push_back(c_stock.front());
        c_stock.pop_front();
        size--;
    }
    //altrimenti aggiungo in coda
    stock stk = {cid,qnt};
    c_stock.push_back(stk);
}
void System::add_m_sold(string mname, int qnt) {
    order_sold osold = {mname,qnt};
    m_done.push_back(osold);
}
void System::add_month() {
    int size = c_ord.size();

    /**
     * CODICE DA MIGLIORARE!
     */
    while(size>0) {
        c_ord.front().month--;
        
        if(c_ord.front().month == 0)  //se il componenete è arrivato lo aggiungo allo stock
            add_c_stock(c_ord.front().component_id, c_ord.front().quantity);
        else  //altrimenti metto in coda
            c_ord.push_back(c_ord.front());
        
        c_ord.pop_front();
        size--;
    }
}
bool System::catch_from_stock(int cid, int qnt) {
    int size = c_stock.size();

    //cerco il componente necessario
    while(size>0) {
        if(c_stock.front().component_id == cid) {   //componente trovato
            if(c_stock.front().quantity >= qnt) {   //controllo quantita'
                c_stock.front().quantity -= qnt;
                if(c_stock.front().quantity == 0)   //controllo se ci sono ancora componenti in magazzino
                    c_stock.pop_front();
                return true;
            }
            else    //non si dispone quantita' richiesta
                return false;
        }

        c_stock.push_back(c_stock.front());
        c_stock.pop_front();
        size--;
    }
    return false;
}
void System::print_current_status() {
    cout << "\nStampa stato corrente...\n\nComponenti in arrivo:\n";
    int size = c_ord.size();
    while(size>0) {
        cout << "id: [" << c_ord.front().component_id << "]\tquantita': [" << c_ord.front().quantity << "]\tarrivo previsto: " << c_ord.front().month << " mesi" << endl;
        c_ord.push_back(c_ord.front());
        c_ord.pop_front();
        size--;
    }
    cout << "\nComponeneti in magazzino:\n";
    size = c_stock.size();
    while(size>0) {
        cout << "id: [" << c_stock.front().component_id << "]\tquantita': [" << c_stock.front().quantity << "]" << endl;
        c_stock.push_back(c_stock.front());
        c_stock.pop_front();
        size--;
    }
    cout << "\nElettrodomestici spediti:\n";
    size = m_done.size();
    while(size>0) {
        cout << "nome: [" << m_done.front().model_name << "]\tquantita': [" << m_done.front().quantity << "]" << endl;
        m_done.push_back(m_done.front());
        m_done.pop_front();
        size--;
    }
}