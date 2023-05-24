#ifndef HANDLER
#define HANDLER

#include "handler.h"
#include <iostream>
#include <string>

/**
 * This function handles Ctrl+C signal, asks user if he/she wants to end the program and
 * based on the user's answer continues executing the program or ends it
 * @param signal
 */
void handler(int signal);

#endif //HANDLER
