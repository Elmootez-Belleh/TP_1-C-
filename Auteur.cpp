#include<iostream>
#include <sstream>
#include"Auteur.h"

using namespace std;

 std::string Auteur::getIdAuteur() const
{
    return _idAuteur;
}

void Auteur::setIdAuteur()
{
    std::string idAuteur;
    cout<<" Veuillez saisir l'identifiant de l'auteur s'il vous plait : "<<flush;
    cin>>idAuteur;
    this->_idAuteur=idAuteur;

}

string Auteur::displayAuteurInfo()
{

    std::string _idAuteur;
   std::string _nom;
   std::string _prenom;
   std::string _date_naissance_auteur;

    //6.b) Ajouter une surcharge de l'operateur << à la classe Lecteur permettant de faire l'affichage à l'écran de la liste des informations d'un lecteur.
          //  Ajouter également une surcharge de l'operateur << aux classes Auteur et Livre permettant de faire l'affichage à l'écran de la liste de toutes les informations d'un livre.
        std::stringstream  ss;
        ss<<" Auteur: ";
        ss<<_idAuteur;
        ss<< "\n";
        ss<<" Nom: ";
        ss<<_nom;

         ss<<"\n";
       ss<<"  Prenom: ";
        ss<<_prenom;
           ss<< "\n";
        ss<<"Date_naissance_auteur ";
        ss<<_date_naissance_auteur;

       return  ss.str();





}

Auteur::Auteur(){
     _idAuteur="";
    _nom="";
    _prenom="";
    _date_naissance_auteur="";
}
//Auteur::Auteur(std::string idAuteur,std::string nom,std::string prenom, std::string date_auteur)
Auteur::Auteur( std::string idAuteur,std::string nom,std::string prenom, std::string date_naissance_auteur)
{

     this->_idAuteur=idAuteur;
      _nom=nom;
      _prenom=prenom;
      _date_naissance_auteur=date_naissance_auteur;
}

/// Affichage:

void Auteur::afficher(){
    cout<<"============================= Auteur ================================"<<endl;
}

/// Setters:

void Auteur::set_identifiant(){
        unsigned int identifiant;
        cout<<" Veuillez saisir l'identifiant de l'auteur s'il vous plait : "<<flush;
        cin>>identifiant;
        this->_idAuteur=identifiant;
    }

    void Auteur::setIdAuteurFromFile( std::string IdAuteur){
        this->_idAuteur=IdAuteur;
    }


    void Auteur::set_nom(){
        std::string nom;
        cout<<" Veuillez saisir le nom de l'auteur s'il vous plait : "<<flush;
        cin>>nom;
        this->_nom=nom;
    }

    void Auteur::set_prenom(){
        std::string prenom;
        cout<<" Veuillez saisir le prenom de l'auteur s'il vous plait : "<<flush;
        cin>>prenom;
        this->_prenom=prenom;
    }

    string Auteur::set_date(){

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
      //  dd.str();
      //  _date_naissance_auteur = dd.str();
        this->_date_naissance_auteur=dd.str();
        return _date_naissance_auteur;

    }

    std::string Auteur::toString(){

        stringstream ss;

        ss<<_nom;
        ss<<";";
        ss<<_prenom;
        ss<<";";
        ss<<_idAuteur;
        ss<<";";
        ss<<_date_naissance_auteur;
        //cout<<endl;
        //cout<<" "<<ss.str()<<endl;

        return ss.str();

    }

