RiskNotify = {
    "secuid": "SecuidInfo",
    "alarm_score": "SecuidInfo",
    "alarm_status": "SecuidInfo",
    "alarm_rule": "SecuidInfo",
    "alarm_time": "SecuidInfo",
    "alarm_msg": "SecuidInfo",
}

FailBackNotify = {
    "system_id": "SecuidInfo",
    "node_id": "SecuidInfo",
    "status": "char",
    "credit_node_flag": "char",
    "urgent_flag": "char",
    "update_source": "SecuidInfo",
}

AccountInfo = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "account_pwd": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_system_id": "SecuidInfo",
}

LoginReq = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "account_pwd": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_system_id": "SecuidInfo",
    "svr_ip": "SecuidInfo",
    "svr_port": "int",
    "terminal_info": "SecuidInfo",
    "inner_flag": "int16_t",
}

SecuidInfo = {
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "fund_id": "SecuidInfo",
    "account_type": "int16_t",
    "account_status": "char",
    "account_class": "char",
    "account_rights": "SecuidInfo",
    "account_hgtright": "char",
}

LoginRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "cust_name": "SecuidInfo",
    "secuid_array": "SecuidInfo",
    "cif_account": "SecuidInfo",
    "user_code": "SecuidInfo",
    "user_token": "SecuidInfo",
    "token_serial_no": "SecuidInfo",
    "sm3_cipher": "SecuidInfo",
    "sys_node_type": "int",
    "clear_switch_flag": "char",
    "trade_switch_flag": "char",
    "sys_server_id": "SecuidInfo",
    "operway": "char",
    "sys_shbond_type": "int16_t",
    "ext_secuid_array": "SecuidInfo",
    "reg_branchid": "SecuidInfo",
}

OrderReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "long long",
    "price": "SecuidInfo",
    "order_flag": "int16_t",
    "policy_id": "uint16_t",
    "share_property": "int16_t",
}

OrderRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_date": "int32_t",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "ex_order_id": "SecuidInfo",
}

CancelReq = {
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "long long",
    "price": "SecuidInfo",
}

BatchCancelAllReq = {
    "cust_id": "SecuidInfo",
    "secu_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "market": "int32_t",
}

CancelRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
    "cancel_id": "SecuidInfo",
    "ex_order_id": "SecuidInfo",
}

QryByOrderIdReq = {
    "order_id": "SecuidInfo",
    "market": "SecuidInfo",
}

QryByCodeReq = {
    "symbol": "SecuidInfo",
}

QryOrderByCodeReq = {
    "symbol": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

QryOrdersReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "query_flag": "int",
    "market": "SecuidInfo",
}

OrderDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "orig_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "order_status": "int16_t",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "long long",
    "price": "SecuidInfo",
    "filled_volume": "long long",
    "filled_turnover": "SecuidInfo",
    "filled_price": "SecuidInfo",
    "cancel_volume": "long long",
    "cancel_flag": "int16_t",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
    "secuid": "SecuidInfo",
    "name": "SecuidInfo",
    "freeze_amount": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "ex_order_id": "SecuidInfo",
}

QryTradeByCodeReq = {
    "symbol": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

QryTradesReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
    "filter_etf": "bool",
    "counter_order_id": "SecuidInfo",
}

QryETFTradesReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
    "counter_order_id": "SecuidInfo",
    "qry_direct": "char",
}

TradeDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "order_type": "int16_t",
    "side": "int16_t",
    "report_type": "int16_t",
    "report_no": "SecuidInfo",
    "volume": "long long",
    "price": "SecuidInfo",
    "turnover": "SecuidInfo",
    "trade_date": "int32_t",
    "trade_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
    "secuid": "SecuidInfo",
    "name": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "ex_report_no": "SecuidInfo",
    "ex_order_id": "SecuidInfo",
    "margin_amt_type": "int16_t",
    "order_price": "SecuidInfo",
    "order_qty": "long long",
}

QryPositionsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
}

PositionDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "side": "int16_t",
    "volume": "long long",
    "avail_volume": "long long",
    "init_volume": "long long",
    "market_value": "SecuidInfo",
    "today_buy_volume": "long long",
    "today_sell_volume": "long long",
    "secuid": "SecuidInfo",
    "cost_price": "SecuidInfo",
    "buy_cost": "SecuidInfo",
    "last_price": "SecuidInfo",
    "income": "SecuidInfo",
    "total_income": "SecuidInfo",
    "profit_cost": "SecuidInfo",
    "today_avail_pr_volume": "long long",
    "market": "int32_t",
    "security_type": "int32_t",
    "freeze_volume": "long long",
    "name": "SecuidInfo",
    "currency_type": "int32_t",
    "security_type_apex": "int32_t",
    "profit_price": "SecuidInfo",
}

QryCashReq = {
    "market": "SecuidInfo",
}

CashDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "total_amount": "SecuidInfo",
    "avail_amount": "SecuidInfo",
    "total_asset": "SecuidInfo",
    "market_value": "SecuidInfo",
    "init_amount": "SecuidInfo",
    "fetch_balance": "SecuidInfo",
}

JZJYAvailFundDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "avail_amount": "SecuidInfo",
}

TransferFundReq = {
    "transfer_side": "int",
    "transfer_value": "SecuidInfo",
    "market": "SecuidInfo",
}

TransferFundRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "transfer_value": "SecuidInfo",
}

TransferFundSecuidReq = {
    "fund_out_market": "SecuidInfo",
    "fund_in_market": "SecuidInfo",
    "transfer_value": "SecuidInfo",
}

TransferFundSecuidRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "transfer_value": "SecuidInfo",
}

QryETFsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

ETFDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "name": "SecuidInfo",
    "first_symbol": "SecuidInfo",
    "second_symbol": "SecuidInfo",
    "trade_unit": "int32_t",
    "cash_component": "SecuidInfo",
    "max_cash_ratio": "SecuidInfo",
    "trade_state": "int32_t",
    "record_num": "int32_t",
    "trade_day": "int32_t",
    "pre_trade_day": "int32_t",
    "nav_percu": "SecuidInfo",
    "nav": "SecuidInfo",
    "creation_limituser": "long long",
    "redemption_limituser": "long long",
    "net_creation_limituser": "long long",
    "net_redemption_limituser": "long long",
    "creation_limit": "long long",
    "redemption_limit": "long long",
    "net_creation_limit": "long long",
    "net_redemption_limit": "long long",
    "etf_type": "int32_t",
    "cash_component_t1": "SecuidInfo",
    "internal_trade_state": "int32_t",
}

QryETFStocksReq = {
    "first_symbol": "SecuidInfo",
    "sz_ksc_type": "int",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

ETFStockDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "first_symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "symbol": "SecuidInfo",
    "volume": "int32_t",
    "replace_flag": "int16_t",
    "over_price_rate": "SecuidInfo",
    "replace_amt": "SecuidInfo",
}

QryMaxOrderQtyReq = {
    "symbol": "SecuidInfo",
    "order_type": "int16_t",
    "side": "int16_t",
    "price": "SecuidInfo",
}

MaxOrderQtyDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "max_qty": "long long",
    "actual_max_qty": "long long",
    "max_pay_amt": "SecuidInfo",
    "max_pay_qty": "long long",
    "sep_rem_qty": "long long",
}

IPOMaxPurchaseDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "market": "SecuidInfo",
    "max_qty": "long long",
    "stib_max_qty": "long long",
    "secuid": "SecuidInfo",
}

QueryIPOStockReq = {
    "query_flag": "int16_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

IPOStockDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "currency_type": "int16_t",
    "ipo_price": "SecuidInfo",
    "max_num": "long long",
    "min_num": "long long",
    "security_type": "int32_t",
}

SecurityBaseInfo = {
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "security_type": "int32_t",
    "security_status": "int32_t",
    "price_tick": "SecuidInfo",
    "limit_up": "SecuidInfo",
    "limit_down": "SecuidInfo",
    "max_qty": "long long",
    "min_qty": "long long",
    "buy_tick": "SecuidInfo",
    "sale_tick": "SecuidInfo",
    "has_price_limit": "int32_t",
    "limit_up_rate": "SecuidInfo",
    "is_registration": "int32_t",
    "limit_down_rate": "SecuidInfo",
    "trade_id": "char",
}

