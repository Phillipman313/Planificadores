#include "stdafx.h"
#include "PrioridadEx.h"


PrioridadEx::PrioridadEx(queue<Proceso *> trabajos, int cantidad) : AEsquema<ProcesoPEx>(cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		Proceso *parte = trabajos.front();
		ProcesoPEx *tarea = new ProcesoPEx();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		lista.push_back(tarea);
		trabajos.pop();
		trabajos.push(parte);
	}
}


PrioridadEx::~PrioridadEx()
{
}

void PrioridadEx::iniciar()
{
	ProcesoPEx *parte = NULL;
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
		if (valor < cantidad)
		{
			if (cambiarProceso(valor, segundos, parte, duracion))
			{
				continue;
			}
			agregarProceso(valor, segundos);
		}
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		parte->setRestante(tiempo);
		if (tiempo >= duracion)
		{
			if (valor < cantidad)
			{
				if (cambiarProceso(valor, segundos, parte, duracion))
				{
					continue;
				}
				agregarProceso(valor, segundos);
			}
			parte->agregarAlto(segundos);
			parte->setFin(segundos);
			parte = cola.front();
			if (parte->getRestante() == 0)
			{
				parte->setInicio(segundos);
			}
			else
			{
				parte->agregarInicio(segundos);
			}
			t0 = t1;
			cola.pop_front();
		}
	}
}

bool PrioridadEx::cambiarProceso(int& valor, int segundos, ProcesoPEx *parte, int& duracion)
{
	bool resultado = false;
	if (segundos >= lista[valor]->getLlegada())
	{
		if (lista[valor]->getPrioridad() < parte->getPrioridad())
		{
			parte->setRestante(segundos);
			parte->agregarAlto(segundos);
			cola.push_back(parte);
			duracion = lista[valor]->getRafaga();
			parte = lista[valor];
			parte->setInicio(segundos);
			++valor;
			resultado = true;
		}
	}
	return true;
}

void PrioridadEx::agregarProceso(int& valor, int segundos)
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
	}
}