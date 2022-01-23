#ifndef LECTEUR_H
#define LECTEUR_H
#include <string>
#include <vector>
//#include <list>
#include<iostream>


 /*!
 * \brief La classe Lecteur nous a permis de repondre a la question (3.a)
 * Créer la classe Lecteur avec ses variables membres, ses méthodes getters et toutes les méthodes / fonctions helper nécessaires.

 */
class Lecteur {

private:

  std::string _idLecteur;
  std::string _nom;
  std::string _prenom;
 std::vector<std::string> _lisItSBN;
// std::vector<std::string> _listISBN;

public:
  //initialisation sans paramètre
    Lecteur();
    Lecteur(std::string identifiant,std::string nom,std::string prenom);


  //initialisation avec paramètre
//    Lecteur(std::string nom , std::string prenom , std::string identifiant , std::vector<std::string> liste);

  //getters
    std::string getNom();
    std::string getPrenom();
    std::string getID();
    //std::string getVecteurISBN();
    std::vector<std::string> getListISBN();


  //setters
    void setNom();
    void setPrenom();
    void setID();
    void setListeISBNLivresEmpruntes();
    void setListISBN(std::string isbn);

  //fonction
    void addISBNtoListe (std::string ISBN);

   std::string toString();
   std::string getIdLecteur() const;
   void setIdLecteur(const std::string &idLecteur);
   std::string displayLecteurInfo();
};

#endif // LECTEUR_H
