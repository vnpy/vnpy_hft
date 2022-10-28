int TdApi::login(string svr_ip, int svr_port, const dict &req, string terminal_info)
{
	AccountInfo myreq = AccountInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getString(req, "account_pwd", myreq.account_pwd);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "cl_system_id", myreq.cl_system_id);
	int i = this->api->Login(svr_ip.c_str(), svr_port, &myreq, terminal_info.c_str());
	return i;
};

	int i = this->api->getCounterType();
	return i;
};

int TdApi::getSecuidInfo(const dict &req, int count)
{
	SecuidInfo myreq = SecuidInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "fund_id", myreq.fund_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getChar(req, "account_status", &myreq.account_status);
	getChar(req, "account_class", &myreq.account_class);
	int i = this->api->GetSecuidInfo(&myreq, count);
	return i;
};

int TdApi::getAllSecuidInfo(const dict &req, int count)
{
	SecuidInfo myreq = SecuidInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "fund_id", myreq.fund_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getChar(req, "account_status", &myreq.account_status);
	getChar(req, "account_class", &myreq.account_class);
	int i = this->api->GetAllSecuidInfo(&myreq, count);
	return i;
};

int TdApi::getApiLocalAddr(const dict &req)
{
	IpAddr myreq = IpAddr();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ip", myreq.ip);
	getInt(req, "port", &myreq.port);
	int i = this->api->GetApiLocalAddr(&myreq);
	return i;
};

int TdApi::order(const dict &req, int request_id)
{
	OrderReq myreq = OrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "volume", &myreq.volume);
	getLonglong(req, "price", &myreq.price);
	getInt16_t(req, "order_flag", &myreq.order_flag);
	getUint16_t(req, "policy_id", &myreq.policy_id);
	getInt16_t(req, "share_property", &myreq.share_property);
	int i = this->api->Order(&myreq, request_id);
	return i;
};

int TdApi::batchOrder(const dict &req, int count, int request_id)
{
	OrderReq myreq = OrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "volume", &myreq.volume);
	getLonglong(req, "price", &myreq.price);
	getInt16_t(req, "order_flag", &myreq.order_flag);
	getUint16_t(req, "policy_id", &myreq.policy_id);
	getInt16_t(req, "share_property", &myreq.share_property);
	int i = this->api->BatchOrder(&myreq, count, request_id);
	return i;
};

int TdApi::cancelOrder(const dict &req, int request_id)
{
	CancelReq myreq = CancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "volume", &myreq.volume);
	getLonglong(req, "price", &myreq.price);
	int i = this->api->CancelOrder(&myreq, request_id);
	return i;
};

int TdApi::batchCancelOrder(const dict &req, int count, int request_id)
{
	CancelReq myreq = CancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "volume", &myreq.volume);
	getLonglong(req, "price", &myreq.price);
	int i = this->api->BatchCancelOrder(&myreq, count, request_id);
	return i;
};

int TdApi::batchCancelAllOrder(const dict &req, int request_id)
{
	BatchCancelAllReq myreq = BatchCancelAllReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cust_id", myreq.cust_id);
	getString(req, "secu_id", myreq.secu_id);
	getString(req, "symbol", myreq.symbol);
	getInt32_t(req, "market", &myreq.market);
	int i = this->api->BatchCancelAllOrder(&myreq, request_id);
	return i;
};

int TdApi::queryOrder(const dict &req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryOrder(&myreq, request_id);
	return i;
};

int TdApi::queryOrderByCode(const dict &req, int request_id)
{
	QryOrderByCodeReq myreq = QryOrderByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOrderByCode(&myreq, request_id);
	return i;
};

int TdApi::queryOrders(const dict &req, int request_id)
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

int TdApi::queryTradeByOrderId(const dict &req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryTradeByOrderId(&myreq, request_id);
	return i;
};

int TdApi::queryTradeByCode(const dict &req, int request_id)
{
	QryTradeByCodeReq myreq = QryTradeByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryTradeByCode(&myreq, request_id);
	return i;
};

