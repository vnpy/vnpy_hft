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

SecuidInfo = {
    "market": "string",
    "secuid": "string",
    "fund_id": "string",
    "account_type": "int16_t",
    "account_status": "char",
    "account_class": "char",
}

LoginRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "cust_id": "string",
    "cust_name": "string",
    "secuid_array": "SecuidInfo",
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
    "ext_secuid_array": "SecuidInfo",
    "reg_branchid": "string",
}

OrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "long long",
    "price": "long long",
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
    "volume": "long long",
    "price": "long long",
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
    "volume": "long long",
    "price": "long long",
    "filled_volume": "long long",
    "filled_turnover": "long long",
    "filled_price": "long long",
    "cancel_volume": "long long",
    "cancel_flag": "int16_t",
    "order_date": "int32_t",
    "order_time": "int32_t",
    "err_code": "int32_t",
    "err_msg": "string",
    "secuid": "string",
    "name": "string",
    "freeze_amount": "long long",
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
    "volume": "long long",
    "price": "long long",
    "turnover": "long long",
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
    "order_price": "long long",
    "order_qty": "long long",
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
    "volume": "long long",
    "avail_volume": "long long",
    "init_volume": "long long",
    "market_value": "long long",
    "today_buy_volume": "long long",
    "today_sell_volume": "long long",
    "secuid": "string",
    "cost_price": "long long",
    "buy_cost": "long long",
    "last_price": "long long",
    "income": "long long",
    "total_income": "long long",
    "profit_cost": "long long",
    "today_avail_pr_volume": "long long",
    "market": "int32_t",
    "security_type": "int32_t",
    "freeze_volume": "long long",
    "name": "string",
    "currency_type": "int32_t",
    "security_type_apex": "int32_t",
    "profit_price": "long long",
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
    "total_amount": "long long",
    "avail_amount": "long long",
    "total_asset": "long long",
    "market_value": "long long",
    "init_amount": "long long",
    "fetch_balance": "long long",
}

JZJYAvailFundDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "avail_amount": "long long",
}

TransferFundReq = {
    "transfer_side": "int",
    "transfer_value": "long long",
    "market": "string",
}

TransferFundRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "transfer_value": "long long",
}

TransferFundSecuidReq = {
    "fund_out_market": "string",
    "fund_in_market": "string",
    "transfer_value": "long long",
}

TransferFundSecuidRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "transfer_value": "long long",
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
    "cash_component": "long long",
    "max_cash_ratio": "long long",
    "trade_state": "int32_t",
    "record_num": "int32_t",
    "trade_day": "int32_t",
    "pre_trade_day": "int32_t",
    "nav_percu": "long long",
    "nav": "long long",
    "creation_limituser": "long long",
    "redemption_limituser": "long long",
    "net_creation_limituser": "long long",
    "net_redemption_limituser": "long long",
    "creation_limit": "long long",
    "redemption_limit": "long long",
    "net_creation_limit": "long long",
    "net_redemption_limit": "long long",
    "etf_type": "int32_t",
    "cash_component_t1": "long long",
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
    "over_price_rate": "long long",
    "replace_amt": "long long",
}

QryMaxOrderQtyReq = {
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "price": "long long",
}

MaxOrderQtyDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_qty": "long long",
    "actual_max_qty": "long long",
    "max_pay_amt": "long long",
    "max_pay_qty": "long long",
    "sep_rem_qty": "long long",
}

IPOMaxPurchaseDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "market": "string",
    "max_qty": "long long",
    "stib_max_qty": "long long",
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
    "ipo_price": "long long",
    "max_num": "long long",
    "min_num": "long long",
    "security_type": "int32_t",
}

SecurityBaseInfo = {
    "symbol": "string",
    "name": "string",
    "security_type": "int32_t",
    "security_status": "int32_t",
    "price_tick": "long long",
    "limit_up": "long long",
    "limit_down": "long long",
    "max_qty": "long long",
    "min_qty": "long long",
    "buy_tick": "long long",
    "sale_tick": "long long",
    "has_price_limit": "int32_t",
    "limit_up_rate": "int",
    "is_registration": "int32_t",
    "limit_down_rate": "int",
}

QryByMarketReq = {
    "market": "string",
}

