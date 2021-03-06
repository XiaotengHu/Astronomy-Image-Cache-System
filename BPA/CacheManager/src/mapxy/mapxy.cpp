/**
 * ################################################
 * ################ Map Coordinates ###############
 * ################################################
 *
 * Version: 1.0
 * File: mapxy.cpp
 * Author: Xiaoteng Hu
 * Description: Map Coordinates
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUCS
 **/


#include "mapxy.h"


/*
 * FUNCTION: mapXY
 * INPUT: Start&&End Coordinates
 * OUTPUT: int*
 * (SIDE)EFFECTS: Map coordinates by accuracy
 */
int * mapXY(int startx, int starty, int endx, int endy) {

	int *xy;
	xy = new int[NUM_XY];

	//size of scale
	int scale = SIZE_ZONE/ACCURACY;

	//Lower
	xy[0] = (startx/scale)*scale;
	xy[1] = (starty/scale)*scale;

	if(xy[0] == 0) {
		xy[0] = 1;
	}

	if(xy[1] == 0) {
		xy[1] = 1;
	}

	//Upper
	if(endx%scale){
		xy[2] = (endx/scale + 1)*scale;
	}else{
		xy[2] = (endx/scale)*scale;
	}

	if(endy%scale) {
		xy[3] = (endy/scale + 1)*scale;
	}else{
		xy[3] = (endy/scale)*scale;
	}

	return xy;
}

