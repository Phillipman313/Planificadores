#include "stdafx.h"
#include "ProcesoEx.h"


ProcesoEx::ProcesoEx()
{
}


ProcesoEx::~ProcesoEx()
{
}

int ProcesoEx::tiempoEspera()
{
	int tiempo = inicio - llegada;
	int largo = altos.size();
	for (int i = 0; i < largo; i++)
	{
		tiempo += (inicios[i] - altos[i]);
	}
	espera = tiempo;
	return espera;
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
