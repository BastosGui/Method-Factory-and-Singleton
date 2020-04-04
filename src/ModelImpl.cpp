#include "ModelImpl.h"

ModelImpl::ModelImpl() {
    setTime(1);
}

ModelImpl::ModelImpl(const Model& modelo) {
    if (&modelo == this)
        return;

    setName(modelo.getName());
    setTime(modelo.getTime());

    for (StockIterator it = beginStocks(); it != endStocks(); ++it){
        delete[] it->second;
    }

    for (FlowIterator it = beginFlows(); it != endFlows(); ++it){
        delete[] it->second;
    }

    Stocks.clear();
    flows.clear();

    for (StockIterator it = modelo.beginStocks(); it != modelo.endStocks(); ++it)
        add(*(it->second));
    for (FlowIterator it = modelo.beginFlows(); it != modelo.endFlows(); ++it)
        add(*(it->second));
}

ModelImpl::ModelImpl(const string& name) {
    setName(name);
    setTime(1);
}

ModelImpl::ModelImpl(const string& name, const int time) {
    setName(name);
    setTime(time);
}

ModelImpl::~ModelImpl() {
}

void ModelImpl::setName(const string &name) {
    this->name = name;
}

bool ModelImpl::setTime(int time) {
    if (time > 0) {
        this->time = time;
        return true;
    }
    return false;
}

string ModelImpl::getName() const {
    return name;
}

int ModelImpl::getTime() const {
    return time;
}

bool ModelImpl::add(Stock& stock) {
    if (Stocks.find(stock.getName()) == Stocks.end()) {
        Stocks.insert(pair <string, Stock*> (stock.getName(), &stock));
        return true;
    }
    return false;
}

bool ModelImpl::add(Flow& fluxo) {
    if (flows.find(fluxo.getName()) == flows.end()) {
        flows.insert(pair <string, Flow*> (fluxo.getName(), &fluxo));
        return true;
    }
    return false;
}

bool ModelImpl::remove(Stock& stock) {
    if (Stocks.find(stock.getName()) != Stocks.end()) {
        Stocks.erase(stock.getName());
        return true;
    }
    return false;
}

bool ModelImpl::remove(Flow& fluxo) {
    if (flows.find(fluxo.getName()) != flows.end()) {
        flows.erase(fluxo.getName());
        return true;
    }
    return false;
}

void ModelImpl::execute() {
    double aux;
    map< string, double > v;
    for (FlowIterator it = flows.begin(); it != flows.end(); ++it) {
        v.insert(pair <string, double> (it->first, 0.0));
    }
    //cout << "\nmodelo: " << getName() << ":" << endl;
    //cout << "Valores iniciais: " << endl;

    //for (StockIterator it = Stocks.begin(); it != Stocks.end(); ++it)
       //cout << "\t" << it->first << " - valor: " << setw(10) << it->second->getValue() << endl;
    for (int i = 1; i <= getTime(); ++i) {
        for (FlowIterator it = flows.begin(); it != flows.end(); ++it) {
            v.at(it->first) = it->second->execute();
        }

        for (FlowIterator it = flows.begin(); it != flows.end(); ++it) {
            aux = v.find(it->first)->second;
            Stock *source, *target;

            source = &(it->second->getSource());
            target = &(it->second->getTarget());

            if (source != NULL)
                source->setValue(source->getValue() - aux);
            if (target != NULL)
                target->setValue(target->getValue() + aux);
        }
        //cout << "Iteracao: " << i << endl;
        //for (StockIterator it = Stocks.begin(); it != Stocks.end(); ++it)
        //cout << "\t" << it->first << " - valor: " << setw(10) << it->second->getValue() << endl;

    }
}

void ModelImpl::print(){
    cout << "modelo: " << getName() << endl;
    cout << "Valor: " << endl;
   for (StockIterator it = Stocks.begin(); it != Stocks.end(); ++it)
        cout << "\t" << it->first << " - valor: " << setw(12) << it->second->getValue() << endl;
}

StockIterator ModelImpl::beginStocks() const {
    return Stocks.begin();
}

StockIterator ModelImpl::endStocks() const {
    return Stocks.end();
}

FlowIterator ModelImpl::beginFlows() const {
    return flows.begin();
}

FlowIterator ModelImpl::endFlows() const {
    return flows.end();
}

Model& ModelImpl::operator=(const Model& modelo) {
    if (&modelo == this)
        return (*this);

    setName(modelo.getName());
    setTime(modelo.getTime());

    for (StockIterator it = beginStocks(); it != endStocks(); ++it){
        delete[] it->second;
    }

    for (FlowIterator it = beginFlows(); it != endFlows(); ++it){
        delete[] it->second;
    }

    Stocks.clear();
    flows.clear();

    for (StockIterator it = modelo.beginStocks(); it != modelo.endStocks(); ++it)
        add(*(it->second));
    for (FlowIterator it = modelo.beginFlows(); it != modelo.endFlows(); ++it)
        add(*(it->second));
    return (*this);
}

bool ModelImpl::operator==(Model& modelo) const {
    if ((this->getName() == modelo.getName()) && (this->getTime() == modelo.getTime())){
        StockIterator it, it2;
        it2 = modelo.beginStocks();
        for(it = beginStocks(); it != endStocks(); ++it){
            if(it->first != it2->first)
                return false;
            it2++;
        }
        return true;
    } else
        return false;
}

Stock& ModelImpl::createStock(string name, double val){
    Stock *sto = new StockImpl(name, val);
    add(*sto);
    return *sto;
}

Stock& ModelImpl::createStock(Stock& stock){
    Stock *sto = new StockImpl(stock.getName(), stock.getValue());
    add(*sto);
    return *sto;
}

Model& ModelImpl::createModel(){
    static ModelImpl* instance = new ModelImpl();
    return *instance;
}

Model& Model::createModel(){
    return ModelImpl::createModel();
}
