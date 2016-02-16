#include "stdafx.h"
#include "ProcesoRR.h"


ProcesoRR::ProcesoRR()
{
}


ProcesoRR::~ProcesoRR()
{
}


int ProcesoRR::getProgreso()
{
	return this->progreso;
}

void ProcesoRR::setProgreso(int progreso)
{
	this->progreso = progreso;
}

void ProcesoRR::agregarInicio(int inicio)
{
	inicios.push_back(inicio);
}

void ProcesoRR::agregarAlto(int alto)
{
	altos.push_back(alto);
}