#pragma once
#include <queue>
#include <vector>
#include "Proceso.h"
#include <time.h>

template <class T>
class AEsquema
{
	protected:
		queue<T *> cola;

		vector<T *> lista;

		int cantidad;

	public:
		AEsquema(int cantidad)
		{
			this->cantidad = cantidad;
		}

		~AEsquema() {}

		virtual void iniciar() = 0;

		void simular()
		{
			time_t t0 = time(NULL);
			time_t t1 = t0;
			T *parte = NULL;
			int valor = cantidad;
			while (valor != 0 || !cola.empty())
			{
				int tiempo = (int)difftime(t1, t0);
				if (parte == NULL)
				{
					parte = lista.front();
					if (tiempo >= parte->getLlegada())
					{
						cola.push(parte);
						parte = NULL;
						valor--;
					}
				}
				t1 = time(NULL);
			}
		}

		static queue<Proceso *> tareas(int cantidad)
		{
			queue<Proceso *> lista;

			int inicio = 0;

			srand(time(NULL));

			for (int i = 0; i < cantidad; i++)
			{
				Proceso *parte = new Proceso();
				parte->setId(i);
				parte->setLlegada(inicio);
				parte->setRafaga(rand() % 100 + 1);
				lista.push(parte);
				inicio = rand() % 10 + (inicio + 1);
			}

			return lista;
		}
};

