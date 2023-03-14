void onDisconnect() override
{
	try
	{
		PYBIND11_OVERLOAD(void, OptionApi, onDisconnect);
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
		PYBIND11_OVERLOAD(void, OptionApi, onError, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onRiskNotify, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onFailBackNotify, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onLogin, data, error);
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
		PYBIND11_OVERLOAD(void, OptionApi, onTradeReport, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onOrderStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onOrderRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCancelRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOrderRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryTradeRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryPositionRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCashRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryJZJYAvailFundRsp, avail_balance, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onTransferFundInAndOutRsp, transfer_value, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onExerciseRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCancelExerciseRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onExerciseStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryContractInfoRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryStockPositionRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onTransferStockStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onTransferStockRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryTransferStockRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onLockOrderStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onLockOrderRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryLockOrderRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryLockPositionRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCombOrderStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCombOrderRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCombExerciseStatus, data);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCombExerciseRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onCancelCombExerciseRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCombOrderRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCombExerciseRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCombPositionRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCombContractInfoRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryTransferFundHistoryRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryCombPositionSubDetailRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onMicroServiceRsp, data, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryPositionLimitsRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryAmountLimitsRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQuerySplitCombMarginDifferenceRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseAppointmentRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryMarginRiskRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionMaxOrderVolumeRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryInquiryStockPositionRsp, data, error, request_id);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionOrderHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionTradeHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseAppointmentHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionDeliveryHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseDeliveryHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionContractAssetHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionDeliveryNettingHistoryRsp, data, error, request_id, last);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionCombPositionHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionSettlementHistoryRsp, data, error, request_id, last, pos_str);
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
		PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionCombStrategyFileRsp, data, error, request_id, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

