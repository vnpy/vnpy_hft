/**
 * @file    hft_trader_api.h
 * @brief   现货两融交易相关接口定义
 */

#ifndef _HFT_TRADER_API_H_
#define _HFT_TRADER_API_H_

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
class TraderSpi {
   public:
    virtual ~TraderSpi() {}

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
     * 订单委托的响应
     * Order、BatchOrder、AppointContractSellStockRepay均由此接口响应
     *
     * @param order_rsp     订单委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info, int request_id,
                            bool is_last) {}

    /**
     * 撤单的响应
     *
     * @param cancel_rsp    撤单应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info, int request_id,
                             bool is_last) {}

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
    virtual void OnQueryOrderRsp(OrderDetail* order_detail, ErrorInfo* error_info, int request_id,
                                 bool is_last, const char* pos_str) {}

    /**
     * 查询当日成交详情的响应，一次返回一个成交详情
     * QueryTradeByCode、QueryTradeByOrderId、QueryTrades、QueryETFTrades均由此接口响应
     * 
     * @param trade_detail  成交详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryTradeRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id,
                                 bool is_last, const char* pos_str) {}

    /**
     * 查询当日持仓详情的响应，一次返回一个持仓详情
     * QueryPosition、QueryPositions由此接口响应
     * 
     * @param position_detail   持仓详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     * @param pos_str           本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryPositionRsp(PositionDetail* position_detail, ErrorInfo* error_info,
                                    int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询当日资金的响应
     * 
     * @param cash_detail   资金详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCashRsp(CashDetail* cash_detail, ErrorInfo* error_info, int request_id) {}

    /**
     * 查集中交易系统可用资金
     *
     * @param avail_balance 可用资金，单位：人民币
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance, ErrorInfo* error_info,
                                         int request_id) {}

    /**
     * 集中交易柜台与快速柜台之间资金转入转出
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundInAndOutRsp(int64_t transfer_value, ErrorInfo* error_info,
                                           int request_id) {}

    /**
     * 针对同一个资金账号，一户两地之间资金划转
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundBetweenSecuidRsp(int64_t transfer_value, ErrorInfo* error_info,
                                                int request_id) {}

    /**
     * 查询ETF基本信息的响应，每次返回一个ETF信息
     * 
     * @param etf_detail    ETF基本信息详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
	 * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryETFRsp(ETFDetail* etf_detail, ErrorInfo* error_info, int request_id,
                               bool is_last, const char* pos_str) {}

    /**
     * 查询一个ETF股票篮子的响应，每次返回ETF的一个股票信息
     * 
     * @param etf_stock_detail      ETF的一个股票信息
     * @param error_info            应答的错误信息
     * @param request_id            对应请求时传入的序列号
     * @param is_last               是否是本次请求的最后一笔响应
	 * @param pos_str				本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryETFStockRsp(ETFStockDetail* etf_stock_detail, ErrorInfo* error_info,
                                    int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询最大可委托数量回调
     *
     * @param detail        最大可委托数量数据
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryMaxOrderQtyRsp(MaxOrderQtyDetail* detail, ErrorInfo* error_info,
                                       int request_id) {}

    /**
     * 查询新股可申购额度的响应
     *
     * @param detail        新股可申购额度数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryIPOMaxPurchaseRsp(IPOMaxPurchaseDetail* detail, ErrorInfo* error_info,
                                          int request_id, bool is_last) {}

    /**
     * 查询新股的响应
     *
     * @param detail        新股数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
	 * @param is_last       是否是本次请求的最后一笔响应
	 * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryIPOStockRsp(IPOStockDetail* detail, ErrorInfo* error_info, int request_id,
                                    bool is_last, const char* pos_str) {}

    /**
     * 查询证券信息的响应
     *
     * @param detail            证券信息
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQuerySecurityBaseInfoRsp(SecurityBaseInfo* detail, ErrorInfo* error_info,
                                            int request_id, bool is_last) {}

    /**
     * 担保品转入转出应答回调
     *
     * @param rsp           担保品转入转出应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditMortgageInOutRsp(CreditMortgageInOutRsp* rsp, ErrorInfo* error_info,
                                          int request_id) {}

    /**
     * 现券还券应答回调
     *
     * @param rsp           现券还券应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditStockBackRsp(CreditStockBackRsp* rsp, ErrorInfo* error_info,
                                      int request_id) {}

    /**
     * 直接还款应答回调
     *
     * @param rsp           直接还款应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditPayBackRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 指定合约直接还款
     *
     * @param rsp           还款信息
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnCreditPayBackByOrderRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info,
                                           int request_id) {}

    /**
     * 信用标的券应答回调
     *
     * @param detail        信用标的券数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditStockRsp(CreditStockDetail* detail, ErrorInfo* error_info,
                                       int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询担保品券回调
     *
     * @param detail        担保品券信息
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditMortgageHoldRsp(CreditMortgageHoldDetail* detail,
                                              ErrorInfo* error_info, int request_id, bool is_last,
                                              const char* pos_str) {}

    /**
     * 信用资产查询应答回调
     *
     * @param detail        信用资产数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCreditAssetsRsp(CreditAssetsDetail* detail, ErrorInfo* error_info,
                                        int request_id) {}

    /**
     * 查询融资合约应答回调
     *
     * @param detail        融资合约数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditFinanceRsp(CreditFinanceDetail* detail, ErrorInfo* error_info,
                                         int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询融券合约应答回调
     *
     * @param detail        融券合约数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditShortsellRsp(CreditShortsellDetail* detail, ErrorInfo* error_info,
                                           int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询可还融资负债金额应答回调
     *
     * @param detail        可还金额数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCreditRepayAmountRsp(CreditRepayAmountDetail* detail, ErrorInfo* error_info,
                                             int request_id) {}

    /**
     * 查询可还融券负债数量应答回调
     *
     * @param detail        可还融券负债数量数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
	 * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditRepayStockRsp(CreditRepayStockDetail* detail, ErrorInfo* error_info,
                                            int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询可融券卖出数量应答回调
     *
     * @param rsp               查询可融券卖出数量应答    
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     * @param is_last           是否是本次请求的最后一笔响应
	 * @param pos_str           本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditSecuritySellQtyRsp(CreditSecuritySellQtyRsp* rsp,
                                                 ErrorInfo* error_info, int request_id,
                                                 bool is_last, const char* pos_str) {}

    /**
     * 查询账户交易权限回调
     *
     * @param rsp           查询交易权限应答
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQuerySecuidRightRsp(QrySecuidRightRsp* rsp, ErrorInfo* error_info,
                                       int request_id) {}

    // 沪港通、深港通特有接口
    /**
     * 查询沪港通参考汇率的响应
     *
     * @param detail        沪港通参考汇率数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKRateRsp(HKRateDetail* detail, ErrorInfo* error_info, int request_id,
                                  bool is_last) {}

    /**
     * 查询沪港通标的券的响应
     *
     * @param detail        沪港通标的券数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKStockRsp(HKStockDetail* detail, ErrorInfo* error_info, int request_id,
                                   bool is_last, const char* pos_str) {}

    /**
     * 查询沪港通辅资金表资产的响应
     *
     * @param detail        沪港通辅资金表资产数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryHKFundRsp(HKFundDetail* detail, ErrorInfo* error_info, int request_id) {}

    /**
     * 查询沪港通最小价差的响应
     *
     * @param detail        沪港通最小价差数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKMinPriceUnitRsp(HKMinPriceUnitDetail* detail, ErrorInfo* error_info,
                                          int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询沪港通交易日历的响应
     *
     * @param detail        沪港通交易日历数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKTradeCalendarRsp(HKTradeCalendarDetail* detail, ErrorInfo* error_info,
                                           int request_id, bool is_last) {}

    /**
     * 查询锁券明细应答
     *
     * @param detail        锁券明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
	 * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryLockSecurityDetailRsp(LockSecurityDetail* detail, ErrorInfo* error_info,
                                              int request_id, bool is_last, const char* pos_str) {}

    /**
     * 展期应答
     *
     * @param rsp           展期应答数据
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnExtendLockSecurityRsp(ExtendLockSecurityRsp* rsp, ErrorInfo* error_info,
                                         int request_id) {}

    /**
     * 查询锁券展期申请应答
     *
     * @param detail        展期明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
	 * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryLockSecurityExtensionRsp(LockSecurityExtensionDetail* detail,
                                                 ErrorInfo* error_info, int request_id,
                                                 bool is_last, const char* pos_str) {}

    /**
     * 查询资金划转流水的响应
     *
     * @param detail        资金划转明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryTransferFundHistoryRsp(TransferFundDetail* detail, ErrorInfo* error_info,
                                               int request_id, bool is_last) {}

    /**
	* 查询当日负债流水的响应
	*
	* @param detail        负债流水明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
    virtual void OnQueryCreditDebtsFlowRsp(CreditDebtsFlowDetail* detail, ErrorInfo* error_info,
                                           int request_id, bool is_last, const char* pos_str) {}
                                           
    /**
    * 查询当日资金流水的响应
    *
    * @param detail        资金流水明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryCreditAssetFlowRsp(CreditAssetFlowDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last, const char* pos_str) {}

    /**
	* 查询信用客户融资融券合约的响应
	*
	* @param detail        信用客户融资融券合约明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
    virtual void OnQueryCreditDebtsRsp(CreditDebtsDetail* detail, ErrorInfo* error_info,
                                       int request_id, bool is_last, const char* pos_str) {}

    /**
     * 微服务应答
     *
     * @param rsp           微服务应答数据
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id) {}

    /**
     * 查询银行账号余额应答回调
     *
     * @param detail        银行余额明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryBankBalanceRsp(BankBalanceDetail* detail, ErrorInfo* error_info,
                                       int request_id) {}

    /**
     * 查询三方存管银行列表应答
     *
     * @param detail        银行列表明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnQueryBankInfoRsp(BankInfoDetail* detail, ErrorInfo* error_info, int request_id,
                                    bool is_last) {}

    /**
     * 银证转账应答回调
     *
     * @param rsp           银证转账应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnBankSecTransferRsp(BankSecTransferRsp* rsp, ErrorInfo* error_info,
                                      int request_id) {}

    /**
     * 查询当日银证转账数据回调
     *
     * @param rsp           当日银证转账数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
	 * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryBankSecTransferRsp(BankSecTransferDetail* detail, ErrorInfo* error_info,
                                           int request_id, bool is_last) {}

    /**
     * 查询银证转账历史数据回调
     *
     * @param detail        银证转账历史数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryHisBankSecTransferRsp(HisBankSecTransferDetail* detail,
                                              ErrorInfo* error_info, int request_id, bool is_last,
                                              const char* pos_str) {}

    /**
     * 可用资金划转应答回调
     *
     * @param detail        可用资金划转应答明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnFundAccountTransferRsp(FundAccountTransferRsp* detail, ErrorInfo* error_info,
                                          int request_id) {}

    /**
     * 查询当日主辅资金账号之间资金划转应答回调
     *
     * @param detail        主辅资金划转明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryFundAccountTransferRsp(FundAccountTransferDetail* detail,
                                               ErrorInfo* error_info, int request_id) {}

    /**
     * 查询历史委托回调
     *
     * @param detail        历史委托明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryHisOrderRsp(HisOrderDetail* detail, ErrorInfo* error_info, int request_id,
                                    bool is_last, const char* pos_str) {}

    /**
     * 查询历史成交应答回调
     *
     * @param detail        历史成交明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryHisTradeRsp(HisTradeDetail* detail, ErrorInfo* error_info, int request_id,
                                    bool is_last, const char* pos_str) {}

    /**
     * 查询交割单应答回调 -- 微服务简化版
     *
     * @param detail        交割单明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryDeliveryOrderRsp(DeliveryOrderDetail* detail, ErrorInfo* error_info,
                                         int request_id, bool is_last, const char* pos_str) {}

    /**
     * 对账单查询应答回调 -- 微服务简化版
     *
     * @param detail        对账单明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryStateOrderRsp(StateOrderDetail* detail, ErrorInfo* error_info,
                                      int request_id, bool is_last, const char* pos_str) {}

	/**
	* 查询交割单(分笔)应答回调 -- 集中交易详细版
	*
	* @param detail        交割单明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryExchangeListsRsp(ExchangeDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

    /**
     * 修改密码的响应
     *
     * @param rsp           修改密码应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnModifyPasswordRsp(ModifyPasswordRsp* rsp, ErrorInfo* error_info,
                                     int request_id) {}

    /**
	* 查询配号信息应答回调
	*
	* @param detail        配号信息数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
    virtual void OnQueryPHXXRsp(QueryPHXXRecord* detail, ErrorInfo* error_info, int request_id,
                                bool is_last, const char* pos_str) {}

    /**
	* 查询中签信息应答回调
	*
	* @param detail        中签信息数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
    virtual void OnQueryZQXXRsp(QueryZQXXRecord* detail, ErrorInfo* error_info, int request_id,
                                bool is_last, const char* pos_str) {}

    /**
     * 查询锁券合同应答
     *
     * @param detail        锁券合同详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryLockSecurityContractRsp(LockSecurityContractDetail* detail,
                                                ErrorInfo* error_info, int request_id, bool is_last,
                                                const char* pos_str) {}

    /**
     * 查询信用合同应答
     *
     * @param detail        信用合同详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditContractRsp(CreditContractDetail* detail, ErrorInfo* error_info,
                                          int request_id) {}

    /**
     * 查询融资融券合约汇总信息应答
     *
     * @param detail        融资融券合约汇总信息详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditDebtsCollectRsp(CreditDebtsCollectDetail* detail,
                                              ErrorInfo* error_info, int request_id, bool is_last,
                                              const char* pos_str) {}

    /**
     * 查询融资融券信用数据应答
     *
     * @param detail        融资融券信用数据详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditDataRsp(CreditDataDetail* detail, ErrorInfo* error_info,
                                      int request_id) {}

    /**
     * 查询信用预到期合约应答
     *
     * @param detail        信用预到期合约详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryPreMaturityDebtsRsp(PreMaturityDebtsDetail* detail, ErrorInfo* error_info,
                                            int request_id, bool is_last, const char* pos_str) {}

    /**
     * 信用预到期合约展期应答
     *
     * @param detail        信用预到期合约展期应答
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnExtendPreMaturityDebtsRsp(ExtendPreMaturityDebtsRsp* detail,
                                             ErrorInfo* error_info, int request_id) {}

    /**
     * 查询信用预到期合约展期应答
     *
     * @param detail        信用预到期合约展期详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryPreMaturityDebtsExtensionRsp(PreMaturityDebtsExtensionDetail* detail,
                                                     ErrorInfo* error_info, int request_id,
                                                     bool is_last, const char* pos_str) {}

    /**
     * 查询网络投票议案应答
     *
     * @param rsp           网络投票议案详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryVoteProposalRsp(VoteProposalDetail* detail, ErrorInfo* error_info,
                                        int request_id, bool is_last) {}

    /**
     * 查询信用投票可投票数应答
     *
     * @param detail        信用投票可投票数
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditVoteCountRsp(CreditVoteCountDetail* detail, ErrorInfo* error_info,
                                           int request_id) {}

    /**
     * 查询信用投票结果应答
     *
     * @param detail        信用投票详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryCreditVoteRsp(CreditVoteDetail* detail, ErrorInfo* error_info,
                                      int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询网络投票客户权益应答
     *
     * @param detail        网络投票客户权益明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryNetVoteRightsRsp(NetVoteRightsDetail* detail, ErrorInfo* error_info,
                                         int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询网络投票结果应答
     *
     * @param detail        网络投票结果明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryNetVoteResultRsp(NetVoteResultDetail* detail, ErrorInfo* error_info,
                                         int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询网络投票可投票数量应答
     *
     * @param detail        网络投票可投票数量明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryNetVoteCountRsp(NetVoteCountDetail* detail, ErrorInfo* error_info,
                                        int request_id, bool is_last) {}

	/**
	* 股票集中度查询应答
	*
	* @param detail        股票集中度明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryStkConcentrationRsp(StkConcentrationDetail* detail, ErrorInfo* error_info,
											int request_id, bool is_last, const char* pos_str) {}

    /**
    * 查询沪港通历史委托明细的响应
    *
    * @param detail        历史委托明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryHKHisOrderRsp(HKHisOrderDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 查询可取资金的响应
    *
    * @param detail        可取资金详情
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQueryWithdrawCashRsp(WithdrawCashRecord* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 查询网络投票委托应答
    *
    * @param detail        网络投票委托详情
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryNetVoteOrderRsp(NetVoteOrderDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last, const char* pos_str) {}
    
	/**
	* 查询当日委托表中的汇总成交信息的响应，一次返回一个成交详情
	*
	* @param trade_detail  成交详情
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryTradeTotalRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id,
											bool is_last, const char* pos_str) {}

	/**
	* ETF 认购 撤单的应答
	*
	* @param order_rsp     ETF 认购 撤单的应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnETFSubscriptCancelRsp(ETFSubscriptCancelRsp* order_rsp, ErrorInfo* error_info,
		int request_id) {}			
	
	/**
	* 网络投票委托的响应
	*
	* @param order_rsp     网络投票委托应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnNetVoteOrderRsp(NetVoteOrderRsp* order_rsp, ErrorInfo* error_info,
		int request_id) {}
	
	/**
	* 信用投票委托的响应
	*
	* @param order_rsp     信用投票委托应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnCreditNetVoteOrderRsp(CreditNetVoteOrderRsp* order_rsp, ErrorInfo* error_info,
		int request_id) {}

    /**
       * 客户资金查询应答回调，微服务渠道
       *
       * @param detail        明细信息
       * @param error_info    应答的错误信息
       * @param request_id    对应请求时传入的序列号
       * @param is_last       是否是本次请求的最后一笔响应
       * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
       */
       virtual void OnQueryMSCashRsp(MSCashDetail* detail, ErrorInfo* error_info,
               int request_id, bool is_last, const char* pos_str) {}

    /**
       * 客户持仓查询应答回调，微服务渠道
       *
       * @param detail        明细信息
       * @param error_info    应答的错误信息
       * @param request_id    对应请求时传入的序列号
       * @param is_last       是否是本次请求的最后一笔响应
       * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
       */
       virtual void OnQueryMSPositionsRsp(MSPositionsDetail* detail, ErrorInfo* error_info,
               int request_id, bool is_last, const char* pos_str) {}

    /**
       * 信用负债流水查询应答回调，微服务渠道
       *
       * @param detail        明细信息
       * @param error_info    应答的错误信息
       * @param request_id    对应请求时传入的序列号
       * @param is_last       是否是本次请求的最后一笔响应
       * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
       */
       virtual void OnQueryMSCreditDebtsFlowRsp(MSCreditDebtsFlowDetail* detail, ErrorInfo* error_info,
               int request_id, bool is_last, const char* pos_str) {}


	
};

