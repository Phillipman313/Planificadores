#include "SRTF.h"
#include "stdafx.h"


SRTF::SRTF(queue<Proceso*> trabajos, int cantidad): AEsquema<ProcesoSRTF>(cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		Proceso *parte = trabajos.front();
		ProcesoSRTF *tarea = new ProcesoSRTF();
		tarea->setId(parte->getId());
		tarea->setLlegada(parte->getLlegada());
		tarea->setRafaga(parte->getRafaga());
		tarea->setProgreso(parte->getRafaga());
		cola.push(tarea);
		lista.push_back(tarea);
		trabajos.pop();
		trabajos.push(parte);
	}
}

void SRTF::iniciar()
{
	ProcesoSRTF *parte = NULL;
	int valor = 0;
	int duracion = 0;
	if (lista[0]->getLlegada() == 0)

		parte = lista[0];
	parte->setInicio(0);
	parte->agregarInicio(0);
	duracion = parte->getProgreso();
	if (parte->getProgreso < lista[0]->getLlegada())
	{
		cola.push(parte);
		valor++;
		}
	}