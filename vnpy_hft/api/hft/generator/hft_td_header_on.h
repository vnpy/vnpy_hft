virtual void onDisconnect() {};

virtual void onError(const dict &error, int request_id) {};

virtual void onRiskNotify(const dict &data) {};

virtual void onFailBackNotify(const dict &data) {};

virtual void onLogin(const dict &data, const dict &error) {};

virtual void onTradeReport(const dict &data) {};

virtual void onOrderStatus(const dict &data) {};

virtual void onOrderRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onCancelRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryTradeRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryPositionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCashRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict &error, int request_id) {};

virtual void onTransferFundInAndOutRsp(int64_t transfer_value, const dict &error, int request_id) {};

virtual void onTransferFundBetweenSecuidRsp(int64_t transfer_value, const dict &error, int request_id) {};

virtual void onQueryETFRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryETFStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryMaxOrderQtyRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryIPOMaxPurchaseRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryIPOStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQuerySecurityBaseInfoRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onCreditMortgageInOutRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCreditStockBackRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCreditPayBackRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCreditPayBackByOrderRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCreditStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditMortgageHoldRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditAssetsRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCreditFinanceRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditShortsellRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditRepayAmountRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCreditRepayStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditSecuritySellQtyRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQuerySecuidRightRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryHKRateRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryHKStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryHKFundRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryHKMinPriceUnitRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryHKTradeCalendarRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryLockSecurityDetailRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryTransferFundHistoryRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryCreditDebtsFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditAssetFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditDebtsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onMicroServiceRsp(const dict &data, int request_id) {};

virtual void onQueryBankBalanceRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryBankInfoRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onBankSecTransferRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryBankSecTransferRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryHisBankSecTransferRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onFundAccountTransferRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryFundAccountTransferRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryHisOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryHisTradeRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryDeliveryOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryStateOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryExchangeListsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onModifyPasswordRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryPHXXRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryZQXXRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryLockSecurityContractRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditContractRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCreditDebtsCollectRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCreditDataRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryPreMaturityDebtsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onExtendPreMaturityDebtsRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryPreMaturityDebtsExtensionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryVoteProposalRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryCreditVoteCountRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCreditVoteRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryNetVoteRightsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryNetVoteResultRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryNetVoteCountRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryStkConcentrationRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryHKHisOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryWithdrawCashRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryNetVoteOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryTradeTotalRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onETFSubscriptCancelRsp(const dict &data, const dict &error, int request_id) {};

virtual void onNetVoteOrderRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCreditNetVoteOrderRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryMSCashRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryMSPositionsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryMSCreditDebtsFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

