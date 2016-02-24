#pragma once
#include "ProcesoEx.h"
class ProcesoPEx : public ProcesoEx
{
	private:
		int prioridad;

	public:
		ProcesoPEx();
		~ProcesoPEx();

		int getPrioridad();
		void setPrioridad(int prioridad);
};

