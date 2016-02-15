#pragma once
#include <queue>
#include "Proceso.h"
#include <time.h>

template <class T>
class AEsquema
{
	protected:
		queue<T *> cola;

		int cantidad;

	public:
		AEsquema(int cantidad)
		{
			this->cantidad = cantidad;
		}

		~AEsquema() {}

		virtual void iniciar() = 0;

		virtual void tiempoEspera() = 0;
		virtual void tiempoEsperaMedio() = 0;
		virtual void tiempoRetorno() = 0;
		virtual void tiempoRetornoMedio() = 0;

		static Proceso **tareas(int cantidad)
		{
			Proceso **lista = new Proceso *[cantidad];

			long inicio = 0;

			srand(time(NULL));

			for (int i = 0; i < cantidad; i++)
			{
				Proceso *parte = new Proceso();
				parte->setId(i);
				parte->setLlegada(inicio);
				parte->setRafaga(rand() % 100 + 1);
				lista[i] = parte;
				inicio = rand() % 10 + (inicio + 1);
			}

			return lista;
		}
};

