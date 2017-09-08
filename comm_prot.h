/*
 * modbus_rtu.h
 *
 *  Created on: 27 cze 2017
 *      Author: tomek
 */

#ifndef COMM_PROT_H_
#define COMM_PROT_H_

#include <inttypes.h>

#define FRAME_LENGTH 		4

class Comm_prot
{
public:
	Comm_prot();
	void Parse(uint8_t* frame);
	void Prepare(uint8_t res);
private:
	void EnqueueCommand(uint8_t command);
	uint8_t Crc8(uint8_t *frame, uint8_t len);
	uint8_t slave_addr;
	uint8_t queued_command;
};

extern Comm_prot comm;

#endif /* COMM_PROT_H_ */
