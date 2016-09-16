#ifndef _PROTOCOLID_H
#define _PROTOCOLID_H

enum 
{
	PROTOCOL_ID_ECHO = 1,						// echo 协议
	PROTOCOL_ID_CQUERYRESULTREQ = 2,			// CQueryResultReq协议，queryd收到的客户端查询结果的协议
	PROTOCOL_ID_SQUERYRESULTREP = 3,			// SQueryResultRep协议, 控制器收到的queryd关于CQueryResultReq的回复
	PROTOCOL_ID_CSENDWEIGHTREQ  = 4,			// CSendWeightReq协议，控制器发送的传送重量的协议, 由CASD处理
	PROTOCOL_ID_CSETCAMARASEQREQ = 5,			// CSetCamaraSeqReq协议，cpsd向casd发送的设置相机序号的协议
	PROTOCOL_ID_SSETCAMARASEQREP = 6,			// SSetCamaraSeqRep协议，casd向cpsd发送的设置相机序号的响应协议
	PROTOCOL_ID_CSENDIMAGEPROCESSDATAREQ = 7,	// CSendImageProcessDataReq协议, cpsd向casd发送的图片处理数据协议
	PROTOCOL_ID_SSENDIMAGEPROCESSDATAREP = 8,	// SSendImageProcessDataReq协议, casd向cpsd回复得发送图片处理数据响应协议
	PROTOCOL_ID_CREGISTERCPSDREQ = 9,			// CRegisterCpsdReq协议，cpsd向casd发送的注册通道序号协议
	PROTOCOL_ID_SREGISTERCPSDREP = 10,			// SRegisterCpsdRep协议，casd向cpsd发送的注册通道序号的响应协议
	PROTOCOL_ID_CREGISTERCLIENTREQ = 11,		// CRegisterClientReq协议，客户端向casd发送的设置客户端通道序号的协议
	PROTOCOL_ID_SREGISTERCLIENTREP = 12,		// SRegisterClientRep协议，casd向客户端发送的设置客户端通道序号的响应协议
	PROTOCOL_ID_FVALIDATEPOSREQP = 13,			// FValidatePosReqp协议，cpsd向casd发送校验图片摆放位置的协议，casd向客户端转发校验图片摆放位置的协议
	PROTOCOL_ID_CPROCESSFEATUREREQ = 14,		// CProcessFeatureReq协议, cpsd向casd发送的处理特征的协议
	PROTOCOL_ID_SPROCESSFEATUREREP = 15,		// SProcessFeatureRep协议, casd向cpsd返回的处理特征的响应协议
	PROTOCOL_ID_SPROCESSRESULT = 16,			// SProcessResult协议, casd向客户端发送的处理结果的协议
	PROTOCOL_ID_CSETPROCESSSTATEREQ = 17,		// CProcessStateReq协议, 客户端向casd发送的设置处理状态的协议, 同时casd向cpsd转发该协议
	PROTOCOL_ID_SSETPROCESSSTATEREP = 18,		// SProcessStateRep协议, casd向客户端返回的设置处理状态的响应协议
	PROTOCOL_ID_CENDBATCHPROCESSREQ = 19,		// CEndBatchProcessReq协议, 客户端向casd发送的结束批次处理的协议
	PROTOCOL_ID_SENDBATCHPROCESSREP = 20,		// SEndBatchProcessRep协议, casd向客户端回复得结束批次处理的响应协议
	PROTOCOL_ID_CLEARNSAMPLEREQ = 21,		    // CLearnSampleReq协议, 客户端向casd发送的学习样本的协议
	PROTOCOL_ID_SLEARNSAMPLEREP = 22,		    // SLearnSampleRep协议, casd向客户端回复的学习样本的协议
};
#endif // end _PROTOCOLID_H
