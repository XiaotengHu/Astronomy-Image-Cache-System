/**
 * ################################################
 * #################### Dispather #################
 * ################################################
 *
 * Version: 1.0
 * File: dispather.h
 * Author: Xiaoteng Hu
 * Description: Dispather
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUCSS
 **/

#include "dispatcher.h"

/*
 * FUNCTION: dispatcher
 * INPUT: string fileName
 * OUTPUT: Server IP
 * (SIDE)EFFECTS: dispatcher
 */
string dispatcher(string fileName) {

	return redisGet(fileName);

}
