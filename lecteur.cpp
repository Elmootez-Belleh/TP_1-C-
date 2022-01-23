//Partie 1 : Création des classes
//Création de Lecteur
//lecteur.cpp

#include<iostream>
#include "lecteur.h"
#include <sstream>
#include <string>





    // initialization sans paramètre
std::string Lecteur::getIdLecteur() const
{
    return _idLecteur;
}

void Lecteur::setIdLecteur(const std::string &idLecteur)
{
    _idLecteur = idLecteur;
}

Lecteur::Lecteur(){
    _idLecteur="";
    _nom="";
    _prenom="";
    _lisItSBN={""};
}

Lecteur::Lecteur(std::string identifiant,std::string nom,std::string prenom){
        _idLecteur=identifiant;
        _nom=nom;
        _prenom=prenom;

    }

//    //initialisation avec paramètre
//    Lecteur::Lecteur(std::string nom , std::string prenom , std::string identifiant , std::vector<std::string> liste){
//        _nom = nom;
//        _prenom = prenom;
//        _identifiant = identifiant;
//        _liste = liste;
//    }

    //setters
    void Lecteur::setNom() { // saisir "nom"
        std::string nom;
        std::cout << " Veuillez saisir votre nom s'il vous plait : " << std::flush;
        std::cin >> nom;
        this->_nom = nom;
    }
    void Lecteur::setPrenom() {// saisir "prenom"
        std::string prenom;
        std::cout << " Veuillez saisir votre prenom s'il vous plait : " << std::flush;
        std::cin >> prenom;
        this -> _prenom = prenom;
     }
    void Lecteur::setID() {// saisir "identifiant"
        std::string identifiant;
        std::cout << " Veuillez saisir votre identifiant s'il vous plait : " << std::flush;
        std::cin >> identifiant;
        this-> _idLecteur = identifiant;
     }
    void Lecteur::setListeISBNLivresEmpruntes() {// saisir "liste"
        std::vector<std::string> liste;
        std::string terme = "";
        int i = 1;
        while (terme != "00"){
            std::cout << " Veuillez saisir l'ISBN numero " << i++ <<" : "<< " ('00' pour terminer) : " << std::flush;
            std::cin >> terme;
            liste.push_back(terme);
     }
        liste.pop_back(); // enlève "00" de la liste
        this-> _lisItSBN = liste;
    }
    void Lecteur::setListISBN(std::string isbn){
        // il faut verifier que le ISBN existe dans la class Livre

        //
        _lisItSBN.push_back(isbn);


        // il faut verifier que le Livre n'est pas emprunte par quelqu'un d'autre
        /// il faut que le ISBN de chaque livre soit enregistre une seule fois meme si le lecteur l'avais emprunte plusieurs fois

    }

    //getter
    std::string Lecteur::getNom() {// renvoie "nom" en type string
        std::string nom = _nom;
        return nom;
    }
    std::string Lecteur::getPrenom() {// renvoie "prenom" en type string
        std::string prenom = _prenom;
        return prenom;
    }
    std::string Lecteur::getID() {// renvoie "identifiant" en type string
        std::string identifiant = _idLecteur;
        return identifiant;
    }

    std::vector<std::string> Lecteur::getListISBN(){
  //  std::string Lecteur::getListISBN() {           // renvoie l'enseble de "liste" en type string par l'operateur ss
      /*  std::vector<std::string> liste = _lisItSBN;
        std::stringstream ss;
        for(int i = 0 ; i < liste.size() ; i++ ){ //l'opérateur "ss" va ajouter les termes en string pour formé une chaine de string
            ss << " - ";
            ss << liste.at(i);
     }
        return ss.str();
        */
        return _lisItSBN;
    }

    //fonction

    // ajoute un ISBN à la liste
    void Lecteur::addISBNtoListe(std::string ISBN){
        std::vector<std::string> liste = _lisItSBN;
        liste.push_back(ISBN);
        this-> _lisItSBN = liste;
     }


    std::string Lecteur::toString(){

       std::stringstream  ss;
        ss<<_idLecteur;
        ss<<";";
        ss<<_nom;
        ss<<";";
        ss<<_prenom;
return ss.str();
    // std::cout<<ss.str()<< "\n";

    }

    std::string Lecteur::displayLecteurInfo()
    {
      //6.b) Ajouter une surcharge de l'operateur << à la classe Lecteur permettant de faire l'affichage à l'écran de la liste des informations d'un lecteur.
      //  Ajouter également une surcharge de l'operateur << aux classes Auteur et Livre permettant de faire l'affichage à l'écran de la liste de toutes les informations d'un livre.
    std::stringstream  ss;
    ss<<" Identifiant: ";
    ss<<_idLecteur;
       ss<< "\n";
      ss<<" Nom: ";
      ss<<_nom;
       ss<< "\n";
   ss<<" Prenom: ";
    ss<<_prenom << "\n";
    ss<<" liste des livres empruntes:"<< "\n";
    for(unsigned int i=0; i<_lisItSBN.size();i++){
        ss<<"\t";
        ss<<_lisItSBN[i];
                }
return ss.str();

    }
