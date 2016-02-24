#pragma once
#include "ProcesoNoEx.h"
class ProcesoPNoEx : public ProcesoNoEx
{
	private:
		int prioridad;

	public:
		ProcesoPNoEx();
		~ProcesoPNoEx();

		int getPrioridad();
		void setPrioridad(int prioridad);
};

