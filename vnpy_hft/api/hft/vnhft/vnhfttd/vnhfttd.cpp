// vnctpmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnhfttd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------
void TdApi::OnDisconnect()
{
	gil_scoped_acquire acquire;
	this->onDisconnect();
};

void TdApi::OnError(ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onError(error, request_id);
};

void TdApi::OnRiskNotify(RiskNotify* risk_notify)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["secuid"] = toUtf(risk_notify->secuid);
		data["alarm_score"] = toUtf(risk_notify->alarm_score);
		data["alarm_status"] = toUtf(risk_notify->alarm_status);
		data["alarm_rule"] = toUtf(risk_notify->alarm_rule);
		data["alarm_time"] = toUtf(risk_notify->alarm_time);
		data["alarm_msg"] = toUtf(risk_notify->alarm_msg);
	}
	this->onRiskNotify(data);
};

void TdApi::OnFailBackNotify(FailBackNotify* failback_notify)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["system_id"] = toUtf(failback_notify->system_id);
		data["node_id"] = toUtf(failback_notify->node_id);
		data["status"] = failback_notify->status;
		data["credit_node_flag"] = failback_notify->credit_node_flag;
		data["urgent_flag"] = failback_notify->urgent_flag;
		data["update_source"] = toUtf(failback_notify->update_source);
	}
	this->onFailBackNotify(data);
};

void TdApi::OnLogin(LoginRsp* rsp, ErrorInfo* error_info)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["cust_id"] = toUtf(rsp->cust_id);
		data["cust_name"] = toUtf(rsp->cust_name);
		data["cif_account"] = toUtf(rsp->cif_account);
		data["user_code"] = toUtf(rsp->user_code);
		data["user_token"] = toUtf(rsp->user_token);
		data["token_serial_no"] = toUtf(rsp->token_serial_no);
		data["sm3_cipher"] = toUtf(rsp->sm3_cipher);
		data["sys_node_type"] = rsp->sys_node_type;
		data["clear_switch_flag"] = rsp->clear_switch_flag;
		data["trade_switch_flag"] = rsp->trade_switch_flag;
		data["sys_server_id"] = toUtf(rsp->sys_server_id);
		data["operway"] = rsp->operway;
		data["sys_shbond_type"] = rsp->sys_shbond_type;
		data["reg_branchid"] = toUtf(rsp->reg_branchid);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onLogin(data, error);
};

void TdApi::OnTradeReport(TradeDetail* trade_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(trade_detail->account_id);
		data["account_type"] = trade_detail->account_type;
		data["cust_orgid"] = toUtf(trade_detail->cust_orgid);
		data["cust_branchid"] = toUtf(trade_detail->cust_branchid);
		data["order_id"] = toUtf(trade_detail->order_id);
		data["cl_order_id"] = toUtf(trade_detail->cl_order_id);
		data["symbol"] = toUtf(trade_detail->symbol);
		data["order_type"] = trade_detail->order_type;
		data["side"] = trade_detail->side;
		data["report_type"] = trade_detail->report_type;
		data["report_no"] = toUtf(trade_detail->report_no);
		data["volume"] = trade_detail->volume;
		data["price"] = trade_detail->price;
		data["turnover"] = trade_detail->turnover;
		data["trade_date"] = trade_detail->trade_date;
		data["trade_time"] = trade_detail->trade_time;
		data["err_code"] = trade_detail->err_code;
		data["err_msg"] = toUtf(trade_detail->err_msg);
		data["secuid"] = toUtf(trade_detail->secuid);
		data["name"] = toUtf(trade_detail->name);
		data["contract_id"] = toUtf(trade_detail->contract_id);
		data["ex_report_no"] = toUtf(trade_detail->ex_report_no);
		data["ex_order_id"] = toUtf(trade_detail->ex_order_id);
		data["margin_amt_type"] = trade_detail->margin_amt_type;
		data["order_price"] = trade_detail->order_price;
		data["order_qty"] = trade_detail->order_qty;
	}
	this->onTradeReport(data);
};

void TdApi::OnOrderStatus(OrderDetail* order_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["order_id"] = toUtf(order_detail->order_id);
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["orig_order_id"] = toUtf(order_detail->orig_order_id);
		data["symbol"] = toUtf(order_detail->symbol);
		data["order_status"] = order_detail->order_status;
		data["order_type"] = order_detail->order_type;
		data["side"] = order_detail->side;
		data["volume"] = order_detail->volume;
		data["price"] = order_detail->price;
		data["filled_volume"] = order_detail->filled_volume;
		data["filled_turnover"] = order_detail->filled_turnover;
		data["filled_price"] = order_detail->filled_price;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["cancel_flag"] = order_detail->cancel_flag;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
		data["secuid"] = toUtf(order_detail->secuid);
		data["name"] = toUtf(order_detail->name);
		data["freeze_amount"] = order_detail->freeze_amount;
		data["contract_id"] = toUtf(order_detail->contract_id);
		data["ex_order_id"] = toUtf(order_detail->ex_order_id);
	}
	this->onOrderStatus(data);
};

void TdApi::OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["order_date"] = order_rsp->order_date;
		data["order_id"] = toUtf(order_rsp->order_id);
		data["cl_order_id"] = toUtf(order_rsp->cl_order_id);
		data["contract_id"] = toUtf(order_rsp->contract_id);
		data["ex_order_id"] = toUtf(order_rsp->ex_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onOrderRsp(data, error, request_id, is_last);
};

