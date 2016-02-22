// Planificacion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AEsquema.h"
#include "AProceso.h"
#include "RoundRobin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	queue<Proceso *> trabajos = AEsquema<AProceso>::tareas(2);

	RoundRobin *esquema = new RoundRobin(trabajos, 2, 3);

	esquema->iniciar();

	return 0;
}