HKRateDetail = {
    "market": "string",
    "buy_rate": "long long",
    "sale_rate": "long long",
    "mid_rate": "long long",
    "set_rate": "long long",
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
    "fund_uncomeavl": "long long",
    "fund_buy": "long long",
    "fund_sale": "long long",
    "fund_uncomebuy": "long long",
    "fund_uncomesale": "long long",
}

QryHKMinPriceUnitReq = {
    "market": "string",
    "code": "string",
    "price": "long long",
    "pos_str": "string",
    "query_num": "int32_t",
}

HKMinPriceUnitDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "stktype": "int16_t",
    "begin_price": "long long",
    "end_price": "long long",
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
    "back_amt": "long long",
    "cl_order_id": "string",
}

CreditPayBackByOrderReq = {
    "sno": "string",
    "order_date": "int",
    "back_amt": "long long",
    "cl_order_id": "string",
    "credit_type": "int32_t",
}

CreditPayBackRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "real_back_amt": "long long",
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
    "margin_rate_fund": "long long",
    "margin_rate_stk": "long long",
    "sep_rem_qty": "int32_t",
}

CreditAssetsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "currency_type": "int16_t",
    "avail_balance": "long long",
    "fetch_balance": "long long",
    "frozen_balance": "long long",
    "stock_balance": "long long",
    "fund_balance": "long long",
    "asset_balance": "long long",
    "avail_margin": "long long",
    "credit_quota": "long long",
    "finance_quota": "long long",
    "shortsell_quota": "long long",
    "assure_ratio": "long long",
    "total_debt": "long long",
    "fund_debt": "long long",
    "stock_debt": "long long",
    "fund_interest_fee": "long long",
    "stock_interest_fee": "long long",
    "shortsell_total_balance": "long long",
    "shortsell_avail_balance": "long long",
    "shortsell_frozen_balance": "long long",
    "enbuyback_avail_balance": "long long",
    "fund_margin_profit": "long long",
    "stock_margin_profit": "long long",
    "fund_interest": "long long",
    "stock_interest": "long long",
    "fund_margin_balance": "long long",
    "stock_margin_balance": "long long",
    "fund_floating_deficit": "long long",
    "stock_floating_deficit": "long long",
    "fund_margin_profit_conversion": "long long",
    "stock_margin_profit_conversion": "long long",
    "hbjj_bal": "long long",
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
    "total_balance": "long long",
    "cur_balance": "long long",
    "total_interest_fee": "long long",
    "cur_interest_fee": "long long",
    "interest_rate": "long long",
    "repayable_balance": "long long",
    "f_deal_bal": "long long",
    "f_exp_cet_intr": "long long",
    "credit_repay_unfrz": "long long",
    "all_fee_unfrz": "long long",
    "market": "int32_t",
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
    "total_qty": "long long",
    "cur_qty": "long long",
    "total_interest_fee": "long long",
    "cur_interest_fee": "long long",
    "interest_rate": "long long",
    "d_stk_bal": "long long",
    "market": "int32_t",
    "all_fee_unfrz": "long long",
    "stk_repay_unfrz": "long long",
    "end_date": "int32_t",
    "init_cost_price": "long long",
}

CreditRepayAmountDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_back_amt": "long long",
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
    "total_qty": "long long",
    "max_back_qty": "long long",
    "returned_qty": "long long",
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
    "pledge_rate": "long long",
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
    "total_qty": "long long",
    "avail_qty": "long long",
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
    "init_amount": "long long",
    "total_amount": "long long",
    "avail_amount": "long long",
    "fetch_amount": "long long",
    "frozen_amount": "long long",
    "used_margin": "long long",
    "exercise_frozen": "long long",
    "deposit_amount": "long long",
    "withdraw_amount": "long long",
    "royalty_in": "long long",
    "royalty_out": "long long",
    "commission": "long long",
    "frozen_commission": "long long",
}

OptionPositionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
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
    "buy_cost": "long long",
    "secuid": "string",
    "margin": "long long",
    "frozen_margin": "long long",
    "commission": "long long",
    "frozen_commission": "long long",
    "exercise_frozen_amount": "long long",
    "frozen_amount": "long long",
    "today_close_profit": "long long",
    "buy_quota_used": "long long",
}

ExerciseReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "volume": "long long",
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
    "price_tick": "long long",
    "contract_status": "int32_t",
    "strike_price": "long long",
    "first_date": "int32_t",
    "last_date": "int32_t",
    "strike_date": "int32_t",
    "expire_date": "int32_t",
    "deliv_date": "int32_t",
    "is_up_down_limit": "int32_t",
    "margin_unit": "long long",
    "pre_settlement_price": "long long",
    "pre_close_price": "long long",
    "underlying_pre_close_price": "long long",
}

TransferStockReq = {
    "symbol": "string",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "long long",
}

TransferStockRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "symbol": "string",
    "transfer_type": "int16_t",
    "transfer_side": "int16_t",
    "transfer_qty": "long long",
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
    "yesterday_volume": "long long",
    "today_bs_volume": "long long",
    "today_pr_volume": "long long",
    "stock_cust_id": "string",
    "stock_secuid": "string",
    "status_msg": "string",
}

LockOrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "lock_type": "int16_t",
    "volume": "long long",
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
    "volume": "long long",
    "cancel_volume": "long long",
    "err_code": "int32_t",
    "err_msg": "string",
}

CombOrderReq = {
    "cl_order_id": "string",
    "symbol": "string",
    "comb_type": "int16_t",
    "comb_strategy": "int16_t",
    "volume": "long long",
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
    "volume": "long long",
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
    "volume": "long long",
    "cancel_volume": "long long",
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
    "volume": "long long",
    "cancel_volume": "long long",
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
    "volume": "long long",
    "avail_volume": "long long",
    "yesterday_volume": "long long",
    "yesterday_avail_volume": "long long",
    "today_volume": "long long",
    "today_avail_volume": "long long",
    "margin": "long long",
    "frozen_margin": "long long",
    "commission": "long long",
    "frozen_commission": "long long",
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
    "volume": "long long",
    "yesterday_volume": "long long",
    "today_volume": "long long",
    "comb_date": "int32_t",
    "comb_time": "int32_t",
    "comb_status": "int16_t",
    "secuid": "string",
    "legs_num": "int32_t",
    "leg1_symbol": "string",
    "leg1_yesterday_volume": "long long",
    "leg1_today_volume": "long long",
    "leg1_pos_side": "int16_t",
    "leg1_option_type": "int16_t",
    "leg2_symbol": "string",
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
    "used_fee_rate": "long long",
    "unused_fee_rate": "long long",
    "lock_qty": "int32_t",
    "used_qty": "int32_t",
    "back_qty": "int32_t",
    "begin_date": "int32_t",
    "back_date": "int32_t",
    "end_date": "int32_t",
    "hs_status": "int16_t",
    "wy_status": "int16_t",
}

ExtendLockSecurityReq = {
    "sys_date": "int32_t",
    "sno": "string",
    "apply_delay_days": "int32_t",
    "apply_used_fee_rate": "long long",
    "apply_unused_fee_rate": "long long",
    "apply_delay_qty": "int32_t",
    "symbol": "string",
}

ExtendLockSecurityRsp = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "apply_date": "int32_t",
    "apply_sno": "string",
}

QryLockSecurityExtensionReq = {
    "start_date": "int",
    "end_date": "int",
    "pos_str": "string",
    "query_num": "int32_t",
}

LockSecurityExtensionDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "apply_date": "int32_t",
    "apply_sno": "string",
    "sys_date": "int32_t",
    "sno": "string",
    "symbol": "string",
    "name": "string",
    "apply_end_date": "int32_t",
    "apply_delay_qty": "int32_t",
    "approval_used_fee_rate": "long long",
    "approval_unused_fee_rate": "long long",
    "approval_status": "int16_t",
    "approval_remark": "string",
    "old_end_date": "int32_t",
    "old_used_fee_rate": "long long",
    "old_unused_fee_rate": "long long",
    "old_left_qty": "long long",
    "old_violate_fee_rate": "long long",
    "old_hs_status": "int16_t",
    "apply_used_fee_rate": "long long",
    "apply_unused_fee_rate": "long long",
    "apply_delay_days": "int32_t",
    "approval_end_date": "int32_t",
    "approval_violate_fee_rate": "long long",
    "approval_delay_qty": "long long",
    "approval_delay_days": "int32_t",
    "hs_status": "int16_t",
    "wy_status": "int16_t",
    "lock_qty": "long long",
    "used_qty": "long long",
    "back_qty": "long long",
    "delay_qty": "long long",
    "oper_date": "int32_t",
    "oper_time": "int32_t",
    "back_type": "int16_t",
    "lock_price": "long long",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "real_date": "int32_t",
    "last_date": "int32_t",
    "deal_back_qty": "long long",
    "secuid": "string",
    "chk_date": "int32_t",
    "chk_time": "int32_t",
    "deal_flag": "int16_t",
    "deal_date": "int32_t",
}

TransferFundDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "serial_number": "string",
    "transact_date": "int32_t",
    "transact_time": "int32_t",
    "transfer_value": "long long",
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
    "market": "string",
}

AmountLimitsDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "long_amount_limit": "long long",
    "avail_long_amount_limit": "long long",
    "market": "string",
}

QrySplitCombMarginDiffReq = {
    "contract_id": "string",
    "comb_strategy": "int16_t",
    "volume": "long long",
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
    "volume": "long long",
    "left_leg_pos_margin": "long long",
    "left_leg_pos_live_margin": "long long",
    "right_leg_pos_margin": "long long",
    "right_leg_pos_live_margin": "long long",
    "comb_pos_margin": "long long",
    "comb_pos_live_margin": "long long",
    "margin_difference": "long long",
    "margin_live_difference": "long long",
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
    "option_unit": "long long",
    "underlying_contract_id": "string",
    "volume": "long long",
    "exercise_price": "long long",
    "exercise_side": "int32_t",
    "cover_flag": "int32_t",
}

QryOptionMaxOrderVolumeReq = {
    "contract_id": "string",
    "side": "int16_t",
    "order_type": "int16_t",
    "order_flag": "int16_t",
    "price": "long long",
}

OptionMaxOrderVolumeDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "max_volume": "long long",
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
    "order_time": "long long",
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
    "underlying_code": "string",
    "underlying_name": "string",
    "underlying_frozen_qty": "long long",
    "underlying_unfrozen_qty": "long long",
    "underlying_cancel_qty": "long long",
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
    "trade_time": "long long",
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
    "pos_str": "string",
    "query_num": "int32_t",
}

OptionHisDeliveryDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "settlement_id": "long long",
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
    "serial_number": "long long",
    "settlement_date": "int32_t",
    "occur_time": "long long",
    "market": "string",
    "currency_type": "int16_t",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "biz_amt": "long long",
    "fund_bln": "long long",
    "fund_avl": "long long",
    "frozen_margin": "long long",
    "unfrozen_margin": "long long",
    "underlying_code": "string",
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
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "settlement_date": "int32_t",
    "market": "string",
    "option_account": "string",
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
    "leg1_num": "string",
    "leg1_type": "int32_t",
    "leg1_side": "int32_t",
    "leg1_position": "long long",
    "leg2_num": "string",
    "leg2_type": "int32_t",
    "leg2_side": "int32_t",
    "leg2_position": "long long",
    "leg3_num": "string",
    "leg3_type": "int32_t",
    "leg3_side": "int32_t",
    "leg3_position": "long long",
    "leg4_num": "string",
    "leg4_type": "int32_t",
    "leg4_side": "int32_t",
    "leg4_position": "long long",
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
    "trade_time": "long long",
    "counter_order_id": "string",
    "market": "string",
    "currency_type": "int32_t",
    "option_account": "string",
    "option_security_type": "int32_t",
    "option_security_action": "int32_t",
    "option_num": "string",
    "option_name": "string",
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
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "function_id": "string",
    "tar_sys": "string",
    "request_content": "SecuidInfo",
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
    "response_list_first": "SecuidInfo",
    "first_list_len": "int32_t",
    "response_list_second": "SecuidInfo",
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
    "sno": "long long",
    "fund_bal": "long long",
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
    "fund_effect": "long long",
    "gm_fund_pwd": "string",
    "bank_pwd": "string",
}

BankSecTransferRsp = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "sno": "long long",
    "busi_type": "char",
    "fund_effect": "long long",
    "fund_bal": "long long",
    "status": "char",
}

QryBankSecTransferReq = {
    "currency_type": "int32_t",
    "sno": "long long",
}