void TdApi::OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(cancel_rsp->account_id);
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = toUtf(cancel_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(cancel_rsp->cust_branchid);
		data["order_id"] = toUtf(cancel_rsp->order_id);
		data["cl_order_id"] = toUtf(cancel_rsp->cl_order_id);
		data["cl_cancel_id"] = toUtf(cancel_rsp->cl_cancel_id);
		data["cancel_id"] = toUtf(cancel_rsp->cancel_id);
		data["ex_order_id"] = toUtf(cancel_rsp->ex_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCancelRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryOrderRsp(OrderDetail* order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["order_id"] = toUtf(order_detail->order_id);
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["orig_order_id"] = toUtf(order_detail->orig_order_id);
		data["symbol"] = toUtf(order_detail->symbol);
		data["order_status"] = order_detail->order_status;
		data["order_type"] = order_detail->order_type;
		data["side"] = order_detail->side;
		data["volume"] = order_detail->volume;
		data["price"] = order_detail->price;
		data["filled_volume"] = order_detail->filled_volume;
		data["filled_turnover"] = order_detail->filled_turnover;
		data["filled_price"] = order_detail->filled_price;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["cancel_flag"] = order_detail->cancel_flag;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
		data["secuid"] = toUtf(order_detail->secuid);
		data["name"] = toUtf(order_detail->name);
		data["freeze_amount"] = order_detail->freeze_amount;
		data["contract_id"] = toUtf(order_detail->contract_id);
		data["ex_order_id"] = toUtf(order_detail->ex_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryTradeRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(trade_detail->account_id);
		data["account_type"] = trade_detail->account_type;
		data["cust_orgid"] = toUtf(trade_detail->cust_orgid);
		data["cust_branchid"] = toUtf(trade_detail->cust_branchid);
		data["order_id"] = toUtf(trade_detail->order_id);
		data["cl_order_id"] = toUtf(trade_detail->cl_order_id);
		data["symbol"] = toUtf(trade_detail->symbol);
		data["order_type"] = trade_detail->order_type;
		data["side"] = trade_detail->side;
		data["report_type"] = trade_detail->report_type;
		data["report_no"] = toUtf(trade_detail->report_no);
		data["volume"] = trade_detail->volume;
		data["price"] = trade_detail->price;
		data["turnover"] = trade_detail->turnover;
		data["trade_date"] = trade_detail->trade_date;
		data["trade_time"] = trade_detail->trade_time;
		data["err_code"] = trade_detail->err_code;
		data["err_msg"] = toUtf(trade_detail->err_msg);
		data["secuid"] = toUtf(trade_detail->secuid);
		data["name"] = toUtf(trade_detail->name);
		data["contract_id"] = toUtf(trade_detail->contract_id);
		data["ex_report_no"] = toUtf(trade_detail->ex_report_no);
		data["ex_order_id"] = toUtf(trade_detail->ex_order_id);
		data["margin_amt_type"] = trade_detail->margin_amt_type;
		data["order_price"] = trade_detail->order_price;
		data["order_qty"] = trade_detail->order_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryTradeRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryPositionRsp(PositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(position_detail->account_id);
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = toUtf(position_detail->cust_orgid);
		data["cust_branchid"] = toUtf(position_detail->cust_branchid);
		data["symbol"] = toUtf(position_detail->symbol);
		data["side"] = position_detail->side;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["init_volume"] = position_detail->init_volume;
		data["market_value"] = position_detail->market_value;
		data["today_buy_volume"] = position_detail->today_buy_volume;
		data["today_sell_volume"] = position_detail->today_sell_volume;
		data["secuid"] = toUtf(position_detail->secuid);
		data["cost_price"] = position_detail->cost_price;
		data["buy_cost"] = position_detail->buy_cost;
		data["last_price"] = position_detail->last_price;
		data["income"] = position_detail->income;
		data["total_income"] = position_detail->total_income;
		data["profit_cost"] = position_detail->profit_cost;
		data["today_avail_pr_volume"] = position_detail->today_avail_pr_volume;
		data["market"] = position_detail->market;
		data["security_type"] = position_detail->security_type;
		data["freeze_volume"] = position_detail->freeze_volume;
		data["name"] = toUtf(position_detail->name);
		data["currency_type"] = position_detail->currency_type;
		data["security_type_apex"] = position_detail->security_type_apex;
		data["profit_price"] = position_detail->profit_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPositionRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCashRsp(CashDetail* cash_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(cash_detail->account_id);
		data["account_type"] = cash_detail->account_type;
		data["cust_orgid"] = toUtf(cash_detail->cust_orgid);
		data["cust_branchid"] = toUtf(cash_detail->cust_branchid);
		data["currency_type"] = cash_detail->currency_type;
		data["total_amount"] = cash_detail->total_amount;
		data["avail_amount"] = cash_detail->avail_amount;
		data["total_asset"] = cash_detail->total_asset;
		data["market_value"] = cash_detail->market_value;
		data["init_amount"] = cash_detail->init_amount;
		data["fetch_balance"] = cash_detail->fetch_balance;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCashRsp(data, error, request_id);
};

void TdApi::OnQueryJZJYAvailFundRsp(int64_t avail_balance, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryJZJYAvailFundRsp(avail_balance, error, request_id);
};

void TdApi::OnTransferFundInAndOutRsp(int64_t transfer_value, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onTransferFundInAndOutRsp(transfer_value, error, request_id);
};

void TdApi::OnTransferFundBetweenSecuidRsp(int64_t transfer_value, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onTransferFundBetweenSecuidRsp(transfer_value, error, request_id);
};

void TdApi::OnQueryETFRsp(ETFDetail* etf_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(etf_detail->account_id);
		data["account_type"] = etf_detail->account_type;
		data["cust_orgid"] = toUtf(etf_detail->cust_orgid);
		data["cust_branchid"] = toUtf(etf_detail->cust_branchid);
		data["name"] = toUtf(etf_detail->name);
		data["first_symbol"] = toUtf(etf_detail->first_symbol);
		data["second_symbol"] = toUtf(etf_detail->second_symbol);
		data["trade_unit"] = etf_detail->trade_unit;
		data["cash_component"] = etf_detail->cash_component;
		data["max_cash_ratio"] = etf_detail->max_cash_ratio;
		data["trade_state"] = etf_detail->trade_state;
		data["record_num"] = etf_detail->record_num;
		data["trade_day"] = etf_detail->trade_day;
		data["pre_trade_day"] = etf_detail->pre_trade_day;
		data["nav_percu"] = etf_detail->nav_percu;
		data["nav"] = etf_detail->nav;
		data["creation_limituser"] = etf_detail->creation_limituser;
		data["redemption_limituser"] = etf_detail->redemption_limituser;
		data["net_creation_limituser"] = etf_detail->net_creation_limituser;
		data["net_redemption_limituser"] = etf_detail->net_redemption_limituser;
		data["creation_limit"] = etf_detail->creation_limit;
		data["redemption_limit"] = etf_detail->redemption_limit;
		data["net_creation_limit"] = etf_detail->net_creation_limit;
		data["net_redemption_limit"] = etf_detail->net_redemption_limit;
		data["etf_type"] = etf_detail->etf_type;
		data["cash_component_t1"] = etf_detail->cash_component_t1;
		data["internal_trade_state"] = etf_detail->internal_trade_state;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryETFRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryETFStockRsp(ETFStockDetail* etf_stock_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(etf_stock_detail->account_id);
		data["account_type"] = etf_stock_detail->account_type;
		data["cust_orgid"] = toUtf(etf_stock_detail->cust_orgid);
		data["cust_branchid"] = toUtf(etf_stock_detail->cust_branchid);
		data["first_symbol"] = toUtf(etf_stock_detail->first_symbol);
		data["name"] = toUtf(etf_stock_detail->name);
		data["symbol"] = toUtf(etf_stock_detail->symbol);
		data["volume"] = etf_stock_detail->volume;
		data["replace_flag"] = etf_stock_detail->replace_flag;
		data["over_price_rate"] = etf_stock_detail->over_price_rate;
		data["replace_amt"] = etf_stock_detail->replace_amt;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryETFStockRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryMaxOrderQtyRsp(MaxOrderQtyDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["max_qty"] = detail->max_qty;
		data["actual_max_qty"] = detail->actual_max_qty;
		data["max_pay_amt"] = detail->max_pay_amt;
		data["max_pay_qty"] = detail->max_pay_qty;
		data["sep_rem_qty"] = detail->sep_rem_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryMaxOrderQtyRsp(data, error, request_id);
};

void TdApi::OnQueryIPOMaxPurchaseRsp(IPOMaxPurchaseDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["market"] = toUtf(detail->market);
		data["max_qty"] = detail->max_qty;
		data["stib_max_qty"] = detail->stib_max_qty;
		data["secuid"] = toUtf(detail->secuid);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryIPOMaxPurchaseRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryIPOStockRsp(IPOStockDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["currency_type"] = detail->currency_type;
		data["ipo_price"] = detail->ipo_price;
		data["max_num"] = detail->max_num;
		data["min_num"] = detail->min_num;
		data["security_type"] = detail->security_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryIPOStockRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQuerySecurityBaseInfoRsp(SecurityBaseInfo* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["security_type"] = detail->security_type;
		data["security_status"] = detail->security_status;
		data["price_tick"] = detail->price_tick;
		data["limit_up"] = detail->limit_up;
		data["limit_down"] = detail->limit_down;
		data["max_qty"] = detail->max_qty;
		data["min_qty"] = detail->min_qty;
		data["buy_tick"] = detail->buy_tick;
		data["sale_tick"] = detail->sale_tick;
		data["has_price_limit"] = detail->has_price_limit;
		data["limit_up_rate"] = detail->limit_up_rate;
		data["is_registration"] = detail->is_registration;
		data["limit_down_rate"] = detail->limit_down_rate;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQuerySecurityBaseInfoRsp(data, error, request_id, is_last);
};

void TdApi::OnCreditMortgageInOutRsp(CreditMortgageInOutRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["cl_order_id"] = toUtf(rsp->cl_order_id);
		data["order_id"] = toUtf(rsp->order_id);
		data["contract_id"] = toUtf(rsp->contract_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCreditMortgageInOutRsp(data, error, request_id);
};

void TdApi::OnCreditStockBackRsp(CreditStockBackRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["cl_order_id"] = toUtf(rsp->cl_order_id);
		data["order_id"] = toUtf(rsp->order_id);
		data["contract_id"] = toUtf(rsp->contract_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCreditStockBackRsp(data, error, request_id);
};

void TdApi::OnCreditPayBackRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["real_back_amt"] = rsp->real_back_amt;
		data["cl_order_id"] = toUtf(rsp->cl_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCreditPayBackRsp(data, error, request_id);
};

void TdApi::OnCreditPayBackByOrderRsp(CreditPayBackRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["real_back_amt"] = rsp->real_back_amt;
		data["cl_order_id"] = toUtf(rsp->cl_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCreditPayBackByOrderRsp(data, error, request_id);
};

void TdApi::OnQueryCreditStockRsp(CreditStockDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["currency_type"] = detail->currency_type;
		data["credit_fund_ctrl"] = detail->credit_fund_ctrl;
		data["credit_stk_ctrl"] = detail->credit_stk_ctrl;
		data["margin_rate_fund"] = detail->margin_rate_fund;
		data["margin_rate_stk"] = detail->margin_rate_stk;
		data["sep_rem_qty"] = detail->sep_rem_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditStockRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditMortgageHoldRsp(CreditMortgageHoldDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["currency_type"] = detail->currency_type;
		data["pledge_rate"] = detail->pledge_rate;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditMortgageHoldRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditAssetsRsp(CreditAssetsDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["currency_type"] = detail->currency_type;
		data["avail_balance"] = detail->avail_balance;
		data["fetch_balance"] = detail->fetch_balance;
		data["frozen_balance"] = detail->frozen_balance;
		data["stock_balance"] = detail->stock_balance;
		data["fund_balance"] = detail->fund_balance;
		data["asset_balance"] = detail->asset_balance;
		data["avail_margin"] = detail->avail_margin;
		data["credit_quota"] = detail->credit_quota;
		data["finance_quota"] = detail->finance_quota;
		data["shortsell_quota"] = detail->shortsell_quota;
		data["assure_ratio"] = detail->assure_ratio;
		data["total_debt"] = detail->total_debt;
		data["fund_debt"] = detail->fund_debt;
		data["stock_debt"] = detail->stock_debt;
		data["fund_interest_fee"] = detail->fund_interest_fee;
		data["stock_interest_fee"] = detail->stock_interest_fee;
		data["shortsell_total_balance"] = detail->shortsell_total_balance;
		data["shortsell_avail_balance"] = detail->shortsell_avail_balance;
		data["shortsell_frozen_balance"] = detail->shortsell_frozen_balance;
		data["enbuyback_avail_balance"] = detail->enbuyback_avail_balance;
		data["fund_margin_profit"] = detail->fund_margin_profit;
		data["stock_margin_profit"] = detail->stock_margin_profit;
		data["fund_interest"] = detail->fund_interest;
		data["stock_interest"] = detail->stock_interest;
		data["fund_margin_balance"] = detail->fund_margin_balance;
		data["stock_margin_balance"] = detail->stock_margin_balance;
		data["fund_floating_deficit"] = detail->fund_floating_deficit;
		data["stock_floating_deficit"] = detail->stock_floating_deficit;
		data["fund_margin_profit_conversion"] = detail->fund_margin_profit_conversion;
		data["stock_margin_profit_conversion"] = detail->stock_margin_profit_conversion;
		data["hbjj_bal"] = detail->hbjj_bal;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditAssetsRsp(data, error, request_id);
};

void TdApi::OnQueryCreditFinanceRsp(CreditFinanceDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["sno"] = toUtf(detail->sno);
		data["currency_type"] = detail->currency_type;
		data["life_status"] = detail->life_status;
		data["occur_date"] = detail->occur_date;
		data["total_balance"] = detail->total_balance;
		data["cur_balance"] = detail->cur_balance;
		data["total_interest_fee"] = detail->total_interest_fee;
		data["cur_interest_fee"] = detail->cur_interest_fee;
		data["interest_rate"] = detail->interest_rate;
		data["repayable_balance"] = detail->repayable_balance;
		data["f_deal_bal"] = detail->f_deal_bal;
		data["f_exp_cet_intr"] = detail->f_exp_cet_intr;
		data["credit_repay_unfrz"] = detail->credit_repay_unfrz;
		data["all_fee_unfrz"] = detail->all_fee_unfrz;
		data["market"] = detail->market;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditFinanceRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditShortsellRsp(CreditShortsellDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["sno"] = toUtf(detail->sno);
		data["currency_type"] = detail->currency_type;
		data["life_status"] = detail->life_status;
		data["occur_date"] = detail->occur_date;
		data["total_qty"] = detail->total_qty;
		data["cur_qty"] = detail->cur_qty;
		data["total_interest_fee"] = detail->total_interest_fee;
		data["cur_interest_fee"] = detail->cur_interest_fee;
		data["interest_rate"] = detail->interest_rate;
		data["d_stk_bal"] = detail->d_stk_bal;
		data["market"] = detail->market;
		data["all_fee_unfrz"] = detail->all_fee_unfrz;
		data["stk_repay_unfrz"] = detail->stk_repay_unfrz;
		data["end_date"] = detail->end_date;
		data["init_cost_price"] = detail->init_cost_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditShortsellRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditRepayAmountRsp(CreditRepayAmountDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["max_back_amt"] = detail->max_back_amt;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditRepayAmountRsp(data, error, request_id);
};

void TdApi::OnQueryCreditRepayStockRsp(CreditRepayStockDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["total_qty"] = detail->total_qty;
		data["max_back_qty"] = detail->max_back_qty;
		data["returned_qty"] = detail->returned_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditRepayStockRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditSecuritySellQtyRsp(CreditSecuritySellQtyRsp* rsp, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["symbol"] = toUtf(rsp->symbol);
		data["total_qty"] = rsp->total_qty;
		data["avail_qty"] = rsp->avail_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditSecuritySellQtyRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQuerySecuidRightRsp(QrySecuidRightRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["market"] = toUtf(rsp->market);
		data["secuid_right"] = rsp->secuid_right;
		data["sign_flag"] = rsp->sign_flag;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQuerySecuidRightRsp(data, error, request_id);
};

void TdApi::OnQueryHKRateRsp(HKRateDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["market"] = toUtf(detail->market);
		data["buy_rate"] = detail->buy_rate;
		data["sale_rate"] = detail->sale_rate;
		data["mid_rate"] = detail->mid_rate;
		data["set_rate"] = detail->set_rate;
		data["sys_date"] = detail->sys_date;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKRateRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryHKStockRsp(HKStockDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["stktype"] = detail->stktype;
		data["currency_type"] = detail->currency_type;
		data["security_type"] = detail->security_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKStockRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryHKFundRsp(HKFundDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["currency_type"] = detail->currency_type;
		data["fund_uncomeavl"] = detail->fund_uncomeavl;
		data["fund_buy"] = detail->fund_buy;
		data["fund_sale"] = detail->fund_sale;
		data["fund_uncomebuy"] = detail->fund_uncomebuy;
		data["fund_uncomesale"] = detail->fund_uncomesale;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKFundRsp(data, error, request_id);
};

void TdApi::OnQueryHKMinPriceUnitRsp(HKMinPriceUnitDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["stktype"] = detail->stktype;
		data["begin_price"] = detail->begin_price;
		data["end_price"] = detail->end_price;
		data["price_unit"] = detail->price_unit;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKMinPriceUnitRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryHKTradeCalendarRsp(HKTradeCalendarDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["date"] = detail->date;
		data["business_flag"] = detail->business_flag;
		data["commit_flag"] = detail->commit_flag;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKTradeCalendarRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryLockSecurityDetailRsp(LockSecurityDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["sys_date"] = detail->sys_date;
		data["sno"] = toUtf(detail->sno);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["lock_type"] = detail->lock_type;
		data["used_fee_rate"] = detail->used_fee_rate;
		data["unused_fee_rate"] = detail->unused_fee_rate;
		data["lock_qty"] = detail->lock_qty;
		data["used_qty"] = detail->used_qty;
		data["back_qty"] = detail->back_qty;
		data["begin_date"] = detail->begin_date;
		data["back_date"] = detail->back_date;
		data["end_date"] = detail->end_date;
		data["hs_status"] = detail->hs_status;
		data["wy_status"] = detail->wy_status;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryLockSecurityDetailRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnExtendLockSecurityRsp(ExtendLockSecurityRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["apply_date"] = rsp->apply_date;
		data["apply_sno"] = toUtf(rsp->apply_sno);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onExtendLockSecurityRsp(data, error, request_id);
};

void TdApi::OnQueryLockSecurityExtensionRsp(LockSecurityExtensionDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["apply_date"] = detail->apply_date;
		data["apply_sno"] = toUtf(detail->apply_sno);
		data["sys_date"] = detail->sys_date;
		data["sno"] = toUtf(detail->sno);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["apply_end_date"] = detail->apply_end_date;
		data["apply_delay_qty"] = detail->apply_delay_qty;
		data["approval_used_fee_rate"] = detail->approval_used_fee_rate;
		data["approval_unused_fee_rate"] = detail->approval_unused_fee_rate;
		data["approval_status"] = detail->approval_status;
		data["approval_remark"] = toUtf(detail->approval_remark);
		data["old_end_date"] = detail->old_end_date;
		data["old_used_fee_rate"] = detail->old_used_fee_rate;
		data["old_unused_fee_rate"] = detail->old_unused_fee_rate;
		data["old_left_qty"] = detail->old_left_qty;
		data["old_violate_fee_rate"] = detail->old_violate_fee_rate;
		data["old_hs_status"] = detail->old_hs_status;
		data["apply_used_fee_rate"] = detail->apply_used_fee_rate;
		data["apply_unused_fee_rate"] = detail->apply_unused_fee_rate;
		data["apply_delay_days"] = detail->apply_delay_days;
		data["approval_end_date"] = detail->approval_end_date;
		data["approval_violate_fee_rate"] = detail->approval_violate_fee_rate;
		data["approval_delay_qty"] = detail->approval_delay_qty;
		data["approval_delay_days"] = detail->approval_delay_days;
		data["hs_status"] = detail->hs_status;
		data["wy_status"] = detail->wy_status;
		data["lock_qty"] = detail->lock_qty;
		data["used_qty"] = detail->used_qty;
		data["back_qty"] = detail->back_qty;
		data["delay_qty"] = detail->delay_qty;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["back_type"] = detail->back_type;
		data["lock_price"] = detail->lock_price;
		data["begin_date"] = detail->begin_date;
		data["end_date"] = detail->end_date;
		data["real_date"] = detail->real_date;
		data["last_date"] = detail->last_date;
		data["deal_back_qty"] = detail->deal_back_qty;
		data["secuid"] = toUtf(detail->secuid);
		data["chk_date"] = detail->chk_date;
		data["chk_time"] = detail->chk_time;
		data["deal_flag"] = detail->deal_flag;
		data["deal_date"] = detail->deal_date;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryLockSecurityExtensionRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryTransferFundHistoryRsp(TransferFundDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["serial_number"] = toUtf(detail->serial_number);
		data["transact_date"] = detail->transact_date;
		data["transact_time"] = detail->transact_time;
		data["transfer_value"] = detail->transfer_value;
		data["transfer_side"] = detail->transfer_side;
		data["transfer_status"] = detail->transfer_status;
		data["remark"] = toUtf(detail->remark);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryTransferFundHistoryRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryCreditDebtsFlowRsp(CreditDebtsFlowDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["currency_type"] = detail->currency_type;
		data["debt_type"] = detail->debt_type;
		data["effect_direct"] = detail->effect_direct;
		data["repay_way"] = detail->repay_way;
		data["stk_code"] = toUtf(detail->stk_code);
		data["stk_name"] = toUtf(detail->stk_name);
		data["details_sno"] = toUtf(detail->details_sno);
		data["relate_sys_date"] = detail->relate_sys_date;
		data["relate_sno"] = toUtf(detail->relate_sno);
		data["market_id"] = detail->market_id;
		data["fund_effect"] = detail->fund_effect;
		data["stk_effect"] = detail->stk_effect;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditDebtsFlowRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditAssetFlowRsp(CreditAssetFlowDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["biz_date"] = detail->biz_date;
		data["details_sno"] = toUtf(detail->details_sno);
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["digest_id"] = detail->digest_id;
		data["digest_name"] = toUtf(detail->digest_name);
		data["currency_type"] = detail->currency_type;
		data["secuid"] = toUtf(detail->secuid);
		data["market_id"] = detail->market_id;
		data["fund_effect"] = detail->fund_effect;
		data["fund_bal"] = detail->fund_bal;
		data["stk_bal"] = detail->stk_bal;
		data["stk_code"] = toUtf(detail->stk_code);
		data["stk_name"] = toUtf(detail->stk_name);
		data["busi_type"] = toUtf(detail->busi_type);
		data["side"] = detail->side;
		data["match_price"] = detail->match_price;
		data["match_qty"] = detail->match_qty;
		data["match_amt"] = detail->match_amt;
		data["order_id"] = toUtf(detail->order_id);
		data["pos_str"] = toUtf(detail->pos_str);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditAssetFlowRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditDebtsRsp(CreditDebtsDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["sys_date"] = detail->sys_date;
		data["end_date"] = detail->end_date;
		data["sno"] = toUtf(detail->sno);
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["security_symbol"] = toUtf(detail->security_symbol);
		data["order_date"] = detail->order_date;
		data["order_id"] = detail->order_id;
		data["secuid"] = toUtf(detail->secuid);
		data["life_status"] = detail->life_status;
		data["d_stk_bal"] = detail->d_stk_bal;
		data["f_deal_bal"] = detail->f_deal_bal;
		data["f_deal_avl"] = detail->f_deal_avl;
		data["init_cost_price"] = detail->init_cost_price;
		data["prof_cost_price"] = detail->prof_cost_price;
		data["profit_cost"] = detail->profit_cost;
		data["stk_repay_unfrz"] = detail->stk_repay_unfrz;
		data["fee_unfrz"] = detail->fee_unfrz;
		data["over_due_fee_unfrz"] = detail->over_due_fee_unfrz;
		data["puni_fee_unfrz"] = detail->puni_fee_unfrz;
		data["over_due_rights_unfrz"] = detail->over_due_rights_unfrz;
		data["puni_rights_unfrz"] = detail->puni_rights_unfrz;
		data["puni_debts_unfrz"] = detail->puni_debts_unfrz;
		data["all_fee_unfrz"] = detail->all_fee_unfrz;
		data["relese_amt"] = detail->relese_amt;
		data["relese_amt_unfrz"] = detail->relese_amt_unfrz;
		data["credit_repay_unfrz"] = detail->credit_repay_unfrz;
		data["f_exp_cet_intr"] = detail->f_exp_cet_intr;
		data["f_debt_qty"] = detail->f_debt_qty;
		data["d_stk_avl"] = detail->d_stk_avl;
		data["last_price"] = detail->last_price;
		data["mkt_val"] = detail->mkt_val;
		data["buy_cost"] = detail->buy_cost;
		data["exp_cet_intr"] = detail->exp_cet_intr;
		data["pos_str"] = toUtf(detail->pos_str);
		data["credit_direct"] = detail->credit_direct;
		data["match_qty"] = detail->match_qty;
		data["stk_repay"] = detail->stk_repay;
		data["clear_amt"] = detail->clear_amt;
		data["credit_repay"] = detail->credit_repay;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditDebtsRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["call_status"] = rsp->call_status;
		data["error_code"] = toUtf(rsp->error_code);
		data["error_info"] = toUtf(rsp->error_info);
		data["error_extra"] = toUtf(rsp->error_extra);
		data["response_list_first"] = toUtf(rsp->response_list_first);
		data["first_list_len"] = rsp->first_list_len;
		data["response_list_second"] = toUtf(rsp->response_list_second);
		data["second_list_len"] = rsp->second_list_len;
	}
	this->onMicroServiceRsp(data, request_id);
};

void TdApi::OnQueryBankBalanceRsp(BankBalanceDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["status"] = detail->status;
		data["sno"] = detail->sno;
		data["fund_bal"] = detail->fund_bal;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryBankBalanceRsp(data, error, request_id);
};

void TdApi::OnQueryBankInfoRsp(BankInfoDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["cust_id"] = toUtf(detail->cust_id);
		data["currency_type"] = detail->currency_type;
		data["bank_code"] = toUtf(detail->bank_code);
		data["bank_name"] = toUtf(detail->bank_name);
		data["bankid"] = toUtf(detail->bankid);
		data["bankpwdflag"] = detail->bankpwdflag;
		data["qrybankfund"] = detail->qrybankfund;
		data["status"] = detail->status;
		data["banktype"] = detail->banktype;
		data["sourcetype"] = detail->sourcetype;
		data["custodystate"] = detail->custodystate;
		data["custodyflag"] = detail->custodyflag;
		data["confirmflag"] = detail->confirmflag;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryBankInfoRsp(data, error, request_id, is_last);
};

void TdApi::OnBankSecTransferRsp(BankSecTransferRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
		data["account_type"] = rsp->account_type;
		data["sno"] = rsp->sno;
		data["busi_type"] = rsp->busi_type;
		data["fund_effect"] = rsp->fund_effect;
		data["fund_bal"] = rsp->fund_bal;
		data["status"] = rsp->status;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onBankSecTransferRsp(data, error, request_id);
};

void TdApi::OnQueryBankSecTransferRsp(BankSecTransferDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["currency_type"] = detail->currency_type;
		data["cust_id"] = toUtf(detail->cust_id);
		data["bank_code"] = toUtf(detail->bank_code);
		data["bank_name"] = toUtf(detail->bank_name);
		data["busi_type"] = detail->busi_type;
		data["sno"] = detail->sno;
		data["fund_effect"] = detail->fund_effect;
		data["fund_bal"] = detail->fund_bal;
		data["remark"] = toUtf(detail->remark);
		data["status"] = detail->status;
		data["bank_msg_id"] = toUtf(detail->bank_msg_id);
		data["bank_msg"] = toUtf(detail->bank_msg);
		data["syserr_id"] = detail->syserr_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryBankSecTransferRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryHisBankSecTransferRsp(HisBankSecTransferDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["pos_str"] = toUtf(detail->pos_str);
		data["sys_date"] = detail->sys_date;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["sno"] = detail->sno;
		data["fund_id"] = toUtf(detail->fund_id);
		data["currency_type"] = detail->currency_type;
		data["cust_id"] = toUtf(detail->cust_id);
		data["cust_name"] = toUtf(detail->cust_name);
		data["bank_code"] = toUtf(detail->bank_code);
		data["bank_name"] = toUtf(detail->bank_name);
		data["busi_type"] = detail->busi_type;
		data["fund_effect"] = detail->fund_effect;
		data["fund_bal"] = detail->fund_bal;
		data["remark"] = toUtf(detail->remark);
		data["status"] = detail->status;
		data["source_type"] = detail->source_type;
		data["strike_flag"] = detail->strike_flag;
		data["bank_msg_id"] = toUtf(detail->bank_msg_id);
		data["bank_msg"] = toUtf(detail->bank_msg);
		data["syserr_id"] = detail->syserr_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHisBankSecTransferRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnFundAccountTransferRsp(FundAccountTransferRsp* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onFundAccountTransferRsp(data, error, request_id);
};

void TdApi::OnQueryFundAccountTransferRsp(FundAccountTransferDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["sys_date"] = detail->sys_date;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["bank_name"] = toUtf(detail->bank_name);
		data["digest_id"] = toUtf(detail->digest_id);
		data["currency_type"] = detail->currency_type;
		data["fund_effect"] = detail->fund_effect;
		data["remark"] = toUtf(detail->remark);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryFundAccountTransferRsp(data, error, request_id);
};

void TdApi::OnQueryHisOrderRsp(HisOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["symbol"] = toUtf(detail->symbol);
		data["oper_date"] = detail->oper_date;
		data["order_date"] = detail->order_date;
		data["trd_flow_id"] = toUtf(detail->trd_flow_id);
		data["cust_id"] = toUtf(detail->cust_id);
		data["currency_type"] = detail->currency_type;
		data["secuid"] = toUtf(detail->secuid);
		data["order_side"] = detail->order_side;
		data["order_id"] = toUtf(detail->order_id);
		data["stk_name"] = toUtf(detail->stk_name);
		data["order_price"] = detail->order_price;
		data["order_qty"] = detail->order_qty;
		data["oper_time"] = detail->oper_time;
		data["order_frz_amt"] = detail->order_frz_amt;
		data["match_qty"] = detail->match_qty;
		data["match_price"] = detail->match_price;
		data["match_amt"] = detail->match_amt;
		data["cancel_qty"] = detail->cancel_qty;
		data["order_status"] = detail->order_status;
		data["seat"] = toUtf(detail->seat);
		data["oper_way"] = detail->oper_way;
		data["cancel_flag"] = detail->cancel_flag;
		data["extqty1"] = detail->extqty1;
		data["remark"] = toUtf(detail->remark);
		data["total_num"] = detail->total_num;
		data["order_type"] = detail->order_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHisOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryHisTradeRsp(HisTradeDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["symbol"] = toUtf(detail->symbol);
		data["busi_flow_id"] = toUtf(detail->busi_flow_id);
		data["cust_id"] = toUtf(detail->cust_id);
		data["currency_type"] = detail->currency_type;
		data["secuid"] = toUtf(detail->secuid);
		data["main_seat"] = toUtf(detail->main_seat);
		data["trd_seat"] = toUtf(detail->trd_seat);
		data["stk_property"] = detail->stk_property;
		data["busi_type"] = toUtf(detail->busi_type);
		data["busi_name"] = toUtf(detail->busi_name);
		data["stk_name"] = toUtf(detail->stk_name);
		data["order_date"] = detail->order_date;
		data["apply_code"] = toUtf(detail->apply_code);
		data["match_code"] = toUtf(detail->match_code);
		data["match_time"] = toUtf(detail->match_time);
		data["match_amt"] = detail->match_amt;
		data["match_qty"] = detail->match_qty;
		data["match_price"] = detail->match_price;
		data["order_qty"] = detail->order_qty;
		data["order_price"] = detail->order_price;
		data["intr_amt"] = detail->intr_amt;
		data["stk_type"] = toUtf(detail->stk_type);
		data["order_side"] = detail->order_side;
		data["oper_date"] = detail->oper_date;
		data["match_date"] = detail->match_date;
		data["stk_bal"] = detail->stk_bal;
		data["total_num"] = detail->total_num;
		data["order_type"] = detail->order_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHisTradeRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryDeliveryOrderRsp(DeliveryOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["symbol"] = toUtf(detail->symbol);
		data["biz_date"] = detail->biz_date;
		data["sno"] = toUtf(detail->sno);
		data["busi_type"] = toUtf(detail->busi_type);
		data["busi_name"] = toUtf(detail->busi_name);
		data["currency_type"] = detail->currency_type;
		data["stk_name"] = toUtf(detail->stk_name);
		data["secuid"] = toUtf(detail->secuid);
		data["main_seat"] = toUtf(detail->main_seat);
		data["ta_code"] = toUtf(detail->ta_code);
		data["tran_sacct"] = toUtf(detail->tran_sacct);
		data["ta_acct"] = toUtf(detail->ta_acct);
		data["order_date"] = detail->order_date;
		data["order_time"] = detail->order_time;
		data["order_side"] = detail->order_side;
		data["apply_code"] = toUtf(detail->apply_code);
		data["order_qty"] = detail->order_qty;
		data["order_price"] = detail->order_price;
		data["match_time"] = detail->match_time;
		data["match_qty"] = detail->match_qty;
		data["match_price"] = detail->match_price;
		data["match_amt"] = detail->match_amt;
		data["fun_deffect"] = detail->fun_deffect;
		data["fund_bal"] = detail->fund_bal;
		data["stk_effect"] = detail->stk_effect;
		data["stk_bal"] = detail->stk_bal;
		data["fee_seat"] = detail->fee_seat;
		data["fee_yjf"] = detail->fee_yjf;
		data["fee_yhs"] = detail->fee_yhs;
		data["fee_jsf"] = detail->fee_jsf;
		data["fee_ghf"] = detail->fee_ghf;
		data["fee_zgf"] = detail->fee_zgf;
		data["fee_sxf"] = detail->fee_sxf;
		data["fee_qsf"] = detail->fee_qsf;
		data["fee_jggf"] = detail->fee_jggf;
		data["fee_other"] = detail->fee_other;
		data["fee_jsxf"] = detail->fee_jsxf;
		data["fee_jygf"] = detail->fee_jygf;
		data["fee_front"] = detail->fee_front;
		data["total_num"] = detail->total_num;
		data["clear_exch_rate"] = detail->clear_exch_rate;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryDeliveryOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryStateOrderRsp(StateOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["symbol"] = toUtf(detail->symbol);
		data["biz_date"] = detail->biz_date;
		data["clear_date"] = detail->clear_date;
		data["sno"] = toUtf(detail->sno);
		data["busi_type"] = toUtf(detail->busi_type);
		data["busi_name"] = toUtf(detail->busi_name);
		data["currency_type"] = detail->currency_type;
		data["stk_name"] = toUtf(detail->stk_name);
		data["secuid"] = toUtf(detail->secuid);
		data["main_seat"] = toUtf(detail->main_seat);
		data["ta_code"] = toUtf(detail->ta_code);
		data["trans_acct"] = toUtf(detail->trans_acct);
		data["ta_acct"] = toUtf(detail->ta_acct);
		data["order_date"] = detail->order_date;
		data["order_time"] = detail->order_time;
		data["order_side"] = detail->order_side;
		data["apply_code"] = toUtf(detail->apply_code);
		data["order_qty"] = detail->order_qty;
		data["order_price"] = detail->order_price;
		data["match_time"] = detail->match_time;
		data["match_qty"] = detail->match_qty;
		data["match_price"] = detail->match_price;
		data["match_amt"] = detail->match_amt;
		data["fund_effect"] = detail->fund_effect;
		data["fund_bal"] = detail->fund_bal;
		data["stkeff_ect"] = detail->stkeff_ect;
		data["stk_bal"] = detail->stk_bal;
		data["total_num"] = detail->total_num;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryStateOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryExchangeListsRsp(ExchangeDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["pos_str"] = toUtf(detail->pos_str);
		data["clear_date"] = detail->clear_date;
		data["biz_date"] = detail->biz_date;
		data["order_date"] = detail->order_date;
		data["order_time"] = detail->order_time;
		data["digest_id"] = detail->digest_id;
		data["digest_name"] = toUtf(detail->digest_name);
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["secuid"] = toUtf(detail->secuid);
		data["cust_name"] = toUtf(detail->cust_name);
		data["order_id"] = toUtf(detail->order_id);
		data["sno"] = toUtf(detail->sno);
		data["stk_name"] = toUtf(detail->stk_name);
		data["order_side"] = detail->order_side;
		data["match_time"] = detail->match_time;
		data["match_code"] = toUtf(detail->match_code);
		data["match_times"] = detail->match_times;
		data["match_qty"] = detail->match_qty;
		data["match_price"] = detail->match_price;
		data["match_amt"] = detail->match_amt;
		data["clear_amt"] = detail->clear_amt;
		data["fee_yhs"] = detail->fee_yhs;
		data["fee_jsxf"] = detail->fee_jsxf;
		data["fee_sxf"] = detail->fee_sxf;
		data["fee_ghf"] = detail->fee_ghf;
		data["fee_qsf"] = detail->fee_qsf;
		data["fee_jygf"] = detail->fee_jygf;
		data["fee_front"] = detail->fee_front;
		data["fee_jsf"] = detail->fee_jsf;
		data["fee_zgf"] = detail->fee_zgf;
		data["fee_other"] = detail->fee_other;
		data["fund_bal"] = detail->fund_bal;
		data["stk_bal"] = detail->stk_bal;
		data["order_qty"] = detail->order_qty;
		data["order_price"] = detail->order_price;
		data["source_type"] = detail->source_type;
		data["bank_code"] = toUtf(detail->bank_code);
		data["bank_id"] = toUtf(detail->bank_id);
		data["counter_order_id"] = toUtf(detail->counter_order_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryExchangeListsRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnModifyPasswordRsp(ModifyPasswordRsp* rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(rsp->account_id);
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = toUtf(rsp->cust_orgid);
		data["cust_branchid"] = toUtf(rsp->cust_branchid);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onModifyPasswordRsp(data, error, request_id);
};

void TdApi::OnQueryPHXXRsp(QueryPHXXRecord* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["busi_date"] = detail->busi_date;
		data["market"] = toUtf(detail->market);
		data["secuid"] = toUtf(detail->secuid);
		data["stk_name"] = toUtf(detail->stk_name);
		data["stk_code"] = toUtf(detail->stk_code);
		data["match_qty"] = detail->match_qty;
		data["mate_no"] = toUtf(detail->mate_no);
		data["currency_type"] = detail->currency_type;
		data["busi_type"] = toUtf(detail->busi_type);
		data["link_stk_code"] = toUtf(detail->link_stk_code);
		data["next_query_index"] = detail->next_query_index;
		data["total_num"] = detail->total_num;
		data["issue_stk_type"] = detail->issue_stk_type;
		data["order_date"] = detail->order_date;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPHXXRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryZQXXRsp(QueryZQXXRecord* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["busi_date"] = detail->busi_date;
		data["market"] = toUtf(detail->market);
		data["secuid"] = toUtf(detail->secuid);
		data["stk_name"] = toUtf(detail->stk_name);
		data["stk_code"] = toUtf(detail->stk_code);
		data["stk_type"] = toUtf(detail->stk_type);
		data["hit_qty"] = detail->hit_qty;
		data["match_price"] = detail->match_price;
		data["order_date"] = detail->order_date;
		data["order_id"] = toUtf(detail->order_id);
		data["mate_no"] = toUtf(detail->mate_no);
		data["currency_type"] = detail->currency_type;
		data["busi_type"] = toUtf(detail->busi_type);
		data["next_query_index"] = detail->next_query_index;
		data["total_num"] = detail->total_num;
		data["issue_stk_type"] = detail->issue_stk_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryZQXXRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryLockSecurityContractRsp(LockSecurityContractDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["sys_date"] = detail->sys_date;
		data["begin_date"] = detail->begin_date;
		data["close_date"] = detail->close_date;
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["status"] = detail->status;
		data["secuid"] = toUtf(detail->secuid);
		data["lock_charge_type"] = detail->lock_charge_type;
		data["first_in_mode"] = detail->first_in_mode;
		data["reserve_qty"] = detail->reserve_qty;
		data["stk_bal"] = detail->stk_bal;
		data["stk_avl"] = detail->stk_avl;
		data["stk_used_qty"] = detail->stk_used_qty;
		data["stk_sale"] = detail->stk_sale;
		data["stk_sale_frz"] = detail->stk_sale_frz;
		data["stk_repay"] = detail->stk_repay;
		data["used_fee_rate"] = detail->used_fee_rate;
		data["used_fee"] = detail->used_fee;
		data["unused_fee_rate"] = detail->unused_fee_rate;
		data["unused_fee"] = detail->unused_fee;
		data["over_used_fee"] = detail->over_used_fee;
		data["over_unused_fee"] = detail->over_unused_fee;
		data["puni_used_fee"] = detail->puni_used_fee;
		data["puni_unused_fee"] = detail->puni_unused_fee;
		data["violate_fee_rate"] = detail->violate_fee_rate;
		data["violate_fee"] = detail->violate_fee;
		data["over_violate_fee"] = detail->over_violate_fee;
		data["puni_violate_fee"] = detail->puni_violate_fee;
		data["cust_id"] = toUtf(detail->cust_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryLockSecurityContractRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditContractRsp(CreditContractDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["f_credit_rate"] = detail->f_credit_rate;
		data["f_year_mg_fee"] = detail->f_year_mg_fee;
		data["f_year_sr_fee"] = detail->f_year_sr_fee;
		data["d_credit_rate"] = detail->d_credit_rate;
		data["d_year_mg_fee"] = detail->d_year_mg_fee;
		data["d_year_sr_fee"] = detail->d_year_sr_fee;
		data["cancel_date"] = detail->cancel_date;
		data["currency_type"] = detail->currency_type;
		data["contract_limit"] = detail->contract_limit;
		data["contract_status"] = detail->contract_status;
		data["begin_date"] = detail->begin_date;
		data["end_date"] = detail->end_date;
		data["f_prate"] = detail->f_prate;
		data["d_prate"] = detail->d_prate;
		data["contract_id"] = toUtf(detail->contract_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditContractRsp(data, error, request_id);
};

void TdApi::OnQueryCreditDebtsCollectRsp(CreditDebtsCollectDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["match_amt"] = detail->match_amt;
		data["match_qty"] = detail->match_qty;
		data["credit_repay"] = detail->credit_repay;
		data["stk_repay"] = detail->stk_repay;
		data["credit_repay_unfrz"] = detail->credit_repay_unfrz;
		data["stk_repay_unfrz"] = detail->stk_repay_unfrz;
		data["credit_bal"] = detail->credit_bal;
		data["stk_bal"] = detail->stk_bal;
		data["last_price"] = detail->last_price;
		data["market_value"] = detail->market_value;
		data["credit_avl"] = detail->credit_avl;
		data["debts_profit"] = detail->debts_profit;
		data["adjust_profit"] = detail->adjust_profit;
		data["credit_fee"] = detail->credit_fee;
		data["stk_debts_avl"] = detail->stk_debts_avl;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditDebtsCollectRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryCreditDataRsp(CreditDataDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["credit_direct"] = detail->credit_direct;
		data["margin_avl"] = detail->margin_avl;
		data["credit_bal"] = detail->credit_bal;
		data["credit_avl"] = detail->credit_avl;
		data["margin_rate"] = detail->margin_rate;
		data["debts_bal"] = detail->debts_bal;
		data["max_amt"] = detail->max_amt;
		data["fund_avl"] = detail->fund_avl;
		data["credit_fund_avl"] = detail->credit_fund_avl;
		data["g_dis_market_avl"] = detail->g_dis_market_avl;
		data["mar_stk_val"] = detail->mar_stk_val;
		data["total_dis_f_mk_val"] = detail->total_dis_f_mk_val;
		data["mar_fund_profit"] = detail->mar_fund_profit;
		data["mar_stk_profit"] = detail->mar_stk_profit;
		data["total_rate_f_debts_bal"] = detail->total_rate_f_debts_bal;
		data["mar_fund_margin"] = detail->mar_fund_margin;
		data["mar_fund_margin_frz"] = detail->mar_fund_margin_frz;
		data["total_rate_d_sale_bal"] = detail->total_rate_d_sale_bal;
		data["mar_stk_margin"] = detail->mar_stk_margin;
		data["mar_stk_margin_frz"] = detail->mar_stk_margin_frz;
		data["total_fee"] = detail->total_fee;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditDataRsp(data, error, request_id);
};

void TdApi::OnQueryPreMaturityDebtsRsp(PreMaturityDebtsDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["secuid"] = toUtf(detail->secuid);
		data["currency_type"] = detail->currency_type;
		data["credit_direct"] = detail->credit_direct;
		data["life_status"] = detail->life_status;
		data["sys_date"] = detail->sys_date;
		data["sno"] = toUtf(detail->sno);
		data["order_id"] = toUtf(detail->order_id);
		data["order_date"] = detail->order_date;
		data["match_qty"] = detail->match_qty;
		data["match_amt"] = detail->match_amt;
		data["leave_amt"] = detail->leave_amt;
		data["leave_qty"] = detail->leave_qty;
		data["all_fee"] = detail->all_fee;
		data["apply_status"] = detail->apply_status;
		data["apply_date"] = detail->apply_date;
		data["apply_sno"] = toUtf(detail->apply_sno);
		data["apply_end_date"] = detail->apply_end_date;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["chk_remark"] = toUtf(detail->chk_remark);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPreMaturityDebtsRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnExtendPreMaturityDebtsRsp(ExtendPreMaturityDebtsRsp* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["apply_date"] = detail->apply_date;
		data["apply_sno"] = toUtf(detail->apply_sno);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onExtendPreMaturityDebtsRsp(data, error, request_id);
};

void TdApi::OnQueryPreMaturityDebtsExtensionRsp(PreMaturityDebtsExtensionDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["secuid"] = toUtf(detail->secuid);
		data["currency_type"] = detail->currency_type;
		data["credit_direct"] = detail->credit_direct;
		data["life_status"] = detail->life_status;
		data["apply_status"] = detail->apply_status;
		data["sys_date"] = detail->sys_date;
		data["apply_date"] = detail->apply_date;
		data["apply_sno"] = toUtf(detail->apply_sno);
		data["sno"] = toUtf(detail->sno);
		data["order_date"] = detail->order_date;
		data["order_id"] = toUtf(detail->order_id);
		data["match_qty"] = detail->match_qty;
		data["match_amt"] = detail->match_amt;
		data["leave_amt"] = detail->leave_amt;
		data["leave_value"] = detail->leave_value;
		data["chk_remark"] = toUtf(detail->chk_remark);
		data["cfm_ans"] = toUtf(detail->cfm_ans);
		data["leave_qty"] = detail->leave_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPreMaturityDebtsExtensionRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryVoteProposalRsp(VoteProposalDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["vote_symbol"] = toUtf(detail->vote_symbol);
		data["vote_name"] = toUtf(detail->vote_name);
		data["begin_date"] = detail->begin_date;
		data["end_date"] = detail->end_date;
		data["meeting_type"] = toUtf(detail->meeting_type);
		data["meeting_desc"] = toUtf(detail->meeting_desc);
		data["meeting_seq"] = toUtf(detail->meeting_seq);
		data["voting_proposal_code"] = toUtf(detail->voting_proposal_code);
		data["voting_prososal_desc"] = toUtf(detail->voting_prososal_desc);
		data["voting_proposal_type"] = detail->voting_proposal_type;
		data["cum_voting_chosen_num"] = detail->cum_voting_chosen_num;
		data["share_holder_role"] = toUtf(detail->share_holder_role);
		data["proposal_relation"] = toUtf(detail->proposal_relation);
		data["share_class"] = toUtf(detail->share_class);
		data["reg_date"] = detail->reg_date;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryVoteProposalRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryCreditVoteCountRsp(CreditVoteCountDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["voting_proposal"] = toUtf(detail->voting_proposal);
		data["rest_qty"] = detail->rest_qty;
		data["stk_name"] = toUtf(detail->stk_name);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditVoteCountRsp(data, error, request_id);
};

void TdApi::OnQueryCreditVoteRsp(CreditVoteDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["symbol"] = toUtf(detail->symbol);
		data["secuid"] = toUtf(detail->secuid);
		data["sys_date"] = detail->sys_date;
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["link_symbol"] = toUtf(detail->link_symbol);
		data["voting_proposal"] = toUtf(detail->voting_proposal);
		data["voting_preference"] = detail->voting_preference;
		data["stk_bal"] = detail->stk_bal;
		data["stk_name"] = toUtf(detail->stk_name);
		data["link_stk_name"] = toUtf(detail->link_stk_name);
		data["meeting_seq"] = toUtf(detail->meeting_seq);
		data["meeting_desc"] = toUtf(detail->meeting_desc);
		data["voting_proposal_type"] = detail->voting_proposal_type;
		data["voting_prososal_desc"] = toUtf(detail->voting_prososal_desc);
		data["key_error_code"] = toUtf(detail->key_error_code);
		data["key_error_msg"] = toUtf(detail->key_error_msg);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCreditVoteRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryNetVoteRightsRsp(NetVoteRightsDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["cust_id"] = toUtf(detail->cust_id);
		data["secuid"] = toUtf(detail->secuid);
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["meeting_seq"] = toUtf(detail->meeting_seq);
		data["reg_date"] = detail->reg_date;
		data["voting_proposal"] = toUtf(detail->voting_proposal);
		data["voting_relation"] = toUtf(detail->voting_relation);
		data["total_num"] = detail->total_num;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryNetVoteRightsRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryNetVoteResultRsp(NetVoteResultDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["busi_date"] = detail->busi_date;
		data["contract_id"] = toUtf(detail->contract_id);
		data["vote_symbol"] = toUtf(detail->vote_symbol);
		data["meeting_seq"] = toUtf(detail->meeting_seq);
		data["cust_id"] = toUtf(detail->cust_id);
		data["fund_id"] = toUtf(detail->fund_id);
		data["secuid"] = toUtf(detail->secuid);
		data["vote_qty"] = detail->vote_qty;
		data["cur_vote_qty"] = detail->cur_vote_qty;
		data["voting_proposal"] = toUtf(detail->voting_proposal);
		data["vote_info"] = toUtf(detail->vote_info);
		data["vote_type"] = detail->vote_type;
		data["total_num"] = detail->total_num;
		data["vote_name"] = toUtf(detail->vote_name);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryNetVoteResultRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryNetVoteCountRsp(NetVoteCountDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["vote_qty"] = detail->vote_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryNetVoteCountRsp(data, error, request_id, is_last);
};

void TdApi::OnQueryStkConcentrationRsp(StkConcentrationDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["market_id"] = detail->market_id;
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["keep_rate_begin"] = detail->keep_rate_begin;
		data["keep_rate_end"] = detail->keep_rate_end;
		data["debt_begin"] = detail->debt_begin;
		data["debt_end"] = detail->debt_end;
		data["ctrl_rate"] = detail->ctrl_rate;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryStkConcentrationRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryHKHisOrderRsp(HKHisOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["sys_date"] = detail->sys_date;
		data["trd_flow_id"] = toUtf(detail->trd_flow_id);
		data["order_id"] = toUtf(detail->order_id);
		data["order_status"] = detail->order_status;
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["secuid"] = toUtf(detail->secuid);
		data["order_qty"] = detail->order_qty;
		data["order_price"] = detail->order_price;
		data["order_frz_amt"] = detail->order_frz_amt;
		data["trade_fee"] = detail->trade_fee;
		data["settle_fee"] = detail->settle_fee;
		data["net_price"] = detail->net_price;
		data["return_rate"] = detail->return_rate;
		data["total_bond_intr"] = detail->total_bond_intr;
		data["settle_days"] = detail->settle_days;
		data["end_order_date"] = detail->end_order_date;
		data["settle_date"] = detail->settle_date;
		data["settle_mode"] = detail->settle_mode;
		data["price_type"] = detail->price_type;
		data["match_type"] = detail->match_type;
		data["stk_name"] = toUtf(detail->stk_name);
		data["oper_date"] = detail->oper_date;
		data["oper_time"] = detail->oper_time;
		data["match_price"] = detail->match_price;
		data["match_qty"] = detail->match_qty;
		data["cancel_qty"] = detail->cancel_qty;
		data["order_side"] = detail->order_side;
		data["contract_sno"] = toUtf(detail->contract_sno);
		data["refer_rate"] = detail->refer_rate;
		data["pos_str"] = toUtf(detail->pos_str);
		data["total_num"] = detail->total_num;
		data["main_seat"] = toUtf(detail->main_seat);
		data["match_amt"] = detail->match_amt;
		data["remark"] = toUtf(detail->remark);
		data["report_time"] = detail->report_time;
		data["cust_id"] = toUtf(detail->cust_id);
		data["cust_name"] = toUtf(detail->cust_name);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryHKHisOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryWithdrawCashRsp(WithdrawCashRecord* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["currency_type"] = detail->currency_type;
		data["total_asset"] = detail->total_asset;
		data["fund_bal"] = detail->fund_bal;
		data["fund_avl"] = detail->fund_avl;
		data["fetch_bal"] = detail->fetch_bal;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryWithdrawCashRsp(data, error, request_id);
};

void TdApi::OnQueryNetVoteOrderRsp(NetVoteOrderDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["order_id"] = detail->order_id;
		data["order_group"] = detail->order_group;
		data["contract_id"] = toUtf(detail->contract_id);
		data["order_date"] = detail->order_date;
		data["cust_id"] = toUtf(detail->cust_id);
		data["cust_name"] = toUtf(detail->cust_name);
		data["currency_type"] = detail->currency_type;
		data["symbol"] = toUtf(detail->symbol);
		data["name"] = toUtf(detail->name);
		data["seat"] = toUtf(detail->seat);
		data["stktype"] = detail->stktype;
		data["side"] = detail->side;
		data["meeting_seq"] = toUtf(detail->meeting_seq);
		data["voting_proposal_code"] = toUtf(detail->voting_proposal_code);
		data["voting_preference"] = detail->voting_preference;
		data["voting_segment"] = toUtf(detail->voting_segment);
		data["total_qty"] = detail->total_qty;
		data["counter_order_time"] = detail->counter_order_time;
		data["order_status"] = detail->order_status;
		data["secuid"] = toUtf(detail->secuid);
		data["remark"] = toUtf(detail->remark);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryNetVoteOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryTradeTotalRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(trade_detail->account_id);
		data["account_type"] = trade_detail->account_type;
		data["cust_orgid"] = toUtf(trade_detail->cust_orgid);
		data["cust_branchid"] = toUtf(trade_detail->cust_branchid);
		data["order_id"] = toUtf(trade_detail->order_id);
		data["cl_order_id"] = toUtf(trade_detail->cl_order_id);
		data["symbol"] = toUtf(trade_detail->symbol);
		data["order_type"] = trade_detail->order_type;
		data["side"] = trade_detail->side;
		data["report_type"] = trade_detail->report_type;
		data["report_no"] = toUtf(trade_detail->report_no);
		data["volume"] = trade_detail->volume;
		data["price"] = trade_detail->price;
		data["turnover"] = trade_detail->turnover;
		data["trade_date"] = trade_detail->trade_date;
		data["trade_time"] = trade_detail->trade_time;
		data["err_code"] = trade_detail->err_code;
		data["err_msg"] = toUtf(trade_detail->err_msg);
		data["secuid"] = toUtf(trade_detail->secuid);
		data["name"] = toUtf(trade_detail->name);
		data["contract_id"] = toUtf(trade_detail->contract_id);
		data["ex_report_no"] = toUtf(trade_detail->ex_report_no);
		data["ex_order_id"] = toUtf(trade_detail->ex_order_id);
		data["margin_amt_type"] = trade_detail->margin_amt_type;
		data["order_price"] = trade_detail->order_price;
		data["order_qty"] = trade_detail->order_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryTradeTotalRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnETFSubscriptCancelRsp(ETFSubscriptCancelRsp* order_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["order_date"] = order_rsp->order_date;
		data["order_id"] = toUtf(order_rsp->order_id);
		data["cl_order_id"] = toUtf(order_rsp->cl_order_id);
		data["cl_cancel_id"] = toUtf(order_rsp->cl_cancel_id);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onETFSubscriptCancelRsp(data, error, request_id);
};

void TdApi::OnNetVoteOrderRsp(NetVoteOrderRsp* order_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["contract_id"] = toUtf(order_rsp->contract_id);
		data["order_sno"] = order_rsp->order_sno;
		data["order_status"] = order_rsp->order_status;
		data["report_time"] = order_rsp->report_time;
		data["cust_id"] = toUtf(order_rsp->cust_id);
		data["secuid"] = toUtf(order_rsp->secuid);
		data["symbol"] = toUtf(order_rsp->symbol);
		data["reject_code"] = toUtf(order_rsp->reject_code);
		data["reject_msg"] = toUtf(order_rsp->reject_msg);
		data["order_group"] = order_rsp->order_group;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onNetVoteOrderRsp(data, error, request_id);
};

void TdApi::OnCreditNetVoteOrderRsp(CreditNetVoteOrderRsp* order_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["reject_code"] = toUtf(order_rsp->reject_code);
		data["reject_msg"] = toUtf(order_rsp->reject_msg);
		data["level"] = toUtf(order_rsp->level);
		data["cust_id"] = toUtf(order_rsp->cust_id);
		data["secuid"] = toUtf(order_rsp->secuid);
		data["symbol"] = toUtf(order_rsp->symbol);
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCreditNetVoteOrderRsp(data, error, request_id);
};

void TdApi::OnQueryMSCashRsp(MSCashDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["pos_str"] = toUtf(detail->pos_str);
		data["busidate"] = detail->busidate;
		data["custid"] = toUtf(detail->custid);
		data["fundunit"] = toUtf(detail->fundunit);
		data["currency_type"] = detail->currency_type;
		data["subjectcode"] = toUtf(detail->subjectcode);
		data["settbody"] = toUtf(detail->settbody);
		data["orgid"] = toUtf(detail->orgid);
		data["brhid"] = toUtf(detail->brhid);
		data["trdsysid"] = toUtf(detail->trdsysid);
		data["coreid"] = toUtf(detail->coreid);
		data["fundid"] = toUtf(detail->fundid);
		data["subjectname"] = toUtf(detail->subjectname);
		data["startbal"] = detail->startbal;
		data["endbal"] = detail->endbal;
		data["fundrealcommit"] = detail->fundrealcommit;
		data["awardamt"] = detail->awardamt;
		data["punishamt"] = detail->punishamt;
		data["totalnum"] = detail->totalnum;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryMSCashRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryMSPositionsRsp(MSPositionsDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["pos_str"] = toUtf(detail->pos_str);
		data["busidate"] = detail->busidate;
		data["custid"] = toUtf(detail->custid);
		data["fundunit"] = toUtf(detail->fundunit);
		data["stkholdunit"] = toUtf(detail->stkholdunit);
		data["secuid"] = toUtf(detail->secuid);
		data["mainseat"] = toUtf(detail->mainseat);
		data["symbol"] = toUtf(detail->symbol);
		data["direction"] = detail->direction;
		data["investtype"] = detail->investtype;
		data["stkid"] = toUtf(detail->stkid);
		data["stkproperty"] = detail->stkproperty;
		data["subjectcode"] = toUtf(detail->subjectcode);
		data["settbody"] = toUtf(detail->settbody);
		data["trdsysid"] = toUtf(detail->trdsysid);
		data["coreid"] = toUtf(detail->coreid);
		data["currency_type"] = detail->currency_type;
		data["schemeid"] = toUtf(detail->schemeid);
		data["subjectname"] = toUtf(detail->subjectname);
		data["startbal"] = detail->startbal;
		data["endbal"] = detail->endbal;
		data["startcost"] = detail->startcost;
		data["endcost"] = detail->endcost;
		data["startcostwithfee"] = detail->startcostwithfee;
		data["endcostwithfee"] = detail->endcostwithfee;
		data["starttradefee"] = detail->starttradefee;
		data["endtradefee"] = detail->endtradefee;
		data["startprofit"] = detail->startprofit;
		data["endprofit"] = detail->endprofit;
		data["startprofitwithfee"] = detail->startprofitwithfee;
		data["endprofitwithfee"] = detail->endprofitwithfee;
		data["startintrcost"] = detail->startintrcost;
		data["endintrcost"] = detail->endintrcost;
		data["startintrprofit"] = detail->startintrprofit;
		data["endintrprofit"] = detail->endintrprofit;
		data["tacode"] = toUtf(detail->tacode);
		data["transacct"] = toUtf(detail->transacct);
		data["taacct"] = toUtf(detail->taacct);
		data["linkstkid"] = toUtf(detail->linkstkid);
		data["extint"] = detail->extint;
		data["extamt"] = detail->extamt;
		data["extchar"] = toUtf(detail->extchar);
		data["extstr"] = toUtf(detail->extstr);
		data["totalnum"] = detail->totalnum;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryMSPositionsRsp(data, error, request_id, is_last, string(pos_str));
};

void TdApi::OnQueryMSCreditDebtsFlowRsp(MSCreditDebtsFlowDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["account_type"] = detail->account_type;
		data["pos_str"] = toUtf(detail->pos_str);
		data["busidate"] = detail->busidate;
		data["operdate"] = detail->operdate;
		data["sysdate"] = detail->sysdate;
		data["logno"] = toUtf(detail->logno);
		data["custid"] = toUtf(detail->custid);
		data["creditdebtstype"] = detail->creditdebtstype;
		data["lifekind"] = detail->lifekind;
		data["direct"] = detail->direct;
		data["paykind"] = detail->paykind;
		data["fundeffect"] = detail->fundeffect;
		data["fundbal"] = detail->fundbal;
		data["stkeffect"] = detail->stkeffect;
		data["stkbal"] = detail->stkbal;
		data["reladate"] = detail->reladate;
		data["relasno"] = toUtf(detail->relasno);
		data["symbol"] = toUtf(detail->symbol);
		data["remark"] = toUtf(detail->remark);
		data["bizdate"] = detail->bizdate;
		data["logassetsno"] = toUtf(detail->logassetsno);
		data["totalnum"] = detail->totalnum;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryMSCreditDebtsFlowRsp(data, error, request_id, is_last, string(pos_str));
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::setLogConfig(string log_path)
{
	this->api->SetLogConfig(log_path.c_str(), LogLevel_Info);
}

void TdApi::createTraderApi()
{
    this->api = TraderApi::CreateTraderApi();
    this->api->RegisterSpi(this);
	this->active = true;
};

void TdApi::release()
{
    this->api->Release();
};


int TdApi::exit()
{
    this->api->Release();
    this->api = NULL;
    return 1;
};

string TdApi::getApiVersion()
{
	string i = this->api->GetApiVersion();
	return i;
}

void TdApi::setCriticalMsgLog(bool enable)
{
	this->api->SetCriticalMsgLog(enable);
};

void TdApi::setLoginRetryCount(int login_retry_count)
{
	this->api->SetLoginRetryCount(login_retry_count);
};

void TdApi::setLoginRetryInterval(int login_retry_interval)
{
	this->api->SetLoginRetryInterval(login_retry_interval);
};

void TdApi::setReconnectConfig(int max_retry_count, int min_interval, int max_interval)
{
	this->api->SetReconnectConfig(max_retry_count, min_interval, max_interval);

};

dict TdApi::getApiLastError()
{
	ErrorInfo* d = this->api->GetApiLastError();

	dict data;
	data["err_code"] = d->err_code;
	data["err_msg"] = toUtf(d->err_msg);
	return data;
};

int TdApi::getCounterType()
{
	int i = this->api->GetCounterType();
    return i;
};

int TdApi::login(string svr_ip, int svr_port, const dict& req, string terminal_info)
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

int TdApi::getSecuidInfo(const dict& req, int count)
{
	SecuidInfo myreq = SecuidInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "fund_id", myreq.fund_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getChar(req, "account_status", &myreq.account_status);
	getChar(req, "account_class", &myreq.account_class);
	int i = this->api->GetSecuidInfo(&myreq, &count);
	return i;
};

int TdApi::getAllSecuidInfo(const dict& req, int count)
{
	SecuidInfo myreq = SecuidInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getString(req, "secuid", myreq.secuid);
	getString(req, "fund_id", myreq.fund_id);
	getInt16_t(req, "account_type", &myreq.account_type);
	getChar(req, "account_status", &myreq.account_status);
	getChar(req, "account_class", &myreq.account_class);
	int i = this->api->GetAllSecuidInfo(&myreq, &count);
	return i;
};

int TdApi::getApiLocalAddr(const dict& req)
{
	IpAddr myreq = IpAddr();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ip", myreq.ip);
	getInt(req, "port", &myreq.port);
	int i = this->api->GetApiLocalAddr(&myreq);
	return i;
};

int TdApi::order(const dict& req, int request_id)
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

int TdApi::batchOrder(const dict& req, int count, int request_id)
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

int TdApi::cancelOrder(const dict& req, int request_id)
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

int TdApi::batchCancelOrder(const dict& req, int count, int request_id)
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

int TdApi::batchCancelAllOrder(const dict& req, int request_id)
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

int TdApi::queryOrder(const dict& req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryOrder(&myreq, request_id);
	return i;
};

int TdApi::queryOrderByCode(const dict& req, int request_id)
{
	QryOrderByCodeReq myreq = QryOrderByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOrderByCode(&myreq, request_id);
	return i;
};

int TdApi::queryOrders(const dict& req, int request_id)
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

int TdApi::queryTradeByOrderId(const dict& req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryTradeByOrderId(&myreq, request_id);
	return i;
};

int TdApi::queryTradeByCode(const dict& req, int request_id)
{
	QryTradeByCodeReq myreq = QryTradeByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryTradeByCode(&myreq, request_id);
	return i;
};

int TdApi::queryTrades(const dict& req, int request_id)
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

int TdApi::queryETFTrades(const dict& req, int request_id)
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

int TdApi::queryPosition(const dict& req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPosition(&myreq, request_id);
	return i;
};

int TdApi::queryPositions(const dict& req, int request_id)
{
	QryPositionsReq myreq = QryPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	int i = this->api->QueryPositions(&myreq, request_id);
	return i;
};

int TdApi::queryCash(const dict& req, int request_id)
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

int TdApi::transferFundInAndOut(const dict& req, int request_id)
{
	TransferFundReq myreq = TransferFundReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "transfer_side", &myreq.transfer_side);
	getLonglong(req, "transfer_value", &myreq.transfer_value);
	getString(req, "market", myreq.market);
	int i = this->api->TransferFundInAndOut(&myreq, request_id);
	return i;
};

int TdApi::transferFundBetweenSecuid(const dict& req, int request_id)
{
	TransferFundSecuidReq myreq = TransferFundSecuidReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "fund_out_market", myreq.fund_out_market);
	getString(req, "fund_in_market", myreq.fund_in_market);
	getLonglong(req, "transfer_value", &myreq.transfer_value);
	int i = this->api->TransferFundBetweenSecuid(&myreq, request_id);
	return i;
};

int TdApi::queryETFs(const dict& req, int request_id)
{
	QryETFsReq myreq = QryETFsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryETFs(&myreq, request_id);
	return i;
};

int TdApi::queryETFStocks(const dict& req, int request_id)
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

int TdApi::queryMaxOrderQty(const dict& req, int request_id)
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

int TdApi::queryIPOStock(const dict& req, int request_id)
{
	QueryIPOStockReq myreq = QueryIPOStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt16_t(req, "query_flag", &myreq.query_flag);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryIPOStock(&myreq, request_id);
	return i;
};

int TdApi::querySecurityBaseInfo(const dict& req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QuerySecurityBaseInfo(&myreq, request_id);
	return i;
};

int TdApi::creditMortgageInOut(const dict& req, int request_id)
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

int TdApi::creditStockBack(const dict& req, int request_id)
{
	CreditStockBackReq myreq = CreditStockBackReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "symbol", myreq.symbol);
	getInt32_t(req, "volume", &myreq.volume);
	int i = this->api->CreditStockBack(&myreq, request_id);
	return i;
};

int TdApi::creditPayBack(const dict& req, int request_id)
{
	CreditPayBackReq myreq = CreditPayBackReq();
	memset(&myreq, 0, sizeof(myreq));
	getLonglong(req, "back_amt", &myreq.back_amt);
	getString(req, "cl_order_id", myreq.cl_order_id);
	int i = this->api->CreditPayBack(&myreq, request_id);
	return i;
};

int TdApi::creditPayBackByOrder(const dict& req, int request_id)
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

int TdApi::queryCreditStock(const dict& req, int request_id)
{
	QryCreditStockReq myreq = QryCreditStockReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditStock(&myreq, request_id);
	return i;
};

int TdApi::queryCreditMortgageHold(const dict& req, int request_id)
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

int TdApi::queryCreditFinance(const dict& req, int request_id)
{
	QryCreditFinanceReq myreq = QryCreditFinanceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditFinance(&myreq, request_id);
	return i;
};

int TdApi::queryCreditShortsell(const dict& req, int request_id)
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

int TdApi::queryCreditRepayStock(const dict& req, int request_id)
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

int TdApi::queryCreditSecuritySellQty(const dict& req, int request_id)
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

int TdApi::querySecuidRight(const dict& req, int request_id)
{
	QrySecuidRightReq myreq = QrySecuidRightReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getInt16_t(req, "secuid_right", &myreq.secuid_right);
	int i = this->api->QuerySecuidRight(&myreq, request_id);
	return i;
};

int TdApi::queryHKRate(const dict& req, int request_id)
{
	QryByMarketReq myreq = QryByMarketReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryHKRate(&myreq, request_id);
	return i;
};

int TdApi::queryHKStock(const dict& req, int request_id)
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

int TdApi::queryHKMinPriceUnit(const dict& req, int request_id)
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

int TdApi::queryHKTradeCalendar(const dict& req, int request_id)
{
	QryByDateReq myreq = QryByDateReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "start_date", &myreq.start_date);
	getInt(req, "end_date", &myreq.end_date);
	int i = this->api->QueryHKTradeCalendar(&myreq, request_id);
	return i;
};

int TdApi::queryLockSecurityDetail(const dict& req, int request_id)
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

int TdApi::extendLockSecurity(const dict& req, int request_id)
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

int TdApi::queryLockSecurityExtension(const dict& req, int request_id)
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

int TdApi::queryCreditDebtsFlow(const dict& req, int request_id)
{
	QryCreditDebtsFlowReq myreq = QryCreditDebtsFlowReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getInt16_t(req, "currency_type", &myreq.currency_type);
	int i = this->api->QueryCreditDebtsFlow(&myreq, request_id);
	return i;
};

int TdApi::queryCreditAssetFlow(const dict& req, int request_id)
{
	QryCreditAssetFlowReq myreq = QryCreditAssetFlowReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryCreditAssetFlow(&myreq, request_id);
	return i;
};

int TdApi::queryCreditDebts(const dict& req, int request_id)
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

int TdApi::doMicroServiceReq(const dict& req, int request_id)
{
	MicroServiceReq myreq = MicroServiceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "function_id", myreq.function_id);
	getString(req, "tar_sys", myreq.tar_sys);
	getChar(req, "request_content", myreq.request_content);
	getInt32_t(req, "request_len", &myreq.request_len);
	int i = this->api->DoMicroServiceReq(&myreq, request_id);
	return i;
};

int TdApi::queryBankBalance(const dict& req, int request_id)
{
	BankBalanceReq myreq = BankBalanceReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getString(req, "bank_code", myreq.bank_code);
	int i = this->api->QueryBankBalance(&myreq, request_id);
	return i;
};

int TdApi::queryBankInfo(const dict& req, int request_id)
{
	QueryBankInfoReq myreq = QueryBankInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	int i = this->api->QueryBankInfo(&myreq, request_id);
	return i;
};

int TdApi::bankSecTransfer(const dict& req, int request_id)
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

int TdApi::queryBankSecTransfer(const dict& req, int request_id)
{
	QryBankSecTransferReq myreq = QryBankSecTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "currency_type", &myreq.currency_type);
	getLonglong(req, "sno", &myreq.sno);
	int i = this->api->QueryBankSecTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryHisBankSecTransfer(const dict& req, int request_id)
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

int TdApi::fundAccountTransfer(const dict& req, int request_id)
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

int TdApi::queryFundAccountTransfer(const dict& req, int request_id)
{
	QryFundAccountTransferReq myreq = QryFundAccountTransferReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "brh_id", myreq.brh_id);
	getString(req, "fund_id", myreq.fund_id);
	int i = this->api->QueryFundAccountTransfer(&myreq, request_id);
	return i;
};

int TdApi::queryHisOrders(const dict& req, int request_id)
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

int TdApi::queryHisTrades(const dict& req, int request_id)
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

int TdApi::queryDeliveryOrders(const dict& req, int request_id)
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

int TdApi::queryStateOrders(const dict& req, int request_id)
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

int TdApi::queryExchangeLists(const dict& req, int request_id)
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

int TdApi::modifyPassword(const dict& req, int request_id)
{
	ModifyPasswordReq myreq = ModifyPasswordReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "old_password", myreq.old_password);
	getString(req, "new_password", myreq.new_password);
	getInt16_t(req, "password_type", &myreq.password_type);
	int i = this->api->ModifyPassword(&myreq, request_id);
	return i;
};

int TdApi::queryPHXX(const dict& req, int request_id)
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

int TdApi::queryZQXX(const dict& req, int request_id)
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

int TdApi::queryLockSecurityContract(const dict& req, int request_id)
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

int TdApi::queryCreditDebtsCollect(const dict& req, int request_id)
{
	QryCreditDebtsCollectReq myreq = QryCreditDebtsCollectReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryCreditDebtsCollect(&myreq, request_id);
	return i;
};

int TdApi::queryCreditData(const dict& req, int request_id)
{
	QryCreditDataReq myreq = QryCreditDataReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getChar(req, "credit_direct", &myreq.credit_direct);
	int i = this->api->QueryCreditData(&myreq, request_id);
	return i;
};

int TdApi::queryPreMaturityDebts(const dict& req, int request_id)
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

int TdApi::extendPreMaturityDebts(const dict& req, int request_id)
{
	ExtendPreMaturityDebtsReq myreq = ExtendPreMaturityDebtsReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "sys_date", &myreq.sys_date);
	getString(req, "sno", myreq.sno);
	int i = this->api->ExtendPreMaturityDebts(&myreq, request_id);
	return i;
};

int TdApi::queryPreMaturityDebtsExtension(const dict& req, int request_id)
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

int TdApi::queryVoteProposal(const dict& req, int request_id)
{
	QryVoteProposalReq myreq = QryVoteProposalReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "vote_symbol", myreq.vote_symbol);
	int i = this->api->QueryVoteProposal(&myreq, request_id);
	return i;
};

int TdApi::queryCreditVoteCount(const dict& req, int request_id)
{
	QryCreditVoteCountReq myreq = QryCreditVoteCountReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "meeting_seq", myreq.meeting_seq);
	getString(req, "voting_proposal", myreq.voting_proposal);
	int i = this->api->QueryCreditVoteCount(&myreq, request_id);
	return i;
};

int TdApi::queryCreditVote(const dict& req, int request_id)
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

int TdApi::queryNetVoteRights(const dict& req, int request_id)
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

int TdApi::queryNetVoteResult(const dict& req, int request_id)
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

int TdApi::queryNetVoteCount(const dict& req, int request_id)
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

int TdApi::appointContractSellStockRepay(const dict& req, int request_id)
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

int TdApi::queryStkConcentration(const dict& req, int request_id)
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

int TdApi::queryHKHisOrders(const dict& req, int request_id)
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

int TdApi::queryWithdrawCash(const dict& req, int request_id)
{
	QueryWithdrawCashReq myreq = QueryWithdrawCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryWithdrawCash(&myreq, request_id);
	return i;
};

int TdApi::queryTradeListTotal(const dict& req, int request_id)
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

int TdApi::eTFSubscriptCancel(const dict& req, int request_id)
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

int TdApi::queryNetVoteOrder(const dict& req, int request_id)
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

int TdApi::netVoteOrder(const dict& req, int request_id, string terminal_info)
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

int TdApi::creditNetVoteOrder(const dict& req, int request_id, string terminal_info)
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

int TdApi::queryMSCash(const dict& req, int request_id)
{
	QueryMSCashReq myreq = QueryMSCashReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryMSCash(&myreq, request_id);
	return i;
};

int TdApi::queryMSPositions(const dict& req, int request_id)
{
	QueryMSPositionsReq myreq = QueryMSPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getChar(req, "qry_direct", &myreq.qry_direct);
	int i = this->api->QueryMSPositions(&myreq, request_id);
	return i;
};

int TdApi::queryMSCreditDebtsFlow(const dict& req, int request_id)
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

///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
    using TdApi::TdApi;
    
	void onDisconnect() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onDisconnect);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onError(const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onError, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRiskNotify(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRiskNotify, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onFailBackNotify(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFailBackNotify, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onLogin(const dict& data, const dict& error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onLogin, data, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onTradeReport(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onTradeReport, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onOrderStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onOrderStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onOrderRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onOrderRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCancelRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCancelRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryTradeRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryTradeRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPositionRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryPositionRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCashRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCashRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryJZJYAvailFundRsp(int64_t avail_balance, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryJZJYAvailFundRsp, avail_balance, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onTransferFundInAndOutRsp(int64_t transfer_value, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onTransferFundInAndOutRsp, transfer_value, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onTransferFundBetweenSecuidRsp(int64_t transfer_value, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onTransferFundBetweenSecuidRsp, transfer_value, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryETFRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryETFRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryETFStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryETFStockRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryMaxOrderQtyRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryMaxOrderQtyRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryIPOMaxPurchaseRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryIPOMaxPurchaseRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryIPOStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryIPOStockRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQuerySecurityBaseInfoRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQuerySecurityBaseInfoRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCreditMortgageInOutRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCreditMortgageInOutRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCreditStockBackRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCreditStockBackRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCreditPayBackRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCreditPayBackRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCreditPayBackByOrderRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCreditPayBackByOrderRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditStockRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditMortgageHoldRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditMortgageHoldRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditAssetsRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetsRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditFinanceRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFinanceRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditShortsellRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditShortsellRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditRepayAmountRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditRepayAmountRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditRepayStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditRepayStockRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditSecuritySellQtyRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditSecuritySellQtyRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQuerySecuidRightRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQuerySecuidRightRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKRateRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKRateRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKStockRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKStockRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKFundRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKFundRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKMinPriceUnitRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKMinPriceUnitRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKTradeCalendarRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKTradeCalendarRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryLockSecurityDetailRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryLockSecurityDetailRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onExtendLockSecurityRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onExtendLockSecurityRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryLockSecurityExtensionRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryLockSecurityExtensionRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryTransferFundHistoryRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryTransferFundHistoryRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditDebtsFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsFlowRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditAssetFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetFlowRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditDebtsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onMicroServiceRsp(const dict& data, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onMicroServiceRsp, data, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryBankBalanceRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryBankBalanceRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryBankInfoRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryBankInfoRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onBankSecTransferRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onBankSecTransferRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryBankSecTransferRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryBankSecTransferRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHisBankSecTransferRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHisBankSecTransferRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onFundAccountTransferRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFundAccountTransferRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryFundAccountTransferRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryFundAccountTransferRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHisOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHisOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHisTradeRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHisTradeRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryDeliveryOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryDeliveryOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryStateOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryStateOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryExchangeListsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryExchangeListsRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onModifyPasswordRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onModifyPasswordRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPHXXRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryPHXXRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryZQXXRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryZQXXRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryLockSecurityContractRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryLockSecurityContractRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditContractRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditContractRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditDebtsCollectRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtsCollectRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditDataRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDataRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPreMaturityDebtsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryPreMaturityDebtsRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onExtendPreMaturityDebtsRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onExtendPreMaturityDebtsRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPreMaturityDebtsExtensionRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryPreMaturityDebtsExtensionRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryVoteProposalRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryVoteProposalRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditVoteCountRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditVoteCountRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCreditVoteRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditVoteRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryNetVoteRightsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteRightsRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryNetVoteResultRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteResultRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryNetVoteCountRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteCountRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryStkConcentrationRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryStkConcentrationRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryHKHisOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryHKHisOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryWithdrawCashRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryWithdrawCashRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryNetVoteOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryNetVoteOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryTradeTotalRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryTradeTotalRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onETFSubscriptCancelRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onETFSubscriptCancelRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onNetVoteOrderRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onNetVoteOrderRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCreditNetVoteOrderRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onCreditNetVoteOrderRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryMSCashRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryMSCashRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryMSPositionsRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryMSPositionsRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryMSCreditDebtsFlowRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryMSCreditDebtsFlowRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};


PYBIND11_MODULE(vnhfttd, m)
{
    class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
    TdApi
        .def(init<>())
        .def("createTraderApi", &TdApi::createTraderApi)
        .def("release", &TdApi::release)
        .def("exit", &TdApi::exit)
        .def("getApiVersion", &TdApi::getApiVersion)
        .def("setLogConfig", &TdApi::setLogConfig)
		.def("setCriticalMsgLog", &TdApi::setCriticalMsgLog)
		.def("setLoginRetryCount", &TdApi::setLoginRetryCount)
		.def("setLoginRetryInterval", &TdApi::setLoginRetryInterval)
		.def("setReconnectConfig", &TdApi::setReconnectConfig)
		.def("getApiLastError", &TdApi::getApiLastError)

		.def("login", &TdApi::login)
		.def("getCounterType", &TdApi::getCounterType)
		.def("getSecuidInfo", &TdApi::getSecuidInfo)
		.def("getAllSecuidInfo", &TdApi::getAllSecuidInfo)
		.def("getApiLocalAddr", &TdApi::getApiLocalAddr)
		.def("order", &TdApi::order)
		.def("batchOrder", &TdApi::batchOrder)
		.def("cancelOrder", &TdApi::cancelOrder)
		.def("batchCancelOrder", &TdApi::batchCancelOrder)
		.def("batchCancelAllOrder", &TdApi::batchCancelAllOrder)
		.def("queryOrder", &TdApi::queryOrder)
		.def("queryOrderByCode", &TdApi::queryOrderByCode)
		.def("queryOrders", &TdApi::queryOrders)
		.def("queryTradeByOrderId", &TdApi::queryTradeByOrderId)
		.def("queryTradeByCode", &TdApi::queryTradeByCode)
		.def("queryTrades", &TdApi::queryTrades)
		.def("queryETFTrades", &TdApi::queryETFTrades)
		.def("queryPosition", &TdApi::queryPosition)
		.def("queryPositions", &TdApi::queryPositions)
		.def("queryCash", &TdApi::queryCash)
		.def("queryJZJYAvailFund", &TdApi::queryJZJYAvailFund)
		.def("transferFundInAndOut", &TdApi::transferFundInAndOut)
		.def("transferFundBetweenSecuid", &TdApi::transferFundBetweenSecuid)
		.def("queryETFs", &TdApi::queryETFs)
		.def("queryETFStocks", &TdApi::queryETFStocks)
		.def("queryMaxOrderQty", &TdApi::queryMaxOrderQty)
		.def("queryIPOMaxPurchase", &TdApi::queryIPOMaxPurchase)
		.def("queryIPOStock", &TdApi::queryIPOStock)
		.def("querySecurityBaseInfo", &TdApi::querySecurityBaseInfo)
		.def("creditMortgageInOut", &TdApi::creditMortgageInOut)
		.def("creditStockBack", &TdApi::creditStockBack)
		.def("creditPayBack", &TdApi::creditPayBack)
		.def("creditPayBackByOrder", &TdApi::creditPayBackByOrder)
		.def("queryCreditStock", &TdApi::queryCreditStock)
		.def("queryCreditMortgageHold", &TdApi::queryCreditMortgageHold)
		.def("queryCreditAssets", &TdApi::queryCreditAssets)
		.def("queryCreditFinance", &TdApi::queryCreditFinance)
		.def("queryCreditShortsell", &TdApi::queryCreditShortsell)
		.def("queryCreditRepayAmount", &TdApi::queryCreditRepayAmount)
		.def("queryCreditRepayStock", &TdApi::queryCreditRepayStock)
		.def("queryCreditSecuritySellQty", &TdApi::queryCreditSecuritySellQty)
		.def("querySecuidRight", &TdApi::querySecuidRight)
		.def("queryHKRate", &TdApi::queryHKRate)
		.def("queryHKStock", &TdApi::queryHKStock)
		.def("queryHKFund", &TdApi::queryHKFund)
		.def("queryHKMinPriceUnit", &TdApi::queryHKMinPriceUnit)
		.def("queryHKTradeCalendar", &TdApi::queryHKTradeCalendar)
		.def("queryLockSecurityDetail", &TdApi::queryLockSecurityDetail)
		.def("extendLockSecurity", &TdApi::extendLockSecurity)
		.def("queryLockSecurityExtension", &TdApi::queryLockSecurityExtension)
		.def("queryTransferFundHistory", &TdApi::queryTransferFundHistory)
		.def("queryCreditDebtsFlow", &TdApi::queryCreditDebtsFlow)
		.def("queryCreditAssetFlow", &TdApi::queryCreditAssetFlow)
		.def("queryCreditDebts", &TdApi::queryCreditDebts)
		.def("doMicroServiceReq", &TdApi::doMicroServiceReq)
		.def("queryBankBalance", &TdApi::queryBankBalance)
		.def("queryBankInfo", &TdApi::queryBankInfo)
		.def("bankSecTransfer", &TdApi::bankSecTransfer)
		.def("queryBankSecTransfer", &TdApi::queryBankSecTransfer)
		.def("queryHisBankSecTransfer", &TdApi::queryHisBankSecTransfer)
		.def("fundAccountTransfer", &TdApi::fundAccountTransfer)
		.def("queryFundAccountTransfer", &TdApi::queryFundAccountTransfer)
		.def("queryHisOrders", &TdApi::queryHisOrders)
		.def("queryHisTrades", &TdApi::queryHisTrades)
		.def("queryDeliveryOrders", &TdApi::queryDeliveryOrders)
		.def("queryStateOrders", &TdApi::queryStateOrders)
		.def("queryExchangeLists", &TdApi::queryExchangeLists)
		.def("modifyPassword", &TdApi::modifyPassword)
		.def("queryPHXX", &TdApi::queryPHXX)
		.def("queryZQXX", &TdApi::queryZQXX)
		.def("queryLockSecurityContract", &TdApi::queryLockSecurityContract)
		.def("queryCreditContract", &TdApi::queryCreditContract)
		.def("queryCreditDebtsCollect", &TdApi::queryCreditDebtsCollect)
		.def("queryCreditData", &TdApi::queryCreditData)
		.def("queryPreMaturityDebts", &TdApi::queryPreMaturityDebts)
		.def("extendPreMaturityDebts", &TdApi::extendPreMaturityDebts)
		.def("queryPreMaturityDebtsExtension", &TdApi::queryPreMaturityDebtsExtension)
		.def("queryVoteProposal", &TdApi::queryVoteProposal)
		.def("queryCreditVoteCount", &TdApi::queryCreditVoteCount)
		.def("queryCreditVote", &TdApi::queryCreditVote)
		.def("queryNetVoteRights", &TdApi::queryNetVoteRights)
		.def("queryNetVoteResult", &TdApi::queryNetVoteResult)
		.def("queryNetVoteCount", &TdApi::queryNetVoteCount)
		.def("appointContractSellStockRepay", &TdApi::appointContractSellStockRepay)
		.def("queryStkConcentration", &TdApi::queryStkConcentration)
		.def("queryHKHisOrders", &TdApi::queryHKHisOrders)
		.def("queryWithdrawCash", &TdApi::queryWithdrawCash)
		.def("queryTradeListTotal", &TdApi::queryTradeListTotal)
		.def("eTFSubscriptCancel", &TdApi::eTFSubscriptCancel)
		.def("queryNetVoteOrder", &TdApi::queryNetVoteOrder)
		.def("netVoteOrder", &TdApi::netVoteOrder)
		.def("creditNetVoteOrder", &TdApi::creditNetVoteOrder)
		.def("queryMSCash", &TdApi::queryMSCash)
		.def("queryMSPositions", &TdApi::queryMSPositions)
		.def("queryMSCreditDebtsFlow", &TdApi::queryMSCreditDebtsFlow)

		.def("onDisconnect", &TdApi::onDisconnect)
		.def("onError", &TdApi::onError)
		.def("onRiskNotify", &TdApi::onRiskNotify)
		.def("onFailBackNotify", &TdApi::onFailBackNotify)
		.def("onLogin", &TdApi::onLogin)
		.def("onTradeReport", &TdApi::onTradeReport)
		.def("onOrderStatus", &TdApi::onOrderStatus)
		.def("onOrderRsp", &TdApi::onOrderRsp)
		.def("onCancelRsp", &TdApi::onCancelRsp)
		.def("onQueryOrderRsp", &TdApi::onQueryOrderRsp)
		.def("onQueryTradeRsp", &TdApi::onQueryTradeRsp)
		.def("onQueryPositionRsp", &TdApi::onQueryPositionRsp)
		.def("onQueryCashRsp", &TdApi::onQueryCashRsp)
		.def("onQueryJZJYAvailFundRsp", &TdApi::onQueryJZJYAvailFundRsp)
		.def("onTransferFundInAndOutRsp", &TdApi::onTransferFundInAndOutRsp)
		.def("onTransferFundBetweenSecuidRsp", &TdApi::onTransferFundBetweenSecuidRsp)
		.def("onQueryETFRsp", &TdApi::onQueryETFRsp)
		.def("onQueryETFStockRsp", &TdApi::onQueryETFStockRsp)
		.def("onQueryMaxOrderQtyRsp", &TdApi::onQueryMaxOrderQtyRsp)
		.def("onQueryIPOMaxPurchaseRsp", &TdApi::onQueryIPOMaxPurchaseRsp)
		.def("onQueryIPOStockRsp", &TdApi::onQueryIPOStockRsp)
		.def("onQuerySecurityBaseInfoRsp", &TdApi::onQuerySecurityBaseInfoRsp)
		.def("onCreditMortgageInOutRsp", &TdApi::onCreditMortgageInOutRsp)
		.def("onCreditStockBackRsp", &TdApi::onCreditStockBackRsp)
		.def("onCreditPayBackRsp", &TdApi::onCreditPayBackRsp)
		.def("onCreditPayBackByOrderRsp", &TdApi::onCreditPayBackByOrderRsp)
		.def("onQueryCreditStockRsp", &TdApi::onQueryCreditStockRsp)
		.def("onQueryCreditMortgageHoldRsp", &TdApi::onQueryCreditMortgageHoldRsp)
		.def("onQueryCreditAssetsRsp", &TdApi::onQueryCreditAssetsRsp)
		.def("onQueryCreditFinanceRsp", &TdApi::onQueryCreditFinanceRsp)
		.def("onQueryCreditShortsellRsp", &TdApi::onQueryCreditShortsellRsp)
		.def("onQueryCreditRepayAmountRsp", &TdApi::onQueryCreditRepayAmountRsp)
		.def("onQueryCreditRepayStockRsp", &TdApi::onQueryCreditRepayStockRsp)
		.def("onQueryCreditSecuritySellQtyRsp", &TdApi::onQueryCreditSecuritySellQtyRsp)
		.def("onQuerySecuidRightRsp", &TdApi::onQuerySecuidRightRsp)
		.def("onQueryHKRateRsp", &TdApi::onQueryHKRateRsp)
		.def("onQueryHKStockRsp", &TdApi::onQueryHKStockRsp)
		.def("onQueryHKFundRsp", &TdApi::onQueryHKFundRsp)
		.def("onQueryHKMinPriceUnitRsp", &TdApi::onQueryHKMinPriceUnitRsp)
		.def("onQueryHKTradeCalendarRsp", &TdApi::onQueryHKTradeCalendarRsp)
		.def("onQueryLockSecurityDetailRsp", &TdApi::onQueryLockSecurityDetailRsp)
		.def("onExtendLockSecurityRsp", &TdApi::onExtendLockSecurityRsp)
		.def("onQueryLockSecurityExtensionRsp", &TdApi::onQueryLockSecurityExtensionRsp)
		.def("onQueryTransferFundHistoryRsp", &TdApi::onQueryTransferFundHistoryRsp)
		.def("onQueryCreditDebtsFlowRsp", &TdApi::onQueryCreditDebtsFlowRsp)
		.def("onQueryCreditAssetFlowRsp", &TdApi::onQueryCreditAssetFlowRsp)
		.def("onQueryCreditDebtsRsp", &TdApi::onQueryCreditDebtsRsp)
		.def("onMicroServiceRsp", &TdApi::onMicroServiceRsp)
		.def("onQueryBankBalanceRsp", &TdApi::onQueryBankBalanceRsp)
		.def("onQueryBankInfoRsp", &TdApi::onQueryBankInfoRsp)
		.def("onBankSecTransferRsp", &TdApi::onBankSecTransferRsp)
		.def("onQueryBankSecTransferRsp", &TdApi::onQueryBankSecTransferRsp)
		.def("onQueryHisBankSecTransferRsp", &TdApi::onQueryHisBankSecTransferRsp)
		.def("onFundAccountTransferRsp", &TdApi::onFundAccountTransferRsp)
		.def("onQueryFundAccountTransferRsp", &TdApi::onQueryFundAccountTransferRsp)
		.def("onQueryHisOrderRsp", &TdApi::onQueryHisOrderRsp)
		.def("onQueryHisTradeRsp", &TdApi::onQueryHisTradeRsp)
		.def("onQueryDeliveryOrderRsp", &TdApi::onQueryDeliveryOrderRsp)
		.def("onQueryStateOrderRsp", &TdApi::onQueryStateOrderRsp)
		.def("onQueryExchangeListsRsp", &TdApi::onQueryExchangeListsRsp)
		.def("onModifyPasswordRsp", &TdApi::onModifyPasswordRsp)
		.def("onQueryPHXXRsp", &TdApi::onQueryPHXXRsp)
		.def("onQueryZQXXRsp", &TdApi::onQueryZQXXRsp)
		.def("onQueryLockSecurityContractRsp", &TdApi::onQueryLockSecurityContractRsp)
		.def("onQueryCreditContractRsp", &TdApi::onQueryCreditContractRsp)
		.def("onQueryCreditDebtsCollectRsp", &TdApi::onQueryCreditDebtsCollectRsp)
		.def("onQueryCreditDataRsp", &TdApi::onQueryCreditDataRsp)
		.def("onQueryPreMaturityDebtsRsp", &TdApi::onQueryPreMaturityDebtsRsp)
		.def("onExtendPreMaturityDebtsRsp", &TdApi::onExtendPreMaturityDebtsRsp)
		.def("onQueryPreMaturityDebtsExtensionRsp", &TdApi::onQueryPreMaturityDebtsExtensionRsp)
		.def("onQueryVoteProposalRsp", &TdApi::onQueryVoteProposalRsp)
		.def("onQueryCreditVoteCountRsp", &TdApi::onQueryCreditVoteCountRsp)
		.def("onQueryCreditVoteRsp", &TdApi::onQueryCreditVoteRsp)
		.def("onQueryNetVoteRightsRsp", &TdApi::onQueryNetVoteRightsRsp)
		.def("onQueryNetVoteResultRsp", &TdApi::onQueryNetVoteResultRsp)
		.def("onQueryNetVoteCountRsp", &TdApi::onQueryNetVoteCountRsp)
		.def("onQueryStkConcentrationRsp", &TdApi::onQueryStkConcentrationRsp)
		.def("onQueryHKHisOrderRsp", &TdApi::onQueryHKHisOrderRsp)
		.def("onQueryWithdrawCashRsp", &TdApi::onQueryWithdrawCashRsp)
		.def("onQueryNetVoteOrderRsp", &TdApi::onQueryNetVoteOrderRsp)
		.def("onQueryTradeTotalRsp", &TdApi::onQueryTradeTotalRsp)
		.def("onETFSubscriptCancelRsp", &TdApi::onETFSubscriptCancelRsp)
		.def("onNetVoteOrderRsp", &TdApi::onNetVoteOrderRsp)
		.def("onCreditNetVoteOrderRsp", &TdApi::onCreditNetVoteOrderRsp)
		.def("onQueryMSCashRsp", &TdApi::onQueryMSCashRsp)
		.def("onQueryMSPositionsRsp", &TdApi::onQueryMSPositionsRsp)
		.def("onQueryMSCreditDebtsFlowRsp", &TdApi::onQueryMSCreditDebtsFlowRsp)
		;

}