// 交易接口类定义
class HFT_TRADER_EXPORT TraderApi {
   public:
    /**
     * 获取TraderApi实例，此实例与登录的交易账号相关联
     * 
     * @return              返回TraderApi实例
     */
    static TraderApi* CreateTraderApi();

    /**
     * 获取API的版本信息
     */
    static const char* GetApiVersion();

    /**
     * 设置日志路径和日志级别，只需调用一次，在调用CreateTraderApi之前调用
     * 
     * @param log_path      日志文件存放目录，默认相对可执行程序所在的目录
     *                      路径包含中文，Windows上使用GBK，Linux上使用UTF8
     * @param log_level     日志级别，默认为LogLevel_Info
     */
    static void SetLogConfig(const char* log_path, LogLevel log_level = LogLevel_Info);

    /**
     * 是否开启业务消息的日志，默认开启，只需调用一次，在调用CreateTraderApi之前调用
     *
     * @param enable        是否开启业务消息的日志
     */
    static void SetCriticalMsgLog(bool enable);

    /**
     * 设置首次登录失败后，自动登录重试次数，默认5次，设置为0会一直重试，
     * 只需调用一次，在调用CreateTraderApi之前调用，所有API共用这个设置
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
    virtual void RegisterSpi(TraderSpi* spi) = 0;

    /**
     * 发起用户登录请求
     *
     * @param svr_ip        交易服务器ip地址
     * @param svr_port      交易服务器端口
     * @param account       接入方交易账户相关信息
     * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档，必须UTF8编码
     * 
     * @return              0表示发起登录请求成功，非0表示发起登录请求失败，通过GetApiLastError获取错误信息
     */
    virtual int Login(const char* svr_ip, int svr_port, const AccountInfo* account_info,
                      const char* terminal_info) = 0;

