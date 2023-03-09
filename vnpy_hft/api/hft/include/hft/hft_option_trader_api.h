/**
 * @file    hft_option_trader_api.h
 * @brief   期权交易相关接口定义
 */

#ifndef _HFT_OPTION_TRADER_API_H_
#define _HFT_OPTION_TRADER_API_H_

#include "hft_trader_struct.h"

/**
 * 统一说明接口中关于交易终端信息字段terminal_info格式要求：
 * PC终端格式如下：
 *     PC;IIP=xxx.xxx.xxx.xxx;IPORT=xxxxx;LIP=xxx.xxx.xxx.xxx;MAC=xxxxxxxxx^xxxxxxxxx;HD=xxxxxxxxx;CPU=xxxxxxxxx@ClientName;V1.0.1
 * 字段含义：
 *     PC===>终端类型为PC电脑
 *     IIP==>公网IP；IPORT==>公网端口（若没有公网接入则填写内网IP和端口号）
 *     LIP==>内网IP；MAC==>网卡MAC地址，可支持多个，使用^分隔
 *     HD==>硬盘序列号；CPU==>CPU序列号
 *     ClientName===>PC终端名称；V1.0.1===>PC终端版本号
 *
 * 手机终端格式如下：
 *     Android终端信息示例：
 *     MA;IIP=xxx.xxx.xxx.xxx;IPORT=xxxxx;LIP=xxx.xxx.xxx.xxx;MAC=xxxxxxxxx^xxxxxxxxx;IMEI=xxxxxxxxx;RMPN=xxxxxxxxx;UMPN=xxxxxxxxx@MobileAppName;V1.0.1
 *     iOS终端信息示例：
 *     MI;IIP=xxx.xxx.xxx.xxx;IPORT=xxxxx;LIP=xxx.xxx.xxx.xxx;MAC=xxxxxxxxx^xxxxxxxxx;IDFV=xxxxxxxxx;RMPN=xxxxxxxxx;UMPN=xxxxxxxxx@MobileAppName;V1.0.1
 * 字段含义：
 *     移动终端类型包括：MI===>iOS终端； MA===>Android终端；OH===>其他移动终端类型，包含Windows Phone
 *     IIP==>公网IP；IPORT==>公网端口（若没有公网接入则填写内网IP和端口号）
 *     LIP==>内网IP；MAC==>网卡MAC地址，可支持多个，使用^分隔
 *     IMEI==>移动Android端的标识符
 *     IDFV==>应商标识符（Identifier For Vendor），是指移动应用程序开发商用于识别用户的标识符。在同一iOS系统移动终端设备上，同一开发商的不同移动应用程序共用同一IDFV；在不同iOS系统移动终端设备上IDFV不同，由36位数字或字母组成
 *     RMPN==>注册手机号码；UMPN==>实际使用手机号码
 *     MobileAppName==>移动终端名称；V1.0.1==>移动终端版本号
 */

namespace HFT {

// 回调接口类定义
class OptionTraderSpi {
   public:
    /**
     * 连接断开时回调
     */
    virtual void OnDisconnect() {}

    /**
     * 错误消息回调，系统出错时才会回调
     * 
     * @param error_info    错误信息
     * @param request_id    对应请求时传入的序列号，如果不是请求触发的错误，此字段值为0
     */
    virtual void OnError(ErrorInfo* error_info, int request_id = 0) {}

    /**
     * 风控告警信息通知回调
     * 
     * @param risk_notify   风控告警信息
     */
    virtual void OnRiskNotify(RiskNotify* risk_notify) {}

	/**
	* 回切通知信息回调
	*
	* @param failback_notify   回切通知信息
	*/
	virtual void OnFailBackNotify(FailBackNotify* failback_notify) {}

    /**
     * 登录成功或失败时回调
     * 
     * @param rsp           登录应答数据，包含客户号、客户姓名、股东代码等信息
     * @param error_info    错误信息
     */
    virtual void OnLogin(LoginRsp* rsp, ErrorInfo* error_info) {}

    /**
     * 成交回报回调
     *
     * @param trade_detail  回调的成交详情对象
     */
    virtual void OnTradeReport(TradeDetail* trade_detail) {}

