int OptionApi::login(const dict &req)
{
	LoginReq myreq = LoginReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getString(req, "account_pwd", myreq.account_pwd);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "cl_system_id", myreq.cl_system_id);
	getString(req, "svr_ip", myreq.svr_ip);
	getInt(req, "svr_port", &myreq.svr_port);
	getString(req, "terminal_info", myreq.terminal_info);
	getInt16_t(req, "inner_flag", &myreq.inner_flag);
	int i = this->api->Login(&myreq);
	return i;
};

	int i = this->api->getCounterType();
	return i;
};

int OptionApi::getSecuidInfo(const dict &req, int count)
{
	SecuidInfo myreq = SecuidInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "fund_id", myreq.fund_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getChar(req, "account_status", &myreq.account_status);
	getChar(req, "account_class", &myreq.account_class);
	getString(req, "account_rights", myreq.account_rights);
	getChar(req, "account_hgtright", &myreq.account_hgtright);
	int i = this->api->GetSecuidInfo(&myreq, count);
	return i;
};

int OptionApi::getApiLocalAddr(const dict &req)
{
	IpAddr myreq = IpAddr();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ip", myreq.ip);
	getInt(req, "port", &myreq.port);
	int i = this->api->GetApiLocalAddr(&myreq);
	return i;
};

int OptionApi::order(const dict &req, int request_id)
{
	OrderReq myreq = OrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getInt64_t(req, "volume", &myreq.volume);
	getInt64_t(req, "price", &myreq.price);
	getInt16_t(req, "order_flag", &myreq.order_flag);
	getUint16_t(req, "policy_id", &myreq.policy_id);
	getInt16_t(req, "share_property", &myreq.share_property);
	int i = this->api->Order(&myreq, request_id);
	return i;
};

int OptionApi::batchOrder(const dict &req, int count, int request_id)
{
	OrderReq myreq = OrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getInt64_t(req, "volume", &myreq.volume);
	getInt64_t(req, "price", &myreq.price);
	getInt16_t(req, "order_flag", &myreq.order_flag);
	getUint16_t(req, "policy_id", &myreq.policy_id);
	getInt16_t(req, "share_property", &myreq.share_property);
	int i = this->api->BatchOrder(&myreq, count, request_id);
	return i;
};

int OptionApi::cancelOrder(const dict &req, int request_id)
{
	CancelReq myreq = CancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getInt64_t(req, "volume", &myreq.volume);
	getInt64_t(req, "price", &myreq.price);
	int i = this->api->CancelOrder(&myreq, request_id);
	return i;
};

int OptionApi::batchCancelOrder(const dict &req, int count, int request_id)
{
	CancelReq myreq = CancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getInt64_t(req, "volume", &myreq.volume);
	getInt64_t(req, "price", &myreq.price);
	int i = this->api->BatchCancelOrder(&myreq, count, request_id);
	return i;
};

int OptionApi::exercise(const dict &req, int request_id)
{
	ExerciseReq myreq = ExerciseReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt64_t(req, "volume", &myreq.volume);
	getInt16_t(req, "exercise_type", &myreq.exercise_type);
	int i = this->api->Exercise(&myreq, request_id);
	return i;
};

int OptionApi::cancelExercise(const dict &req, int request_id)
{
	CancelExerciseReq myreq = CancelExerciseReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	int i = this->api->CancelExercise(&myreq, request_id);
	return i;
};

int OptionApi::queryOrder(const dict &req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryOrder(&myreq, request_id);
	return i;
};

int OptionApi::queryOrderByCode(const dict &req, int request_id)
{
	QryOrderByCodeReq myreq = QryOrderByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOrderByCode(&myreq, request_id);
	return i;
};

int OptionApi::queryOrders(const dict &req, int request_id)
{
	QryOrdersReq myreq = QryOrdersReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt(req, "query_flag", &myreq.query_flag);
	getString(req, "market", myreq.market);
	int i = this->api->QueryOrders(&myreq, request_id);
	return i;
};

int OptionApi::queryTradeByCode(const dict &req, int request_id)
{
	QryTradeByCodeReq myreq = QryTradeByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryTradeByCode(&myreq, request_id);
	return i;
};

int OptionApi::queryTrades(const dict &req, int request_id)
{
	QryTradesReq myreq = QryTradesReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	getBool(req, "filter_etf", &myreq.filter_etf);
	getString(req, "counter_order_id", myreq.counter_order_id);
	int i = this->api->QueryTrades(&myreq, request_id);
	return i;
};

int OptionApi::queryPosition(const dict &req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPosition(&myreq, request_id);
	return i;
};

int OptionApi::queryPositions(const dict &req, int request_id)
{
	QryPositionsReq myreq = QryPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	int i = this->api->QueryPositions(&myreq, request_id);
	return i;
};

int OptionApi::queryCash(const dict &req, int request_id)
{
	QryCashReq myreq = QryCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryCash(&myreq, request_id);
	return i;
};

