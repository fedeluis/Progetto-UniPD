// Federico Luisetto    1187521
#include <iostream>
#include <string>
#include "Model.h"

//costruttori
Model::Model()
    :id{-1}, name{""}, comp{}
    {}
Model::Model(int mid, string mname)
    :id{mid}, name{mname}, comp{}
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
int Model::get_m_id() {
    return this->id;
}
string Model::get_m_name() {
    return this->name;
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
string Model::print_component() {
    string output = "Componenti:\n";
    for(int i=0; i<comp.size(); i++) {
        output = output + "id: " + to_string(comp.front().c_id) + ", name: " + comp.front().c_name + ", quantita': " + to_string(comp.front().qnt) + "\n";
        component tmp = comp.front();
        comp.push_back(tmp);
        comp.pop_front();
    }
    return output;
}