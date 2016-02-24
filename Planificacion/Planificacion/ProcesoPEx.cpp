#include "stdafx.h"
#include "ProcesoPEx.h"


ProcesoPEx::ProcesoPEx()
{
}


ProcesoPEx::~ProcesoPEx()
{
}

int ProcesoPEx::getPrioridad()
{
	return this->prioridad;
}

void ProcesoPEx::setPrioridad(int prioridad)
{
	this->prioridad = prioridad;
}
