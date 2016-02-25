#pragma once
#include "AProceso.h"
class ProcesoNoEx : public AProceso
{
	public:
		ProcesoNoEx();
		~ProcesoNoEx();

		void tiempoEspera();
		void tiempoRetorno();

};