    /**
     * 订单状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnOrderStatus(OrderDetail* order_detail) {}

    /**
     * 订单委托应答回调
     *
     * @param order_rsp     订单委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info,
                            int request_id, bool is_last) {}

    /**
     * 撤单应答回调
     *
     * @param cancel_rsp    撤单应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info,
                             int request_id, bool is_last) {}

    /**
     * 查询当日订单详情的响应，一次返回一个订单详情
     * QueryOrder、QueryOrderByCode、QueryOrders均由此接口响应
     * 
     * @param order_detail  订单详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOrderRsp(OrderDetail* order_detail,
                                 ErrorInfo* error_info, int request_id,
                                 bool is_last, const char* pos_str) {}

    /**
     * 查询当日成交详情的响应，一次返回一个成交详情
     * QueryTradeByCode、QueryTrades均由此接口响应
     * 
     * @param trade_detail  成交详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryTradeRsp(TradeDetail* trade_detail,
                                 ErrorInfo* error_info, int request_id,
                                 bool is_last, const char* pos_str) {}

    /**
     * 查询当日持仓详情的响应，一次返回一个持仓详情
     * QueryPosition、QueryPositions由此接口响应
     * 
     * @param position_detail   持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryPositionRsp(OptionPositionDetail* position_detail,
                                    ErrorInfo* error_info, int request_id,
                                    bool is_last) {}

    /**
     * 查询当日资金的响应
     * 
     * @param cash_detail   资金详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCashRsp(OptionCashDetail* cash_detail,
                                ErrorInfo* error_info, int request_id) {}

    /**
     * 查集中交易系统可用资金
     *
     * @param avail_balance 可用资金，单位：人民币
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance,
                                         ErrorInfo* error_info,
                                         int request_id) {}

    /**
     * 集中交易柜台与快速柜台之间资金转入转出
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundInAndOutRsp(int64_t transfer_value,
                                           ErrorInfo* error_info,
                                           int request_id) {}

    /**
     * 行权响应
     *
     * @param exercise_rsp  行权响应详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnExerciseRsp(ExerciseRsp* exercise_rsp, ErrorInfo* error_info,
                               int request_id) {}

    /**
     * 撤销行权响应
     *
     * @param cancel_rsp    撤销行权响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCancelExerciseRsp(CancelExerciseRsp* cancel_rsp,
                                     ErrorInfo* error_info, int request_id) {}

    /**
     * 行权状态推送
     *
     * @param exercise      行权委托详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnExerciseStatus(ExerciseDetail* exercise) {}

    /**
     * 查询当日行权委托的响应，一次返回一个持仓详情
     * QueryExercise, QueryExercises由此接口响应
     *
     * @param detail            行权委托详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     * @param pos_str           本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryExerciseRsp(ExerciseDetail* detail,
                                    ErrorInfo* error_info, int request_id,
                                    bool is_last, const char* pos_str) {}

    /**
     * 查询期权合约信息
     * QueryContractInfo由此接口响应
     *
     * @param detail            期权合约信息
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryContractInfoRsp(ContractInfo* detail,
                                        ErrorInfo* error_info, int request_id,
                                        bool is_last) {}

    /**
     * 查询期权系统现货持仓的响应
     * QueryStockPositions由此接口响应
     * 
     * @param position_detail   现货持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryStockPositionRsp(PositionDetail* position_detail,
                                         ErrorInfo* error_info,
                                         int request_id, bool is_last) {}

    /**
     * 现货持仓划转状态推送
     *
     * @param transfer_detail   现货持仓划转详情
     */
    virtual void OnTransferStockStatus(TransferStockDetail* transfer_detail) {}

    /**
     * 现货持仓划转响应
     *
     * @param transfer_rsp  现货持仓划转响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnTransferStockRsp(TransferStockRsp* transfer_rsp,
                                    ErrorInfo* error_info, int request_id) {}

    /**
     * 查询现货持仓划转流水的响应
     * QueryTransferStocks由此接口响应
     * 
     * @param transfer_detail   现货持仓划转详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     */
    virtual void OnQueryTransferStockRsp(TransferStockDetail* transfer_detail,
                                         ErrorInfo* error_info,
                                         int request_id) {}

