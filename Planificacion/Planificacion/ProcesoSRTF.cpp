#include "ProcesoSRTF.h"
#include "stdafx.h"

ProcesoSRTF::ProcesoSRTF()

{
}

ProcesoSRTF::~ProcesoSRTF()
{

}

void ProcesoSRTF::tiempoEspera()
{
}

void ProcesoSRTF::tiempoRetorno()
{
	
}

int ProcesoSRTF::getProgreso()
{
	return this->progreso;
}

void ProcesoSRTF::setProgreso(int progreso)
{
	this->progreso = progreso;

}

void ProcesoSRTF::agregarInicio(int inicio)
{
	inicios.push_back(inicio);
}

void ProcesoSRTF::agregarAlto(int alto)
{
	altos.push_back(alto);
}
