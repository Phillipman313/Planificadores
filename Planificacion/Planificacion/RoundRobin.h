#pragma once
#include "AEsquema.h"
#include "ProcesoEx.h"

class RoundRobin : public AEsquema<ProcesoEx>
{
	private:
		int quantum;

	public:
		RoundRobin(queue<Proceso *> trabajos, int cantidad, int quantum);
		~RoundRobin();

		void iniciar();

		void agregarProceso(int& valor, int segundos);
};

