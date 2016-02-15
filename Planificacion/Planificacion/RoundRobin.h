#pragma once
#include "AEsquema.h"
#include "ProcesoRR.h"

class RoundRobin : public AEsquema<ProcesoRR>
{
	private:
		int quantum;

	public:
		//RoundRobin(int cantidad);
		RoundRobin(Proceso **lista, int cantidad, int quantum);
		~RoundRobin();

		void iniciar();

		void tiempoEspera();
		void tiempoEsperaMedio();
		void tiempoRetorno();
		void tiempoRetornoMedio();
};

