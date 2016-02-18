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

int Proceso::getLlegada()
{
	return this->llegada;
}

void Proceso::setLlegada(int llegada)
{
	this->llegada = llegada;
}

int Proceso::getRafaga()
{
	return this->rafaga;
}

void Proceso::setRafaga(int rafaga)
{
	this->rafaga = rafaga;
}
