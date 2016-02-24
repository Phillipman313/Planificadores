#pragma once
#include "AProceso.h"
#include <vector>
class ProcesoNoEx : public AProceso
{
	private:
		int restante;

		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoNoEx();
		~ProcesoNoEx();

		void tiempoEspera();
		void tiempoRetorno();

		void agregarInicio(int inicio);
		void agregarAlto(int alto);

		int getRestante();
		void setRestante(int restante);
};

