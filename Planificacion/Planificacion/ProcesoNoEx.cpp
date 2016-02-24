#include "stdafx.h"
#include "ProcesoNoEx.h"


ProcesoNoEx::ProcesoNoEx()
{
}


ProcesoNoEx::~ProcesoNoEx()
{
}


void ProcesoNoEx::tiempoEspera()
{

}

void ProcesoNoEx::tiempoRetorno()
{

}

void ProcesoNoEx::agregarInicio(int inicio)
{
	inicios.push_back(inicio);
}

void ProcesoNoEx::agregarAlto(int alto)
{
	altos.push_back(alto);
}

int ProcesoNoEx::getRestante()
{
	return this->restante;
}

void ProcesoNoEx::setRestante(int restante)
{
	this->restante = restante;
}