    /**
     * 锁定现货委托状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnLockOrderStatus(LockOrderDetail* order_detail) {}

    /**
     * 锁定现货委托应答回调
     *
     * @param order_rsp     锁定现货委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnLockOrderRsp(LockOrderRsp* order_rsp, ErrorInfo* error_info,
                                int request_id, bool is_last) {}

    /**
     * 查询当日锁定委托详情的响应，一次返回一个订单详情
     * QueryLockOrder、QueryLockOrders均由此接口响应
     * 
     * @param order_detail  锁定委托详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryLockOrderRsp(LockOrderDetail* order_detail,
                                     ErrorInfo* error_info, int request_id,
                                     bool is_last, const char* pos_str) {}

    /**
     * 查询当日锁定持仓详情的响应，一次返回一个持仓详情
     * QueryLockPositions由此接口响应
     * 
     * @param position_detail   锁定的现货持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryLockPositionRsp(PositionDetail* position_detail,
                                        ErrorInfo* error_info, int request_id,
                                        bool is_last) {}

    /**
     * 组合委托状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnCombOrderStatus(CombOrderDetail* order_detail) {}

    /**
     * 组合委托应答回调
     *
     * @param order_rsp     组合委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCombOrderRsp(CombOrderRsp* order_rsp, ErrorInfo* error_info,
                                int request_id, bool is_last) {}

    /**
     * 组合行权状态推送
     *
     * @param exercise      组合行权委托详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCombExerciseStatus(CombExerciseDetail* exercise) {}

    /**
     * 组合行权响应
     *
     * @param exercise_rsp  组合行权响应详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCombExerciseRsp(CombExerciseRsp* exercise_rsp,
                                   ErrorInfo* error_info, int request_id) {}

    /**
     * 撤销组合行权响应
     *
     * @param cancel_rsp    撤销组合行权响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCancelCombExerciseRsp(CancelCombExerciseRsp* cancel_rsp,
                                         ErrorInfo* error_info,
                                         int request_id) {}

    /**
     * 查询当日组合订单详情的响应，一次返回一个订单详情
     * QueryCombOrder、QueryCombOrderByCode、QueryCombOrders均由此接口响应
     * 
     * @param order_detail  组合订单详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCombOrderRsp(CombOrderDetail* order_detail,
                                     ErrorInfo* error_info, int request_id,
                                     bool is_last, const char* pos_str) {}

    /**
     * 查询当日组合行权委托的响应，一次返回一个持仓详情
     * QueryCombExercise, QueryCombExercises由此接口响应
     *
     * @param detail            组合行权委托详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     * @param pos_str           本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCombExerciseRsp(CombExerciseDetail* detail,
                                        ErrorInfo* error_info, int request_id,
                                        bool is_last, const char* pos_str) {}

    /**
     * 查询当日组合持仓详情的响应，一次返回一个持仓详情
     * QueryCombPosition、QueryCombPositions由此接口响应
     * 
     * @param position_detail   组合持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryCombPositionRsp(CombPositionDetail* position_detail,
                                        ErrorInfo* error_info, int request_id,
                                        bool is_last) {}

    /**
     * 查询组合期权合约信息
     * QueryCombContractInfo由此接口响应
     *
     * @param detail            期权合约信息
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryCombContractInfoRsp(CombContractInfo* detail,
                                            ErrorInfo* error_info,
                                            int request_id, bool is_last) {}

    /**
     * 查询资金划转流水的响应
     *
     * @param detail        资金划转明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryTransferFundHistoryRsp(TransferFundDetail* detail,
                                               ErrorInfo* error_info,
                                               int request_id, bool is_last) {}

    /**
     * 查询当日组合持仓详情的响应，一次返回一个持仓详情
     * QueryCombPositionSubDetails由此接口响应
     * 
     * @param position_detail   组合持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryCombPositionSubDetailRsp(CombPositionSubDetail* position_detail,
                                                 ErrorInfo* error_info, int request_id,
                                                 bool is_last) {}

    /**
     * 微服务应答
     *
     * @param rsp           微服务应答数据
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id) {}

    /**
     * 查询投资者限仓的响应，一次返回一个限仓详情
     * QueryPositionLimits由此接口响应
     * 
     * @param limit_detail      限仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQueryPositionLimitsRsp(PositionLimitsDetail* limit_detail,
                                          ErrorInfo* error_info, int request_id,
                                          bool is_last) {}

    /**
     * 查询投资者限额的响应，一次返回一个限额详情
     * QueryAmountLimits由此接口响应
     * 
     * @param limit_detail      限额详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     */
    virtual void OnQueryAmountLimitsRsp(AmountLimitsDetail* limit_detail,
                                        ErrorInfo* error_info, int request_id) {}

    /**
     * 查询拆分组合合约后保证金差额变动响应
     * QuerySplitCombMarginDifference由此接口响应
     * 
     * @param margin_diff_detail    拆分组合合约后保证金差额变动详情
     * @param error_info            应答的错误信息
     * @param request_id            对应请求时传入的序列号
     */
    virtual void OnQuerySplitCombMarginDifferenceRsp(SplitCombMarginDiffDetail* margin_diff_detail, 
                                                    ErrorInfo* error_info, int request_id) {}

    /**
     * 查询投资者行权指派明细响应
     * QueryExerciseAppointment由此接口响应
     * 
     * @param appointment_detail     投资者行权指派明细详情
     * @param error_info             应答的错误信息
     * @param request_id             对应请求时传入的序列号
     * @param is_last                是否是本次请求的最后一笔响应
     */
    virtual void OnQueryExerciseAppointmentRsp(ExerciseAppointmentDetail* appointment_detail, 
                                              ErrorInfo* error_info, int request_id, 
                                              bool is_last) {}

    /**
     * 查询股票期权保证金风险度明细响应
     * QueryMarginRisk由此接口响应
     * 
     * @param detail                 投资者行权指派明细详情
     * @param error_info             应答的错误信息
     * @param request_id             对应请求时传入的序列号
     */
    virtual void OnQueryMarginRiskRsp(MarginRiskDetail* detail, ErrorInfo* error_info, int request_id) {}
   
