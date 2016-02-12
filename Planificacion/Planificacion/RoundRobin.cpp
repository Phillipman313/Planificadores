#include "stdafx.h"
#include "RoundRobin.h"


RoundRobin::RoundRobin(int quantum)
{
	this->quantum = quantum;

	for (int i = 0; i < cantidad; i++) {
		Proceso *parte = lista[i];
		ProcesoRR *tarea = new ProcesoRR();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		cola.push(tarea);
	}
}


RoundRobin::~RoundRobin()
{
}

void RoundRobin::iniciar()
{

}

int RoundRobin::getQuantum()
{

}

void RoundRobin::setQuantum(int quantum)
{

}