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

void onQueryPositionRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPositionRsp, data, error, request_id, last);
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

void onExerciseRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onExerciseRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelExerciseRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelExerciseRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onExerciseStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onExerciseStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryExerciseRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryExerciseRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryContractInfoRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryContractInfoRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryStockPositionRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryStockPositionRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTransferStockStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTransferStockStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTransferStockRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTransferStockRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTransferStockRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTransferStockRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onLockOrderStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onLockOrderStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onLockOrderRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onLockOrderRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryLockOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryLockOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryLockPositionRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryLockPositionRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCombOrderStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCombOrderStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCombOrderRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCombOrderRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCombExerciseStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCombExerciseStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCombExerciseRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCombExerciseRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelCombExerciseRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelCombExerciseRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCombOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCombOrderRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCombExerciseRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCombExerciseRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCombPositionRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCombPositionRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCombContractInfoRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCombContractInfoRsp, data, error, request_id, last);
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

void onQueryCombPositionSubDetailRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCombPositionSubDetailRsp, data, error, request_id, last);
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

void onQueryPositionLimitsRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPositionLimitsRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryAmountLimitsRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryAmountLimitsRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQuerySplitCombMarginDifferenceRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQuerySplitCombMarginDifferenceRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryExerciseAppointmentRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryExerciseAppointmentRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMarginRiskRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMarginRiskRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionMaxOrderVolumeRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionMaxOrderVolumeRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryInquiryStockPositionRsp(const dict &data, const dict &error, int request_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryInquiryStockPositionRsp, data, error, request_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionOrderHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionOrderHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionTradeHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionTradeHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryExerciseAppointmentHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryExerciseAppointmentHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionDeliveryHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionDeliveryHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryExerciseDeliveryHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryExerciseDeliveryHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionContractAssetHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionContractAssetHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionDeliveryNettingHistoryRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionDeliveryNettingHistoryRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombPositionHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombPositionHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionSettlementHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionSettlementHistoryRsp, data, error, request_id, last, pos_str);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombStrategyFileRsp(const dict &data, const dict &error, int request_id, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombStrategyFileRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

