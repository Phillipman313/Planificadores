#include "stdafx.h"
#include "ProcesoEx.h"


ProcesoEx::ProcesoEx()
{
}


ProcesoEx::~ProcesoEx()
{
}

void ProcesoEx::tiempoEspera()
{
}

void ProcesoEx::tiempoRetorno()
{
}

void ProcesoEx::reducir(int segundos)
{
	this->restante = this->restante - segundos;
}

void ProcesoEx::agregarInicio(int inicio)
{
	inicios.push_back(inicio);
}

void ProcesoEx::agregarAlto(int alto)
{
	altos.push_back(alto);
}

int ProcesoEx::getRestante()
{
	return this->restante;
}

void ProcesoEx::setRestante(int restante)
{
	this->restante = restante;
}
