/*
 * machine.h
 *
 *  Created on: 27 cze 2017
 *      Author: tomek
 */

#ifndef MACHINE_H_
#define MACHINE_H_
#include <inttypes.h>
#include <stdio.h>			// NULL

class EventData
{
public:
};

struct StateStruct;

class Machine
{
public:
	Machine(uint8_t max_states);
	uint16_t GetState();
	void Event(uint16_t new_state, EventData* pdata = NULL);
//	virtual uint16_t Who() { return 10; }
//	virtual ~Machine();
protected:
	uint16_t current_state;
	enum States {ST_NOT_ALLOWED = 0xFF};
private:
	const uint8_t _max_states;
	bool _event_generated;
	void ChangeState(uint16_t new_state);
	virtual const StateStruct* GetStateMap() { return NULL;}

};

typedef void (Machine::*StateFunc)(EventData *);
struct StateStruct
{
    StateFunc pStateFunc;
};

#endif /* MACHINE_H_ */