int TdApi::queryTrades(const dict &req, int request_id)
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

int TdApi::queryETFTrades(const dict &req, int request_id)
{
	QryETFTradesReq myreq = QryETFTradesReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	getString(req, "counter_order_id", myreq.counter_order_id);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryETFTrades(&myreq, request_id);
	return i;
};

int TdApi::queryPosition(const dict &req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPosition(&myreq, request_id);
	return i;
};

int TdApi::queryPositions(const dict &req, int request_id)
{
	QryPositionsReq myreq = QryPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	int i = this->api->QueryPositions(&myreq, request_id);
	return i;
};

int TdApi::queryCash(const dict &req, int request_id)
{
	QryCashReq myreq = QryCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryCash(&myreq, request_id);
	return i;
};

int TdApi::queryJZJYAvailFund(int request_id)
{
	int i = this->api->QueryJZJYAvailFund(request_id);
	return i;
};

int TdApi::transferFundInAndOut(const dict &req, int request_id)
{
	TransferFundReq myreq = TransferFundReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "transfer_side", &myreq.transfer_side);
	getLonglong(req, "transfer_value", &myreq.transfer_value);
	getString(req, "market", myreq.market);
	int i = this->api->TransferFundInAndOut(&myreq, request_id);
	return i;
};

int TdApi::transferFundBetweenSecuid(const dict &req, int request_id)
{
	TransferFundSecuidReq myreq = TransferFundSecuidReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "fund_out_market", myreq.fund_out_market);
	getString(req, "fund_in_market", myreq.fund_in_market);
	getLonglong(req, "transfer_value", &myreq.transfer_value);
	int i = this->api->TransferFundBetweenSecuid(&myreq, request_id);
	return i;
};

int TdApi::queryETFs(const dict &req, int request_id)
{
	QryETFsReq myreq = QryETFsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryETFs(&myreq, request_id);
	return i;
};

int TdApi::queryETFStocks(const dict &req, int request_id)
{
	QryETFStocksReq myreq = QryETFStocksReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "first_symbol", myreq.first_symbol);
	getInt(req, "sz_ksc_type", &myreq.sz_ksc_type);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryETFStocks(&myreq, request_id);
	return i;
};

int TdApi::queryMaxOrderQty(const dict &req, int request_id)
{
	QryMaxOrderQtyReq myreq = QryMaxOrderQtyReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "price", &myreq.price);
	int i = this->api->QueryMaxOrderQty(&myreq, request_id);
	return i;
};

int TdApi::queryIPOMaxPurchase(int request_id)
{
	int i = this->api->QueryIPOMaxPurchase(request_id);
	return i;
};

int TdApi::queryIPOStock(const dict &req, int request_id)
{
	QueryIPOStockReq myreq = QueryIPOStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt16_t(req, "query_flag", &myreq.query_flag);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryIPOStock(&myreq, request_id);
	return i;
};

int TdApi::querySecurityBaseInfo(const dict &req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QuerySecurityBaseInfo(&myreq, request_id);
	return i;
};

int TdApi::creditMortgageInOut(const dict &req, int request_id)
{
	CreditMortgageInOutReq myreq = CreditMortgageInOutReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "side", &myreq.side);
	getInt32_t(req, "volume", &myreq.volume);
	getString(req, "opp_fund_id", myreq.opp_fund_id);
	getString(req, "opp_secu_id", myreq.opp_secu_id);
	int i = this->api->CreditMortgageInOut(&myreq, request_id);
	return i;
};

int TdApi::creditStockBack(const dict &req, int request_id)
{
	CreditStockBackReq myreq = CreditStockBackReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt32_t(req, "volume", &myreq.volume);
	int i = this->api->CreditStockBack(&myreq, request_id);
	return i;
};

int TdApi::creditPayBack(const dict &req, int request_id)
{
	CreditPayBackReq myreq = CreditPayBackReq();
	memset(&myreq, 0, sizeof(myreq));
	getLonglong(req, "back_amt", &myreq.back_amt);
	getString(req, "cl_order_id", myreq.cl_order_id);
	int i = this->api->CreditPayBack(&myreq, request_id);
	return i;
};

