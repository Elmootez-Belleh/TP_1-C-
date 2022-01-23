#include<iostream>
#include"Livre.h"
#include <sstream>
#include <string>


using namespace std;

std::string Livre::getAuteurs() const
{
    /*
  //  stringstream ss;


   //  cout<<ss.str()<<endl;
    // return ss.str();


      for(unsigned int i = 0; i < auteurs.size(); i++) // D’ailleurs, i++ ou ++i ?
                           {
                             std::string    aut=auteurs[i];
                                cout << aut << endl;
                                ss<<aut;
                                ss<<",";
                               }


   //to erase the last character of the string.

    std::string s = ss.str();
    if (!s.empty()) {
            s.pop_back();
        }
    cout<<s <<endl;*/

    return this->_IdAuteur;
}


void Livre::setAuteurs(std::string const &value)
{
    //auteurs = value;
    this->_IdAuteur=value;
    /*
    istringstream ss(value);
    string word;

   while (getline(ss, word,','))
         auteurs.push_back(word);
   */


}

std::string Livre::getStatus() const
{
    return _status;
}

void Livre::setStatus(const std::string &status)
{
    _status = status;
}

std::string Livre::getISBN() const
{
    return _ISBN;
}

void Livre::setISBN(const std::string &ISBN)
{
    _ISBN = ISBN;
}

Livre::Livre(){
    _title="";
    _IdAuteur="";
    _langue="";
    _genre="";
    _date_de_publication="";
    //_nb_lecteur=0;
    _ISBN="";
    //_identifiant="";
}


Livre::Livre(std::string title, std::string IdAuteur, std::string date_de_publication,
             std::string ISBN,std::string genre,std::string langue,std::string status ){

  // title;IdAuteur;date_de_publication;ISBN;identifiant;nb_lecteur;genre;langue

     this->_title=title;
     this->_IdAuteur= IdAuteur;
     this->_date_de_publication=date_de_publication;
    this->_ISBN=ISBN;
      //this->_identifiant=identifiant;
     // int intdata1 = stoi (nb_lecteur);
     //this->_nb_lecteur=intdata1;
     this->_genre=genre;
     this->_langue=langue;
     this->_status=status;

      //setAuteurs(IdAuteur);





}

    /// Setters
    ///
     void Livre::setTitleFromFile(std::string title)
     {
        this->_title=title;
     }

     void Livre::setLangueFromFile(std::string langue){
         this->_langue=langue;

     }
     void Livre::setGenreFromFile(std::string genre){
         this->_genre=genre;

     }
     void Livre::setDateDePublicationFromFile(std::string date_de_publication){
         this->_date_de_publication=date_de_publication;

     }
     /*
     void Livre::setNbLecteurFromFile(int nb_lecteur){
         this->_nb_lecteur=nb_lecteur;

     }*/
     void Livre::setISBNFromFile(std::string ISBN){
         this->_ISBN=ISBN;

     }

     void Livre::setIdAuteurFromFile(std::string IdAuteur){
    //  this->_auteur->setIdAuteurFromFile(IdAuteur);
      this->_IdAuteur=IdAuteur;
//this->auteurs.push_back(IdAuteur);


     }

     void Livre::setIdentifiantsEmprunteursFromFile(std::string IdEmprunteur){
       //  this->_identifiant=IdEmprunteur;
         this->lecteurs.push_back(IdEmprunteur);


     }

    void Livre::set_title(){
        cout<<" ================  Informations sur le livre  ==============="<<endl;
        std::string title;
        cout<<" Veuillez saisir le titre du livre s'il vous plait : "<<flush;
        cin>>title;
        this->_title=title;
    }
    void Livre::set_auteur(){
        cout<<" ================  Informations sur l'auteur  ==============="<<endl;
      Auteur *auteur = new Auteur();
      auteur->set_nom();
      auteur->set_prenom();
      auteur->set_identifiant();
      auteur->set_date();
      auteur->setIdAuteur();

    }
    void Livre::set_langue(){
        cout<<" ================  Langues  ==============="<<endl;
        int selection=0;
        cout<<" Langues disponibles : "<<endl;
        cout<<" 1 - Anglais (saisir 1) "<<endl;
        cout<<" 2 - Arabe (saisir 2)"<<endl;
        cout<<" 3 - Francais (saisir 3)"<<endl;
        cout<<" 4 - Espagnol (saisir 4)"<<endl;
        //do{
            cout<<" Veuillez saisir une langue s'il vous plait : "<<endl;
            cin>>selection;
            switch(selection){
                case 1:
                    _langue=" Anglais";
                    cout<<" Vous avez saisis : "<< _langue << endl;
                    break;
                case 2:
                    _langue=" Arabe";
                    cout<<" Vous avez saisis : "<< _langue << endl;
                    break;
                case 3:
                    _langue=" Francais";
                    cout<<" Vous avez saisis : "<< _langue << endl;
                    break;
                case 4:
                    _langue=" Espagnol";
                    cout<<" Vous avez saisis : "<< _langue << endl;
                    break;
                default:
                    cout<<" Veuillez saisir un chiffre entre 0 et 4 s'il vous plait !! "<<endl;
                    exit(0);
            }

        //} while((selection > 0) && (selection < 5));

    }
    void Livre::set_genre(){
        std::string genre;
        cout<<" Veuillez saisir le genre du livre s'il vous plait : "<<flush;
        cin>>genre;
        this->_genre=genre;
    }
    void Livre::set_date_de_publication(){
        cout<<" ================  Date de publication du livre  ==============="<<endl;
        std::string date_de_publication;
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
        date_de_publication = dd.str();
        //this->_date=date;
        this->_date_de_publication=date_de_publication;
    }
    /*
    void Livre::set_nb_lecteur(){
        int nb_lecteur;
        cout<<" Veuillez saisir le nombre de lecteur s'il vous plait : "<<flush;
        cin>>nb_lecteur;

//        while(int x=0){
//           try {

//                cin>>nb_lecteur;
//                throw(nb_lecteur);
//           }

//           catch (string nb_lecteur) {
//               cout<<"Vous devez saisir un entier"<<endl;
//               x=0;
//           }
//            if(nb_lecteur>=0){
//                x+=1;
//                break;
//            }
//           cout<<"Veuillez saisir le nombre de lecteur s'il vous plait : "<<flush;


//        }

        //this->_nb_lecteur=nb_lecteur;
    }
    */

    void Livre::set_ISBN(){
        cout<<" ================  Informations sur l'ISBN  ==============="<<endl;
        std::string ISBN;
        cout<<" Veuillez saisir le ISBN s'il vous plait : "<<flush;
        cin>>ISBN;
//        std::stringstream convert;
//        convert<<ISBN;
//        std::string str = convert.str();
        this->_ISBN=ISBN;
    }
