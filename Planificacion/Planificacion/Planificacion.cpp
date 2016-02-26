// Planificacion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AEsquema.h"
#include "AProceso.h"
#include "RoundRobin.h"
#include "FIFO.h"
#include "SJF.h"
#include "SRTF.h"
#include "PrioridadNoEx.h"
#include "PrioridadEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Planificadores de procesos" << endl;

	int cantidad = 0;

	cout << "Ingrese la cantidad de procesos: " << endl;

	cin >> cantidad;

	queue<Proceso *> trabajos = AEsquema<AProceso>::tareas(cantidad);

	cout << "Procesos: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		Proceso *parte = trabajos.front();
		cout << "Id: " << parte->getId() << ", Llegada: " << parte->getLlegada() << ", Rafaga: " << parte->getRafaga() << endl;
		trabajos.pop();
		trabajos.push(parte);
	}

	//Copiar con su respectivo planificador

	system("pause");

	return 0;

	cout << "SRTF" << endl;
	SRTF *esquema = new SRTF(trabajos, cantidad);
	esquema->iniciar();
	cout << "" << endl;
	esquema->desplegarLista();
	cout << "" << endl;

	system("pause");

	return 0;
}

