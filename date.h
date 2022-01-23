#include <iostream>

#ifndef DATE_H
#define DATE_H
/*!
 * \brief La Date class ( question: 1.a) nous permet de reprendre la classe Date vue en cours et l'adapter pour qu'elle puisse prendre en compte les années.
 * dans cette classe nous avons les variables privees (month, day et year),
 * un construteur a plusieurs entrees Date(int month=1, int day=1, int year=1)
 * des methodes getters et setters pour l'encapsulation de la classe
 * des fonctions membres (updateMonth,updateDay,updateYear,next,back et toString);
 */
class Date {
public:
   Date(int month=1, int day=1, int year=1);
   int month() const;
   int day() const;
   int year () const;

   void updateMonth();
   void updateDay();
   void updateYear();
   void next();
   void back();
 //  void toString();
   std::string toString();
private:
   int _month;
   int _day;
   int _year;
};

bool isDate(int month, int day, int year);
int getDaysInMonth(int month);
int dayOfYear(Date d);
std::string toString(Date d);


#endif // DATE_H