int OptionApi::queryJZJYAvailFund(int request_id)
{
	int i = this->api->QueryJZJYAvailFund(request_id);
	return i;
};

int OptionApi::transferFundInAndOut(const dict &req, int request_id)
{
	TransferFundReq myreq = TransferFundReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "transfer_side", &myreq.transfer_side);
	getInt64_t(req, "transfer_value", &myreq.transfer_value);
	getString(req, "market", myreq.market);
	int i = this->api->TransferFundInAndOut(&myreq, request_id);
	return i;
};

int OptionApi::queryExercise(string order_id, int request_id)
{
	int i = this->api->QueryExercise(order_id.c_str(), request_id);
	return i;
};

int OptionApi::queryExercises(const dict &req, int request_id)
{
	QryExercisesReq myreq = QryExercisesReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryExercises(&myreq, request_id);
	return i;
};

int OptionApi::queryContractInfo(int request_id, string symbol)
{
	int i = this->api->QueryContractInfo(request_id, symbol.c_str());
	return i;
};

int OptionApi::queryStockPositions(int request_id, string symbol)
{
	int i = this->api->QueryStockPositions(request_id, symbol.c_str());
	return i;
};

int OptionApi::transferStock(const dict &req, int request_id)
{
	TransferStockReq myreq = TransferStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "transfer_type", &myreq.transfer_type);
	getInt16_t(req, "transfer_side", &myreq.transfer_side);
	getInt64_t(req, "transfer_qty", &myreq.transfer_qty);
	int i = this->api->TransferStock(&myreq, request_id);
	return i;
};

int OptionApi::queryTransferStocks(int request_id, string symbol, int16_t transfer_side)
{
	int i = this->api->QueryTransferStocks(request_id, symbol.c_str(), transfer_side);
	return i;
};

int OptionApi::lockOrder(const dict &req, int request_id)
{
	LockOrderReq myreq = LockOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "lock_type", &myreq.lock_type);
	getInt64_t(req, "volume", &myreq.volume);
	int i = this->api->LockOrder(&myreq, request_id);
	return i;
};

int OptionApi::queryLockOrder(string symbol, int request_id)
{
	int i = this->api->QueryLockOrder(symbol.c_str(), request_id);
	return i;
};

int OptionApi::queryLockOrders(const dict &req, int request_id)
{
	QryLockOrdersReq myreq = QryLockOrdersReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryLockOrders(&myreq, request_id);
	return i;
};

int OptionApi::queryLockPositions(int request_id, string symbol)
{
	int i = this->api->QueryLockPositions(request_id, symbol.c_str());
	return i;
};

int OptionApi::combOrder(const dict &req, int request_id)
{
	CombOrderReq myreq = CombOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "comb_type", &myreq.comb_type);
	getInt16_t(req, "comb_strategy", &myreq.comb_strategy);
	getInt64_t(req, "volume", &myreq.volume);
	getString(req, "exch_comb_id", myreq.exch_comb_id);
	int i = this->api->CombOrder(&myreq, request_id);
	return i;
};

int OptionApi::combExercise(const dict &req, int request_id)
{
	CombExerciseReq myreq = CombExerciseReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "call_symbol", myreq.call_symbol);
	getString(req, "put_symbol", myreq.put_symbol);
	getInt64_t(req, "volume", &myreq.volume);
	int i = this->api->CombExercise(&myreq, request_id);
	return i;
};

int OptionApi::cancelCombExercise(const dict &req, int request_id)
{
	CancelCombExerciseReq myreq = CancelCombExerciseReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	int i = this->api->CancelCombExercise(&myreq, request_id);
	return i;
};

int OptionApi::queryCombOrder(string order_id, int request_id)
{
	int i = this->api->QueryCombOrder(order_id.c_str(), request_id);
	return i;
};

int OptionApi::queryCombOrderByCode(string symbol, int request_id)
{
	int i = this->api->QueryCombOrderByCode(symbol.c_str(), request_id);
	return i;
};

int OptionApi::queryCombOrders(const dict &req, int request_id)
{
	QryCombOrdersReq myreq = QryCombOrdersReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCombOrders(&myreq, request_id);
	return i;
};

int OptionApi::queryCombExercise(string order_id, int request_id)
{
	int i = this->api->QueryCombExercise(order_id.c_str(), request_id);
	return i;
};

int OptionApi::queryCombExercises(const dict &req, int request_id)
{
	QryCombExercisesReq myreq = QryCombExercisesReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCombExercises(&myreq, request_id);
	return i;
};

int OptionApi::queryCombPositions(int request_id, string symbol, int16_t comb_strategy)
{
	int i = this->api->QueryCombPositions(request_id, symbol.c_str(), comb_strategy);
	return i;
};