QryByMarketReq = {
    "market": "SecuidInfo",
}

HKRateDetail = {
    "market": "SecuidInfo",
    "buy_rate": "SecuidInfo",
    "sale_rate": "SecuidInfo",
    "mid_rate": "SecuidInfo",
    "set_rate": "SecuidInfo",
    "sys_date": "int32_t",
}

QryHKStock = {
    "market": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

HKStockDetail = {
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "stktype": "int16_t",
    "currency_type": "int16_t",
    "security_type": "int32_t",
}

HKFundDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "fund_uncomeavl": "SecuidInfo",
    "fund_buy": "SecuidInfo",
    "fund_sale": "SecuidInfo",
    "fund_uncomebuy": "SecuidInfo",
    "fund_uncomesale": "SecuidInfo",
}

QryHKMinPriceUnitReq = {
    "market": "SecuidInfo",
    "code": "SecuidInfo",
    "price": "long long",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

HKMinPriceUnitDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "stktype": "int16_t",
    "begin_price": "SecuidInfo",
    "end_price": "SecuidInfo",
    "price_unit": "int32_t",
}

QryByDateReq = {
    "start_date": "int",
    "end_date": "int",
}

HKTradeCalendarDetail = {
    "date": "int32_t",
    "business_flag": "int16_t",
    "commit_flag": "int16_t",
}

CreditMortgageInOutReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "side": "int16_t",
    "volume": "int32_t",
    "opp_fund_id": "SecuidInfo",
    "opp_secu_id": "SecuidInfo",
}

CreditMortgageInOutRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "contract_id": "SecuidInfo",
}

CreditStockBackReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "volume": "int32_t",
}

CreditStockBackRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "contract_id": "SecuidInfo",
}

CreditPayBackReq = {
    "back_amt": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
}

CreditPayBackByOrderReq = {
    "sno": "SecuidInfo",
    "order_date": "int",
    "back_amt": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "credit_type": "int32_t",
}

CreditPayBackRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "real_back_amt": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
}

QryCreditStockReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditStockDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "currency_type": "int16_t",
    "credit_fund_ctrl": "char",
    "credit_stk_ctrl": "char",
    "margin_rate_fund": "SecuidInfo",
    "margin_rate_stk": "SecuidInfo",
    "sep_rem_qty": "int32_t",
}

CreditAssetsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "avail_balance": "SecuidInfo",
    "fetch_balance": "SecuidInfo",
    "frozen_balance": "SecuidInfo",
    "stock_balance": "SecuidInfo",
    "fund_balance": "SecuidInfo",
    "asset_balance": "SecuidInfo",
    "avail_margin": "SecuidInfo",
    "credit_quota": "SecuidInfo",
    "finance_quota": "SecuidInfo",
    "shortsell_quota": "SecuidInfo",
    "assure_ratio": "SecuidInfo",
    "total_debt": "SecuidInfo",
    "fund_debt": "SecuidInfo",
    "stock_debt": "SecuidInfo",
    "fund_interest_fee": "SecuidInfo",
    "stock_interest_fee": "SecuidInfo",
    "shortsell_total_balance": "SecuidInfo",
    "shortsell_avail_balance": "SecuidInfo",
    "shortsell_frozen_balance": "SecuidInfo",
    "enbuyback_avail_balance": "SecuidInfo",
    "fund_margin_profit": "SecuidInfo",
    "stock_margin_profit": "SecuidInfo",
    "fund_interest": "SecuidInfo",
    "stock_interest": "SecuidInfo",
    "fund_margin_balance": "SecuidInfo",
    "stock_margin_balance": "SecuidInfo",
    "fund_floating_deficit": "SecuidInfo",
    "stock_floating_deficit": "SecuidInfo",
    "fund_margin_profit_conversion": "SecuidInfo",
    "stock_margin_profit_conversion": "SecuidInfo",
    "hbjj_bal": "SecuidInfo",
}

QryCreditFinanceReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditFinanceDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "sno": "SecuidInfo",
    "currency_type": "int16_t",
    "life_status": "int16_t",
    "occur_date": "int32_t",
    "total_balance": "SecuidInfo",
    "cur_balance": "SecuidInfo",
    "total_interest_fee": "SecuidInfo",
    "cur_interest_fee": "SecuidInfo",
    "interest_rate": "SecuidInfo",
    "repayable_balance": "SecuidInfo",
    "f_deal_bal": "SecuidInfo",
    "f_exp_cet_intr": "SecuidInfo",
    "credit_repay_unfrz": "SecuidInfo",
    "all_fee_unfrz": "SecuidInfo",
    "market": "int32_t",
    "pos_str": "SecuidInfo",
    "end_date": "int32_t",
}

QryCreditShortsellReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditShortsellDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "sno": "SecuidInfo",
    "currency_type": "int16_t",
    "life_status": "int16_t",
    "occur_date": "int32_t",
    "total_qty": "long long",
    "cur_qty": "long long",
    "total_interest_fee": "SecuidInfo",
    "cur_interest_fee": "SecuidInfo",
    "interest_rate": "SecuidInfo",
    "d_stk_bal": "long long",
    "market": "int32_t",
    "all_fee_unfrz": "SecuidInfo",
    "stk_repay_unfrz": "long long",
    "end_date": "int32_t",
    "init_cost_price": "SecuidInfo",
}

CreditRepayAmountDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "max_back_amt": "SecuidInfo",
}

QryCreditRepayStockReq = {
    "market": "SecuidInfo",
    "code": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditRepayStockDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "total_qty": "long long",
    "max_back_qty": "long long",
    "returned_qty": "long long",
}

QryCreditMortgageHoldReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditMortgageHoldDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "currency_type": "int16_t",
    "pledge_rate": "SecuidInfo",
}

QryCreditSecuritySellQtyReq = {
    "market": "SecuidInfo",
    "code": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditSecuritySellQtyRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "total_qty": "long long",
    "avail_qty": "long long",
}

QrySecuidRightReq = {
    "market": "SecuidInfo",
    "secuid_right": "int16_t",
}

QrySecuidRightRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "market": "SecuidInfo",
    "secuid_right": "int16_t",
    "sign_flag": "bool",
}

OptionCashDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "init_amount": "SecuidInfo",
    "total_amount": "SecuidInfo",
    "avail_amount": "SecuidInfo",
    "fetch_amount": "SecuidInfo",
    "frozen_amount": "SecuidInfo",
    "used_margin": "SecuidInfo",
    "exercise_frozen": "SecuidInfo",
    "deposit_amount": "SecuidInfo",
    "withdraw_amount": "SecuidInfo",
    "royalty_in": "SecuidInfo",
    "royalty_out": "SecuidInfo",
    "commission": "SecuidInfo",
    "frozen_commission": "SecuidInfo",
}

OptionPositionDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "side": "int16_t",
    "init_volume": "long long",
    "init_avail_volume": "long long",
    "init_comb_volume": "long long",
    "volume": "long long",
    "avail_volume": "long long",
    "comb_volume": "long long",
    "open_volume": "long long",
    "close_volume": "long long",
    "exercise_frozen": "long long",
    "buy_cost": "SecuidInfo",
    "secuid": "SecuidInfo",
    "margin": "SecuidInfo",
    "frozen_margin": "SecuidInfo",
    "commission": "SecuidInfo",
    "frozen_commission": "SecuidInfo",
    "exercise_frozen_amount": "SecuidInfo",
    "frozen_amount": "SecuidInfo",
    "today_close_profit": "SecuidInfo",
    "buy_quota_used": "SecuidInfo",
    "last_price": "SecuidInfo",
    "underlying_multiple": "long long",
}

ExerciseReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "volume": "long long",
    "exercise_type": "int16_t",
}

ExerciseRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "exercise_type": "int16_t",
}

CancelExerciseReq = {
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

CancelExerciseRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

QryExercisesReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

ExerciseDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "exercise_type": "int16_t",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "counter_order_date": "int32_t",
    "counter_order_time": "int32_t",
    "counter_cancel_time": "int32_t",
    "exercise_status": "int32_t",
    "oper_status": "int32_t",
    "symbol": "SecuidInfo",
    "volume": "int32_t",
    "cancel_volume": "int32_t",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
}

