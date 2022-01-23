#ifndef AUTEUR_H
#define AUTEUR_H
#include<string>
#include "date.h"

/*!
 * \brief La classe Auteur  nous a permis de repondre a la question (2.c) du TP a savoir:
 *  Créer une classe Auteur comprenant les informations (identifiant numérique, nom, prénom, date de naissance)
 *
 *
 *
 * et modifier la classe Livre pour tenir compte de la nouvelle classe Auteur

 */
class Auteur{

private:
     std::string _idAuteur;
    std::string _nom;
    std::string _prenom;
    std::string _date_naissance_auteur;
    //Date* _date;

public:

    Auteur();
   // Auteur(unsigned int idAuteur,std::string nom,std::string prenom, std::string date_naissance_auteur);
    Auteur( std::string idAuteur,std::string nom,std::string prenom, std::string date_naissance_auteur);

    /// Affichage :
    void afficher();

    ///Getters:
    std::string get_identifiant(std::string identifiant);
    std::string get_nom(std::string nom);
    std::string get_prenom(std::string prenom);
    void get_date();

    ///Setters:
    void set_identifiant();
    void setIdAuteurFromFile(std::string IdAuteur);
    void set_nom();
    void setNomFromFile(std::string nom);
    void set_prenom();
    std::string set_date();

    /// Chargement de l'operateur:

    std::string toString();
     std::string getIdAuteur() const;
    void setIdAuteur();

    std::string displayAuteurInfo();
};

#endif // AUTEUR_H
