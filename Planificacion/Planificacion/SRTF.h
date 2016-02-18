#pragma once
#include "AEsquema.h"
#include "ProcesoSRTF.h"


class SRTF : public AEsquema<ProcesoSRTF>
{



	
public:
	SRTF(queue <Proceso *>trabajos, int cantidad);
	void iniciar();

};
