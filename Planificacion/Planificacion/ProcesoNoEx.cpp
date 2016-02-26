#include "stdafx.h"
#include "ProcesoNoEx.h"


ProcesoNoEx::ProcesoNoEx()
{
}


ProcesoNoEx::~ProcesoNoEx()
{
}


int ProcesoNoEx::tiempoEspera()
{
	espera = inicio - llegada;
	return espera;
}