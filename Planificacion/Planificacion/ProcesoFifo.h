#pragma once

class Proceso
{
	private:
		int id;
		long llegada;
		long inicio;
		long rafaga;
		long fin;

	public:
		Proceso();
		~Proceso();

		int getId();
		void setId(int id);

		long getLlegada();
		void setLlegada(long llegada);

		long getInicio();
		void setInicio(long inicio);

		long getRafaga();
		void setRafaga(long rafaga);

		long getFin();
		void setFin(long fin);
};

