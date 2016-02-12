#pragma once
#include <queue>
#include "Proceso.h"

template <class T>
class AEsquema
{
	protected:
		queue<T *> cola;

		Proceso **lista;
		int cantidad;

	public:
		AEsquema(int cantidad);
		~AEsquema();

		virtual void iniciar() = 0;

		int segundos(long t0, long t1);
};

