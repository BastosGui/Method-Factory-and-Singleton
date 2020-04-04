#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"

using namespace std;

#define FlowExpression(NAME, EXPRESSION) class NAME: public FlowImpl { public:NAME(const string& name, Stock* source, Stock* target): FlowImpl(name, source, target){} double expression(){ return EXPRESSION; } };

#define SOURCE getSource()
#define TARGET getTarget()

class FlowImpl:public Flow
{
	public:
		//Construtores
		FlowImpl();
		FlowImpl(const FlowImpl&);
		FlowImpl(const string&, Stock*, Stock*);

		//Destrutor
		virtual ~FlowImpl();

		//Getters
		string getName() const;
		Stock& getSource() const;
		Stock& getTarget() const;

		//Setters
		void setName(const string&);
		void setSource(Stock&);
		void setTarget(Stock&);

		//Sobrecarga de Operadores
		Flow& operator=(const Flow&);
    	bool operator==(Flow&) const;

		//Funções
		virtual double expression() = 0;
		double execute();

	private:
		string name;
		Stock *source, *target;

};

#endif	/* FLOWIMPL_H */