**Enginyeria de Software Ràdio – Universitat Politècnica de Catalunya (UPC)**  **.**

**Autor: Sergio Ornaque Armengol**

## INTRODUCCIÓN

Este proyecto ha consistido en la creación de un DUC y un DDC usando la arquitectura &quot;Efficient IQ&quot;. La estructura del DDC se muestra en la próxima imagen, siendo la misma que en el DUC pero cambiando el orden de sus componentes.

![](RackMultipart20210529-4-18qjmkn_html_a98b81727dd0a389.png)

## SETUP DEL DUC Y DDC

El repositorio contiene 3 carpetas, en dos de ellas se encuentran los módulos que tienen que ser instalados en la carpeta de módulos de ALOE mientras la otra contiene aplicaciones para visualizar el correcto funcionamiento de éstos.

## APLICACIONES

Hay 3 aplicaciones para ver el funcionamiento de los módulos:

**1.- DUC:** En esta APP se genera un tono a 5 KHz que pasa por el DUC que hemos diseñado y se puede ver a la salida el tono a 17 KHz.

![](RackMultipart20210529-4-18qjmkn_html_8763a18c5e437b51.png)

**2.- DDC:** En esta APP se genera un tono a 5 KHz y se usa un DUC normal para trasladarlo a 17KHz. Luego se usa el DDC diseñado para trasladarlo de nuevo a banda base.

![](RackMultipart20210529-4-18qjmkn_html_7811d2e5463ba6d6.png)

**3.- DUC\_Y\_DDC:** Esta APP usa los 2 módulos que se han diseñado al mismo tiempo. En este caso, se ha configurado el DUC para hacer una interpolación por 2 y el DDC se ha configurado para delmar por 2, obteniendo los siguientes resultados:

![](RackMultipart20210529-4-18qjmkn_html_8a9759739987b6d7.png)

\* Salida del DUC con interpolación por 2

![](RackMultipart20210529-4-18qjmkn_html_50906ebba3e3de02.png)

\* Salida del DUC con delmación por 2

## MÓDULOS: DDC

El módulo tiene los siguientes parámetros de configuración:

1. **polyphaseFilterPath:** dirección relativa al filtro polifase.

1. **polyphaseFilterSize:** tamaño del filtro polifase. El tamaño máximo es de 256 coeficientes.

1. **polyphaseFilterPartitions:** cantidad de bancos que se van a generar a partir del filtro polifase.

1. **polyphaseFilterFirstCoeffI:** índice del primer coeficiente que usará el filtro de la rama I.

1. **polyphaseFilterFirstCoeffQ:** índice del primer coeficiente que usará el filtro de la rama Q.

1. **interpolationFactor:** factor de interpolación que se aplicará a la señal. Máximo 9.

1. **delmationFactor:** factor de delmado que se aplicará a la señal.

## MÓDULOS: DUC

Contiene los mismos parámetros que el DDC además de 2 parámetros extra para definir un filtro paso alto que permite eliminar el ruido en banda base.

1. **highPassFilterPath:** dirección relativa del HPF.

1. **highPassFilterSize:** tamaño del HPF. El tamaño máximo es de 1024 coeficientes.

## FILTROS POLIFASE

El switch que forma parte de la arquitectura que hemos diseñado tiene el problema de que causa un desfase de un tiempo de muestreo entre las 2 ramas.

Para arreglar este desfase, separamos los coeficientes de un filtro con módulo igual a 1 en &quot;n&quot; bancos. El resultado son &quot;n&quot; filtros con un delay de grupo diferente.

Finalmente, aplicamos un filtro de estos en cada una de las ramas para arreglar el delay que ha causado el switch.

De los 4 bancos de coeficientes conseguidos a partir de un filtro de 128 coeficientes, hemos usado los bancos que empiezan con el coeficiente 0 y 3.

