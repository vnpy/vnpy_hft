int login(string svr_ip, int svr_port, const dict &req, string terminal_info);

int getCounterType();

int getSecuidInfo(const dict &req, int count);

int getAllSecuidInfo(const dict &req, int count);

int getApiLocalAddr(const dict &req);

int order(const dict &req, int request_id);

int batchOrder(const dict &req, int count, int request_id);

int cancelOrder(const dict &req, int request_id);

int batchCancelOrder(const dict &req, int count, int request_id);

int batchCancelAllOrder(const dict &req, int request_id);

int queryOrder(const dict &req, int request_id);

int queryOrderByCode(const dict &req, int request_id);

int queryOrders(const dict &req, int request_id);

int queryTradeByOrderId(const dict &req, int request_id);

int queryTradeByCode(const dict &req, int request_id);

int queryTrades(const dict &req, int request_id);

int queryETFTrades(const dict &req, int request_id);

int queryPosition(const dict &req, int request_id);

int queryPositions(const dict &req, int request_id);

int queryCash(const dict &req, int request_id);

int queryJZJYAvailFund(int request_id);

int transferFundInAndOut(const dict &req, int request_id);

int transferFundBetweenSecuid(const dict &req, int request_id);

int queryETFs(const dict &req, int request_id);

int queryETFStocks(const dict &req, int request_id);

int queryMaxOrderQty(const dict &req, int request_id);

int queryIPOMaxPurchase(int request_id);

int queryIPOStock(const dict &req, int request_id);

int querySecurityBaseInfo(const dict &req, int request_id);

int creditMortgageInOut(const dict &req, int request_id);

int creditStockBack(const dict &req, int request_id);

int creditPayBack(const dict &req, int request_id);

int creditPayBackByOrder(const dict &req, int request_id);

int queryCreditStock(const dict &req, int request_id);

int queryCreditMortgageHold(const dict &req, int request_id);

int queryCreditAssets(int request_id);

int queryCreditFinance(const dict &req, int request_id);

int queryCreditShortsell(const dict &req, int request_id);

int queryCreditRepayAmount(int request_id);

int queryCreditRepayStock(const dict &req, int request_id);

int queryCreditSecuritySellQty(const dict &req, int request_id);

int querySecuidRight(const dict &req, int request_id);

int queryHKRate(const dict &req, int request_id);

int queryHKStock(const dict &req, int request_id);

int queryHKFund(int request_id);

int queryHKMinPriceUnit(const dict &req, int request_id);

int queryHKTradeCalendar(const dict &req, int request_id);

int queryLockSecurityDetail(const dict &req, int request_id);

int extendLockSecurity(const dict &req, int request_id);

int queryLockSecurityExtension(const dict &req, int request_id);

int queryTransferFundHistory(int request_id);

int queryCreditDebtsFlow(const dict &req, int request_id);

int queryCreditAssetFlow(const dict &req, int request_id);

int queryCreditDebts(const dict &req, int request_id);

int doMicroServiceReq(const dict &req, int request_id);

int queryBankBalance(const dict &req, int request_id);

int queryBankInfo(const dict &req, int request_id);

int bankSecTransfer(const dict &req, int request_id);

int queryBankSecTransfer(const dict &req, int request_id);

int queryHisBankSecTransfer(const dict &req, int request_id);

int fundAccountTransfer(const dict &req, int request_id);

int queryFundAccountTransfer(const dict &req, int request_id);

int queryHisOrders(const dict &req, int request_id);

int queryHisTrades(const dict &req, int request_id);

int queryDeliveryOrders(const dict &req, int request_id);

int queryStateOrders(const dict &req, int request_id);

int queryExchangeLists(const dict &req, int request_id);

int modifyPassword(const dict &req, int request_id);

int queryPHXX(const dict &req, int request_id);

int queryZQXX(const dict &req, int request_id);

int queryLockSecurityContract(const dict &req, int request_id);

int queryCreditContract(int request_id);

int queryCreditDebtsCollect(const dict &req, int request_id);

int queryCreditData(const dict &req, int request_id);

int queryPreMaturityDebts(const dict &req, int request_id);

int extendPreMaturityDebts(const dict &req, int request_id);

int queryPreMaturityDebtsExtension(const dict &req, int request_id);

int queryVoteProposal(const dict &req, int request_id);

int queryCreditVoteCount(const dict &req, int request_id);

int queryCreditVote(const dict &req, int request_id);

int queryNetVoteRights(const dict &req, int request_id);

int queryNetVoteResult(const dict &req, int request_id);

int queryNetVoteCount(const dict &req, int request_id);

int appointContractSellStockRepay(const dict &req, int request_id);

int queryStkConcentration(const dict &req, int request_id);

int queryHKHisOrders(const dict &req, int request_id);

int queryWithdrawCash(const dict &req, int request_id);

int queryTradeListTotal(const dict &req, int request_id);

int eTFSubscriptCancel(const dict &req, int request_id);

int queryNetVoteOrder(const dict &req, int request_id);

int netVoteOrder(const dict &req, int request_id, string terminal_info);

int creditNetVoteOrder(const dict &req, int request_id, string terminal_info);

int queryMSCash(const dict &req, int request_id);

int queryMSPositions(const dict &req, int request_id);

int queryMSCreditDebtsFlow(const dict &req, int request_id);

