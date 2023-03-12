RiskNotify = {
    "secuid": "str",
    "alarm_score": "str",
    "alarm_status": "str",
    "alarm_rule": "str",
    "alarm_time": "str",
    "alarm_msg": "str",
}

FailBackNotify = {
    "system_id": "str",
    "node_id": "str",
    "status": "char",
    "credit_node_flag": "char",
    "urgent_flag": "char",
    "update_source": "str",
}

AccountInfo = {
    "account_id": "str",
    "account_type": "int16_t",
    "account_pwd": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_system_id": "str",
}

LoginReq = {
    "account_id": "str",
    "account_type": "int16_t",
    "account_pwd": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_system_id": "str",
    "svr_ip": "str",
    "svr_port": "int",
    "terminal_info": "str",
    "inner_flag": "int16_t",
}

SecuidInfo = {
    "market": "str",
    "secuid": "str",
    "fund_id": "str",
    "account_type": "int16_t",
    "account_status": "char",
    "account_class": "char",
    "account_rights": "str",
    "account_hgtright": "char",
}

LoginRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cust_id": "str",
    "cust_name": "str",
    "secuid_array": "str",
    "cif_account": "str",
    "user_code": "str",
    "user_token": "str",
    "token_serial_no": "str",
    "sm3_cipher": "str",
    "sys_node_type": "int",
    "clear_switch_flag": "char",
    "trade_switch_flag": "char",
    "sys_server_id": "str",
    "operway": "char",
    "sys_shbond_type": "int16_t",
    "ext_secuid_array": "str",
    "reg_branchid": "str",
}

OrderReq = {
    "cl_order_id": "str",
    "symbol": "str",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "int64_t",
    "price": "int64_t",
    "order_flag": "int16_t",
    "policy_id": "uint16_t",
    "share_property": "int16_t",
}

OrderRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_date": "int32_t",
    "order_id": "str",
    "cl_order_id": "str",
    "contract_id": "str",
    "ex_order_id": "str",
}

CancelReq = {
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
    "symbol": "str",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "int64_t",
    "price": "int64_t",
}

BatchCancelAllReq = {
    "cust_id": "str",
    "secu_id": "str",
    "symbol": "str",
    "market": "int32_t",
}

CancelRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
    "cancel_id": "str",
    "ex_order_id": "str",
}

QryByOrderIdReq = {
    "order_id": "str",
    "market": "str",
}

QryByCodeReq = {
    "symbol": "str",
}

QryOrderByCodeReq = {
    "symbol": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

QryOrdersReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "query_flag": "int",
    "market": "str",
}

OrderDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "str",
    "cl_order_id": "str",
    "orig_order_id": "str",
    "symbol": "str",
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
    "err_msg": "str",
    "secuid": "str",
    "name": "str",
    "freeze_amount": "int64_t",
    "contract_id": "str",
    "ex_order_id": "str",
}

QryTradeByCodeReq = {
    "symbol": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

QryTradesReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
    "filter_etf": "bool",
    "counter_order_id": "str",
}

QryETFTradesReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
    "counter_order_id": "str",
    "qry_direct": "char",
}

TradeDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "str",
    "cl_order_id": "str",
    "symbol": "str",
    "order_type": "int16_t",
    "side": "int16_t",
    "report_type": "int16_t",
    "report_no": "str",
    "volume": "int64_t",
    "price": "int64_t",
    "turnover": "int64_t",
    "trade_date": "int32_t",
    "trade_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "str",
    "secuid": "str",
    "name": "str",
    "contract_id": "str",
    "ex_report_no": "str",
    "ex_order_id": "str",
    "margin_amt_type": "int16_t",
    "order_price": "int64_t",
    "order_qty": "int64_t",
}

QryPositionsReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
}

PositionDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "side": "int16_t",
    "volume": "int64_t",
    "avail_volume": "int64_t",
    "init_volume": "int64_t",
    "market_value": "int64_t",
    "today_buy_volume": "int64_t",
    "today_sell_volume": "int64_t",
    "secuid": "str",
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
    "name": "str",
    "currency_type": "int32_t",
    "security_type_apex": "int32_t",
    "profit_price": "int64_t",
}

QryCashReq = {
    "market": "str",
}

CashDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "currency_type": "int16_t",
    "total_amount": "int64_t",
    "avail_amount": "int64_t",
    "total_asset": "int64_t",
    "market_value": "int64_t",
    "init_amount": "int64_t",
    "fetch_balance": "int64_t",
}

JZJYAvailFundDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "avail_amount": "int64_t",
}

TransferFundReq = {
    "transfer_side": "int",
    "transfer_value": "int64_t",
    "market": "str",
}

TransferFundRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "transfer_value": "int64_t",
}

TransferFundSecuidReq = {
    "fund_out_market": "str",
    "fund_in_market": "str",
    "transfer_value": "int64_t",
}

TransferFundSecuidRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "transfer_value": "int64_t",
}

QryETFsReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

ETFDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "name": "str",
    "first_symbol": "str",
    "second_symbol": "str",
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
    "first_symbol": "str",
    "sz_ksc_type": "int",
    "pos_str": "str",
    "query_num": "int32_t",
}

ETFStockDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "first_symbol": "str",
    "name": "str",
    "symbol": "str",
    "volume": "int32_t",
    "replace_flag": "int16_t",
    "over_price_rate": "int64_t",
    "replace_amt": "int64_t",
}

QryMaxOrderQtyReq = {
    "symbol": "str",
    "order_type": "int16_t",
    "side": "int16_t",
    "price": "int64_t",
}

MaxOrderQtyDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "max_qty": "int64_t",
    "actual_max_qty": "int64_t",
    "max_pay_amt": "int64_t",
    "max_pay_qty": "int64_t",
    "sep_rem_qty": "int64_t",
}

IPOMaxPurchaseDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "market": "str",
    "max_qty": "int64_t",
    "stib_max_qty": "int64_t",
    "secuid": "str",
}

QueryIPOStockReq = {
    "query_flag": "int16_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

IPOStockDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "currency_type": "int16_t",
    "ipo_price": "int64_t",
    "max_num": "int64_t",
    "min_num": "int64_t",
    "security_type": "int32_t",
}

SecurityBaseInfo = {
    "symbol": "str",
    "name": "str",
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
    "market": "str",
}

HKRateDetail = {
    "market": "str",
    "buy_rate": "int64_t",
    "sale_rate": "int64_t",
    "mid_rate": "int64_t",
    "set_rate": "int64_t",
    "sys_date": "int32_t",
}

QryHKStock = {
    "market": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

HKStockDetail = {
    "symbol": "str",
    "name": "str",
    "stktype": "int16_t",
    "currency_type": "int16_t",
    "security_type": "int32_t",
}

HKFundDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "currency_type": "int16_t",
    "fund_uncomeavl": "int64_t",
    "fund_buy": "int64_t",
    "fund_sale": "int64_t",
    "fund_uncomebuy": "int64_t",
    "fund_uncomesale": "int64_t",
}

QryHKMinPriceUnitReq = {
    "market": "str",
    "code": "str",
    "price": "int64_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

HKMinPriceUnitDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
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
    "cl_order_id": "str",
    "symbol": "str",
    "side": "int16_t",
    "volume": "int32_t",
    "opp_fund_id": "str",
    "opp_secu_id": "str",
}

CreditMortgageInOutRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_order_id": "str",
    "order_id": "str",
    "contract_id": "str",
}

CreditStockBackReq = {
    "cl_order_id": "str",
    "symbol": "str",
    "volume": "int32_t",
}

CreditStockBackRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_order_id": "str",
    "order_id": "str",
    "contract_id": "str",
}

CreditPayBackReq = {
    "back_amt": "int64_t",
    "cl_order_id": "str",
}

CreditPayBackByOrderReq = {
    "sno": "str",
    "order_date": "int",
    "back_amt": "int64_t",
    "cl_order_id": "str",
    "credit_type": "int32_t",
}

CreditPayBackRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "real_back_amt": "int64_t",
    "cl_order_id": "str",
}

QryCreditStockReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditStockDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "currency_type": "int16_t",
    "credit_fund_ctrl": "char",
    "credit_stk_ctrl": "char",
    "margin_rate_fund": "int64_t",
    "margin_rate_stk": "int64_t",
    "sep_rem_qty": "int32_t",
}

CreditAssetsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditFinanceDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "sno": "str",
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
    "pos_str": "str",
    "end_date": "int32_t",
}

QryCreditShortsellReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditShortsellDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "sno": "str",
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
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "max_back_amt": "int64_t",
}

QryCreditRepayStockReq = {
    "market": "str",
    "code": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditRepayStockDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "total_qty": "int64_t",
    "max_back_qty": "int64_t",
    "returned_qty": "int64_t",
}

QryCreditMortgageHoldReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditMortgageHoldDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "currency_type": "int16_t",
    "pledge_rate": "int64_t",
}

QryCreditSecuritySellQtyReq = {
    "market": "str",
    "code": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditSecuritySellQtyRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "total_qty": "int64_t",
    "avail_qty": "int64_t",
}

QrySecuidRightReq = {
    "market": "str",
    "secuid_right": "int16_t",
}

QrySecuidRightRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "market": "str",
    "secuid_right": "int16_t",
    "sign_flag": "bool",
}

OptionCashDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
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
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
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
    "secuid": "str",
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
    "cl_order_id": "str",
    "symbol": "str",
    "volume": "int64_t",
    "exercise_type": "int16_t",
}

ExerciseRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_order_id": "str",
    "order_id": "str",
    "exercise_type": "int16_t",
}

CancelExerciseReq = {
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

CancelExerciseRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

QryExercisesReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

ExerciseDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "exercise_type": "int16_t",
    "cl_order_id": "str",
    "order_id": "str",
    "counter_order_date": "int32_t",
    "counter_order_time": "int32_t",
    "counter_cancel_time": "int32_t",
    "exercise_status": "int32_t",
    "oper_status": "int32_t",
    "symbol": "str",
    "volume": "int32_t",
    "cancel_volume": "int32_t",
    "err_code": "int32_t",
    "err_msg": "str",
}

