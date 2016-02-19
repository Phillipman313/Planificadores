#include<stdio.h>

void main()
{
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
	float avg_wt, avg_tat;
	printf("Cuántos Procesos hay?");
	scanf("%d", &n);

	printf("nDigite el tiempo de ráfaga:n");
	for (i = 0; i<n; i++)
	{
		printf("p%d:", i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;           //contiene el número de procesos
	}

	//ordena por orden ascendente los tiempos de ráfaga
	for (i = 0; i<n; i++)
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (bt[j]<bt[pos])
				pos = j;
		}

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0] = 0;            //el tiempo de espera para el primer proceso es cero.

						  //calcula el tiempo de espera
	for (i = 1; i<n; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += bt[j];

		total += wt[i];
	}

	avg_wt = (float)total / n;      //tiempo de espera promedio
	total = 0;

	printf("nProceso    Tiempo de ráfaga    tTiempo de EsperatTurnaround Time");
	for (i = 0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];     //calcula el tiempo de retorno
		total += tat[i];
		printf("np%dtt  %dtt    %dttt%d", p[i], bt[i], wt[i], tat[i]);
	}

	avg_tat = (float)total / n;     //tiempo de retorno promedio
	printf("nnTiempo de espera promedio=%f", avg_wt);
	printf("nTiempo de retorno promedio=%fn", avg_tat);

}