#pragma once
#include "AEsquema.h"
#include "ProcesoRR.h"

class RoundRobin : public AEsquema<ProcesoRR>
{
	private:
		int quantum;

	public:
		RoundRobin(int quantum);
		~RoundRobin();

		void iniciar();

		int getQuantum();
		void setQuantum(int quantum);

};

