void onDisconnect() override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onDisconnect);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onError(const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onError, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRiskNotify(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRiskNotify, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFailBackNotify(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFailBackNotify, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onLogin(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onLogin, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTradeReport(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTradeReport, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOrderStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOrderStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOrderRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOrderRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTradeRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTradeRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPositionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPositionRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCashRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCashRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryJZJYAvailFundRsp, avail_balance, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTransferFundInAndOutRsp(int64_t transfer_value, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTransferFundInAndOutRsp, transfer_value, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTransferFundBetweenSecuidRsp(int64_t transfer_value, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTransferFundBetweenSecuidRsp, transfer_value, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETFRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETFRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETFStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETFStockRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMaxOrderQtyRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMaxOrderQtyRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOMaxPurchaseRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOMaxPurchaseRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOStockRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQuerySecurityBaseInfoRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQuerySecurityBaseInfoRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditMortgageInOutRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditMortgageInOutRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditStockBackRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditStockBackRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditPayBackRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditPayBackRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditPayBackByOrderRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditPayBackByOrderRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditStockRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditMortgageHoldRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditMortgageHoldRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditAssetsRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetsRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditFinanceRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFinanceRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditShortsellRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditShortsellRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditRepayAmountRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditRepayAmountRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditRepayStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditRepayStockRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditSecuritySellQtyRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditSecuritySellQtyRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQuerySecuidRightRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQuerySecuidRightRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKRateRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKRateRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKStockRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKStockRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKFundRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKFundRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKMinPriceUnitRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKMinPriceUnitRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKTradeCalendarRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKTradeCalendarRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryLockSecurityDetailRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryLockSecurityDetailRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTransferFundHistoryRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTransferFundHistoryRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDebtsFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsFlowRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditAssetFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetFlowRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDebtsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onMicroServiceRsp(const dict &data, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onMicroServiceRsp, data, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryBankBalanceRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryBankBalanceRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryBankInfoRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryBankInfoRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onBankSecTransferRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onBankSecTransferRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryBankSecTransferRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryBankSecTransferRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHisBankSecTransferRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHisBankSecTransferRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFundAccountTransferRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFundAccountTransferRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryFundAccountTransferRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryFundAccountTransferRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHisOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHisOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHisTradeRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHisTradeRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryDeliveryOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryDeliveryOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryStateOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryStateOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryExchangeListsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryExchangeListsRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onModifyPasswordRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onModifyPasswordRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPHXXRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPHXXRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryZQXXRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryZQXXRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryLockSecurityContractRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryLockSecurityContractRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditContractRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditContractRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDebtsCollectRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsCollectRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDataRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDataRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPreMaturityDebtsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPreMaturityDebtsRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onExtendPreMaturityDebtsRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onExtendPreMaturityDebtsRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPreMaturityDebtsExtensionRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPreMaturityDebtsExtensionRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryVoteProposalRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryVoteProposalRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditVoteCountRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditVoteCountRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditVoteRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditVoteRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryNetVoteRightsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteRightsRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryNetVoteResultRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteResultRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryNetVoteCountRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteCountRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryStkConcentrationRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryStkConcentrationRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryHKHisOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryHKHisOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryWithdrawCashRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryWithdrawCashRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryNetVoteOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTradeTotalRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTradeTotalRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onETFSubscriptCancelRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onETFSubscriptCancelRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onNetVoteOrderRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onNetVoteOrderRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditNetVoteOrderRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditNetVoteOrderRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMSCashRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMSCashRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMSPositionsRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMSPositionsRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMSCreditDebtsFlowRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMSCreditDebtsFlowRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

