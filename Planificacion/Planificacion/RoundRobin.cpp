#include "stdafx.h"
#include "RoundRobin.h"


RoundRobin::RoundRobin(queue<Proceso *> trabajos, int cantidad, int quantum) : AEsquema<ProcesoEx>(cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		Proceso *parte = trabajos.front();
		ProcesoEx *tarea = new ProcesoEx();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		tarea->setRestante(parte->getRafaga());
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
	ProcesoEx *parte = NULL;
	int valor = 1;
	int duracion = 0;
	time_t iniciar = time(NULL);
	time_t seguir = iniciar;
	int segundos = 0;
	parte = agregarPrimero(iniciar, segundos);
	duracion = parte->getRestante();
	if (quantum < duracion)
	{
		duracion = quantum;
	}
	time_t t0 = iniciar;
	int pasado = 0;
	while (valor != cantidad || !cola.empty())
	{
		seguir = time(NULL);
		segundos = (int)difftime(seguir, iniciar);
		agregarProceso(valor, segundos);
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		if (tiempo >= duracion)
		{
			parte->agregarAlto(segundos);
			if (parte->getRestante() != 0)
			{
				agregarProceso(valor, segundos);
				cola.push_back(parte);
			}
			parte = cola.front();
			parte->setInicio(segundos);
			duracion = parte->getRestante();
			if (quantum < duracion)
			{
				duracion = quantum;
			}
			t0 = t1;
			cola.pop_front();
		}
		else
		{
			parte->reducir(tiempo - pasado);
			pasado = tiempo;
		}
	}
}