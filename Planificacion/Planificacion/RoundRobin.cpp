#include "stdafx.h"
#include "RoundRobin.h"


RoundRobin::RoundRobin(AProceso **lista, int cantidad, int quantum) : AEsquema<ProcesoRR>(cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		AProceso *parte = lista[i];
		ProcesoRR *tarea = new ProcesoRR();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		cola.push(tarea);
		original.push_back(tarea);
	}

	this->quantum = quantum;
}


RoundRobin::~RoundRobin()
{
}


void RoundRobin::iniciar()
{
	time_t t0 = time(NULL);
	ProcesoRR *parte = cola.front();
	long valor = 0;
	if (parte != NULL)
	{
		parte->setInicio(valor);
		parte->agregarInicio(valor);
	}
	int duracion = parte->getRafaga();
	if (parte->getRafaga() > quantum)
	{
		duracion = quantum;
	}
	while (!cola.empty())
	{
		time_t t1 = time(NULL);
		double tiempo = difftime(t1, t0);
		if (tiempo >= duracion)
		{
			cola.pop();
			valor = duracion;
			parte->agregarAlto(valor);
			parte->setProgreso(duracion);
			if (duracion != parte->getRafaga())
			{
				cola.push(parte);
			}
			parte = cola.front();
			parte->setInicio(valor);
			parte->agregarInicio(valor);
			t0 = t1;
		}
	}
}