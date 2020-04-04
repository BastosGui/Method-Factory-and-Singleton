#include <iostream>
#include "Model.h"
#include <cassert>
#include <cmath>

using namespace std;


FlowExpression(FlowLog, (0.3 * TARGET*(1 - TARGET / 70)));
FlowExpression(FlowExp, (0.3 * TARGET));

FlowExpression(FlowLogistico, (0.01 * TARGET*(1 - TARGET / 70)));
FlowExpression(FlowExponencial, (0.01 * SOURCE));

FlowExpression(FlowF, (0.01*SOURCE));
FlowExpression(FlowG, (0.01*SOURCE));
FlowExpression(FlowR, (0.01*SOURCE));
FlowExpression(FlowT, (0.01*SOURCE));
FlowExpression(FlowU, (0.01*SOURCE));
FlowExpression(FlowV, (0.01*SOURCE));   

FlowExpression(FlowTeste, (5*SOURCE));


void testeUnitarioStock()
{    
    //Testes unitários Stock
    Model& testeStock = Model::createModel();
    Stock& stock1 = testeStock.createStock("estoque", 20);
    assert (stock1.getName() == "estoque");
    assert (stock1.getValue() == 20);
    stock1.setValue(10);
    assert (stock1.getValue() == 10);
    Stock& stock2 = testeStock.createStock(stock1);
    assert(stock1.getName() == stock2.getName());
    assert(stock1.getValue() == stock2.getValue());
    assert (&stock1 != &stock2);
    assert (stock1 == stock2);
    assert (stock2 == stock1);

    //Operação entre stocks e constantes
    assert (10 + stock1 == 20);
    assert (stock1 + 10 == 20);
    assert (10 - stock1 == 0);
    assert (stock1 - 10 == 0);
    assert (10 * stock1 == 100);
    assert (stock1 * 10 == 100);
    assert (10 / stock1 == 1);
    assert (stock1 / 10 == 1);
    
    //Operação entre stocks
    assert (stock1 == stock2);
    assert (stock1 + stock2 == 20);
    assert (stock2 + stock1 == 20);
    assert (stock1 - stock2 == 0);
    assert (stock2 - stock1 == 0);
    assert (stock1 * stock2 == 100);
    assert (stock2 * stock1 == 100);
    assert (stock1 / stock2 == 1);
    assert (stock2 / stock1 == 1);
    
}

/*
void testeUnitarioFlow()
{
    //Testes unitarios Flow
    Stock *stockTeste1 = new StockImpl("stockTeste1", 10);
    Stock *stockTeste2 = new StockImpl("stockTeste2", 20);
    Stock *stockTeste3 = new StockImpl("stockTeste3", 30);
    FlowTeste fluxoTeste1("fluxoTeste1", stockTeste1, stockTeste2);
    FlowTeste fluxoTeste2(fluxoTeste1);
    assert(fluxoTeste1 == fluxoTeste2);
    FlowTeste fluxoTeste3 = fluxoTeste2;
    assert(fluxoTeste2 == fluxoTeste3);
    assert(fluxoTeste1.getName() == "fluxoTeste1");
    assert(fluxoTeste1.getSource().getName() == stockTeste1->getName());
    assert(fluxoTeste1.getTarget().getName() == stockTeste2->getName());
    fluxoTeste1.setName("fluxoTesteNovo");
    assert(fluxoTeste1.getName() == "fluxoTesteNovo");
    fluxoTeste1.setSource(*stockTeste3);
    assert(fluxoTeste1.getSource().getName() == stockTeste3->getName());
    fluxoTeste1.setTarget(*stockTeste1);
    assert(fluxoTeste1.getTarget().getName() == stockTeste1->getName());
    assert(fluxoTeste1.execute() == 5*fluxoTeste1.getSource().getValue());

}
*/
/*
void testeUnitarioModel()
{
    //Testes unitarios Model
    Model *modelo3 = new ModelImpl("modelo3", 10);
    Model *modelo4 = new ModelImpl(*modelo3);
    Model *modelo5 = new ModelImpl("modelo5");
    assert(modelo3->getName() == "modelo3");
    assert(modelo3->getTime() == 10);
    assert(*modelo3 == *modelo4);
    assert(modelo3->getName() == modelo4->getName());
    assert(modelo3->getTime() == modelo4->getTime());
    assert(modelo5->getName() == "modelo5");
    assert(modelo5->getTime() == 1);

    modelo3->setName("novo_modelo3");
    assert(modelo3->getName() == "novo_modelo3");
    modelo3->setTime(1);
    assert(modelo3->getTime() == 1);

    Stock *stock3 = new StockImpl("stock3", 10);
    FlowExp fluxo3("fluxo3", NULL, stock3);
    assert(modelo3->add(*stock3));
    assert(modelo3->add(fluxo3));
    StockIterator itSB = modelo3->beginStocks();
    FlowIterator itFB = modelo3->beginFlows();
    assert(itSB->first == stock3->getName());
    assert(itFB->first == fluxo3.getName());
    
    double valor_inicial = stock3->getValue();
    double valor_eq = fluxo3.expression();
    modelo3->execute();
    assert(stock3->getValue() == valor_inicial+valor_eq);

    modelo5 = modelo3;
    assert(modelo3 == modelo5);
    
    Stock *stock4 = new StockImpl("stock4", 10);
    FlowLog fluxo4("fluxo4", NULL, stock4);
    modelo3->add(*stock4);
    modelo3->add(fluxo4);
    itSB = modelo3->beginStocks();
    StockIterator itSE = modelo3->endStocks();
    itFB = modelo3->beginFlows();
    FlowIterator itFE = modelo3->endFlows();
    
    assert(itSB->first == stock3->getName());
    assert(itFB->first == fluxo3.getName());
    itSB++;
    itFB++;
    assert(itSB->first == stock4->getName());
    assert(itFB->first == fluxo4.getName());
    itSB++;
    itFB++;
    assert(itSB == itSE);
    assert(itFB == itFE);

    assert(modelo3->remove(*stock3));
    assert(modelo3->remove(fluxo3));
    itSB = modelo3->beginStocks();
    itFB = modelo3->beginFlows();
    itSB++;
    itFB++;
    itSE = modelo3->endStocks();
    itFE = modelo3->endFlows();
    assert(itSB == itSE);
    assert(itFB == itFE);

}
*/
void testeFuncionalExpo()
{
    Model& funcionalExpo = Model::createModel();
    funcionalExpo.setName("modeloExp");
    funcionalExpo.setTime(100);
    Stock& pop1 = funcionalExpo.createStock("pop1", 100);
    Stock& pop2 = funcionalExpo.createStock("pop2", 0);
    Flow& exponencial = funcionalExpo.createFLow<FlowExponencial>("exponencial", &pop1, &pop2);
    funcionalExpo.execute();
    assert(fabs(pop1.getValue()-36.6032) < 0.0001);
    assert(fabs(pop2.getValue()-63.3968) < 0.0001);
}

