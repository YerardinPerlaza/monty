, > ,			Número 1 y 2
< 			Vuelvo a Número 1
[			Operación suma
	-		Número 1 resta 1
	> +		Número 2 suma 1 alojando resultado
	<		Vuelvo a número 1 hasta que número 1 sea 0
]
+++++ +		Casilla 1 añade 6 (contador para restar 48 o ASCII 0)
[
	> ----- ---	Casilla 2 resta 8 (6 * menos 8 = menos 48)
 	< -    	Casilla 1 resta 1
]
>.			Vuelvo a casilla 2 para mostrar resultado y termina
