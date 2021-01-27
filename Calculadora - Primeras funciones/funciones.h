/** \brief Valida que la opcion sea elegida sea la correcta
 *
 * \param opcion- la opcion elegida por el usuario
 * \param desde- opcion minima valida
 * \param hasta- opcion maxima valida
 * \param msjError- mensaje a ser mostrado al ingresar una opcion no valida
 * \return 0 error - 1 ok
 *
 */
int validarOpcion(int opcion,int desde,int hasta,char* msjError);

/** \brief Realiza una suma entre dos valores
 *
 * \param numeroA- operando 1 que sera sumado
 * \param numeroB- operando 2 que sera sumado
 * \return suma entre dos numeros
 *
 */
int realizarSuma(int numeroA,int numeroB);

/** \brief Realiza una resta entre dos valores
 *
 * \param numeroA- operando 1 que sera restado
 * \param numeroB- operando 2 que sera restado
 * \return resta entre dos numeros
 *
 */
int realizarResta(int numeroA,int numeroB);

/** \brief Realiza una division entre dos valores
 *
 * \param numeroA- operando 1 que sera dividido
 * \param numeroB- operando 2 que sera dividendo
 * \return division entre dos numeros
 *
 */
 float realizarDivision(int numeroA,int numeroB);

/** \brief Realiza una multiplicacion entre dos valores
 *
 * \param numeroA- operando 1 que sera multiplicado
 * \param numeroB- operando 2 que sera multiplicador
 * \return multiplicacion entre ambos numeros
 *
 */
int realizarMultiplicacion(int numeroA,int numeroB);

/** \brief Realiza factorial de un numero
 *
 * \param numeroA- operando que sera factoreado
 * \return factorial
 *
 */
long realizarFactorial(int numero);


