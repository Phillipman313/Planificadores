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
		virtual void agregarProceso(int& valor, int segundos) = 0;

		T *agregarPrimero(time_t t0, int& segundos)
		{
			time_t t1 = t0;
			T *parte = lista[0];
			while (segundos <= parte->getLlegada())
			{
				if (segundos >= parte->getLlegada())
				{
					parte->setInicio(segundos);
					break;
				}
				t1 = time(NULL);
				segundos = (int)difftime(t1, t0);
			}
			return parte;
		}

		void tiempoEsperaMedio()
		{
			cout << "Tiempo de espera medio: (";
			int total = 0;
			int largo = cantidad - 1;
			for (int i = 0; i < largo; i++)
			{
				total += lista[i]->tiempoEspera();
				cout << lista[i]->tiempoEspera() << " + ";
			}
			cout << lista[largo]->tiempoEspera() << ") = ";
			cout << total / cantidad << endl;
		}

		void tiempoRetornoMedio()
		{
			cout << "Tiempo de retorno medio: (";
			int total = 0;
			int largo = cantidad - 1;
			for (int i = 0; i < largo; i++)
			{
				total += lista[i]->tiempoRetorno();
				cout << lista[i]->tiempoRetorno() << " + ";
			}
			cout << lista[largo]->tiempoRetorno() << ") = ";
			cout << total / cantidad << endl;
		}

		void desplegarLista()
		{
			for (int i = 0; i < cantidad; i++)
			{
				T *parte = lista[i];
				cout << "Id: " << parte->getId() << ", Inicio: " << parte->getInicio() << ", Tiempo de espera: " << parte->tiempoEspera() << ", Tiempo de retorno: " << parte->tiempoRetorno() << endl;
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
				parte->setRafaga(rand() % 10 + 1);
				lista.push(parte);
				inicio = rand() % 3 + (inicio + 1);
			}

			return lista;
		}
};