void testeFuncionalLog()
{
    Model& funcionalLog = Model::createModel();
    funcionalLog.setName("modeloLog");
    funcionalLog.setTime(100);
    Stock& p1 = funcionalLog.createStock("p1", 100);
    Stock& p2 = funcionalLog.createStock("p2", 10);
    Flow& logistico = funcionalLog.createFLow<FlowLogistico>("logistico", &p1, &p2);
    funcionalLog.execute();
    assert(fabs(p1.getValue()-88.2167) < 0.0001);
    assert(fabs(p2.getValue()-21.7834) < 0.0001);
}


void testeFuncionalComplex()
{
    Model& funcionalComplex = Model::createModel();
    funcionalComplex.setName("modeloComplexo");
    funcionalComplex.setTime(100);
    Stock& q1 = funcionalComplex.createStock("q1", 100);
    Stock& q2 = funcionalComplex.createStock("q2", 0);
    Stock& q3 = funcionalComplex.createStock("q3", 100);
    Stock& q4 = funcionalComplex.createStock("q4", 0);
    Stock& q5 = funcionalComplex.createStock("q5", 0);
    Flow& f = funcionalComplex.createFLow<FlowF>("f", &q1, &q2);
    Flow& g = funcionalComplex.createFLow<FlowG>("g", &q1, &q3);
    Flow& r = funcionalComplex.createFLow<FlowR>("r", &q2, &q5);
    Flow& t = funcionalComplex.createFLow<FlowT>("t", &q2, &q3);
    Flow& u = funcionalComplex.createFLow<FlowU>("u", &q3, &q4);
    Flow& v = funcionalComplex.createFLow<FlowV>("v", &q4, &q1);
    funcionalComplex.execute();
    assert(fabs(q1.getValue()-31.8513) < 0.0001);
    assert(fabs(q2.getValue()-18.4003) < 0.0001);
    assert(fabs(q3.getValue()-77.1143) < 0.0001);
    assert(fabs(q4.getValue()-56.1728) < 0.0001);
    assert(fabs(q5.getValue()-16.4612) < 0.0001);
}


void testSingleton(){
    Model& m1 = Model::createModel();
    Model& m2 = Model::createModel();
    assert (&m1 == &m2);
    m2.setName("qualquer");
    assert(m1.getName() == "qualquer");
}

int main() {
    testeFuncionalExpo();
    testeFuncionalLog();
    testeFuncionalComplex();
    testSingleton();
    //testeUnitarioStock();
    //testeUnitarioFlow();
    //testeUnitarioModel();
    
    return 0;
}