BankSecTransferDetail = {
    "account_id": "string",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "account_type": "int16_t",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "currency_type": "int32_t",
    "cust_id": "string",
    "bank_code": "string",
    "bank_name": "string",
    "busi_type": "char",
    "sno": "long long",
    "fund_effect": "long long",
    "fund_bal": "long long",
    "remark": "string",
    "status": "char",
    "bank_msg_id": "string",
    "bank_msg": "string",
    "syserr_id": "long long",
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
    "oper_time": "long long",
    "sno": "long long",
    "fund_id": "string",
    "currency_type": "int32_t",
    "cust_id": "string",
    "cust_name": "string",
    "bank_code": "string",
    "bank_name": "string",
    "busi_type": "char",
    "fund_effect": "long long",
    "fund_bal": "long long",
    "remark": "string",
    "status": "char",
    "source_type": "char",
    "strike_flag": "char",
    "bank_msg_id": "string",
    "bank_msg": "string",
    "syserr_id": "long long",
}

FundAccountTransferReq = {
    "in_orgid": "string",
    "in_fund_id": "string",
    "out_orgid": "string",
    "out_fund_id": "string",
    "currency_type": "int32_t",
    "fund_effect": "long long",
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
    "oper_time": "long long",
    "bank_name": "string",
    "digest_id": "string",
    "currency_type": "int32_t",
    "fund_effect": "long long",
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
    "order_price": "long long",
    "order_qty": "long long",
    "oper_time": "long long",
    "order_frz_amt": "long long",
    "match_qty": "long long",
    "match_price": "long long",
    "match_amt": "long long",
    "cancel_qty": "long long",
    "order_status": "int32_t",
    "seat": "string",
    "oper_way": "char",
    "cancel_flag": "int16_t",
    "extqty1": "long long",
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
    "match_amt": "long long",
    "match_qty": "long long",
    "match_price": "long long",
    "order_qty": "long long",
    "order_price": "long long",
    "intr_amt": "long long",
    "stk_type": "string",
    "order_side": "int16_t",
    "oper_date": "int32_t",
    "match_date": "int32_t",
    "stk_bal": "long long",
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
    "order_time": "long long",
    "order_side": "int16_t",
    "apply_code": "string",
    "order_qty": "long long",
    "order_price": "long long",
    "match_time": "long long",
    "match_qty": "long long",
    "match_price": "long long",
    "match_amt": "long long",
    "fun_deffect": "long long",
    "fund_bal": "long long",
    "stk_effect": "long long",
    "stk_bal": "long long",
    "fee_seat": "long long",
    "fee_yjf": "long long",
    "fee_yhs": "long long",
    "fee_jsf": "long long",
    "fee_ghf": "long long",
    "fee_zgf": "long long",
    "fee_sxf": "long long",
    "fee_qsf": "long long",
    "fee_jggf": "long long",
    "fee_other": "long long",
    "fee_jsxf": "long long",
    "fee_jygf": "long long",
    "fee_front": "long long",
    "total_num": "int32_t",
    "clear_exch_rate": "long long",
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
    "order_qty": "long long",
    "order_price": "long long",
    "match_time": "int32_t",
    "match_qty": "long long",
    "match_price": "long long",
    "match_amt": "long long",
    "fund_effect": "long long",
    "fund_bal": "long long",
    "stkeff_ect": "long long",
    "stk_bal": "long long",
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
    "order_time": "long long",
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
    "match_time": "long long",
    "match_code": "string",
    "match_times": "long long",
    "match_qty": "long long",
    "match_price": "long long",
    "match_amt": "long long",
    "clear_amt": "long long",
    "fee_yhs": "long long",
    "fee_jsxf": "long long",
    "fee_sxf": "long long",
    "fee_ghf": "long long",
    "fee_qsf": "long long",
    "fee_jygf": "long long",
    "fee_front": "long long",
    "fee_jsf": "long long",
    "fee_zgf": "long long",
    "fee_other": "long long",
    "fund_bal": "long long",
    "stk_bal": "long long",
    "order_qty": "long long",
    "order_price": "long long",
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
    "query_index": "long long",
    "query_num": "long long",
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
    "match_qty": "long long",
    "mate_no": "string",
    "currency_type": "int16_t",
    "busi_type": "string",
    "link_stk_code": "string",
    "next_query_index": "long long",
    "total_num": "long long",
    "issue_stk_type": "char",
    "order_date": "int32_t",
}

