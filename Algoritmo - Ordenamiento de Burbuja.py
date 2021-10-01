"""
Algoritmo que implementa el Ordenamiento de Burbuja, el Ordenamiento de Burbuja es un algortimo sencillo que nos permte ordenar listas de una manera rapida y eficente
Más información sobre el Ordenamiento de burbuja: https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja

Puedes descargar más algortmos desde nuestro sitio web: algoritmosmathpy.github.io/algoritmosmathpy/
"""

#Creamos una lista vacia denominada "vector"
vector = []
#Obtenemos la entrada del usuario que seran todos los valores que se le agregaran a la lista
index = int(input("Ingresar valor (<= 0 para terminar): "))
#Mientras que el usuario no introduzca un valor menor o igual a cera, el programa seguira guardando datos en la lista
while index > 0:
	#La funcion append nos permite agrgar un elemnto al final de una lista
	#En este caso guadara todos los datos del usuario
	vector.append(index)
	#Seguimos obteniendo datos del usuario
	index = int(input("Ingresar valor (<= 0 para terminar): "))

#Creamos una varable "num", que contenga la longitud de la lista
num = len(vector)
#Una variable "i" que incrementara dentro del bucle
i = 0
#Un bucle que no se detendra hasta que "i" deje de ser menor que num
while i < num:
	#Una variable "j" con el valor de "i"
	j = i
	#Un bucle que no se detendra hasta que "j" deje de ser menor que num
	while j < num:
		#Hacemos comprobaciones con los datos de la lista
		if vector[i] > vector[j]:
			#Una varable "aux" con el valor del indice mayor
			aux = vector[i]
			#Hacemos un intercambio de valores dentro de la lista
			vector[i] = vector[j]
			#El dato menor ahora sera tendra como valor la variable "aux"
			vector[j] = aux
		#Incrementamos la variable "j"
		j = j + 1
	#Incementamos la variable "i"
	i = i + 1

#Mostramos la lista ordenada
print("\n Lista ordenada: ")
print(vector)
