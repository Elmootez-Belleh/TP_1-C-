#ifndef LIVRE_H
#define LIVRE_H
#include <string>
#include "Auteur.h"
#include "lecteur.h"
#include "date.h"

/// Partie 1 : Creation des classes

/*!
 * \brief La classe Livre nous a permis de repondre a la question (2.a) du TP a savoir:
 * Créer la classe Livre avec ses variables membres, ses méthodes getters et toutes les méthodes et fonctions helper nécessaires.
 * Les variables membres sont:



2.d) Tester et valider les classes Auteur et Livre.

 */
class Livre{

private:
    std::string _title;
    std::string _langue;
    std::string _genre;

      std::string _IdAuteur;
    std::string _date_de_publication;
    std::string _ISBN;
    std::string _status;
  //  std::string _identifiant;
   // std::list<std::string> _identifiants;
   // Auteur* _auteur;
   // Lecteur* _lecteur;
   // Date* _date;
   // int _nb_lecteur;
   // std::vector<std::string> auteurs;
    std::vector<std::string> lecteurs;



    // list<Person> lp = new list<Person>();
     //    Person p = new Person();
    //     p.Name = "Smith";
     //    lp.insert(p);

public:

    Livre();
    Livre(std::string title, std::string IdAuteur, std::string date_de_publication,
                 std::string ISBN,std::string genre,std::string langue,std::string status );
    /// Getters :
    std::string  getTitle();
     std::string  getAuteur();
    std::string get_title(std::string title);

    std::string get_auteur(std::string auteur);

    std::string get_langue(std::string langue);
    std::string get_genre(std::string genre);
    std::string get_date_de_publication(std::string date_de_publication);
    int get_nb_lecteur(int nb_identifiant);
    unsigned long int get_ISBN(unsigned long int ISBN);
    unsigned long int get_identifiants(unsigned long int identifiant[]);
    Auteur get_auteur();
    std::string get_Informations();


    ///setters
    void set_title();
    void setTitleFromFile(std::string title);
    void set_langue();
    void setLangueFromFile(std::string langue);
    void set_genre();
    void setGenreFromFile(std::string genre);
    void set_date_de_publication();
    void setDateDePublicationFromFile(std::string date_de_publication);
    void set_nb_lecteur();
    void setNbLecteurFromFile(int nb_lecteur);
    void set_ISBN();
    void setISBNFromFile(std::string ISBN);
    void set_identifiants(std::string identifiant);
    void setIdentifiantsEmprunteursFromFile(std::string IdEmprunteur);
    void set_auteur();
    //void set_auteur(std::string IdAuteur);
    void setIdAuteurFromFile(std::string IdAuteur);
    void set_Auteur(Auteur aut);
    std::string setIdentifiant();
    std::string setIdentifiantFromFile(std::string identifiant);




    /// Chargement de l'operateur:
   // std::string toString();

    const  std::string toString();
    void toStringHeader();

    std::string  getAuteurs() const;
    void setAuteurs(std::string const &value);
    std::string getStatus() const;
    void setStatus(const std::string &status);
    std::string getISBN() const;
    void setISBN(const std::string &ISBN);
    std::string displayLivreInfo();
};



#endif // LIVRE_H
