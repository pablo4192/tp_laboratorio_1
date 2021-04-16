/*
 * tp1EclipseLib.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Estanguet Pablo; DIV: 1G
 */

#ifndef TP1ECLIPSELIB_H_
#define TP1ECLIPSELIB_H_



#endif /* TP1ECLIPSELIB_H_ */

/** \brief Recibe dos valores flotantes o enteros y los suma.
 *
 * \param a float Primer valor flotante o entero a recibir.
 * \param b float Segundo valor flotante o entero a recibir
 * \return float Resultado de la suma.
 *
 */
float sumarTp1(float a, float b);

/** \brief Recibe dos valores flotantes o enteros y los resta
 *
 * \param a float Primer valor flotante o entero a recibir.
 * \param b float Segundo valor flotante o entero a recibir
 * \return float Resultado de la resta
 *
 */
float restaTp1(float a, float b);

/** \brief Recibe dos valores flotantes o enteros y los divide
 *
 * \param a float Primer valor flotante o entero a recibir.
 * \param b float Segundo valor flotante o entero a recibir
 * \return float Resultado de la division.
 *
 */
float divisionTp1(float a, float b);


/** \brief Recibe dos valores flotantes o enteros y los multiplica.
 *
 * \param a float Primer valor flotante o entero a recibir.
 * \param b float Segundo valor flotante o entero a recibir
 * \return float Resultado de la multiplicacion.
 *
 */
float multiplicacionTp1(float a, float b);


/** \brief Recibe un valor y realiza el factorial.
 *
 * \param float valor a recibir.
 * \return long int Resultado del factorial.
 *
 */
long int factorialTp1(float);


/** \brief Presenta el menu de opciones a escoger.
 *
 * \param float Primer parametro ingresado por el usuario a mostrar en pantalla.
 * \param float Segundo parametro ingresado por el usuario a mostrar en pantalla.
 * \return int Opcion elegida.
 *
 */
int menuDeOpciones(float, float);
