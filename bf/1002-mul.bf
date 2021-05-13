>, >, <<			Número 1 y Número 2

Conversión a números
+++++ +			Casilla 1 añade 6 (contador para restar 48 o ASCII 0)
[
 > ----- ---			Número 1 resta 8 (6 * menos 8 = menos 48)
 > ----- ---			Número 2 resta 8 (6 * menos 8 = menos 48)
 << -	 			Casilla 1 resta 1
]

Multiplicación (sumo número 1 número 2 veces)
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

Reconversión a ASCII
>>				Avanzo a casilla anterior a resultado
+++++ +			Casilla anterior a resultado (contador) añade 6
[
 > +++++ +++			Resultado añade 8 (6 * 8 = 48)
 < -	 			Contador resta 1
]
>.				Vuelvo a resultado para mostrar en pantalla