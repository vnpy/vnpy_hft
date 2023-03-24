RiskNotify = {
    "secuid": "string",
    "alarm_score": "string",
    "alarm_status": "string",
    "alarm_rule": "string",
    "alarm_time": "string",
    "alarm_msg": "string",
}

FailBackNotify = {
    "system_id": "string",
    "node_id": "string",
    "status": "char",
    "credit_node_flag": "char",
    "urgent_flag": "char",
    "update_source": "string",
}

AccountInfo = {
    "account_id": "string",
    "account_type": "int16_t",
    "account_pwd": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_system_id": "string",
}

LoginReq = {
    "account_id": "string",
    "account_type": "int16_t",
    "account_pwd": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_system_id": "string",
    "svr_ip": "string",
    "svr_port": "int",
    "terminal_info": "string",
    "inner_flag": "int16_t",
}

SecuidInfo = {
    "market": "string",
    "secuid": "string",
    "fund_id": "string",
    "account_type": "int16_t",
    "account_status": "char",
    "account_class": "char",
    "account_rights": "string",
    "account_hgtright": "char",
}

LoginRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cust_id": "string",
    "cust_name": "string",
    "secuid_array": "str",
    "cif_account": "string",
    "user_code": "string",
    "user_token": "string",
    "token_serial_no": "string",
    "sm3_cipher": "string",
    "sys_node_type": "int",
    "clear_switch_flag": "char",
    "trade_switch_flag": "char",
    "sys_server_id": "string",
    "operway": "char",
    "sys_shbond_type": "int16_t",
    "ext_secuid_array": "str",
    "reg_branchid": "string",
}

OrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "int64_t",
    "price": "int64_t",
    "order_flag": "int16_t",
    "policy_id": "uint16_t",
    "share_property": "int16_t",
}

OrderRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_date": "int32_t",
    "order_id": "string",
    "cl_order_id": "string",
    "contract_id": "string",
    "ex_order_id": "string",
}

CancelReq = {
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "int64_t",
    "price": "int64_t",
}

BatchCancelAllReq = {
    "cust_id": "string",
    "secu_id": "string",
    "symbol": "string",
    "market": "int32_t",
}

CancelRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
    "cancel_id": "string",
    "ex_order_id": "string",
}

QryByOrderIdReq = {
    "order_id": "string",
    "market": "string",
}

QryByCodeReq = {
    "symbol": "string",
}

QryOrderByCodeReq = {
    "symbol": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

QryOrdersReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "query_flag": "int",
    "market": "string",
}

OrderDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "string",
    "cl_order_id": "string",
    "orig_order_id": "string",
    "symbol": "string",
    "order_status": "int16_t",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "int64_t",
    "price": "int64_t",
    "filled_volume": "int64_t",
    "filled_turnover": "int64_t",
    "filled_price": "int64_t",
    "cancel_volume": "int64_t",
    "cancel_flag": "int16_t",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "string",
    "secuid": "string",
    "name": "string",
    "freeze_amount": "int64_t",
    "contract_id": "string",
    "ex_order_id": "string",
}

QryTradeByCodeReq = {
    "symbol": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

QryTradesReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
    "filter_etf": "bool",
    "counter_order_id": "string",
}

QryETFTradesReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
    "counter_order_id": "string",
    "qry_direct": "char",
}

TradeDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "string",
    "cl_order_id": "string",
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "report_type": "int16_t",
    "report_no": "string",
    "volume": "int64_t",
    "price": "int64_t",
    "turnover": "int64_t",
    "trade_date": "int32_t",
    "trade_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "string",
    "secuid": "string",
    "name": "string",
    "contract_id": "string",
    "ex_report_no": "string",
    "ex_order_id": "string",
    "margin_amt_type": "int16_t",
    "order_price": "int64_t",
    "order_qty": "int64_t",
}

QryPositionsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
}

PositionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "side": "int16_t",
    "volume": "int64_t",
    "avail_volume": "int64_t",
    "init_volume": "int64_t",
    "market_value": "int64_t",
    "today_buy_volume": "int64_t",
    "today_sell_volume": "int64_t",
    "secuid": "string",
    "cost_price": "int64_t",
    "buy_cost": "int64_t",
    "last_price": "int64_t",
    "income": "int64_t",
    "total_income": "int64_t",
    "profit_cost": "int64_t",
    "today_avail_pr_volume": "int64_t",
    "market": "int32_t",
    "security_type": "int32_t",
    "freeze_volume": "int64_t",
    "name": "string",
    "currency_type": "int32_t",
    "security_type_apex": "int32_t",
    "profit_price": "int64_t",
}

QryCashReq = {
    "market": "string",
}

CashDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "total_amount": "int64_t",
    "avail_amount": "int64_t",
    "total_asset": "int64_t",
    "market_value": "int64_t",
    "init_amount": "int64_t",
    "fetch_balance": "int64_t",
}

JZJYAvailFundDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "avail_amount": "int64_t",
}

TransferFundReq = {
    "transfer_side": "int",
    "transfer_value": "int64_t",
    "market": "string",
}

TransferFundRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "transfer_value": "int64_t",
}

TransferFundSecuidReq = {
    "fund_out_market": "string",
    "fund_in_market": "string",
    "transfer_value": "int64_t",
}

TransferFundSecuidRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "transfer_value": "int64_t",
}

QryETFsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

ETFDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "name": "string",
    "first_symbol": "string",
    "second_symbol": "string",
    "trade_unit": "int32_t",
    "cash_component": "int64_t",
    "max_cash_ratio": "int64_t",
    "trade_state": "int32_t",
    "record_num": "int32_t",
    "trade_day": "int32_t",
    "pre_trade_day": "int32_t",
    "nav_percu": "int64_t",
    "nav": "int64_t",
    "creation_limituser": "int64_t",
    "redemption_limituser": "int64_t",
    "net_creation_limituser": "int64_t",
    "net_redemption_limituser": "int64_t",
    "creation_limit": "int64_t",
    "redemption_limit": "int64_t",
    "net_creation_limit": "int64_t",
    "net_redemption_limit": "int64_t",
    "etf_type": "int32_t",
    "cash_component_t1": "int64_t",
    "internal_trade_state": "int32_t",
}

QryETFStocksReq = {
    "first_symbol": "string",
    "sz_ksc_type": "int",
    "pos_str": "string",
    "query_num": "int32_t",
}

ETFStockDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "first_symbol": "string",
    "name": "string",
    "symbol": "string",
    "volume": "int32_t",
    "replace_flag": "int16_t",
    "over_price_rate": "int64_t",
    "replace_amt": "int64_t",
}

QryMaxOrderQtyReq = {
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "price": "int64_t",
}

MaxOrderQtyDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_qty": "int64_t",
    "actual_max_qty": "int64_t",
    "max_pay_amt": "int64_t",
    "max_pay_qty": "int64_t",
    "sep_rem_qty": "int64_t",
}

IPOMaxPurchaseDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "max_qty": "int64_t",
    "stib_max_qty": "int64_t",
    "secuid": "string",
}

