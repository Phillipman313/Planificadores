#pragma once
#include "AEsquema.h"
#include "ProcesoEx.h"


class SRTF : public AEsquema<ProcesoEx>
{

	public:
		SRTF(queue <Proceso *>trabajos, int cantidad);
		~SRTF();

		void iniciar();

		bool cambiarProceso(int& valor, int segundos, ProcesoEx *parte, int& duracion);

		void agregarProceso(int& valor, int segundos);
};