    /**
     * 查询期权最大可委托数响应
     * QueryOptionMaxOrderVolume由此接口响应
     * @param max_order_detail       期权最大可委托数详情
     * @param error_info             应答的错误信息
     * @param request_id             对应请求时传入的序列号
     */
    virtual void OnQueryOptionMaxOrderVolumeRsp(OptionMaxOrderVolumeDetail* max_order_detail, 
                                               ErrorInfo* error_info, int request_id) {}

   /**
   * 查询现货系统现货持仓的响应
   * QueryInquiryStockPositions由此接口响应
   *
   * @param position_detail   现货持仓详情
   * @param error_info        应答的错误信息
   * @param request_id        对应请求时传入的序列号
   */
   virtual void OnQueryInquiryStockPositionRsp(PositionDetail* position_detail,
											   ErrorInfo* error_info, int request_id) {}

    /**
     * 查询股票期权历史委托响应，一次返回一个历史委托详情
     * QueryOptionOrderHistory由此接口响应
     *
     * @param his_order_detail      股票期权历史委托详情
     * @param error_info            应答的错误信息
     * @param request_id            对应请求时传入的序列号
     * @param is_last               是否是本次请求的最后一笔响应
     * @param pos_str               本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionOrderHistoryRsp(OptionHisOrderDetail* his_order_detail,
                                              ErrorInfo* error_info, int request_id,
                                              bool is_last, const char* pos_str) {}

    /**
     * 查询股票期权历史成交响应，一次返回一个历史成交详情
     * QueryOptionTradeHistory由此接口响应
     *
     * @param his_trade_detail     股票期权历史成交详情
     * @param error_info           应答的错误信息
     * @param request_id           对应请求时传入的序列号
     * @param is_last              是否是本次请求的最后一笔响应
     * @param pos_str              本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionTradeHistoryRsp(OptionHisTradeDetail* his_trade_detail,
                                              ErrorInfo* error_info, int request_id,
                                              bool is_last, const char* pos_str) {}

    /**
     * 查询股票期权历史行权指派明细响应，一次返回一个历史行权指派明细详情
     * QueryExerciseAppointmentHistory由此接口响应
     *
     * @param his_appointment_detail       股票期权历史行权指派明细详情
     * @param error_info                   应答的错误信息
     * @param request_id                   对应请求时传入的序列号
     * @param is_last                      是否是本次请求的最后一笔响应
     * @param pos_str                      本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryExerciseAppointmentHistoryRsp(HisExerciseAppointmentDetail* his_appointment_detail,
                                                      ErrorInfo* error_info, int request_id,
                                                      bool is_last, const char* pos_str) {}

    /**
     * 查询股票期权历史交收明细响应，一次返回一个历史交收明细详情
     * QueryOptionDeliveryHistory由此接口响应
     *
     * @param his_delivery_detail     股票期权历史交收明细详情
     * @param error_info              应答的错误信息
     * @param request_id              对应请求时传入的序列号
     * @param is_last                 是否是本次请求的最后一笔响应
     * @param pos_str                 本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionDeliveryHistoryRsp(OptionHisDeliveryDetail* his_delivery_detail,
                                                 ErrorInfo* error_info, int request_id,
                                                 bool is_last, const char* pos_str) {}

    /**
     * 查询历史行权交收流水明细响应，一次返回一个历史行权交收流水明细
     * QueryExerciseDeliveryHistory由此接口响应
     *
     * @param exercise_delivery_detail     历史行权交收流水明细
     * @param error_info                   应答的错误信息
     * @param request_id                   对应请求时传入的序列号
     * @param is_last                      是否是本次请求的最后一笔响应
     * @param pos_str                      本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryExerciseDeliveryHistoryRsp(HisExerciseDeliveryyDetail* exercise_delivery_detail,
                                                   ErrorInfo* error_info, int request_id,
                                                   bool is_last, const char* pos_str) {}

    /**
     * 查询对账单历史合约资产响应，一次返回一个对账单历史合约资产明细
     * QueryOptionContractAssetHistory由此接口响应
     *
     * @param contract_asset_detail        对账单历史合约资产明细
     * @param error_info                   应答的错误信息
     * @param request_id                   对应请求时传入的序列号
     * @param is_last                      是否是本次请求的最后一笔响应
     * @param pos_str                      本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionContractAssetHistoryRsp(OptionHisContractAssetDetail* contract_asset_detail,
                                                      ErrorInfo* error_info, int request_id,
                                                      bool is_last, const char* pos_str) {}

    /**
     * 查询历史交收金额汇总轧差响应，一次返回一个历史交收金额汇总轧差明细
     * QueryOptionDeliveryNettingHistory由此接口响应
     *
     * @param delivery_netting_detail        历史交收金额汇总轧差明细
     * @param error_info                     应答的错误信息
     * @param request_id                     对应请求时传入的序列号
     * @param is_last                        是否是本次请求的最后一笔响应
     */
    virtual void OnQueryOptionDeliveryNettingHistoryRsp(OptionHisDeliveryNettingDetail* delivery_netting_detail,
                                                        ErrorInfo* error_info, int request_id,
                                                        bool is_last) {}

