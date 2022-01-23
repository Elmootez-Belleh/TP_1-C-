#include <iostream>
#include <string>
#include <list>
#include "date.h"
#include "Livre.h"
#include "lecteur.h"
#include "Auteur.h"
#include "emprunt.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstdlib>

#include "bibliotheque.h"

using namespace std;

//#define OUT 0
//#define IN 1


//static vector<Lecteur> lecteurs;
//static vector<Livre> livres;
//static vector<Emprunt> emprunts;
//static vector<Auteur> auteurs;

Bibliotheque *bib;
/*
  unsigned  countWordInLine(char *str)  {
     // int a = *str.size();
      //cout <<"nb char:";
       //cout << a << endl;
       int state = OUT;
           unsigned wc = 0; // word count

           // Scan all characters one by one
           while (*str)
           {
               // If next character is a separator, set the
               // state as OUT
               if (*str == ';' || *str == '\n' || *str == '\t')
                   state = OUT;

               // If next character is not a word separator and
               // state is OUT, then set the state as IN and
               // increment word count
               else if (state == OUT)
               {
                   state = IN;
                   ++wc;
               }

               // Move to next character
               ++str;
           }

           return wc;

  }

  */
 int  readFromFiles(std::string _fichier)
{

    std::stringstream ss;
    ss <<"C:/temp/mootez/TP_01/" << _fichier <<".txt";
    std::string s = ss.str();
     cout << s << endl;
      ifstream  fichier(s, ios::in);  // on ouvre le fichier en lecture

        if(fichier)  // si l'ouverture a réussi
        {

            string line;


            while (getline(fichier, line))
            {
               vector<string> fields;
               istringstream ss(line);
               string word;

              while (getline(ss, word,';'))
                    fields.push_back(word);

                if(_fichier=="livres"){
               Livre *l1=new Livre(fields[0],fields[1],fields[2],fields[3],fields[4],fields[5],fields[6]);
               bib->newLivre(*l1);
                     }
                else if(_fichier=="lecteurs"){

                    Lecteur *l1=new Lecteur(fields[0],fields[1],fields[2]);
                     bib->newLecteur(l1);

                }
                else if(_fichier=="emprunts"){

                    // Emprunt *e1=new Emprunt(fields[0],fields[1],fields[2]);
                   // bib->newEmprunt(e1);
                  //  bib->emprunterLivre(fields[0],fields[1]);
                      bib->loadEmprunteLivresFromFile(fields[0],fields[1],fields[2]);

                }
                else if(_fichier=="auteurs"){

                     Auteur *a1=new Auteur(fields[0],fields[1],fields[2],fields[3]);
                    bib->newAuteur(a1);


                }

                 }
            fichier.close();
           }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

        return 0;
}

 void writeToFiles( std::string filename)
{

    std::stringstream ss;
    ss <<"C:/temp/mootez/TP_01/" << filename <<".txt";
    std::string s = ss.str();
    cout << s << endl;


        ofstream fichier(s, ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

        if(fichier)  // si l'ouverture a réussi
        {
            // instructions
         if(filename=="olivres"){

            for(unsigned int i = 0; i < bib->getLivres().size(); i++) // D’ailleurs, i++ ou ++i ?
                                   {
                                     std::string    line=bib->getLivreByIndex(i).toString();
                                    //    cout << line << endl;
                                     fichier << line  <<endl;
                                     }

                              }
            else if(filename=="olecteurs")
                    {
                      for(unsigned int i = 0; i < bib->getLecteurs().size(); i++) // D’ailleurs, i++ ou ++i ?
                              {
                              string line=bib->getLecteurByIndex(i).toString();
                              fichier << line  <<endl;
                              }

                        }

         else if(filename=="oemprunts")
                 {

                   for(unsigned int i = 0; i <bib->getEmprunts().size(); i++) // D’ailleurs, i++ ou ++i ?
                           {
                           string line=bib->getEmpruntByIndex(i).toString();
                           fichier << line  <<endl;
                           }

                     }

         else if(filename=="oauteurs")
                 {

                   for(unsigned int i = 0; i < bib->getAuteurs().size(); i++) // D’ailleurs, i++ ou ++i ?
                           {
                           string line=bib->getAuteurByIndex(i).toString();
                           fichier << line  <<endl;
                           }

                     }

                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;

       // return 0;
}

void menu(){

    int selection=0;
    std::string _date;


    do{

        cout<<"\n Menu (1,2,3 or 4, 0 pour sortir)"<<"\n";

        cout<<"\n 0: pour sortir";

        cout<<"\n 1: Tester la date";

        cout<<"\n 2: Ajouter un Livre";

        cout<<"\n 3: Ajouter un Lecteur";

        cout<<"\n 4: Ajouter un Emprunt";

        cout<<"\n 5: Afficher les informations sur un Lecteur";

        cout<<"\n 6: Afficher les informations sur un Livre";

        cout<<"\n\n Enter selection: ";

        cin>>selection;


    switch(selection)
            {
        case 0:
            {
                  writeToFiles("olivres");
                  writeToFiles("olecteurs");
                  writeToFiles("oemprunts");
                  writeToFiles("oauteurs");

                   exit(0);    // terminates the complete program execution
            }
        case 1:
            {
        //1.b) Valider son bon fonctionnement  de la date avec un programme de test.
                Date *d1=new Date;
                d1->toString();
            }
            break;

        case 2:
            {
   //     2.b) Valider son bon fonctionnement de creation d'un livre et la classe Auteur avec un programme de test.

                Livre *l1 = new Livre();
                l1->set_title();
                l1->set_auteur();   // validation de la classe Auteur

                l1->set_date_de_publication();
                l1->set_ISBN();
                l1->set_genre();
                l1->set_langue();
                bib->newLivre(*l1);

              }
            break;

        case 3:
            {
           //   3.b) Valider son bon fonctionnement avec un programme de test.
                Lecteur *l1 = new Lecteur();
                l1->setNom();
                l1->setPrenom();
                l1->setID();

                l1->setListeISBNLivresEmpruntes();
                 bib->newLecteur(l1);
              //  lecteurs.push_back(*l1);

             }
            break;

        case 4:
            {
        //4.b) Valider son bon fonctionnement avec un programme de test.

        std::string idLecteur,isbn;
         cout<<"Entrez l'identifiant de l'auteur"<<endl;
         cin>>idLecteur;
         cout<<"Entrez l'ISBN du livre"<<endl;
         cin>>isbn;
         bib->emprunterLivre(idLecteur,isbn);

             }
            break;

    case 5:
        {
        std::string lecteur;
        cout << "Entrez l'identifiant du lecteur";
        cin>>lecteur;

       cout<<bib->displayLecteurInfo(lecteur)<<endl;

// 6.c) Utiliser ces fonctions pour vérifier que les informations saisies dans la bibliothèque sont bien correctes.

         }
        break;
    case 6:
        {
// 6.c) Utiliser ces fonctions pour vérifier que les informations saisies dans la bibliothèque sont bien correctes.

        std::string livre;
        cout << "Entrez l'identifiant du lecteur";
        cin>>livre;

       cout<<bib->displayLivreInfo(livre)<<endl;
         }

        break;
    case 7:
        {
 //7.a) Créer la méthode / fonction helper permettant de chercher tous les livres d'un auteur.
        std::string auteur;
        cout << "Entrez l'identifiant de l'auteur";
        cin>>auteur;

       cout<<bib->afficherTousLivresAuteur(auteur)<<endl;
         }

        break;

    case 8:
        {
 //7.b) Créer la méthode / fonction helper permettant de chercher tous les livres empruntés et de calculer le pourcentage de livres empruntés       std::string auteur;


       cout<< bib->afficherTousLivresEmrunte()<<endl;
        cout<< bib->pourcentageTousLivresEmprunte()<<"%"<<endl;
         }

        break;

    case 9:
        {
 //7.c) Créer la méthode / fonction helper permettant de chercher tous les livres empruntés par un lecteur.
        std::string lecteur;
        cout << "Entrez l'identifiant du Lecteur";
        cin>>lecteur;
       cout<< bib->afficherTousLivresEmrunteparUnLecteur(lecteur)<<endl;
          }

        break;

    case 10:
        {

        //7.d) Créer la méthode /
        //fonction helper permettant d'établir le classement des lecteurs en fonction du nombre de livres empruntés
     vector<   unsigned int > _nblecteurs;
     for(int i=0; i<bib->getAuteurs().size(); i++)
           _nblecteurs.push_back(bib->afficherNbLivresEmrunteparLecteur(bib->getAuteurs()[i].getIdAuteur()));

       }
 break;
     }

}while((selection > 0) && (selection < 11));



}


void commit(){
    writeToFiles("olivres");
    writeToFiles("olecteurs");
    writeToFiles("oemprunts");
        writeToFiles("oauteurs");
}

void loadData(){
    readFromFiles("livres");
    readFromFiles("lecteurs");
    readFromFiles("emprunts");
    readFromFiles("auteurs");
}
int  main(){
    bib=new Bibliotheque();
   loadData();
    menu();

    return 0;

}