ContractInfo = {
    "contract_id": "str",
    "exch_contract_id": "str",
    "contract_name": "str",
    "underlying_contract_id": "str",
    "underlying_contract_name": "str",
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
    "symbol": "str",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "int64_t",
}

TransferStockRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "int64_t",
}

TransferStockDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "serial_number": "str",
    "symbol": "str",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "yesterday_volume": "int64_t",
    "today_bs_volume": "int64_t",
    "today_pr_volume": "int64_t",
    "stock_cust_id": "str",
    "stock_secuid": "str",
    "status_msg": "str",
}

LockOrderReq = {
    "cl_order_id": "str",
    "symbol": "str",
    "lock_type": "int16_t",
    "volume": "int64_t",
}

LockOrderRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "lock_type": "int16_t",
    "order_id": "str",
    "cl_order_id": "str",
}

QryLockOrdersReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

LockOrderDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "cl_order_id": "str",
    "order_id": "str",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "lock_type": "int16_t",
    "lock_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "str",
}

CombOrderReq = {
    "cl_order_id": "str",
    "symbol": "str",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "exch_comb_id": "str",
}

CombOrderRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "comb_type": "int16_t",
    "order_id": "str",
    "cl_order_id": "str",
}

CombExerciseReq = {
    "cl_order_id": "str",
    "call_symbol": "str",
    "put_symbol": "str",
    "volume": "int64_t",
}

CombExerciseRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cl_order_id": "str",
    "order_id": "str",
}

CancelCombExerciseReq = {
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

CancelCombExerciseRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

QryCombOrdersReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CombOrderDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "exch_comb_id": "str",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "cl_order_id": "str",
    "order_id": "str",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "order_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "str",
}

QryCombExercisesReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CombExerciseDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "call_symbol": "str",
    "put_symbol": "str",
    "cl_order_id": "str",
    "order_id": "str",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "cancel_time": "int32_t",
    "exercise_status": "int16_t",
    "oper_status": "int16_t",
    "volume": "int64_t",
    "cancel_volume": "int64_t",
    "err_code": "int32_t",
    "err_msg": "str",
}

CombPositionDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
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
    "secuid": "str",
}

CombPositionSubDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "comb_strategy": "int16_t",
    "exch_comb_id": "str",
    "volume": "int64_t",
    "yesterday_volume": "int64_t",
    "today_volume": "int64_t",
    "comb_date": "int32_t",
    "comb_time": "int32_t",
    "comb_status": "int16_t",
    "secuid": "str",
    "legs_num": "int32_t",
    "leg1_symbol": "str",
    "leg1_yesterday_volume": "int64_t",
    "leg1_today_volume": "int64_t",
    "leg1_pos_side": "int16_t",
    "leg1_option_type": "int16_t",
    "leg2_symbol": "str",
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
    "contract_id": "str",
    "comb_strategy": "int16_t",
    "leg1_contract_id": "str",
    "leg1_name": "str",
    "leg1_side": "int16_t",
    "leg2_contract_id": "str",
    "leg2_name": "str",
    "leg2_side": "int16_t",
}

QryLockSecurityReq = {
    "start_date": "int",
    "end_date": "int",
    "market": "str",
    "code": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

LockSecurityDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "sys_date": "int32_t",
    "sno": "str",
    "symbol": "str",
    "name": "str",
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
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "serial_number": "str",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_value": "int64_t",
    "transfer_side": "int16_t",
    "transfer_status": "int16_t",
    "remark": "str",
}

PositionLimitsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
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
    "market": "str",
}

AmountLimitsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "long_amount_limit": "int64_t",
    "avail_long_amount_limit": "int64_t",
    "market": "str",
}

QrySplitCombMarginDiffReq = {
    "contract_id": "str",
    "comb_strategy": "int16_t",
    "volume": "int64_t",
    "exch_comb_id": "str",
}

SplitCombMarginDiffDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "market": "str",
    "contract_id": "str",
    "exch_comb_id": "str",
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
    "market": "str",
    "contract_id": "str",
}

ExerciseAppointmentDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "market": "str",
    "contract_id": "str",
    "counter_order_date": "int32_t",
    "secuid": "str",
    "options_type": "int32_t",
    "option_unit": "int64_t",
    "underlying_contract_id": "str",
    "volume": "int64_t",
    "exercise_price": "int64_t",
    "exercise_side": "int32_t",
    "cover_flag": "int32_t",
}

QryOptionMaxOrderVolumeReq = {
    "contract_id": "str",
    "side": "int16_t",
    "order_type": "int16_t",
    "order_flag": "int16_t",
    "price": "int64_t",
}

OptionMaxOrderVolumeDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "max_volume": "int64_t",
}

QryOptionHisOrderReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisOrderDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "trade_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "contract_id": "str",
    "status": "int32_t",
    "market": "str",
    "secuid": "str",
    "option_account": "str",
    "option_security_type": "int32_t",
    "option_num": "str",
    "option_code": "str",
    "option_name": "str",
    "comb_num": "str",
    "comb_strategy": "int16_t",
    "leg1_num": "str",
    "leg2_num": "str",
    "leg3_num": "str",
    "leg4_num": "str",
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
    "underlying_code": "str",
    "underlying_name": "str",
    "underlying_frozen_qty": "int64_t",
    "underlying_unfrozen_qty": "int64_t",
    "underlying_cancel_qty": "int64_t",
    "leg1_side": "int32_t",
    "leg2_side": "int32_t",
    "leg3_side": "int32_t",
    "leg4_side": "int32_t",
    "leg1_name": "str",
    "leg2_name": "str",
    "leg3_name": "str",
    "leg4_name": "str",
}

QryOptionHisTradeReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisTradeDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "trade_date": "int32_t",
    "trade_time": "int64_t",
    "order_date": "int32_t",
    "counter_order_id": "str",
    "contract_id": "str",
    "match_id": "str",
    "market": "str",
    "secuid": "str",
    "option_account": "str",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "str",
    "option_name": "str",
    "comb_num": "str",
    "comb_strategy": "int16_t",
    "leg1_num": "str",
    "leg2_num": "str",
    "leg3_num": "str",
    "leg4_num": "str",
    "currency_type": "int16_t",
    "underlying_code": "str",
    "underlying_name": "str",
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
    "leg1_name": "str",
    "leg2_name": "str",
    "leg3_name": "str",
    "leg4_name": "str",
}

QryHisExerciseAppointmentReq = {
    "currency_type": "int16_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

HisExerciseAppointmentDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "counter_order_date": "int32_t",
    "currency_type": "int16_t",
    "market": "str",
    "secuid": "str",
    "option_account": "str",
    "option_num": "str",
    "option_name": "str",
    "options_type": "int32_t",
    "underlying_code": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisDeliveryDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "settlement_id": "int64_t",
    "settlement_date": "int32_t",
    "counter_order_id": "str",
    "contract_id": "str",
    "market": "str",
    "option_account": "str",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "str",
    "option_name": "str",
    "comb_num": "str",
    "comb_strategy": "int16_t",
    "leg1_num": "str",
    "leg2_num": "str",
    "leg3_num": "str",
    "leg4_num": "str",
    "currency_type": "int16_t",
    "underlying_code": "str",
    "underlying_name": "str",
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
    "leg1_name": "str",
    "leg2_name": "str",
    "leg3_name": "str",
    "leg4_name": "str",
}

QryHisExerciseDeliveryReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

HisExerciseDeliveryyDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "serial_number": "int64_t",
    "settlement_date": "int32_t",
    "occur_time": "int64_t",
    "market": "str",
    "currency_type": "int16_t",
    "option_account": "str",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "biz_amt": "int64_t",
    "fund_bln": "int64_t",
    "fund_avl": "int64_t",
    "frozen_margin": "int64_t",
    "unfrozen_margin": "int64_t",
    "underlying_code": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisContractAssetDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "occur_date": "int32_t",
    "market": "str",
    "currency_type": "int16_t",
    "option_account": "str",
    "option_num": "str",
    "option_code": "str",
    "option_name": "str",
    "options_type": "int32_t",
    "option_side": "int32_t",
    "cover_flag": "int32_t",
    "underlying_code": "str",
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
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "settlement_date": "int32_t",
    "market": "str",
    "option_account": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisCombPositionDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "occur_date": "int32_t",
    "market": "str",
    "currency_type": "int16_t",
    "secuid": "str",
    "option_account": "str",
    "comb_num": "str",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "str",
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
    "leg1_num": "str",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_position": "int64_t",
    "leg2_num": "str",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_position": "int64_t",
    "leg3_num": "str",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_position": "int64_t",
    "leg4_num": "str",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_position": "int64_t",
    "leg1_name": "str",
    "leg2_name": "str",
    "leg3_name": "str",
    "leg4_name": "str",
}

QryOptionHisSettlementReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "pos_str": "str",
    "query_num": "int32_t",
}

OptionHisSettlementDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "settlement_date": "int32_t",
    "trade_date": "int32_t",
    "trade_time": "int64_t",
    "counter_order_id": "str",
    "market": "str",
    "currency_type": "int32_t",
    "option_account": "str",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "str",
    "option_name": "str",
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
    "market": "str",
    "comb_strategy": "int16_t",
}

OptionCombStrategyFileDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "market": "str",
    "comb_strategy": "int16_t",
    "comb_strategy_name": "str",
    "same_expdate": "int16_t",
    "same_underlying": "int16_t",
    "auto_split_day": "str",
    "opt_underlying_codes": "str",
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
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "function_id": "str",
    "tar_sys": "str",
    "request_content": "str",
    "request_len": "int32_t",
}

MicroServiceRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "call_status": "bool",
    "error_code": "str",
    "error_info": "str",
    "error_extra": "str",
    "response_list_first": "str",
    "first_list_len": "int32_t",
    "response_list_second": "str",
    "second_list_len": "int32_t",
}

