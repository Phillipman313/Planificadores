#pragma once
#include "AEsquema.h"
#include "ProcesoPNoEx.h"
class PrioridadNoEx : public AEsquema<ProcesoPNoEx>
{
	public:
		PrioridadNoEx(queue<Proceso *> trabajos, int cantidad);
		~PrioridadNoEx();

		void iniciar();

		bool agregarProceso(int& valor, int segundos);
};

