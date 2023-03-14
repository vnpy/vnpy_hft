//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnhft.h"
#include "pybind11/pybind11.h"
#include "hft/hft_option_trader_api.h"


using namespace pybind11;
using namespace HFT;



///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class OptionApi : public OptionTraderSpi
{
private:
    OptionTraderApi* api;           //API对象
    bool active = false;            //工作状态

public:
    OptionApi()
    {
    };

    ~OptionApi()
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
     * 订单状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnOrderStatus(OrderDetail* order_detail);

    /**
     * 订单委托应答回调
     *
     * @param order_rsp     订单委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * 撤单应答回调
     *
     * @param cancel_rsp    撤单应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last);

    /**
     * 查询当日资金的响应
     *
     * @param cash_detail   资金详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnQueryCashRsp(OptionCashDetail* cash_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * 查集中交易系统可用资金
     *
     * @param avail_balance 可用资金，单位：人民币
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     */
    virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance,
        ErrorInfo* error_info,
        int request_id);

    /**
     * 集中交易柜台与快速柜台之间资金转入转出
     *
     * @param transfer_value    划转金额
     * @param error_info        应答的错误信息
     * @param request_id        请求序列号，用于匹配响应，由用户自定义
     */
    virtual void OnTransferFundInAndOutRsp(int64_t transfer_value,
        ErrorInfo* error_info,
        int request_id);

    /**
     * 行权响应
     *
     * @param exercise_rsp  行权响应详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnExerciseRsp(ExerciseRsp* exercise_rsp, ErrorInfo* error_info,
        int request_id);

    /**
     * 撤销行权响应
     *
     * @param cancel_rsp    撤销行权响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCancelExerciseRsp(CancelExerciseRsp* cancel_rsp,
        ErrorInfo* error_info, int request_id);

    /**
     * 行权状态推送
     *
     * @param exercise      行权委托详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnExerciseStatus(ExerciseDetail* exercise);

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
        bool is_last, const char* pos_str);

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
        bool is_last);

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
        int request_id, bool is_last);

    /**
     * 现货持仓划转状态推送
     *
     * @param transfer_detail   现货持仓划转详情
     */
    virtual void OnTransferStockStatus(TransferStockDetail* transfer_detail);

    /**
     * 现货持仓划转响应
     *
     * @param transfer_rsp  现货持仓划转响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnTransferStockRsp(TransferStockRsp* transfer_rsp,
        ErrorInfo* error_info, int request_id);

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
        int request_id);

    /**
     * 锁定现货委托状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnLockOrderStatus(LockOrderDetail* order_detail);

    /**
     * 锁定现货委托应答回调
     *
     * @param order_rsp     锁定现货委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnLockOrderRsp(LockOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

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
        bool is_last, const char* pos_str);

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
        bool is_last);

    /**
     * 组合委托状态变化回调
     *
     * @param order_detail  回调的订单对象
     */
    virtual void OnCombOrderStatus(CombOrderDetail* order_detail);

    /**
     * 组合委托应答回调
     *
     * @param order_rsp     组合委托应答
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnCombOrderRsp(CombOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * 组合行权状态推送
     *
     * @param exercise      组合行权委托详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCombExerciseStatus(CombExerciseDetail* exercise);

    /**
     * 组合行权响应
     *
     * @param exercise_rsp  组合行权响应详情
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCombExerciseRsp(CombExerciseRsp* exercise_rsp,
        ErrorInfo* error_info, int request_id);

    /**
     * 撤销组合行权响应
     *
     * @param cancel_rsp    撤销组合行权响应类型
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnCancelCombExerciseRsp(CancelCombExerciseRsp* cancel_rsp,
        ErrorInfo* error_info,
        int request_id);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last);

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
        int request_id, bool is_last);

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
        int request_id, bool is_last);

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
        bool is_last);

    /**
     * 微服务应答
     *
     * @param rsp           微服务应答数据
     * @param request_id    对应请求时传入的序列号
     */
    virtual void OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id);

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
        bool is_last);

    /**
     * 查询投资者限额的响应，一次返回一个限额详情
     * QueryAmountLimits由此接口响应
     *
     * @param limit_detail      限额详情
     * @param error_info        应答的错误信息
     * @param request_id        对应请求时传入的序列号
     */
    virtual void OnQueryAmountLimitsRsp(AmountLimitsDetail* limit_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * 查询拆分组合合约后保证金差额变动响应
     * QuerySplitCombMarginDifference由此接口响应
     *
     * @param margin_diff_detail    拆分组合合约后保证金差额变动详情
     * @param error_info            应答的错误信息
     * @param request_id            对应请求时传入的序列号
     */
    virtual void OnQuerySplitCombMarginDifferenceRsp(SplitCombMarginDiffDetail* margin_diff_detail,
        ErrorInfo* error_info, int request_id);

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
        bool is_last);

    /**
     * 查询股票期权保证金风险度明细响应
     * QueryMarginRisk由此接口响应
     *
     * @param detail                 投资者行权指派明细详情
     * @param error_info             应答的错误信息
     * @param request_id             对应请求时传入的序列号
     */
    virtual void OnQueryMarginRiskRsp(MarginRiskDetail* detail, ErrorInfo* error_info, int request_id);

    /**
     * 查询期权最大可委托数响应
     * QueryOptionMaxOrderVolume由此接口响应
     * @param max_order_detail       期权最大可委托数详情
     * @param error_info             应答的错误信息
     * @param request_id             对应请求时传入的序列号
     */
    virtual void OnQueryOptionMaxOrderVolumeRsp(OptionMaxOrderVolumeDetail* max_order_detail,
        ErrorInfo* error_info, int request_id);

    /**
    * 查询现货系统现货持仓的响应
    * QueryInquiryStockPositions由此接口响应
    *
    * @param position_detail   现货持仓详情
    * @param error_info        应答的错误信息
    * @param request_id        对应请求时传入的序列号
    */
    virtual void OnQueryInquiryStockPositionRsp(PositionDetail* position_detail,
        ErrorInfo* error_info, int request_id);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        bool is_last);

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
        bool is_last, const char* pos_str);

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
        bool is_last, const char* pos_str);

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
        ErrorInfo* error_info, int request_id, bool is_last);

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

    virtual void onQueryPositionRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryCashRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict& error, int request_id) {};

    virtual void onTransferFundInAndOutRsp(int64_t transfer_value, const dict& error, int request_id) {};

    virtual void onExerciseRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCancelExerciseRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onExerciseStatus(const dict& data) {};

    virtual void onQueryExerciseRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryContractInfoRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryStockPositionRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onTransferStockStatus(const dict& data) {};

    virtual void onTransferStockRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryTransferStockRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onLockOrderStatus(const dict& data) {};

    virtual void onLockOrderRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryLockOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryLockPositionRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onCombOrderStatus(const dict& data) {};

    virtual void onCombOrderRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onCombExerciseStatus(const dict& data) {};

    virtual void onCombExerciseRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onCancelCombExerciseRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryCombOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCombExerciseRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryCombPositionRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryCombContractInfoRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryTransferFundHistoryRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryCombPositionSubDetailRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onMicroServiceRsp(const dict& data, int request_id) {};

    virtual void onQueryPositionLimitsRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryAmountLimitsRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQuerySplitCombMarginDifferenceRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryExerciseAppointmentRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryMarginRiskRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryOptionMaxOrderVolumeRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryInquiryStockPositionRsp(const dict& data, const dict& error, int request_id) {};

    virtual void onQueryOptionOrderHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionTradeHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryExerciseAppointmentHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionDeliveryHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryExerciseDeliveryHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionContractAssetHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionDeliveryNettingHistoryRsp(const dict& data, const dict& error, int request_id, bool last) {};

    virtual void onQueryOptionCombPositionHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionSettlementHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) {};

    virtual void onQueryOptionCombStrategyFileRsp(const dict& data, const dict& error, int request_id, bool last) {};

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

    int getApiLocalAddr(const dict& req);

    int order(const dict& req, int request_id);

    int batchOrder(const dict& req, int count, int request_id);

    int cancelOrder(const dict& req, int request_id);

    int batchCancelOrder(const dict& req, int count, int request_id);

    int exercise(const dict& req, int request_id);

    int cancelExercise(const dict& req, int request_id);

    int queryOrder(const dict& req, int request_id);

    int queryOrderByCode(const dict& req, int request_id);

    int queryOrders(const dict& req, int request_id);

    int queryTradeByCode(const dict& req, int request_id);

    int queryTrades(const dict& req, int request_id);

    int queryPosition(const dict& req, int request_id);

    int queryPositions(const dict& req, int request_id);

    int queryCash(const dict& req, int request_id);

    int queryJZJYAvailFund(int request_id);

    int transferFundInAndOut(const dict& req, int request_id);

    int queryExercise(string order_id, int request_id);

    int queryExercises(const dict& req, int request_id);

    int queryContractInfo(int request_id, string symbol);

    int queryStockPositions(int request_id, string symbol);

    int transferStock(const dict& req, int request_id);

    int queryTransferStocks(int request_id, string symbol, int16_t transfer_side);

    int lockOrder(const dict& req, int request_id);

    int queryLockOrder(string symbol, int request_id);

    int queryLockOrders(const dict& req, int request_id);

    int queryLockPositions(int request_id, string symbol);

    int combOrder(const dict& req, int request_id);

    int combExercise(const dict& req, int request_id);

    int cancelCombExercise(const dict& req, int request_id);

    int queryCombOrder(string order_id, int request_id);

    int queryCombOrderByCode(string symbol, int request_id);

    int queryCombOrders(const dict& req, int request_id);

    int queryCombExercise(string order_id, int request_id);

    int queryCombExercises(const dict& req, int request_id);

    int queryCombPositions(int request_id, string symbol, int16_t comb_strategy);

    int queryCombContractInfo(int request_id, string symbol, int comb_strategy);

    int queryTransferFundHistory(int request_id);

    int queryCombPositionSubDetails(int request_id, string symbol, int16_t comb_strategy);

    int doMicroServiceReq(const dict& req, int request_id);

    int queryPositionLimits(int request_id, string symbol);

    int queryAmountLimits(const dict& req, int request_id);

    int querySplitCombMarginDifference(const dict& req, int request_id);

    int queryExerciseAppointment(const dict& req, int request_id);

    int queryMarginRisk(int request_id);

    int queryOptionMaxOrderVolume(const dict& req, int request_id);

    int queryInquiryStockPosition(int request_id, string symbol);

    int queryOptionOrderHistory(const dict& req, int request_id);

    int queryOptionTradeHistory(const dict& req, int request_id);

    int queryExerciseAppointmentHistory(const dict& req, int request_id);

    int queryOptionDeliveryHistory(const dict& req, int request_id);

    int queryExerciseDeliveryHistory(const dict& req, int request_id);

    int queryOptionContractAssetHistory(const dict& req, int request_id);

    int queryOptionDeliveryNettingHistory(const dict& req, int request_id);

    int queryOptionCombPositionHistory(const dict& req, int request_id);

    int queryOptionSettlementHistory(const dict& req, int request_id);

    int queryOptionCombStrategyFile(const dict& req, int request_id);
};