int TdApi::creditPayBackByOrder(const dict &req, int request_id)
{
	CreditPayBackByOrderReq myreq = CreditPayBackByOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "sno", myreq.sno);
	getInt(req, "order_date", &myreq.order_date);
	getLonglong(req, "back_amt", &myreq.back_amt);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getInt32_t(req, "credit_type", &myreq.credit_type);
	int i = this->api->CreditPayBackByOrder(&myreq, request_id);
	return i;
};

int TdApi::queryCreditStock(const dict &req, int request_id)
{
	QryCreditStockReq myreq = QryCreditStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditStock(&myreq, request_id);
	return i;
};

int TdApi::queryCreditMortgageHold(const dict &req, int request_id)
{
	QryCreditMortgageHoldReq myreq = QryCreditMortgageHoldReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditMortgageHold(&myreq, request_id);
	return i;
};

int TdApi::queryCreditAssets(int request_id)
{
	int i = this->api->QueryCreditAssets(request_id);
	return i;
};

int TdApi::queryCreditFinance(const dict &req, int request_id)
{
	QryCreditFinanceReq myreq = QryCreditFinanceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditFinance(&myreq, request_id);
	return i;
};

int TdApi::queryCreditShortsell(const dict &req, int request_id)
{
	QryCreditShortsellReq myreq = QryCreditShortsellReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditShortsell(&myreq, request_id);
	return i;
};

int TdApi::queryCreditRepayAmount(int request_id)
{
	int i = this->api->QueryCreditRepayAmount(request_id);
	return i;
};

int TdApi::queryCreditRepayStock(const dict &req, int request_id)
{
	QryCreditRepayStockReq myreq = QryCreditRepayStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "code", myreq.code);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditRepayStock(&myreq, request_id);
	return i;
};

int TdApi::queryCreditSecuritySellQty(const dict &req, int request_id)
{
	QryCreditSecuritySellQtyReq myreq = QryCreditSecuritySellQtyReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "code", myreq.code);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditSecuritySellQty(&myreq, request_id);
	return i;
};

int TdApi::querySecuidRight(const dict &req, int request_id)
{
	QrySecuidRightReq myreq = QrySecuidRightReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getInt16_t(req, "secuid_right", &myreq.secuid_right);
	int i = this->api->QuerySecuidRight(&myreq, request_id);
	return i;
};

int TdApi::queryHKRate(const dict &req, int request_id)
{
	QryByMarketReq myreq = QryByMarketReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryHKRate(&myreq, request_id);
	return i;
};

int TdApi::queryHKStock(const dict &req, int request_id)
{
	QryHKStock myreq = QryHKStock();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryHKStock(&myreq, request_id);
	return i;
};

int TdApi::queryHKFund(int request_id)
{
	int i = this->api->QueryHKFund(request_id);
	return i;
};

int TdApi::queryHKMinPriceUnit(const dict &req, int request_id)
{
	QryHKMinPriceUnitReq myreq = QryHKMinPriceUnitReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "code", myreq.code);
	getLonglong(req, "price", &myreq.price);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryHKMinPriceUnit(&myreq, request_id);
	return i;
};

int TdApi::queryHKTradeCalendar(const dict &req, int request_id)
{
	QryByDateReq myreq = QryByDateReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "start_date", &myreq.start_date);
	getInt(req, "end_date", &myreq.end_date);
	int i = this->api->QueryHKTradeCalendar(&myreq, request_id);
	return i;
};

int TdApi::queryLockSecurityDetail(const dict &req, int request_id)
{
	QryLockSecurityReq myreq = QryLockSecurityReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "start_date", &myreq.start_date);
	getInt(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "code", myreq.code);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryLockSecurityDetail(&myreq, request_id);
	return i;
};

