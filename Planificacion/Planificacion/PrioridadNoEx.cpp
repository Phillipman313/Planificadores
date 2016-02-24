#include "stdafx.h"
#include "PrioridadNoEx.h"


PrioridadNoEx::PrioridadNoEx(queue<Proceso *> trabajos, int cantidad) : AEsquema<ProcesoPNoEx>(cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		Proceso *parte = trabajos.front();
		ProcesoPNoEx *tarea = new ProcesoPNoEx();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		lista.push_back(tarea);
		trabajos.pop();
		trabajos.push(parte);
	}
}


PrioridadNoEx::~PrioridadNoEx()
{
}

void PrioridadNoEx::iniciar()
{
	ProcesoPNoEx *parte = NULL;
	int valor = 1;
	int duracion = 0;
	time_t iniciar = time(NULL);
	time_t seguir = iniciar;
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
			t0 = t1;
			cola.pop_front();
		}
	}
}

bool PrioridadNoEx::agregarProceso(int& valor, int segundos)
{
	bool resultado = false;
	if (valor != cantidad)
	{
		if (segundos >= lista[valor]->getLlegada())
		{
			if (lista[valor]->getPrioridad() <= cola.front()->getPrioridad())
			{
				cola.push_front(lista[valor]);
			}
			else if (lista[valor]->getPrioridad() >= cola.back()->getPrioridad())
			{
				cola.push_back(lista[valor]);
			}
			else
			{
				int inicio = 1;
				int fin = cantidad - 1;
				bool listo = false;
				int mitad = (fin - inicio) / 2;
				while (lista[valor]->getPrioridad() != cola[mitad]->getPrioridad())
				{
					if (lista[valor]->getPrioridad() > cola[mitad]->getPrioridad())
					{
						inicio = mitad;
					}
					else
					{
						fin = mitad;
					}
					mitad = (fin - inicio) / 2;
				}
				cola.insert(cola.begin() + mitad, lista[valor]);
			}
			++valor;
			resultado = true;
		}
	}
	return resultado;
}