ContractInfo = {
    "contract_id": "SecuidInfo",
    "exch_contract_id": "SecuidInfo",
    "contract_name": "SecuidInfo",
    "underlying_contract_id": "SecuidInfo",
    "underlying_contract_name": "SecuidInfo",
    "underlying_multiplier": "int32_t",
    "strike_mode": "int32_t",
    "options_type": "int32_t",
    "order_unit": "int32_t",
    "buy_trading_unit": "int32_t",
    "sell_trading_unit": "int32_t",
    "max_market_order_buy_volume": "int32_t",
    "min_market_order_buy_volume": "int32_t",
    "max_limit_order_buy_volume": "int32_t",
    "min_limit_order_buy_volume": "int32_t",
    "max_market_order_sell_volume": "int32_t",
    "min_market_order_sell_volume": "int32_t",
    "max_limit_order_sell_volume": "int32_t",
    "min_limit_order_sell_volume": "int32_t",
    "volume_multiplier": "int32_t",
    "price_tick": "SecuidInfo",
    "contract_status": "int32_t",
    "strike_price": "SecuidInfo",
    "first_date": "int32_t",
    "last_date": "int32_t",
    "strike_date": "int32_t",
    "expire_date": "int32_t",
    "deliv_date": "int32_t",
    "is_up_down_limit": "int32_t",
    "margin_unit": "SecuidInfo",
    "pre_settlement_price": "SecuidInfo",
    "pre_close_price": "SecuidInfo",
    "underlying_pre_close_price": "SecuidInfo",
}

TransferStockReq = {
    "symbol": "SecuidInfo",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "long long",
}

TransferStockRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "long long",
}

TransferStockDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "serial_number": "SecuidInfo",
    "symbol": "SecuidInfo",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "yesterday_volume": "long long",
    "today_bs_volume": "long long",
    "today_pr_volume": "long long",
    "stock_cust_id": "SecuidInfo",
    "stock_secuid": "SecuidInfo",
    "status_msg": "SecuidInfo",
}

LockOrderReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "lock_type": "int16_t",
    "volume": "long long",
}

LockOrderRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "lock_type": "int16_t",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
}

QryLockOrdersReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

LockOrderDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "lock_type": "int16_t",
    "lock_status": "int16_t",
    "volume": "long long",
    "cancel_volume": "long long",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
}

CombOrderReq = {
    "cl_order_id": "SecuidInfo",
    "symbol": "SecuidInfo",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "volume": "long long",
    "exch_comb_id": "SecuidInfo",
}

CombOrderRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "comb_type": "int16_t",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
}

CombExerciseReq = {
    "cl_order_id": "SecuidInfo",
    "call_symbol": "SecuidInfo",
    "put_symbol": "SecuidInfo",
    "volume": "long long",
}

CombExerciseRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
}

CancelCombExerciseReq = {
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

CancelCombExerciseRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

QryCombOrdersReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CombOrderDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "exch_comb_id": "SecuidInfo",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "order_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "long long",
    "cancel_volume": "long long",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
}

QryCombExercisesReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CombExerciseDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "call_symbol": "SecuidInfo",
    "put_symbol": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "exercise_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "long long",
    "cancel_volume": "long long",
    "err_code": "int32_t",
    "err_msg": "SecuidInfo",
}

CombPositionDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "comb_strategy": "int16_t",
    "volume": "long long",
    "avail_volume": "long long",
    "yesterday_volume": "long long",
    "yesterday_avail_volume": "long long",
    "today_volume": "long long",
    "today_avail_volume": "long long",
    "margin": "SecuidInfo",
    "frozen_margin": "SecuidInfo",
    "commission": "SecuidInfo",
    "frozen_commission": "SecuidInfo",
    "secuid": "SecuidInfo",
}

CombPositionSubDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "comb_strategy": "int16_t",
    "exch_comb_id": "SecuidInfo",
    "volume": "long long",
    "yesterday_volume": "long long",
    "today_volume": "long long",
    "comb_date": "int32_t",
    "comb_time": "int32_t",
    "comb_status": "int16_t",
    "secuid": "SecuidInfo",
    "legs_num": "int32_t",
    "leg1_symbol": "SecuidInfo",
    "leg1_yesterday_volume": "long long",
    "leg1_today_volume": "long long",
    "leg1_pos_side": "int16_t",
    "leg1_option_type": "int16_t",
    "leg2_symbol": "SecuidInfo",
    "leg2_yesterday_volume": "long long",
    "leg2_today_volume": "long long",
    "leg2_pos_side": "int16_t",
    "leg2_option_type": "int16_t",
    "yesterday_split_frozen_volume": "long long",
    "today_split_frozen_volume": "long long",
    "leg1_yesterday_split_frozen_volume": "long long",
    "leg1_today_split_frozen_volume": "long long",
    "leg2_yesterday_split_frozen_volume": "long long",
    "leg2_today_split_frozen_volume": "long long",
}

CombContractInfo = {
    "contract_id": "SecuidInfo",
    "comb_strategy": "int16_t",
    "leg1_contract_id": "SecuidInfo",
    "leg1_name": "SecuidInfo",
    "leg1_side": "int16_t",
    "leg2_contract_id": "SecuidInfo",
    "leg2_name": "SecuidInfo",
    "leg2_side": "int16_t",
}

QryLockSecurityReq = {
    "start_date": "int",
    "end_date": "int",
    "market": "SecuidInfo",
    "code": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

LockSecurityDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "sys_date": "int32_t",
    "sno": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "lock_type": "int16_t",
    "used_fee_rate": "SecuidInfo",
    "unused_fee_rate": "SecuidInfo",
    "lock_qty": "int32_t",
    "used_qty": "int32_t",
    "back_qty": "int32_t",
    "begin_date": "int32_t",
    "back_date": "int32_t",
    "end_date": "int32_t",
    "hs_status": "int16_t",
    "wy_status": "int16_t",
}

TransferFundDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "serial_number": "SecuidInfo",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_value": "SecuidInfo",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "remark": "SecuidInfo",
}

PositionLimitsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "avail_total_limit": "long long",
    "avail_long_limit": "long long",
    "avail_today_open_limit": "long long",
    "avail_today_buy_open_limit": "long long",
    "avail_today_sell_open_limit": "long long",
    "avail_today_covered_open_limit": "long long",
    "avail_long_call_limit": "long long",
    "avail_long_put_limit": "long long",
    "avail_long_underlying_limit": "long long",
    "avail_short_underlying_limit": "long long",
    "total_limit": "long long",
    "long_limit": "long long",
    "today_open_limit": "long long",
    "today_buy_open_limit": "long long",
    "today_sell_open_limit": "long long",
    "today_covered_open_limit": "long long",
    "long_call_limit": "long long",
    "long_put_limit": "long long",
    "long_underlying_limit": "long long",
    "short_underlying_limit": "long long",
}

QryAmountLimitsReq = {
    "market": "SecuidInfo",
}

AmountLimitsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "long_amount_limit": "SecuidInfo",
    "avail_long_amount_limit": "SecuidInfo",
    "market": "SecuidInfo",
}

QrySplitCombMarginDiffReq = {
    "contract_id": "SecuidInfo",
    "comb_strategy": "int16_t",
    "volume": "long long",
    "exch_comb_id": "SecuidInfo",
}

SplitCombMarginDiffDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "market": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "exch_comb_id": "SecuidInfo",
    "comb_strategy": "int16_t",
    "volume": "long long",
    "left_leg_pos_margin": "SecuidInfo",
    "left_leg_pos_live_margin": "SecuidInfo",
    "right_leg_pos_margin": "SecuidInfo",
    "right_leg_pos_live_margin": "SecuidInfo",
    "comb_pos_margin": "SecuidInfo",
    "comb_pos_live_margin": "SecuidInfo",
    "margin_difference": "SecuidInfo",
    "margin_live_difference": "SecuidInfo",
}

QryExerciseAppointmentReq = {
    "market": "SecuidInfo",
    "contract_id": "SecuidInfo",
}

ExerciseAppointmentDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "market": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "counter_order_date": "int32_t",
    "secuid": "SecuidInfo",
    "options_type": "int32_t",
    "option_unit": "long long",
    "underlying_contract_id": "SecuidInfo",
    "volume": "long long",
    "exercise_price": "SecuidInfo",
    "exercise_side": "int32_t",
    "cover_flag": "int32_t",
}

QryOptionMaxOrderVolumeReq = {
    "contract_id": "SecuidInfo",
    "side": "int16_t",
    "order_type": "int16_t",
    "order_flag": "int16_t",
    "price": "SecuidInfo",
}

OptionMaxOrderVolumeDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "max_volume": "long long",
}

QryOptionHisOrderReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisOrderDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "trade_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "long long",
    "contract_id": "SecuidInfo",
    "status": "int32_t",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "option_account": "SecuidInfo",
    "option_security_type": "int32_t",
    "option_num": "SecuidInfo",
    "option_code": "SecuidInfo",
    "option_name": "SecuidInfo",
    "comb_num": "SecuidInfo",
    "comb_strategy": "int16_t",
    "leg1_num": "SecuidInfo",
    "leg2_num": "SecuidInfo",
    "leg3_num": "SecuidInfo",
    "leg4_num": "SecuidInfo",
    "currency_type": "int16_t",
    "price": "long long",
    "qty": "int32_t",
    "order_amt": "long long",
    "order_frozen_amt": "long long",
    "order_unfrozen_amt": "long long",
    "offer_qty": "int32_t",
    "offer_time": "long long",
    "cancel_qty": "long long",
    "match_qty": "long long",
    "match_amt": "long long",
    "cancel_flag": "int32_t",
    "underlying_code": "SecuidInfo",
    "underlying_name": "SecuidInfo",
    "underlying_frozen_qty": "long long",
    "underlying_unfrozen_qty": "long long",
    "underlying_cancel_qty": "long long",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "SecuidInfo",
    "leg2_name": "SecuidInfo",
    "leg3_name": "SecuidInfo",
    "leg4_name": "SecuidInfo",
}

QryOptionHisTradeReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisTradeDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "trade_date": "int32_t",
    "trade_time": "long long",
    "order_date": "int32_t",
    "counter_order_id": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "match_id": "SecuidInfo",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "option_account": "SecuidInfo",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "SecuidInfo",
    "option_name": "SecuidInfo",
    "comb_num": "SecuidInfo",
    "comb_strategy": "int16_t",
    "leg1_num": "SecuidInfo",
    "leg2_num": "SecuidInfo",
    "leg3_num": "SecuidInfo",
    "leg4_num": "SecuidInfo",
    "currency_type": "int16_t",
    "underlying_code": "SecuidInfo",
    "underlying_name": "SecuidInfo",
    "price": "long long",
    "qty": "int32_t",
    "order_frozen_amt": "long long",
    "match_price": "long long",
    "match_qty": "long long",
    "match_amt": "long long",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "SecuidInfo",
    "leg2_name": "SecuidInfo",
    "leg3_name": "SecuidInfo",
    "leg4_name": "SecuidInfo",
}

QryHisExerciseAppointmentReq = {
    "currency_type": "int16_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

HisExerciseAppointmentDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "counter_order_date": "int32_t",
    "currency_type": "int16_t",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "option_account": "SecuidInfo",
    "option_num": "SecuidInfo",
    "option_name": "SecuidInfo",
    "options_type": "int32_t",
    "underlying_code": "SecuidInfo",
    "cover_flag": "int32_t",
    "volume": "long long",
    "underlying_volume": "long long",
    "exercise_amt": "long long",
    "exercise_price": "long long",
    "exercise_side": "int32_t",
    "comb_volume": "long long",
}

QryOptionHisDeliveryReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisDeliveryDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "settlement_id": "long long",
    "settlement_date": "int32_t",
    "counter_order_id": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "market": "SecuidInfo",
    "option_account": "SecuidInfo",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "SecuidInfo",
    "option_name": "SecuidInfo",
    "comb_num": "SecuidInfo",
    "comb_strategy": "int16_t",
    "leg1_num": "SecuidInfo",
    "leg2_num": "SecuidInfo",
    "leg3_num": "SecuidInfo",
    "leg4_num": "SecuidInfo",
    "currency_type": "int16_t",
    "underlying_code": "SecuidInfo",
    "underlying_name": "SecuidInfo",
    "price": "long long",
    "qty": "int32_t",
    "order_amt": "long long",
    "match_price": "long long",
    "match_qty": "long long",
    "match_amt": "long long",
    "match_cnt": "int32_t",
    "stamp_duty": "long long",
    "handle_fee": "long long",
    "secu_regu_fee": "long long",
    "trd_regu_fee": "long long",
    "clearing_fee": "long long",
    "exch_trans_fee": "long long",
    "trans_fee": "long long",
    "exe_trans_fee": "long long",
    "paidin_com": "long long",
    "settlement_amt": "long long",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "SecuidInfo",
    "leg2_name": "SecuidInfo",
    "leg3_name": "SecuidInfo",
    "leg4_name": "SecuidInfo",
}

QryHisExerciseDeliveryReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

HisExerciseDeliveryyDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "serial_number": "long long",
    "settlement_date": "int32_t",
    "occur_time": "long long",
    "market": "SecuidInfo",
    "currency_type": "int16_t",
    "option_account": "SecuidInfo",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "biz_amt": "long long",
    "fund_bln": "long long",
    "fund_avl": "long long",
    "frozen_margin": "long long",
    "unfrozen_margin": "long long",
    "underlying_code": "SecuidInfo",
    "underlying_volume": "long long",
    "stamp_duty": "long long",
    "handle_fee": "long long",
    "secu_regu_fee": "long long",
    "trd_regu_fee": "long long",
    "clearing_fee": "long long",
    "venture_fee": "long long",
    "trans_fee": "long long",
    "exe_trans_fee": "long long",
    "paidin_com": "long long",
    "fee_amt": "long long",
    "volume": "long long",
    "comb_volume": "long long",
    "biz_code": "int32_t",
}

QryOptionHisContractAssetReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisContractAssetDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "occur_date": "int32_t",
    "market": "SecuidInfo",
    "currency_type": "int16_t",
    "option_account": "SecuidInfo",
    "option_num": "SecuidInfo",
    "option_code": "SecuidInfo",
    "option_name": "SecuidInfo",
    "options_type": "int32_t",
    "option_side": "int32_t",
    "cover_flag": "int32_t",
    "underlying_code": "SecuidInfo",
    "option_prebln": "long long",
    "option_bln": "long long",
    "option_avl": "long long",
    "option_margin": "long long",
    "comb_volume": "long long",
}

QryOptionHisDeliveryNettingReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
}

OptionHisDeliveryNettingDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "settlement_date": "int32_t",
    "market": "SecuidInfo",
    "option_account": "SecuidInfo",
    "stamp_duty": "long long",
    "handle_fee": "long long",
    "secu_regu_fee": "long long",
    "trd_regu_fee": "long long",
    "clearing_fee": "long long",
    "exch_trans_fee": "long long",
    "trans_fee": "long long",
    "exe_trans_fee": "long long",
    "paidin_com": "long long",
    "settlement_amt": "long long",
}

QryOptionHisCombPositionReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisCombPositionDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "occur_date": "int32_t",
    "market": "SecuidInfo",
    "currency_type": "int16_t",
    "secuid": "SecuidInfo",
    "option_account": "SecuidInfo",
    "comb_num": "SecuidInfo",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "SecuidInfo",
    "comb_prebln": "long long",
    "comb_bln": "long long",
    "comb_avl": "long long",
    "comb_trade_frz": "long long",
    "comb_trade_ufz": "long long",
    "comb_trade_otd": "long long",
    "comb_trade_bln": "long long",
    "comb_clearing_frz": "long long",
    "comb_clearing_ufz": "long long",
    "comb_clearing_otd": "long long",
    "comb_margin_unit": "long long",
    "comb_margin": "long long",
    "leg_count": "int32_t",
    "leg1_num": "SecuidInfo",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_position": "long long",
    "leg2_num": "SecuidInfo",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_position": "long long",
    "leg3_num": "SecuidInfo",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_position": "long long",
    "leg4_num": "SecuidInfo",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_position": "long long",
    "leg1_name": "SecuidInfo",
    "leg2_name": "SecuidInfo",
    "leg3_name": "SecuidInfo",
    "leg4_name": "SecuidInfo",
}

QryOptionHisSettlementReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

OptionHisSettlementDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "settlement_date": "int32_t",
    "trade_date": "int32_t",
    "trade_time": "long long",
    "counter_order_id": "SecuidInfo",
    "market": "SecuidInfo",
    "currency_type": "int32_t",
    "option_account": "SecuidInfo",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "SecuidInfo",
    "option_name": "SecuidInfo",
    "option_side": "int32_t",
    "match_price": "long long",
    "match_qty": "long long",
    "match_amt": "long long",
    "option_bln": "long long",
    "handle_fee": "long long",
    "clearing_fee": "long long",
    "trans_fee": "long long",
    "exe_trans_fee": "long long",
    "paidin_com": "long long",
    "fee_amt": "long long",
    "biz_amt": "long long",
    "fund_bln": "long long",
}

QryOptionCombStrategyFileReq = {
    "market": "SecuidInfo",
    "comb_strategy": "int16_t",
}

OptionCombStrategyFileDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "market": "SecuidInfo",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "SecuidInfo",
    "same_expdate": "int16_t",
    "same_underlying": "int16_t",
    "auto_split_day": "SecuidInfo",
    "opt_underlying_codes": "SecuidInfo",
    "leg_count": "int32_t",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_exeprc_seq": "int32_t",
    "leg1_expdate_seq": "int32_t",
    "leg1_position": "long long",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_exeprc_seq": "int32_t",
    "leg2_expdate_seq": "int32_t",
    "leg2_position": "long long",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_exeprc_seq": "int32_t",
    "leg3_expdate_seq": "int32_t",
    "leg3_position": "long long",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_exeprc_seq": "int32_t",
    "leg4_expdate_seq": "int32_t",
    "leg4_position": "long long",
}

MicroServiceReq = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "function_id": "SecuidInfo",
    "tar_sys": "SecuidInfo",
    "request_content": "SecuidInfo",
    "request_len": "int32_t",
}

MicroServiceRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "call_status": "bool",
    "error_code": "SecuidInfo",
    "error_info": "SecuidInfo",
    "error_extra": "SecuidInfo",
    "response_list_first": "SecuidInfo",
    "first_list_len": "int32_t",
    "response_list_second": "SecuidInfo",
    "second_list_len": "int32_t",
}

BankBalanceReq = {
    "currency_type": "int32_t",
    "bank_code": "SecuidInfo",
}

BankBalanceDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "status": "char",
    "sno": "long long",
    "fund_bal": "SecuidInfo",
}

QueryBankInfoReq = {
    "currency_type": "int32_t",
}

BankInfoDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "cust_id": "SecuidInfo",
    "currency_type": "int32_t",
    "bank_code": "SecuidInfo",
    "bank_name": "SecuidInfo",
    "bankid": "SecuidInfo",
    "bankpwdflag": "char",
    "qrybankfund": "char",
    "status": "char",
    "banktype": "char",
    "sourcetype": "char",
    "custodystate": "char",
    "custodyflag": "char",
    "confirmflag": "char",
}

BankSecTransferReq = {
    "currency_type": "int",
    "bank_code": "SecuidInfo",
    "busi_type": "char",
    "fund_effect": "SecuidInfo",
    "gm_fund_pwd": "SecuidInfo",
    "bank_pwd": "SecuidInfo",
}

BankSecTransferRsp = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "sno": "long long",
    "busi_type": "char",
    "fund_effect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "status": "char",
}

QryBankSecTransferReq = {
    "currency_type": "int32_t",
    "sno": "long long",
}

BankSecTransferDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "currency_type": "int32_t",
    "cust_id": "SecuidInfo",
    "bank_code": "SecuidInfo",
    "bank_name": "SecuidInfo",
    "busi_type": "char",
    "sno": "long long",
    "fund_effect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "remark": "SecuidInfo",
    "status": "char",
    "bank_msg_id": "SecuidInfo",
    "bank_msg": "SecuidInfo",
    "syserr_id": "long long",
}

QryHisBankSecTransferReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "currency_type": "int32_t",
    "qry_direct": "char",
    "query_num": "int32_t",
    "pos_str": "SecuidInfo",
}

HisBankSecTransferDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "pos_str": "SecuidInfo",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "sno": "long long",
    "fund_id": "SecuidInfo",
    "currency_type": "int32_t",
    "cust_id": "SecuidInfo",
    "cust_name": "SecuidInfo",
    "bank_code": "SecuidInfo",
    "bank_name": "SecuidInfo",
    "busi_type": "char",
    "fund_effect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "remark": "SecuidInfo",
    "status": "char",
    "source_type": "char",
    "strike_flag": "char",
    "bank_msg_id": "SecuidInfo",
    "bank_msg": "SecuidInfo",
    "syserr_id": "long long",
}

FundAccountTransferReq = {
    "in_orgid": "SecuidInfo",
    "in_fund_id": "SecuidInfo",
    "out_orgid": "SecuidInfo",
    "out_fund_id": "SecuidInfo",
    "currency_type": "int32_t",
    "fund_effect": "SecuidInfo",
    "remark": "SecuidInfo",
}

FundAccountTransferRsp = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
}

QryFundAccountTransferReq = {
    "brh_id": "SecuidInfo",
    "fund_id": "SecuidInfo",
}

FundAccountTransferDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "bank_name": "SecuidInfo",
    "digest_id": "SecuidInfo",
    "currency_type": "int32_t",
    "fund_effect": "SecuidInfo",
    "remark": "SecuidInfo",
}

QryHisOrderReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "SecuidInfo",
    "stk_code": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_date": "int32_t",
    "qry_direct": "char",
}

HisOrderDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "symbol": "SecuidInfo",
    "oper_date": "int32_t",
    "order_date": "int32_t",
    "trd_flow_id": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "currency_type": "int16_t",
    "secuid": "SecuidInfo",
    "order_side": "int16_t",
    "order_id": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "order_price": "SecuidInfo",
    "order_qty": "long long",
    "oper_time": "long long",
    "order_frz_amt": "SecuidInfo",
    "match_qty": "long long",
    "match_price": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "cancel_qty": "long long",
    "order_status": "int32_t",
    "seat": "SecuidInfo",
    "oper_way": "char",
    "cancel_flag": "int16_t",
    "extqty1": "long long",
    "remark": "SecuidInfo",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryHisTradeReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
    "stk_code": "SecuidInfo",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

HisTradeDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "symbol": "SecuidInfo",
    "busi_flow_id": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "currency_type": "int32_t",
    "secuid": "SecuidInfo",
    "main_seat": "SecuidInfo",
    "trd_seat": "SecuidInfo",
    "stk_property": "int16_t",
    "busi_type": "SecuidInfo",
    "busi_name": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "order_date": "int32_t",
    "apply_code": "SecuidInfo",
    "match_code": "SecuidInfo",
    "match_time": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "match_qty": "long long",
    "match_price": "SecuidInfo",
    "order_qty": "long long",
    "order_price": "SecuidInfo",
    "intr_amt": "SecuidInfo",
    "stk_type": "SecuidInfo",
    "order_side": "int16_t",
    "oper_date": "int32_t",
    "match_date": "int32_t",
    "stk_bal": "long long",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryDeliveryOrderReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "SecuidInfo",
    "stk_code": "SecuidInfo",
}

DeliveryOrderDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "symbol": "SecuidInfo",
    "biz_date": "int32_t",
    "sno": "SecuidInfo",
    "busi_type": "SecuidInfo",
    "busi_name": "SecuidInfo",
    "currency_type": "int32_t",
    "stk_name": "SecuidInfo",
    "secuid": "SecuidInfo",
    "main_seat": "SecuidInfo",
    "ta_code": "SecuidInfo",
    "tran_sacct": "SecuidInfo",
    "ta_acct": "SecuidInfo",
    "order_date": "int32_t",
    "order_time": "long long",
    "order_side": "int16_t",
    "apply_code": "SecuidInfo",
    "order_qty": "long long",
    "order_price": "SecuidInfo",
    "match_time": "long long",
    "match_qty": "long long",
    "match_price": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "fun_deffect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "stk_effect": "long long",
    "stk_bal": "SecuidInfo",
    "fee_seat": "SecuidInfo",
    "fee_yjf": "SecuidInfo",
    "fee_yhs": "SecuidInfo",
    "fee_jsf": "SecuidInfo",
    "fee_ghf": "SecuidInfo",
    "fee_zgf": "SecuidInfo",
    "fee_sxf": "SecuidInfo",
    "fee_qsf": "SecuidInfo",
    "fee_jggf": "SecuidInfo",
    "fee_other": "SecuidInfo",
    "fee_jsxf": "SecuidInfo",
    "fee_jygf": "SecuidInfo",
    "fee_front": "SecuidInfo",
    "total_num": "int32_t",
    "clear_exch_rate": "SecuidInfo",
}

QryStateOrderReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "stk_code": "SecuidInfo",
    "currency_type": "int16_t",
}

StateOrderDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "symbol": "SecuidInfo",
    "biz_date": "int32_t",
    "clear_date": "int32_t",
    "sno": "SecuidInfo",
    "busi_type": "SecuidInfo",
    "busi_name": "SecuidInfo",
    "currency_type": "int32_t",
    "stk_name": "SecuidInfo",
    "secuid": "SecuidInfo",
    "main_seat": "SecuidInfo",
    "ta_code": "SecuidInfo",
    "trans_acct": "SecuidInfo",
    "ta_acct": "SecuidInfo",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "order_side": "int16_t",
    "apply_code": "SecuidInfo",
    "order_qty": "long long",
    "order_price": "SecuidInfo",
    "match_time": "int32_t",
    "match_qty": "long long",
    "match_price": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "fund_effect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "stkeff_ect": "long long",
    "stk_bal": "SecuidInfo",
    "total_num": "int32_t",
}

QueryExchangeListsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
}

ExchangeDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "pos_str": "SecuidInfo",
    "clear_date": "int32_t",
    "biz_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "long long",
    "digest_id": "int32_t",
    "digest_name": "SecuidInfo",
    "currency_type": "int32_t",
    "symbol": "SecuidInfo",
    "secuid": "SecuidInfo",
    "cust_name": "SecuidInfo",
    "order_id": "SecuidInfo",
    "sno": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "order_side": "int16_t",
    "match_time": "long long",
    "match_code": "SecuidInfo",
    "match_times": "long long",
    "match_qty": "long long",
    "match_price": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "clear_amt": "SecuidInfo",
    "fee_yhs": "SecuidInfo",
    "fee_jsxf": "SecuidInfo",
    "fee_sxf": "SecuidInfo",
    "fee_ghf": "SecuidInfo",
    "fee_qsf": "SecuidInfo",
    "fee_jygf": "SecuidInfo",
    "fee_front": "SecuidInfo",
    "fee_jsf": "SecuidInfo",
    "fee_zgf": "SecuidInfo",
    "fee_other": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "stk_bal": "SecuidInfo",
    "order_qty": "long long",
    "order_price": "SecuidInfo",
    "source_type": "char",
    "bank_code": "SecuidInfo",
    "bank_id": "SecuidInfo",
    "counter_order_id": "SecuidInfo",
}

ModifyPasswordReq = {
    "old_password": "SecuidInfo",
    "new_password": "SecuidInfo",
    "password_type": "int16_t",
}

ModifyPasswordRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
}

QueryPHXXReq = {
    "query_index": "long long",
    "query_num": "long long",
    "stk_code": "SecuidInfo",
    "secuid": "SecuidInfo",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

QueryPHXXRecord = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "stk_code": "SecuidInfo",
    "match_qty": "long long",
    "mate_no": "SecuidInfo",
    "currency_type": "int16_t",
    "busi_type": "SecuidInfo",
    "link_stk_code": "SecuidInfo",
    "next_query_index": "long long",
    "total_num": "long long",
    "issue_stk_type": "char",
    "order_date": "int32_t",
}

QueryZQXXReq = {
    "query_index": "long long",
    "query_num": "long long",
    "stk_code": "SecuidInfo",
    "secuid": "SecuidInfo",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "market": "SecuidInfo",
}

QueryZQXXRecord = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "stk_code": "SecuidInfo",
    "stk_type": "SecuidInfo",
    "hit_qty": "long long",
    "match_price": "SecuidInfo",
    "order_date": "int32_t",
    "order_id": "SecuidInfo",
    "mate_no": "SecuidInfo",
    "currency_type": "int16_t",
    "busi_type": "SecuidInfo",
    "next_query_index": "long long",
    "total_num": "long long",
    "issue_stk_type": "char",
}

QryLockSecurityContractReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "symbol": "SecuidInfo",
    "status": "SecuidInfo",
}

LockSecurityContractDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "sys_date": "int32_t",
    "begin_date": "int32_t",
    "close_date": "int32_t",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "status": "char",
    "secuid": "SecuidInfo",
    "lock_charge_type": "int16_t",
    "first_in_mode": "int16_t",
    "reserve_qty": "long long",
    "stk_bal": "long long",
    "stk_avl": "long long",
    "stk_used_qty": "long long",
    "stk_sale": "long long",
    "stk_sale_frz": "long long",
    "stk_repay": "long long",
    "used_fee_rate": "SecuidInfo",
    "used_fee": "SecuidInfo",
    "unused_fee_rate": "SecuidInfo",
    "unused_fee": "SecuidInfo",
    "over_used_fee": "SecuidInfo",
    "over_unused_fee": "SecuidInfo",
    "puni_used_fee": "SecuidInfo",
    "puni_unused_fee": "SecuidInfo",
    "violate_fee_rate": "SecuidInfo",
    "violate_fee": "SecuidInfo",
    "over_violate_fee": "SecuidInfo",
    "puni_violate_fee": "SecuidInfo",
    "cust_id": "SecuidInfo",
}

CreditContractDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "f_credit_rate": "SecuidInfo",
    "f_year_mg_fee": "SecuidInfo",
    "f_year_sr_fee": "SecuidInfo",
    "d_credit_rate": "SecuidInfo",
    "d_year_mg_fee": "SecuidInfo",
    "d_year_sr_fee": "SecuidInfo",
    "cancel_date": "int32_t",
    "currency_type": "int16_t",
    "contract_limit": "int32_t",
    "contract_status": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "f_prate": "SecuidInfo",
    "d_prate": "SecuidInfo",
    "contract_id": "SecuidInfo",
}

QryCreditDebtsCollectReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "symbol": "SecuidInfo",
}

CreditDebtsCollectDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "match_qty": "long long",
    "credit_repay": "SecuidInfo",
    "stk_repay": "long long",
    "credit_repay_unfrz": "SecuidInfo",
    "stk_repay_unfrz": "long long",
    "credit_bal": "SecuidInfo",
    "stk_bal": "long long",
    "last_price": "SecuidInfo",
    "market_value": "SecuidInfo",
    "credit_avl": "SecuidInfo",
    "debts_profit": "SecuidInfo",
    "adjust_profit": "SecuidInfo",
    "credit_fee": "SecuidInfo",
    "stk_debts_avl": "long long",
}

QryCreditDataReq = {
    "symbol": "SecuidInfo",
    "credit_direct": "char",
}

CreditDataDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "credit_direct": "char",
    "margin_avl": "SecuidInfo",
    "credit_bal": "SecuidInfo",
    "credit_avl": "SecuidInfo",
    "margin_rate": "SecuidInfo",
    "debts_bal": "SecuidInfo",
    "max_amt": "SecuidInfo",
    "fund_avl": "SecuidInfo",
    "credit_fund_avl": "SecuidInfo",
    "g_dis_market_avl": "SecuidInfo",
    "mar_stk_val": "SecuidInfo",
    "total_dis_f_mk_val": "SecuidInfo",
    "mar_fund_profit": "SecuidInfo",
    "mar_stk_profit": "SecuidInfo",
    "total_rate_f_debts_bal": "SecuidInfo",
    "mar_fund_margin": "SecuidInfo",
    "mar_fund_margin_frz": "SecuidInfo",
    "total_rate_d_sale_bal": "SecuidInfo",
    "mar_stk_margin": "SecuidInfo",
    "mar_stk_margin_frz": "SecuidInfo",
    "total_fee": "SecuidInfo",
}

QryPreMaturityDebtsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "SecuidInfo",
}

PreMaturityDebtsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "secuid": "SecuidInfo",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "sys_date": "int32_t",
    "sno": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_date": "int32_t",
    "match_qty": "long long",
    "match_amt": "SecuidInfo",
    "leave_amt": "SecuidInfo",
    "leave_qty": "long long",
    "all_fee": "SecuidInfo",
    "apply_status": "int16_t",
    "apply_date": "int32_t",
    "apply_sno": "SecuidInfo",
    "apply_end_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "chk_remark": "SecuidInfo",
}

ExtendPreMaturityDebtsReq = {
    "sys_date": "int32_t",
    "sno": "SecuidInfo",
}

ExtendPreMaturityDebtsRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "apply_date": "int32_t",
    "apply_sno": "SecuidInfo",
}

QryPreMaturityDebtsExtensionReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "SecuidInfo",
}

PreMaturityDebtsExtensionDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "secuid": "SecuidInfo",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "apply_status": "int16_t",
    "sys_date": "int32_t",
    "apply_date": "int32_t",
    "apply_sno": "SecuidInfo",
    "sno": "SecuidInfo",
    "order_date": "int32_t",
    "order_id": "SecuidInfo",
    "match_qty": "long long",
    "match_amt": "SecuidInfo",
    "leave_amt": "SecuidInfo",
    "leave_value": "SecuidInfo",
    "chk_remark": "SecuidInfo",
    "cfm_ans": "SecuidInfo",
    "leave_qty": "long long",
}

QryVoteProposalReq = {
    "symbol": "SecuidInfo",
    "vote_symbol": "SecuidInfo",
}

VoteProposalDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "vote_symbol": "SecuidInfo",
    "vote_name": "SecuidInfo",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "meeting_type": "SecuidInfo",
    "meeting_desc": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "voting_proposal_code": "SecuidInfo",
    "voting_prososal_desc": "SecuidInfo",
    "voting_proposal_type": "char",
    "cum_voting_chosen_num": "long long",
    "share_holder_role": "SecuidInfo",
    "proposal_relation": "SecuidInfo",
    "share_class": "SecuidInfo",
    "reg_date": "int32_t",
}

QryCreditVoteCountReq = {
    "symbol": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
}

CreditVoteCountDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
    "rest_qty": "long long",
    "stk_name": "SecuidInfo",
}

QryCreditVoteReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "code": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
}

CreditVoteDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "secuid": "SecuidInfo",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "link_symbol": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
    "voting_preference": "int16_t",
    "stk_bal": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "link_stk_name": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "meeting_desc": "SecuidInfo",
    "voting_proposal_type": "char",
    "voting_prososal_desc": "SecuidInfo",
    "key_error_code": "SecuidInfo",
    "key_error_msg": "SecuidInfo",
}

QryNetVoteRightsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "market": "SecuidInfo",
    "stk_code": "SecuidInfo",
}

NetVoteRightsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "secuid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "reg_date": "int32_t",
    "voting_proposal": "SecuidInfo",
    "voting_relation": "SecuidInfo",
    "total_num": "int32_t",
}

QryNetVoteResultReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "SecuidInfo",
    "vote_code": "SecuidInfo",
}

NetVoteResultDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "busi_date": "int32_t",
    "contract_id": "SecuidInfo",
    "vote_symbol": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "fund_id": "SecuidInfo",
    "secuid": "SecuidInfo",
    "vote_qty": "long long",
    "cur_vote_qty": "long long",
    "voting_proposal": "SecuidInfo",
    "vote_info": "SecuidInfo",
    "vote_type": "char",
    "total_num": "int32_t",
    "vote_name": "SecuidInfo",
}

QryNetVoteCountReq = {
    "secuid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "vote_code": "SecuidInfo",
    "reg_date": "int32_t",
}

NetVoteCountDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "vote_qty": "long long",
}

QryCreditDebtsFlowReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "currency_type": "int16_t",
}

CreditDebtsFlowDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "currency_type": "int16_t",
    "debt_type": "char",
    "effect_direct": "char",
    "repay_way": "char",
    "stk_code": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "details_sno": "SecuidInfo",
    "relate_sys_date": "int32_t",
    "relate_sno": "SecuidInfo",
    "market_id": "int32_t",
    "fund_effect": "SecuidInfo",
    "stk_effect": "long long",
}

QryCreditAssetFlowReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditAssetFlowDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "biz_date": "int32_t",
    "details_sno": "SecuidInfo",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "digest_id": "int32_t",
    "digest_name": "SecuidInfo",
    "currency_type": "int16_t",
    "secuid": "SecuidInfo",
    "market_id": "int32_t",
    "fund_effect": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "stk_bal": "long long",
    "stk_code": "SecuidInfo",
    "stk_name": "SecuidInfo",
    "busi_type": "SecuidInfo",
    "side": "int16_t",
    "match_price": "SecuidInfo",
    "match_qty": "long long",
    "match_amt": "SecuidInfo",
    "order_id": "SecuidInfo",
    "pos_str": "SecuidInfo",
}

QueryCreditDebtsReq = {
    "credit_direct": "char",
    "qry_direct": "char",
    "sys_date": "int32_t",
    "sno": "SecuidInfo",
    "currency_type": "int16_t",
    "symbol": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

CreditDebtsDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "sys_date": "int32_t",
    "end_date": "int32_t",
    "sno": "SecuidInfo",
    "currency_type": "int16_t",
    "symbol": "SecuidInfo",
    "security_symbol": "SecuidInfo",
    "order_date": "int32_t",
    "order_id": "long long",
    "secuid": "SecuidInfo",
    "life_status": "int16_t",
    "d_stk_bal": "long long",
    "f_deal_bal": "SecuidInfo",
    "f_deal_avl": "SecuidInfo",
    "init_cost_price": "SecuidInfo",
    "prof_cost_price": "SecuidInfo",
    "profit_cost": "SecuidInfo",
    "stk_repay_unfrz": "long long",
    "fee_unfrz": "SecuidInfo",
    "over_due_fee_unfrz": "SecuidInfo",
    "puni_fee_unfrz": "SecuidInfo",
    "over_due_rights_unfrz": "SecuidInfo",
    "puni_rights_unfrz": "SecuidInfo",
    "puni_debts_unfrz": "SecuidInfo",
    "all_fee_unfrz": "SecuidInfo",
    "relese_amt": "SecuidInfo",
    "relese_amt_unfrz": "SecuidInfo",
    "credit_repay_unfrz": "SecuidInfo",
    "f_exp_cet_intr": "SecuidInfo",
    "f_debt_qty": "SecuidInfo",
    "d_stk_avl": "long long",
    "last_price": "SecuidInfo",
    "mkt_val": "SecuidInfo",
    "buy_cost": "SecuidInfo",
    "exp_cet_intr": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "credit_direct": "char",
    "match_qty": "long long",
    "stk_repay": "long long",
    "clear_amt": "SecuidInfo",
    "credit_repay": "SecuidInfo",
}

StkConcentrationReq = {
    "query_index": "SecuidInfo",
    "query_num": "int32_t",
    "symbol": "SecuidInfo",
    "market": "SecuidInfo",
}

StkConcentrationDetail = {
    "market_id": "int32_t",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "keep_rate_begin": "long long",
    "keep_rate_end": "long long",
    "debt_begin": "long long",
    "debt_end": "long long",
    "ctrl_rate": "long long",
}

MarginRiskDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "rt_risk_rate": "SecuidInfo",
}

QryHKHisOrderReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "SecuidInfo",
    "secuid": "SecuidInfo",
    "stk_code": "SecuidInfo",
    "order_id": "SecuidInfo",
    "bank_code": "SecuidInfo",
    "qry_direct": "char",
}

HKHisOrderDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "trd_flow_id": "SecuidInfo",
    "order_id": "SecuidInfo",
    "order_status": "int32_t",
    "currency_type": "int16_t",
    "symbol": "SecuidInfo",
    "secuid": "SecuidInfo",
    "order_qty": "long long",
    "order_price": "SecuidInfo",
    "order_frz_amt": "SecuidInfo",
    "trade_fee": "SecuidInfo",
    "settle_fee": "SecuidInfo",
    "net_price": "SecuidInfo",
    "return_rate": "SecuidInfo",
    "total_bond_intr": "SecuidInfo",
    "settle_days": "int32_t",
    "end_order_date": "int32_t",
    "settle_date": "int32_t",
    "settle_mode": "int16_t",
    "price_type": "int16_t",
    "match_type": "int16_t",
    "stk_name": "SecuidInfo",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "match_price": "SecuidInfo",
    "match_qty": "long long",
    "cancel_qty": "long long",
    "order_side": "int16_t",
    "contract_sno": "SecuidInfo",
    "refer_rate": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "total_num": "int32_t",
    "main_seat": "SecuidInfo",
    "match_amt": "SecuidInfo",
    "remark": "SecuidInfo",
    "report_time": "long long",
    "cust_id": "SecuidInfo",
    "cust_name": "SecuidInfo",
}

QueryWithdrawCashReq = {
    "market": "SecuidInfo",
}

WithdrawCashRecord = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "currency_type": "int16_t",
    "total_asset": "SecuidInfo",
    "fund_bal": "SecuidInfo",
    "fund_avl": "SecuidInfo",
    "fetch_bal": "SecuidInfo",
}

QryTradeListTotalReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "order_id": "SecuidInfo",
    "market": "SecuidInfo",
    "stkcode": "SecuidInfo",
}

QryNetVoteOrderReq = {
    "market": "SecuidInfo",
    "meeting_seq": "SecuidInfo",
    "voting_proposal_code": "SecuidInfo",
    "stock_code": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
}

NetVoteOrderDetail = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_id": "long long",
    "order_group": "long long",
    "contract_id": "SecuidInfo",
    "order_date": "int32_t",
    "cust_id": "SecuidInfo",
    "cust_name": "SecuidInfo",
    "currency_type": "int32_t",
    "symbol": "SecuidInfo",
    "name": "SecuidInfo",
    "seat": "SecuidInfo",
    "stktype": "int16_t",
    "side": "int16_t",
    "meeting_seq": "SecuidInfo",
    "voting_proposal_code": "SecuidInfo",
    "voting_preference": "long long",
    "voting_segment": "SecuidInfo",
    "total_qty": "long long",
    "counter_order_time": "int32_t",
    "order_status": "int16_t",
    "secuid": "SecuidInfo",
    "remark": "SecuidInfo",
}

ETFSubscriptCancelReq = {
    "order_date": "int32_t",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

ETFSubscriptCancelRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "order_date": "int32_t",
    "order_id": "SecuidInfo",
    "cl_order_id": "SecuidInfo",
    "cl_cancel_id": "SecuidInfo",
}

NetVoteOrderReq = {
    "symbol": "SecuidInfo",
    "link_stk_code": "SecuidInfo",
    "order_qty": "long long",
    "reg_date": "int32_t",
    "meeting_seq": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
    "voting_preference": "int16_t",
    "voting_segment": "SecuidInfo",
}

NetVoteOrderRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "contract_id": "SecuidInfo",
    "order_sno": "long long",
    "order_status": "int16_t",
    "report_time": "long long",
    "cust_id": "SecuidInfo",
    "secuid": "SecuidInfo",
    "symbol": "SecuidInfo",
    "reject_code": "SecuidInfo",
    "reject_msg": "SecuidInfo",
    "order_group": "int32_t",
}

CreditNetVoteOrderReq = {
    "symbol": "SecuidInfo",
    "link_stk_code": "SecuidInfo",
    "reg_date": "int32_t",
    "currency_type": "int16_t",
    "order_qty": "long long",
    "meeting_seq": "SecuidInfo",
    "voting_proposal": "SecuidInfo",
    "voting_preference": "int16_t",
}

CreditNetVoteOrderRsp = {
    "account_id": "SecuidInfo",
    "account_type": "int16_t",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "reject_code": "SecuidInfo",
    "reject_msg": "SecuidInfo",
    "level": "SecuidInfo",
    "cust_id": "SecuidInfo",
    "secuid": "SecuidInfo",
    "symbol": "SecuidInfo",
}

QueryMSCashReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCashDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "pos_str": "SecuidInfo",
    "busidate": "int32_t",
    "custid": "SecuidInfo",
    "fundunit": "SecuidInfo",
    "currency_type": "int32_t",
    "subjectcode": "SecuidInfo",
    "settbody": "SecuidInfo",
    "orgid": "SecuidInfo",
    "brhid": "SecuidInfo",
    "trdsysid": "SecuidInfo",
    "coreid": "SecuidInfo",
    "fundid": "SecuidInfo",
    "subjectname": "SecuidInfo",
    "startbal": "SecuidInfo",
    "endbal": "SecuidInfo",
    "fundrealcommit": "SecuidInfo",
    "awardamt": "SecuidInfo",
    "punishamt": "SecuidInfo",
    "totalnum": "long long",
}

QueryMSPositionsReq = {
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSPositionsDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "pos_str": "SecuidInfo",
    "busidate": "int32_t",
    "custid": "SecuidInfo",
    "fundunit": "SecuidInfo",
    "stkholdunit": "SecuidInfo",
    "secuid": "SecuidInfo",
    "mainseat": "SecuidInfo",
    "symbol": "SecuidInfo",
    "direction": "int16_t",
    "investtype": "int16_t",
    "stkid": "SecuidInfo",
    "stkproperty": "int16_t",
    "subjectcode": "SecuidInfo",
    "settbody": "SecuidInfo",
    "trdsysid": "SecuidInfo",
    "coreid": "SecuidInfo",
    "currency_type": "int32_t",
    "schemeid": "SecuidInfo",
    "subjectname": "SecuidInfo",
    "startbal": "SecuidInfo",
    "endbal": "SecuidInfo",
    "startcost": "SecuidInfo",
    "endcost": "SecuidInfo",
    "startcostwithfee": "SecuidInfo",
    "endcostwithfee": "SecuidInfo",
    "starttradefee": "SecuidInfo",
    "endtradefee": "SecuidInfo",
    "startprofit": "SecuidInfo",
    "endprofit": "SecuidInfo",
    "startprofitwithfee": "SecuidInfo",
    "endprofitwithfee": "SecuidInfo",
    "startintrcost": "SecuidInfo",
    "endintrcost": "SecuidInfo",
    "startintrprofit": "SecuidInfo",
    "endintrprofit": "SecuidInfo",
    "tacode": "SecuidInfo",
    "transacct": "SecuidInfo",
    "taacct": "SecuidInfo",
    "linkstkid": "SecuidInfo",
    "extint": "int32_t",
    "extamt": "SecuidInfo",
    "extchar": "SecuidInfo",
    "extstr": "SecuidInfo",
    "totalnum": "long long",
}

QueryMSCreditDebtsFlowReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "SecuidInfo",
    "code": "SecuidInfo",
    "pos_str": "SecuidInfo",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCreditDebtsFlowDetail = {
    "account_id": "SecuidInfo",
    "cust_orgid": "SecuidInfo",
    "cust_branchid": "SecuidInfo",
    "account_type": "int16_t",
    "pos_str": "SecuidInfo",
    "busidate": "int32_t",
    "operdate": "int32_t",
    "sysdate": "int32_t",
    "logno": "SecuidInfo",
    "custid": "SecuidInfo",
    "creditdebtstype": "char",
    "lifekind": "bool",
    "direct": "char",
    "paykind": "char",
    "fundeffect": "SecuidInfo",
    "fundbal": "SecuidInfo",
    "stkeffect": "SecuidInfo",
    "stkbal": "SecuidInfo",
    "reladate": "int32_t",
    "relasno": "SecuidInfo",
    "symbol": "SecuidInfo",
    "remark": "SecuidInfo",
    "bizdate": "int32_t",
    "logassetsno": "SecuidInfo",
    "totalnum": "long long",
}