/*
    std::string Livre::setIdentifiant(){
        cout<<" ================  Informations sur l'identifiant  ==============="<<endl;
        cout<<" Veuillez saisir votre identifiant s'il vous plait : "<<flush;
        cin>>_identifiant;
        return _identifiant;
    }

    void Livre::set_identifiants(string identifiant){
        _identifiant = identifiant;
        //_identifiants.push_back(_identifiant);

    }
    */


   const std::string Livre::toString(){

       stringstream ss;

        ss<<_title;
        ss<<";";
       ss<<_IdAuteur;
        ss<<";";
        ss<<_date_de_publication;
        ss<<";";
        ss<<_ISBN;
        ss<<";";
        ss<<_genre;
        ss<<";";
        ss<<_langue;
        ss<<";";
        ss<<_status;

        return ss.str();

    }

    void Livre::toStringHeader(){

        stringstream ss;
        ss<<"title;";
        ss<<"auteur;";
        ss<<"date_de_publication;";
        ss<<"ISBN;";
        ss<<"identifiant;";
        ss<<"nb_lecteur;";
        ss<<"genre";
        ss<<"langue";

        //title;auteur;date_de_publication;ISBN;;identifiant;nb_lecteur;genre;langue

      //  cout<<ss.str()<<endl;

    }


    /// Getters

    std::string Livre::get_title(std::string title){
        return title;
    }
    std::string Livre::getTitle(){
        return _title;
    }
    std::string Livre::getAuteur(){
        return _IdAuteur;
    }


    std::string Livre::get_auteur(std::string auteur){
        return auteur;
    }
    std::string Livre::get_langue(std::string langue){
        return langue;
    }
    std::string Livre::get_genre(std::string genre){
        return genre;
    }
    std::string Livre::get_date_de_publication(std::string date_de_publication){
        return date_de_publication;
    }
    int Livre::get_nb_lecteur(int nb_lecteur){
        return nb_lecteur;
    }
    unsigned long int Livre::get_ISBN(unsigned long int ISBN){
        return ISBN;
    }
    /*
    unsigned long int Livre::get_identifiants(unsigned long int identifiant[]){
        int sauvegarde=0;
        for(int i=0;i<_nb_lecteur;i++)
            sauvegarde=identifiant[i];
        return sauvegarde;
    }*/

//    std::string Livre::get_Informations(){
//        stringstream ii;
//        ii<<" Titre :";
//        ii<<_title;
//        ii<<" |";
//        ii<<" Nom auteur : ";
////        ii<< *_auteur->get_nom();
//    }

    std::string Livre::displayLivreInfo()
    {
      //6.b) Ajouter une surcharge de l'operateur << à la classe Lecteur permettant de faire l'affichage à l'écran de la liste des informations d'un lecteur.
      //  Ajouter également une surcharge de l'operateur << aux classes Auteur et Livre permettant de faire l'affichage à l'écran de la liste de toutes les informations d'un livre.
    std::stringstream  ss;
    ss<<" Titre: ";
    ss<<_title;
    ss<< "\n";
    ss<<" Genre: ";
    ss<<_genre;
     ss<<"\n";
   ss<<"  Auteur: ";
    ss<<_IdAuteur;
       ss<< "\n";
    ss<<"date_de_publication: ";
    ss<<_date_de_publication;
       ss<< "\n";
    ss<<" ISBN: ";
    ss<<_ISBN;
       ss<< "\n";
    ss<<" Langue: ";
    ss<<_langue;
       ss<< "\n";
    ss<<" Etat: ";
    ss<<_status;
       ss<< "\n";


    ss<<" liste des livres empruntes:"<< "\n";
    for(unsigned int i=0; i<lecteurs.size();i++){
        ss<<"\t";
        ss<<lecteurs[i];
                }
   return  ss.str();


    }
