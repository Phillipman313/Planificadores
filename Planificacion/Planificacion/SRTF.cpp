#include "stdafx.h"
#include "SRTF.h"


SRTF::SRTF(queue<Proceso*> trabajos, int cantidad) : AEsquema<ProcesoEx>(cantidad)
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
}

SRTF::~SRTF()
{
}

void SRTF::iniciar()
{
	ProcesoEx *parte = NULL;
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
		parte->setProgreso(tiempo);
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
			parte->setFin(segundos);
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

bool SRTF::cambiarProceso(int& valor, int segundos, ProcesoEx *parte, int& duracion)
{
	bool resultado = false;
	if (segundos >= lista[valor]->getLlegada())
	{
		parte->cambiar();
		if (lista[valor]->getRafaga() < parte->getRestante())
		{
			parte->agregarAlto(segundos);
			cola.push_back(parte);
			duracion = lista[valor]->getRafaga();
			parte = lista[valor];
			parte->setInicio(segundos);
			++valor;
			resultado = true;
		}
	}
	return resultado;
}

void SRTF::agregarProceso(int& valor, int segundos)
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
					int lugar = 0;
					for (int i = cola.size() - 1; i > 0; i--)
					{
						if (lista[valor]->getRafaga() < cola[i]->getRafaga())
						{
							lugar = i;
						}
					}
					cola.insert(cola.begin() + lugar, lista[valor]);
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