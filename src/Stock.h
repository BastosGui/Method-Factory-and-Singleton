#ifndef STOCK_H
#define STOCK_H

#include <string>

using namespace std;

class Stock{

    friend double operator+(const Stock&, const Stock&);
    friend double operator-(const Stock&, const Stock&);
    friend double operator*(const Stock&, const Stock&);
    friend double operator/(const Stock&, const Stock&);
    friend double operator+(const double&, const Stock&);
    friend double operator-(const double&, const Stock&);
    friend double operator*(const double&, const Stock&);
    friend double operator/(const double&, const Stock&);
    friend double operator+(const Stock&, const double&);
    friend double operator-(const Stock&, const double&);
    friend double operator*(const Stock&, const double&);
    friend double operator/(const Stock&, const double&);
    
    public:

        //Getters
        virtual string getName() const = 0;
        virtual double getValue() const = 0;
        
        //Setters
        virtual void setName(const string&) = 0;
        virtual void setValue(const double&) = 0;

        virtual Stock& operator=(const Stock&) = 0;
        virtual bool operator==(Stock&) const = 0;
};

#endif