#pragma once
#include "AProceso.h"
#include <vector>
class ProcesoEx : public AProceso
{
	protected:
		int restante;

		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoEx();
		~ProcesoEx();

		void tiempoEspera();
		void tiempoRetorno();

		void agregarInicio(int inicio);
		void agregarAlto(int alto);

		int getRestante();
		void setRestante(int restante);
};