QueryZQXXReq = {
    "query_index": "long long",
    "query_num": "long long",
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
    "hit_qty": "long long",
    "match_price": "long long",
    "order_date": "int32_t",
    "order_id": "string",
    "mate_no": "string",
    "currency_type": "int16_t",
    "busi_type": "string",
    "next_query_index": "long long",
    "total_num": "long long",
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
    "reserve_qty": "long long",
    "stk_bal": "long long",
    "stk_avl": "long long",
    "stk_used_qty": "long long",
    "stk_sale": "long long",
    "stk_sale_frz": "long long",
    "stk_repay": "long long",
    "used_fee_rate": "long long",
    "used_fee": "long long",
    "unused_fee_rate": "long long",
    "unused_fee": "long long",
    "over_used_fee": "long long",
    "over_unused_fee": "long long",
    "puni_used_fee": "long long",
    "puni_unused_fee": "long long",
    "violate_fee_rate": "long long",
    "violate_fee": "long long",
    "over_violate_fee": "long long",
    "puni_violate_fee": "long long",
    "cust_id": "string",
}

CreditContractDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "f_credit_rate": "long long",
    "f_year_mg_fee": "long long",
    "f_year_sr_fee": "long long",
    "d_credit_rate": "long long",
    "d_year_mg_fee": "long long",
    "d_year_sr_fee": "long long",
    "cancel_date": "int32_t",
    "currency_type": "int16_t",
    "contract_limit": "int32_t",
    "contract_status": "int32_t",
    "begin_date": "int32_t",
    "end_date": "int32_t",
    "f_prate": "long long",
    "d_prate": "long long",
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
    "match_amt": "long long",
    "match_qty": "long long",
    "credit_repay": "long long",
    "stk_repay": "long long",
    "credit_repay_unfrz": "long long",
    "stk_repay_unfrz": "long long",
    "credit_bal": "long long",
    "stk_bal": "long long",
    "last_price": "long long",
    "market_value": "long long",
    "credit_avl": "long long",
    "debts_profit": "long long",
    "adjust_profit": "long long",
    "credit_fee": "long long",
    "stk_debts_avl": "long long",
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
    "margin_avl": "long long",
    "credit_bal": "long long",
    "credit_avl": "long long",
    "margin_rate": "long long",
    "debts_bal": "long long",
    "max_amt": "long long",
    "fund_avl": "long long",
    "credit_fund_avl": "long long",
    "g_dis_market_avl": "long long",
    "mar_stk_val": "long long",
    "total_dis_f_mk_val": "long long",
    "mar_fund_profit": "long long",
    "mar_stk_profit": "long long",
    "total_rate_f_debts_bal": "long long",
    "mar_fund_margin": "long long",
    "mar_fund_margin_frz": "long long",
    "total_rate_d_sale_bal": "long long",
    "mar_stk_margin": "long long",
    "mar_stk_margin_frz": "long long",
    "total_fee": "long long",
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
    "match_qty": "long long",
    "match_amt": "long long",
    "leave_amt": "long long",
    "leave_qty": "long long",
    "all_fee": "long long",
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
    "match_qty": "long long",
    "match_amt": "long long",
    "leave_amt": "long long",
    "leave_value": "long long",
    "chk_remark": "string",
    "cfm_ans": "string",
    "leave_qty": "long long",
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
    "cum_voting_chosen_num": "long long",
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
    "rest_qty": "long long",
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
    "stk_bal": "long long",
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
    "vote_qty": "long long",
    "cur_vote_qty": "long long",
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
    "vote_qty": "long long",
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
    "fund_effect": "long long",
    "stk_effect": "long long",
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
    "fund_effect": "long long",
    "fund_bal": "long long",
    "stk_bal": "long long",
    "stk_code": "string",
    "stk_name": "string",
    "busi_type": "string",
    "side": "int16_t",
    "match_price": "long long",
    "match_qty": "long long",
    "match_amt": "long long",
    "order_id": "string",
    "pos_str": "string",
}

