#include "stdafx.h"
#include "AEsquema.h"
#include <time.h>


template <class T>
AEsquema::AEsquema(int cantidad)
{
	srand(time(NULL));

	lista = new Proceso *[cantidad];

	long inicio = 0;

	for (int i = 0; i < cantidad; i++) {
		Proceso * parte = new Proceso();
		parte->setId(i);
		parte->setLlegada(inicio);
		parte->setRafaga(rand() % 100 + 1);
		lista[i] = parte;
		inicio = rand() % 10 + inicio + 1;
	}

	this->cantidad = cantidad;
}


template <class T>
AEsquema::~AEsquema()
{
}

template <class T>
int AEsquema::segundos(long t0, long t1)
{
	return (int)t1 - t0;
}