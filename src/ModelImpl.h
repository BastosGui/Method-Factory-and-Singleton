#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"
#include "StockImpl.h"
#include "FlowImpl.h"

using namespace std;

class ModelImpl:public Model
{
public:
    
    //Destrutor
    virtual ~ModelImpl();
    
    //Setters
    void setName(const string&);
    bool setTime(int);
    
    //Getters
    string getName() const;
    int getTime() const;
    
    //Funções
    bool add(Stock&);
    bool add(Flow&);
    bool remove(Stock&);
    bool remove(Flow&);
    void execute();
    void print();

    static Model& createModel();
    Stock& createStock(string, double);
    Stock& createStock(Stock&);
    
    //Iteradores
    StockIterator beginStocks() const;
    StockIterator endStocks() const;
    FlowIterator beginFlows() const;
    FlowIterator endFlows() const;
    
    //Sobrecarga de operadores
    Model& operator=(const Model&);
    bool operator==(Model&) const;
    
private:
    string name;
    int time;
    map< string, Stock* > Stocks;
    map< string, Flow* > flows;
    static ModelImpl* instance;

    //Construtores
    ModelImpl();
    ModelImpl(const Model&);
    ModelImpl(const string&);
    ModelImpl(const string&, const int);
};

#endif  /* MODELIMPL_H */