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
	duracion = parte->getRafaga();
	if (quantum < duracion)
	{
		duracion = quantum;
	}
	time_t t0 = iniciar;
	while (parte != NULL)
	{
		seguir = time(NULL);
		segundos = (int)difftime(seguir, iniciar);
		agregarProceso(valor, segundos);
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		parte->setRestante(tiempo);
		if (tiempo >= duracion)
		{
			parte->agregarAlto(segundos);
			if (parte->getRestante() < parte->getRafaga())
			{
				agregarProceso(valor, segundos);
				cola.push_back(parte);
			}
			else
			{
				parte->setFin(segundos);
			}
			if (valor != cantidad || !cola.empty())
			{
				if (!cola.empty())
				{
					parte = cola.front();
					if (parte->getRestante() == 0)
					{
						parte->setInicio(segundos);
						duracion = parte->getRafaga();
					}
					else
					{
						parte->agregarInicio(segundos);
						duracion = parte->getRafaga() - parte->getRestante();
						if (quantum < duracion)
						{
							duracion = quantum;
						}
					}
					t0 = t1;
					cola.pop_front();
				}
			}
			else
			{
				parte = NULL;
			}
		}
	}
}

void RoundRobin::agregarProceso(int& valor, int segundos)
{
	if (valor < cantidad)
	{
		if (segundos >= lista[valor]->getLlegada())
		{
			cola.push_back(lista[valor]);
			++valor;
		}
	}
}