#ifndef _TCPLIBBASE_H_
#define _TCPLIBBASE_H_

#ifdef DLL_IMPLEMENT
#define DLL_API	__declspec(dllexport)
#else
#define DLL_API	__declspec(dllimport)
#endif

#include <stdio.h>

#define MAX_LINE		1024
#define LISTEN_BACKLOG	32
#define MAX_LISTEN_SOCKET_NUM	5000
#define MAX_READ_MSG_LEN	4096

enum STATUS_EN
{
	success = 0,
	WSAStartup_fail,
	socket_create_fail,
	bind_fail,
	listen_fail,
	event_base_new_fail,
	inet_ntop_fail,
	connect_fail,
	evconnlistener_new_bind_fail,
	bufferevent_socket_new_fail,
	bufferevent_socket_connect_fail,
};

enum CBTYPE_EN
{
	TCP_CLIENT_CONNECT = 0,		//�ͻ�����Ӧ�����ϵ���Ϣ
	TCP_CLIENT_DISCONNECT,		//�ͻ�����Ӧ�Ͽ�ʱ����Ϣ
	TCP_SERVER_CONNECT,			//�������Ӧ�ͻ������ӵ���Ϣ
	TCP_SERVER_DISCONNECT,		//�������Ӧ�ͻ��˶Ͽ�����Ϣ
	TCP_READ_DATA,						//���ݶ�ȡ��Ϣ
};

//enType���ص����ͣ�pThis�����ö���ָ�룬pBuf�����ݻ���
typedef void (*ReadCbFun)(CBTYPE_EN enType, void *pThis, void *pBuf);

struct CBFUN_PARAM_T
{
	char *pIP;
	int nPort;
	void *pThis;
	ReadCbFun cbFun;
};

struct DATA_PACKAGE_T
{
	int nLen;
	unsigned char *pData;
	void *pSendID;			//�������ݵ�ID
	DATA_PACKAGE_T()
	{
		nLen = 0;
		pData = NULL;
		pSendID = NULL;
	}
};


class CTcpCommLibBase
{
public:
	//���ش����� STATUS_EN��0-success
	virtual int Init() = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;
	/**********************************
	//pSendID�����ݷ���ID������˱��봫�롣����˴���NULLʱ���������һ�����ӵĿͻ��˷������ݡ�		
	//										�ͻ��˿�Ĭ�ϴ���NULL��					
	//pBuf���跢�͵��ַ���
	//nLen���ַ�����С��Ҫ��С��4096
	//����ֵ��0-success��С��0-fail
	**********************************/
	virtual int Send(void *pSendID, const unsigned char*pBuf, unsigned int nLen) = 0;

	//�ͻ���ʹ��
	virtual int GetSocketID();
};

//nType��0-����� 1-�ͻ���
DLL_API CTcpCommLibBase *CreateTcpCommLib(int nType, CBFUN_PARAM_T param);
DLL_API void DeleteTcpCommLib();


#endif