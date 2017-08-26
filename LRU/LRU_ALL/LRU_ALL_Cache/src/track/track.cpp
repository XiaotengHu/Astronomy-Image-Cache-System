/**
 * ################################################
 * ############### Track Operation ################
 * ################################################
 *
 * Version: 1.0
 * File: track.cpp
 * Author: Xiaoteng Hu
 * Description: Track Operation
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUC
 **/


#include "track.h"


/*
 * FUNCTION: record
 * INPUT: list<RequestInfo>
 * OUTPUT: none
 * (SIDE)EFFECTS: record of requests list
 */
void record(list<RequestInfo> requestsList) {

	writeCSV(REQUEST_RECORD_PATH, requestsList);

}


/*
 * FUNCTION: recordRate
 * INPUT: string hitRate
 * OUTPUT: none
 * (SIDE)EFFECTS: record of hit Rate
 */
void recordRate(string hitRate) {

	writeCSV(RATE_RECORD_PATH, hitRate);

}


/*
 * FUNCTION: genReqFromTrack
 * INPUT: list<RequestInfo>
 * OUTPUT: none
 * (SIDE)EFFECTS: Generate requests from track
 */
void genReqFromTrack(list<RequestInfo> *requestsList) {

	readCSV(TRACK_PATH, requestsList);

}

