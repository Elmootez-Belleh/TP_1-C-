#include "bibliotheque.h"
#include "date.h"
#include <sstream>

static Livre livre;


vector<Lecteur> Bibliotheque::getLecteurs() const
{
    return _lecteurs;
}

void Bibliotheque::setLecteurs(const vector<Lecteur> &value)
{
    _lecteurs = value;
}

vector<Livre> Bibliotheque::getLivres() const
{
    return _livres;
}

void Bibliotheque::setLivres(const vector<Livre> &value)
{
    _livres = value;
}

vector<Emprunt> Bibliotheque::getEmprunts() const
{
    return _emprunts;
}

void Bibliotheque::setEmprunts(const vector<Emprunt> &value)
{
    _emprunts = value;
}

vector<Auteur> Bibliotheque::getAuteurs() const
{
    return _auteurs;
}

void Bibliotheque::setAuteurs(const vector<Auteur> &value)
{
    _auteurs = value;
}

void Bibliotheque::newLecteur(Lecteur *lecteur)
{
  this->_lecteurs.push_back(*lecteur) ;

}

void Bibliotheque::newLivre(const Livre &livre)
{
   std::string test= livre.getISBN();
   _livres.push_back(livre) ;
}

void Bibliotheque::newAuteur(Auteur *auteur)
{
    this->_auteurs.push_back(*auteur) ;
}

void Bibliotheque::newEmprunt(Emprunt *emprunt)
{
    this->_emprunts.push_back(*emprunt) ;
}

Livre Bibliotheque::getLivreByIndex(unsigned int index) const
{
      return   _livres[index];
}
Auteur Bibliotheque::getAuteurByIndex(unsigned int index) const
{
      return   _auteurs[index];
}
Lecteur Bibliotheque::getLecteurByIndex(unsigned int index) const
{
      return   _lecteurs[index];
}
Emprunt Bibliotheque::getEmpruntByIndex(unsigned int index) const
{
      return   _emprunts[index];
}
/*!
 * \brief Bibliotheque::emprunterLivre reponse a la question (6.c)
 * c'est une méthodes  permettant à un lecteur d'emprunter un livre disponible (Ne pas oublier d’ajouter une variable membre supplémentaire dans la classe Livre)
 * et de restituer un livre emprunté.
 * \param idAuteur est un parametre d'entree contenant l'identifiant du lecteur
 * \param isbn contenant l'identifiant du livre
 * \return  une drapau  permettant d'afficher un message a un utilisateur
 */
unsigned int Bibliotheque::emprunterLivre(std::string idLecteur, std::string isbn)
{
    unsigned int result=0;


    Date *date=new Date();
    date->updateDay();
    date->updateMonth();
    date->updateYear();
    std::string status;
    unsigned int i;
    for(i = 0; i < _livres.size(); i++)
                      {
                            if (_livres[i].getISBN()==isbn)
                            {
                                status=_livres[i].getStatus();
                                break;
                            }
                        }

       if(status=="disponible") {
                Emprunt *l1=new Emprunt(idLecteur,isbn, date->toString());
                _emprunts.push_back(*l1);
                for(unsigned int j= 0; j < _lecteurs.size(); j++)
                                  {
                                        if (_lecteurs[j].getIdLecteur()==idLecteur)
                                        {
                                          _lecteurs[j].setListISBN(isbn);
                                          _livres[i].setStatus("indisponible");
                                            break;
                                        }
                                    }
                result=1;
              }
       else{
           cout<<"le livre n'est pas disponible"<<endl;
       }
       return result;
}

unsigned int Bibliotheque::loadEmprunteLivresFromFile(std::string idLecteur, std::string isbn,std::string _date )
{
    unsigned int result=0;
    std::string status;
    unsigned int i;
    for(i = 0; i < _livres.size(); i++)
                      {
                            if (_livres[i].getISBN()==isbn)
                            {
                                status=_livres[i].getStatus();
                                break;
                            }
                        }

       if(status=="disponible") {
                Emprunt *l1=new Emprunt(idLecteur,isbn, _date);
                _emprunts.push_back(*l1);
                for(unsigned int j= 0; j < _lecteurs.size(); j++)
                                  {
                                        if (_lecteurs[j].getIdLecteur()==idLecteur)
                                        {
                                          _lecteurs[j].setListISBN(isbn);
                                          _livres[i].setStatus("indisponible");
                                            break;
                                        }
                                    }
                result=1;
              }
       else{
           cout<<"le livre n'est pas disponible"<<endl;
       }
       return result;
}


