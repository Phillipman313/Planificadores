#pragma once
#include "AProceso.h"
#include <vector>

class ProcesoRR : public AProceso
{
	private:
		int progreso;

		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoRR();
		~ProcesoRR();

		void tiempoEspera();
		void tiempoEsperaMedio();
		void tiempoRetorno();
		void tiempoRetornoMedio();

		int getProgreso();
		void setProgreso(int progreso);

		void agregarInicio(int inicio);
		void agregarAlto(int alto);
};