QueryIPOStockReq = {
    "query_flag": "int16_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

IPOStockDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "currency_type": "int16_t",
    "ipo_price": "int64_t",
    "max_num": "int64_t",
    "min_num": "int64_t",
    "security_type": "int32_t",
}

SecurityBaseInfo = {
    "symbol": "string",
    "name": "string",
    "security_type": "int32_t",
    "security_status": "int32_t",
    "price_tick": "int64_t",
    "limit_up": "int64_t",
    "limit_down": "int64_t",
    "max_qty": "int64_t",
    "min_qty": "int64_t",
    "buy_tick": "int64_t",
    "sale_tick": "int64_t",
    "has_price_limit": "int32_t",
    "limit_up_rate": "int32_t",
    "is_registration": "int32_t",
    "limit_down_rate": "int32_t",
    "trade_id": "char",
}

QryByMarketReq = {
    "market": "string",
}

HKRateDetail = {
    "market": "string",
    "buy_rate": "int64_t",
    "sale_rate": "int64_t",
    "mid_rate": "int64_t",
    "set_rate": "int64_t",
    "sys_date": "int32_t",
}

QryHKStock = {
    "market": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

HKStockDetail = {
    "symbol": "string",
    "name": "string",
    "stktype": "int16_t",
    "currency_type": "int16_t",
    "security_type": "int32_t",
}

HKFundDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "fund_uncomeavl": "int64_t",
    "fund_buy": "int64_t",
    "fund_sale": "int64_t",
    "fund_uncomebuy": "int64_t",
    "fund_uncomesale": "int64_t",
}

QryHKMinPriceUnitReq = {
    "market": "string",
    "code": "string",
    "price": "int64_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

HKMinPriceUnitDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "stktype": "int16_t",
    "begin_price": "int64_t",
    "end_price": "int64_t",
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
    "cl_order_id": "string",
    "symbol": "string",
    "side": "int16_t",
    "volume": "int32_t",
    "opp_fund_id": "string",
    "opp_secu_id": "string",
}

CreditMortgageInOutRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_order_id": "string",
    "order_id": "string",
    "contract_id": "string",
}

CreditStockBackReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "volume": "int32_t",
}

CreditStockBackRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_order_id": "string",
    "order_id": "string",
    "contract_id": "string",
}

CreditPayBackReq = {
    "back_amt": "int64_t",
    "cl_order_id": "string",
}

CreditPayBackByOrderReq = {
    "sno": "string",
    "order_date": "int",
    "back_amt": "int64_t",
    "cl_order_id": "string",
    "credit_type": "int32_t",
}

CreditPayBackRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "real_back_amt": "int64_t",
    "cl_order_id": "string",
}

QryCreditStockReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditStockDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "currency_type": "int16_t",
    "credit_fund_ctrl": "char",
    "credit_stk_ctrl": "char",
    "margin_rate_fund": "int64_t",
    "margin_rate_stk": "int64_t",
    "sep_rem_qty": "int32_t",
}

CreditAssetsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "avail_balance": "int64_t",
    "fetch_balance": "int64_t",
    "frozen_balance": "int64_t",
    "stock_balance": "int64_t",
    "fund_balance": "int64_t",
    "asset_balance": "int64_t",
    "avail_margin": "int64_t",
    "credit_quota": "int64_t",
    "finance_quota": "int64_t",
    "shortsell_quota": "int64_t",
    "assure_ratio": "int64_t",
    "total_debt": "int64_t",
    "fund_debt": "int64_t",
    "stock_debt": "int64_t",
    "fund_interest_fee": "int64_t",
    "stock_interest_fee": "int64_t",
    "shortsell_total_balance": "int64_t",
    "shortsell_avail_balance": "int64_t",
    "shortsell_frozen_balance": "int64_t",
    "enbuyback_avail_balance": "int64_t",
    "fund_margin_profit": "int64_t",
    "stock_margin_profit": "int64_t",
    "fund_interest": "int64_t",
    "stock_interest": "int64_t",
    "fund_margin_balance": "int64_t",
    "stock_margin_balance": "int64_t",
    "fund_floating_deficit": "int64_t",
    "stock_floating_deficit": "int64_t",
    "fund_margin_profit_conversion": "int64_t",
    "stock_margin_profit_conversion": "int64_t",
    "hbjj_bal": "int64_t",
}

QryCreditFinanceReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditFinanceDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "sno": "string",
    "currency_type": "int16_t",
    "life_status": "int16_t",
    "occur_date": "int32_t",
    "total_balance": "int64_t",
    "cur_balance": "int64_t",
    "total_interest_fee": "int64_t",
    "cur_interest_fee": "int64_t",
    "interest_rate": "int64_t",
    "repayable_balance": "int64_t",
    "f_deal_bal": "int64_t",
    "f_exp_cet_intr": "int64_t",
    "credit_repay_unfrz": "int64_t",
    "all_fee_unfrz": "int64_t",
    "market": "int32_t",
    "pos_str": "string",
    "end_date": "int32_t",
}

QryCreditShortsellReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditShortsellDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "sno": "string",
    "currency_type": "int16_t",
    "life_status": "int16_t",
    "occur_date": "int32_t",
    "total_qty": "int64_t",
    "cur_qty": "int64_t",
    "total_interest_fee": "int64_t",
    "cur_interest_fee": "int64_t",
    "interest_rate": "int64_t",
    "d_stk_bal": "int64_t",
    "market": "int32_t",
    "all_fee_unfrz": "int64_t",
    "stk_repay_unfrz": "int64_t",
    "end_date": "int32_t",
    "init_cost_price": "int64_t",
}

CreditRepayAmountDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_back_amt": "int64_t",
}

QryCreditRepayStockReq = {
    "market": "string",
    "code": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditRepayStockDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "total_qty": "int64_t",
    "max_back_qty": "int64_t",
    "returned_qty": "int64_t",
}

QryCreditMortgageHoldReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditMortgageHoldDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "currency_type": "int16_t",
    "pledge_rate": "int64_t",
}

QryCreditSecuritySellQtyReq = {
    "market": "string",
    "code": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditSecuritySellQtyRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "total_qty": "int64_t",
    "avail_qty": "int64_t",
}

QrySecuidRightReq = {
    "market": "string",
    "secuid_right": "int16_t",
}

QrySecuidRightRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "secuid_right": "int16_t",
    "sign_flag": "bool",
}

OptionCashDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "init_amount": "int64_t",
    "total_amount": "int64_t",
    "avail_amount": "int64_t",
    "fetch_amount": "int64_t",
    "frozen_amount": "int64_t",
    "used_margin": "int64_t",
    "exercise_frozen": "int64_t",
    "deposit_amount": "int64_t",
    "withdraw_amount": "int64_t",
    "royalty_in": "int64_t",
    "royalty_out": "int64_t",
    "commission": "int64_t",
    "frozen_commission": "int64_t",
}

OptionPositionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "side": "int16_t",
    "init_volume": "int64_t",
    "init_avail_volume": "int64_t",
    "init_comb_volume": "int64_t",
    "volume": "int64_t",
    "avail_volume": "int64_t",
    "comb_volume": "int64_t",
    "open_volume": "int64_t",
    "close_volume": "int64_t",
    "exercise_frozen": "int64_t",
    "buy_cost": "int64_t",
    "secuid": "string",
    "margin": "int64_t",
    "frozen_margin": "int64_t",
    "commission": "int64_t",
    "frozen_commission": "int64_t",
    "exercise_frozen_amount": "int64_t",
    "frozen_amount": "int64_t",
    "today_close_profit": "int64_t",
    "buy_quota_used": "int64_t",
    "last_price": "int64_t",
    "underlying_multiple": "int64_t",
}

ExerciseReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "volume": "int64_t",
    "exercise_type": "int16_t",
}

ExerciseRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_order_id": "string",
    "order_id": "string",
    "exercise_type": "int16_t",
}

CancelExerciseReq = {
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

CancelExerciseRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

QryExercisesReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

ExerciseDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "exercise_type": "int16_t",
    "cl_order_id": "string",
    "order_id": "string",
    "counter_order_date": "int32_t",
    "counter_order_time": "int32_t",
    "counter_cancel_time": "int32_t",
    "exercise_status": "int32_t",
    "oper_status": "int32_t",
    "symbol": "string",
    "volume": "int32_t",
    "cancel_volume": "int32_t",
    "err_code": "int32_t",
    "err_msg": "string",
}

ContractInfo = {
    "contract_id": "string",
    "exch_contract_id": "string",
    "contract_name": "string",
    "underlying_contract_id": "string",
    "underlying_contract_name": "string",
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
    "price_tick": "int64_t",
    "contract_status": "int32_t",
    "strike_price": "int64_t",
    "first_date": "int32_t",
    "last_date": "int32_t",
    "strike_date": "int32_t",
    "expire_date": "int32_t",
    "deliv_date": "int32_t",
    "is_up_down_limit": "int32_t",
    "margin_unit": "int64_t",
    "pre_settlement_price": "int64_t",
    "pre_close_price": "int64_t",
    "underlying_pre_close_price": "int64_t",
}

TransferStockReq = {
    "symbol": "string",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "int64_t",
}

TransferStockRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "int64_t",
}

TransferStockDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "serial_number": "string",
    "symbol": "string",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "yesterday_volume": "int64_t",
    "today_bs_volume": "int64_t",
    "today_pr_volume": "int64_t",
    "stock_cust_id": "string",
    "stock_secuid": "string",
    "status_msg": "string",
}

LockOrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "lock_type": "int16_t",
    "volume": "int64_t",
}

LockOrderRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "lock_type": "int16_t",
    "order_id": "string",
    "cl_order_id": "string",
}

QryLockOrdersReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

LockOrderDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "cl_order_id": "string",
    "order_id": "string",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "lock_type": "int16_t",
    "lock_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "string",
}

CombOrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "exch_comb_id": "string",
}

CombOrderRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "comb_type": "int16_t",
    "order_id": "string",
    "cl_order_id": "string",
}

CombExerciseReq = {
    "cl_order_id": "string",
    "call_symbol": "string",
    "put_symbol": "string",
    "volume": "int64_t",
}

CombExerciseRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cl_order_id": "string",
    "order_id": "string",
}

CancelCombExerciseReq = {
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

CancelCombExerciseRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

QryCombOrdersReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CombOrderDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "exch_comb_id": "string",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "cl_order_id": "string",
    "order_id": "string",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "order_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "string",
}

QryCombExercisesReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CombExerciseDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "call_symbol": "string",
    "put_symbol": "string",
    "cl_order_id": "string",
    "order_id": "string",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "exercise_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "string",
}

CombPositionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "avail_volume": "int64_t",
    "yesterday_volume": "int64_t",
    "yesterday_avail_volume": "int64_t",
    "today_volume": "int64_t",
    "today_avail_volume": "int64_t",
    "margin": "int64_t",
    "frozen_margin": "int64_t",
    "commission": "int64_t",
    "frozen_commission": "int64_t",
    "secuid": "string",
}

CombPositionSubDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "comb_strategy": "int16_t",
    "exch_comb_id": "string",
    "volume": "int64_t",
    "yesterday_volume": "int64_t",
    "today_volume": "int64_t",
    "comb_date": "int32_t",
    "comb_time": "int32_t",
    "comb_status": "int16_t",
    "secuid": "string",
    "legs_num": "int32_t",
    "leg1_symbol": "string",
    "leg1_yesterday_volume": "int64_t",
    "leg1_today_volume": "int64_t",
    "leg1_pos_side": "int16_t",
    "leg1_option_type": "int16_t",
    "leg2_symbol": "string",
    "leg2_yesterday_volume": "int64_t",
    "leg2_today_volume": "int64_t",
    "leg2_pos_side": "int16_t",
    "leg2_option_type": "int16_t",
    "yesterday_split_frozen_volume": "int64_t",
    "today_split_frozen_volume": "int64_t",
    "leg1_yesterday_split_frozen_volume": "int64_t",
    "leg1_today_split_frozen_volume": "int64_t",
    "leg2_yesterday_split_frozen_volume": "int64_t",
    "leg2_today_split_frozen_volume": "int64_t",
}

CombContractInfo = {
    "contract_id": "string",
    "comb_strategy": "int16_t",
    "leg1_contract_id": "string",
    "leg1_name": "string",
    "leg1_side": "int16_t",
    "leg2_contract_id": "string",
    "leg2_name": "string",
    "leg2_side": "int16_t",
}

QryLockSecurityReq = {
    "start_date": "int",
    "end_date": "int",
    "market": "string",
    "code": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

LockSecurityDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "sys_date": "int32_t",
    "sno": "string",
    "symbol": "string",
    "name": "string",
    "lock_type": "int16_t",
    "used_fee_rate": "int64_t",
    "unused_fee_rate": "int64_t",
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
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "serial_number": "string",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_value": "int64_t",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "remark": "string",
}

PositionLimitsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "avail_total_limit": "int64_t",
    "avail_long_limit": "int64_t",
    "avail_today_open_limit": "int64_t",
    "avail_today_buy_open_limit": "int64_t",
    "avail_today_sell_open_limit": "int64_t",
    "avail_today_covered_open_limit": "int64_t",
    "avail_long_call_limit": "int64_t",
    "avail_long_put_limit": "int64_t",
    "avail_long_underlying_limit": "int64_t",
    "avail_short_underlying_limit": "int64_t",
    "total_limit": "int64_t",
    "long_limit": "int64_t",
    "today_open_limit": "int64_t",
    "today_buy_open_limit": "int64_t",
    "today_sell_open_limit": "int64_t",
    "today_covered_open_limit": "int64_t",
    "long_call_limit": "int64_t",
    "long_put_limit": "int64_t",
    "long_underlying_limit": "int64_t",
    "short_underlying_limit": "int64_t",
}

QryAmountLimitsReq = {
    "market": "string",
}

AmountLimitsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "long_amount_limit": "int64_t",
    "avail_long_amount_limit": "int64_t",
    "market": "string",
}

QrySplitCombMarginDiffReq = {
    "contract_id": "string",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "exch_comb_id": "string",
}

SplitCombMarginDiffDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "contract_id": "string",
    "exch_comb_id": "string",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "left_leg_pos_margin": "int64_t",
    "left_leg_pos_live_margin": "int64_t",
    "right_leg_pos_margin": "int64_t",
    "right_leg_pos_live_margin": "int64_t",
    "comb_pos_margin": "int64_t",
    "comb_pos_live_margin": "int64_t",
    "margin_difference": "int64_t",
    "margin_live_difference": "int64_t",
}

QryExerciseAppointmentReq = {
    "market": "string",
    "contract_id": "string",
}

ExerciseAppointmentDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "contract_id": "string",
    "counter_order_date": "int32_t",
    "secuid": "string",
    "options_type": "int32_t",
    "option_unit": "int64_t",
    "underlying_contract_id": "string",
    "volume": "int64_t",
    "exercise_price": "int64_t",
    "exercise_side": "int32_t",
    "cover_flag": "int32_t",
}

QryOptionMaxOrderVolumeReq = {
    "contract_id": "string",
    "side": "int16_t",
    "order_type": "int16_t",
    "order_flag": "int16_t",
    "price": "int64_t",
}

OptionMaxOrderVolumeDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_volume": "int64_t",
}

QryOptionHisOrderReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisOrderDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "trade_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "contract_id": "string",
    "status": "int32_t",
    "market": "string",
    "secuid": "string",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_num": "string",
    "option_code": "string",
    "option_name": "string",
    "comb_num": "string",
    "comb_strategy": "int16_t",
    "leg1_num": "string",
    "leg2_num": "string",
    "leg3_num": "string",
    "leg4_num": "string",
    "currency_type": "int16_t",
    "price": "int64_t",
    "qty": "int32_t",
    "order_amt": "int64_t",
    "order_frozen_amt": "int64_t",
    "order_unfrozen_amt": "int64_t",
    "offer_qty": "int32_t",
    "offer_time": "int64_t",
    "cancel_qty": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "cancel_flag": "int32_t",
    "underlying_code": "string",
    "underlying_name": "string",
    "underlying_frozen_qty": "int64_t",
    "underlying_unfrozen_qty": "int64_t",
    "underlying_cancel_qty": "int64_t",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "string",
    "leg2_name": "string",
    "leg3_name": "string",
    "leg4_name": "string",
}

QryOptionHisTradeReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisTradeDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "trade_date": "int32_t",
    "trade_time": "int64_t",
    "order_date": "int32_t",
    "counter_order_id": "string",
    "contract_id": "string",
    "match_id": "string",
    "market": "string",
    "secuid": "string",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "string",
    "option_name": "string",
    "comb_num": "string",
    "comb_strategy": "int16_t",
    "leg1_num": "string",
    "leg2_num": "string",
    "leg3_num": "string",
    "leg4_num": "string",
    "currency_type": "int16_t",
    "underlying_code": "string",
    "underlying_name": "string",
    "price": "int64_t",
    "qty": "int32_t",
    "order_frozen_amt": "int64_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "string",
    "leg2_name": "string",
    "leg3_name": "string",
    "leg4_name": "string",
}

QryHisExerciseAppointmentReq = {
    "currency_type": "int16_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

HisExerciseAppointmentDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "counter_order_date": "int32_t",
    "currency_type": "int16_t",
    "market": "string",
    "secuid": "string",
    "option_account": "string",
    "option_num": "string",
    "option_name": "string",
    "options_type": "int32_t",
    "underlying_code": "string",
    "cover_flag": "int32_t",
    "volume": "int64_t",
    "underlying_volume": "int64_t",
    "exercise_amt": "int64_t",
    "exercise_price": "int64_t",
    "exercise_side": "int32_t",
    "comb_volume": "int64_t",
}

QryOptionHisDeliveryReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisDeliveryDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "settlement_id": "int64_t",
    "settlement_date": "int32_t",
    "counter_order_id": "string",
    "contract_id": "string",
    "market": "string",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "string",
    "option_name": "string",
    "comb_num": "string",
    "comb_strategy": "int16_t",
    "leg1_num": "string",
    "leg2_num": "string",
    "leg3_num": "string",
    "leg4_num": "string",
    "currency_type": "int16_t",
    "underlying_code": "string",
    "underlying_name": "string",
    "price": "int64_t",
    "qty": "int32_t",
    "order_amt": "int64_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "match_cnt": "int32_t",
    "stamp_duty": "int64_t",
    "handle_fee": "int64_t",
    "secu_regu_fee": "int64_t",
    "trd_regu_fee": "int64_t",
    "clearing_fee": "int64_t",
    "exch_trans_fee": "int64_t",
    "trans_fee": "int64_t",
    "exe_trans_fee": "int64_t",
    "paidin_com": "int64_t",
    "settlement_amt": "int64_t",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "string",
    "leg2_name": "string",
    "leg3_name": "string",
    "leg4_name": "string",
}

QryHisExerciseDeliveryReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

HisExerciseDeliveryyDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "serial_number": "int64_t",
    "settlement_date": "int32_t",
    "occur_time": "int64_t",
    "market": "string",
    "currency_type": "int16_t",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "biz_amt": "int64_t",
    "fund_bln": "int64_t",
    "fund_avl": "int64_t",
    "frozen_margin": "int64_t",
    "unfrozen_margin": "int64_t",
    "underlying_code": "string",
    "underlying_volume": "int64_t",
    "stamp_duty": "int64_t",
    "handle_fee": "int64_t",
    "secu_regu_fee": "int64_t",
    "trd_regu_fee": "int64_t",
    "clearing_fee": "int64_t",
    "venture_fee": "int64_t",
    "trans_fee": "int64_t",
    "exe_trans_fee": "int64_t",
    "paidin_com": "int64_t",
    "fee_amt": "int64_t",
    "volume": "int64_t",
    "comb_volume": "int64_t",
    "biz_code": "int32_t",
}

QryOptionHisContractAssetReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisContractAssetDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "occur_date": "int32_t",
    "market": "string",
    "currency_type": "int16_t",
    "option_account": "string",
    "option_num": "string",
    "option_code": "string",
    "option_name": "string",
    "options_type": "int32_t",
    "option_side": "int32_t",
    "cover_flag": "int32_t",
    "underlying_code": "string",
    "option_prebln": "int64_t",
    "option_bln": "int64_t",
    "option_avl": "int64_t",
    "option_margin": "int64_t",
    "comb_volume": "int64_t",
}

QryOptionHisDeliveryNettingReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
}

OptionHisDeliveryNettingDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "settlement_date": "int32_t",
    "market": "string",
    "option_account": "string",
    "stamp_duty": "int64_t",
    "handle_fee": "int64_t",
    "secu_regu_fee": "int64_t",
    "trd_regu_fee": "int64_t",
    "clearing_fee": "int64_t",
    "exch_trans_fee": "int64_t",
    "trans_fee": "int64_t",
    "exe_trans_fee": "int64_t",
    "paidin_com": "int64_t",
    "settlement_amt": "int64_t",
}

QryOptionHisCombPositionReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisCombPositionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "occur_date": "int32_t",
    "market": "string",
    "currency_type": "int16_t",
    "secuid": "string",
    "option_account": "string",
    "comb_num": "string",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "string",
    "comb_prebln": "int64_t",
    "comb_bln": "int64_t",
    "comb_avl": "int64_t",
    "comb_trade_frz": "int64_t",
    "comb_trade_ufz": "int64_t",
    "comb_trade_otd": "int64_t",
    "comb_trade_bln": "int64_t",
    "comb_clearing_frz": "int64_t",
    "comb_clearing_ufz": "int64_t",
    "comb_clearing_otd": "int64_t",
    "comb_margin_unit": "int64_t",
    "comb_margin": "int64_t",
    "leg_count": "int32_t",
    "leg1_num": "string",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_position": "int64_t",
    "leg2_num": "string",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_position": "int64_t",
    "leg3_num": "string",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_position": "int64_t",
    "leg4_num": "string",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_position": "int64_t",
    "leg1_name": "string",
    "leg2_name": "string",
    "leg3_name": "string",
    "leg4_name": "string",
}

QryOptionHisSettlementReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisSettlementDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "settlement_date": "int32_t",
    "trade_date": "int32_t",
    "trade_time": "int64_t",
    "counter_order_id": "string",
    "market": "string",
    "currency_type": "int32_t",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "string",
    "option_name": "string",
    "option_side": "int32_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "option_bln": "int64_t",
    "handle_fee": "int64_t",
    "clearing_fee": "int64_t",
    "trans_fee": "int64_t",
    "exe_trans_fee": "int64_t",
    "paidin_com": "int64_t",
    "fee_amt": "int64_t",
    "biz_amt": "int64_t",
    "fund_bln": "int64_t",
}

QryOptionCombStrategyFileReq = {
    "market": "string",
    "comb_strategy": "int16_t",
}

OptionCombStrategyFileDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "string",
    "same_expdate": "int16_t",
    "same_underlying": "int16_t",
    "auto_split_day": "string",
    "opt_underlying_codes": "string",
    "leg_count": "int32_t",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_exeprc_seq": "int32_t",
    "leg1_expdate_seq": "int32_t",
    "leg1_position": "int64_t",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_exeprc_seq": "int32_t",
    "leg2_expdate_seq": "int32_t",
    "leg2_position": "int64_t",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_exeprc_seq": "int32_t",
    "leg3_expdate_seq": "int32_t",
    "leg3_position": "int64_t",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_exeprc_seq": "int32_t",
    "leg4_expdate_seq": "int32_t",
    "leg4_position": "int64_t",
}

MicroServiceReq = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "function_id": "string",
    "tar_sys": "string",
    "request_content": "string",
    "request_len": "int32_t",
}

MicroServiceRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "call_status": "bool",
    "error_code": "string",
    "error_info": "string",
    "error_extra": "string",
    "response_list_first": "string",
    "first_list_len": "int32_t",
    "response_list_second": "string",
    "second_list_len": "int32_t",
}

BankBalanceReq = {
    "currency_type": "int32_t",
    "bank_code": "string",
}

BankBalanceDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "status": "char",
    "sno": "int64_t",
    "fund_bal": "int64_t",
}

QueryBankInfoReq = {
    "currency_type": "int32_t",
}

BankInfoDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "cust_id": "string",
    "currency_type": "int32_t",
    "bank_code": "string",
    "bank_name": "string",
    "bankid": "string",
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
    "bank_code": "string",
    "busi_type": "char",
    "fund_effect": "int64_t",
    "gm_fund_pwd": "string",
    "bank_pwd": "string",
}

BankSecTransferRsp = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "sno": "int64_t",
    "busi_type": "char",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "status": "char",
}

QryBankSecTransferReq = {
    "currency_type": "int32_t",
    "sno": "int64_t",
}

BankSecTransferDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "currency_type": "int32_t",
    "cust_id": "string",
    "bank_code": "string",
    "bank_name": "string",
    "busi_type": "char",
    "sno": "int64_t",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "remark": "string",
    "status": "char",
    "bank_msg_id": "string",
    "bank_msg": "string",
    "syserr_id": "int64_t",
}

QryHisBankSecTransferReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "currency_type": "int32_t",
    "qry_direct": "char",
    "query_num": "int32_t",
    "pos_str": "string",
}

HisBankSecTransferDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "pos_str": "string",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "sno": "int64_t",
    "fund_id": "string",
    "currency_type": "int32_t",
    "cust_id": "string",
    "cust_name": "string",
    "bank_code": "string",
    "bank_name": "string",
    "busi_type": "char",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "remark": "string",
    "status": "char",
    "source_type": "char",
    "strike_flag": "char",
    "bank_msg_id": "string",
    "bank_msg": "string",
    "syserr_id": "int64_t",
}

FundAccountTransferReq = {
    "in_orgid": "string",
    "in_fund_id": "string",
    "out_orgid": "string",
    "out_fund_id": "string",
    "currency_type": "int32_t",
    "fund_effect": "int64_t",
    "remark": "string",
}

FundAccountTransferRsp = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
}

QryFundAccountTransferReq = {
    "brh_id": "string",
    "fund_id": "string",
}

FundAccountTransferDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "bank_name": "string",
    "digest_id": "string",
    "currency_type": "int32_t",
    "fund_effect": "int64_t",
    "remark": "string",
}

QryHisOrderReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "string",
    "stk_code": "string",
    "order_id": "string",
    "order_date": "int32_t",
    "qry_direct": "char",
}

HisOrderDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "symbol": "string",
    "oper_date": "int32_t",
    "order_date": "int32_t",
    "trd_flow_id": "string",
    "cust_id": "string",
    "currency_type": "int16_t",
    "secuid": "string",
    "order_side": "int16_t",
    "order_id": "string",
    "stk_name": "string",
    "order_price": "int64_t",
    "order_qty": "int64_t",
    "oper_time": "int64_t",
    "order_frz_amt": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "match_amt": "int64_t",
    "cancel_qty": "int64_t",
    "order_status": "int32_t",
    "seat": "string",
    "oper_way": "char",
    "cancel_flag": "int16_t",
    "extqty1": "int64_t",
    "remark": "string",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryHisTradeReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
    "stk_code": "string",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

HisTradeDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "symbol": "string",
    "busi_flow_id": "string",
    "cust_id": "string",
    "currency_type": "int32_t",
    "secuid": "string",
    "main_seat": "string",
    "trd_seat": "string",
    "stk_property": "int16_t",
    "busi_type": "string",
    "busi_name": "string",
    "stk_name": "string",
    "order_date": "int32_t",
    "apply_code": "string",
    "match_code": "string",
    "match_time": "string",
    "match_amt": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "intr_amt": "int64_t",
    "stk_type": "string",
    "order_side": "int16_t",
    "oper_date": "int32_t",
    "match_date": "int32_t",
    "stk_bal": "int64_t",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryDeliveryOrderReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "string",
    "stk_code": "string",
}

DeliveryOrderDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "symbol": "string",
    "biz_date": "int32_t",
    "sno": "string",
    "busi_type": "string",
    "busi_name": "string",
    "currency_type": "int32_t",
    "stk_name": "string",
    "secuid": "string",
    "main_seat": "string",
    "ta_code": "string",
    "tran_sacct": "string",
    "ta_acct": "string",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "order_side": "int16_t",
    "apply_code": "string",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "match_time": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "match_amt": "int64_t",
    "fun_deffect": "int64_t",
    "fund_bal": "int64_t",
    "stk_effect": "int64_t",
    "stk_bal": "int64_t",
    "fee_seat": "int64_t",
    "fee_yjf": "int64_t",
    "fee_yhs": "int64_t",
    "fee_jsf": "int64_t",
    "fee_ghf": "int64_t",
    "fee_zgf": "int64_t",
    "fee_sxf": "int64_t",
    "fee_qsf": "int64_t",
    "fee_jggf": "int64_t",
    "fee_other": "int64_t",
    "fee_jsxf": "int64_t",
    "fee_jygf": "int64_t",
    "fee_front": "int64_t",
    "total_num": "int32_t",
    "clear_exch_rate": "int64_t",
}

QryStateOrderReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "stk_code": "string",
    "currency_type": "int16_t",
}

StateOrderDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "symbol": "string",
    "biz_date": "int32_t",
    "clear_date": "int32_t",
    "sno": "string",
    "busi_type": "string",
    "busi_name": "string",
    "currency_type": "int32_t",
    "stk_name": "string",
    "secuid": "string",
    "main_seat": "string",
    "ta_code": "string",
    "trans_acct": "string",
    "ta_acct": "string",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "order_side": "int16_t",
    "apply_code": "string",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "match_time": "int32_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "match_amt": "int64_t",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "stkeff_ect": "int64_t",
    "stk_bal": "int64_t",
    "total_num": "int32_t",
}

QueryExchangeListsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
}

ExchangeDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "pos_str": "string",
    "clear_date": "int32_t",
    "biz_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "digest_id": "int32_t",
    "digest_name": "string",
    "currency_type": "int32_t",
    "symbol": "string",
    "secuid": "string",
    "cust_name": "string",
    "order_id": "string",
    "sno": "string",
    "stk_name": "string",
    "order_side": "int16_t",
    "match_time": "int64_t",
    "match_code": "string",
    "match_times": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "match_amt": "int64_t",
    "clear_amt": "int64_t",
    "fee_yhs": "int64_t",
    "fee_jsxf": "int64_t",
    "fee_sxf": "int64_t",
    "fee_ghf": "int64_t",
    "fee_qsf": "int64_t",
    "fee_jygf": "int64_t",
    "fee_front": "int64_t",
    "fee_jsf": "int64_t",
    "fee_zgf": "int64_t",
    "fee_other": "int64_t",
    "fund_bal": "int64_t",
    "stk_bal": "int64_t",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "source_type": "char",
    "bank_code": "string",
    "bank_id": "string",
    "counter_order_id": "string",
}

ModifyPasswordReq = {
    "old_password": "string",
    "new_password": "string",
    "password_type": "int16_t",
}

ModifyPasswordRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
}

QueryPHXXReq = {
    "query_index": "int64_t",
    "query_num": "int64_t",
    "stk_code": "string",
    "secuid": "string",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

QueryPHXXRecord = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "string",
    "secuid": "string",
    "stk_name": "string",
    "stk_code": "string",
    "match_qty": "int64_t",
    "mate_no": "string",
    "currency_type": "int16_t",
    "busi_type": "string",
    "link_stk_code": "string",
    "next_query_index": "int64_t",
    "total_num": "int64_t",
    "issue_stk_type": "char",
    "order_date": "int32_t",
}

QueryZQXXReq = {
    "query_index": "int64_t",
    "query_num": "int64_t",
    "stk_code": "string",
    "secuid": "string",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "market": "string",
}

QueryZQXXRecord = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "string",
    "secuid": "string",
    "stk_name": "string",
    "stk_code": "string",
    "stk_type": "string",
    "hit_qty": "int64_t",
    "match_price": "int64_t",
    "order_date": "int32_t",
    "order_id": "string",
    "mate_no": "string",
    "currency_type": "int16_t",
    "busi_type": "string",
    "next_query_index": "int64_t",
    "total_num": "int64_t",
    "issue_stk_type": "char",
}

QryLockSecurityContractReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "symbol": "string",
    "status": "string",
}

LockSecurityContractDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "sys_date": "int32_t",
    "begin_date": "int32_t",
    "close_date": "int32_t",
    "symbol": "string",
    "name": "string",
    "status": "char",
    "secuid": "string",
    "lock_charge_type": "int16_t",
    "first_in_mode": "int16_t",
    "reserve_qty": "int64_t",
    "stk_bal": "int64_t",
    "stk_avl": "int64_t",
    "stk_used_qty": "int64_t",
    "stk_sale": "int64_t",
    "stk_sale_frz": "int64_t",
    "stk_repay": "int64_t",
    "used_fee_rate": "int64_t",
    "used_fee": "int64_t",
    "unused_fee_rate": "int64_t",
    "unused_fee": "int64_t",
    "over_used_fee": "int64_t",
    "over_unused_fee": "int64_t",
    "puni_used_fee": "int64_t",
    "puni_unused_fee": "int64_t",
    "violate_fee_rate": "int64_t",
    "violate_fee": "int64_t",
    "over_violate_fee": "int64_t",
    "puni_violate_fee": "int64_t",
    "cust_id": "string",
}

CreditContractDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "f_credit_rate": "int64_t",
    "f_year_mg_fee": "int64_t",
    "f_year_sr_fee": "int64_t",
    "d_credit_rate": "int64_t",
    "d_year_mg_fee": "int64_t",
    "d_year_sr_fee": "int64_t",
    "cancel_date": "int32_t",
    "currency_type": "int16_t",
    "contract_limit": "int32_t",
    "contract_status": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "f_prate": "int64_t",
    "d_prate": "int64_t",
    "contract_id": "string",
}

QryCreditDebtsCollectReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "symbol": "string",
}

CreditDebtsCollectDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "symbol": "string",
    "name": "string",
    "match_amt": "int64_t",
    "match_qty": "int64_t",
    "credit_repay": "int64_t",
    "stk_repay": "int64_t",
    "credit_repay_unfrz": "int64_t",
    "stk_repay_unfrz": "int64_t",
    "credit_bal": "int64_t",
    "stk_bal": "int64_t",
    "last_price": "int64_t",
    "market_value": "int64_t",
    "credit_avl": "int64_t",
    "debts_profit": "int64_t",
    "adjust_profit": "int64_t",
    "credit_fee": "int64_t",
    "stk_debts_avl": "int64_t",
}

QryCreditDataReq = {
    "symbol": "string",
    "credit_direct": "char",
}

CreditDataDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "symbol": "string",
    "name": "string",
    "credit_direct": "char",
    "margin_avl": "int64_t",
    "credit_bal": "int64_t",
    "credit_avl": "int64_t",
    "margin_rate": "int64_t",
    "debts_bal": "int64_t",
    "max_amt": "int64_t",
    "fund_avl": "int64_t",
    "credit_fund_avl": "int64_t",
    "g_dis_market_avl": "int64_t",
    "mar_stk_val": "int64_t",
    "total_dis_f_mk_val": "int64_t",
    "mar_fund_profit": "int64_t",
    "mar_stk_profit": "int64_t",
    "total_rate_f_debts_bal": "int64_t",
    "mar_fund_margin": "int64_t",
    "mar_fund_margin_frz": "int64_t",
    "total_rate_d_sale_bal": "int64_t",
    "mar_stk_margin": "int64_t",
    "mar_stk_margin_frz": "int64_t",
    "total_fee": "int64_t",
}

QryPreMaturityDebtsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "string",
}

PreMaturityDebtsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "secuid": "string",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "sys_date": "int32_t",
    "sno": "string",
    "order_id": "string",
    "order_date": "int32_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "leave_amt": "int64_t",
    "leave_qty": "int64_t",
    "all_fee": "int64_t",
    "apply_status": "int16_t",
    "apply_date": "int32_t",
    "apply_sno": "string",
    "apply_end_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "chk_remark": "string",
}

ExtendPreMaturityDebtsReq = {
    "sys_date": "int32_t",
    "sno": "string",
}

ExtendPreMaturityDebtsRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "apply_date": "int32_t",
    "apply_sno": "string",
}

QryPreMaturityDebtsExtensionReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "string",
}

PreMaturityDebtsExtensionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "secuid": "string",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "apply_status": "int16_t",
    "sys_date": "int32_t",
    "apply_date": "int32_t",
    "apply_sno": "string",
    "sno": "string",
    "order_date": "int32_t",
    "order_id": "string",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "leave_amt": "int64_t",
    "leave_value": "int64_t",
    "chk_remark": "string",
    "cfm_ans": "string",
    "leave_qty": "int64_t",
}

QryVoteProposalReq = {
    "symbol": "string",
    "vote_symbol": "string",
}

VoteProposalDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "name": "string",
    "vote_symbol": "string",
    "vote_name": "string",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "meeting_type": "string",
    "meeting_desc": "string",
    "meeting_seq": "string",
    "voting_proposal_code": "string",
    "voting_prososal_desc": "string",
    "voting_proposal_type": "char",
    "cum_voting_chosen_num": "int64_t",
    "share_holder_role": "string",
    "proposal_relation": "string",
    "share_class": "string",
    "reg_date": "int32_t",
}

QryCreditVoteCountReq = {
    "symbol": "string",
    "meeting_seq": "string",
    "voting_proposal": "string",
}

CreditVoteCountDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "voting_proposal": "string",
    "rest_qty": "int64_t",
    "stk_name": "string",
}

QryCreditVoteReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "code": "string",
    "voting_proposal": "string",
}

CreditVoteDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "secuid": "string",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "link_symbol": "string",
    "voting_proposal": "string",
    "voting_preference": "int16_t",
    "stk_bal": "int64_t",
    "stk_name": "string",
    "link_stk_name": "string",
    "meeting_seq": "string",
    "meeting_desc": "string",
    "voting_proposal_type": "char",
    "voting_prososal_desc": "string",
    "key_error_code": "string",
    "key_error_msg": "string",
}

QryNetVoteRightsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "market": "string",
    "stk_code": "string",
}

NetVoteRightsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cust_id": "string",
    "secuid": "string",
    "symbol": "string",
    "name": "string",
    "meeting_seq": "string",
    "reg_date": "int32_t",
    "voting_proposal": "string",
    "voting_relation": "string",
    "total_num": "int32_t",
}

QryNetVoteResultReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "string",
    "vote_code": "string",
}

NetVoteResultDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "busi_date": "int32_t",
    "contract_id": "string",
    "vote_symbol": "string",
    "meeting_seq": "string",
    "cust_id": "string",
    "fund_id": "string",
    "secuid": "string",
    "vote_qty": "int64_t",
    "cur_vote_qty": "int64_t",
    "voting_proposal": "string",
    "vote_info": "string",
    "vote_type": "char",
    "total_num": "int32_t",
    "vote_name": "string",
}

QryNetVoteCountReq = {
    "secuid": "string",
    "symbol": "string",
    "vote_code": "string",
    "reg_date": "int32_t",
}

NetVoteCountDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "vote_qty": "int64_t",
}

QryCreditDebtsFlowReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "currency_type": "int16_t",
}

CreditDebtsFlowDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "debt_type": "char",
    "effect_direct": "char",
    "repay_way": "char",
    "stk_code": "string",
    "stk_name": "string",
    "details_sno": "string",
    "relate_sys_date": "int32_t",
    "relate_sno": "string",
    "market_id": "int32_t",
    "fund_effect": "int64_t",
    "stk_effect": "int64_t",
}

QryCreditAssetFlowReq = {
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditAssetFlowDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "biz_date": "int32_t",
    "details_sno": "string",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "digest_id": "int32_t",
    "digest_name": "string",
    "currency_type": "int16_t",
    "secuid": "string",
    "market_id": "int32_t",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "stk_bal": "int64_t",
    "stk_code": "string",
    "stk_name": "string",
    "busi_type": "string",
    "side": "int16_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "order_id": "string",
    "pos_str": "string",
}

QueryCreditDebtsReq = {
    "credit_direct": "char",
    "qry_direct": "char",
    "sys_date": "int32_t",
    "sno": "string",
    "currency_type": "int16_t",
    "symbol": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

CreditDebtsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "sys_date": "int32_t",
    "end_date": "int32_t",
    "sno": "string",
    "currency_type": "int16_t",
    "symbol": "string",
    "security_symbol": "string",
    "order_date": "int32_t",
    "order_id": "int64_t",
    "secuid": "string",
    "life_status": "int16_t",
    "d_stk_bal": "int64_t",
    "f_deal_bal": "int64_t",
    "f_deal_avl": "int64_t",
    "init_cost_price": "int64_t",
    "prof_cost_price": "int64_t",
    "profit_cost": "int64_t",
    "stk_repay_unfrz": "int64_t",
    "fee_unfrz": "int64_t",
    "over_due_fee_unfrz": "int64_t",
    "puni_fee_unfrz": "int64_t",
    "over_due_rights_unfrz": "int64_t",
    "puni_rights_unfrz": "int64_t",
    "puni_debts_unfrz": "int64_t",
    "all_fee_unfrz": "int64_t",
    "relese_amt": "int64_t",
    "relese_amt_unfrz": "int64_t",
    "credit_repay_unfrz": "int64_t",
    "f_exp_cet_intr": "int64_t",
    "f_debt_qty": "int64_t",
    "d_stk_avl": "int64_t",
    "last_price": "int64_t",
    "mkt_val": "int64_t",
    "buy_cost": "int64_t",
    "exp_cet_intr": "int64_t",
    "pos_str": "string",
    "credit_direct": "char",
    "match_qty": "int64_t",
    "stk_repay": "int64_t",
    "clear_amt": "int64_t",
    "credit_repay": "int64_t",
}

StkConcentrationReq = {
    "query_index": "string",
    "query_num": "int32_t",
    "symbol": "string",
    "market": "string",
}

