/**
 * ################################################
 * ################### Socket ####################
 * ################################################
 *
 * Version: 1.0
 * File: socket.h
 * Author: Xiaoteng Hu
 * Description: Socket Communications
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUCSS
 **/

#ifndef SRC_SOCKET_SOCKET_H_
#define SRC_SOCKET_SOCKET_H_

#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>

#include "../struct/structs.h"
#include "../utils/stringOper.h"
#include "../variables/variables.h"


/*
 * FUNCTION: send message to server
 * INPUT: RequestInfo request && string pattern
 * OUTPUT:
 * (SIDE)EFFECTS: send message to server
 */
void send(string ip, RequestInfo request, string pattern);


/*
 * FUNCTION: send EOF to server
 * INPUT:
 * OUTPUT:
 * (SIDE)EFFECTS: send EOF to server
 */
void reqEOF();


/*
 * FUNCTION: receive message from client
 * INPUT:
 * OUTPUT: RequestInfo
 * (SIDE)EFFECTS: receive message from client
 */
RequestInfo recevice(string pattern);

#endif /* SRC_SOCKET_SOCKET_H_ */