int TdApi::extendLockSecurity(const dict &req, int request_id)
{
	ExtendLockSecurityReq myreq = ExtendLockSecurityReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "sys_date", &myreq.sys_date);
	getString(req, "sno", myreq.sno);
	getInt32_t(req, "apply_delay_days", &myreq.apply_delay_days);
	getLonglong(req, "apply_used_fee_rate", &myreq.apply_used_fee_rate);
	getLonglong(req, "apply_unused_fee_rate", &myreq.apply_unused_fee_rate);
	getInt32_t(req, "apply_delay_qty", &myreq.apply_delay_qty);
	getString(req, "symbol", myreq.symbol);
	int i = this->api->ExtendLockSecurity(&myreq, request_id);
	return i;
};

int TdApi::queryLockSecurityExtension(const dict &req, int request_id)
{
	QryLockSecurityExtensionReq myreq = QryLockSecurityExtensionReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "start_date", &myreq.start_date);
	getInt(req, "end_date", &myreq.end_date);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryLockSecurityExtension(&myreq, request_id);
	return i;
};

int TdApi::queryTransferFundHistory(int request_id)
{
	int i = this->api->QueryTransferFundHistory(request_id);
	return i;
};

int TdApi::queryCreditDebtsFlow(const dict &req, int request_id)
{
	QryCreditDebtsFlowReq myreq = QryCreditDebtsFlowReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt16_t(req, "currency_type", &myreq.currency_type);
	int i = this->api->QueryCreditDebtsFlow(&myreq, request_id);
	return i;
};

int TdApi::queryCreditAssetFlow(const dict &req, int request_id)
{
	QryCreditAssetFlowReq myreq = QryCreditAssetFlowReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditAssetFlow(&myreq, request_id);
	return i;
};

int TdApi::queryCreditDebts(const dict &req, int request_id)
{
	QueryCreditDebtsReq myreq = QueryCreditDebtsReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "credit_direct", &myreq.credit_direct);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getInt32_t(req, "sys_date", &myreq.sys_date);
	getString(req, "sno", myreq.sno);
	getInt16_t(req, "currency_type", &myreq.currency_type);
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditDebts(&myreq, request_id);
	return i;
};

int TdApi::doMicroServiceReq(const dict &req, int request_id)
{
	MicroServiceReq myreq = MicroServiceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "function_id", myreq.function_id);
	getString(req, "tar_sys", myreq.tar_sys);
	getSecuidinfo(req, "request_content", &myreq.request_content);
	getInt32_t(req, "request_len", &myreq.request_len);
	int i = this->api->DoMicroServiceReq(&myreq, request_id);
	return i;
};

int TdApi::queryBankBalance(const dict &req, int request_id)
{
	BankBalanceReq myreq = BankBalanceReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getString(req, "bank_code", myreq.bank_code);
	int i = this->api->QueryBankBalance(&myreq, request_id);
	return i;
};

int TdApi::queryBankInfo(const dict &req, int request_id)
{
	QueryBankInfoReq myreq = QueryBankInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	int i = this->api->QueryBankInfo(&myreq, request_id);
	return i;
};

int TdApi::bankSecTransfer(const dict &req, int request_id)
{
	BankSecTransferReq myreq = BankSecTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "currency_type", &myreq.currency_type);
	getString(req, "bank_code", myreq.bank_code);
	getChar(req, "busi_type", &myreq.busi_type);
	getLonglong(req, "fund_effect", &myreq.fund_effect);
	getString(req, "gm_fund_pwd", myreq.gm_fund_pwd);
	getString(req, "bank_pwd", myreq.bank_pwd);
	int i = this->api->BankSecTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryBankSecTransfer(const dict &req, int request_id)
{
	QryBankSecTransferReq myreq = QryBankSecTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getLonglong(req, "sno", &myreq.sno);
	int i = this->api->QueryBankSecTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryHisBankSecTransfer(const dict &req, int request_id)
{
	QryHisBankSecTransferReq myreq = QryHisBankSecTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "pos_str", myreq.pos_str);
	int i = this->api->QueryHisBankSecTransfer(&myreq, request_id);
	return i;
};

