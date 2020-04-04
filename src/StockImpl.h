#ifndef STOCKIMPL_H
#define	STOCKIMPL_H

#include "Stock.h"

using namespace std;

class StockImpl:public Stock
{
    public:
        StockImpl(const string&, const double&);

        //Destrtor
        virtual ~StockImpl();

        //Getters
        string getName() const;
        double getValue() const;
        
        //Setters
        void setName(const string&);
        void setValue(const double&);

        //Sobrecarga de Operadores
        Stock& operator=(const Stock&);
        bool operator==(Stock&) const;

    private:
        string name;
        double value;

        //Construtores
        StockImpl();
        StockImpl(const StockImpl&);
};

#endif	/* STOCKIMPL */