int OptionApi::queryCombContractInfo(int request_id, string symbol, int comb_strategy)
{
	int i = this->api->QueryCombContractInfo(request_id, symbol.c_str(), comb_strategy);
	return i;
};

int OptionApi::queryTransferFundHistory(int request_id)
{
	int i = this->api->QueryTransferFundHistory(request_id);
	return i;
};

int OptionApi::queryCombPositionSubDetails(int request_id, string symbol, int16_t comb_strategy)
{
	int i = this->api->QueryCombPositionSubDetails(request_id, symbol.c_str(), comb_strategy);
	return i;
};

int OptionApi::doMicroServiceReq(const dict &req, int request_id)
{
	MicroServiceReq myreq = MicroServiceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "function_id", myreq.function_id);
	getString(req, "tar_sys", myreq.tar_sys);
	getString(req, "request_content", myreq.request_content);
	getInt32_t(req, "request_len", &myreq.request_len);
	int i = this->api->DoMicroServiceReq(&myreq, request_id);
	return i;
};

int OptionApi::queryPositionLimits(int request_id, string symbol)
{
	int i = this->api->QueryPositionLimits(request_id, symbol.c_str());
	return i;
};

int OptionApi::queryAmountLimits(const dict &req, int request_id)
{
	QryAmountLimitsReq myreq = QryAmountLimitsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryAmountLimits(&myreq, request_id);
	return i;
};

int OptionApi::querySplitCombMarginDifference(const dict &req, int request_id)
{
	QrySplitCombMarginDiffReq myreq = QrySplitCombMarginDiffReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "contract_id", myreq.contract_id);
	getInt16_t(req, "comb_strategy", &myreq.comb_strategy);
	getInt64_t(req, "volume", &myreq.volume);
	getString(req, "exch_comb_id", myreq.exch_comb_id);
	int i = this->api->QuerySplitCombMarginDifference(&myreq, request_id);
	return i;
};

int OptionApi::queryExerciseAppointment(const dict &req, int request_id)
{
	QryExerciseAppointmentReq myreq = QryExerciseAppointmentReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "contract_id", myreq.contract_id);
	int i = this->api->QueryExerciseAppointment(&myreq, request_id);
	return i;
};

int OptionApi::queryMarginRisk(int request_id)
{
	int i = this->api->QueryMarginRisk(request_id);
	return i;
};

int OptionApi::queryOptionMaxOrderVolume(const dict &req, int request_id)
{
	QryOptionMaxOrderVolumeReq myreq = QryOptionMaxOrderVolumeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "contract_id", myreq.contract_id);
	getInt16_t(req, "side", &myreq.side);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "order_flag", &myreq.order_flag);
	getInt64_t(req, "price", &myreq.price);
	int i = this->api->QueryOptionMaxOrderVolume(&myreq, request_id);
	return i;
};

int OptionApi::queryInquiryStockPosition(int request_id, string symbol)
{
	int i = this->api->QueryInquiryStockPosition(request_id, symbol.c_str());
	return i;
};

int OptionApi::queryOptionOrderHistory(const dict &req, int request_id)
{
	QryOptionHisOrderReq myreq = QryOptionHisOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionOrderHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionTradeHistory(const dict &req, int request_id)
{
	QryOptionHisTradeReq myreq = QryOptionHisTradeReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionTradeHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryExerciseAppointmentHistory(const dict &req, int request_id)
{
	QryHisExerciseAppointmentReq myreq = QryHisExerciseAppointmentReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt16_t(req, "currency_type", &myreq.currency_type);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryExerciseAppointmentHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionDeliveryHistory(const dict &req, int request_id)
{
	QryOptionHisDeliveryReq myreq = QryOptionHisDeliveryReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionDeliveryHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryExerciseDeliveryHistory(const dict &req, int request_id)
{
	QryHisExerciseDeliveryReq myreq = QryHisExerciseDeliveryReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryExerciseDeliveryHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionContractAssetHistory(const dict &req, int request_id)
{
	QryOptionHisContractAssetReq myreq = QryOptionHisContractAssetReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionContractAssetHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionDeliveryNettingHistory(const dict &req, int request_id)
{
	QryOptionHisDeliveryNettingReq myreq = QryOptionHisDeliveryNettingReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	int i = this->api->QueryOptionDeliveryNettingHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionCombPositionHistory(const dict &req, int request_id)
{
	QryOptionHisCombPositionReq myreq = QryOptionHisCombPositionReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionCombPositionHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionSettlementHistory(const dict &req, int request_id)
{
	QryOptionHisSettlementReq myreq = QryOptionHisSettlementReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOptionSettlementHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionCombStrategyFile(const dict &req, int request_id)
{
	QryOptionCombStrategyFileReq myreq = QryOptionCombStrategyFileReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getInt16_t(req, "comb_strategy", &myreq.comb_strategy);
	int i = this->api->QueryOptionCombStrategyFile(&myreq, request_id);
	return i;
};

