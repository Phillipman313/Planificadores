#pragma once
class AProceso
{
	private:
		int id;
		int llegada;
		int inicio;
		int rafaga;
		int fin;

	public:
		AProceso();
		~AProceso();

		virtual void tiempoEspera() = 0;
		virtual void tiempoEsperaMedio() = 0;
		virtual void tiempoRetorno() = 0;
		virtual void tiempoRetornoMedio() = 0;

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

