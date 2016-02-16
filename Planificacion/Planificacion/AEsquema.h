#pragma once
#include <queue>
#include <vector>
#include "AProceso.h"
#include <time.h>

template <class T>
class AEsquema
{
	protected:
		queue<T *> cola;

		vector<T *> original;

		int cantidad;

	public:
		AEsquema(int cantidad)
		{
			this->cantidad = cantidad;
		}

		~AEsquema() {}

		virtual void iniciar() = 0;

		static AProceso **tareas(int cantidad)
		{
			AProceso **lista = new AProceso *[cantidad];

			int inicio = 0;

			srand(time(NULL));

			for (int i = 0; i < cantidad; i++)
			{
				AProceso *parte = new AProceso();
				parte->setId(i);
				parte->setLlegada(inicio);
				parte->setRafaga(rand() % 100 + 1);
				lista[i] = parte;
				inicio = rand() % 10 + (inicio + 1);
			}

			return lista;
		}
};

