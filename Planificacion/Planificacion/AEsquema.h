#pragma once
#include <queue>
#include <deque>
#include <vector>
#include "Proceso.h"
#include <time.h>

template <class T>
class AEsquema
{
	protected:
		deque<T *> cola;

		vector<T *> lista;

		int cantidad;

	public:
		AEsquema(int cantidad)
		{
			this->cantidad = cantidad;
		}

		~AEsquema() {}

		virtual void iniciar() = 0;

		T *agregarPrimero(time_t t0, int& segundos)
		{
			time_t t1 = t0;
			T *parte = lista[0];
			while (segundos <= parte->getLlegada())
			{
				if (segundos == parte->getLlegada())
				{
					parte->setInicio(segundos);
					break;
				}
				t1 = time(NULL);
				segundos = (int)difftime(t1, t0);
			}
			return parte;
		}

		bool agregarProceso(int& valor, int segundos)
		{
			bool resultado = false;
			if (valor != cantidad)
			{
				if (segundos >= lista[valor]->getLlegada())
				{
					cola.push_back(lista[valor]);
					++valor;
					resultado = true;
				}
			}
			return resultado;
		}

		static queue<Proceso *> tareas(int cantidad)
		{
			queue<Proceso *> lista;

			int inicio = 3;

			srand(time(NULL));

			for (int i = 0; i < cantidad; i++)
			{
				Proceso *parte = new Proceso();
				parte->setId(i);
				parte->setLlegada(inicio);
				parte->setRafaga(rand() % 10);
				lista.push(parte);
				inicio = rand() % 10 + (inicio + 1);
			}

			return lista;
		}
};