int TdApi::fundAccountTransfer(const dict &req, int request_id)
{
	FundAccountTransferReq myreq = FundAccountTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "in_orgid", myreq.in_orgid);
	getString(req, "in_fund_id", myreq.in_fund_id);
	getString(req, "out_orgid", myreq.out_orgid);
	getString(req, "out_fund_id", myreq.out_fund_id);
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getLonglong(req, "fund_effect", &myreq.fund_effect);
	getString(req, "remark", myreq.remark);
	int i = this->api->FundAccountTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryFundAccountTransfer(const dict &req, int request_id)
{
	QryFundAccountTransferReq myreq = QryFundAccountTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "brh_id", myreq.brh_id);
	getString(req, "fund_id", myreq.fund_id);
	int i = this->api->QueryFundAccountTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryHisOrders(const dict &req, int request_id)
{
	QryHisOrderReq myreq = QryHisOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "stk_code", myreq.stk_code);
	getString(req, "order_id", myreq.order_id);
	getInt32_t(req, "order_date", &myreq.order_date);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryHisOrders(&myreq, request_id);
	return i;
};

int TdApi::queryHisTrades(const dict &req, int request_id)
{
	QryHisTradeReq myreq = QryHisTradeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	getString(req, "stk_code", myreq.stk_code);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryHisTrades(&myreq, request_id);
	return i;
};

int TdApi::queryDeliveryOrders(const dict &req, int request_id)
{
	QryDeliveryOrderReq myreq = QryDeliveryOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "stk_code", myreq.stk_code);
	int i = this->api->QueryDeliveryOrders(&myreq, request_id);
	return i;
};

int TdApi::queryStateOrders(const dict &req, int request_id)
{
	QryStateOrderReq myreq = QryStateOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getString(req, "stk_code", myreq.stk_code);
	getInt16_t(req, "currency_type", &myreq.currency_type);
	int i = this->api->QueryStateOrders(&myreq, request_id);
	return i;
};

int TdApi::queryExchangeLists(const dict &req, int request_id)
{
	QueryExchangeListsReq myreq = QueryExchangeListsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	int i = this->api->QueryExchangeLists(&myreq, request_id);
	return i;
};

int TdApi::modifyPassword(const dict &req, int request_id)
{
	ModifyPasswordReq myreq = ModifyPasswordReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "old_password", myreq.old_password);
	getString(req, "new_password", myreq.new_password);
	getInt16_t(req, "password_type", &myreq.password_type);
	int i = this->api->ModifyPassword(&myreq, request_id);
	return i;
};

int TdApi::queryPHXX(const dict &req, int request_id)
{
	QueryPHXXReq myreq = QueryPHXXReq();
	memset(&myreq, 0, sizeof(myreq));
	getLonglong(req, "query_index", &myreq.query_index);
	getLonglong(req, "query_num", &myreq.query_num);
	getString(req, "stk_code", myreq.stk_code);
	getString(req, "secuid", myreq.secuid);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryPHXX(&myreq, request_id);
	return i;
};

int TdApi::queryZQXX(const dict &req, int request_id)
{
	QueryZQXXReq myreq = QueryZQXXReq();
	memset(&myreq, 0, sizeof(myreq));
	getLonglong(req, "query_index", &myreq.query_index);
	getLonglong(req, "query_num", &myreq.query_num);
	getString(req, "stk_code", myreq.stk_code);
	getString(req, "secuid", myreq.secuid);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getChar(req, "qry_direct", &myreq.qry_direct);
	getString(req, "market", myreq.market);
	int i = this->api->QueryZQXX(&myreq, request_id);
	return i;
};

int TdApi::queryLockSecurityContract(const dict &req, int request_id)
{
	QryLockSecurityContractReq myreq = QryLockSecurityContractReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "symbol", myreq.symbol);
	getString(req, "status", myreq.status);
	int i = this->api->QueryLockSecurityContract(&myreq, request_id);
	return i;
};

