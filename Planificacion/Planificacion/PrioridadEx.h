#pragma once
#include "AEsquema.h"
#include "ProcesoPEx.h"
class PrioridadEx : public AEsquema<ProcesoPEx>
{
	public:
		PrioridadEx(queue<Proceso *> trabajos, int cantidad);
		~PrioridadEx();

		void iniciar();

		bool cambiarProceso(int& valor, int segundos, ProcesoPEx *parte, int& duracion);

		void agregarProceso(int& valor, int segundos);
};