Tenemos que asegurarnos de que su respuesta en frecuencia sea estable en el ancho de frecuencias que nos interesa y que su retardo de grupo también.

## FILTROS POLIFASE: INICIO EN EL COEF 0

Como se ve en las imágenes siguientes, su respuesta en frecuencia y retardo de grupo es lineal en el ancho de banda que se usa.

![](RackMultipart20210529-4-18qjmkn_html_e0dce87fa2e910f.png)

\* Respuesta frecuencial

![](RackMultipart20210529-4-18qjmkn_html_501a126da1f174cc.png)

\* Retardo de grupo

## FILTROS POLIFASE: INICIO EN EL COEF 1

![](RackMultipart20210529-4-18qjmkn_html_2d08263b4a78a7e1.png)

\* Respuesta frecuencial

![](RackMultipart20210529-4-18qjmkn_html_6db6171ad726535c.png)

\* Retardo de grupo

## FILTROS POLIFASE: INICIO EN EL COEF 2

![](RackMultipart20210529-4-18qjmkn_html_3bd5a0c00fc2e811.png)

\* Respuesta frecuencial

![](RackMultipart20210529-4-18qjmkn_html_abb6ab2beac7ee31.png)

\* Retardo de grupo

## FILTROS POLIFASE: INICIO EN EL COEF 3

![](RackMultipart20210529-4-18qjmkn_html_8bf427bac8c08fd0.png)

\* Respuesta frecuencial

![](RackMultipart20210529-4-18qjmkn_html_98bf06f8f9b5a974.png)

\* Retardo de grupo

## FILTROS ESCOGIDOS

A la hora de escoger dos bancos de filtros, se tiene que tener en cuenta que tiene que haber una diferencia entre sus delays de 1 TS.

El primer filtro que hemos escogido, siendo su primer coeficiente el índice 0 del original (que tenía 128 coeficientes) tiene un delay de:

![](RackMultipart20210529-4-18qjmkn_html_a148be0b4ccf667c.png)

El segundo filtro escogido, siendo su primer coeficiente el índice 2 del original (que tenía 128 coeficientes) tiene un delay de:

![](RackMultipart20210529-4-18qjmkn_html_8b9da3eec69095c7.png)

De esta forma, conseguimos una diferencia de delay de 1 Ts, que es justo lo que necesitábamos para arreglar el delay causado por el switch.

## FILTROS ERRONEOS

Puede ser interesante ver que pasaría si los filtros utilizados no corrigen correctamente el desfase entre la rama I y Q, para ello seleccionamos el banco de filtros que empiezan por el coeficiente cero y uno, que tienen una diferencia de delay no igual a la que agrega el switch.

El resultado es que la señal no tiene la misma amplitud que su señal imagen, como se puede ver en la siguiente imagen.

![](RackMultipart20210529-4-18qjmkn_html_733bf9047be37876.png)

## COMPUTACIÓN

Se han diseñado los módulos pensando en conseguir el menor coste computacional posible, de forma que se pueda en tiempo real.

Algunos de los parámetros de diseño que hemos aplicado con:

1. Hemos usado floats en vez de doubles.

1. Todas las funciones que necesitan leer archivos del disco duro se ejecutan en el init y los datos se guardan en la memoria RAM, de forma que no se tengan que leer archivos durante la ejecución.

1. Hacemos la delmación, interpolación y convolución al mismo tiempo.

1. Hemos eliminado todo el código residual que no se usa, así como parámetros de configuración no necesarios.

## POSIBLES MEJORAS

El HPF que se encuentra en el DDC es, teóricamente, no necesario y se podría eliminar. Lo he agregado al proyecto dado que el resultado sale más limpio al filtrar las frecuencias inferiores a las que se encuentra la señal después de pasar por el DDC.

Se tendrían que hacer más pruebas para ver si estos alias a baja frecuencia son molestos o si se pueden eliminar usando filtros polifase más lineales en frecuencia.