int TdApi::queryCreditContract(int request_id)
{
	int i = this->api->QueryCreditContract(request_id);
	return i;
};

int TdApi::queryCreditDebtsCollect(const dict &req, int request_id)
{
	QryCreditDebtsCollectReq myreq = QryCreditDebtsCollectReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryCreditDebtsCollect(&myreq, request_id);
	return i;
};

int TdApi::queryCreditData(const dict &req, int request_id)
{
	QryCreditDataReq myreq = QryCreditDataReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getChar(req, "credit_direct", &myreq.credit_direct);
	int i = this->api->QueryCreditData(&myreq, request_id);
	return i;
};

int TdApi::queryPreMaturityDebts(const dict &req, int request_id)
{
	QryPreMaturityDebtsReq myreq = QryPreMaturityDebtsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPreMaturityDebts(&myreq, request_id);
	return i;
};

int TdApi::extendPreMaturityDebts(const dict &req, int request_id)
{
	ExtendPreMaturityDebtsReq myreq = ExtendPreMaturityDebtsReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "sys_date", &myreq.sys_date);
	getString(req, "sno", myreq.sno);
	int i = this->api->ExtendPreMaturityDebts(&myreq, request_id);
	return i;
};

int TdApi::queryPreMaturityDebtsExtension(const dict &req, int request_id)
{
	QryPreMaturityDebtsExtensionReq myreq = QryPreMaturityDebtsExtensionReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPreMaturityDebtsExtension(&myreq, request_id);
	return i;
};

int TdApi::queryVoteProposal(const dict &req, int request_id)
{
	QryVoteProposalReq myreq = QryVoteProposalReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "vote_symbol", myreq.vote_symbol);
	int i = this->api->QueryVoteProposal(&myreq, request_id);
	return i;
};

int TdApi::queryCreditVoteCount(const dict &req, int request_id)
{
	QryCreditVoteCountReq myreq = QryCreditVoteCountReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "meeting_seq", myreq.meeting_seq);
	getString(req, "voting_proposal", myreq.voting_proposal);
	int i = this->api->QueryCreditVoteCount(&myreq, request_id);
	return i;
};

int TdApi::queryCreditVote(const dict &req, int request_id)
{
	QryCreditVoteReq myreq = QryCreditVoteReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "code", myreq.code);
	getString(req, "voting_proposal", myreq.voting_proposal);
	int i = this->api->QueryCreditVote(&myreq, request_id);
	return i;
};

int TdApi::queryNetVoteRights(const dict &req, int request_id)
{
	QryNetVoteRightsReq myreq = QryNetVoteRightsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	getString(req, "stk_code", myreq.stk_code);
	int i = this->api->QueryNetVoteRights(&myreq, request_id);
	return i;
};

int TdApi::queryNetVoteResult(const dict &req, int request_id)
{
	QryNetVoteResultReq myreq = QryNetVoteResultReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "vote_code", myreq.vote_code);
	int i = this->api->QueryNetVoteResult(&myreq, request_id);
	return i;
};

int TdApi::queryNetVoteCount(const dict &req, int request_id)
{
	QryNetVoteCountReq myreq = QryNetVoteCountReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "secuid", myreq.secuid);
	getString(req, "symbol", myreq.symbol);
	getString(req, "vote_code", myreq.vote_code);
	getInt32_t(req, "reg_date", &myreq.reg_date);
	int i = this->api->QueryNetVoteCount(&myreq, request_id);
	return i;
};

int TdApi::appointContractSellStockRepay(const dict &req, int request_id)
{
	AppointContractSellStockRepayReq myreq = AppointContractSellStockRepayReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "order_date", &myreq.order_date);
	getString(req, "sno", myreq.sno);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt16_t(req, "order_type", &myreq.order_type);
	getInt16_t(req, "side", &myreq.side);
	getLonglong(req, "volume", &myreq.volume);
	getLonglong(req, "price", &myreq.price);
	int i = this->api->AppointContractSellStockRepay(&myreq, request_id);
	return i;
};

