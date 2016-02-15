#pragma once
#include "Proceso.h"
#include <vector>

class ProcesoRR : public Proceso
{
	private:
		long progreso;

		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoRR();
		~ProcesoRR();

		int getProgreso();
		void setProgreso(int progreso);

		void agregarInicio(int inicio);
		void agregarAlto(int alto);
};

