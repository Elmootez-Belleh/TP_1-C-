#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include "lecteur.h"
#include"Livre.h"
#include "emprunt.h"
#include"Auteur.h"

/*!
 * \brief La classe Bibliotheque  nous permet de repondre a la question (6.a)
 *  Créer la classe Bibliothèque avec ses variables membres et ses fonctions getters.

6.b) Créer les méthodes / fonctions helper permettant d’ajouter un Auteur, un Livre et un Lecteur à la bibliothèque.

6.c) Créer les méthodes / fonctions helper permettant à un lecteur d'emprunter un livre disponible (Ne pas oublier d’ajouter une variable membre supplémentaire dans la classe Livre) et de restituer un livre emprunté. Attention, un Lecteur peut restituer un livre qu’il a emprunté mais pas un livre emprunté par un autre Lecteur.
 */
class Bibliotheque
{
    private:

      vector<Lecteur> _lecteurs;
      vector<Livre> _livres;
      vector<Emprunt> _emprunts;
      vector<Auteur> _auteurs;
public:
    Bibliotheque();
    vector<Lecteur> getLecteurs() const;
    void setLecteurs(const vector<Lecteur> &value);
    vector<Livre> getLivres() const;
    void setLivres(const vector<Livre> &value);
    vector<Emprunt> getEmprunts() const;
    void setEmprunts(const vector<Emprunt> &value);
    vector<Auteur> getAuteurs() const;
    void setAuteurs(const vector<Auteur> &value);

    void newLecteur(Lecteur *lecteur);
    void newLivre(const Livre &livre);
    void newAuteur(Auteur *auteur);
    void newEmprunt(Emprunt *emprunt);


     Livre  getLivreByIndex(unsigned int index) const;

    unsigned int emprunterLivre(std::string idAuteur, std::string isbn);
    std::string displayLivreInfo(std::string isbn);
    std::string displayAuteurInfo(std::string idAuteur);
    std::string displayLecteurInfo(string idLecteur);
    Auteur getAuteurByIndex(unsigned int index) const;
    Lecteur getLecteurByIndex(unsigned int index) const;
    Emprunt getEmpruntByIndex(unsigned int index) const;
    unsigned int loadEmprunteLivresFromFile(std::string idLecteur, std::string isbn, std::string _date);
     std::string afficherTousLivresAuteur(std::string idAuteur);


     std::string afficherTousLivresEmrunte();
     unsigned int pourcentageTousLivresEmprunte();
     std::string afficherTousLivresEmrunteparUnLecteur(std::string lecteur);
     unsigned int afficherNbLivresEmrunteparLecteur(std::string lecteur);
};

#endif // BIBLIOTHEQUE_H
