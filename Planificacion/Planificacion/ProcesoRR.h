#pragma once
#include "Proceso.h"
#include <vector>

class ProcesoRR : public Proceso
{
	private:
		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoRR();
		~ProcesoRR();
};