StkConcentrationDetail = {
    "market_id": "int32_t",
    "symbol": "string",
    "name": "string",
    "keep_rate_begin": "int64_t",
    "keep_rate_end": "int64_t",
    "debt_begin": "int64_t",
    "debt_end": "int64_t",
    "ctrl_rate": "int64_t",
}

MarginRiskDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "rt_risk_rate": "int64_t",
}

QryHKHisOrderReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "string",
    "secuid": "string",
    "stk_code": "string",
    "order_id": "string",
    "bank_code": "string",
    "qry_direct": "char",
}

HKHisOrderDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "trd_flow_id": "string",
    "order_id": "string",
    "order_status": "int32_t",
    "currency_type": "int16_t",
    "symbol": "string",
    "secuid": "string",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "order_frz_amt": "int64_t",
    "trade_fee": "int64_t",
    "settle_fee": "int64_t",
    "net_price": "int64_t",
    "return_rate": "int64_t",
    "total_bond_intr": "int64_t",
    "settle_days": "int32_t",
    "end_order_date": "int32_t",
    "settle_date": "int32_t",
    "settle_mode": "int16_t",
    "price_type": "int16_t",
    "match_type": "int16_t",
    "stk_name": "string",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "cancel_qty": "int64_t",
    "order_side": "int16_t",
    "contract_sno": "string",
    "refer_rate": "int64_t",
    "pos_str": "string",
    "total_num": "int32_t",
    "main_seat": "string",
    "match_amt": "int64_t",
    "remark": "string",
    "report_time": "int64_t",
    "cust_id": "string",
    "cust_name": "string",
}

QueryWithdrawCashReq = {
    "market": "string",
}

WithdrawCashRecord = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "currency_type": "int16_t",
    "total_asset": "int64_t",
    "fund_bal": "int64_t",
    "fund_avl": "int64_t",
    "fetch_bal": "int64_t",
}

QryTradeListTotalReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "order_id": "string",
    "market": "string",
    "stkcode": "string",
}

QryNetVoteOrderReq = {
    "market": "string",
    "meeting_seq": "string",
    "voting_proposal_code": "string",
    "stock_code": "string",
    "pos_str": "string",
    "query_num": "int32_t",
}

NetVoteOrderDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_id": "int64_t",
    "order_group": "int64_t",
    "contract_id": "string",
    "order_date": "int32_t",
    "cust_id": "string",
    "cust_name": "string",
    "currency_type": "int32_t",
    "symbol": "string",
    "name": "string",
    "seat": "string",
    "stktype": "int16_t",
    "side": "int16_t",
    "meeting_seq": "string",
    "voting_proposal_code": "string",
    "voting_preference": "int64_t",
    "voting_segment": "string",
    "total_qty": "int64_t",
    "counter_order_time": "int32_t",
    "order_status": "int16_t",
    "secuid": "string",
    "remark": "string",
}

ETFSubscriptCancelReq = {
    "order_date": "int32_t",
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

ETFSubscriptCancelRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "order_date": "int32_t",
    "order_id": "string",
    "cl_order_id": "string",
    "cl_cancel_id": "string",
}

NetVoteOrderReq = {
    "symbol": "string",
    "link_stk_code": "string",
    "order_qty": "int64_t",
    "reg_date": "int32_t",
    "meeting_seq": "string",
    "voting_proposal": "string",
    "voting_preference": "int16_t",
    "voting_segment": "string",
}

NetVoteOrderRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "contract_id": "string",
    "order_sno": "int64_t",
    "order_status": "int16_t",
    "report_time": "int64_t",
    "cust_id": "string",
    "secuid": "string",
    "symbol": "string",
    "reject_code": "string",
    "reject_msg": "string",
    "order_group": "int32_t",
}

CreditNetVoteOrderReq = {
    "symbol": "string",
    "link_stk_code": "string",
    "reg_date": "int32_t",
    "currency_type": "int16_t",
    "order_qty": "int64_t",
    "meeting_seq": "string",
    "voting_proposal": "string",
    "voting_preference": "int16_t",
}

CreditNetVoteOrderRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "reject_code": "string",
    "reject_msg": "string",
    "level": "string",
    "cust_id": "string",
    "secuid": "string",
    "symbol": "string",
}

QueryMSCashReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCashDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "pos_str": "string",
    "busidate": "int32_t",
    "custid": "string",
    "fundunit": "string",
    "currency_type": "int32_t",
    "subjectcode": "string",
    "settbody": "string",
    "orgid": "string",
    "brhid": "string",
    "trdsysid": "string",
    "coreid": "string",
    "fundid": "string",
    "subjectname": "string",
    "startbal": "int64_t",
    "endbal": "int64_t",
    "fundrealcommit": "int64_t",
    "awardamt": "int64_t",
    "punishamt": "int64_t",
    "totalnum": "int64_t",
}

QueryMSPositionsReq = {
    "pos_str": "string",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSPositionsDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "pos_str": "string",
    "busidate": "int32_t",
    "custid": "string",
    "fundunit": "string",
    "stkholdunit": "string",
    "secuid": "string",
    "mainseat": "string",
    "symbol": "string",
    "direction": "int16_t",
    "investtype": "int16_t",
    "stkid": "string",
    "stkproperty": "int16_t",
    "subjectcode": "string",
    "settbody": "string",
    "trdsysid": "string",
    "coreid": "string",
    "currency_type": "int32_t",
    "schemeid": "string",
    "subjectname": "string",
    "startbal": "int64_t",
    "endbal": "int64_t",
    "startcost": "int64_t",
    "endcost": "int64_t",
    "startcostwithfee": "int64_t",
    "endcostwithfee": "int64_t",
    "starttradefee": "int64_t",
    "endtradefee": "int64_t",
    "startprofit": "int64_t",
    "endprofit": "int64_t",
    "startprofitwithfee": "int64_t",
    "endprofitwithfee": "int64_t",
    "startintrcost": "int64_t",
    "endintrcost": "int64_t",
    "startintrprofit": "int64_t",
    "endintrprofit": "int64_t",
    "tacode": "string",
    "transacct": "string",
    "taacct": "string",
    "linkstkid": "string",
    "extint": "int32_t",
    "extamt": "int64_t",
    "extchar": "string",
    "extstr": "string",
    "totalnum": "int64_t",
}

QueryMSCreditDebtsFlowReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "string",
    "code": "string",
    "pos_str": "string",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCreditDebtsFlowDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "pos_str": "string",
    "busidate": "int32_t",
    "operdate": "int32_t",
    "sysdate": "int32_t",
    "logno": "string",
    "custid": "string",
    "creditdebtstype": "char",
    "lifekind": "bool",
    "direct": "char",
    "paykind": "char",
    "fundeffect": "int64_t",
    "fundbal": "int64_t",
    "stkeffect": "int64_t",
    "stkbal": "int64_t",
    "reladate": "int32_t",
    "relasno": "string",
    "symbol": "string",
    "remark": "string",
    "bizdate": "int32_t",
    "logassetsno": "string",
    "totalnum": "int64_t",
}
