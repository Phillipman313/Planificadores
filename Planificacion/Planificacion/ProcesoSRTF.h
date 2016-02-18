#pragma once
#include "AProceso.h"
#include <vector>
#include "stdafx.h"

class ProcesoSRTF : public AProceso
{
private:

	int progreso;

	vector<int> inicios;
	vector <int> altos;


public:
	ProcesoSRTF();
	~ProcesoSRTF();
	
	void tiempoEspera();
	void tiempoRetorno();

	int getProgreso();
	void setProgreso(int progreso);

	void agregarInicio(int inicio);
	void agregarAlto(int alto);


	

};
