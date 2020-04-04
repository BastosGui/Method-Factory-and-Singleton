#include "FlowImpl.h"

FlowImpl::FlowImpl(){}

FlowImpl::FlowImpl(const FlowImpl &fluxo)
{
	if(&fluxo == this)
		return;
	setName(fluxo.getName());
	setSource(fluxo.getSource());
	setTarget(fluxo.getTarget());
}

FlowImpl::FlowImpl(const string& name, Stock *source, Stock *target)
{
	setName(name);
	setSource(*source);
	setTarget(*target);
}

FlowImpl::~FlowImpl(){}

string FlowImpl::getName() const
{
	return name;
}

void FlowImpl::setName(const string &name)
{
	this->name = name;
}

Stock& FlowImpl::getSource() const
{
	return *source;
}

void FlowImpl::setSource(Stock &source)
{
	this->source = &source;
}

Stock& FlowImpl::getTarget() const
{
	return *target;
}

void FlowImpl::setTarget(Stock &target)
{
	this->target = &target;
}

double FlowImpl::execute()
{
	return expression();
}

Flow& FlowImpl::operator=(const Flow &fluxo)
{
	if(&fluxo == this)
		return (*this);
	setName(fluxo.getName());
	setSource(fluxo.getSource());
	setTarget(fluxo.getTarget());
	return (*this);
}

bool FlowImpl::operator==(Flow& fluxo) const
{
	if((getName() == fluxo.getName()) && (getSource() == fluxo.getSource()) && (getTarget() == fluxo.getTarget()))
		return true;
	return false;
}