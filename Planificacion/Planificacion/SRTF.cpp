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

bool SRTF::cambiarProceso(int& valor, int segundos, ProcesoEx *parte, int& duracion)
{
	bool resultado = false;
	if (segundos >= lista[valor]->getLlegada())
	{
		if (lista[valor]->getRafaga() < parte->getRestante())
		{
			parte->agregarAlto(segundos);
			cola.push_back(parte);
			duracion = parte->getRafaga();
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
				while (lista[valor]->getRafaga() != cola[valor]->getRafaga())
				{
					if (lista[valor]->getRafaga() > cola[mitad]->getRafaga())
					{
						inicio = mitad;
					}
					else
					{
						fin = mitad;
					}
				}
				cola.insert(cola.begin() + mitad, lista[valor]);
			}
			++valor;
		}
	}
}