std::string Bibliotheque::displayLivreInfo(std::string isbn)
{
    std::string res="";
    for(unsigned int i=0; i<_livres.size(); i++){

        if (_livres[i].getISBN()==isbn){
            res =_livres[i].displayLivreInfo();

        }

    }
    return res;

}
//7.a) Créer la méthode / fonction helper permettant de chercher tous les livres d'un auteur.
std::string Bibliotheque::afficherTousLivresAuteur(std::string idAuteur)
{
   //std::string res="";
   stringstream ss;

   for(unsigned int i = 0; i < _livres.size(); i++)
                     {
                           if (_livres[i].getAuteur()==idAuteur)
                           {
                                ss<<_livres[i].toString()<<endl;

                           }
                       }
   return ss.str();
}

std::string Bibliotheque::afficherTousLivresEmrunte()
{

   stringstream ss;
   unsigned int count=0;

   for(unsigned int i = 0; i < _livres.size(); i++)
                     {
                           if (_livres[i].getStatus()=="indisponible")
                           {
                                ss<<_livres[i].toString()<<endl;

                           }
                       }
   return ss.str();
}
//7.d) Créer la méthode / fonction helper permettant d'établir le classement des lecteurs en fonction du nombre de livres empruntés
unsigned int Bibliotheque::afficherNbLivresEmrunteparLecteur(std::string lecteur)
{
    //7.c) Créer la méthode / fonction helper permettant de chercher tous les livres empruntés par un lecteur.

   unsigned int count=0;


   for(unsigned int i = 0; i < _lecteurs.size(); i++)
                     {
                           if (_lecteurs[i].getIdLecteur()==lecteur)
                           {
                               for(unsigned int j = 0; j < _lecteurs[i].getListISBN().size(); j++)
                               {
                                  count++;

                               }



                           }
                       }
   return count;
}




std::string Bibliotheque::afficherTousLivresEmrunteparUnLecteur(std::string lecteur)
{
    //7.c) Créer la méthode / fonction helper permettant de chercher tous les livres empruntés par un lecteur.

   stringstream ss;


   for(unsigned int i = 0; i < _lecteurs.size(); i++)
                     {
                           if (_lecteurs[i].getIdLecteur()==lecteur)
                           {
                               for(unsigned int j = 0; j < _lecteurs[i].getListISBN().size(); j++)
                               {
                                  ss<<_lecteurs[i].getListISBN()[j]<<endl;

                               }



                           }
                       }
   return ss.str();
}


unsigned int Bibliotheque::pourcentageTousLivresEmprunte()
{

   //stringstream ss;
   unsigned int count=0;

   for(unsigned int i = 0; i < _livres.size(); i++)
                     {
                           if (_livres[i].getStatus()=="indisponible")
                           {
                              //  ss<<_livres[i].toString()<<endl;
                               count++;

                           }
                       }
   return (count/_livres.size())*100;
}


std::string Bibliotheque::displayAuteurInfo(string idAuteur)
{
    std::string res="";
    for(unsigned int i=0; i<_auteurs.size(); i++){

        if (_auteurs[i].getIdAuteur()==idAuteur){
            res =_auteurs[i].displayAuteurInfo();

        }

    }
    return res;
}
std::string Bibliotheque::displayLecteurInfo(string idLecteur)
{
    std::string res="";
    for(unsigned int i=0; i<_lecteurs.size(); i++){

        if (_lecteurs[i].getIdLecteur()==idLecteur){

            res =_lecteurs[i].displayLecteurInfo();

        }

    }
    return res;
}
Bibliotheque::Bibliotheque()
{

}
