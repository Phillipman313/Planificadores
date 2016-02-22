#include "stdafx.h"
#include "RoundRobin.h"


RoundRobin::RoundRobin(queue<Proceso *> trabajos, int cantidad, int quantum) : AEsquema<ProcesoRR>(cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		Proceso *parte = trabajos.front();
		ProcesoRR *tarea = new ProcesoRR();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		tarea->setProgreso(parte->getRafaga());
		lista.push_back(tarea);
		trabajos.pop();
		trabajos.push(parte);
	}

	this->quantum = quantum;
}


RoundRobin::~RoundRobin()
{
}


void RoundRobin::iniciar()
{
	ProcesoRR *parte = NULL;
	int valor = 0;
	int duracion = 0;
	if (lista[0]->getLlegada() == 0)
	{
		parte = lista[0];
		parte->setInicio(0);
		duracion = parte->getProgreso();
		if (quantum > duracion)
		{
			duracion = quantum;
		}
		valor++;
	}
	time_t iniciar = time(NULL);
	time_t t0 = iniciar;
	while (valor != cantidad || !cola.empty())
	{
		time_t seguir = time(NULL);
		int segundos = (int)difftime(seguir, iniciar);
		if (segundos >= lista[valor]->getLlegada())
		{
			if (parte != NULL) 
			{
				cola.push(lista[valor]);
			}
			else
			{
				parte = lista[valor];
				parte->setInicio(segundos);
				duracion = parte->getProgreso();
				if (quantum > duracion)
				{
					duracion = quantum;
				}
			}
			valor++;
		}
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		if (tiempo >= duracion)
		{
			cola.pop();
			parte->agregarAlto(segundos);
			if (parte->getProgreso() != 0)
			{
				cola.push(parte);
			}
			parte = cola.front();
			parte->setInicio(segundos);
			parte->agregarInicio(segundos);
			duracion = parte->getProgreso();
			if (quantum > duracion)
			{
				duracion = quantum;
			}
			t0 = t1;
		}
	}
}