Entrada:
>, >, <<			Número 1 y Número 2

Conversión a números:
+++++ +			Casilla 1 añade 6 (contador para restar 48 o ASCII 0)
[
 > ----- ---			Número 1 resta 8 (6 * menos 8 = menos 48)
 > ----- ---			Número 2 resta 8 (6 * menos 8 = menos 48)
 << -	 			Casilla 1 resta 1
]

Multiplicación (sumo número 1 número 2 veces):
>[				Avanza una casilla
	>[			Avanza una casilla
		> + > +	Siguientes dos casillas suma 1
		<< -  		Casilla del número 2 resta 1
	]	   		Hasta que casilla del número 2 sea cero
	 >[			Avanzo una casilla
	 	< + > -	Cambio de ubicación la casilla anterior al resultado
	      			 con número 2
	]
 	<< -			Número 1 resta 1
]	   			Hasta que número 1 sea cero

Para mostrar el número en pantalla se hará el algoritmo de la división al
resultado de la multiplicación en donde el cociente es el dígito en la posición
de los 10 y el resíduo el dígito en la posición de los 1
Convención: d = dividendo = resultado de la multiplicación
Posición inicial:	d | 0 | 10
Posición final:	0 | d | 10-(d % 10) | d % 10 | d / 10
>>> > >++++++++++	 	Dividendo = resultado de la multiplicación |
				| 0 | 10 (divisor)
<<				De vuelta al dividendo
[
	-			Resta 1 al dividendo
	> +			Suma 1 a la copia de dividendo
	> -			Resta 1 al divisor
	[ 			Si divisor no es cero:
		> +		  Añade 1 a copia de divisor
		>>		  Va hasta última casilla 0
	]
	>			Avanza al siguiente número:
				   Si divisor es cero empieza siguiente sección
	[			Si divisor es 0
		+		Suma uno a copia de divisor para completar
		[
			- <	Copia de divisor intercambia con divisor
			+ >	  hasta que copia de divisor sea cero
		]
		> +		Suma 1 a cociente
		>>		Va hasta última casilla 0
	]
	<<<<<<			De vuelta al dividendo
]

Impresión de los dígitos
>>>>				Avanzar al dígito de los 10
> [-]				Vaciar lo que hay en la casilla siguiente
< 				Devolverse al dígito de los 10
[				Si existe:
  [
    - > + <			  Pasar el dígito de los 10 a la casilla
  ]   	  			  siguiente y conventirlo a ASCII para imprimir
  +++++ +			  Casilla vacía añade 6
  [
    > +++++ +++		  Número añade 8 para sumarle '0' (48 en ASCII)
    < -	    		  Casilla anterior resta 1
  ]
  >.<				  Imprime número
]
++++++				Añado 6 para convertir dígito de los 1 a ASCII
[
  < +++++ +++			Número añade ocho para sumarle '0' (48 en ASCII)
  > -	  			Casilla siguiente resta 1
]
<.				Imprime número
[-]				Vacía casilla
++++++++++.			Imprime nueva línea '\n' (10 en ASCII)
