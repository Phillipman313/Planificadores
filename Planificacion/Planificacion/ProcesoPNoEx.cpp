#include "stdafx.h"
#include "ProcesoPNoEx.h"


ProcesoPNoEx::ProcesoPNoEx()
{
}


ProcesoPNoEx::~ProcesoPNoEx()
{
}

int ProcesoPNoEx::getPrioridad()
{
	return this->prioridad;
}

void ProcesoPNoEx::setPrioridad(int prioridad)
{
	this->prioridad = prioridad;
}
