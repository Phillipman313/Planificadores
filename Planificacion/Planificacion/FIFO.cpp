#include "stdafx.h"
#include "FIFO.h"


FIFO::FIFO(queue<Proceso *> trabajos, int cantidad) : AEsquema<ProcesoNoEx>(cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		Proceso *parte = trabajos.front();
		ProcesoNoEx *tarea = new ProcesoNoEx();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		lista.push_back(tarea);
		trabajos.pop();
		trabajos.push(parte);
	}
}


FIFO::~FIFO()
{
}

void FIFO::iniciar()
{
	ProcesoNoEx *parte = NULL;
	time_t iniciar = time(NULL);
	time_t seguir = iniciar;
	int valor = 1;
	int duracion = 0;
	int segundos = 0;
	parte = agregarPrimero(iniciar, segundos);
	duracion = parte->getRafaga();
	time_t t0 = iniciar;
	while (valor != cantidad || !cola.empty())
	{
		seguir = time(NULL);
		segundos = (int)difftime(seguir, iniciar);
		agregarProceso(valor, segundos);
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		if (tiempo >= duracion)
		{
			parte->setFin(segundos);
			agregarProceso(valor, segundos);
			parte = cola.front();
			parte->setInicio(segundos);
			duracion = parte->getRafaga();
			t0 = t1;
			cola.pop_front();
		}
	}
}

void FIFO::agregarProceso(int& valor, int segundos)
{
	if (valor != cantidad)
	{
		if (segundos >= lista[valor]->getLlegada())
		{
			cola.push_back(lista[valor]);
			++valor;
		}
	}
}