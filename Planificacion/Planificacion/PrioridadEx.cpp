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
	int pasado = 0;
	while (valor != cantidad || !cola.empty())
	{
		seguir = time(NULL);
		segundos = (int)difftime(seguir, iniciar);
		if (!cambiarProceso(valor, segundos, parte, duracion))
		{
			agregarProceso(valor, segundos);
		}
		time_t t1 = seguir;
		int tiempo = (int)difftime(t1, t0);
		if (tiempo >= duracion)
		{
			if (cambiarProceso(valor, segundos, parte, duracion))
			{
				continue;
			}
			agregarProceso(valor, segundos);
			if (parte->getRestante() != 0)
			{
				cola.push_back(parte);
			}
			parte = cola.front();
			parte->setInicio(segundos);
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

bool PrioridadEx::cambiarProceso(int& valor, int segundos, ProcesoPEx *parte, int& duracion)
{
	bool resultado = false;
	if (segundos >= lista[valor]->getLlegada())
	{
		if (lista[valor]->getPrioridad() < parte->getPrioridad())
		{
			parte->agregarAlto(segundos);
			cola.push_back(parte);
			duracion = lista[valor]->getRestante();
			parte = lista[valor];
			parte->setInicio(segundos);
			++valor;
			resultado = true;
		}
	}
	return true;
}

bool PrioridadEx::agregarProceso(int& valor, int segundos)
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