//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnhft.h"
#include "pybind11/pybind11.h"
#include "hft/hft_trader_api.h"


using namespace pybind11;
using namespace HFT;



///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public TraderSpi
{
private:
	TraderApi* api;            //API对象
    bool active = false;       //工作状态

public:
    TdApi()
    {
    };

    ~TdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API回调函数
    //-------------------------------------------------------------------------------------

    /**
     * 连接断开时回调
     */
    virtual void OnDisconnect();

    /**
     * 错误消息回调，系统出错时才会回调
     *
     * @param error_info    错误信息
     * @param request_id    对应请求时传入的序列号，如果不是请求触发的错误，此字段值为0
     */
    virtual void OnError(ErrorInfo* error_info, int request_id = 0);

    /**
     * 风控告警信息通知回调
     *
     * @param risk_notify   风控告警信息
     */
    virtual void OnRiskNotify(RiskNotify* risk_notify);

    /**
    * 回切通知信息回调
    *
    * @param failback_notify   回切通知信息
    */
    virtual void OnFailBackNotify(FailBackNotify* failback_notify);

    /**
     * 登录成功或失败时回调
     *
     * @param rsp           登录应答数据，包含客户号、客户姓名、股东代码等信息
     * @param error_info    错误信息
     */
    virtual void OnLogin(LoginRsp* rsp, ErrorInfo* error_info);

    /**
     * 成交回报回调
     *
     * @param trade_detail  回调的成交详情对象
     */
    virtual void OnTradeReport(TradeDetail* trade_detail);

    /**
     * 订单状态变化回调  	注意，集中交易柜台不支持此回调通知
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnOrderStatus(OrderDetail* order_detail);

    /**
     * 订单委托的响应
     * Order、BatchOrder均由此接口响应
     *
     * @param order_rsp     订单委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * 撤单的响应
     *
     * @param cancel_rsp    撤单应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info, int request_id,
        bool is_last);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询当日资金的响应
     *
     * @param cash_detail   资金详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCashRsp(CashDetail* cash_detail, ErrorInfo* error_info, int request_id);

    /**
     * 查集中交易系统可用资金
     *
     * @param avail_balance 可用资金，单位：人民币
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance, ErrorInfo* error_info,
        int request_id);

    /**
     * 集中交易柜台与快速柜台之间资金转入转出
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundInAndOutRsp(int64_t transfer_value, ErrorInfo* error_info,
        int request_id);

    /**
     * 针对同一个资金账号，一户两地之间资金划转
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundBetweenSecuidRsp(int64_t transfer_value, ErrorInfo* error_info,
        int request_id);

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
        bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询最大可委托数量回调
     *
     * @param detail        最大可委托数量数据
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryMaxOrderQtyRsp(MaxOrderQtyDetail* detail, ErrorInfo* error_info,
        int request_id);

    /**
     * 查询新股可申购额度的响应
     *
     * @param detail        新股可申购额度数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryIPOMaxPurchaseRsp(IPOMaxPurchaseDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        bool is_last, const char* pos_str);

    /**
     * 查询证券信息的响应
     *
     * @param detail            证券信息
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     * @param is_last           是否是本次请求的最后一笔响应
     */
    virtual void OnQuerySecurityBaseInfoRsp(SecurityBaseInfo* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * 担保品转入转出应答回调
     *
     * @param rsp           担保品转入转出应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditMortgageInOutRsp(CreditMortgageInOutRsp* rsp, ErrorInfo* error_info,
        int request_id);

    /**
     * 现券还券应答回调
     *
     * @param rsp           现券还券应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditStockBackRsp(CreditStockBackRsp* rsp, ErrorInfo* error_info,
        int request_id);

    /**
     * 直接还款应答回调
     *
     * @param rsp           直接还款应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCreditPayBackRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info, int request_id);

    /**
     * 指定合约直接还款
     *
     * @param rsp           还款信息
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnCreditPayBackByOrderRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        const char* pos_str);

    /**
     * 信用资产查询应答回调
     *
     * @param detail        信用资产数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCreditAssetsRsp(CreditAssetsDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询可还融资负债金额应答回调
     *
     * @param detail        可还金额数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCreditRepayAmountRsp(CreditRepayAmountDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

    /**
     * 查询账户交易权限回调
     *
     * @param rsp           查询交易权限应答
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQuerySecuidRightRsp(QrySecuidRightRsp* rsp, ErrorInfo* error_info,
        int request_id);

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
        bool is_last);

    /**
     * 查询沪港通标的券的响应
     *
     * @param detail        沪港通标的券数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKStockRsp(HKStockDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * 查询沪港通辅资金表资产的响应
     *
     * @param detail        沪港通辅资金表资产数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryHKFundRsp(HKFundDetail* detail, ErrorInfo* error_info, int request_id);

    /**
     * 查询沪港通最小价差的响应
     *
     * @param detail        沪港通最小价差数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKMinPriceUnitRsp(HKMinPriceUnitDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询沪港通交易日历的响应
     *
     * @param detail        沪港通交易日历数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryHKTradeCalendarRsp(HKTradeCalendarDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询资金划转流水的响应
     *
     * @param detail        资金划转明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryTransferFundHistoryRsp(TransferFundDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 微服务应答
     *
     * @param rsp           微服务应答数据
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id);

    /**
     * 查询银行账号余额应答回调
     *
     * @param detail        银行余额明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryBankBalanceRsp(BankBalanceDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        bool is_last);

    /**
     * 银证转账应答回调
     *
     * @param rsp           银证转账应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnBankSecTransferRsp(BankSecTransferRsp* rsp, ErrorInfo* error_info,
        int request_id);

    /**
     * 查询当日银证转账数据回调
     *
     * @param rsp           当日银证转账数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryBankSecTransferRsp(BankSecTransferDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        const char* pos_str);

    /**
     * 可用资金划转应答回调
     *
     * @param detail        可用资金划转应答明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnFundAccountTransferRsp(FundAccountTransferRsp* detail, ErrorInfo* error_info,
        int request_id);

    /**
     * 查询当日主辅资金账号之间资金划转应答回调
     *
     * @param detail        主辅资金划转明细数据
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryFundAccountTransferRsp(FundAccountTransferDetail* detail,
        ErrorInfo* error_info, int request_id);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 修改密码的响应
     *
     * @param rsp           修改密码应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnModifyPasswordRsp(ModifyPasswordRsp* rsp, ErrorInfo* error_info,
        int request_id);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        const char* pos_str);

    /**
     * 查询信用合同应答
     *
     * @param detail        信用合同详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditContractRsp(CreditContractDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        const char* pos_str);

    /**
     * 查询融资融券信用数据应答
     *
     * @param detail        融资融券信用数据详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditDataRsp(CreditDataDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 信用预到期合约展期应答
     *
     * @param detail        信用预到期合约展期应答
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnExtendPreMaturityDebtsRsp(ExtendPreMaturityDebtsRsp* detail,
        ErrorInfo* error_info, int request_id);

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
        bool is_last, const char* pos_str);

    /**
     * 查询网络投票议案应答
     *
     * @param rsp           网络投票议案详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryVoteProposalRsp(VoteProposalDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * 查询信用投票可投票数应答
     *
     * @param detail        信用投票可投票数
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryCreditVoteCountRsp(CreditVoteCountDetail* detail, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    /**
     * 查询网络投票可投票数量应答
     *
     * @param detail        网络投票可投票数量明细
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryNetVoteCountRsp(NetVoteCountDetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        int request_id, bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

    /**
    * 查询可取资金的响应
    *
    * @param detail        可取资金详情
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQueryWithdrawCashRsp(WithdrawCashRecord* detail, ErrorInfo* error_info, int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

    /**
    * ETF 认购 撤单的应答
    *
    * @param order_rsp     ETF 认购 撤单的应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnETFSubscriptCancelRsp(ETFSubscriptCancelRsp* order_rsp, ErrorInfo* error_info,
        int request_id);

    /**
    * 网络投票委托的响应
    *
    * @param order_rsp     网络投票委托应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnNetVoteOrderRsp(NetVoteOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id);

    /**
    * 信用投票委托的响应
    *
    * @param order_rsp     信用投票委托应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnCreditNetVoteOrderRsp(CreditNetVoteOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

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
        int request_id, bool is_last, const char* pos_str);

    //-------------------------------------------------------------------------------------
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------

    virtual void onDisconnect() {};

    virtual void onError(const dict& error, int request_id) {};

    virtual void onRiskNotify(const dict& data) {};

    virtual void onFailBackNotify(const dict& data) {};

    virtual void onLogin(const dict& data, const dict& error) {};

    virtual void onTradeReport(const dict& data) {};

    virtual void onOrderStatus(const dict& data) {};

    virtual void onOrderRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onCancelRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryTradeRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryPositionRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCashRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict& error, int request_id) {};

    virtual void onTransferFundInAndOutRsp(int64_t transfer_value, const dict& error, int request_id) {};

    virtual void onTransferFundBetweenSecuidRsp(int64_t transfer_value, const dict& error, int request_id) {};

    virtual void onQueryETFRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryETFStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryMaxOrderQtyRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryIPOMaxPurchaseRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryIPOStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQuerySecurityBaseInfoRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onCreditMortgageInOutRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCreditStockBackRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCreditPayBackRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCreditPayBackByOrderRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCreditStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditMortgageHoldRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditAssetsRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCreditFinanceRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditShortsellRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditRepayAmountRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCreditRepayStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditSecuritySellQtyRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQuerySecuidRightRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryHKRateRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryHKStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryHKFundRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryHKMinPriceUnitRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryHKTradeCalendarRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryLockSecurityDetailRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryTransferFundHistoryRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryCreditDebtsFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditAssetFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditDebtsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onMicroServiceRsp(const dict& data, int request_id) {};

    virtual void onQueryBankBalanceRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryBankInfoRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onBankSecTransferRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryBankSecTransferRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryHisBankSecTransferRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onFundAccountTransferRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryFundAccountTransferRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryHisOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryHisTradeRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryDeliveryOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryStateOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryExchangeListsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onModifyPasswordRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryPHXXRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryZQXXRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryLockSecurityContractRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditContractRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCreditDebtsCollectRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCreditDataRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryPreMaturityDebtsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onExtendPreMaturityDebtsRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryPreMaturityDebtsExtensionRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryVoteProposalRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryCreditVoteCountRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCreditVoteRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryNetVoteRightsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryNetVoteResultRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryNetVoteCountRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryStkConcentrationRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryHKHisOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryWithdrawCashRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryNetVoteOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryTradeTotalRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onETFSubscriptCancelRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onNetVoteOrderRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCreditNetVoteOrderRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryMSCashRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryMSPositionsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryMSCreditDebtsFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------
	void setLogConfig(string log_path);

    void createTraderApi();

    void release();

    int exit();

    string getApiVersion();

	void setCriticalMsgLog(bool enable);

	void setLoginRetryCount(int login_retry_count);

	void setLoginRetryInterval(int login_retry_interval);

	void setReconnectConfig(int max_retry_count, int min_interval, int max_interval);

    dict getApiLastError();

    int login(const dict& req);

    int getCounterType();

    pybind11::list getSecuidInfo();

    pybind11::list getAllSecuidInfo();

    int getApiLocalAddr(const dict& req);

    int order(const dict& req, int request_id);

    int batchOrder(const dict& req, int count, int request_id);

    int cancelOrder(const dict& req, int request_id);

    int batchCancelOrder(const dict& req, int count, int request_id);

    int batchCancelAllOrder(const dict& req, int request_id);

    int queryOrder(const dict& req, int request_id);

    int queryOrderByCode(const dict& req, int request_id);

    int queryOrders(const dict& req, int request_id);

    int queryTradeByOrderId(const dict& req, int request_id);

    int queryTradeByCode(const dict& req, int request_id);

    int queryTrades(const dict& req, int request_id);

    int queryETFTrades(const dict& req, int request_id);

    int queryPosition(const dict& req, int request_id);

    int queryPositions(const dict& req, int request_id);

    int queryCash(const dict& req, int request_id);

    int queryJZJYAvailFund(int request_id);

    int transferFundInAndOut(const dict& req, int request_id);

    int transferFundBetweenSecuid(const dict& req, int request_id);

    int queryETFs(const dict& req, int request_id);

    int queryETFStocks(const dict& req, int request_id);

    int queryMaxOrderQty(const dict& req, int request_id);

    int queryIPOMaxPurchase(int request_id);

    int queryIPOStock(const dict& req, int request_id);

    int querySecurityBaseInfo(const dict& req, int request_id);

    int creditMortgageInOut(const dict& req, int request_id);

    int creditStockBack(const dict& req, int request_id);

    int creditPayBack(const dict& req, int request_id);

    int creditPayBackByOrder(const dict& req, int request_id);

    int queryCreditStock(const dict& req, int request_id);

    int queryCreditMortgageHold(const dict& req, int request_id);

    int queryCreditAssets(int request_id);

    int queryCreditFinance(const dict& req, int request_id);

    int queryCreditShortsell(const dict& req, int request_id);

    int queryCreditRepayAmount(int request_id);

    int queryCreditRepayStock(const dict& req, int request_id);

    int queryCreditSecuritySellQty(const dict& req, int request_id);

    int querySecuidRight(const dict& req, int request_id);

    int queryHKRate(const dict& req, int request_id);

    int queryHKStock(const dict& req, int request_id);

    int queryHKFund(int request_id);

    int queryHKMinPriceUnit(const dict& req, int request_id);

    int queryHKTradeCalendar(const dict& req, int request_id);

    int queryLockSecurityDetail(const dict& req, int request_id);

    int queryTransferFundHistory(int request_id);

    int queryCreditDebtsFlow(const dict& req, int request_id);

    int queryCreditAssetFlow(const dict& req, int request_id);

    int queryCreditDebts(const dict& req, int request_id);

    int doMicroServiceReq(const dict& req, int request_id);

    int queryBankBalance(const dict& req, int request_id);

    int queryBankInfo(const dict& req, int request_id);

    int bankSecTransfer(const dict& req, int request_id);

    int queryBankSecTransfer(const dict& req, int request_id);

    int queryHisBankSecTransfer(const dict& req, int request_id);

    int fundAccountTransfer(const dict& req, int request_id);

    int queryFundAccountTransfer(const dict& req, int request_id);

    int queryHisOrders(const dict& req, int request_id);

    int queryHisTrades(const dict& req, int request_id);

    int queryDeliveryOrders(const dict& req, int request_id);

    int queryStateOrders(const dict& req, int request_id);

    int queryExchangeLists(const dict& req, int request_id);

    int modifyPassword(const dict& req, int request_id);

    int queryPHXX(const dict& req, int request_id);

    int queryZQXX(const dict& req, int request_id);

    int queryLockSecurityContract(const dict& req, int request_id);

    int queryCreditContract(int request_id);

    int queryCreditDebtsCollect(const dict& req, int request_id);

    int queryCreditData(const dict& req, int request_id);

    int queryPreMaturityDebts(const dict& req, int request_id);

    int extendPreMaturityDebts(const dict& req, int request_id);

    int queryPreMaturityDebtsExtension(const dict& req, int request_id);

    int queryVoteProposal(const dict& req, int request_id);

    int queryCreditVoteCount(const dict& req, int request_id);

    int queryCreditVote(const dict& req, int request_id);

    int queryNetVoteRights(const dict& req, int request_id);

    int queryNetVoteResult(const dict& req, int request_id);

    int queryNetVoteCount(const dict& req, int request_id);

    int queryStkConcentration(const dict& req, int request_id);

    int queryHKHisOrders(const dict& req, int request_id);

    int queryWithdrawCash(const dict& req, int request_id);

    int queryTradeListTotal(const dict& req, int request_id);

    int eTFSubscriptCancel(const dict& req, int request_id);

    int queryNetVoteOrder(const dict& req, int request_id);

    int netVoteOrder(const dict& req, int request_id, string terminal_info);

    int creditNetVoteOrder(const dict& req, int request_id, string terminal_info);

    int queryMSCash(const dict& req, int request_id);

    int queryMSPositions(const dict& req, int request_id);

    int queryMSCreditDebtsFlow(const dict& req, int request_id);
};
