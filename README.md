# Planificadores
Implementacion de planificacion de procesos

Hay dos clases: Proceso y AEsquema<T> que representan los procesos y una clase abstracta para cada planificador


-Debido a que ciertos planificadores tienen atributos extra de los que tiene Proceso, entonces se crea una nueva clase que hereda publicamente de Proceso. Ejemplo ProcesoRR.

-Cada planificador debe ser una clase nueva que hereda de AEsquema<T> y debe implementar el metodo iniciar() de AEsquema<T>. AEsquema<T> tiene un queue que es la cola de procesos. Ejemplo RoundRobin<ProcesoRR>.

-Cuando se termina la implementacion del planificador, se usa en main.cpp y se crea una nueva instancia de la clase que se construyo y se llama iniciar()


William Arce:

-FIFO

Daniel Arrieta:

-SJF

Esteban Araya:

-SRTF

Felipe Chen:

-Round Robin

-Prioridad