    /**
     * 获取资金账号绑定的柜台类型，登陆成功后可获取
     * 
     * @return              返回柜台类型，请参考CounterType定义
     *						正常返回值在1~99之间，包含1和99，其他值为异常。
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
	* 获取同一客户号下的所有股东账号信息，包含不同资金账号下的，登陆成功后可获取
	*
	* @param secuids       指向股东账号数组的指针，需调用方分配数组内存
	* @param count         股东账号数组大小，count会返回实际的数组大小
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int GetAllSecuidInfo(SecuidInfo* secuids, int* count) = 0;

    /**
     * 获取接口连接网关时本地地址，登录成功后可获取
     * 内网连接时获取的是内网地址，外网连接时是外网地址
     *
     * @param localAddr     接口连接网关时本地地址
     */
    virtual int GetApiLocalAddr(IpAddr* localAddr) = 0;

    /**
     * 股票、场内基金、质押式回购下单、新股申购、ETF申购赎回
     *
     * @param order         传入下单请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int Order(OrderReq* order, int request_id) = 0;

    /**
     * 股票、场内基金、质押式回购下单、新股申购、ETF申购赎回，最大支持500个
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
    virtual int BatchCancelOrder(CancelReq* cancels, int count, int request_id) = 0;

	/**
	* 一键撤单，仅支持低延迟两融
 	* 客户号为必填参数
	* 如果按客户号撤单，    股东代码填空、标的代码填空、市场填0
 	* 如果按市场撤单，		股东代码填支持的股东代码，标的代码填空，市场填股东所在市场
 	* 如果按标的撤单，		股东代码填标的代码对应的股东代码，市场填证券代码所在市场
	*
	* @param cancels       传入撤单请求对象
	* @param count         传入撤单请求对象
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @return              成功返回0，失败返回错误码，错误码定义在error.h文件
	*/
	virtual int BatchCancelAllOrder(BatchCancelAllReq* cancels, int request_id) = 0;

