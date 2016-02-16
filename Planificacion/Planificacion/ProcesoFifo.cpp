#include "stdafx.h"
#include "Proceso.h"


Proceso::Proceso()
{
}


Proceso::~Proceso()
{
}

int Proceso::getId()
{
	return this->id;
}

void Proceso::setId(int id)
{
	this->id = id;
}

long Proceso::getLlegada()
{
	return this->llegada;
}

void Proceso::setLlegada(long llegada)
{
	this->llegada = llegada;
}

long Proceso::getInicio()
{
	return this->inicio;
}

void Proceso::setInicio(long inicio)
{
	this->inicio = inicio;
}

long Proceso::getRafaga()
{
	return this->rafaga;
}

void Proceso::setRafaga(long rafaga)
{
	this->rafaga = rafaga;
}

long Proceso::getFin()
{
	return this->fin;
}

void Proceso::setFin(long fin)
{
	this->fin = fin;
}