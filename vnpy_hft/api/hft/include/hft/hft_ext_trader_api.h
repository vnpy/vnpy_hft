/**
 * @file    hft_ext_trader_api.h
 * @brief   在现货两融基础上扩展更多业务接口的定义，包含其他较少使用的业务
 */

#ifndef _HFT_EXT_TRADER_API_H_
#define _HFT_EXT_TRADER_API_H_

#include "hft_trader_api.h"
#include "hft_ext_trader_struct.h"

namespace HFT {

// 扩展的回调接口类定义
class ExtTraderSpi : public TraderSpi {
   public:
    virtual ~ExtTraderSpi() {}

    /**
	 * 基金转托管应答
	 *
	 * @param rsp           基金转托管应答详情
	 * @param error_info    应答的错误信息
	 * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	 */
    virtual void OnFundReDepositRsp(FundReDepositRsp* detail, ErrorInfo* error_info,
                                    int request_id) {}

	/**
    * 要约收购业务委托应答
    *
    * @param detail        要约收购业务委托详情
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnTenderOfferOrderRsp(TenderOfferOrderDetail* detail, ErrorInfo* error_info, int request_id) {}

    /**
     * 查询要约收购信息应答
     *
     * @param detail        要约收购信息详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryTenderOfferInfoRsp(TenderOfferInfoDetail* detail, ErrorInfo* error_info,
                                           int request_id, bool is_last, const char* pos_str) {}

    /**
     * 查询股转受限投资者可交易证券应答
     *
     * @param detail        股转受限投资者可交易证券详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
     */
    virtual void OnQueryNEEQLimitedInvestorTradableStockRsp(
        NEEQLimitedInvestorTradableStockDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
     * 查询预受要约可委托数量应答
     *
     * @param detail        预受要约可委托数量详情
     * @param error_info    应答的错误信息
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryPreOffereeUsableOrderQtyRsp(PreOffereeUsableOrderQtyDetail* detail,
                                                    ErrorInfo* error_info, int request_id,
                                                    bool is_last) {}

    /**
     * 股转委托申报应答
     *  (股转集中竞价申报、股转发行申报(询价/申购)、股转协议转让定价申报)
     *
     * @param rsp           股转委托申报应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQOrderRsp(NEEQOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 股转集中竞价申报应答（两网退市股票专用）
     *
     * @param rsp           股转集中竞价申报应答（两网退市股票专用）
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQDelistOrderRsp(NEEQDelistOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 股转协议转让成交确认申报应答
     *
     * @param rsp           股转协议转让成交确认申报应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQTransactionOrderRsp(NEEQTransactionOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 股转摘牌协议转让成交确认申报应答
     *
     * @param rsp           股转摘牌协议转让成交确认申报应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQDelistTransactionOrderRsp(NEEQDelistTransactionOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 股转大宗交易成交确认申报应答
     *
     * @param rsp           股转大宗交易成交确认申报应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQBlockTradeOrderRsp(NEEQBlockTradeOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
     * 股转要约收购业务申报应答
     *
     * @param rsp           股转要约收购业务申报应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnNEEQTenderOfferOrderRsp(NEEQTenderOfferOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}


    /**
    * 股转专用股份明细查询应答
    *
    * @param detail        股转专用股份明细详情
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryNEEQSharesDetailRsp(QueryNEEQSharesDetail* detail,
        ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}
        
    /**
    * 股转市场公开发行认购结果查询应答
    *
    * @param detail        股转市场公开发行认购结果详情
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryNEEQSubscriptionResultsOfIPORsp(NEEQSubscriptionResultsOfIPODetail* detail, ErrorInfo* error_info,
        int request_id, bool is_last, const char* pos_str) {}

	/**
	* 查询要约收购人信息应答
	*
	* @param detail        要约收购人信息明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryTenderOfferUserRsp(TenderOfferUserDetail* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 大宗交易预委托应答
	*
	* @param rsp           大宗交易预委托应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnBlockPreOrderRsp(BlockPreOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 查询大宗交易预委托应答
	*
	* @param detail        大宗交易预委托明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQueryBlockPreOrderRsp(BlockPreOrderDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

	/**
	* 撤销大宗交易预委托应答
	*
	* @param rsp           撤销大宗交易预委托应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnCancelBlockPreOrderRsp(CancelBlockPreOrderRsp* rsp, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 查询大宗交易预委托营业部权限应答
	*
	* @param detail        大宗交易预委托营业部权限明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQueryBlockPreOrderDeptRightsRsp(BlockPreOrderDeptRightsDetail* detail,
		ErrorInfo* error_info, int request_id,
		bool is_last) {}

	/**
	* 大宗交易通用委托应答
	*
	* @param rsp           大宗交易通用委托应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnBlockOrderRsp(BlockOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 大宗交易通用撤单应答
	*
	* @param rsp           大宗交易通用撤单应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnCancelBlockOrderRsp(CancelBlockOrderRsp* rsp, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 查询大宗交易协议行情应答
	*
	* @param detail        协议行情明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryBlockMarketDataRsp(BlockMarketDataDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}
		
	/**
	* 沪港通公司行为申报请求应答
	*
	* @param detail        沪港通公司行为申报请求应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnHKCompanyBusinessApplyRsp(HKCompanyBusinessApplyRsp* detail, ErrorInfo* error_info,
		int request_id) {}
		
	/**
    * 港股通昨日结算汇率查询的响应
    *
    * @param detail        昨日结算汇率明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryHKYestDaySettSpotRateRsp(HKYestDaySettSpotRateDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

	/**
	* 查询港股通通知信息的响应
	*
	* @param req           查询港股通通知信息请求对象
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryHKNoticeInfoRsp(HKNoticeInfoDetail* detail, ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str) {}

    /**
    * 港股通公司行为历史查询的响应
    *
    * @param detail        港股通公司行为历史明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryHKCompHisBehaviorRsp(HKCompHisBehaviorDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 港股通登记日权益数量查询的响应
    *
    * @param detail        港股通登记日权益数量明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryHKRegisDateRightsQtyRsp(HKRegisDateRightsQtyDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

	/**
	* 查询港股通公司行为和投票应答
	*
	* @param detail        港股通公司行为和投票详情
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryHKCorporateActionAndVoteRsp(HKCorporateActionAndVoteDetail* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

    /**
     * ETF网下认购应答
     *
     * @param rsp           ETF网下认购应答
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual void OnETFOfflineSubscribeRsp(ETFOfflineSubscribeRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 外围 ETF 认购查询股票可认购数量应答
	*
	* @param detail        外围 ETF 认购查询股票可认购数量应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnQueryETFStkSubscribeAbleQtyRsp(QryETFStkSubscribeAbleQtyRsp* detail, ErrorInfo* error_info, 
												  int request_id, bool is_last, const char* pos_str) {}

	/**
	* 外围 ETF 认购查询请求应答
	*
	* @param detail        外围 ETF 认购查询请求应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnQueryETFSubscribeInfoRsp(QryETFSubscribeInfoRsp* detail, ErrorInfo* error_info,
											int request_id, bool is_last, const char* pos_str) {}

    /**
    * 深圳场内LOF基金分红方式设置应答
    *
    * @param rsp           深圳场内LOF基金分红方式设置应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnSZLOFDividendMethodSetRsp(SZLOFDividendMethodSetRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 私募认购/申购业务应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnPrivateOfferingPurchaseRsp(OfOrderDetailRsp* detail, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 基金申购/认购业务应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnFundPurchaseOrderRsp(FundPurchaseRsp* detail, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 基金赎回业务应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnFundRedeemRsp(OfOrderDetailRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 基金撤销( 认购/ 申购/ 赎回) 业务应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnFundOrderCancelRsp(OfOrderDetailRsp* detail, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 基金转换业务请求应答
	*
	* @param rsp           基金转换业务应答
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnFundTransformRsp(FundCommRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 基金分红方式设置请求应答
	*
	* @param rsp           基金分红方式设置应答
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnFundSetBonusTypeRsp(FundCommRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 基金分红方式查询请求应答
	*
	* @param rsp           基金分红方式应答明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryFundBonusTypeRsp(FundBonusTypeDetail* rsp, ErrorInfo* error_info,
		int request_id, bool is_last) {}

	/**
	* 开放式基金当日委托查询应答
	*
	*
	* @param detail        基金当日委托查询详情
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryOfOrderRsp(QryOfOrderRspDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

	/**
	* 开放式基金持仓查询应答
	*
	*
	* @param detail        基金持仓查询详情
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryOfPositionRsp(QryOfPositionRspDetail* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

	/**
	*  基金确认息查应答
	*
	* @param detail		   基金确认息查详情
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryFundConfirmInfoRsp(QryFundConfirmInfoRsp* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

	/**
	*  基金行情信息查询请求应答
	*
	* @param detail		   基金行情信息详情
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryFundMarketDataRsp(QryFundMarketDataRsp* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}

	/**
	* 基金开户应答
	*
	* @param rsp           基金开户应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnCreatFundAccountRsp(CreatFundAccountRsp* detail, ErrorInfo* error_info,
		int request_id) {}

	/**
	* 基金账户信息查询请求应答
	*
	* @param detail		   基金账户信息详情
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryFundAccountInfoRsp(QryFundAccountInfoRsp* detail, ErrorInfo* error_info,
		int request_id, bool is_last, const char* pos_str) {}
	
	/**
    * 新私募债委托处理应答, 同时支持上海新债券协商成交委托应答
    *
    * @param rsp           委托处理应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnNewPrivatePlacementBondOrderRsp(NewPrivatePlacementBondOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
    * 新私募债委托撤单应答
    *
    * @param cancel_rsp    新私募债委托撤单应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnNewPrivatePlacementBondCancelOrderRsp(NewPrivatePlacementBondCancelOrderRsp* cancel_rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 新私募债可撤委托查询的响应
    *
    * @param detail        新私募债可撤委托明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryNewPrivateBondAviCancelOrderRsp(NewPrivateBondAviCancelOrderDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 固收委托查询的响应
    *
    * @param detail        固收委托明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySolidChargeOrderRsp(SolidChargeOrderDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

	/**
	* 报价行情查询应答
	*
	* @param req           报价行情查询应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryQuotationRsp(QryQuotationDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 协议回购委托查询（沪深）应答
	*
	* @param req           协议回购委托查询（沪深）应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryNegotiatedRepurchaseOrderRsp(QryNegotiatedRepurchaseOrderDetail* detail, ErrorInfo* error_info, 
			int request_id, bool is_last, const char* pos_str) {}

	/**
	* 协议回购交易员查询应答
	*
	* @param req           协议回购交易员查询应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryNegotiatedRepurchaseDealperRsp(NegotiatedRepurchaseDealperDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 协议回购委托撤单应答
	*
	* @param req           协议回购委托撤单应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnNegotiatedRepurchaseOrderCancelRsp(NegotiatedRepurchaseOrderCancelDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 协议回购确认拒绝应答
	*
	* @param req           协议回购确认拒绝应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnNegotiatedRepurchaseRejectRsp(NegotiatedRepurchaseRejectDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 客户回购指标查询应答
	*
	* @param req           客户回购指标查询应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQueryRepurchaseIndexRsp(QryRepurchaseIndexDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 未到期回购合约查询应答
	*
	* @param req           未到期回购合约查询应答
	* @param request_id    应答序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void QueryUnexpiredRepurchaseContractRsp(QryUnexpiredRepurchaseContractDetail* detail, ErrorInfo* error_info, 
												     int request_id, bool is_last) {}


	/**
	* 未到期余额查询应答
	*
	* @param detail        未到期余额明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQueryContractBuyBackUnexpiredAmtRsp(QryContractBuyBackUnexpiredAmtRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 上海交易所未结算协议回购查询应答
	*
	* @param detail        交易所未结算协议回购明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQueryContractBuyBackUnsettledInfoRsp(QryContractBuyBackUnsettledInfoRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳债券协议回购转发成交请求查询应答
	*
	* @param detail        深圳债券协议回购转发成交明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZBondContractBuyBackTransmitTradeRsp(QrySZBondContractBuyBackTransmitTradeRsp* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 深圳债券协议回购可质押券查询应答
	*
	* @param detail        深圳债券协议回购可质押券明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZBondContractBuyBackPledgeAvailableStkRsp(QrySZBondContractBuyBackPledgeAvailableStkRsp* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 深圳债券质押交易商信息查询应答
	*
	* @param detail        深圳债券质押交易商信息明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZBondContractBuyBackPledgeMemberRsp(QrySZBondContractBuyBackPledgeMemberRsp* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 深圳债券质押本地未到期回购合约查询应答
	*
	* @param detail        深圳债券质押本地未到期回购合约明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZBondContractBuyBackPledgeUnexpiredRsp(QrySZBondContractBuyBackPledgeUnexpiredRsp* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
	* 深圳债券协议回购质押券查询应答
	*
	* @param detail        深圳债券协议回购质押券明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZBondContractBuyBackPledgeStkRsp(QrySZBondContractBuyBackPledgeStkRsp* detail, ErrorInfo* error_info, int request_id, bool is_last) {}


	/**
	* 查询债券质押式回购实际占款天数应答
	*
	* @param detail        债券质押式回购实际占款天数明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnBondContractBuyBackPledgeOccupyDaysRsp(BondContractBuyBackPledgeOccupyDaysDetail* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 客户新标准券查询应答
	*
	* @param rsp           客户新标准券查询应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnQueryCustStandardNewBondRsp(QryCustStandardNewBondRsp* detail, ErrorInfo* error_info, int request_id) {}
	
	/**
	* 当日逆回购成交查询应答
	*
	* @param detail        当日逆回购成交明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryBondReverseTradeListRsp(QryBondReverseTradeListRsp* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}
		
	/**
	* 未到期回购查询应答
	*
	* @param detail        未到期回购明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryUnexpiredBondReverseInfoRsp(QryUnexpiredBondReverseInfoRsp* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}
	
	/**
    * 债券交易通用委托应答
    *
    * @param rsp           债券交易通用委托应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnBondOrderRsp(BondOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}
	
	/**
	* 质押存量折算查询应答
	*
	* @param detail        质押存量折算明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryBondPledgeAvailableDiscountRsp(QryBondPledgeAvailableDiscountRsp* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

    /**
    * 客户总资产明细查询应答
    *
    * @param rsp           客户总资产明细查询应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnQueryTotalAssetDetailRsp(TotalAssetDetailRsp* rsp, ErrorInfo* error_info, int request_id) {}
	/**
	* 留存业务客户资产总值查询明细
	*
	* @param rsp           留存业务客户资产总值查询明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnQueryRetainedTotalAssetsRsp(RetainedTotalAssetsRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 留存业务客户资产总值分类查询明细
	*
	* @param rsp           留存业务客户资产总值分类查询明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnQueryRetainedTotalAssetsTypeRsp(RetainedTotalAssetsTypeRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 留存业务， 查询资金账户应答
	*
	* @param rsp           留存业务， 查询资金账户应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQueryRetainedFundRsp(RetainedFundDetailRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 留存业务， 查询持仓列表应答
	*
	* @param rsp          留存业务， 查询持仓列表应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQueryRetainedPositionListRsp(RetainedPositionDetailRsp* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 留存业务， 查询委托列表应答
	*
	* @param rsp          留存业务， 查询委托列表应答
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQueryRetainedOrderListRsp(RetainedOrderStatusDetailRsp* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 留存业务 撤单委托查询应答
	*
	* @param detail        撤单委托明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryRetainedCancelOrderListRsp(RetainedCancelOrderRecord* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 留存业务 当日分笔成交查询应答
	*
	* @param detail        当日分笔成交明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryRetainedTradeListRsp(RetainedTradeRecord* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 留存业务 当日汇总成交查询应答
	*
	* @param detail        当日汇总成交明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryRetainedTradeListTotalRsp(RetainedTradeTotalRecord* detail,
		ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) {}

	/**
	* 新股中签扣款顺序查询的响应
	*
	* @param detail        新股中签扣款顺序明细数据
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
	*/
	virtual void OnQueryIPOLotteryDeductSeqRsp(IPOLotteryDeductSeqDetail* detail, ErrorInfo* error_info, int request_id,
		bool is_last, const char* pos_str) {}

	/**
	* 新股中签扣款顺序设置的应答
	*
	* @param detail        新股中签扣款顺序设置应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnSetIPOLotteryDeductSeqRsp(SetIPOLotteryDeductSeqRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 中签资金冻结后放弃认购回调
	*
	* @param rsp           中签资金冻结后放弃认购应答详情
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnIPOLotteryAbandonRsp(IPOLotteryAbandonRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 港股通投票请求应答
	*
	* @param detail        港股通投票请求应答
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnHKStockVoteRsp(HKStockVoteRsp* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 深圳固收债券当日委托查询响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondOrderRsp(SZBondOrderDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收当日委托扩展信息查询响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondOrderExtendInfoRsp(SZBondOrderExtendInfoDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收债券历史委托查询响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondHisOrderRsp(SZBondHisOrderDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收市场竞买预约信息查询响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondMarketBidAppointmentRsp(SZBondMarketBidAppointmentDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收客户竞买预约信息查询响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySZBondCustomerBidAppointmentRsp(SZBondCustomerBidAppointmentDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last) {}


	/**
    * 深圳固收债券-历史成交明细查询应答
    *
    * @param detail        历史成交明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryBondHistoryTradingDetailsRsp(BondHistoryTradingDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

	/**
    * 深圳固收债券-申报委托撤单应答
    *
    * @param detail        申报委托撤单数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnSZBondOrderCancelRsp(SZBondOrderCancelDetail* detail, ErrorInfo* error_info, int request_id) {}

	/**
    * 深圳固收债券-转发询价查询应答
    *
    * @param detail        转发询价查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQuerySZBondForwardInquiryRsp(SZBondForwardInquiryDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
    * 深圳固收债券-转发报价查询应答
    *
    * @param detail        转发报价查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQuerySZBondForwardQuotationRsp(SZBondForwardQuotationDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}

	/**
    * 深圳固收债券-点击成交逐笔委托行情查询应答
    *
    * @param detail        点击成交逐笔委托行情查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondPerOrderInfoOfClickDealRsp(SZBondPerOrderInfoOfClickDealDetail* detail, ErrorInfo* error_info, 
			int request_id, bool is_last, const char* pos_str) {}

	/**
    * 深圳固收债券-交易业务参考信息查询应答
    *
    * @param detail        交易业务参考信息查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQuerySZBondTradingBusinessReferenceInfoRsp(SZBondTradingBusinessReferenceInfoDetail* detail, ErrorInfo* error_info, int request_id, bool is_last) {}



    /**
    * 固收债券历史委托扩展信息查询的响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryBondHisOrderExtInfoRsp(BondHisOrderExtInfoDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收债券协商成交申报查询的响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySZBondNegotiatedTradeOrderRsp(SZBondNegotiatedTradeOrderDetail* detail, ErrorInfo* error_info, 
                       int request_id, bool is_last) {}

    /**
    * 深圳固收债券当日成交明细查询的响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondTradeListRsp(SZBondTradeListDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 固收债券竞买成交历史预约信息查询的响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryBondAuctionsTradeHisAppointmentRsp(BondAuctionsTradeHisAppointmentDetail* detail, ErrorInfo* error_info, int request_id,
        bool is_last, const char* pos_str) {}

    /**
    * 深圳固收债券竞买成交逐笔应价行情查询的响应
    *
    * @param detail        响应的明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
	* @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQuerySZBondAuctionsTradeBidMarketOrderRsp(SZBondAuctionsTradeBidMarketOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str){}

    /**
    * 客户风险测评信息查询的响应
    *
    * @param detail        客户风险测评信息明细数据
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQueryCustRiskAssessmentInfoRsp(CustRiskAssessmentInfoDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last) {}   
  


	/**
	* 券池券单查询应答
	*
	* @param detail        券池券单查询应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQCQueryVoucherRsp(QCQueryVoucherDetail* detail, ErrorInfo* error_info,
									 int request_id, bool is_last, const char* pos_str) {}
	
	/**
	* 市场券约券下单应答
	*
	* @param detail        市场券约券下单应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQytSubscribeOrderRsp(QytSubscribeOrderDetail* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通约券委托查询应答
    *
    * @param detail        券源通约券委托详情
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytSubscribeOrderListRsp(QytSubscribeOrderRecord* detail, ErrorInfo* error_info, 
            int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通约券委托撤单应答
    *
    * @param rsp        券源通约券委托撤单应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnCancelQytSubscribeOrderRsp(CancelQytSubscribeOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通约券委托成交查询应答
    *
    * @param detail        券源通约券委托成交详情
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytSubscribeTradeListRsp(QytSubscribeTradeDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last, const char* pos_str) {}


	/**
	* 券单汇总查询应答
	*
	* @param detail        券单汇总查询应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQCQueryVoucherSummaryRsp(QCQueryVoucherSummaryDetail* detail, ErrorInfo* error_info,
									 int request_id, bool is_last, const char* pos_str) {}
	
    /**
    * 券源通展期前置判断应答
    *
    * @param detail        券源通展期前置判断应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnQytExtensionPreJudgeRsp(QytExtensionPreJudgeRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通展期申请委托应答
    *
    * @param detail        券源通展期申请委托应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnQytExtensionOrderRsp(QytExtensionOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通展期申请查询应答
    *
    * @param detail        券源通展期申请查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytExtensionOrderListRsp(QytExtensionOrderDetail* detail, ErrorInfo* error_info, 
                       int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通展期申请撤销应答
    *
    * @param detail        券源通展期申请撤销应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnCancelQytExtensionOrderRsp(CancelQytExtensionOrderRsp* detail, ErrorInfo* error_info, int request_id) {}

	/**
	* 约券合约查询应答
	*
	* @param detail        约券合约应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnQCQueryAppointmentContractRsp(QCQueryAppointmentContractDetail* detail, ErrorInfo* error_info,
									 int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券池查询客户合约定价信息应答
    *
    * @param detail        客户合约定价信息详情
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQCQueryCustContractPriceInfoRsp(QCQueryCustContractPriceInfoDeatil* detail, ErrorInfo* error_info,
                                        int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通预告申报应答
    *
    * @param detail        券源通预告申报应答明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQytForecastOrderRsp(QytForecastOrderDetail* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通定向申报应答
    *
    * @param detail        券源通定向申报应答明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQytDirectOrderRsp(QytDirectOrderDetail* detail, ErrorInfo* error_info, int request_id) {}


    /**
    * 券源通标准篮子申报应答
    *
    * @param detail        券源通标准篮子申报应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnQytBasketOrderRsp(QytBasketOrderDetail* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通篮子申报撤单应答
    *
    * @param detail        券源通篮子申报撤单应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnCancelQytBasketOrderRsp(CancelQytBasketOrderRsp* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通篮子申报查询应答
    *
    * @param detail        篮子申报明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytBasketOrderRsp(QytBasketOrderRecord* detail, ErrorInfo* error_info, 
            int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通标准篮子申报详情应答
    *
    * @param detail        标准篮子申报详情明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytBasketOrderDetailRsp(QytBasketOrderDetailRecord* detail, ErrorInfo* error_info, 
            int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通定制篮子申报详情应答
    *
    * @param detail        定制篮子申报详情明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytCustBasketOrderDetailRsp(QytCustBasketOrderDetailRecord* detail, ErrorInfo* error_info, 
            int request_id, bool is_last, const char* pos_str) {}


    /**
     * 资产总值分类查询的响应
     * 
     * @param detail        明细记录
     * @param error_info    应答的错误信息
     * @param request_id    对应请求时传入的序列号
     * @param is_last       是否是本次请求的最后一笔响应
     */
    virtual void OnQueryTotalFundAssetDetailRsp(TotalFundAssetDetail* detail, ErrorInfo* error_info, int request_id,
												bool is_last) {}

	/**
	* 基金确认信息查询响应
	*
	* @param detail        明细记录
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQueryFundConfirmInfoJZRsp(QueryFundConfirmInfoDetail* detail, ErrorInfo* error_info, int request_id,
											bool is_last, const char* pos_str) {}

	/**
	* 外围基金交收信息查询响应
	*
	* @param detail        明细记录
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQueryFundSettleMentRsp(QueryFundSettleMentDetail* detail, ErrorInfo* error_info, int request_id,
										 bool is_last, const char* pos_str) {}

	/**
	* 基金历史交易查询响应
	*
	* @param detail        明细记录
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQueryFundHisTransacRsp(QueryFundHisTransacDetail* detail, ErrorInfo* error_info, int request_id,
										 bool is_last, const char* pos_str) {}
	/**
	* 基金产品风险揭示书签署响应
	*
	* @param detail        明细记录
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	*/
	virtual void OnSignFundRiskGgreementRsp(SignFundRiskGgreementRsp* detail, ErrorInfo* error_info, int request_id) {}

    /**
    * 资金横向划转应答
    *
    * @param rsp           资金横向划转应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    */
    virtual void OnLateralTransferOrderRsp(LateralTransferOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 查询横向划转流水应答
    *
    * @param detail        横向划转流水明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQueryLateralTransferFlowRsp(LateralTransferFlowDetail* detail, ErrorInfo* error_info,
            int request_id, bool is_last) {}

	/**
	* 券源通意向登记应答
	*
	* @param req           券源通意向登记请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQytIntenRegistraRsp(QytIntenRegistraRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 券源通查询意向登记应答
	*
	* @param req           券源通查询意向登记请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual void OnQytQueryIntenRegistraRsp(QytQueryIntenRegistraRsp* detail, ErrorInfo* error_info,
											int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通提前了结前置判断应答
    *
    * @param detail        券源通提前了结前置判断应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnQytSettleEarlyPreJudgeRsp(QytSettleEarlyPreJudgeRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通提前了结申请应答
    *
    * @param detail        券源通提前了结申请应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnQytSettleEarlyOrderRsp(QytSettleEarlyOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 券源通提前了结查询应答
    *
    * @param detail        券源通提前了结查询应答
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryQytSettleEarlyOrdersRsp(QytSettleEarlyOrderDetail* detail, ErrorInfo* error_info, 
                       int request_id, bool is_last, const char* pos_str) {}

    /**
    * 券源通提前了结撤单应答
    *
    * @param rsp           券源通提前了结撤单应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnCancelQytSettleEarlyOrderRsp(CancelQytSettleEarlyOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳报价回购合约查询应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZQuoteRepoContractRsp(QrySZQuoteRepoContractDetail* detail, ErrorInfo* error_info,
											   int request_id, bool is_last) {}

	/**
	* 深圳报价回购委托应答
	*
	* @param rsp           应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnSZQuoteRepoOrderRsp(SZQuoteRepoOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳报价回购不再续做应答
	*
	* @param rsp           应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnSZQuoteRepoNoContinueRsp(SZQuoteRepoNoContinueRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳报价回购提前购回委托应答
	*
	* @param rsp           应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnSZQuoteRepoEarlyRepurchaseOrderRsp(SZQuoteRepoEarlyRepurchaseOrderRsp* rsp,
													  ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳报价回购提前购回预约应答
	*
	* @param rsp           应答明细
	* @param error_info    应答的错误信息
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*/
	virtual void OnSZQuoteRepoEarlyRepurchaseBookRsp(SZQuoteRepoEarlyRepurchaseBookRsp* rsp,
													 ErrorInfo* error_info, int request_id) {}

	/**
	* 深圳报价回购合约不再续做查询应答
	*
	* @param detail        应答明细
	* @param error_info    应答的错误信息
	* @param request_id    对应请求时传入的序列号
	* @param is_last       是否是本次请求的最后一笔响应
	*/
	virtual void OnQuerySZQuoteRepoNoContinueContractRsp(QrySZQuoteRepoNoContinueContractDetail* detail, ErrorInfo* error_info,
														 int request_id, bool is_last) {}

    /**
    * 报价回购利率额度查询应答
    *
    * @param detail        报价回购利率额度明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQueryQuoteRepoInteRateLimitRsp(QuoteRepoInteRateLimitDetail* detail, 
			ErrorInfo* error_info, int request_id, bool is_last) {}

    /**
    * 深圳报价回购产品信息查询应答
    *
    * @param detail        报价回购产品信息明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySZQuoteRepoProdInfoRsp(SZQuoteRepoProdInfoDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last) {}

    /**
    * 深圳报价回购委托查询应答
    *
    * @param detail        深圳报价回购委托明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySZQuoteRepoOrdersRsp(SZQuoteRepoOrderDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last) {}

	/**
    * 上海报价回购委托应答
    *
    * @param rsp           上海报价回购委托应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnSHQuoteRepoOrderRsp(SHQuoteRepoOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
    * 上海报价回购不再续做应答
    *
    * @param rsp           上海报价回购不再续做应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnSHQuoteRepoNoContinueRsp(SHQuoteRepoNoContinueRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
    * 上海报价回购提前购回委托应答
    *
    * @param rsp           上海报价回购提前购回委托应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnSHQuoteRepoEarlyRepurchaseOrderRsp(SHQuoteRepoEarlyRepurchaseOrderRsp* rsp, ErrorInfo* error_info, int request_id) {}

	/**
    * 上海报价回购提前购回预约应答
    *
    * @param rsp           上海报价回购提前购回预约应答
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    */
    virtual void OnSHQuoteRepoEarlyRepurchaseBookRsp(SHQuoteRepoEarlyRepurchaseBookRsp* rsp, ErrorInfo* error_info, int request_id) {}

    /**
    * 上海报价回购合约查询应答
    *
    * @param detail        上海报价回购合约明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySHQuoteRepoContractRsp(SHQuoteRepoContractDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last) {}

    /**
    * 上海报价回购业务查询应答
    *
    * @param detail        上海报价回购业务明细
    * @param error_info    应答的错误信息
    * @param request_id    对应请求时传入的序列号
    * @param is_last       是否是本次请求的最后一笔响应
    */
    virtual void OnQuerySHQuoteRepoBusinessRsp(SHQuoteRepoBusinessDetail* detail, ErrorInfo* error_info, 
            int request_id, bool is_last) {}

    /**
    * 股转发行证券信息查询应答
    *
    * @param detail        股转发行证券信息详情
    * @param error_info    应答的错误信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param is_last       是否是本次请求的最后一笔响应
    * @param pos_str       本次查询最后一条记录的定位串，用于下一次查询
    */
    virtual void OnQueryNEEQIPOStockRsp(NEEQIPOStockDetail* detail, ErrorInfo* error_info,
            int request_id, bool is_last, const char* pos_str) {}


};
 

// 扩展的交易接口类定义
class HFT_TRADER_EXPORT ExtTraderApi : virtual public TraderApi {
   public:
    /**
     * 获取ExtTraderApi实例，此实例与登录的交易账号相关联
     * 
     * @return              返回ExtTraderApi实例
     */
    static ExtTraderApi* CreateExtTraderApi();

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
     * 基金转托管请求
     *
     * @param req           基金转托管请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int FundReDeposit(FundReDepositReq* req, int request_id) = 0;

    /**
    * 要约收购业务委托请求
    *
    * @param order         要约收购业务委托请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int TenderOfferOrder(TenderOfferOrderReq* order, int request_id) = 0;

    /**
     * 要约收购信息查询请求
     *
     * @param req           要约收购信息查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTenderOfferInfo(QryTenderOfferInfoReq* req, int request_id) = 0;

    /**
     * 股转受限投资者可交易证券查询请求
     *
     * @param req           股转受限投资者可交易证券查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryNEEQLimitedInvestorTradableStock(QryNEEQLimitedInvestorTradableStockReq* req,
                                                      int request_id) = 0;

    /**
     * 预受要约可委托数量查询请求
     *
     * @param req           预受要约可委托数量查询请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryPreOffereeUsableOrderQty(QryPreOffereeUsableOrderQtyReq* req,
                                              int request_id) = 0;

    /**
     * 股转委托申报请求
     *  (股转集中竞价申报、股转发行申报(询价/申购)、股转协议转让定价申报)
     *
     * @param req           股转委托申报请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQOrder(NEEQOrderReq* req, int request_id) = 0;

    /**
     * 股转集中竞价申报请求（两网退市股票专用）
     *
     * @param req           股转集中竞价申报请求（两网退市股票专用）
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQDelistOrder(NEEQDelistOrderReq* req, int request_id) = 0;

    /**
     * 股转协议转让成交确认申报请求
     *
     * @param req           股转协议转让成交确认申报请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQTransactionOrder(NEEQTransactionOrderReq* req, int request_id) = 0;

    /**
     * 股转摘牌协议转让成交确认申报请求
     *
     * @param req           股转摘牌协议转让成交确认申报请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQDelistTransactionOrder(NEEQDelistTransactionOrderReq* req, int request_id) = 0;

    /**
     * 股转大宗交易成交确认申报请求
     *
     * @param req           股转大宗交易成交确认申报请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQBlockTradeOrder(NEEQBlockTradeOrderReq* req, int request_id) = 0;

    /**
     * 股转要约收购业务申报请求
     *
     * @param req           股转要约收购业务申报请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int NEEQTenderOfferOrder(NEEQTenderOfferOrderReq* req, int request_id) = 0;

    /**
    * 股转专用股份明细查询请求
    *
    * @param req           股转专用股份明细查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryNEEQShares(QueryNEEQSharesDetailReq* req, int request_id) = 0;
    
    /**
    * 股转市场公开发行认购结果查询请求
    *
    * @param req           股转市场公开发行认购结果查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryNEEQSubscriptionResultsOfIPO(QueryNEEQSubscriptionResultsOfIPOReq* req, int request_id) = 0;

	/**
	* 要约收购人信息查询
	*
	* @param req           要约收购人信息查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryTenderOfferUser(QryTenderOfferUser* req, int request_id) = 0;

	/**
	* 大宗交易预委托申请
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int BlockPreOrder(BlockPreOrderReq* req, int request_id) = 0;

	/**
	* 查询大宗交易预委托
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBlockPreOrders(QryBlockPreOrderReq* req, int request_id) = 0;

	/**
	* 撤销大宗交易预委托
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int CancelBlockPreOrder(CancelBlockPreOrderReq* req, int request_id) = 0;

	/**
	* 查询大宗交易预委托营业部权限
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBlockPreOrderDeptRights(QryBlockPreOrderDeptRightsReq* req,
		int request_id) = 0;

	/**
	* 大宗交易通用委托
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int BlockOrder(BlockOrderReq* req, int request_id) = 0;

	/**
	* 大宗交易通用撤单
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int CancelBlockOrder(CancelBlockOrderReq* req, int request_id) = 0;

	/**
	* 查询大宗交易协议行情
	*
	* @param req           请求明细，目前仅支持深圳市场查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBlockMarketData(QryBlockMarketDataReq* req, int request_id) = 0;

/**
	* 沪港通公司行为申报请求
	*
	* @param req           沪港通公司行为申报请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int HKCompanyBusinessApply(HKCompanyBusinessApplyReq* req, int request_id) = 0;

	/**
    * 港股通昨日结算汇率查询请求
    *
    * @param req           查询昨日结算汇率请求对象
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryHKYestDaySettSpotRate(QryHKYestDaySettSpotRateReq* req, int request_id) = 0;

	/**
	* 查询港股通通知信息请求
	*
	* @param req           查询港股通通知信息请求对象
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryHKNoticeInfo(QryHKNoticeReq* req, int request_id) = 0;

    /**
    * 港股通公司行为历史查询请求
    *
    * @param req           港股通公司行为历史查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryHKCompHisBehavior(QryHKCompHisBehaviorReq* req, int request_id) = 0;

    /**
    * 港股通登记日权益数量查询请求
    *
    * @param req           港股通登记日权益数量查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryHKRegisDateRightsQty(QryHKRegisDateRightsQtyReq* req, int request_id) = 0;
	
	/**
	* 港股通公司行为和投票查询请求
	*
	* @param req           港股通公司行为和投票查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryHKCorporateActionAndVote(QryHKCorporateActionAndVoteReq* req, int request_id) = 0;

    /**
     * ETF网下认购请求
     *
     * @param req           ETF网下认购请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int ETFOfflineSubscribe(ETFOfflineSubscribeReq* req, int request_id) = 0;

	/**
	* 外围 ETF 认购查询股票可认购数量请求
	*
	* @param req           外围 ETF 认购查询股票可认购数量请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryETFStkSubscribeAbleQty(QryETFStkSubscribeAbleQty* req, int request_id) = 0;

	/**
	* 外围 ETF 认购查询请求
	*
	* @param req           外围 ETF 认购查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryETFSubscribeInfo(QryETFSubscribeInfo* req, int request_id) = 0;

    /**
     * 深圳场内LOF基金分红方式设置请求
     *
     * @param req           深圳场内LOF基金分红方式设置请求
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int SZLOFDividendMethodSet(SZLOFDividendMethodSetReq* req, int request_id) = 0;
	

	/**
	* 私募认购/申购业务
	*
	* @param req           私募认购/申购业务请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int PrivateOfferingPurchase(PrivateOfferingPurchaseReq* req, int request_id) = 0;

	/**
	* 基金申购/认购业务
	*
	* @param req           基金申购/认购业务明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int FundPurchaseOrder(FundPurchaseReq* req, int request_id) = 0;

	/**
	* 基金赎回业务
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int FundRedeem(FundRedeemReq* req, int request_id) = 0;

	/**
	* 基金撤销(认购/申购/赎回)
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int FundOrderCancel(FundOrderCancelReq* req, int request_id) = 0;

	/**
	* 基金转换业务请求
	*
	* @param req           基金转换业务请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int FundTransform(FundTransformReq* req, int request_id) = 0;

	/**
	* 基金分红方式设置请求
	*
	* @param req           基金分红方式设置请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int FundSetBonusType(FundSetBonusTypeReq* req, int request_id) = 0;

	/**
	* 基金分红方式查询请求
	*
	* @param req           基金分红方式查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundBonusType(int request_id) = 0;

	/**
	* 开放式基金当日委托查询请求
	*
	* @param req           基金当日委托查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryOfOrder(QryOfOrderReq* req, int request_id) = 0;

	/**
	* 开放式基金持仓查询请求
	*
	* @param req           开放式基金持仓查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryOfPosition(QryOfPositionReq* req, int request_id) = 0;

	/**
	* 基金确认息查询请求
	*
	* @param req           基金确认息查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundConfirmInfo(QryFundConfirmInfoReq* req, int request_id) = 0;

	/**
	* 基金行情信息查询请求
	*
	* @param req           基金行情信息查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundMarketData(QryFundMarketDataReq* req, int request_id) = 0;

	/**
	* 基金开户请求
	*
	* @param req           基金开户请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int CreatFundAccount(CreatFundAccountReq* req, int request_id) = 0;

	/**
	* 基金账户信息查询请求
	*
	* @param req           基金账户信息查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundAccountInfo(QryFundAccountInfoReq* req, int request_id) = 0;

	/**
    * 新私募债委托处理请求, 同时支持上海新债券协商成交委托请求
    *
    * @param req           委托处理请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int NewPrivatePlacementBondOrder(NewPrivatePlacementBondOrderReq* req, int request_id) = 0;

    /**
    * 新私募债委托撤单请求
    *
    * @param cancel_req    新私募债委托撤单请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int NewPrivatePlacementBondCancelOrder(NewPrivatePlacementBondCancelOrderReq* cancel_req, int request_id) = 0;

    /**
    * 新私募债可撤委托查询请求
    *
    * @param req           新私募债可撤委托查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryNewPrivateBondAviCancelOrder(QryNewPrivateBondAviCancelOrderReq* req, int request_id) = 0;

    /**
    * 固收委托查询请求
    *
    * @param req           固收委托查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySolidChargeOrder(QrySolidChargeOrderReq* req, int request_id) = 0;

	/**
	* 报价行情查询请求
	*
	* @param req           报价行情查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryQuotation(QryQuotationReq* req, int request_id) = 0;

	/**
	* 协议回购委托查询（沪深）
	*
	* @param req           协议回购委托查询（沪深）
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryNegotiatedRepurchaseOrder(QryNegotiatedRepurchaseOrderReq* req, int request_id) = 0;

	/**
	* 协议回购交易员查询
	*
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryNegotiatedRepurchaseDealper(int request_id) = 0;

	/**
	* 协议回购委托撤单
	*
	* @param req           协议回购委托撤单
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int NegotiatedRepurchaseOrderCancel(NegotiatedRepurchaseOrderCancelReq* req, int request_id) = 0;

	/**
	* 协议回购确认拒绝
	*
	* @param req           协议回购确认拒绝
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int NegotiatedRepurchaseReject(RejectNegotiatedRepurchaseReq* req, int request_id) = 0;

	/**
	* 客户回购指标查询
	*
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRepurchaseIndex(int request_id) = 0;

	/**
	* 未到期回购合约查询
	*
	* @param req           未到期回购合约查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryUnexpiredRepurchaseContract(QryUnexpiredRepurchaseContractReq* req, int request_id) = 0;

	/**
	* 未到期余额查询
	*
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryContractBuyBackUnexpiredAmt(int request_id) = 0;

	/**
	* 上海交易所未结算协议回购查询
	*
	* @param req           上海交易所未结算协议回购查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryContractBuyBackUnsettledInfo(QryContractBuyBackUnsettledInfoReq* req, int request_id) = 0;

	/**
	* 上海债券协议回购委托,应答OnBondOrderRsp
	*
	* @param req           上海债券协议回购委托
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int NegotiatedRepurchaseOrder(NegotiatedRepurchaseOrderReq* req, int request_id) = 0;

	/**
	* 深圳债券协议回购转发成交请求查询
	*
	* @param req           深圳债券协议回购转发成交请求查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZBondContractBuyBackTransmitTrade(QrySZBondContractBuyBackTransmitTradeReq* req, int request_id) = 0;

	/**
	* 深圳债券协议回购可质押券查询
	*
	* @param req           深圳债券协议回购可质押券查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZBondContractBuyBackPledgeAvailableStk(QrySZBondContractBuyBackPledgeAvailableStkReq* req, int request_id) = 0;

	/**
	* 深圳债券质押交易商信息查询
	*
	* @param req           深圳债券质押交易商信息查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZBondContractBuyBackPledgeMember(QrySZBondContractBuyBackPledgeMemberReq* req, int request_id) = 0;

	/**
	* 深圳债券质押本地未到期回购合约查询
	*
	* @param req           深圳债券质押本地未到期回购合约查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZBondContractBuyBackPledgeUnexpired(QrySZBondContractBuyBackPledgeUnexpiredReq* req, int request_id) = 0;

	/**
	* 深圳债券协议回购质押券查询
	*
	* @param req           深圳债券协议回购质押券查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZBondContractBuyBackPledgeStk(QrySZBondContractBuyBackPledgeStkReq* req, int request_id) = 0;


	/**
	* 深圳债券协议回购委托,应答OnBondOrderRsp
	*
	* @param req           深圳债券协议回购委托
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZNegotiatedRepurchaseOrder(SZNegotiatedRepurchaseOrderReq* req, int request_id) = 0;

	/**
	* 深圳债券协议回购委托撤单,应答OnNegotiatedRepurchaseOrderCancelRsp
	*
	* @param req           深圳债券协议回购委托撤单
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZNegotiatedRepurchaseOrderCancel(NegotiatedRepurchaseOrderCancelReq* req, int request_id) = 0;


	/**
	* 债券质押式回购实际占款天数查询
	*
	* @param req           债券质押式回购实际占款天数查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBondContractBuyBackPledgeOccupyDays(QryBondContractBuyBackPledgeOccupyDays* req, int request_id) = 0;

	/**
	* 客户新标准券查询
	*
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryCustStandardNewBond(int request_id) = 0;
	
	/**
	* 当日逆回购成交查询
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBondReverseTradeList(QryBondReverseTradeListReq* req, int request_id) = 0;
	
	/**
	* 未到期回购查询
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryUnexpiredBondReverseInfo(QryUnexpiredBondReverseInfoReq* req, int request_id) = 0;
	
	/**
    * 债券交易通用委托，目前仅支持债券分销业务，后续迁移其他相关业务。
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int BondOrder(BondOrderReq* req, int request_id, const char* terminal_info) = 0;

	/**
	* 质押存量折算查询
	*
	* @param req           请求明细
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryBondPledgeAvailableDiscount(QryBondPledgeAvailableDiscountReq* req, int request_id) = 0;

	/**
    * 客户总资产明细查询请求，仅柜台类型为1,4,6,8,9时支持实时更新
    *
    * @param req           客户总资产明细查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryTotalAssetDetail(QryTotalAssetDetailReq* req, int request_id) = 0;

	/**
	* 留存业务客户资产总值查询
	*
	* @param req           留存业务客户资产总值查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedTotalAssets(QryRetainedTotalAssetsReq* req, int request_id) = 0;

	/**
	* 留存业务客户资产总值分类查询
	*
	* @param req           留存业务客户资产总值分类查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedTotalAssetsType(QryRetainedTotalAssetsTypeReq* req, int request_id) = 0;

	/**
	*  留存业务， 查询资金账户
	*
	* @param req           留存业务， 查询资金账户
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedFund(QueryRetainedFundReq* req, int request_id) = 0;

	/**
	* 留存业务， 查询持仓列表
	*
	* @param req           留存业务， 查询持仓列表
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedPositionList(QueryRetainedPositionListReq* req, int request_id) = 0;

	/**
	*  留存业务， 查询委托列表
	*
	* @param req            留存业务， 查询委托列表
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedOrderList(QueryRetainedOrderListReq* req, int request_id) = 0;

	/**
	* 留存业务 撤单委托查询
	*
	* @param req           留存业务 撤单委托查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedCancelOrderList(QryRetainedCancelOrderListReq* req, int request_id) = 0;

	/**
	* 留存业务 当日分笔成交查询
	*
	* @param req           留存业务 当日分笔成交查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedTradeList(QryRetainedTradeListReq* req, int request_id) = 0;

	/**
	* 留存业务 当日汇总成交查询
	*
	* @param req           留存业务 当日汇总成交查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryRetainedTradeListTotal(QryRetainedTradeListTotalReq* req, int request_id) = 0;

	/**
	* 新股中签扣款顺序查询请求
	*
	* @param req           新股中签扣款顺序查询请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryIPOLotteryDeductSeq(QryIPOLotteryDeductSeqReq* req, int request_id) = 0;

	/**
	* 新股中签扣款顺序设置请求
	*
	* @param req           新股中签扣款顺序设置请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SetIPOLotteryDeductSeq(SetIPOLotteryDeductSeqReq* req, int request_id) = 0;

	/**
	* 中签资金冻结后放弃认购请求
	*
	* @param req           中签资金冻结后放弃认购请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int IPOLotteryAbandon(IPOLotteryAbandonReq* req, int request_id) = 0;

	/**
	* 港股通投票请求
	*
	* @param req           港股通投票请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int HKStockVote(HKStockVoteReq* req, int request_id) = 0;

	/**
    * 深圳固收债券报价申报委托请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondQuotationOrder(SZBondQuotationOrderReq* req, int request_id) = 0;

	/**
    * 深圳固收债券报价回复申报委托请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondQuotationReplyOrder(SZBondQuotationReplyOrderReq* req, int request_id) = 0;

	/**
    * 深圳固收债券询价请求申报委托请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondInquiryOrder(SZBondInquiryOrderReq* req, int request_id) = 0;

	/**
    * 深圳固收债券当日委托查询请求
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondOrder(QuerySZBondOrderReq* req, int request_id) = 0;
    
	/**
    * 深圳固收当日委托扩展信息查询请求
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondOrderExtendInfo(QuerySZBondOrderExtendInfoReq* req, int request_id) = 0;

	/**
    * 深圳固收债券历史委托查询请求
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondHisOrder(QuerySZBondHisOrderReq* req, int request_id) = 0;

	/**
    * 深圳固收市场竞买预约信息查询请求
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondMarketBidAppointment(QuerySZBondMarketBidAppointmentReq* req, int request_id) = 0;

	/**
    * 深圳固收客户竞买预约信息查询请求
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondCustomerBidAppointment(QuerySZBondCustomerBidAppointmentReq* req, int request_id) = 0;


	/**
    * 深圳固收债券-历史成交明细查询请求
    *
    * @param req           历史成交明细查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryBondHistoryTradingDetails(QueryBondHistoryTradingDetailsReq* req, int request_id) = 0;

	/**
    * 深圳固收债券-申报委托撤单请求
    *
    * @param req           申报委托撤单请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondOrderCancel(SZBondOrderCancelReq* req, int request_id) = 0;

	/**
    * 深圳固收债券-转发询价查询请求
    *
    * @param req           转发询价查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondForwardInquiry(QuerySZBondForwardInquiryReq* req, int request_id) = 0;

	/**
    * 深圳固收债券-转发报价查询请求
    *
    * @param req           转发报价查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondForwardQuotation(QuerySZBondForwardQuotationReq* req, int request_id) = 0;

	/**
    * 深圳固收债券-点击成交逐笔委托行情查询请求
    *
    * @param req           点击成交逐笔委托行情查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondPerOrderInfoOfClickDeal(QuerySZBondPerOrderInfoOfClickDealReq* req, int request_id) = 0;

	/**
    * 深圳固收债券-交易业务参考信息查询请求
    *
    * @param req           交易业务参考信息查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondTradingBusinessReferenceInfo(QuerySZBondTradingBusinessReferenceInfoReq* req, int request_id) = 0;


    /**
    * 深圳固收债券协商成交申报请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondNegotiatedTradeOrder(SZBondNegotiatedTradeOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 深圳固收债券竞买成交出价委托请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondAuctionsTradeSendOrder(SZBondAuctionsTradeSendOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 深圳固收债券竞买成交应价委托请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondAuctionsTradeReplyOrder(SZBondAuctionsTradeReplyOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 深圳固收债券回售转售申报请求, 应答OnBondOrderRsp 
    *
    * @param req           请求明细
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SZBondPutBackResaleOrder(SZBondPutBackResaleOrderReq* req, int request_id) = 0;

    /**
    * 固收债券历史委托扩展信息查询请求
    *
    * @param req           请求详细信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryBondHisOrderExtInfo(QryBondHisOrderExtInfoReq* req, int request_id) = 0;

    /**
    * 深圳固收债券协商成交申报查询请求
    *
    * @param req           请求详细信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondNegotiatedTradeOrder(QrySZBondNegotiatedTradeOrderReq* req, int request_id) = 0;

    /**
    * 深圳固收债券当日成交明细查询请求
    *
    * @param req           请求详细信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondTradeList(QrySZBondTradeListReq* req, int request_id) = 0;

    /**
    * 固收债券竞买成交历史预约信息查询请求
    *
    * @param req           请求详细信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryBondAuctionsTradeHisAppointment(QryBondAuctionsTradeHisAppointmentReq* req, int request_id) = 0;

    /**
    * 深圳固收债券竞买成交逐笔应价行情查询请求
    *
    * @param req           请求详细信息
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZBondAuctionsTradeBidMarketOrder(QrySZBondAuctionsTradeBidMarketOrderReq* req, int request_id) = 0;

    /**
    * 客户风险测评信息查询请求
    *
    * @param req           客户风险测评信息查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryCustRiskAssessmentInfo(QryCustRiskAssessmentInfoReq* req, int request_id) = 0;

	
	/**
	* 券池券单查询
	*
	* @param req           券池券单查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QCQueryVoucher(QCQueryVoucherReq* req, int request_id) = 0;

	/**
	* 市场券约券下单请求
	*
	* @param req           市场券约券下单请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QytSubscribeOrder(QytSubscribeOrderReq* req, int request_id) = 0;

    /**
    * 券源通约券委托查询请求
    *
    * @param req           券源通约券委托查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytSubscribeOrderList(QueryQytSubscribeOrderListReq* req, int request_id) = 0;

    /**
    * 券源通约券委托撤单请求
    *
    * @param req           券源通约券委托撤单请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int CancelQytSubscribeOrder(CancelQytSubscribeOrderReq* req, int request_id) = 0;

    /**
    * 券源通约券委托成交查询请求
    *
    * @param req           券源通约券委托成交查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytSubscribeTradeList(QueryQytSubscribeTradeListReq* req, int request_id) = 0;

	/**
	* 券单汇总查询
	*
	* @param req           券单汇总查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
    virtual int QCQueryVoucherSummary(QCQueryVoucherSummaryReq* req, int request_id) = 0;
    /**
    * 券源通展期前置判断请求
    *
    * @param req           券源通展期前置判断请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytExtensionPreJudge(QytExtensionPreJudgeReq* req, int request_id) = 0;

    /**
    * 券源通展期申请委托请求
    *
    * @param req           券源通展期申请委托请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytExtensionOrder(QytExtensionOrderReq* req, int request_id) = 0;

    /**
    * 券源通展期申请查询请求
    *
    * @param req           券源通展期申请查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytExtensionOrderList(QryQytExtensionOrderListReq* req, int request_id) = 0;

    /**
    * 券源通展期申请撤销请求
    *
    * @param req           券源通展期申请撤销请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int CancelQytExtensionOrder(CancelQytExtensionOrderReq* req, int request_id) = 0;
 
	/**
	* 券池查询约券合约请求
	*
	* @param req           约券合约查询
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
    virtual int QCQueryAppointmentContract(QCQueryAppointmentContractReq* req, int request_id) = 0;

    /**
    * 券池查询客户合约定价信息请求 (数据更新频率为每日更新一次)
    *
    * @param req           查询客户合约定价信息请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QCQueryCustContractPriceInfo(QCQueryCustContractPriceInfoReq* req, int request_id) = 0;
	
	/**
	* 券源通预告申报请求
	*
	* @param req           券源通预告申报请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QytForecastOrder(QytForecastOrderReq* req, int request_id) = 0;

	/**
	* 券源通定向申报请求
	*
	* @param req           券源通定向申报请求
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QytDirectOrder(QytDirectOrderReq* req, int request_id) = 0;

    /**
    * 券源通标准篮子申报请求
    *
    * @param req           券源通标准篮子申报请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytBasketOrder(QytBasketOrderReq* req, int request_id) = 0;

    /**
    * 券源通篮子申报撤单请求
    *
    * @param req           券源通篮子申报撤单请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int CancelQytBasketOrder(CancelQytBasketOrderReq* req, int request_id) = 0;

    /**
    * 券源通篮子申报查询请求
    *
    * @param req           券源通篮子申报查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytBasketOrder(QueryQytBasketOrderReq* req, int request_id) = 0;

    /**
    * 券源通标准篮子申报详情请求
    *
    * @param req           券源通标准篮子申报详情请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytBasketOrderDetail(QueryQytBasketOrderDetailReq* req, int request_id) = 0;

    /**
    * 券源通定制篮子申报详情请求
    *
    * @param req           券源通定制篮子申报详情请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytCustBasketOrderDetail(QueryQytCustBasketOrderDetailReq* req, int request_id) = 0;

    /**
     * 资产总值分类查询请求
     *
     * @param qry_req       资产总值分类查询的请求数据
     * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
     *
     * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
     */
    virtual int QueryTotalFundAssetDetail(QryTotalFundAssetDetailReq* req, int request_id) = 0;

	/**
	* 基金确认信息查询请求
	*
	* @param req           基金确认信息查询请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundConfirmInfoJZ(QueryFundConfirmInfoReq* req, int request_id) = 0;

	/**
	* 外围基金交收信息查询请求
	*
	* @param req           请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundSettleMent(QueryFundSettleMentReq* req, int request_id) = 0;

	/**
	* 基金历史交易查询请求
	*
	* @param req           请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QueryFundHisTransac(QueryFundHisTransacReq* req, int request_id) = 0;

	/**
	* 基金产品风险揭示书签署请求
	*
	* @param req           请求数据
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SignFundRiskGgreement(SignFundRiskGgreementReq* req, int request_id) = 0;

    /**
    * 资金横向划转请求
    *
    * @param req           资金横向划转请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int LateralTransferOrder(LateralTransferOrderReq* req, int request_id) = 0;

    /**
    * 查询横向划转流水请求
    *
    * @param req           查询横向划转流水请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryLateralTransferFlow(QueryLateralTransferFlowReq* req, int request_id) = 0;

    /**
    * 券源通意向登记请求
    *
    * @param req           券源通意向登记请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytIntenRegistra(QytIntenRegistraReq* req, int request_id) = 0;
    
    /**
    * 券源通查询意向登记请求
    *
    * @param req           券源通查询意向登记请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
	virtual int QytQueryIntenRegistra(QytQueryIntenRegistraReq* req, int request_id) = 0;

    /**
    * 券源通提前了结前置判断请求
    *
    * @param req           券源通提前了结前置判断请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytSettleEarlyPreJudge(QytSettleEarlyPreJudgeReq* req, int request_id) = 0;

    /**
    * 券源通提前了结申请请求
    *
    * @param req           券源通提前了结申请请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QytSettleEarlyOrder(QytSettleEarlyOrderReq* req, int request_id) = 0;

    /**
    * 券源通提前了结查询请求
    *
    * @param req           券源通提前了结查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQytSettleEarlyOrders(QryQytSettleEarlyOrdersReq* req, int request_id) = 0;

    /**
    * 券源通提前了结撤单请求
    *
    * @param req           券源通提前了结撤单请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int CancelQytSettleEarlyOrder(CancelQytSettleEarlyOrderReq* req, int request_id) = 0;

	/**
	* 深圳报价回购合约查询请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZQuoteRepoContract(QrySZQuoteRepoContractReq* req, int request_id) = 0;

	/**
	* 深圳报价回购委托请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZQuoteRepoOrder(SZQuoteRepoOrderReq* req, int request_id) = 0;

	/**
	* 深圳报价回购不再续做请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZQuoteRepoNoContinue(SZQuoteRepoNoContinueReq* req, int request_id) = 0;

	/**
	* 深圳报价回购提前购回委托请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZQuoteRepoEarlyRepurchaseOrder(SZQuoteRepoEarlyRepurchaseOrderReq* req, int request_id) = 0;

	/**
	* 深圳报价回购提前购回预约请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int SZQuoteRepoEarlyRepurchaseBook(SZQuoteRepoEarlyRepurchaseBookReq* req, int request_id) = 0;

	/**
	* 深圳报价回购合约不再续做查询请求
	*
	* @param req           请求参数
	* @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
	*
	* @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
	*/
	virtual int QuerySZQuoteRepoNoContinueContract(QrySZQuoteRepoNoContinueContractReq* req, int request_id) = 0;

   /**
    * 报价回购利率额度查询请求
    *
    * @param req           报价回购利率额度查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryQuoteRepoInteRateLimit(QryQuoteRepoInteRateLimitReq* req, int request_id) = 0;

   /**
    * 深圳报价回购产品信息查询请求
    *
    * @param req           深圳报价回购产品信息查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZQuoteRepoProdInfo(QrySZQuoteRepoProdInfoReq* req, int request_id) = 0;

   /**
    * 深圳报价回购委托查询请求
    *
    * @param req           深圳报价回购委托查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySZQuoteRepoOrders(QrySZQuoteRepoOrdersReq* req, int request_id) = 0;

    /**
    * 上海报价回购委托
    *
    * @param req           上海报价回购委托请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SHQuoteRepoOrder(SHQuoteRepoOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 上海报价回购不再续做
    *
    * @param req           上海报价回购不再续做请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SHQuoteRepoNoContinue(SHQuoteRepoNoContinueReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 上海报价回购提前购回委托
    *
    * @param req           上海报价回购提前购回委托请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SHQuoteRepoEarlyRepurchaseOrder(SHQuoteRepoEarlyRepurchaseOrderReq* req, int request_id, const char* terminal_info) = 0;

    /**
    * 上海报价回购提前购回预约
    *
    * @param req           上海报价回购提前购回预约请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    * @param terminal_info 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int SHQuoteRepoEarlyRepurchaseBook(SHQuoteRepoEarlyRepurchaseBookReq* req, int request_id, const char* terminal_info) = 0;

   /**
    * 上海报价回购合约查询请求
    *
    * @param req           上海报价回购合约查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySHQuoteRepoContract(QrySHQuoteRepoContractReq* req, int request_id) = 0;

   /**
    * 上海报价回购业务查询请求
    *
    * @param req           上海报价回购业务查询请求参数
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QuerySHQuoteRepoBusiness(QrySHQuoteRepoBusinessReq* req, int request_id) = 0;

   /**
    * 股转发行证券信息查询请求
    *
    * @param req           股转发行证券信息查询请求
    * @param request_id    请求序列号，用于匹配响应，由用户自定义，非0
    *
    * @return              成功返回0，失败返回错误码，通过GetApiLastError获取错误信息
    */
    virtual int QueryNEEQIPOStock(QueryNEEQIPOStockReq* req, int request_id) = 0;

    
};

}  // namespace HFT

#endif  // _HFT_EXT_TRADER_API_H_
