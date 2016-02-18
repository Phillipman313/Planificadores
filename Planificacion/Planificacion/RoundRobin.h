#pragma once
#include "AEsquema.h"
#include "ProcesoRR.h"

class RoundRobin : public AEsquema<ProcesoRR>
{
	private:
		int quantum;

	public:
		RoundRobin(queue<Proceso *> trabajos, int cantidad, int quantum);
		~RoundRobin();

		void iniciar();
};

