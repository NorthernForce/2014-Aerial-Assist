#include "BallCmdServer.h"
#include "../Robotmap.h"

using namespace std;

/**
 * @brief Constructs the BallCmdServer class. This 
 * creates the connection, and starts the socket 
 * connection thread.
 * @param host The host name of the server to connect 
 * to (a string) (ex: "10.1.72.2").
 * @param port The port to connect to on the server (ex: 9999).
 */
BallCmdServer::BallCmdServer(int port) :
	m_port(port),
	in_sockfd(socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)),
	out_sockfd(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)),
	alliance(DriverStation::kInvalid),
	m_incomingTask("IncomingConnection", (FUNCPTR)BallCmdServer::RecvTask, Task::kDefaultPriority-10),
	m_outgoingTask("OutgoingConnection", (FUNCPTR)BallCmdServer::AcceptTask, Task::kDefaultPriority - 10),
	m_dataSemaphore(semBCreate(SEM_Q_PRIORITY, SEM_FULL)),
	xVel(0.0),
	yVel(0.0),
	rVel(0.0)
{
	printf("Starting server on port %d...\n",port);	
	
	in_sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(in_sockfd == -1) {
		printf("Error creating incoming socket\n");
	}
			
	memset(&in_sa, 0, sizeof in_sa);
	in_sa.sin_family = AF_INET;
	in_sa.sin_addr.s_addr = htonl(INADDR_ANY);
	in_sa.sin_port = htons(port);
			
	if(bind(in_sockfd, (struct sockaddr*)&in_sa, sizeof in_sa) < 0) {
		printf("Error binding socket\n");
		close(in_sockfd);
	}
	
	memset(&out_sa,0,sizeof out_sa);
	out_sa.sin_family = AF_INET;
	out_sa.sin_addr.s_addr = htonl(INADDR_ANY);
	out_sa.sin_port = htons(port);
	
	if(-1 == out_sockfd) {
		printf("Could not create outgoing socket\n");
		goto fail;
	}
	
	if(-1 == bind(out_sockfd, (struct sockaddr*)&out_sa, sizeof out_sa)) {
		printf("Could not bind socket\n");
		goto fail;
	}
	
	if(-1 == listen(out_sockfd, 1)) {
		printf("Could not listen on socket\n");
		goto fail;
	}
	
	m_incomingTask.Start(reinterpret_cast<UINT32>(this));
	m_outgoingTask.Start(reinterpret_cast<UINT32>(this));
fail:;
}

/**
 * @brief The method that the SocketConnectionTask calls
 * to begin running. 
 */
void BallCmdServer::AcceptTask(BallCmdServer &sock)
{
	while(1) {
		if(sock.connfd < 0) {
			sock.connfd = accept(sock.out_sockfd, 0, 0);
			Wait(1.0);
		}
	}
}

void BallCmdServer::RecvTask(BallCmdServer& sock) {
	while(sock.recv());
}

void BallCmdServer::init() {
	alliance = DriverStation::GetInstance()->GetAlliance();
}

void BallCmdServer::getVel(float* x, float* y, float* r) {
	const Synchronized sync(m_dataSemaphore);
	if(x != 0) *x = xVel;
	if(y != 0) *y = yVel;
	if(r != 0) *r = rVel;
}

/**
 * @brief Starts the stream of data from the server.
 */
void BallCmdServer::StartFeedback()
{
	if(alliance == DriverStation::kRed) {
		send(1);
	} else if(alliance == DriverStation::kBlue) {
		send(2);
	} else {
		send(0);
	}
}

/**
 * @brief Stops the stream of data from the server. 
 */
void BallCmdServer::StopFeedback()
{
	return send(0);
}

/**
 * @brief Sends a line of data back to the server. 
 * @param line The line of data to send.
 * @return The number of bytes sent. -1 if error. 
 */
void BallCmdServer::send(char byte)
{
	if(connfd >= 0) {
		out_buf[0] = byte;
		if(::send(connfd, out_buf, 1, 0) < 0) {
			close(connfd);
			connfd = -1;
		}
	}
}

bool BallCmdServer::recv() {
	if(3 == recvfrom(in_sockfd, in_buf, sizeof in_buf, 0, 0, 0)) {
		const Synchronized sync(m_dataSemaphore);
		xVel = (in_buf[0] <= 127) ? (in_buf[0]/127.0f) : ((in_buf[0]-255.0f)/128.0f);
		yVel = (in_buf[1] <= 127) ? (in_buf[1]/127.0f) : ((in_buf[1]-255.0f)/128.0f);
		rVel = (in_buf[2] <= 127) ? (in_buf[2]/127.0f) : ((in_buf[2]-255.0f)/128.0f);
		return true;
	} else {
		return false;
	}
}

void BallCmdServer::reset() {
	const Synchronized sync(m_dataSemaphore);
	xVel = 0.0;
	yVel = 0.0;
	rVel = 0.0;
}
