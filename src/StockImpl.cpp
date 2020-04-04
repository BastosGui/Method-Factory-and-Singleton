#include "StockImpl.h"

StockImpl::StockImpl()
{
	setValue(0);
}

StockImpl::StockImpl(const StockImpl &stock)
{
	setName(stock.getName());
	setValue(stock.getValue());
}

StockImpl::StockImpl(const string &name, const double &value)
{
	setValue(value);
	setName(name);
}

StockImpl::~StockImpl(){}

string StockImpl::getName() const{
	return this->name;
}

void StockImpl::setName(const string &name){
	this->name = name;
}

double StockImpl::getValue() const{
	return this->value;
}


void StockImpl::setValue(const double &value){
	this->value = value;
}

Stock& StockImpl::operator=(const Stock &stock)
{
	if(&stock == this)
            return (*this);
	setName(stock.getName());
	setValue(stock.getValue());
	return (*this);
}

bool StockImpl::operator==(Stock& stock) const
{
	if((getName() == stock.getName()) && getValue() == stock.getValue())
		return true;
	return false;
}

double operator+(const Stock &sistema1, const Stock &sistema2){
	return sistema1.getValue()+sistema2.getValue();
}

double operator-(const Stock &sistema1, const Stock &sistema2){
	return sistema1.getValue()-sistema2.getValue();
}

double operator*(const Stock &sistema1, const Stock &sistema2){
	return sistema1.getValue()*sistema2.getValue();
}

double operator/(const Stock &sistema1, const Stock &sistema2){
	return sistema1.getValue()/sistema2.getValue();
}

double operator+(const double &value, const Stock &stock){
	return value+stock.getValue();
}

double operator-(const double &value, const Stock &stock){
	return value-stock.getValue();
}

double operator*(const double &value, const Stock &stock){
	return value*stock.getValue();
}

double operator/(const double &value, const Stock &stock){
	return value/stock.getValue();
}

double operator+(const Stock &stock, const double &value){
	return stock.getValue()+value;
}

double operator-(const Stock &stock, const double &value){
	return stock.getValue()-value;
}

double operator*(const Stock &stock, const double &value){
	return stock.getValue()*value;
}

double operator/(const Stock &stock, const double &value){
	return stock.getValue()/value;
}
