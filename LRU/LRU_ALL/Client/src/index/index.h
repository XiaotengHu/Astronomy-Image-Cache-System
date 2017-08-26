/**
 * ################################################
 * ############### Index's Operation ##############
 * ################################################
 *
 * Version: 1.0
 * File: capacity.h
 * Author: Xiaoteng Hu
 * Description: Index's Operation
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUCS
 **/

#ifndef SRC_INDEX_INDEX_H_
#define SRC_INDEX_INDEX_H_

#include <iostream>
#include <map>
#include <list>
#include <string>

#include "../struct/structs.h"
using namespace std;


/*
 * FUNCTION: Compute Area
 * INPUT: Start&&End coordinates
 * OUTPUT: Area
 * (SIDE)EFFECTS: Compute Area
 */
int comArea(int startx, int starty, int endx, int endy);


/*
 * FUNCTION: Compute Cross Area
 * INPUT: Start&&End coordinates
 * OUTPUT: Area
 * (SIDE)EFFECTS: Compute Cross Area
 */
int comCrossArea(int oldStartx, int oldStarty, int oldEndx, int oldEndy,
		int newStartx, int newStarty, int newEndx, int newEndy);


/*
 * FUNCTION: Is File Name Hit or Not
 * INPUT: IndexInfo & RequestInfo
 * OUTPUT: bool
 * (SIDE)EFFECTS: Is File Name Hit or Not
 */
bool fileNameHit(map<string, list<IndexInfo> > index, RequestInfo request);


/*
 * FUNCTION: Is Area Hit or Not
 * INPUT: IndexInfo & RequestInfo
 * OUTPUT: bool
 * (SIDE)EFFECTS: Is Area Hit or Not
 */
bool areaHit(map<string, list<IndexInfo> > index, RequestInfo request);


/*
 * FUNCTION: Merge Two IndexInfo
 * INPUT: IndexInfo & RequestInfo
 * OUTPUT: IndexInfo
 * (SIDE)EFFECTS: Merge Two IndexInfo
 */
IndexInfo merge(list<IndexInfo> *indexList, IndexInfo oldIndex, RequestInfo request);


/*
 * FUNCTION: Search In Index
 * INPUT: IndexInfo & RequestInfo
 * OUTPUT: bool
 * (SIDE)EFFECTS: Search In Index
 */
bool searchInIndex(map<string, list<IndexInfo> > index, RequestInfo request);


/*
 * FUNCTION: Update Index
 * INPUT: IndexInfo & RequestInfo
 * OUTPUT: string
 * (SIDE)EFFECTS: Update Index
 */
string  updateIndex(map<string, list<IndexInfo> > *index, RequestInfo request);


/*
 * FUNCTION: Insert Into Index
 * INPUT: IndexInfo & RequestInfo & int
 * OUTPUT: string
 * (SIDE)EFFECTS: Insert Into Index
 */
string  insertIntoIndex(map<string, list<IndexInfo> > *index, RequestInfo request, int* mapxy);


/*
 * FUNCTION: Insert Into Index
 * INPUT: IndexInfo & RequestInfo & IndexInfo
 * OUTPUT: string
 * (SIDE)EFFECTS: Insert Into Index
 */
string  insertIntoIndex(map<string, list<IndexInfo> > *index, RequestInfo request, IndexInfo tmpIndex);


/*
 * FUNCTION: Update All Index
 * INPUT: IndexInfo & int
 * OUTPUT: none
 * (SIDE)EFFECTS: Update All Index
 */
void updateAllIndex(map<string, list<IndexInfo> > *index, int currentTime);


/*
 * FUNCTION: Compute Priority
 * INPUT: IndexInfo & int
 * OUTPUT: double
 * (SIDE)EFFECTS: Compute Priority
 */
double comPriority(IndexInfo index, int currentTime);


/*
 * FUNCTION: update Total Capacity
 * INPUT: IndexInfo & int
 * OUTPUT: none
 * (SIDE)EFFECTS: Update Total Capacity
 */
void updateTotalCapacity();


#endif /* SRC_INDEX_INDEX_H_ */
