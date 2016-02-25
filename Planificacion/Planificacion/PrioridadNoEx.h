#pragma once
#include "AEsquema.h"
#include "ProcesoPNoEx.h"
class PrioridadNoEx : public AEsquema<ProcesoPNoEx>
{
	public:
		PrioridadNoEx(queue<Proceso *> trabajos, int cantidad);
		~PrioridadNoEx();

		void iniciar();

		void agregarProceso(int& valor, int segundos);
};

