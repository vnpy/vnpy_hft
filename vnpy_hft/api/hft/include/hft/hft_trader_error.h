/**
 * @file    hft_trader_error.h
 * @brief   错误码定义
 */

#ifndef _HFT_TRADER_ERROR_H_
#define _HFT_TRADER_ERROR_H_

// 错误码和错误消息定义
#define HFT_TRADER_ERRNO_MAP(XX)                                                           \
    XX(SUCCESS, 0, "成功")                                                                 \
    /* 交易API错误码 14000-14999 */                                                   \
    XX(ERR_HFT_TRADER_INTERNAL, 14000, "系统内部错误")                                     \
    XX(ERR_HFT_TRADER_INVALID_PARAM, 14001, "参数非法")                                    \
    XX(ERR_HFT_TRADER_NETWORK_TIMEOUT, 14002, "网络超时")                                  \
    XX(ERR_HFT_TRADER_NETWORK_SEND_FAIL, 14003, "消息发送失败")                            \
    XX(ERR_HFT_TRADER_INVALID_PKG, 14004, "非法协议包")                                    \
    XX(ERR_HFT_TRADER_PACK_FAIL, 14005, "打包失败")                                        \
    XX(ERR_HFT_TRADER_UNPACK_FAIL, 14006, "解包失败")                                      \
    XX(ERR_HFT_TRADER_NO_MEM, 14007, "内存不够")                                           \
    XX(ERR_HFT_TRADER_INIT_ERROR, 14008, "客户端初始化错误")                               \
    XX(ERR_HFT_TRADER_NOT_CONNECT, 14009, "客户端未连接")                                  \
    XX(ERR_HFT_TRADER_LOGIN_GW_FAIL, 14010, "客户端登录网关失败")                          \
    XX(ERR_HFT_TRADER_NOT_INIT, 14011, "客户端未初始化")                                   \
    XX(ERR_HFT_TRADER_GW_ROUTE_FAIL, 14012, "网关返回路由失败")                            \
    XX(ERR_HFT_TRADER_GW_LOGIC_FAIL, 14013, "网关返回逻辑错误")                            \
    XX(ERR_HFT_TRADER_GW_KEYFIELD_FAIL, 14014, "网关返回关键字段错误")                     \
    XX(ERR_HFT_TRADER_GW_DECODE_FAIL, 14015, "网关返回解析错误")                           \
    XX(ERR_HFT_TRADER_GW_NO_USER, 14016, "用户不在白名单内")                               \
    XX(ERR_HFT_TRADER_GW_NO_COUNTERID, 14017, "用户没配任何柜台")                          \
    XX(ERR_HFT_TRADER_GW_ERROR_IP, 14018, "用户的接入IP地址错误")                          \
    XX(ERR_HFT_TRADER_GW_ERROR_MAC, 14019, "用户的接入MAC地址错误")                        \
    XX(ERR_HFT_TRADER_NO_DATA, 14020, "未查到数据或全部数据查询完毕")                      \
    XX(ERR_HFT_TRADER_NO_CERT_FILE, 14021, "证书文件不存在")                               \
    XX(ERR_HFT_TRADER_GW_UNKOWN_MSG, 14022, "网关返回不能处理此消息")                      \
    XX(ERR_HFT_TRADER_GW_OVERRUN, 14023, "网关返回流量超限，阻断此消息")                   \
    XX(ERR_HFT_TRADER_GW_FUNDID_DISABLE, 14024, "交易账号被禁用")                          \
    XX(ERR_HFT_TRADER_GW_INVALID_CID, 14025, "网关返回客户端连接ID非法")                   \
    XX(ERR_HFT_TRADER_GW_USED_CID, 14026, "网关返回客户端连接ID已被使用")                  \
    XX(ERR_HFT_TRADER_EXCEED_MAX_NUM, 14027, "超过最大条数限制")                           \
    XX(ERR_HFT_TRADER_SEQNO_NOT_UNIQUE, 14028, "请求序号一段时间内需唯一")                 \
    XX(ERR_HFT_TRADER_GW_REQUIRE_MIN_API_VERSION, 14029, "接口版本低于最低版本要求")       \
    XX(ERR_HFT_TRADER_UNSUPPORTED_FUNC, 14030, "不支持此功能")                             \
    XX(ERR_HFT_TRADER_BUFFER_OVERFLOW, 14031, "传入的对象内存不够")                        \
    XX(ERR_HFT_TRADER_NOT_FOUND_SECUID, 14032, "未获取到股东账号")                         \
    XX(ERR_HFT_TRADER_QRY_SERVERID_FAILED, 14033, "查询账号核心号失败")                    \
    XX(ERR_HFT_TRADER_LOGIN_FAIL, 14034, "客户端登录账号失败")                             \
    XX(ERR_HFT_TRADER_QRY_SERVERID_INVALID_DATA, 14035, "查询账号核心号返回的数据不对")    \
    XX(ERR_HFT_TRADER_CALL_MICRO_SERVICE, 14036, "微服务返回调用失败")                     \
    XX(ERR_HFT_TRADER_MICRO_SERVICE_BIZERROR, 14037, "微服务返回业务错误")                 \
    XX(ERR_HFT_TRADER_GET_PASSWORD_FAIL_AFTER_CHANGE, 14038, "修改密码后获取新密码失败")   \
    XX(ERR_HFT_TRADER_GET_USERCODE_FAIL_AFTER_CHANGE, 14039, "修改密码后获取用户代码失败") \
    XX(ERR_HFT_TRADER_GET_USERCODE_FAIL, 14040, "未获取到用户代码")                        \
    XX(ERR_HFT_TRADER_SWITCH_FUND_ID_FAIL, 14041,                                          \
       "同一个API对象已成功绑定一个资金账号时，不能再使用其他账号登录")                    \
    XX(ERR_HFT_TRADER_INVALID_RSP_DATA, 14042, "应答数据为空，应答数据包有问题")           \
    XX(ERR_HFT_TRADER_EXCEED_MAX_CONNECTION, 14043, "网关返回超过最大连接数")

typedef enum {
#define XX(name, code, _) name = code,
    HFT_TRADER_ERRNO_MAP(XX)
#undef XX
} HFT_TRADER_ERROR;

#endif  // _HFT_TRADER_ERROR_H_