AppointContractSellStockRepayReq = {
    "order_date": "int32_t",
    "sno": "string",
    "cl_order_id": "string",
    "symbol": "string",
    "order_type": "int16_t",
    "side": "int16_t",
    "volume": "long long",
    "price": "long long",
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
    "order_id": "long long",
    "secuid": "string",
    "life_status": "int16_t",
    "d_stk_bal": "long long",
    "f_deal_bal": "long long",
    "f_deal_avl": "long long",
    "init_cost_price": "long long",
    "prof_cost_price": "long long",
    "profit_cost": "long long",
    "stk_repay_unfrz": "long long",
    "fee_unfrz": "long long",
    "over_due_fee_unfrz": "long long",
    "puni_fee_unfrz": "long long",
    "over_due_rights_unfrz": "long long",
    "puni_rights_unfrz": "long long",
    "puni_debts_unfrz": "long long",
    "all_fee_unfrz": "long long",
    "relese_amt": "long long",
    "relese_amt_unfrz": "long long",
    "credit_repay_unfrz": "long long",
    "f_exp_cet_intr": "long long",
    "f_debt_qty": "long long",
    "d_stk_avl": "long long",
    "last_price": "long long",
    "mkt_val": "long long",
    "buy_cost": "long long",
    "exp_cet_intr": "long long",
    "pos_str": "string",
    "credit_direct": "char",
    "match_qty": "long long",
    "stk_repay": "long long",
    "clear_amt": "long long",
    "credit_repay": "long long",
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
    "keep_rate_begin": "long long",
    "keep_rate_end": "long long",
    "debt_begin": "long long",
    "debt_end": "long long",
    "ctrl_rate": "long long",
}

MarginRiskDetail = {
    "account_id": "string",
    "account_type": "int16_t",
    "cust_orgid": "string",
    "cust_branchid": "string",
    "rt_risk_rate": "long long",
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
    "order_qty": "long long",
    "order_price": "long long",
    "order_frz_amt": "long long",
    "trade_fee": "long long",
    "settle_fee": "long long",
    "net_price": "long long",
    "return_rate": "long long",
    "total_bond_intr": "long long",
    "settle_days": "int32_t",
    "end_order_date": "int32_t",
    "settle_date": "int32_t",
    "settle_mode": "int16_t",
    "price_type": "int16_t",
    "match_type": "int16_t",
    "stk_name": "string",
    "oper_date": "int32_t",
    "oper_time": "long long",
    "match_price": "long long",
    "match_qty": "long long",
    "cancel_qty": "long long",
    "order_side": "int16_t",
    "contract_sno": "string",
    "refer_rate": "long long",
    "pos_str": "string",
    "total_num": "int32_t",
    "main_seat": "string",
    "match_amt": "long long",
    "remark": "string",
    "report_time": "long long",
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
    "total_asset": "long long",
    "fund_bal": "long long",
    "fund_avl": "long long",
    "fetch_bal": "long long",
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
    "order_id": "long long",
    "order_group": "long long",
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
    "voting_preference": "long long",
    "voting_segment": "string",
    "total_qty": "long long",
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
    "order_qty": "long long",
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
    "order_sno": "long long",
    "order_status": "int16_t",
    "report_time": "long long",
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
    "order_qty": "long long",
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
    "startbal": "long long",
    "endbal": "long long",
    "fundrealcommit": "long long",
    "awardamt": "long long",
    "punishamt": "long long",
    "totalnum": "long long",
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
    "startbal": "long long",
    "endbal": "long long",
    "startcost": "long long",
    "endcost": "long long",
    "startcostwithfee": "long long",
    "endcostwithfee": "long long",
    "starttradefee": "long long",
    "endtradefee": "long long",
    "startprofit": "long long",
    "endprofit": "long long",
    "startprofitwithfee": "long long",
    "endprofitwithfee": "long long",
    "startintrcost": "long long",
    "endintrcost": "long long",
    "startintrprofit": "long long",
    "endintrprofit": "long long",
    "tacode": "string",
    "transacct": "string",
    "taacct": "string",
    "linkstkid": "string",
    "extint": "int32_t",
    "extamt": "long long",
    "extchar": "string",
    "extstr": "string",
    "totalnum": "long long",
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
    "fundeffect": "long long",
    "fundbal": "long long",
    "stkeffect": "long long",
    "stkbal": "long long",
    "reladate": "int32_t",
    "relasno": "string",
    "symbol": "string",
    "remark": "string",
    "bizdate": "int32_t",
    "logassetsno": "string",
    "totalnum": "long long",
}

