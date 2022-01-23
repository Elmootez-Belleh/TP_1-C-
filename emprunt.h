#ifndef EMPRUNT_H
#define EMPRUNT_H
#include <string>
#include "date.h"
#include "Livre.h"
#include "lecteur.h"

using namespace std;

/*!
 * \brief La classe  Emprunt nous a permis de repondre a la question  (4.a)
 * Créer la classe Emprunt avec ses variables membres et ses fonctions getters.


 */

class Emprunt
{

private:
    std::string _idLecteur;
    std::string _ISBN;
    std::string _dateEmprunt;
   // Livre* _livre;
  //  Lecteur* _lecteur;

public:
    Emprunt();
    Emprunt(std::string lecteur,std::string ISBN, std::string date);
  //  Emprunt(std::string date, Livre *livre, Lecteur *lecteur);
    //setters:
    const std::string &identifiant() const;
    const std::string &ISBN() const;
    std::string getIdentifiant();
    std::string getISBN();
    std::string getDate();
    void setISBN();
    void setIdentifiant();
    void setDate();
     std::string toString();
  //   void displayAuteurInfo(std::string idAuteur);

};

#endif // EMPRUNT_H
