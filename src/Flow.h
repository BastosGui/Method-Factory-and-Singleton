#ifndef FLOW_H
#define FLOW_H

#include <iostream>

#include "Stock.h"

using namespace std;

class Flow
{   
public:
    //Getters
    virtual string getName() const = 0;
	virtual Stock& getSource() const = 0;
	virtual Stock& getTarget() const = 0;

	//Setters
	virtual void setName(const string&) = 0;
	virtual void setSource(Stock&) = 0;
	virtual void setTarget(Stock&) = 0;

	//Sobrecarga de Operadores
	virtual Flow& operator=(const Flow&) = 0;
   	virtual bool operator==(Flow&) const = 0;

	//Funções
	virtual double expression() = 0;
	virtual double execute() = 0;
};

#endif