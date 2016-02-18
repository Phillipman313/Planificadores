#pragma once
class Proceso
{
	private:
		int id;
		int llegada;
		int rafaga;

	public:
		Proceso();
		~Proceso();

		int getId();
		void setId(int id);

		int getLlegada();
		void setLlegada(int llegada);

		int getRafaga();
		void setRafaga(int rafaga);
};

