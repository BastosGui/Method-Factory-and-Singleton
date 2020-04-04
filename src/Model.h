#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>
#include <iomanip>

#include "Flow.h"
#include "Stock.h"
#include "FlowImpl.h"

typedef map<string, Stock*>::const_iterator StockIterator;
typedef map<string, Flow*>::const_iterator FlowIterator;

class Model
{
public:
    //Setters
    virtual void setName(const string&) = 0;
    virtual bool setTime(int) = 0;
    
    //Getters
    virtual string getName() const = 0;
    virtual int getTime() const = 0;
    
    //Funções
    virtual bool add(Stock&) = 0;
    virtual bool add(Flow&) = 0;
    virtual bool remove(Stock&) = 0;
    virtual bool remove(Flow&) = 0;
    virtual void execute() = 0;
    virtual void print() = 0;

    //Factory
    static Model& createModel();
    virtual Stock& createStock(string, double) = 0;
    virtual Stock& createStock(Stock&) = 0;
    
    template < typename T_FLOW_IMPL >
    Flow& createFLow(string id, Stock *o = NULL, Stock *d = NULL)
    {
        Flow *f = new T_FLOW_IMPL(id, o, d);
        add(*f);
        return *f;
    }
    
    //Iteradores
    virtual StockIterator beginStocks() const = 0;
    virtual StockIterator endStocks() const = 0;
    virtual FlowIterator beginFlows() const = 0;
    virtual FlowIterator endFlows() const = 0;
    
    //Sobrecarga de operadores
    virtual Model& operator=(const Model&) = 0;
    virtual bool operator==(Model&) const = 0;
};

#endif