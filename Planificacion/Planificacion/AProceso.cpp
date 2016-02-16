#include "stdafx.h"
#include "AProceso.h"


AProceso::AProceso()
{
}


AProceso::~AProceso()
{
}


int AProceso::getId()
{
	return this->id;
}

void AProceso::setId(int id)
{
	this->id = id;
}

int AProceso::getLlegada()
{
	return this->llegada;
}

void AProceso::setLlegada(int llegada)
{
	this->llegada = llegada;
}

int AProceso::getInicio()
{
	return this->inicio;
}

void AProceso::setInicio(int inicio)
{
	this->inicio = inicio;
}

int AProceso::getRafaga()
{
	return this->rafaga;
}

void AProceso::setRafaga(int rafaga)
{
	this->rafaga = rafaga;
}

int AProceso::getFin()
{
	return this->fin;
}

void AProceso::setFin(int fin)
{
	this->fin = fin;
}