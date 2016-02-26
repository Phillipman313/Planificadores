#pragma once
class AProceso
{
	protected:
		int id;
		int llegada;
		int inicio;
		int rafaga;
		int fin;

		int espera;

	public:
		AProceso();
		~AProceso();

		virtual int tiempoEspera() = 0;
		int tiempoRetorno();

		int getId();
		void setId(int id);

		int getLlegada();
		void setLlegada(int llegada);

		int getInicio();
		void setInicio(int inicio);

		int getRafaga();
		void setRafaga(int rafaga);

		int getFin();
		void setFin(int fin);

};

