#pragma once
#include "AEsquema.h"
#include "ProcesoNoEx.h"
class FIFO : public AEsquema<ProcesoNoEx>
{
	public:
		FIFO(queue<Proceso *> trabajos, int cantidad);
		~FIFO();

		void iniciar();

		void agregarProceso(int& valor, int segundos);
};

