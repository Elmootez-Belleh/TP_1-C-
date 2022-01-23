#include <iostream>
#include "emprunt.h"
#include <sstream>


Emprunt::Emprunt()
{ 

}
Emprunt::Emprunt(std::string lecteur,std::string ISBN, std::string date){


            this->_idLecteur=lecteur;
             this->_ISBN=ISBN;
             this->_dateEmprunt=date;
}

/*
Emprunt::Emprunt(string date, Livre *livre, Lecteur *lecteur) : _dateEmprunt(date),
    _livre(livre),
    _lecteur(lecteur)
{
  //  std::string _myISBN = getISBN();

    lecteur->setListISBN(_ISBN);

}*/

void Emprunt::setISBN()
{
    cout<<" ================  Informations sur l'ISBN  ==============="<<endl;
    std::string ISBN;
    cout<<" Veuillez saisir le ISBN s'il vous plait : "<<flush;
    cin>>ISBN;
    _ISBN = ISBN;
}

void Emprunt::setIdentifiant()
{
    cout<<" ================  Informations sur l'identifiant  ==============="<<endl;
    std::string identifiant;
    cout<<" Veuillez saisir votre identifiant s'il vous plait : "<<flush;
    cin >> identifiant;
    _idLecteur = identifiant;
}

void Emprunt::setDate(){
    cout<<" ================  Date d'Emprunt  ==============="<<endl;
    std::string dateEmprunt;
    int day=1;
    int year=1;
    int month=1;
    Date *date=new Date(1,1,1);
    date->updateDay();
    date->updateMonth();
    date->updateYear();
    day=date->day();
    month=date->month();
    year=date->year();
    Date(day,month,year);
    stringstream dd;
    if(day<10)
        dd<<"0"<<day;
    else
        dd<<day;
    dd<<"/";
    if(month<10)
        dd<<"0"<<day;
    else
        dd<<month;
    dd<<"/";
    dd<<year;
    dd.str();
    dateEmprunt = dd.str();
    this->_dateEmprunt=dateEmprunt;
}


std::string Emprunt::getISBN(){
    return _ISBN;
}

std::string Emprunt::getIdentifiant(){
    return _idLecteur;
}
std::string Emprunt::getDate(){
    return _dateEmprunt;
}

 std::string Emprunt::toString(){

   // cout<<" Voici les informations que vous avez saisis : "<<endl;

    stringstream ss;

    ss<<_idLecteur;
     ss<<";";
    ss<<_ISBN;
     ss<<";";
    ss<<_dateEmprunt;
  //  cout<<ss.str()<<endl;
    return ss.str();

 }



