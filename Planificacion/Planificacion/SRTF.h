#pragma once
#include "AEsquema.h"
#include "ProcesoEx.h"


class SRTF : public AEsquema<ProcesoEx>
{

	public:
		SRTF(queue <Proceso *>trabajos, int cantidad);
		~SRTF();

		void iniciar();

};
