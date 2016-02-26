#pragma once
#include "AProceso.h"
#include <vector>
class ProcesoEx : public AProceso
{
	protected:
		int restante;

		int progreso;

		vector<int> inicios;
		vector<int> altos;

	public:
		ProcesoEx();
		~ProcesoEx();

		int tiempoEspera();

		void cambiar();

		void agregarInicio(int inicio);
		void agregarAlto(int alto);

		int getRestante();
		void setRestante(int restante);

		int getProgreso();
		void setProgreso(int progreso);
};