    /**
     * 查询历史组合持仓明细响应，一次返回一个历史组合持仓明细
     * QueryOptionCombPositionHistory由此接口响应
     *
     * @param comb_position_detail           历史组合持仓明细
     * @param error_info                     应答的错误信息
     * @param request_id                     对应请求时传入的序列号
     * @param is_last                        是否是本次请求的最后一笔响应
     * @param pos_str                        本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionCombPositionHistoryRsp(OptionHisCombPositionDetail* comb_position_detail,
                                                     ErrorInfo* error_info, int request_id,
                                                     bool is_last, const char* pos_str) {}

    /**
     * 查询期权历史交割单响应，一次返回一个历史交割单明细
     * QueryOptionSettlementHistory由此接口响应
     *
     * @param his_settlement_detail          期权历史交割单明细
     * @param error_info                     应答的错误信息
     * @param request_id                     对应请求时传入的序列号
     * @param is_last                        是否是本次请求的最后一笔响应
     * @param pos_str                        本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryOptionSettlementHistoryRsp(OptionHisSettlementDetail* his_settlement_detail,
                                                   ErrorInfo* error_info, int request_id,
                                                   bool is_last, const char* pos_str) {}

    /**
     * 查询期权组合策略文件响应，一次返回一个期权组合策略文件明细
     * QueryOptionCombStrategyFile由此接口响应
     *
     * @param comb_strategy_file_detail      期权组合策略文件明细
     * @param error_info                     应答的错误信息
     * @param request_id                     对应请求时传入的序列号
     * @param is_last                        是否是本次请求的最后一笔响应
     */
    virtual void OnQueryOptionCombStrategyFileRsp(OptionCombStrategyFileDetail* comb_strategy_file_detail,
                                                  ErrorInfo* error_info, int request_id, bool is_last) {}

};

// 交易接口类定义
class HFT_TRADER_EXPORT OptionTraderApi {
   public:
    /**
     * 获取OptionTraderApi实例，此实例与登录的交易账号相关联
     * 
     * @return              返回OptionTraderApi实例
     */
    static OptionTraderApi* CreateOptionTraderApi();

    /**
     * 获取API的版本信息
     */
    static const char* GetApiVersion();

    /**
     * 设置日志路径和日志级别，只需调用一次，在调用CreateOptionTraderApi之前调用
     * 
     * @param log_path      日志文件存放目录，默认相对可执行程序所在的目录
     *                      路径包含中文，请使用UTF8编码
     * @param log_level     日志级别，默认为LogLevel_Info
     */
    static void SetLogConfig(const char* log_path,
                             LogLevel log_level = LogLevel_Info);

    /**
     * 是否开启业务消息的日志，默认开启，只需调用一次，在调用CreateTraderApi之前调用
     *
     * @param enable        是否开启业务消息的日志
     */
    static void SetCriticalMsgLog(bool enable);

    /**
     * 设置首次登录失败后，自动登录重试次数，默认5次，设置为0会一直重试，
     * 只需调用一次，在调用CreateOptionTraderApi之前调用，所有API共用这个设置
     *
     * @param login_retry_count     自动登录重试次数
     */
    static void SetLoginRetryCount(int login_retry_count);

    /**
     * 设置重试登录时间间隔，默认5秒，最小值也是5秒
     * 只需调用一次，在调用CreateTraderApi之前调用，所有API共用这个设置
     *
     * @param login_retry_interval     自动登录重试时间间隔
     */
    static void SetLoginRetryInterval(int login_retry_interval);

    /**
     * 设置连接断开重连参数，只需调用一次
     *
     * @param max_retry_count     最大重连次数，大于0
     * @param min_interval        最小重连时间间隔，单位秒，最小为5秒
     * @param max_interval        最大重连时间间隔，单位秒，最小为6秒
     */
    static void SetReconnectConfig(int max_retry_count, int min_interval, int max_interval);

    /**
     * 设置应用层心跳参数，只需调用一次
     *
     * @param ka_interval         发送应用层心跳时间间隔，单位秒，默认30秒
     * @param max_probe_cnt       未收到对方心跳，继续发送心跳探测包的最大次数，默认10次
     */
    static void SetKeepaliveConfig(int ka_interval, int max_probe_cnt);

    /**
     * 不再使用本接口对象时，调用该函数删除接口对象
     */
    virtual void Release() = 0;

    /**
     * 获取最新一次错误信息
     */
    virtual ErrorInfo* GetApiLastError() = 0;

