#pragma once
#include "AEsquema.h"
#include "ProcesoRR.h"

class RoundRobin : public AEsquema<ProcesoRR>
{
	private:
		int quantum;

	public:
		RoundRobin(AProceso **lista, int cantidad, int quantum);
		~RoundRobin();

		void iniciar();
};