int TdApi::queryStkConcentration(const dict &req, int request_id)
{
	StkConcentrationReq myreq = StkConcentrationReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "query_index", myreq.query_index);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "symbol", myreq.symbol);
	getString(req, "market", myreq.market);
	int i = this->api->QueryStkConcentration(&myreq, request_id);
	return i;
};

int TdApi::queryHKHisOrders(const dict &req, int request_id)
{
	QryHKHisOrderReq myreq = QryHKHisOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "stk_code", myreq.stk_code);
	getString(req, "order_id", myreq.order_id);
	getString(req, "bank_code", myreq.bank_code);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryHKHisOrders(&myreq, request_id);
	return i;
};

int TdApi::queryWithdrawCash(const dict &req, int request_id)
{
	QueryWithdrawCashReq myreq = QueryWithdrawCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryWithdrawCash(&myreq, request_id);
	return i;
};

int TdApi::queryTradeListTotal(const dict &req, int request_id)
{
	QryTradeListTotalReq myreq = QryTradeListTotalReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	getString(req, "stkcode", myreq.stkcode);
	int i = this->api->QueryTradeListTotal(&myreq, request_id);
	return i;
};

int TdApi::eTFSubscriptCancel(const dict &req, int request_id)
{
	ETFSubscriptCancelReq myreq = ETFSubscriptCancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "order_date", &myreq.order_date);
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	int i = this->api->ETFSubscriptCancel(&myreq, request_id);
	return i;
};

int TdApi::queryNetVoteOrder(const dict &req, int request_id)
{
	QryNetVoteOrderReq myreq = QryNetVoteOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "meeting_seq", myreq.meeting_seq);
	getString(req, "voting_proposal_code", myreq.voting_proposal_code);
	getString(req, "stock_code", myreq.stock_code);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryNetVoteOrder(&myreq, request_id);
	return i;
};

int TdApi::netVoteOrder(const dict &req, int request_id, string terminal_info)
{
	NetVoteOrderReq myreq = NetVoteOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "link_stk_code", myreq.link_stk_code);
	getLonglong(req, "order_qty", &myreq.order_qty);
	getInt32_t(req, "reg_date", &myreq.reg_date);
	getString(req, "meeting_seq", myreq.meeting_seq);
	getString(req, "voting_proposal", myreq.voting_proposal);
	getInt16_t(req, "voting_preference", &myreq.voting_preference);
	getString(req, "voting_segment", myreq.voting_segment);
	int i = this->api->NetVoteOrder(&myreq, request_id, terminal_info.c_str());
	return i;
};

int TdApi::creditNetVoteOrder(const dict &req, int request_id, string terminal_info)
{
	CreditNetVoteOrderReq myreq = CreditNetVoteOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "link_stk_code", myreq.link_stk_code);
	getInt32_t(req, "reg_date", &myreq.reg_date);
	getInt16_t(req, "currency_type", &myreq.currency_type);
	getLonglong(req, "order_qty", &myreq.order_qty);
	getString(req, "meeting_seq", myreq.meeting_seq);
	getString(req, "voting_proposal", myreq.voting_proposal);
	getInt16_t(req, "voting_preference", &myreq.voting_preference);
	int i = this->api->CreditNetVoteOrder(&myreq, request_id, terminal_info.c_str());
	return i;
};

int TdApi::queryMSCash(const dict &req, int request_id)
{
	QueryMSCashReq myreq = QueryMSCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryMSCash(&myreq, request_id);
	return i;
};

int TdApi::queryMSPositions(const dict &req, int request_id)
{
	QueryMSPositionsReq myreq = QueryMSPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryMSPositions(&myreq, request_id);
	return i;
};

int TdApi::queryMSCreditDebtsFlow(const dict &req, int request_id)
{
	QueryMSCreditDebtsFlowReq myreq = QueryMSCreditDebtsFlowReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	getString(req, "market", myreq.market);
	getString(req, "code", myreq.code);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryMSCreditDebtsFlow(&myreq, request_id);
	return i;
};