    /**
     * 注册回调接口实例，需在Login之前调用
     * 
     * @param spi           派生自回调接口类的实例
     */
    virtual void RegisterSpi(OptionTraderSpi* spi) = 0;

    /**
     * 用户登录请求
     *
     * @param req 			登录请求相关信息
     * 
     * @return              0表示发起登录请求成功，非0表示发起登录请求失败，通过GetApiLastError获取错误信息
     */
    virtual int Login(const LoginReq* req) = 0;

    /**
     * 获取用户绑定的柜台类型，登陆成功后可获取
     * 
     * @return              返回柜台类型，请参考CounterType定义
     */
    virtual int GetCounterType() = 0;

    /**
     * 获取资金账号的股东账号信息，登陆成功后可获取
     *
     * @param secuids       指向股东账号数组的指针，需调用方分配数组内存
     * @param count         股东账号数组大小，count会返回实际的数组大小
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int GetSecuidInfo(SecuidInfo* secuids, int* count) = 0;

    /**
     * 获取接口连接网关时本地地址，登录成功后可获取
     * 内网连接时获取的是内网地址，外网连接时是外网地址
     *
     * @param localAddr     接口连接网关时本地地址
     */
    virtual int GetApiLocalAddr(IpAddr* localAddr) = 0;

    /**
     * 下单
     *
     * @param order         传入下单请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int Order(OrderReq* order, int request_id) = 0;

    /**
     * 批量下单，最大支持500个
     *
     * @param orders        传入下单请求对象数组
     * @param count         传入下单请求对象数组大小
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int BatchOrder(OrderReq* orders, int count, int request_id) = 0;

    /**
     * 单个撤单
     *
     * @param cancel        传入撤单请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，错误码定义在error.h文件
     */
    virtual int CancelOrder(CancelReq* cancel, int request_id) = 0;

    /**
     * 批量撤单，最大支持500个
     *
     * @param cancels       传入撤单请求对象数组
     * @param count         传入撤单请求对象数组大小
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，错误码定义在error.h文件
     */
    virtual int BatchCancelOrder(CancelReq* cancels, int count,
                                 int request_id) = 0;

