// Federico Luisetto    1187521
#include <iostream>
#include <string>
#include "Model.h"

//costruttori
Model::Model()
    :id{-1}, name{""}, comp{}, price{-1}
    {}
Model::Model(int mid, string mname, double mprice)
    :id{mid}, name{mname}, comp{}, price{mprice}
    {}
//distruttore
Model::~Model() {
    comp.clear();
}
void Model::set_id(int mid) {
    if(mid<0)
        throw invalid_id();
    this->id = mid;
}
void Model::set_name(string mname) {
    if(mname.length()==0)
        throw invalid_id();
    this->name = mname;
}
void Model::add_component(int cid, string cname, int q) {
    if(q<1)
        throw invalid_qnt();
    //creo variabile
    component n = {cid,cname,q};
    //aggiungo in coda
    comp.push_back(n);
}
void Model::set_price(double mprice) {
    if(mprice<0)
        throw invalid_price();
    this->price = mprice;
}
int Model::get_m_id() {
    return this->id;
}
string Model::get_m_name() {
    return this->name;
}
double Model::get_m_price() {
    return this->price;
}
int Model::get_c_id(int index) {
    if(index>=comp.size() || comp.empty())
        throw invalid_index();
    
    component output;

    //per ricavare l'output tolgo elementi dalla testa e li inserisco in coda
    for(int i=0; i<=index; i++) {
        if(i==index)
            output = comp.front();
        
        component tmp = comp.front();
        comp.push_back(tmp);
        comp.pop_front();
    }

    return output.c_id;
}
string Model::get_c_name(int index) {
    if(index>=comp.size() || comp.empty())
        throw invalid_index();
    
    component output;

    //per ricavare l'output tolgo elementi dalla testa e li inserisco in coda
    for(int i=0; i<=index; i++) {
        if(i==index)
            output = comp.front();
        
        component tmp = comp.front();
        comp.push_back(tmp);
        comp.pop_front();
    }

    return output.c_name;
}
int Model::get_c_qnt(int index) {
    if(index>=comp.size() || comp.empty())
        throw invalid_index();
    
    component output;

    //per ricavare l'output tolgo elementi dalla testa e li inserisco in coda
    for(int i=0; i<=index; i++) {
        if(i==index)
            output = comp.front();
        
        component tmp = comp.front();
        comp.push_back(tmp);
        comp.pop_front();
    }

    return output.qnt;
}
void Model::print_component() {
    cout << "Descrizione elettrodomestico..\nid: [" << id << "]\tnome: '" << name << "'\tprezzo: " << price << "$\nLista componeneti:\n";
    for(int i=0; i<comp.size(); i++) {
        cout << "id: [" << comp.front().c_id << "]\t nome: '" + comp.front().c_name << "'\t quantita': [" << comp.front().qnt << "]\n";
        comp.push_back(comp.front());
        comp.pop_front();
    }
    cout << endl;
}