#include "date.h"
#include <assert.h>
#include <sstream>

using namespace std;


    Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
        bool status = isDate(month, day,year);
        assert(status && "Date is not valid");
    }

    int Date::month() const {
        return _month;
    }

    int Date::day() const {
        return _day;
    }
    int Date::year() const {
        return _year;
    }

    void Date::updateMonth() {
        std::cout<<" Veuillez saisir le mois s'il vous plait :"<<std::flush;
        int month;
        std::cin>>month;
        bool status = isDate(month, _day,_year);
        assert(status==true && "New month is not valid");
        _month = month;
    }

    void Date::updateDay() {
        std::cout<<" Veuillez saisir le jour s'il vous plait :"<<std::flush;
        int day;
        std::cin>>day;
        bool status = isDate(_month, day,_year);
        assert(status==true && "New day is not valid");
        _day = day;
    }

    void Date::updateYear(){
        std::cout<<" Veuillez saisir l'annee s'il vous plait :"<<std::flush;
        int year;
        std::cin>>year;
        bool status = isDate(_month, _day,year);
        assert(status==true && "New day is not valid");
        _year = year;
    }

    void Date::next() {
        if ((_month==12) && (_day==31)) {
            _day=1;
            _month=1;
            _year+=1;
        }
        else if (_day==getDaysInMonth(_month)) {
            _day=1;
            _month++;
        }
        else {
            _day++;
        }
    }

    void Date::back() {
        if ((_month==1) && (_day==1)) {
            _day=31;
            _month=12;
            _year-=1;
        }
        else if (_day==1) {
            _month--;
            _day=getDaysInMonth(_month);
        }
        else {
            _day--;
        }
    }


    /**
     *
     * Helper functions
     *
    */

    bool isDate(int month, int day, int year) {
        if ((day < 1) || (day>31)) return false;
        if ((month <1) || (month>12)) return false;
        if ((month == 2) && (day > 28)) return false;
        if (((month == 4) || (month == 6) ||
            (month == 9) || (month == 11)) && (day > 30)) return false;
        return true;
    }

    int getDaysInMonth(int month)  {
        assert(((month >=1) && (month<=12)) && "Month is not valid");
        if (month == 2) return 28;
        if ((month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12)) return 31;
        return 30;
    }

    int dayOfYear(Date d) {
        auto day=0;
        for (auto i=1;i<d.month();i++) {
            day+=getDaysInMonth(i);
        }
        day+= d.day();

        return day;
    }
/*
    void Date::toString(){

        stringstream ss;
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
        if(day<10)
            ss<<" 0"<<day;
        else
            ss<<" "<<day;
        ss<<"/";
        if(month<10)
            ss<<"0"<<day;
        else
            ss<<month;
        ss<<"/";
        ss<<year;
        cout<<ss.str()<<endl;



    }
*/
    std::string Date::toString(){
         stringstream ss;
       ss<<_day;
       ss<<"/";
       ss<<_month;
       ss<<"/";
       ss<<_year;

       return ss.str();



}


    std::string toString(Date d) {
        return std::to_string(d.day()) + "/" + std::to_string(d.month()) + "/" + std::to_string(d.year());
    }