    /**
     * 行权请求
     *
     * @param exercise_req      行权的请求类型
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int Exercise(ExerciseReq* exercise_req, int request_id) = 0;

    /**
     * 撤销行权委托
     *
     * @param cancel_req        撤销行权请求类型
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CancelExercise(CancelExerciseReq* cancel_req,
                               int request_id) = 0;

    /**
     * 查询当日单个订单详情
     *
     * @param qry_req       根据委托号查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOrder(QryByOrderIdReq* qry_req, int request_id) = 0;

    /**
     * 查当日指定标的委托列表
     *
     * @param qry_req       根据指定标的查询委托列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOrderByCode(QryOrderByCodeReq* qry_req, int request_id) = 0;

    /**
     * 查询当日订单列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     *
     * @param qry_req       根据定位串查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOrders(QryOrdersReq* qry_req, int request_id) = 0;

    /**
     * 查当日指定标的成交列表
     *
     * @param qry_req       根据标的代码查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTradeByCode(QryTradeByCodeReq* qry_req, int request_id) = 0;

    /**
     * 查询账户的当日成交列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     * 
     * @param qry_req       根据定位串查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTrades(QryTradesReq* qry_req, int request_id) = 0;

    /**
     * 查当日指定标的持仓
     *
     * @param qry_req       根据标的代码查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPosition(QryByCodeReq* qry_req, int request_id) = 0;

    /**
     * 查询当日持仓列表，一次性全部查询出来
     *
     * @param qry_req       请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPositions(QryPositionsReq* qry_req, int request_id) = 0;

    /**
     * 查询当日账户资产详情
     * 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCash(QryCashReq* qry_req, int request_id) = 0;

    /**
     * 查集中交易系统可用资金
     * 仅支持泰琰柜台
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryJZJYAvailFund(int request_id) = 0;

    /**
     * 针对同一个资金账号在集中交易柜台与快速柜台之间资金转入转出
     *
     * @param trans_req         资金划转请求
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int TransferFundInAndOut(TransferFundReq* trans_req,
                                     int request_id) = 0;

    /**
     * 查询单个行权委托
     *
     * @param order_id      行权委托编号
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryExercise(const char* order_id, int request_id) = 0;

    /**
     * 查询行权委托列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     *
     * @param qry_req       查询行权委托列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryExercises(QryExercisesReq* qry_req, int request_id) = 0;

    /**
     * 查询期权合约信息
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        合约代码，格式为市场.证券ID或市场.合约ID, 默认查询所有，低延时期权柜台必传
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryContractInfo(int request_id,
                                  const char* symbol = NULL) = 0;

    /**
     * 查询期权系统现货持仓
     * 仅支持泰琰柜台
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        交易标的，格式为市场.证券ID或市场.合约ID, 默认查询所有
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryStockPositions(int request_id,
                                    const char* symbol = NULL) = 0;

    /**
     * 现货持仓划转
     * 仅支持泰琰柜台，低延时柜台不需要该接口
     *
     * @param transfer_req  传入现货转移请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int TransferStock(TransferStockReq* transfer_req,
                              int request_id) = 0;

    /**
     * 查询现货持仓划转流水
     * 仅支持泰琰柜台，低延时柜台不需要该接口
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        根据转移标的过滤查询结果, 如果为NULL，则查询所有标的
     * @param transfer_side 根据持仓转移方向过滤查询结果, 如果为0，则查询所有方向，
     *                      参考TransferStockPositionSide定义
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTransferStocks(int request_id, const char* symbol = NULL,
                                    int16_t transfer_side = 0) = 0;

    /**
     * 现货锁定委托
     *
     * @param lock_req      现货锁定请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int LockOrder(LockOrderReq* lock_req, int request_id) = 0;

    /**
     * 根据标的查询现货锁定委托
     *
     * @param symbol        标的代码，例如SH.600000
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockOrder(const char* symbol, int request_id) = 0;

    /**
     * 查询现货锁定委托列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     *
     * @param qry_req       查询现货锁定委托列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockOrders(QryLockOrdersReq* qry_req, int request_id) = 0;

    /**
     * 查询现货锁定持仓列表
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        现货锁定标的，格式为市场.证券ID或市场.合约ID, 默认查询所有
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockPositions(int request_id,
                                   const char* symbol = NULL) = 0;

    /**
     * 组合委托
     *
     * @param order         传入组合委托请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CombOrder(CombOrderReq* order, int request_id) = 0;

    /**
     * 组合行权请求
     *
     * @param exercise_req      组合行权的请求类型
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CombExercise(CombExerciseReq* exercise_req, int request_id) = 0;

    /**
     * 撤销组合行权委托
     *
     * @param cancel_req        撤销组合行权请求类型
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CancelCombExercise(CancelCombExerciseReq* cancel_req,
                                   int request_id) = 0;

    /**
     * 查询当日单个组合委托详情
     *
     * @param order_id      后台系统的订单id
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombOrder(const char* order_id, int request_id) = 0;

    /**
     * 查当日指定标的组合委托列表
     *
     * @param symbol        标的代码，例如SH.600000
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombOrderByCode(const char* symbol, int request_id) = 0;

    /**
     * 查询当日组合委托列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     *
     * @param qry_req       查询当日组合委托列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombOrders(QryCombOrdersReq* qry_req, int request_id) = 0;

    /**
     * 查询单个组合行权委托
     *
     * @param order_id      行权委托编号
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombExercise(const char* order_id, int request_id) = 0;

    /**
     * 查询组合行权委托列表，支持定位串增量查询
     * 泰琰柜台仅支持全量查询
     *
     * @param qry_req       查询组合行权委托列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombExercises(QryCombExercisesReq* qry_req, int request_id) = 0;

    /**
     * 查询当日组合持仓列表
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        根据组合合约代码查询，格式为市场.证券ID或市场.合约ID, 默认查询所有，仅支持泰琰柜台
     * @param comb_strategy 根据组合策略类型查询，请参考OptionCombineStrategy定义，仅支持泰琰柜台
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombPositions(int request_id, const char* symbol = NULL,
                                   int16_t comb_strategy = 0) = 0;

    /**
     * 查询组合期权合约信息
     * 仅支持泰琰柜台
     * 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        根据组合合约代码查询，格式为市场.证券ID或市场.合约ID, 默认查询所有
     * @param comb_strategy 根据组合策略类型查询，请参考OptionCombineStrategy定义
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombContractInfo(int request_id, const char* symbol = NULL,
                                      int comb_strategy = 0) = 0;

    /**
     * 查询资金划转流水
     * 仅支持泰琰柜台
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTransferFundHistory(int request_id) = 0;

    /**
     * 查询当日组合持仓二级明细列表
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        根据组合合约代码查询，格式为市场.证券ID或市场.合约ID, 默认查询所有，仅支持泰琰柜台
     * @param comb_strategy 根据组合策略类型查询，请参考OptionCombineStrategy定义，仅支持泰琰柜台
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCombPositionSubDetails(int request_id, const char* symbol = NULL,
                                            int16_t comb_strategy = 0) = 0;

    /**
     * 微服务请求
     *
     * @param req           请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int DoMicroServiceReq(MicroServiceReq* req, int request_id) = 0;

    /**
     * 查询投资者限仓请求
     * 仅支持泰琰柜台
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param symbol        根据标的证券代码查询，格式为市场.证券ID或市场.证券代码ID, 默认查询所有
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPositionLimits(int request_id, const char* symbol = NULL) = 0;

    /**
     * 查询投资者限额请求
     * 仅支持泰琰柜台
     *
     * @param qry_req       查询投资者限额请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryAmountLimits(QryAmountLimitsReq* qry_req, int request_id) = 0;

    /**
     * 查询拆分组合合约后保证金差额变动
     * 仅支持泰琰柜台
     * 
     * @param margin_diff_req      查询拆分组合合约后保证金差额变动请求
     * @param request_id           请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                     成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QuerySplitCombMarginDifference(QrySplitCombMarginDiffReq* margin_diff_req, int request_id) = 0;

    /**
     * 查询投资者行权指派明细
     * 仅支持泰琰柜台
     * 
     * @param exercise_appoint_req    查询投资者行权指派明细请求
     * @param request_id              请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                        成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryExerciseAppointment(QryExerciseAppointmentReq* exercise_appoint_req, int request_id) = 0;

    /**
     * 查询股票期权保证金风险度
     * 
     * @param request_id              请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                        成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryMarginRisk(int request_id) = 0;
   
    /**
     * 查询期权最大可委托数请求
     * 
     * @param max_order_req            查询期权最大可委托数请求
     * @param request_id               请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                         成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionMaxOrderVolume(QryOptionMaxOrderVolumeReq* max_order_req, int request_id) = 0;

   /**
   * 查询现货系统现货持仓
   * 仅支持泰琰柜台
   *
   * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
   * @param symbol        交易标的，格式为市场.证券ID或市场.合约ID, 默认查询所有
   *
   * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
   */
   virtual int QueryInquiryStockPosition(int request_id, const char* symbol = NULL) = 0;
   
