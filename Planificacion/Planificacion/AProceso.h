#pragma once
class AProceso
{
	protected:
		int id;
		int llegada;
		int inicio;
		int rafaga;
		int fin;

	public:
		AProceso();
		~AProceso();

		virtual void tiempoEspera() = 0;
		virtual void tiempoRetorno() = 0;

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

