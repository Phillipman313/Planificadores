#include "stdafx.h"
#include "SJF.h"


SJF::SJF(queue<Proceso *> trabajos, int cantidad) : AEsquema<ProcesoNoEx>(cantidad)
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


SJF::~SJF()
{
}

void SJF::iniciar()
{
	ProcesoNoEx *parte = NULL;
	int valor = 1;
	int duracion = 0;
	time_t iniciar = time(NULL);
	time_t seguir = iniciar;
	int segundos = 0;
	parte = agregarPrimero(iniciar, segundos);
	duracion = parte->getRafaga();
	time_t t0 = iniciar;
	while (parte != NULL)
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
			if (valor != cantidad || !cola.empty())
			{
				if (!cola.empty())
				{
					parte = cola.front();
					parte->setInicio(segundos);
					duracion = parte->getRafaga();
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

void SJF::agregarProceso(int& valor, int segundos)
{
	if (valor != cantidad)
	{
		if (segundos >= lista[valor]->getLlegada())
		{
			if (!cola.empty())
			{
				if (lista[valor]->getRafaga() <= cola.front()->getRafaga())
				{
					cola.push_front(lista[valor]);
				}
				else if (lista[valor]->getRafaga() >= cola.back()->getRafaga())
				{
					cola.push_back(lista[valor]);
				}
				else
				{
					int inicio = 1;
					int fin = cantidad - 1;
					int mitad = (fin - inicio) / 2;
					while (lista[valor]->getRafaga() != cola[mitad]->getRafaga())
					{
						if (lista[valor]->getRafaga() > cola[mitad]->getRafaga())
						{
							fin = mitad;
						}
						else
						{
							inicio = mitad;
						}
						mitad = (fin - inicio) / 2;
					}
					cola.insert(cola.begin() + mitad, lista[valor]);
				}
			}
			else
			{
				cola.push_back(lista[valor]);
			}
			++valor;
		}
	}
}
