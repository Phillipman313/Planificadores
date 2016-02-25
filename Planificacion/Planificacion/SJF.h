#pragma once
#include "AEsquema.h"
#include "ProcesoNoEx.h"
class SJF : public AEsquema<ProcesoNoEx>
{
	public:
		SJF(queue<Proceso *> trabajos, int cantidad);
		~SJF();

		void iniciar();

		void agregarProceso(int& valor, int segundos);
};