    /**
     * 查询股票期权历史委托请求
     * 
     * @param order_history_req        查询股票期权历史委托请求
     * @param request_id               请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                         成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionOrderHistory(QryOptionHisOrderReq* order_history_req, int request_id) = 0;

    /**
     * 查询股票期权历史成交请求
     * 
     * @param trade_history_req        查询股票期权历史成交请求
     * @param request_id               请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                         成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionTradeHistory(QryOptionHisTradeReq* trade_history_req, int request_id) = 0;

    /**
     * 查询股票期权历史行权指派明细请求
     * 
     * @param appoint_history_req      查询股票期权历史行权指派明细请求
     * @param request_id               请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                         成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryExerciseAppointmentHistory(QryHisExerciseAppointmentReq* appoint_history_req, int request_id) = 0;

    /**
     * 查询股票期权历史交收明细请求，只查询普通交易数据，起始日期相差不大于3个月
     * 
     * @param delivery_history_req        查询股票期权历史交收明细请求
     * @param request_id                  请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                            成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionDeliveryHistory(QryOptionHisDeliveryReq* delivery_history_req, int request_id) = 0;

    /**
     * 查询历史行权交收流水明细请求
     * 
     * @param exercise_delivery_req        查询历史行权交收流水明细请求
     * @param request_id                   请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                             成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryExerciseDeliveryHistory(QryHisExerciseDeliveryReq* exercise_delivery_req, int request_id) = 0;

    /**
     * 查询对账单历史合约资产请求
     * 
     * @param contract_asset_req            查询对账单历史合约资产请求
     * @param request_id                    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionContractAssetHistory(QryOptionHisContractAssetReq* contract_asset_req, int request_id) = 0;

    /**
     * 查询历史交收金额汇总轧差请求，只查询普通交易数据，起始日期相差不大于3个月
     * 
     * @param delivery_netting_req            查询历史交收金额汇总轧差请求
     * @param request_id                      请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                                成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionDeliveryNettingHistory(QryOptionHisDeliveryNettingReq* delivery_netting_req, int request_id) = 0;

    /**
     * 查询历史组合持仓明细请求，起始日期相差不大于3个月
     * 
     * @param comb_position_req               查询历史组合持仓明细请求
     * @param request_id                      请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                                成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionCombPositionHistory(QryOptionHisCombPositionReq* comb_position_req, int request_id) = 0;

    /**
     * 查询期权历史交割单请求，所有导致合约持仓余额变动的数据, 包括普通交易、对冲、行权指派，起始日期相差不大于3个月
     * 
     * @param his_settlement_req              查询期权历史交割单请求
     * @param request_id                      请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                                成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionSettlementHistory(QryOptionHisSettlementReq* his_settlement_req, int request_id) = 0;

    /**
     * 查询期权组合策略文件请求
     * 
     * @param comb_strategy_file_req          期权组合策略文件查询请求
     * @param request_id                      请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return                                成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOptionCombStrategyFile(QryOptionCombStrategyFileReq* comb_strategy_file_req, int request_id) = 0;

   protected:
    virtual ~OptionTraderApi(){};
};

}  // namespace HFT

#endif  // _HFT_OPTION_TRADER_API_H_