BankBalanceReq = {
    "currency_type": "int32_t",
    "bank_code": "str",
}

BankBalanceDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "status": "char",
    "sno": "int64_t",
    "fund_bal": "int64_t",
}

QueryBankInfoReq = {
    "currency_type": "int32_t",
}

BankInfoDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "cust_id": "str",
    "currency_type": "int32_t",
    "bank_code": "str",
    "bank_name": "str",
    "bankid": "str",
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
    "bank_code": "str",
    "busi_type": "char",
    "fund_effect": "int64_t",
    "gm_fund_pwd": "str",
    "bank_pwd": "str",
}

BankSecTransferRsp = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
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
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "currency_type": "int32_t",
    "cust_id": "str",
    "bank_code": "str",
    "bank_name": "str",
    "busi_type": "char",
    "sno": "int64_t",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "remark": "str",
    "status": "char",
    "bank_msg_id": "str",
    "bank_msg": "str",
    "syserr_id": "int64_t",
}

QryHisBankSecTransferReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "currency_type": "int32_t",
    "qry_direct": "char",
    "query_num": "int32_t",
    "pos_str": "str",
}

HisBankSecTransferDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "pos_str": "str",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "sno": "int64_t",
    "fund_id": "str",
    "currency_type": "int32_t",
    "cust_id": "str",
    "cust_name": "str",
    "bank_code": "str",
    "bank_name": "str",
    "busi_type": "char",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "remark": "str",
    "status": "char",
    "source_type": "char",
    "strike_flag": "char",
    "bank_msg_id": "str",
    "bank_msg": "str",
    "syserr_id": "int64_t",
}

FundAccountTransferReq = {
    "in_orgid": "str",
    "in_fund_id": "str",
    "out_orgid": "str",
    "out_fund_id": "str",
    "currency_type": "int32_t",
    "fund_effect": "int64_t",
    "remark": "str",
}

FundAccountTransferRsp = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
}

QryFundAccountTransferReq = {
    "brh_id": "str",
    "fund_id": "str",
}

FundAccountTransferDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "bank_name": "str",
    "digest_id": "str",
    "currency_type": "int32_t",
    "fund_effect": "int64_t",
    "remark": "str",
}

QryHisOrderReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "str",
    "stk_code": "str",
    "order_id": "str",
    "order_date": "int32_t",
    "qry_direct": "char",
}

HisOrderDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "symbol": "str",
    "oper_date": "int32_t",
    "order_date": "int32_t",
    "trd_flow_id": "str",
    "cust_id": "str",
    "currency_type": "int16_t",
    "secuid": "str",
    "order_side": "int16_t",
    "order_id": "str",
    "stk_name": "str",
    "order_price": "int64_t",
    "order_qty": "int64_t",
    "oper_time": "int64_t",
    "order_frz_amt": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "match_amt": "int64_t",
    "cancel_qty": "int64_t",
    "order_status": "int32_t",
    "seat": "str",
    "oper_way": "char",
    "cancel_flag": "int16_t",
    "extqty1": "int64_t",
    "remark": "str",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryHisTradeReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
    "stk_code": "str",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

HisTradeDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "symbol": "str",
    "busi_flow_id": "str",
    "cust_id": "str",
    "currency_type": "int32_t",
    "secuid": "str",
    "main_seat": "str",
    "trd_seat": "str",
    "stk_property": "int16_t",
    "busi_type": "str",
    "busi_name": "str",
    "stk_name": "str",
    "order_date": "int32_t",
    "apply_code": "str",
    "match_code": "str",
    "match_time": "str",
    "match_amt": "int64_t",
    "match_qty": "int64_t",
    "match_price": "int64_t",
    "order_qty": "int64_t",
    "order_price": "int64_t",
    "intr_amt": "int64_t",
    "stk_type": "str",
    "order_side": "int16_t",
    "oper_date": "int32_t",
    "match_date": "int32_t",
    "stk_bal": "int64_t",
    "total_num": "int32_t",
    "order_type": "int16_t",
}

QryDeliveryOrderReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "str",
    "stk_code": "str",
}

DeliveryOrderDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "symbol": "str",
    "biz_date": "int32_t",
    "sno": "str",
    "busi_type": "str",
    "busi_name": "str",
    "currency_type": "int32_t",
    "stk_name": "str",
    "secuid": "str",
    "main_seat": "str",
    "ta_code": "str",
    "tran_sacct": "str",
    "ta_acct": "str",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "order_side": "int16_t",
    "apply_code": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "stk_code": "str",
    "currency_type": "int16_t",
}

StateOrderDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "symbol": "str",
    "biz_date": "int32_t",
    "clear_date": "int32_t",
    "sno": "str",
    "busi_type": "str",
    "busi_name": "str",
    "currency_type": "int32_t",
    "stk_name": "str",
    "secuid": "str",
    "main_seat": "str",
    "ta_code": "str",
    "trans_acct": "str",
    "ta_acct": "str",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "order_side": "int16_t",
    "apply_code": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
    "qry_direct": "char",
    "begin_date": "int32_t",
    "end_date": "int32_t",
}

ExchangeDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "pos_str": "str",
    "clear_date": "int32_t",
    "biz_date": "int32_t",
    "order_date": "int32_t",
    "order_time": "int64_t",
    "digest_id": "int32_t",
    "digest_name": "str",
    "currency_type": "int32_t",
    "symbol": "str",
    "secuid": "str",
    "cust_name": "str",
    "order_id": "str",
    "sno": "str",
    "stk_name": "str",
    "order_side": "int16_t",
    "match_time": "int64_t",
    "match_code": "str",
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
    "bank_code": "str",
    "bank_id": "str",
    "counter_order_id": "str",
}

ModifyPasswordReq = {
    "old_password": "str",
    "new_password": "str",
    "password_type": "int16_t",
}

ModifyPasswordRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
}

QueryPHXXReq = {
    "query_index": "int64_t",
    "query_num": "int64_t",
    "stk_code": "str",
    "secuid": "str",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
}

QueryPHXXRecord = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "str",
    "secuid": "str",
    "stk_name": "str",
    "stk_code": "str",
    "match_qty": "int64_t",
    "mate_no": "str",
    "currency_type": "int16_t",
    "busi_type": "str",
    "link_stk_code": "str",
    "next_query_index": "int64_t",
    "total_num": "int64_t",
    "issue_stk_type": "char",
    "order_date": "int32_t",
}

QueryZQXXReq = {
    "query_index": "int64_t",
    "query_num": "int64_t",
    "stk_code": "str",
    "secuid": "str",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "qry_direct": "char",
    "market": "str",
}

QueryZQXXRecord = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "busi_date": "int32_t",
    "market": "str",
    "secuid": "str",
    "stk_name": "str",
    "stk_code": "str",
    "stk_type": "str",
    "hit_qty": "int64_t",
    "match_price": "int64_t",
    "order_date": "int32_t",
    "order_id": "str",
    "mate_no": "str",
    "currency_type": "int16_t",
    "busi_type": "str",
    "next_query_index": "int64_t",
    "total_num": "int64_t",
    "issue_stk_type": "char",
}

QryLockSecurityContractReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "symbol": "str",
    "status": "str",
}

LockSecurityContractDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "sys_date": "int32_t",
    "begin_date": "int32_t",
    "close_date": "int32_t",
    "symbol": "str",
    "name": "str",
    "status": "char",
    "secuid": "str",
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
    "cust_id": "str",
}

CreditContractDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
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
    "contract_id": "str",
}

QryCreditDebtsCollectReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "symbol": "str",
}

CreditDebtsCollectDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "currency_type": "int16_t",
    "symbol": "str",
    "name": "str",
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
    "symbol": "str",
    "credit_direct": "char",
}

CreditDataDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "currency_type": "int16_t",
    "symbol": "str",
    "name": "str",
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
    "pos_str": "str",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "str",
}

PreMaturityDebtsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "secuid": "str",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "sys_date": "int32_t",
    "sno": "str",
    "order_id": "str",
    "order_date": "int32_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "leave_amt": "int64_t",
    "leave_qty": "int64_t",
    "all_fee": "int64_t",
    "apply_status": "int16_t",
    "apply_date": "int32_t",
    "apply_sno": "str",
    "apply_end_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "chk_remark": "str",
}

ExtendPreMaturityDebtsReq = {
    "sys_date": "int32_t",
    "sno": "str",
}

ExtendPreMaturityDebtsRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "apply_date": "int32_t",
    "apply_sno": "str",
}

QryPreMaturityDebtsExtensionReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "symbol": "str",
}

PreMaturityDebtsExtensionDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "secuid": "str",
    "currency_type": "int16_t",
    "credit_direct": "char",
    "life_status": "int16_t",
    "apply_status": "int16_t",
    "sys_date": "int32_t",
    "apply_date": "int32_t",
    "apply_sno": "str",
    "sno": "str",
    "order_date": "int32_t",
    "order_id": "str",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "leave_amt": "int64_t",
    "leave_value": "int64_t",
    "chk_remark": "str",
    "cfm_ans": "str",
    "leave_qty": "int64_t",
}

QryVoteProposalReq = {
    "symbol": "str",
    "vote_symbol": "str",
}

VoteProposalDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "name": "str",
    "vote_symbol": "str",
    "vote_name": "str",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "meeting_type": "str",
    "meeting_desc": "str",
    "meeting_seq": "str",
    "voting_proposal_code": "str",
    "voting_prososal_desc": "str",
    "voting_proposal_type": "char",
    "cum_voting_chosen_num": "int64_t",
    "share_holder_role": "str",
    "proposal_relation": "str",
    "share_class": "str",
    "reg_date": "int32_t",
}

QryCreditVoteCountReq = {
    "symbol": "str",
    "meeting_seq": "str",
    "voting_proposal": "str",
}

CreditVoteCountDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "voting_proposal": "str",
    "rest_qty": "int64_t",
    "stk_name": "str",
}

QryCreditVoteReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "code": "str",
    "voting_proposal": "str",
}

CreditVoteDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "symbol": "str",
    "secuid": "str",
    "sys_date": "int32_t",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "link_symbol": "str",
    "voting_proposal": "str",
    "voting_preference": "int16_t",
    "stk_bal": "int64_t",
    "stk_name": "str",
    "link_stk_name": "str",
    "meeting_seq": "str",
    "meeting_desc": "str",
    "voting_proposal_type": "char",
    "voting_prososal_desc": "str",
    "key_error_code": "str",
    "key_error_msg": "str",
}

QryNetVoteRightsReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "market": "str",
    "stk_code": "str",
}

NetVoteRightsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "cust_id": "str",
    "secuid": "str",
    "symbol": "str",
    "name": "str",
    "meeting_seq": "str",
    "reg_date": "int32_t",
    "voting_proposal": "str",
    "voting_relation": "str",
    "total_num": "int32_t",
}

QryNetVoteResultReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "str",
    "vote_code": "str",
}

NetVoteResultDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "busi_date": "int32_t",
    "contract_id": "str",
    "vote_symbol": "str",
    "meeting_seq": "str",
    "cust_id": "str",
    "fund_id": "str",
    "secuid": "str",
    "vote_qty": "int64_t",
    "cur_vote_qty": "int64_t",
    "voting_proposal": "str",
    "vote_info": "str",
    "vote_type": "char",
    "total_num": "int32_t",
    "vote_name": "str",
}

QryNetVoteCountReq = {
    "secuid": "str",
    "symbol": "str",
    "vote_code": "str",
    "reg_date": "int32_t",
}

NetVoteCountDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "vote_qty": "int64_t",
}

QryCreditDebtsFlowReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "currency_type": "int16_t",
}

CreditDebtsFlowDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "currency_type": "int16_t",
    "debt_type": "char",
    "effect_direct": "char",
    "repay_way": "char",
    "stk_code": "str",
    "stk_name": "str",
    "details_sno": "str",
    "relate_sys_date": "int32_t",
    "relate_sno": "str",
    "market_id": "int32_t",
    "fund_effect": "int64_t",
    "stk_effect": "int64_t",
}

QryCreditAssetFlowReq = {
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditAssetFlowDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "biz_date": "int32_t",
    "details_sno": "str",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "digest_id": "int32_t",
    "digest_name": "str",
    "currency_type": "int16_t",
    "secuid": "str",
    "market_id": "int32_t",
    "fund_effect": "int64_t",
    "fund_bal": "int64_t",
    "stk_bal": "int64_t",
    "stk_code": "str",
    "stk_name": "str",
    "busi_type": "str",
    "side": "int16_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "match_amt": "int64_t",
    "order_id": "str",
    "pos_str": "str",
}

QueryCreditDebtsReq = {
    "credit_direct": "char",
    "qry_direct": "char",
    "sys_date": "int32_t",
    "sno": "str",
    "currency_type": "int16_t",
    "symbol": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

CreditDebtsDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "sys_date": "int32_t",
    "end_date": "int32_t",
    "sno": "str",
    "currency_type": "int16_t",
    "symbol": "str",
    "security_symbol": "str",
    "order_date": "int32_t",
    "order_id": "int64_t",
    "secuid": "str",
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
    "pos_str": "str",
    "credit_direct": "char",
    "match_qty": "int64_t",
    "stk_repay": "int64_t",
    "clear_amt": "int64_t",
    "credit_repay": "int64_t",
}

StkConcentrationReq = {
    "query_index": "str",
    "query_num": "int32_t",
    "symbol": "str",
    "market": "str",
}

StkConcentrationDetail = {
    "market_id": "int32_t",
    "symbol": "str",
    "name": "str",
    "keep_rate_begin": "int64_t",
    "keep_rate_end": "int64_t",
    "debt_begin": "int64_t",
    "debt_end": "int64_t",
    "ctrl_rate": "int64_t",
}

MarginRiskDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "rt_risk_rate": "int64_t",
}

QryHKHisOrderReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "str",
    "secuid": "str",
    "stk_code": "str",
    "order_id": "str",
    "bank_code": "str",
    "qry_direct": "char",
}

HKHisOrderDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "sys_date": "int32_t",
    "trd_flow_id": "str",
    "order_id": "str",
    "order_status": "int32_t",
    "currency_type": "int16_t",
    "symbol": "str",
    "secuid": "str",
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
    "stk_name": "str",
    "oper_date": "int32_t",
    "oper_time": "int64_t",
    "match_price": "int64_t",
    "match_qty": "int64_t",
    "cancel_qty": "int64_t",
    "order_side": "int16_t",
    "contract_sno": "str",
    "refer_rate": "int64_t",
    "pos_str": "str",
    "total_num": "int32_t",
    "main_seat": "str",
    "match_amt": "int64_t",
    "remark": "str",
    "report_time": "int64_t",
    "cust_id": "str",
    "cust_name": "str",
}

QueryWithdrawCashReq = {
    "market": "str",
}

