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

virtual void onQueryPositionRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryCashRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict &error, int request_id) {};

virtual void onTransferFundInAndOutRsp(int64_t transfer_value, const dict &error, int request_id) {};

virtual void onExerciseRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCancelExerciseRsp(const dict &data, const dict &error, int request_id) {};

virtual void onExerciseStatus(const dict &data) {};

virtual void onQueryExerciseRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryContractInfoRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryStockPositionRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onTransferStockStatus(const dict &data) {};

virtual void onTransferStockRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryTransferStockRsp(const dict &data, const dict &error, int request_id) {};

virtual void onLockOrderStatus(const dict &data) {};

virtual void onLockOrderRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryLockOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryLockPositionRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onCombOrderStatus(const dict &data) {};

virtual void onCombOrderRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onCombExerciseStatus(const dict &data) {};

virtual void onCombExerciseRsp(const dict &data, const dict &error, int request_id) {};

virtual void onCancelCombExerciseRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryCombOrderRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCombExerciseRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryCombPositionRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryCombContractInfoRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryTransferFundHistoryRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryCombPositionSubDetailRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onMicroServiceRsp(const dict &data, int request_id) {};

virtual void onQueryPositionLimitsRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryAmountLimitsRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQuerySplitCombMarginDifferenceRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryExerciseAppointmentRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryMarginRiskRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryOptionMaxOrderVolumeRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryInquiryStockPositionRsp(const dict &data, const dict &error, int request_id) {};

virtual void onQueryOptionOrderHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionTradeHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryExerciseAppointmentHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionDeliveryHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryExerciseDeliveryHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionContractAssetHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionDeliveryNettingHistoryRsp(const dict &data, const dict &error, int request_id, bool last) {};

virtual void onQueryOptionCombPositionHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionSettlementHistoryRsp(const dict &data, const dict &error, int request_id, bool last, string pos_str) {};

virtual void onQueryOptionCombStrategyFileRsp(const dict &data, const dict &error, int request_id, bool last) {};

