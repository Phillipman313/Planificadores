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
		tarea->setRestante(parte->getRafaga());
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
	int valor = 0;
	int duracion = 0;
	if (lista[0]->getLlegada() == 0)

		parte = lista[0];
	parte->setInicio(0);
	parte->agregarInicio(0);
	duracion = parte->getRestante();
	if (parte->getRestante() < lista[0]->getLlegada())
	{
		cola.push_back(parte);
		valor++;
	}
}