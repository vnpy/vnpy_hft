int login(const dict &req);

int getCounterType();

int getSecuidInfo(const dict &req, int count);

int getApiLocalAddr(const dict &req);

int order(const dict &req, int request_id);

int batchOrder(const dict &req, int count, int request_id);

int cancelOrder(const dict &req, int request_id);

int batchCancelOrder(const dict &req, int count, int request_id);

int exercise(const dict &req, int request_id);

int cancelExercise(const dict &req, int request_id);

int queryOrder(const dict &req, int request_id);

int queryOrderByCode(const dict &req, int request_id);

int queryOrders(const dict &req, int request_id);

int queryTradeByCode(const dict &req, int request_id);

int queryTrades(const dict &req, int request_id);

int queryPosition(const dict &req, int request_id);

int queryPositions(const dict &req, int request_id);

int queryCash(const dict &req, int request_id);

int queryJZJYAvailFund(int request_id);

int transferFundInAndOut(const dict &req, int request_id);

int queryExercise(string order_id, int request_id);

int queryExercises(const dict &req, int request_id);

int queryContractInfo(int request_id, string symbol);

int queryStockPositions(int request_id, string symbol);

int transferStock(const dict &req, int request_id);

int queryTransferStocks(int request_id, string symbol, const dict &req);

int lockOrder(const dict &req, int request_id);

int queryLockOrder(string symbol, int request_id);

int queryLockOrders(const dict &req, int request_id);

int queryLockPositions(int request_id, string symbol);

int combOrder(const dict &req, int request_id);

int combExercise(const dict &req, int request_id);

int cancelCombExercise(const dict &req, int request_id);

int queryCombOrder(string order_id, int request_id);

int queryCombOrderByCode(string symbol, int request_id);

int queryCombOrders(const dict &req, int request_id);

int queryCombExercise(string order_id, int request_id);

int queryCombExercises(const dict &req, int request_id);

int queryCombPositions(int request_id, string symbol, const dict &req);

int queryCombContractInfo(int request_id, string symbol, int comb_strategy);

int queryTransferFundHistory(int request_id);

int queryCombPositionSubDetails(int request_id, string symbol, const dict &req);

int doMicroServiceReq(const dict &req, int request_id);

int queryPositionLimits(int request_id, string symbol);

int queryAmountLimits(const dict &req, int request_id);

int querySplitCombMarginDifference(const dict &req, int request_id);

int queryExerciseAppointment(const dict &req, int request_id);

int queryMarginRisk(int request_id);

int queryOptionMaxOrderVolume(const dict &req, int request_id);

int queryInquiryStockPosition(int request_id, string symbol);

int queryOptionOrderHistory(const dict &req, int request_id);

int queryOptionTradeHistory(const dict &req, int request_id);

int queryExerciseAppointmentHistory(const dict &req, int request_id);

int queryOptionDeliveryHistory(const dict &req, int request_id);

int queryExerciseDeliveryHistory(const dict &req, int request_id);

int queryOptionContractAssetHistory(const dict &req, int request_id);

int queryOptionDeliveryNettingHistory(const dict &req, int request_id);

int queryOptionCombPositionHistory(const dict &req, int request_id);

int queryOptionSettlementHistory(const dict &req, int request_id);

int queryOptionCombStrategyFile(const dict &req, int request_id);