WithdrawCashRecord = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "currency_type": "int16_t",
    "total_asset": "int64_t",
    "fund_bal": "int64_t",
    "fund_avl": "int64_t",
    "fetch_bal": "int64_t",
}

QryTradeListTotalReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "order_id": "str",
    "market": "str",
    "stkcode": "str",
}

QryNetVoteOrderReq = {
    "market": "str",
    "meeting_seq": "str",
    "voting_proposal_code": "str",
    "stock_code": "str",
    "pos_str": "str",
    "query_num": "int32_t",
}

NetVoteOrderDetail = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_id": "int64_t",
    "order_group": "int64_t",
    "contract_id": "str",
    "order_date": "int32_t",
    "cust_id": "str",
    "cust_name": "str",
    "currency_type": "int32_t",
    "symbol": "str",
    "name": "str",
    "seat": "str",
    "stktype": "int16_t",
    "side": "int16_t",
    "meeting_seq": "str",
    "voting_proposal_code": "str",
    "voting_preference": "int64_t",
    "voting_segment": "str",
    "total_qty": "int64_t",
    "counter_order_time": "int32_t",
    "order_status": "int16_t",
    "secuid": "str",
    "remark": "str",
}

ETFSubscriptCancelReq = {
    "order_date": "int32_t",
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

ETFSubscriptCancelRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "order_date": "int32_t",
    "order_id": "str",
    "cl_order_id": "str",
    "cl_cancel_id": "str",
}

NetVoteOrderReq = {
    "symbol": "str",
    "link_stk_code": "str",
    "order_qty": "int64_t",
    "reg_date": "int32_t",
    "meeting_seq": "str",
    "voting_proposal": "str",
    "voting_preference": "int16_t",
    "voting_segment": "str",
}

NetVoteOrderRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "contract_id": "str",
    "order_sno": "int64_t",
    "order_status": "int16_t",
    "report_time": "int64_t",
    "cust_id": "str",
    "secuid": "str",
    "symbol": "str",
    "reject_code": "str",
    "reject_msg": "str",
    "order_group": "int32_t",
}

CreditNetVoteOrderReq = {
    "symbol": "str",
    "link_stk_code": "str",
    "reg_date": "int32_t",
    "currency_type": "int16_t",
    "order_qty": "int64_t",
    "meeting_seq": "str",
    "voting_proposal": "str",
    "voting_preference": "int16_t",
}

CreditNetVoteOrderRsp = {
    "account_id": "str",
    "account_type": "int16_t",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "reject_code": "str",
    "reject_msg": "str",
    "level": "str",
    "cust_id": "str",
    "secuid": "str",
    "symbol": "str",
}

QueryMSCashReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCashDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "pos_str": "str",
    "busidate": "int32_t",
    "custid": "str",
    "fundunit": "str",
    "currency_type": "int32_t",
    "subjectcode": "str",
    "settbody": "str",
    "orgid": "str",
    "brhid": "str",
    "trdsysid": "str",
    "coreid": "str",
    "fundid": "str",
    "subjectname": "str",
    "startbal": "int64_t",
    "endbal": "int64_t",
    "fundrealcommit": "int64_t",
    "awardamt": "int64_t",
    "punishamt": "int64_t",
    "totalnum": "int64_t",
}

QueryMSPositionsReq = {
    "pos_str": "str",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSPositionsDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "pos_str": "str",
    "busidate": "int32_t",
    "custid": "str",
    "fundunit": "str",
    "stkholdunit": "str",
    "secuid": "str",
    "mainseat": "str",
    "symbol": "str",
    "direction": "int16_t",
    "investtype": "int16_t",
    "stkid": "str",
    "stkproperty": "int16_t",
    "subjectcode": "str",
    "settbody": "str",
    "trdsysid": "str",
    "coreid": "str",
    "currency_type": "int32_t",
    "schemeid": "str",
    "subjectname": "str",
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
    "tacode": "str",
    "transacct": "str",
    "taacct": "str",
    "linkstkid": "str",
    "extint": "int32_t",
    "extamt": "int64_t",
    "extchar": "str",
    "extstr": "str",
    "totalnum": "int64_t",
}

QueryMSCreditDebtsFlowReq = {
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "market": "str",
    "code": "str",
    "pos_str": "str",
    "query_num": "int32_t",
    "qry_direct": "char",
}

MSCreditDebtsFlowDetail = {
    "account_id": "str",
    "cust_orgid": "str",
    "cust_branchid": "str",
    "account_type": "int16_t",
    "pos_str": "str",
    "busidate": "int32_t",
    "operdate": "int32_t",
    "sysdate": "int32_t",
    "logno": "str",
    "custid": "str",
    "creditdebtstype": "char",
    "lifekind": "bool",
    "direct": "char",
    "paykind": "char",
    "fundeffect": "int64_t",
    "fundbal": "int64_t",
    "stkeffect": "int64_t",
    "stkbal": "int64_t",
    "reladate": "int32_t",
    "relasno": "str",
    "symbol": "str",
    "remark": "str",
    "bizdate": "int32_t",
    "logassetsno": "str",
    "totalnum": "int64_t",
}

