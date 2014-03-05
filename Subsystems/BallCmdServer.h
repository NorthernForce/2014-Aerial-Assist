#ifndef BallCmdServer_H
#define BallCmdServer_H

#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <stdarg.h>
#include <vector>
#include <netinet/in.h>
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * A library for connecting the cRIO to a telnet
 * socket server. This class creates a thread
 * and reads strings from the telnet server and stores
 * them so that they can be read by other classes. 
 *
 * @author arthurlockman
 */
class BallCmdServer
{
private:
	int m_port;
	struct sockaddr_in in_sa;
	struct sockaddr_in out_sa;
	int in_sockfd;
	int out_sockfd;
	int connfd;
	DriverStation::Alliance alliance;
	Task m_incomingTask;
	Task m_outgoingTask;
	SEM_ID m_dataSemaphore;
	
	float xVel;
	float yVel;
	float rVel;
	
	char in_buf[3];
	char out_buf[1];
	bool recv();
	void send(char byte);
	static void AcceptTask(BallCmdServer& sock);
	static void RecvTask(BallCmdServer& sock);
	
public:
	BallCmdServer(int port);
	~BallCmdServer();
	void getVel(float* x, float* y, float* r);
	void reset();
	void init();
	void StartFeedback();
	void StopFeedback();
};

#endif