    /**
     * 查询当日单个订单详情
     *
     * @param qry_req       根据柜台委托号查询的请求数据
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
     *
     * @param qry_req       根据定位串查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryOrders(QryOrdersReq* qry_req, int request_id) = 0;

    /**
     * 查询当日单个订单成交列表
     * @param order_id      根据柜台委托号查询的请求数据 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTradeByOrderId(QryByOrderIdReq* qry_req, int request_id) = 0;

    /**
     * 查当日指定标的成交列表
     *
     * @param qry_req       根据当日指定标的查询成交列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTradeByCode(QryTradeByCodeReq* qry_req, int request_id) = 0;

    /**
     * 查询当日成交列表，支持定位串增量查询
     * 
     * @param qry_req				查询当日成交列表的请求数据
     * @param request_id			请求序列号，用于匹配响应，由用户自定义，非0
     * @return						成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTrades(QryTradesReq* qry_req, int request_id) = 0;

    /**
     * 查询当日ETF申赎及成分股成交列表，支持定位串增量查询，仅君睿柜台需要
     * 
     * @param qry_req       查询当日ETF申赎及成分股成交列表的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryETFTrades(QryETFTradesReq* qry_req, int request_id) = 0;

    /**
     * 查当日指定标的持仓
     *
     * @param qry_req       根据标的查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPosition(QryByCodeReq* qry_req, int request_id) = 0;

    /**
     * 查询当日账户持仓列表，支持定位串增量查询
     *
     * @param qry_req       根据定位串查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPositions(QryPositionsReq* qry_req, int request_id) = 0;

    /**
     * 查询当日账户资金详情
     * 
     * @param qry_req       查询资金请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCash(QryCashReq* qry_req, int request_id) = 0;

    /**
     * 查集中交易系统可用资金
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryJZJYAvailFund(int request_id) = 0;

    /**
     * 针对同一个资金账号在集中交易柜台与快速柜台之间资金转入转出
     * 仅支持极速柜台，大集中柜台使用银证转账
     * @param trans_req         资金划转请求
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int TransferFundInAndOut(TransferFundReq* trans_req, int request_id) = 0;

    /**
     * 针对同一个资金账号，一户两地之间资金划转，仅君睿柜台支持
     * 
     * @param trans_req         资金划转请求
     * @param request_id        请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return                  成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int TransferFundBetweenSecuid(TransferFundSecuidReq* trans_req, int request_id) = 0;

    /**
     * 查询ETF基本信息列表，只返回可申赎的ETF列表
     * 
     * @param qry_req       查询请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryETFs(QryETFsReq* qry_req, int request_id) = 0;

    /**
     * 查询一个ETF股票篮子信息
     * 
     * @param qry_req       查询请求数据，symbol填ETF的一级市场代码，格式为市场.证券ID
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryETFStocks(QryETFStocksReq* qry_req, int request_id) = 0;

    /**
     * 查询最大可委托数量
     *
     * @param qry_req       最大可委托数量查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryMaxOrderQty(QryMaxOrderQtyReq* qry_req, int request_id) = 0;

    /**
     * 查询新股可申购额度
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryIPOMaxPurchase(int request_id) = 0;

    /**
     * 查询新股新债
     * 
	 * @param qry_req       新股新债查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryIPOStock(QueryIPOStockReq* qry_req, int request_id) = 0;

    /**
     * 查询单个证券信息，仅君睿柜台支持
     *
     * @param qry_req       查询请求数据，symbol填市场.证券ID或市场.合约ID，必填
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QuerySecurityBaseInfo(QryByCodeReq* qry_req, int request_id) = 0;

    /**
     * 担保品转入转出
     * 
     * @param req           担保品划转请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CreditMortgageInOut(CreditMortgageInOutReq* req, int request_id) = 0;

    /**
     * 现券还券
     * 
     * @param req           现券还券请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CreditStockBack(CreditStockBackReq* req, int request_id) = 0;

    /**
     * 直接还款
     * 
     * @param credit_req    直接还款请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int CreditPayBack(CreditPayBackReq* credit_req, int request_id) = 0;

    /**
     * 指定合约直接还款
     *
     * @param sno           合约编号
     * @param order_date    合约发生日期
     * @param back_amt      合约还款金额，扩大一万倍，精度0.01
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0, 必传
	 * @param cl_order_id   客户端订单id，用来引用一个普通订单，由用户自定义，可不传
	 * @param credit_type   信用交易类型，枚举见CreditType，必传
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int CreditPayBackByOrder(CreditPayBackByOrderReq* req, int request_id) = 0;

    /**
     * 查询信用标的券，支持定位串增量查询
     *
     * @param pos_str       查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
     * @param query_num     查询的数量
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryCreditStock(QryCreditStockReq* req, int request_id) = 0;

    /**
     * 查询担保品券，支持定位串增量查询
     *
     * @param pos_str       查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
     * @param query_num     查询的数量
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryCreditMortgageHold(QryCreditMortgageHoldReq* req, int request_id) = 0;

    /**
     * 查询信用资产
     * 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditAssets(int request_id) = 0;

    /**
     * 查询信用融资合约，支持定位串增量查询
     *
     * @param pos_str       查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
     * @param query_num     查询的数量
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryCreditFinance(QryCreditFinanceReq* req, int request_id) = 0;

    /**
     * 查询信用融券合约，支持定位串增量查询
     *
     * @param pos_str       查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
     * @param query_num     查询的数量
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryCreditShortsell(QryCreditShortsellReq* req, int request_id) = 0;

    /**
     * 查询信用融资负债金额
     * 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditRepayAmount(int request_id) = 0;

    /**
     * 查询可还融券负债数量
     *
     * @param qry_req       查询可还融券负债数量的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditRepayStock(QryCreditRepayStockReq* qry_req, int request_id) = 0;

    /**
     * 查询可融券卖出数量，即查询锁券的证券总数量和可用数量
     *
     * @param qry_req       查询可融券卖出数量的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditSecuritySellQty(QryCreditSecuritySellQtyReq* qry_req,
                                           int request_id) = 0;

    /**
     * 查询账户交易权限
     *
     * @param market        市场，如"SZ SH"
     * @param secuid_right  权限类型，如创业板，参考SecuidRight定义
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QuerySecuidRight(QrySecuidRightReq* req, int request_id) = 0;

    // 沪港通、深港通特有接口
    /**
     * 查询沪港通参考汇率
     *
     * @param market        市场，深港通传SZHK，沪港通传SHHK，大小写不敏感
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryHKRate(QryByMarketReq* req, int request_id) = 0;

    /**
     * 查询沪港通标的券
     *
     * @param market        市场，深港通传SZHK，沪港通传SHHK，大小写不敏感
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHKStock(QryHKStock* qry_req, int request_id) = 0;

    /**
     * 查询沪港通辅资金表资产
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHKFund(int request_id) = 0;

    /**
     * 查询沪港通最小价差
     *
     * @param market        市场，深港通传SZHK，沪港通传SHHK，大小写不敏感
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHKMinPriceUnit(QryHKMinPriceUnitReq* req, int request_id) = 0;

    /**
     * 查询沪港通交易日历，查询结果包括起始日期
     *
     * @param start_date    开始日期，如20190415
     * @param end_date      结束日期，如20190418
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
	virtual int QueryHKTradeCalendar(QryByDateReq* req, int request_id) = 0;

    /**
     * 查询锁券明细信息请求
     *
     * @param qry_req       查询请求数据 
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockSecurityDetail(QryLockSecurityReq* qry_req, int request_id) = 0;

    /**
     * 锁券展期申请
     *
     * @param req           锁券展期请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int ExtendLockSecurity(ExtendLockSecurityReq* req, int request_id) = 0;

    /**
     * 查询锁券展期申请请求
     *
     * @param req           查询请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockSecurityExtension(QryLockSecurityExtensionReq* req, int request_id) = 0;

    /**
     * 查询极速柜台与集中交易之间的资金划转流水，
     * 仅支持顶点现货
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTransferFundHistory(int request_id) = 0;

    /**
	* 查询当日负债流水，仅支持低延迟两融
	*
	* @param req       	   请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryCreditDebtsFlow(QryCreditDebtsFlowReq* req, int request_id) = 0;
    
    /**
    * 查询当日资金流水，仅支持低延迟两融
    *
	* @param req       	   请求数据
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
	virtual int QueryCreditAssetFlow(QryCreditAssetFlowReq* req, int request_id) = 0;

    /**
	* 查询信用客户融资融券合约请求
	*
	* @param req       请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
    virtual int QueryCreditDebts(QueryCreditDebtsReq* req, int request_id) = 0;

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
     * 查询银行账户余额请求
     * 
     * @param req           查银行账户余额请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryBankBalance(BankBalanceReq* req, int request_id) = 0;

    /**
     * 查询三方存管银行列表请求
     *
     * @param req           查询三方存管银行列表请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryBankInfo(QueryBankInfoReq* req, int request_id) = 0;

    /**
     * 银证转账请求
     * 
     * @param req           银证转账请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int BankSecTransfer(BankSecTransferReq* req, int request_id) = 0;

    /**
     * 查询当日银证转账请求
     * 
     * @param req           银证转账查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryBankSecTransfer(QryBankSecTransferReq* req, int request_id) = 0;

    /**
     * 查询银证转账历史请求
     * 
     * @param req           查询银证转账历史
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHisBankSecTransfer(QryHisBankSecTransferReq* req, int request_id) = 0;

    /**
     * 主辅资金账号之间可用资金划转
     * 
     * @param req           可用资金划转请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int FundAccountTransfer(FundAccountTransferReq* req, int request_id) = 0;

    /**
     * 查询当日主辅资金账号之间资金划转
     * 
     * @param req           查询主辅资金账号之间资金划转请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryFundAccountTransfer(QryFundAccountTransferReq* req, int request_id) = 0;

    /**
     * 查询历史委托列表
     * 
     * @param req           查询历史委托请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHisOrders(QryHisOrderReq* req, int request_id) = 0;

    /**
     * 查询历史成交列表
     * 
     * @param req           查询历史成交请求对象
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryHisTrades(QryHisTradeReq* req, int request_id) = 0;

    /**
     * 查询交割单请求--微服务简化版
     * 
     * @param req           查询交割单请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryDeliveryOrders(QryDeliveryOrderReq* req, int request_id) = 0;

    /**
     * 查询对账单请求--微服务简化版
     * 
     * @param req           对账单查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * 
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryStateOrders(QryStateOrderReq* req, int request_id) = 0;

	/**
	* 查询交割单(分笔)请求--集中交易详细版，新增支持集中清算，功能号改变，接口不变
    *   老功能号900086，新功能号910062
	*
	* @param req           查询交割单请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryExchangeLists(QueryExchangeListsReq* req, int request_id) = 0;

    /**
     * 修改密码请求
     *
     * @param req           修改密码请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int ModifyPassword(ModifyPasswordReq* req, int request_id) = 0;

    /**
	* 查询新股配号请求 (微服务新增)
	*
	* @param req           查询新股配号请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
    virtual int QueryPHXX(QueryPHXXReq* req, int request_id) = 0;

    /**
	* 查询新股中签请求 (微服务新增)
	*
	* @param req           查询新股中签请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
    virtual int QueryZQXX(QueryZQXXReq* req, int request_id) = 0;

    /**
     * 查询锁券合同请求
     *
     * @param req           查询锁券合同请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryLockSecurityContract(QryLockSecurityContractReq* req, int request_id) = 0;

    /**
     * 查询信用合同请求
     *
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditContract(int request_id) = 0;

    /**
     * 查询融资融券合约汇总信息请求
     *
     * @param req           查询融资融券合约汇总信息请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditDebtsCollect(QryCreditDebtsCollectReq* req, int request_id) = 0;

    /**
     * 查询融资融券信用数据请求
     *
     * @param req           查询融资融券信用数据请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditData(QryCreditDataReq* req, int request_id) = 0;

    /**
     * 查询信用预到期合约请求
     *
     * @param req           查询信用预到期合约请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPreMaturityDebts(QryPreMaturityDebtsReq* req, int request_id) = 0;

    /**
     * 信用预到期合约展期请求
     *
     * @param req           信用预到期合约展期请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int ExtendPreMaturityDebts(ExtendPreMaturityDebtsReq* req, int request_id) = 0;

    /**
     * 查询信用预到期合约展期请求
     *
     * @param req           查询信用预到期合约展期请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPreMaturityDebtsExtension(QryPreMaturityDebtsExtensionReq* req,
                                               int request_id) = 0;

    /**
     * 查询网络投票议案请求
     *
     * @param req           查询网络投票议案请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryVoteProposal(QryVoteProposalReq* req, int request_id) = 0;

    /**
     * 查询信用投票可投票数请求
     *
     * @param req           查询可投票数请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditVoteCount(QryCreditVoteCountReq* req, int request_id) = 0;

    /**
     * 查询信用投票结果请求
     *
     * @param req           查询信用投票结果请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryCreditVote(QryCreditVoteReq* req, int request_id) = 0;

    /**
     * 查询网络投票客户权益请求
     *
     * @param req           网络投票客户权益查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryNetVoteRights(QryNetVoteRightsReq* req, int request_id) = 0;

    /**
     * 查询网络投票结果请求
     *
     * @param req           网络投票结果查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryNetVoteResult(QryNetVoteResultReq* req, int request_id) = 0;

    /**
     * 查询网络投票可投票数量请求
     *
     * @param req           网络投票可投票数量查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryNetVoteCount(QryNetVoteCountReq* req, int request_id) = 0;

    /**
    * 指定合约卖券还款-通过通用普通委托应答确认
    *
    * @param req           卖券还款的请求参数构造
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int AppointContractSellStockRepay(AppointContractSellStockRepayReq* req,
                                              int request_id) = 0;

	/**
	* 股票集中度查询
	*
	* @param req           股票集中度查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryStkConcentration(StkConcentrationReq* req, int request_id) = 0;

    /**
    * 查询沪港通历史委托明细
    *
    * @param req           查询历史委托请求对象
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryHKHisOrders(QryHKHisOrderReq* req, int request_id) = 0;

    /**
    * 查询可取资金请求
    *
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param market        市场，君睿柜台一户两地时使用，查对应市场的可取资金，
    *                      传SH或SZ是查上海或深圳的可取资金，大小写不敏感，默认查两地汇总的可取资金
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
	virtual int QueryWithdrawCash(QueryWithdrawCashReq* req, int request_id) = 0;

	/**
	* 查询当日委托表中的汇总成交信息，支持定位串增量查询
	*
	* @param pos_str       根据定位串查询的请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryTradeListTotal(QryTradeListTotalReq* qry_req, int request_id) = 0;

	/**
	* ETF 认购撤单请求
	*
	* @param req           ETF认购撤单请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int ETFSubscriptCancel(ETFSubscriptCancelReq* req, int request_id) = 0;

    /**
    * 查询网络投票委托请求
    *
    * @param req           网络投票委托查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryNetVoteOrder(QryNetVoteOrderReq* req, int request_id) = 0;
	
	/**
	* 网络投票委托请求，新增微服务接口
	*
	* @param req           网络投票委托请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int NetVoteOrder(NetVoteOrderReq* req, int request_id, const char* terminal_info) = 0;

	/**
	* 信用投票委托请求，新增微服务接口
	*
	* @param req           信用投票委托请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int CreditNetVoteOrder(CreditNetVoteOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
       * 客户资金查询请求
       *
       * 使用场景：           查询账户清算后的期初资金，主要用于外围系统清算后核对、调平。
       * @param req           客户资金查询请求，微服务渠道
       * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
       * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
       */
       virtual int QueryMSCash(QueryMSCashReq* req, int request_id) = 0;

    /**
       * 客户持仓查询请求
       *
       * 使用场景：           查询账户清算后的期初持仓，主要用于外围系统清算后核对、调平。
       * @param req           客户持仓查询请求，微服务渠道
       * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
       * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
       */
       virtual int QueryMSPositions(QueryMSPositionsReq* req, int request_id) = 0;

    /**
       * 信用负债流水查询请求，微服务渠道
       *
       * 使用场景：           查询账户清算后的信用负债流水，主要用于外围系统清算后核对、调平。
       * @param req           信用负债流水查询请求，微服务渠道
       * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
       * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
       */
       virtual int QueryMSCreditDebtsFlow(QueryMSCreditDebtsFlowReq* req, int request_id) = 0;
	


   protected:
    virtual ~TraderApi(){};
};

}  // namespace HFT

#endif  // _HFT_TRADER_API_H_
