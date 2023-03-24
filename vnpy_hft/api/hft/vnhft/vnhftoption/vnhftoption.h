//ϵͳ
#ifdef WIN32
#include "pch.h"
#endif

#include "vnhft.h"
#include "pybind11/pybind11.h"
#include "hft/hft_option_trader_api.h"


using namespace pybind11;
using namespace HFT;



///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class OptionApi : public OptionTraderSpi
{
private:
    OptionTraderApi* api;           //API����
    bool active = false;            //����״̬

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
    //API�ص�����
    //-------------------------------------------------------------------------------------

   /**
     * ���ӶϿ�ʱ�ص�
     */
    virtual void OnDisconnect();

    /**
     * ������Ϣ�ص���ϵͳ����ʱ�Ż�ص�
     *
     * @param error_info    ������Ϣ
     * @param request_id    ��Ӧ����ʱ��������кţ�����������󴥷��Ĵ��󣬴��ֶ�ֵΪ0
     */
    virtual void OnError(ErrorInfo* error_info, int request_id = 0);

    /**
     * ��ظ澯��Ϣ֪ͨ�ص�
     *
     * @param risk_notify   ��ظ澯��Ϣ
     */
    virtual void OnRiskNotify(RiskNotify* risk_notify);

    /**
    * ����֪ͨ��Ϣ�ص�
    *
    * @param failback_notify   ����֪ͨ��Ϣ
    */
    virtual void OnFailBackNotify(FailBackNotify* failback_notify);

    /**
     * ��¼�ɹ���ʧ��ʱ�ص�
     *
     * @param rsp           ��¼Ӧ�����ݣ������ͻ��š��ͻ��������ɶ��������Ϣ
     * @param error_info    ������Ϣ
     */
    virtual void OnLogin(LoginRsp* rsp, ErrorInfo* error_info);

    /**
     * �ɽ��ر��ص�
     *
     * @param trade_detail  �ص��ĳɽ��������
     */
    virtual void OnTradeReport(TradeDetail* trade_detail);

    /**
     * ����״̬�仯�ص�
     *
     * @param order_detail  �ص��Ķ�������
     */
    virtual void OnOrderStatus(OrderDetail* order_detail);

    /**
     * ����ί��Ӧ��ص�
     *
     * @param order_rsp     ����ί��Ӧ��
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * ����Ӧ��ص�
     *
     * @param cancel_rsp    ����Ӧ��
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * ��ѯ���ն����������Ӧ��һ�η���һ����������
     * QueryOrder��QueryOrderByCode��QueryOrders���ɴ˽ӿ���Ӧ
     *
     * @param order_detail  ��������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOrderRsp(OrderDetail* order_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ���ճɽ��������Ӧ��һ�η���һ���ɽ�����
     * QueryTradeByCode��QueryTrades���ɴ˽ӿ���Ӧ
     *
     * @param trade_detail  �ɽ�����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryTradeRsp(TradeDetail* trade_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ���ճֲ��������Ӧ��һ�η���һ���ֲ�����
     * QueryPosition��QueryPositions�ɴ˽ӿ���Ӧ
     *
     * @param position_detail   �ֲ�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryPositionRsp(OptionPositionDetail* position_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯ�����ʽ����Ӧ
     *
     * @param cash_detail   �ʽ�����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnQueryCashRsp(OptionCashDetail* cash_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * �鼯�н���ϵͳ�����ʽ�
     *
     * @param avail_balance �����ʽ𣬵�λ�������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    �������кţ�����ƥ����Ӧ�����û��Զ��壬��0
     */
    virtual void OnQueryJZJYAvailFundRsp(int64_t avail_balance,
        ErrorInfo* error_info,
        int request_id);

    /**
     * ���н��׹�̨����ٹ�̨֮���ʽ�ת��ת��
     *
     * @param transfer_value    ��ת���
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        �������кţ�����ƥ����Ӧ�����û��Զ���
     */
    virtual void OnTransferFundInAndOutRsp(int64_t transfer_value,
        ErrorInfo* error_info,
        int request_id);

    /**
     * ��Ȩ��Ӧ
     *
     * @param exercise_rsp  ��Ȩ��Ӧ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnExerciseRsp(ExerciseRsp* exercise_rsp, ErrorInfo* error_info,
        int request_id);

    /**
     * ������Ȩ��Ӧ
     *
     * @param cancel_rsp    ������Ȩ��Ӧ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnCancelExerciseRsp(CancelExerciseRsp* cancel_rsp,
        ErrorInfo* error_info, int request_id);

    /**
     * ��Ȩ״̬����
     *
     * @param exercise      ��Ȩί������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnExerciseStatus(ExerciseDetail* exercise);

    /**
     * ��ѯ������Ȩί�е���Ӧ��һ�η���һ���ֲ�����
     * QueryExercise, QueryExercises�ɴ˽ӿ���Ӧ
     *
     * @param detail            ��Ȩί������
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str           ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryExerciseRsp(ExerciseDetail* detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ȩ��Լ��Ϣ
     * QueryContractInfo�ɴ˽ӿ���Ӧ
     *
     * @param detail            ��Ȩ��Լ��Ϣ
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryContractInfoRsp(ContractInfo* detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯ��Ȩϵͳ�ֻ��ֲֵ���Ӧ
     * QueryStockPositions�ɴ˽ӿ���Ӧ
     *
     * @param position_detail   �ֻ��ֲ�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryStockPositionRsp(PositionDetail* position_detail,
        ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * �ֻ��ֲֻ�ת״̬����
     *
     * @param transfer_detail   �ֻ��ֲֻ�ת����
     */
    virtual void OnTransferStockStatus(TransferStockDetail* transfer_detail);

    /**
     * �ֻ��ֲֻ�ת��Ӧ
     *
     * @param transfer_rsp  �ֻ��ֲֻ�ת��Ӧ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnTransferStockRsp(TransferStockRsp* transfer_rsp,
        ErrorInfo* error_info, int request_id);

    /**
     * ��ѯ�ֻ��ֲֻ�ת��ˮ����Ӧ
     * QueryTransferStocks�ɴ˽ӿ���Ӧ
     *
     * @param transfer_detail   �ֻ��ֲֻ�ת����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     */
    virtual void OnQueryTransferStockRsp(TransferStockDetail* transfer_detail,
        ErrorInfo* error_info,
        int request_id);

    /**
     * �����ֻ�ί��״̬�仯�ص�
     *
     * @param order_detail  �ص��Ķ�������
     */
    virtual void OnLockOrderStatus(LockOrderDetail* order_detail);

    /**
     * �����ֻ�ί��Ӧ��ص�
     *
     * @param order_rsp     �����ֻ�ί��Ӧ��
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnLockOrderRsp(LockOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * ��ѯ��������ί���������Ӧ��һ�η���һ����������
     * QueryLockOrder��QueryLockOrders���ɴ˽ӿ���Ӧ
     *
     * @param order_detail  ����ί������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryLockOrderRsp(LockOrderDetail* order_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ���������ֲ��������Ӧ��һ�η���һ���ֲ�����
     * QueryLockPositions�ɴ˽ӿ���Ӧ
     *
     * @param position_detail   �������ֻ��ֲ�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryLockPositionRsp(PositionDetail* position_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ���ί��״̬�仯�ص�
     *
     * @param order_detail  �ص��Ķ�������
     */
    virtual void OnCombOrderStatus(CombOrderDetail* order_detail);

    /**
     * ���ί��Ӧ��ص�
     *
     * @param order_rsp     ���ί��Ӧ��
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnCombOrderRsp(CombOrderRsp* order_rsp, ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * �����Ȩ״̬����
     *
     * @param exercise      �����Ȩί������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnCombExerciseStatus(CombExerciseDetail* exercise);

    /**
     * �����Ȩ��Ӧ
     *
     * @param exercise_rsp  �����Ȩ��Ӧ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnCombExerciseRsp(CombExerciseRsp* exercise_rsp,
        ErrorInfo* error_info, int request_id);

    /**
     * ���������Ȩ��Ӧ
     *
     * @param cancel_rsp    ���������Ȩ��Ӧ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnCancelCombExerciseRsp(CancelCombExerciseRsp* cancel_rsp,
        ErrorInfo* error_info,
        int request_id);

    /**
     * ��ѯ������϶����������Ӧ��һ�η���һ����������
     * QueryCombOrder��QueryCombOrderByCode��QueryCombOrders���ɴ˽ӿ���Ӧ
     *
     * @param order_detail  ��϶�������
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str       ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryCombOrderRsp(CombOrderDetail* order_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ���������Ȩί�е���Ӧ��һ�η���һ���ֲ�����
     * QueryCombExercise, QueryCombExercises�ɴ˽ӿ���Ӧ
     *
     * @param detail            �����Ȩί������
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str           ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryCombExerciseRsp(CombExerciseDetail* detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ������ϳֲ��������Ӧ��һ�η���һ���ֲ�����
     * QueryCombPosition��QueryCombPositions�ɴ˽ӿ���Ӧ
     *
     * @param position_detail   ��ϳֲ�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryCombPositionRsp(CombPositionDetail* position_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯ�����Ȩ��Լ��Ϣ
     * QueryCombContractInfo�ɴ˽ӿ���Ӧ
     *
     * @param detail            ��Ȩ��Լ��Ϣ
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryCombContractInfoRsp(CombContractInfo* detail,
        ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * ��ѯ�ʽ�ת��ˮ����Ӧ
     *
     * @param detail        �ʽ�ת��ϸ����
     * @param error_info    Ӧ��Ĵ�����Ϣ
     * @param request_id    ��Ӧ����ʱ��������к�
     * @param is_last       �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryTransferFundHistoryRsp(TransferFundDetail* detail,
        ErrorInfo* error_info,
        int request_id, bool is_last);

    /**
     * ��ѯ������ϳֲ��������Ӧ��һ�η���һ���ֲ�����
     * QueryCombPositionSubDetails�ɴ˽ӿ���Ӧ
     *
     * @param position_detail   ��ϳֲ�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryCombPositionSubDetailRsp(CombPositionSubDetail* position_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ΢����Ӧ��
     *
     * @param rsp           ΢����Ӧ������
     * @param request_id    ��Ӧ����ʱ��������к�
     */
    virtual void OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id);

    /**
     * ��ѯͶ�����޲ֵ���Ӧ��һ�η���һ���޲�����
     * QueryPositionLimits�ɴ˽ӿ���Ӧ
     *
     * @param limit_detail      �޲�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     * @param is_last           �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryPositionLimitsRsp(PositionLimitsDetail* limit_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯͶ�����޶����Ӧ��һ�η���һ���޶�����
     * QueryAmountLimits�ɴ˽ӿ���Ӧ
     *
     * @param limit_detail      �޶�����
     * @param error_info        Ӧ��Ĵ�����Ϣ
     * @param request_id        ��Ӧ����ʱ��������к�
     */
    virtual void OnQueryAmountLimitsRsp(AmountLimitsDetail* limit_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * ��ѯ�����Ϻ�Լ��֤����䶯��Ӧ
     * QuerySplitCombMarginDifference�ɴ˽ӿ���Ӧ
     *
     * @param margin_diff_detail    �����Ϻ�Լ��֤����䶯����
     * @param error_info            Ӧ��Ĵ�����Ϣ
     * @param request_id            ��Ӧ����ʱ��������к�
     */
    virtual void OnQuerySplitCombMarginDifferenceRsp(SplitCombMarginDiffDetail* margin_diff_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * ��ѯͶ������Ȩָ����ϸ��Ӧ
     * QueryExerciseAppointment�ɴ˽ӿ���Ӧ
     *
     * @param appointment_detail     Ͷ������Ȩָ����ϸ����
     * @param error_info             Ӧ��Ĵ�����Ϣ
     * @param request_id             ��Ӧ����ʱ��������к�
     * @param is_last                �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryExerciseAppointmentRsp(ExerciseAppointmentDetail* appointment_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯ��Ʊ��Ȩ��֤����ն���ϸ��Ӧ
     * QueryMarginRisk�ɴ˽ӿ���Ӧ
     *
     * @param detail                 Ͷ������Ȩָ����ϸ����
     * @param error_info             Ӧ��Ĵ�����Ϣ
     * @param request_id             ��Ӧ����ʱ��������к�
     */
    virtual void OnQueryMarginRiskRsp(MarginRiskDetail* detail, ErrorInfo* error_info, int request_id);

    /**
     * ��ѯ��Ȩ����ί������Ӧ
     * QueryOptionMaxOrderVolume�ɴ˽ӿ���Ӧ
     * @param max_order_detail       ��Ȩ����ί��������
     * @param error_info             Ӧ��Ĵ�����Ϣ
     * @param request_id             ��Ӧ����ʱ��������к�
     */
    virtual void OnQueryOptionMaxOrderVolumeRsp(OptionMaxOrderVolumeDetail* max_order_detail,
        ErrorInfo* error_info, int request_id);

    /**
    * ��ѯ�ֻ�ϵͳ�ֻ��ֲֵ���Ӧ
    * QueryInquiryStockPositions�ɴ˽ӿ���Ӧ
    *
    * @param position_detail   �ֻ��ֲ�����
    * @param error_info        Ӧ��Ĵ�����Ϣ
    * @param request_id        ��Ӧ����ʱ��������к�
    */
    virtual void OnQueryInquiryStockPositionRsp(PositionDetail* position_detail,
        ErrorInfo* error_info, int request_id);

    /**
     * ��ѯ��Ʊ��Ȩ��ʷί����Ӧ��һ�η���һ����ʷί������
     * QueryOptionOrderHistory�ɴ˽ӿ���Ӧ
     *
     * @param his_order_detail      ��Ʊ��Ȩ��ʷί������
     * @param error_info            Ӧ��Ĵ�����Ϣ
     * @param request_id            ��Ӧ����ʱ��������к�
     * @param is_last               �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str               ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionOrderHistoryRsp(OptionHisOrderDetail* his_order_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ʊ��Ȩ��ʷ�ɽ���Ӧ��һ�η���һ����ʷ�ɽ�����
     * QueryOptionTradeHistory�ɴ˽ӿ���Ӧ
     *
     * @param his_trade_detail     ��Ʊ��Ȩ��ʷ�ɽ�����
     * @param error_info           Ӧ��Ĵ�����Ϣ
     * @param request_id           ��Ӧ����ʱ��������к�
     * @param is_last              �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str              ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionTradeHistoryRsp(OptionHisTradeDetail* his_trade_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ʊ��Ȩ��ʷ��Ȩָ����ϸ��Ӧ��һ�η���һ����ʷ��Ȩָ����ϸ����
     * QueryExerciseAppointmentHistory�ɴ˽ӿ���Ӧ
     *
     * @param his_appointment_detail       ��Ʊ��Ȩ��ʷ��Ȩָ����ϸ����
     * @param error_info                   Ӧ��Ĵ�����Ϣ
     * @param request_id                   ��Ӧ����ʱ��������к�
     * @param is_last                      �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                      ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryExerciseAppointmentHistoryRsp(HisExerciseAppointmentDetail* his_appointment_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ʊ��Ȩ��ʷ������ϸ��Ӧ��һ�η���һ����ʷ������ϸ����
     * QueryOptionDeliveryHistory�ɴ˽ӿ���Ӧ
     *
     * @param his_delivery_detail     ��Ʊ��Ȩ��ʷ������ϸ����
     * @param error_info              Ӧ��Ĵ�����Ϣ
     * @param request_id              ��Ӧ����ʱ��������к�
     * @param is_last                 �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                 ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionDeliveryHistoryRsp(OptionHisDeliveryDetail* his_delivery_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��ʷ��Ȩ������ˮ��ϸ��Ӧ��һ�η���һ����ʷ��Ȩ������ˮ��ϸ
     * QueryExerciseDeliveryHistory�ɴ˽ӿ���Ӧ
     *
     * @param exercise_delivery_detail     ��ʷ��Ȩ������ˮ��ϸ
     * @param error_info                   Ӧ��Ĵ�����Ϣ
     * @param request_id                   ��Ӧ����ʱ��������к�
     * @param is_last                      �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                      ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryExerciseDeliveryHistoryRsp(HisExerciseDeliveryyDetail* exercise_delivery_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ���˵���ʷ��Լ�ʲ���Ӧ��һ�η���һ�����˵���ʷ��Լ�ʲ���ϸ
     * QueryOptionContractAssetHistory�ɴ˽ӿ���Ӧ
     *
     * @param contract_asset_detail        ���˵���ʷ��Լ�ʲ���ϸ
     * @param error_info                   Ӧ��Ĵ�����Ϣ
     * @param request_id                   ��Ӧ����ʱ��������к�
     * @param is_last                      �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                      ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionContractAssetHistoryRsp(OptionHisContractAssetDetail* contract_asset_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��ʷ���ս�����������Ӧ��һ�η���һ����ʷ���ս�����������ϸ
     * QueryOptionDeliveryNettingHistory�ɴ˽ӿ���Ӧ
     *
     * @param delivery_netting_detail        ��ʷ���ս�����������ϸ
     * @param error_info                     Ӧ��Ĵ�����Ϣ
     * @param request_id                     ��Ӧ����ʱ��������к�
     * @param is_last                        �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryOptionDeliveryNettingHistoryRsp(OptionHisDeliveryNettingDetail* delivery_netting_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last);

    /**
     * ��ѯ��ʷ��ϳֲ���ϸ��Ӧ��һ�η���һ����ʷ��ϳֲ���ϸ
     * QueryOptionCombPositionHistory�ɴ˽ӿ���Ӧ
     *
     * @param comb_position_detail           ��ʷ��ϳֲ���ϸ
     * @param error_info                     Ӧ��Ĵ�����Ϣ
     * @param request_id                     ��Ӧ����ʱ��������к�
     * @param is_last                        �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                        ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionCombPositionHistoryRsp(OptionHisCombPositionDetail* comb_position_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ȩ��ʷ�����Ӧ��һ�η���һ����ʷ�����ϸ
     * QueryOptionSettlementHistory�ɴ˽ӿ���Ӧ
     *
     * @param his_settlement_detail          ��Ȩ��ʷ�����ϸ
     * @param error_info                     Ӧ��Ĵ�����Ϣ
     * @param request_id                     ��Ӧ����ʱ��������к�
     * @param is_last                        �Ƿ��Ǳ�����������һ����Ӧ
     * @param pos_str                        ���β�ѯ���һ����¼�Ķ�λ����������һ�β�ѯ
     */
    virtual void OnQueryOptionSettlementHistoryRsp(OptionHisSettlementDetail* his_settlement_detail,
        ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str);

    /**
     * ��ѯ��Ȩ��ϲ����ļ���Ӧ��һ�η���һ����Ȩ��ϲ����ļ���ϸ
     * QueryOptionCombStrategyFile�ɴ˽ӿ���Ӧ
     *
     * @param comb_strategy_file_detail      ��Ȩ��ϲ����ļ���ϸ
     * @param error_info                     Ӧ��Ĵ�����Ϣ
     * @param request_id                     ��Ӧ����ʱ��������к�
     * @param is_last                        �Ƿ��Ǳ�����������һ����Ӧ
     */
    virtual void OnQueryOptionCombStrategyFileRsp(OptionCombStrategyFileDetail* comb_strategy_file_detail,
        ErrorInfo* error_info, int request_id, bool is_last);

    //-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
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
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------
    void createTraderApi();

    string getApiVersion();

    void setLogConfig(string log_path);

    void setCriticalMsgLog(bool enable);

    void setLoginRetryCount(int login_retry_count);

    void setLoginRetryInterval(int login_retry_interval);

    void setReconnectConfig(int max_retry_count, int min_interval, int max_interval);

    void setKeepaliveConfig(int ka_interval, int max_probe_cnt);

    void release();

    dict getApiLastError();

    int exit();

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
