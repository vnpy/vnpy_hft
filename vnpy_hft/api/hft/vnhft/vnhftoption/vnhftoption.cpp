// vnctpmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "pch.h"
#include "vnhftoption.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void OptionApi::OnDisconnect()
{
	gil_scoped_acquire acquire;
	this->onDisconnect();
};

void OptionApi::OnError(ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onError(error, request_id);
};

void OptionApi::OnRiskNotify(RiskNotify* risk_notify)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["secuid"] = risk_notify->secuid;
		data["alarm_score"] = risk_notify->alarm_score;
		data["alarm_status"] = risk_notify->alarm_status;
		data["alarm_rule"] = risk_notify->alarm_rule;
		data["alarm_time"] = risk_notify->alarm_time;
		data["alarm_msg"] = risk_notify->alarm_msg;
	}
	this->onRiskNotify(data);
};

void OptionApi::OnFailBackNotify(FailBackNotify* failback_notify)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["system_id"] = failback_notify->system_id;
		data["node_id"] = failback_notify->node_id;
		data["status"] = failback_notify->status;
		data["credit_node_flag"] = failback_notify->credit_node_flag;
		data["urgent_flag"] = failback_notify->urgent_flag;
		data["update_source"] = failback_notify->update_source;
	}
	this->onFailBackNotify(data);
};

void OptionApi::OnLogin(LoginRsp* rsp, ErrorInfo* error_info)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = rsp->account_id;
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = rsp->cust_orgid;
		data["cust_branchid"] = rsp->cust_branchid;
		data["cust_id"] = rsp->cust_id;
		data["cust_name"] = rsp->cust_name;
		data["cif_account"] = rsp->cif_account;
		data["user_code"] = rsp->user_code;
		data["user_token"] = rsp->user_token;
		data["token_serial_no"] = rsp->token_serial_no;
		data["sm3_cipher"] = rsp->sm3_cipher;
		data["sys_node_type"] = rsp->sys_node_type;
		data["clear_switch_flag"] = rsp->clear_switch_flag;
		data["trade_switch_flag"] = rsp->trade_switch_flag;
		data["sys_server_id"] = rsp->sys_server_id;
		data["operway"] = rsp->operway;
		data["sys_shbond_type"] = rsp->sys_shbond_type;
		data["reg_branchid"] = rsp->reg_branchid;

		pybind11::list secuid_list;
		pybind11::list ext_secuid_list;

		for (int i = 0; i < 10; i++)
		{
			SecuidInfo secuid = rsp->secuid_array[i];
			dict d1;
			d1["market"] = secuid.market;
			d1["secuid"] = secuid.secuid;
			d1["fund_id"] = secuid.fund_id;
			d1["account_type"] = secuid.account_type;
			d1["account_status"] = secuid.account_status;
			d1["account_class"] = secuid.account_class;
			d1["account_rights"] = secuid.account_rights;
			d1["account_hgtright"] = secuid.account_hgtright;
			secuid_list.append(d1);

			SecuidInfo ext_secuid = rsp->ext_secuid_array[i];
			dict d2;
			d2["market"] = ext_secuid.market;
			d2["secuid"] = ext_secuid.secuid;
			d2["fund_id"] = ext_secuid.fund_id;
			d2["account_type"] = ext_secuid.account_type;
			d2["account_status"] = ext_secuid.account_status;
			d2["account_class"] = ext_secuid.account_class;
			d2["account_rights"] = ext_secuid.account_rights;
			d2["account_hgtright"] = ext_secuid.account_hgtright;
			ext_secuid_list.append(d2);
		}

		data["secuid_array"] = secuid_list;
		data["ext_secuid_array"] = ext_secuid_list;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onLogin(data, error);
};

void OptionApi::OnTradeReport(TradeDetail* trade_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = trade_detail->account_id;
		data["account_type"] = trade_detail->account_type;
		data["cust_orgid"] = trade_detail->cust_orgid;
		data["cust_branchid"] = trade_detail->cust_branchid;
		data["order_id"] = trade_detail->order_id;
		data["cl_order_id"] = trade_detail->cl_order_id;
		data["symbol"] = trade_detail->symbol;
		data["order_type"] = trade_detail->order_type;
		data["side"] = trade_detail->side;
		data["report_type"] = trade_detail->report_type;
		data["report_no"] = trade_detail->report_no;
		data["volume"] = trade_detail->volume;
		data["price"] = trade_detail->price;
		data["turnover"] = trade_detail->turnover;
		data["trade_date"] = trade_detail->trade_date;
		data["trade_time"] = trade_detail->trade_time;
		data["err_code"] = trade_detail->err_code;
		data["err_msg"] = trade_detail->err_msg;
		data["secuid"] = trade_detail->secuid;
		data["name"] = trade_detail->name;
		data["contract_id"] = trade_detail->contract_id;
		data["ex_report_no"] = trade_detail->ex_report_no;
		data["ex_order_id"] = trade_detail->ex_order_id;
		data["margin_amt_type"] = trade_detail->margin_amt_type;
		data["order_price"] = trade_detail->order_price;
		data["order_qty"] = trade_detail->order_qty;
	}
	this->onTradeReport(data);
};

void OptionApi::OnOrderStatus(OrderDetail* order_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["order_id"] = order_detail->order_id;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["orig_order_id"] = order_detail->orig_order_id;
		data["symbol"] = order_detail->symbol;
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
		data["err_msg"] = order_detail->err_msg;
		data["secuid"] = order_detail->secuid;
		data["name"] = order_detail->name;
		data["freeze_amount"] = order_detail->freeze_amount;
		data["contract_id"] = order_detail->contract_id;
		data["ex_order_id"] = order_detail->ex_order_id;
	}
	this->onOrderStatus(data);
};

void OptionApi::OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_rsp->account_id;
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = order_rsp->cust_orgid;
		data["cust_branchid"] = order_rsp->cust_branchid;
		data["order_date"] = order_rsp->order_date;
		data["order_id"] = order_rsp->order_id;
		data["cl_order_id"] = order_rsp->cl_order_id;
		data["contract_id"] = order_rsp->contract_id;
		data["ex_order_id"] = order_rsp->ex_order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onOrderRsp(data, error, request_id, is_last);
};

void OptionApi::OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = cancel_rsp->account_id;
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = cancel_rsp->cust_orgid;
		data["cust_branchid"] = cancel_rsp->cust_branchid;
		data["order_id"] = cancel_rsp->order_id;
		data["cl_order_id"] = cancel_rsp->cl_order_id;
		data["cl_cancel_id"] = cancel_rsp->cl_cancel_id;
		data["cancel_id"] = cancel_rsp->cancel_id;
		data["ex_order_id"] = cancel_rsp->ex_order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCancelRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryOrderRsp(OrderDetail* order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["order_id"] = order_detail->order_id;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["orig_order_id"] = order_detail->orig_order_id;
		data["symbol"] = order_detail->symbol;
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
		data["err_msg"] = order_detail->err_msg;
		data["secuid"] = order_detail->secuid;
		data["name"] = order_detail->name;
		data["freeze_amount"] = order_detail->freeze_amount;
		data["contract_id"] = order_detail->contract_id;
		data["ex_order_id"] = order_detail->ex_order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryTradeRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = trade_detail->account_id;
		data["account_type"] = trade_detail->account_type;
		data["cust_orgid"] = trade_detail->cust_orgid;
		data["cust_branchid"] = trade_detail->cust_branchid;
		data["order_id"] = trade_detail->order_id;
		data["cl_order_id"] = trade_detail->cl_order_id;
		data["symbol"] = trade_detail->symbol;
		data["order_type"] = trade_detail->order_type;
		data["side"] = trade_detail->side;
		data["report_type"] = trade_detail->report_type;
		data["report_no"] = trade_detail->report_no;
		data["volume"] = trade_detail->volume;
		data["price"] = trade_detail->price;
		data["turnover"] = trade_detail->turnover;
		data["trade_date"] = trade_detail->trade_date;
		data["trade_time"] = trade_detail->trade_time;
		data["err_code"] = trade_detail->err_code;
		data["err_msg"] = trade_detail->err_msg;
		data["secuid"] = trade_detail->secuid;
		data["name"] = trade_detail->name;
		data["contract_id"] = trade_detail->contract_id;
		data["ex_report_no"] = trade_detail->ex_report_no;
		data["ex_order_id"] = trade_detail->ex_order_id;
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

void OptionApi::OnQueryPositionRsp(OptionPositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["side"] = position_detail->side;
		data["init_volume"] = position_detail->init_volume;
		data["init_avail_volume"] = position_detail->init_avail_volume;
		data["init_comb_volume"] = position_detail->init_comb_volume;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["comb_volume"] = position_detail->comb_volume;
		data["open_volume"] = position_detail->open_volume;
		data["close_volume"] = position_detail->close_volume;
		data["exercise_frozen"] = position_detail->exercise_frozen;
		data["buy_cost"] = position_detail->buy_cost;
		data["secuid"] = position_detail->secuid;
		data["margin"] = position_detail->margin;
		data["frozen_margin"] = position_detail->frozen_margin;
		data["commission"] = position_detail->commission;
		data["frozen_commission"] = position_detail->frozen_commission;
		data["exercise_frozen_amount"] = position_detail->exercise_frozen_amount;
		data["frozen_amount"] = position_detail->frozen_amount;
		data["today_close_profit"] = position_detail->today_close_profit;
		data["buy_quota_used"] = position_detail->buy_quota_used;
		data["last_price"] = position_detail->last_price;
		data["underlying_multiple"] = position_detail->underlying_multiple;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryCashRsp(OptionCashDetail* cash_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = cash_detail->account_id;
		data["account_type"] = cash_detail->account_type;
		data["cust_orgid"] = cash_detail->cust_orgid;
		data["cust_branchid"] = cash_detail->cust_branchid;
		data["currency_type"] = cash_detail->currency_type;
		data["init_amount"] = cash_detail->init_amount;
		data["total_amount"] = cash_detail->total_amount;
		data["avail_amount"] = cash_detail->avail_amount;
		data["fetch_amount"] = cash_detail->fetch_amount;
		data["frozen_amount"] = cash_detail->frozen_amount;
		data["used_margin"] = cash_detail->used_margin;
		data["exercise_frozen"] = cash_detail->exercise_frozen;
		data["deposit_amount"] = cash_detail->deposit_amount;
		data["withdraw_amount"] = cash_detail->withdraw_amount;
		data["royalty_in"] = cash_detail->royalty_in;
		data["royalty_out"] = cash_detail->royalty_out;
		data["commission"] = cash_detail->commission;
		data["frozen_commission"] = cash_detail->frozen_commission;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCashRsp(data, error, request_id);
};

void OptionApi::OnQueryJZJYAvailFundRsp(int64_t avail_balance, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryJZJYAvailFundRsp(avail_balance, error, request_id);
};

void OptionApi::OnTransferFundInAndOutRsp(int64_t transfer_value, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onTransferFundInAndOutRsp(transfer_value, error, request_id);
};

void OptionApi::OnExerciseRsp(ExerciseRsp* exercise_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = exercise_rsp->account_id;
		data["account_type"] = exercise_rsp->account_type;
		data["cust_orgid"] = exercise_rsp->cust_orgid;
		data["cust_branchid"] = exercise_rsp->cust_branchid;
		data["cl_order_id"] = exercise_rsp->cl_order_id;
		data["order_id"] = exercise_rsp->order_id;
		data["exercise_type"] = exercise_rsp->exercise_type;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onExerciseRsp(data, error, request_id);
};

void OptionApi::OnCancelExerciseRsp(CancelExerciseRsp* cancel_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = cancel_rsp->account_id;
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = cancel_rsp->cust_orgid;
		data["cust_branchid"] = cancel_rsp->cust_branchid;
		data["order_id"] = cancel_rsp->order_id;
		data["cl_order_id"] = cancel_rsp->cl_order_id;
		data["cl_cancel_id"] = cancel_rsp->cl_cancel_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCancelExerciseRsp(data, error, request_id);
};

void OptionApi::OnExerciseStatus(ExerciseDetail* exercise)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = exercise->account_id;
		data["account_type"] = exercise->account_type;
		data["cust_orgid"] = exercise->cust_orgid;
		data["cust_branchid"] = exercise->cust_branchid;
		data["exercise_type"] = exercise->exercise_type;
		data["cl_order_id"] = exercise->cl_order_id;
		data["order_id"] = exercise->order_id;
		data["counter_order_date"] = exercise->counter_order_date;
		data["counter_order_time"] = exercise->counter_order_time;
		data["counter_cancel_time"] = exercise->counter_cancel_time;
		data["exercise_status"] = exercise->exercise_status;
		data["oper_status"] = exercise->oper_status;
		data["symbol"] = exercise->symbol;
		data["volume"] = exercise->volume;
		data["cancel_volume"] = exercise->cancel_volume;
		data["err_code"] = exercise->err_code;
		data["err_msg"] = exercise->err_msg;
	}
	this->onExerciseStatus(data);
};

void OptionApi::OnQueryExerciseRsp(ExerciseDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = detail->account_id;
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = detail->cust_orgid;
		data["cust_branchid"] = detail->cust_branchid;
		data["exercise_type"] = detail->exercise_type;
		data["cl_order_id"] = detail->cl_order_id;
		data["order_id"] = detail->order_id;
		data["counter_order_date"] = detail->counter_order_date;
		data["counter_order_time"] = detail->counter_order_time;
		data["counter_cancel_time"] = detail->counter_cancel_time;
		data["exercise_status"] = detail->exercise_status;
		data["oper_status"] = detail->oper_status;
		data["symbol"] = detail->symbol;
		data["volume"] = detail->volume;
		data["cancel_volume"] = detail->cancel_volume;
		data["err_code"] = detail->err_code;
		data["err_msg"] = detail->err_msg;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryExerciseRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryContractInfoRsp(ContractInfo* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["contract_id"] = detail->contract_id;
		data["exch_contract_id"] = detail->exch_contract_id;
		data["contract_name"] = detail->contract_name;
		data["underlying_contract_id"] = detail->underlying_contract_id;
		data["underlying_contract_name"] = detail->underlying_contract_name;
		data["underlying_multiplier"] = detail->underlying_multiplier;
		data["strike_mode"] = detail->strike_mode;
		data["options_type"] = detail->options_type;
		data["order_unit"] = detail->order_unit;
		data["buy_trading_unit"] = detail->buy_trading_unit;
		data["sell_trading_unit"] = detail->sell_trading_unit;
		data["max_market_order_buy_volume"] = detail->max_market_order_buy_volume;
		data["min_market_order_buy_volume"] = detail->min_market_order_buy_volume;
		data["max_limit_order_buy_volume"] = detail->max_limit_order_buy_volume;
		data["min_limit_order_buy_volume"] = detail->min_limit_order_buy_volume;
		data["max_market_order_sell_volume"] = detail->max_market_order_sell_volume;
		data["min_market_order_sell_volume"] = detail->min_market_order_sell_volume;
		data["max_limit_order_sell_volume"] = detail->max_limit_order_sell_volume;
		data["min_limit_order_sell_volume"] = detail->min_limit_order_sell_volume;
		data["volume_multiplier"] = detail->volume_multiplier;
		data["price_tick"] = detail->price_tick;
		data["contract_status"] = detail->contract_status;
		data["strike_price"] = detail->strike_price;
		data["first_date"] = detail->first_date;
		data["last_date"] = detail->last_date;
		data["strike_date"] = detail->strike_date;
		data["expire_date"] = detail->expire_date;
		data["deliv_date"] = detail->deliv_date;
		data["is_up_down_limit"] = detail->is_up_down_limit;
		data["margin_unit"] = detail->margin_unit;
		data["pre_settlement_price"] = detail->pre_settlement_price;
		data["pre_close_price"] = detail->pre_close_price;
		data["underlying_pre_close_price"] = detail->underlying_pre_close_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryContractInfoRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryStockPositionRsp(PositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["side"] = position_detail->side;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["init_volume"] = position_detail->init_volume;
		data["market_value"] = position_detail->market_value;
		data["today_buy_volume"] = position_detail->today_buy_volume;
		data["today_sell_volume"] = position_detail->today_sell_volume;
		data["secuid"] = position_detail->secuid;
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
		data["name"] = position_detail->name;
		data["currency_type"] = position_detail->currency_type;
		data["security_type_apex"] = position_detail->security_type_apex;
		data["profit_price"] = position_detail->profit_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryStockPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnTransferStockStatus(TransferStockDetail* transfer_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = transfer_detail->account_id;
		data["account_type"] = transfer_detail->account_type;
		data["cust_orgid"] = transfer_detail->cust_orgid;
		data["cust_branchid"] = transfer_detail->cust_branchid;
		data["serial_number"] = transfer_detail->serial_number;
		data["symbol"] = transfer_detail->symbol;
		data["transact_date"] = transfer_detail->transact_date;
		data["transact_time"] = transfer_detail->transact_time;
		data["transfer_type"] = transfer_detail->transfer_type;
		data["transfer_side"] = transfer_detail->transfer_side;
		data["transfer_status"] = transfer_detail->transfer_status;
		data["yesterday_volume"] = transfer_detail->yesterday_volume;
		data["today_bs_volume"] = transfer_detail->today_bs_volume;
		data["today_pr_volume"] = transfer_detail->today_pr_volume;
		data["stock_cust_id"] = transfer_detail->stock_cust_id;
		data["stock_secuid"] = transfer_detail->stock_secuid;
		data["status_msg"] = transfer_detail->status_msg;
	}
	this->onTransferStockStatus(data);
};

void OptionApi::OnTransferStockRsp(TransferStockRsp* transfer_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = transfer_rsp->account_id;
		data["account_type"] = transfer_rsp->account_type;
		data["cust_orgid"] = transfer_rsp->cust_orgid;
		data["cust_branchid"] = transfer_rsp->cust_branchid;
		data["symbol"] = transfer_rsp->symbol;
		data["transfer_type"] = transfer_rsp->transfer_type;
		data["transfer_side"] = transfer_rsp->transfer_side;
		data["transfer_qty"] = transfer_rsp->transfer_qty;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onTransferStockRsp(data, error, request_id);
};

void OptionApi::OnQueryTransferStockRsp(TransferStockDetail* transfer_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = transfer_detail->account_id;
		data["account_type"] = transfer_detail->account_type;
		data["cust_orgid"] = transfer_detail->cust_orgid;
		data["cust_branchid"] = transfer_detail->cust_branchid;
		data["serial_number"] = transfer_detail->serial_number;
		data["symbol"] = transfer_detail->symbol;
		data["transact_date"] = transfer_detail->transact_date;
		data["transact_time"] = transfer_detail->transact_time;
		data["transfer_type"] = transfer_detail->transfer_type;
		data["transfer_side"] = transfer_detail->transfer_side;
		data["transfer_status"] = transfer_detail->transfer_status;
		data["yesterday_volume"] = transfer_detail->yesterday_volume;
		data["today_bs_volume"] = transfer_detail->today_bs_volume;
		data["today_pr_volume"] = transfer_detail->today_pr_volume;
		data["stock_cust_id"] = transfer_detail->stock_cust_id;
		data["stock_secuid"] = transfer_detail->stock_secuid;
		data["status_msg"] = transfer_detail->status_msg;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryTransferStockRsp(data, error, request_id);
};

void OptionApi::OnLockOrderStatus(LockOrderDetail* order_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["symbol"] = order_detail->symbol;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["order_id"] = order_detail->order_id;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["lock_type"] = order_detail->lock_type;
		data["lock_status"] = order_detail->lock_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = order_detail->err_msg;
	}
	this->onLockOrderStatus(data);
};

void OptionApi::OnLockOrderRsp(LockOrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_rsp->account_id;
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = order_rsp->cust_orgid;
		data["cust_branchid"] = order_rsp->cust_branchid;
		data["lock_type"] = order_rsp->lock_type;
		data["order_id"] = order_rsp->order_id;
		data["cl_order_id"] = order_rsp->cl_order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onLockOrderRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryLockOrderRsp(LockOrderDetail* order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["symbol"] = order_detail->symbol;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["order_id"] = order_detail->order_id;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["lock_type"] = order_detail->lock_type;
		data["lock_status"] = order_detail->lock_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = order_detail->err_msg;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryLockOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryLockPositionRsp(PositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["side"] = position_detail->side;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["init_volume"] = position_detail->init_volume;
		data["market_value"] = position_detail->market_value;
		data["today_buy_volume"] = position_detail->today_buy_volume;
		data["today_sell_volume"] = position_detail->today_sell_volume;
		data["secuid"] = position_detail->secuid;
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
		data["name"] = position_detail->name;
		data["currency_type"] = position_detail->currency_type;
		data["security_type_apex"] = position_detail->security_type_apex;
		data["profit_price"] = position_detail->profit_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryLockPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnCombOrderStatus(CombOrderDetail* order_detail)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["symbol"] = order_detail->symbol;
		data["exch_comb_id"] = order_detail->exch_comb_id;
		data["comb_type"] = order_detail->comb_type;
		data["comb_strategy"] = order_detail->comb_strategy;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["order_id"] = order_detail->order_id;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["order_status"] = order_detail->order_status;
		data["oper_status"] = order_detail->oper_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = order_detail->err_msg;
	}
	this->onCombOrderStatus(data);
};

void OptionApi::OnCombOrderRsp(CombOrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_rsp->account_id;
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = order_rsp->cust_orgid;
		data["cust_branchid"] = order_rsp->cust_branchid;
		data["comb_type"] = order_rsp->comb_type;
		data["order_id"] = order_rsp->order_id;
		data["cl_order_id"] = order_rsp->cl_order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCombOrderRsp(data, error, request_id, is_last);
};

void OptionApi::OnCombExerciseStatus(CombExerciseDetail* exercise)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = exercise->account_id;
		data["account_type"] = exercise->account_type;
		data["cust_orgid"] = exercise->cust_orgid;
		data["cust_branchid"] = exercise->cust_branchid;
		data["call_symbol"] = exercise->call_symbol;
		data["put_symbol"] = exercise->put_symbol;
		data["cl_order_id"] = exercise->cl_order_id;
		data["order_id"] = exercise->order_id;
		data["order_date"] = exercise->order_date;
		data["order_time"] = exercise->order_time;
		data["cancel_time"] = exercise->cancel_time;
		data["exercise_status"] = exercise->exercise_status;
		data["oper_status"] = exercise->oper_status;
		data["volume"] = exercise->volume;
		data["cancel_volume"] = exercise->cancel_volume;
		data["err_code"] = exercise->err_code;
		data["err_msg"] = exercise->err_msg;
	}
	this->onCombExerciseStatus(data);
};

void OptionApi::OnCombExerciseRsp(CombExerciseRsp* exercise_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = exercise_rsp->account_id;
		data["account_type"] = exercise_rsp->account_type;
		data["cust_orgid"] = exercise_rsp->cust_orgid;
		data["cust_branchid"] = exercise_rsp->cust_branchid;
		data["cl_order_id"] = exercise_rsp->cl_order_id;
		data["order_id"] = exercise_rsp->order_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCombExerciseRsp(data, error, request_id);
};

void OptionApi::OnCancelCombExerciseRsp(CancelCombExerciseRsp* cancel_rsp, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = cancel_rsp->account_id;
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = cancel_rsp->cust_orgid;
		data["cust_branchid"] = cancel_rsp->cust_branchid;
		data["order_id"] = cancel_rsp->order_id;
		data["cl_order_id"] = cancel_rsp->cl_order_id;
		data["cl_cancel_id"] = cancel_rsp->cl_cancel_id;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onCancelCombExerciseRsp(data, error, request_id);
};

void OptionApi::OnQueryCombOrderRsp(CombOrderDetail* order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = order_detail->account_id;
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = order_detail->cust_orgid;
		data["cust_branchid"] = order_detail->cust_branchid;
		data["symbol"] = order_detail->symbol;
		data["exch_comb_id"] = order_detail->exch_comb_id;
		data["comb_type"] = order_detail->comb_type;
		data["comb_strategy"] = order_detail->comb_strategy;
		data["cl_order_id"] = order_detail->cl_order_id;
		data["order_id"] = order_detail->order_id;
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["order_status"] = order_detail->order_status;
		data["oper_status"] = order_detail->oper_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = order_detail->err_msg;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCombOrderRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryCombExerciseRsp(CombExerciseDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = detail->account_id;
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = detail->cust_orgid;
		data["cust_branchid"] = detail->cust_branchid;
		data["call_symbol"] = detail->call_symbol;
		data["put_symbol"] = detail->put_symbol;
		data["cl_order_id"] = detail->cl_order_id;
		data["order_id"] = detail->order_id;
		data["order_date"] = detail->order_date;
		data["order_time"] = detail->order_time;
		data["cancel_time"] = detail->cancel_time;
		data["exercise_status"] = detail->exercise_status;
		data["oper_status"] = detail->oper_status;
		data["volume"] = detail->volume;
		data["cancel_volume"] = detail->cancel_volume;
		data["err_code"] = detail->err_code;
		data["err_msg"] = detail->err_msg;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCombExerciseRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryCombPositionRsp(CombPositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["comb_strategy"] = position_detail->comb_strategy;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["yesterday_volume"] = position_detail->yesterday_volume;
		data["yesterday_avail_volume"] = position_detail->yesterday_avail_volume;
		data["today_volume"] = position_detail->today_volume;
		data["today_avail_volume"] = position_detail->today_avail_volume;
		data["margin"] = position_detail->margin;
		data["frozen_margin"] = position_detail->frozen_margin;
		data["commission"] = position_detail->commission;
		data["frozen_commission"] = position_detail->frozen_commission;
		data["secuid"] = position_detail->secuid;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCombPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryCombContractInfoRsp(CombContractInfo* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["contract_id"] = detail->contract_id;
		data["comb_strategy"] = detail->comb_strategy;
		data["leg1_contract_id"] = detail->leg1_contract_id;
		data["leg1_name"] = detail->leg1_name;
		data["leg1_side"] = detail->leg1_side;
		data["leg2_contract_id"] = detail->leg2_contract_id;
		data["leg2_name"] = detail->leg2_name;
		data["leg2_side"] = detail->leg2_side;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCombContractInfoRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryTransferFundHistoryRsp(TransferFundDetail* detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = detail->account_id;
		data["cust_orgid"] = detail->cust_orgid;
		data["cust_branchid"] = detail->cust_branchid;
		data["account_type"] = detail->account_type;
		data["serial_number"] = detail->serial_number;
		data["transact_date"] = detail->transact_date;
		data["transact_time"] = detail->transact_time;
		data["transfer_value"] = detail->transfer_value;
		data["transfer_side"] = detail->transfer_side;
		data["transfer_status"] = detail->transfer_status;
		data["remark"] = detail->remark;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryTransferFundHistoryRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryCombPositionSubDetailRsp(CombPositionSubDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["comb_strategy"] = position_detail->comb_strategy;
		data["exch_comb_id"] = position_detail->exch_comb_id;
		data["volume"] = position_detail->volume;
		data["yesterday_volume"] = position_detail->yesterday_volume;
		data["today_volume"] = position_detail->today_volume;
		data["comb_date"] = position_detail->comb_date;
		data["comb_time"] = position_detail->comb_time;
		data["comb_status"] = position_detail->comb_status;
		data["secuid"] = position_detail->secuid;
		data["legs_num"] = position_detail->legs_num;
		data["leg1_symbol"] = position_detail->leg1_symbol;
		data["leg1_yesterday_volume"] = position_detail->leg1_yesterday_volume;
		data["leg1_today_volume"] = position_detail->leg1_today_volume;
		data["leg1_pos_side"] = position_detail->leg1_pos_side;
		data["leg1_option_type"] = position_detail->leg1_option_type;
		data["leg2_symbol"] = position_detail->leg2_symbol;
		data["leg2_yesterday_volume"] = position_detail->leg2_yesterday_volume;
		data["leg2_today_volume"] = position_detail->leg2_today_volume;
		data["leg2_pos_side"] = position_detail->leg2_pos_side;
		data["leg2_option_type"] = position_detail->leg2_option_type;
		data["yesterday_split_frozen_volume"] = position_detail->yesterday_split_frozen_volume;
		data["today_split_frozen_volume"] = position_detail->today_split_frozen_volume;
		data["leg1_yesterday_split_frozen_volume"] = position_detail->leg1_yesterday_split_frozen_volume;
		data["leg1_today_split_frozen_volume"] = position_detail->leg1_today_split_frozen_volume;
		data["leg2_yesterday_split_frozen_volume"] = position_detail->leg2_yesterday_split_frozen_volume;
		data["leg2_today_split_frozen_volume"] = position_detail->leg2_today_split_frozen_volume;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryCombPositionSubDetailRsp(data, error, request_id, is_last);
};

void OptionApi::OnMicroServiceRsp(MicroServiceRsp* rsp, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = rsp->account_id;
		data["account_type"] = rsp->account_type;
		data["cust_orgid"] = rsp->cust_orgid;
		data["cust_branchid"] = rsp->cust_branchid;
		data["call_status"] = rsp->call_status;
		data["error_code"] = rsp->error_code;
		data["error_info"] = rsp->error_info;
		data["error_extra"] = rsp->error_extra;
		data["response_list_first"] = rsp->response_list_first;
		data["first_list_len"] = rsp->first_list_len;
		data["response_list_second"] = rsp->response_list_second;
		data["second_list_len"] = rsp->second_list_len;
	}
	this->onMicroServiceRsp(data, request_id);
};

void OptionApi::OnQueryPositionLimitsRsp(PositionLimitsDetail* limit_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = limit_detail->account_id;
		data["account_type"] = limit_detail->account_type;
		data["cust_orgid"] = limit_detail->cust_orgid;
		data["cust_branchid"] = limit_detail->cust_branchid;
		data["symbol"] = limit_detail->symbol;
		data["avail_total_limit"] = limit_detail->avail_total_limit;
		data["avail_long_limit"] = limit_detail->avail_long_limit;
		data["avail_today_open_limit"] = limit_detail->avail_today_open_limit;
		data["avail_today_buy_open_limit"] = limit_detail->avail_today_buy_open_limit;
		data["avail_today_sell_open_limit"] = limit_detail->avail_today_sell_open_limit;
		data["avail_today_covered_open_limit"] = limit_detail->avail_today_covered_open_limit;
		data["avail_long_call_limit"] = limit_detail->avail_long_call_limit;
		data["avail_long_put_limit"] = limit_detail->avail_long_put_limit;
		data["avail_long_underlying_limit"] = limit_detail->avail_long_underlying_limit;
		data["avail_short_underlying_limit"] = limit_detail->avail_short_underlying_limit;
		data["total_limit"] = limit_detail->total_limit;
		data["long_limit"] = limit_detail->long_limit;
		data["today_open_limit"] = limit_detail->today_open_limit;
		data["today_buy_open_limit"] = limit_detail->today_buy_open_limit;
		data["today_sell_open_limit"] = limit_detail->today_sell_open_limit;
		data["today_covered_open_limit"] = limit_detail->today_covered_open_limit;
		data["long_call_limit"] = limit_detail->long_call_limit;
		data["long_put_limit"] = limit_detail->long_put_limit;
		data["long_underlying_limit"] = limit_detail->long_underlying_limit;
		data["short_underlying_limit"] = limit_detail->short_underlying_limit;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryPositionLimitsRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryAmountLimitsRsp(AmountLimitsDetail* limit_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = limit_detail->account_id;
		data["account_type"] = limit_detail->account_type;
		data["cust_orgid"] = limit_detail->cust_orgid;
		data["cust_branchid"] = limit_detail->cust_branchid;
		data["long_amount_limit"] = limit_detail->long_amount_limit;
		data["avail_long_amount_limit"] = limit_detail->avail_long_amount_limit;
		data["market"] = limit_detail->market;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryAmountLimitsRsp(data, error, request_id);
};

void OptionApi::OnQuerySplitCombMarginDifferenceRsp(SplitCombMarginDiffDetail* margin_diff_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = margin_diff_detail->account_id;
		data["account_type"] = margin_diff_detail->account_type;
		data["cust_orgid"] = margin_diff_detail->cust_orgid;
		data["cust_branchid"] = margin_diff_detail->cust_branchid;
		data["market"] = margin_diff_detail->market;
		data["contract_id"] = margin_diff_detail->contract_id;
		data["exch_comb_id"] = margin_diff_detail->exch_comb_id;
		data["comb_strategy"] = margin_diff_detail->comb_strategy;
		data["volume"] = margin_diff_detail->volume;
		data["left_leg_pos_margin"] = margin_diff_detail->left_leg_pos_margin;
		data["left_leg_pos_live_margin"] = margin_diff_detail->left_leg_pos_live_margin;
		data["right_leg_pos_margin"] = margin_diff_detail->right_leg_pos_margin;
		data["right_leg_pos_live_margin"] = margin_diff_detail->right_leg_pos_live_margin;
		data["comb_pos_margin"] = margin_diff_detail->comb_pos_margin;
		data["comb_pos_live_margin"] = margin_diff_detail->comb_pos_live_margin;
		data["margin_difference"] = margin_diff_detail->margin_difference;
		data["margin_live_difference"] = margin_diff_detail->margin_live_difference;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQuerySplitCombMarginDifferenceRsp(data, error, request_id);
};

void OptionApi::OnQueryExerciseAppointmentRsp(ExerciseAppointmentDetail* appointment_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = appointment_detail->account_id;
		data["account_type"] = appointment_detail->account_type;
		data["cust_orgid"] = appointment_detail->cust_orgid;
		data["cust_branchid"] = appointment_detail->cust_branchid;
		data["market"] = appointment_detail->market;
		data["contract_id"] = appointment_detail->contract_id;
		data["counter_order_date"] = appointment_detail->counter_order_date;
		data["secuid"] = appointment_detail->secuid;
		data["options_type"] = appointment_detail->options_type;
		data["option_unit"] = appointment_detail->option_unit;
		data["underlying_contract_id"] = appointment_detail->underlying_contract_id;
		data["volume"] = appointment_detail->volume;
		data["exercise_price"] = appointment_detail->exercise_price;
		data["exercise_side"] = appointment_detail->exercise_side;
		data["cover_flag"] = appointment_detail->cover_flag;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryExerciseAppointmentRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryMarginRiskRsp(MarginRiskDetail* detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = detail->account_id;
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = detail->cust_orgid;
		data["cust_branchid"] = detail->cust_branchid;
		data["rt_risk_rate"] = detail->rt_risk_rate;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryMarginRiskRsp(data, error, request_id);
};

void OptionApi::OnQueryOptionMaxOrderVolumeRsp(OptionMaxOrderVolumeDetail* max_order_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = max_order_detail->account_id;
		data["account_type"] = max_order_detail->account_type;
		data["cust_orgid"] = max_order_detail->cust_orgid;
		data["cust_branchid"] = max_order_detail->cust_branchid;
		data["max_volume"] = max_order_detail->max_volume;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionMaxOrderVolumeRsp(data, error, request_id);
};

void OptionApi::OnQueryInquiryStockPositionRsp(PositionDetail* position_detail, ErrorInfo* error_info, int request_id)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = position_detail->account_id;
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = position_detail->cust_orgid;
		data["cust_branchid"] = position_detail->cust_branchid;
		data["symbol"] = position_detail->symbol;
		data["side"] = position_detail->side;
		data["volume"] = position_detail->volume;
		data["avail_volume"] = position_detail->avail_volume;
		data["init_volume"] = position_detail->init_volume;
		data["market_value"] = position_detail->market_value;
		data["today_buy_volume"] = position_detail->today_buy_volume;
		data["today_sell_volume"] = position_detail->today_sell_volume;
		data["secuid"] = position_detail->secuid;
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
		data["name"] = position_detail->name;
		data["currency_type"] = position_detail->currency_type;
		data["security_type_apex"] = position_detail->security_type_apex;
		data["profit_price"] = position_detail->profit_price;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryInquiryStockPositionRsp(data, error, request_id);
};

void OptionApi::OnQueryOptionOrderHistoryRsp(OptionHisOrderDetail* his_order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = his_order_detail->account_id;
		data["account_type"] = his_order_detail->account_type;
		data["cust_orgid"] = his_order_detail->cust_orgid;
		data["cust_branchid"] = his_order_detail->cust_branchid;
		data["trade_date"] = his_order_detail->trade_date;
		data["order_date"] = his_order_detail->order_date;
		data["order_time"] = his_order_detail->order_time;
		data["contract_id"] = his_order_detail->contract_id;
		data["status"] = his_order_detail->status;
		data["market"] = his_order_detail->market;
		data["secuid"] = his_order_detail->secuid;
		data["option_account"] = his_order_detail->option_account;
		data["option_security_type"] = his_order_detail->option_security_type;
		data["option_num"] = his_order_detail->option_num;
		data["option_code"] = his_order_detail->option_code;
		data["option_name"] = his_order_detail->option_name;
		data["comb_num"] = his_order_detail->comb_num;
		data["comb_strategy"] = his_order_detail->comb_strategy;
		data["leg1_num"] = his_order_detail->leg1_num;
		data["leg2_num"] = his_order_detail->leg2_num;
		data["leg3_num"] = his_order_detail->leg3_num;
		data["leg4_num"] = his_order_detail->leg4_num;
		data["currency_type"] = his_order_detail->currency_type;
		data["price"] = his_order_detail->price;
		data["qty"] = his_order_detail->qty;
		data["order_amt"] = his_order_detail->order_amt;
		data["order_frozen_amt"] = his_order_detail->order_frozen_amt;
		data["order_unfrozen_amt"] = his_order_detail->order_unfrozen_amt;
		data["offer_qty"] = his_order_detail->offer_qty;
		data["offer_time"] = his_order_detail->offer_time;
		data["cancel_qty"] = his_order_detail->cancel_qty;
		data["match_qty"] = his_order_detail->match_qty;
		data["match_amt"] = his_order_detail->match_amt;
		data["cancel_flag"] = his_order_detail->cancel_flag;
		data["underlying_code"] = his_order_detail->underlying_code;
		data["underlying_name"] = his_order_detail->underlying_name;
		data["underlying_frozen_qty"] = his_order_detail->underlying_frozen_qty;
		data["underlying_unfrozen_qty"] = his_order_detail->underlying_unfrozen_qty;
		data["underlying_cancel_qty"] = his_order_detail->underlying_cancel_qty;
		data["leg1_side"] = his_order_detail->leg1_side;
		data["leg2_side"] = his_order_detail->leg2_side;
		data["leg3_side"] = his_order_detail->leg3_side;
		data["leg4_side"] = his_order_detail->leg4_side;
		data["leg1_name"] = his_order_detail->leg1_name;
		data["leg2_name"] = his_order_detail->leg2_name;
		data["leg3_name"] = his_order_detail->leg3_name;
		data["leg4_name"] = his_order_detail->leg4_name;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionOrderHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionTradeHistoryRsp(OptionHisTradeDetail* his_trade_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = his_trade_detail->account_id;
		data["account_type"] = his_trade_detail->account_type;
		data["cust_orgid"] = his_trade_detail->cust_orgid;
		data["cust_branchid"] = his_trade_detail->cust_branchid;
		data["trade_date"] = his_trade_detail->trade_date;
		data["trade_time"] = his_trade_detail->trade_time;
		data["order_date"] = his_trade_detail->order_date;
		data["counter_order_id"] = his_trade_detail->counter_order_id;
		data["contract_id"] = his_trade_detail->contract_id;
		data["match_id"] = his_trade_detail->match_id;
		data["market"] = his_trade_detail->market;
		data["secuid"] = his_trade_detail->secuid;
		data["option_account"] = his_trade_detail->option_account;
		data["option_security_type"] = his_trade_detail->option_security_type;
		data["option_security_action"] = his_trade_detail->option_security_action;
		data["option_num"] = his_trade_detail->option_num;
		data["option_name"] = his_trade_detail->option_name;
		data["comb_num"] = his_trade_detail->comb_num;
		data["comb_strategy"] = his_trade_detail->comb_strategy;
		data["leg1_num"] = his_trade_detail->leg1_num;
		data["leg2_num"] = his_trade_detail->leg2_num;
		data["leg3_num"] = his_trade_detail->leg3_num;
		data["leg4_num"] = his_trade_detail->leg4_num;
		data["currency_type"] = his_trade_detail->currency_type;
		data["underlying_code"] = his_trade_detail->underlying_code;
		data["underlying_name"] = his_trade_detail->underlying_name;
		data["price"] = his_trade_detail->price;
		data["qty"] = his_trade_detail->qty;
		data["order_frozen_amt"] = his_trade_detail->order_frozen_amt;
		data["match_price"] = his_trade_detail->match_price;
		data["match_qty"] = his_trade_detail->match_qty;
		data["match_amt"] = his_trade_detail->match_amt;
		data["leg1_side"] = his_trade_detail->leg1_side;
		data["leg2_side"] = his_trade_detail->leg2_side;
		data["leg3_side"] = his_trade_detail->leg3_side;
		data["leg4_side"] = his_trade_detail->leg4_side;
		data["leg1_name"] = his_trade_detail->leg1_name;
		data["leg2_name"] = his_trade_detail->leg2_name;
		data["leg3_name"] = his_trade_detail->leg3_name;
		data["leg4_name"] = his_trade_detail->leg4_name;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionTradeHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryExerciseAppointmentHistoryRsp(HisExerciseAppointmentDetail* his_appointment_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = his_appointment_detail->account_id;
		data["account_type"] = his_appointment_detail->account_type;
		data["cust_orgid"] = his_appointment_detail->cust_orgid;
		data["cust_branchid"] = his_appointment_detail->cust_branchid;
		data["counter_order_date"] = his_appointment_detail->counter_order_date;
		data["currency_type"] = his_appointment_detail->currency_type;
		data["market"] = his_appointment_detail->market;
		data["secuid"] = his_appointment_detail->secuid;
		data["option_account"] = his_appointment_detail->option_account;
		data["option_num"] = his_appointment_detail->option_num;
		data["option_name"] = his_appointment_detail->option_name;
		data["options_type"] = his_appointment_detail->options_type;
		data["underlying_code"] = his_appointment_detail->underlying_code;
		data["cover_flag"] = his_appointment_detail->cover_flag;
		data["volume"] = his_appointment_detail->volume;
		data["underlying_volume"] = his_appointment_detail->underlying_volume;
		data["exercise_amt"] = his_appointment_detail->exercise_amt;
		data["exercise_price"] = his_appointment_detail->exercise_price;
		data["exercise_side"] = his_appointment_detail->exercise_side;
		data["comb_volume"] = his_appointment_detail->comb_volume;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryExerciseAppointmentHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionDeliveryHistoryRsp(OptionHisDeliveryDetail* his_delivery_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = his_delivery_detail->account_id;
		data["account_type"] = his_delivery_detail->account_type;
		data["cust_orgid"] = his_delivery_detail->cust_orgid;
		data["cust_branchid"] = his_delivery_detail->cust_branchid;
		data["settlement_id"] = his_delivery_detail->settlement_id;
		data["settlement_date"] = his_delivery_detail->settlement_date;
		data["counter_order_id"] = his_delivery_detail->counter_order_id;
		data["contract_id"] = his_delivery_detail->contract_id;
		data["market"] = his_delivery_detail->market;
		data["option_account"] = his_delivery_detail->option_account;
		data["option_security_type"] = his_delivery_detail->option_security_type;
		data["option_security_action"] = his_delivery_detail->option_security_action;
		data["option_num"] = his_delivery_detail->option_num;
		data["option_name"] = his_delivery_detail->option_name;
		data["comb_num"] = his_delivery_detail->comb_num;
		data["comb_strategy"] = his_delivery_detail->comb_strategy;
		data["leg1_num"] = his_delivery_detail->leg1_num;
		data["leg2_num"] = his_delivery_detail->leg2_num;
		data["leg3_num"] = his_delivery_detail->leg3_num;
		data["leg4_num"] = his_delivery_detail->leg4_num;
		data["currency_type"] = his_delivery_detail->currency_type;
		data["underlying_code"] = his_delivery_detail->underlying_code;
		data["underlying_name"] = his_delivery_detail->underlying_name;
		data["price"] = his_delivery_detail->price;
		data["qty"] = his_delivery_detail->qty;
		data["order_amt"] = his_delivery_detail->order_amt;
		data["match_price"] = his_delivery_detail->match_price;
		data["match_qty"] = his_delivery_detail->match_qty;
		data["match_amt"] = his_delivery_detail->match_amt;
		data["match_cnt"] = his_delivery_detail->match_cnt;
		data["stamp_duty"] = his_delivery_detail->stamp_duty;
		data["handle_fee"] = his_delivery_detail->handle_fee;
		data["secu_regu_fee"] = his_delivery_detail->secu_regu_fee;
		data["trd_regu_fee"] = his_delivery_detail->trd_regu_fee;
		data["clearing_fee"] = his_delivery_detail->clearing_fee;
		data["exch_trans_fee"] = his_delivery_detail->exch_trans_fee;
		data["trans_fee"] = his_delivery_detail->trans_fee;
		data["exe_trans_fee"] = his_delivery_detail->exe_trans_fee;
		data["paidin_com"] = his_delivery_detail->paidin_com;
		data["settlement_amt"] = his_delivery_detail->settlement_amt;
		data["leg1_side"] = his_delivery_detail->leg1_side;
		data["leg2_side"] = his_delivery_detail->leg2_side;
		data["leg3_side"] = his_delivery_detail->leg3_side;
		data["leg4_side"] = his_delivery_detail->leg4_side;
		data["leg1_name"] = his_delivery_detail->leg1_name;
		data["leg2_name"] = his_delivery_detail->leg2_name;
		data["leg3_name"] = his_delivery_detail->leg3_name;
		data["leg4_name"] = his_delivery_detail->leg4_name;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionDeliveryHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryExerciseDeliveryHistoryRsp(HisExerciseDeliveryyDetail* exercise_delivery_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = exercise_delivery_detail->account_id;
		data["account_type"] = exercise_delivery_detail->account_type;
		data["cust_orgid"] = exercise_delivery_detail->cust_orgid;
		data["cust_branchid"] = exercise_delivery_detail->cust_branchid;
		data["serial_number"] = exercise_delivery_detail->serial_number;
		data["settlement_date"] = exercise_delivery_detail->settlement_date;
		data["occur_time"] = exercise_delivery_detail->occur_time;
		data["market"] = exercise_delivery_detail->market;
		data["currency_type"] = exercise_delivery_detail->currency_type;
		data["option_account"] = exercise_delivery_detail->option_account;
		data["option_security_type"] = exercise_delivery_detail->option_security_type;
		data["option_security_action"] = exercise_delivery_detail->option_security_action;
		data["biz_amt"] = exercise_delivery_detail->biz_amt;
		data["fund_bln"] = exercise_delivery_detail->fund_bln;
		data["fund_avl"] = exercise_delivery_detail->fund_avl;
		data["frozen_margin"] = exercise_delivery_detail->frozen_margin;
		data["unfrozen_margin"] = exercise_delivery_detail->unfrozen_margin;
		data["underlying_code"] = exercise_delivery_detail->underlying_code;
		data["underlying_volume"] = exercise_delivery_detail->underlying_volume;
		data["stamp_duty"] = exercise_delivery_detail->stamp_duty;
		data["handle_fee"] = exercise_delivery_detail->handle_fee;
		data["secu_regu_fee"] = exercise_delivery_detail->secu_regu_fee;
		data["trd_regu_fee"] = exercise_delivery_detail->trd_regu_fee;
		data["clearing_fee"] = exercise_delivery_detail->clearing_fee;
		data["venture_fee"] = exercise_delivery_detail->venture_fee;
		data["trans_fee"] = exercise_delivery_detail->trans_fee;
		data["exe_trans_fee"] = exercise_delivery_detail->exe_trans_fee;
		data["paidin_com"] = exercise_delivery_detail->paidin_com;
		data["fee_amt"] = exercise_delivery_detail->fee_amt;
		data["volume"] = exercise_delivery_detail->volume;
		data["comb_volume"] = exercise_delivery_detail->comb_volume;
		data["biz_code"] = exercise_delivery_detail->biz_code;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryExerciseDeliveryHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionContractAssetHistoryRsp(OptionHisContractAssetDetail* contract_asset_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = contract_asset_detail->account_id;
		data["account_type"] = contract_asset_detail->account_type;
		data["cust_orgid"] = contract_asset_detail->cust_orgid;
		data["cust_branchid"] = contract_asset_detail->cust_branchid;
		data["occur_date"] = contract_asset_detail->occur_date;
		data["market"] = contract_asset_detail->market;
		data["currency_type"] = contract_asset_detail->currency_type;
		data["option_account"] = contract_asset_detail->option_account;
		data["option_num"] = contract_asset_detail->option_num;
		data["option_code"] = contract_asset_detail->option_code;
		data["option_name"] = contract_asset_detail->option_name;
		data["options_type"] = contract_asset_detail->options_type;
		data["option_side"] = contract_asset_detail->option_side;
		data["cover_flag"] = contract_asset_detail->cover_flag;
		data["underlying_code"] = contract_asset_detail->underlying_code;
		data["option_prebln"] = contract_asset_detail->option_prebln;
		data["option_bln"] = contract_asset_detail->option_bln;
		data["option_avl"] = contract_asset_detail->option_avl;
		data["option_margin"] = contract_asset_detail->option_margin;
		data["comb_volume"] = contract_asset_detail->comb_volume;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionContractAssetHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionDeliveryNettingHistoryRsp(OptionHisDeliveryNettingDetail* delivery_netting_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = delivery_netting_detail->account_id;
		data["account_type"] = delivery_netting_detail->account_type;
		data["cust_orgid"] = delivery_netting_detail->cust_orgid;
		data["cust_branchid"] = delivery_netting_detail->cust_branchid;
		data["settlement_date"] = delivery_netting_detail->settlement_date;
		data["market"] = delivery_netting_detail->market;
		data["option_account"] = delivery_netting_detail->option_account;
		data["stamp_duty"] = delivery_netting_detail->stamp_duty;
		data["handle_fee"] = delivery_netting_detail->handle_fee;
		data["secu_regu_fee"] = delivery_netting_detail->secu_regu_fee;
		data["trd_regu_fee"] = delivery_netting_detail->trd_regu_fee;
		data["clearing_fee"] = delivery_netting_detail->clearing_fee;
		data["exch_trans_fee"] = delivery_netting_detail->exch_trans_fee;
		data["trans_fee"] = delivery_netting_detail->trans_fee;
		data["exe_trans_fee"] = delivery_netting_detail->exe_trans_fee;
		data["paidin_com"] = delivery_netting_detail->paidin_com;
		data["settlement_amt"] = delivery_netting_detail->settlement_amt;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionDeliveryNettingHistoryRsp(data, error, request_id, is_last);
};

void OptionApi::OnQueryOptionCombPositionHistoryRsp(OptionHisCombPositionDetail* comb_position_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = comb_position_detail->account_id;
		data["account_type"] = comb_position_detail->account_type;
		data["cust_orgid"] = comb_position_detail->cust_orgid;
		data["cust_branchid"] = comb_position_detail->cust_branchid;
		data["occur_date"] = comb_position_detail->occur_date;
		data["market"] = comb_position_detail->market;
		data["currency_type"] = comb_position_detail->currency_type;
		data["secuid"] = comb_position_detail->secuid;
		data["option_account"] = comb_position_detail->option_account;
		data["comb_num"] = comb_position_detail->comb_num;
		data["comb_strategy"] = comb_position_detail->comb_strategy;
		data["comb_strategy_name"] = comb_position_detail->comb_strategy_name;
		data["comb_prebln"] = comb_position_detail->comb_prebln;
		data["comb_bln"] = comb_position_detail->comb_bln;
		data["comb_avl"] = comb_position_detail->comb_avl;
		data["comb_trade_frz"] = comb_position_detail->comb_trade_frz;
		data["comb_trade_ufz"] = comb_position_detail->comb_trade_ufz;
		data["comb_trade_otd"] = comb_position_detail->comb_trade_otd;
		data["comb_trade_bln"] = comb_position_detail->comb_trade_bln;
		data["comb_clearing_frz"] = comb_position_detail->comb_clearing_frz;
		data["comb_clearing_ufz"] = comb_position_detail->comb_clearing_ufz;
		data["comb_clearing_otd"] = comb_position_detail->comb_clearing_otd;
		data["comb_margin_unit"] = comb_position_detail->comb_margin_unit;
		data["comb_margin"] = comb_position_detail->comb_margin;
		data["leg_count"] = comb_position_detail->leg_count;
		data["leg1_num"] = comb_position_detail->leg1_num;
		data["leg1_type"] = comb_position_detail->leg1_type;
		data["leg1_side"] = comb_position_detail->leg1_side;
		data["leg1_position"] = comb_position_detail->leg1_position;
		data["leg2_num"] = comb_position_detail->leg2_num;
		data["leg2_type"] = comb_position_detail->leg2_type;
		data["leg2_side"] = comb_position_detail->leg2_side;
		data["leg2_position"] = comb_position_detail->leg2_position;
		data["leg3_num"] = comb_position_detail->leg3_num;
		data["leg3_type"] = comb_position_detail->leg3_type;
		data["leg3_side"] = comb_position_detail->leg3_side;
		data["leg3_position"] = comb_position_detail->leg3_position;
		data["leg4_num"] = comb_position_detail->leg4_num;
		data["leg4_type"] = comb_position_detail->leg4_type;
		data["leg4_side"] = comb_position_detail->leg4_side;
		data["leg4_position"] = comb_position_detail->leg4_position;
		data["leg1_name"] = comb_position_detail->leg1_name;
		data["leg2_name"] = comb_position_detail->leg2_name;
		data["leg3_name"] = comb_position_detail->leg3_name;
		data["leg4_name"] = comb_position_detail->leg4_name;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionCombPositionHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionSettlementHistoryRsp(OptionHisSettlementDetail* his_settlement_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = his_settlement_detail->account_id;
		data["account_type"] = his_settlement_detail->account_type;
		data["cust_orgid"] = his_settlement_detail->cust_orgid;
		data["cust_branchid"] = his_settlement_detail->cust_branchid;
		data["settlement_date"] = his_settlement_detail->settlement_date;
		data["trade_date"] = his_settlement_detail->trade_date;
		data["trade_time"] = his_settlement_detail->trade_time;
		data["counter_order_id"] = his_settlement_detail->counter_order_id;
		data["market"] = his_settlement_detail->market;
		data["currency_type"] = his_settlement_detail->currency_type;
		data["option_account"] = his_settlement_detail->option_account;
		data["option_security_type"] = his_settlement_detail->option_security_type;
		data["option_security_action"] = his_settlement_detail->option_security_action;
		data["option_num"] = his_settlement_detail->option_num;
		data["option_name"] = his_settlement_detail->option_name;
		data["option_side"] = his_settlement_detail->option_side;
		data["match_price"] = his_settlement_detail->match_price;
		data["match_qty"] = his_settlement_detail->match_qty;
		data["match_amt"] = his_settlement_detail->match_amt;
		data["option_bln"] = his_settlement_detail->option_bln;
		data["handle_fee"] = his_settlement_detail->handle_fee;
		data["clearing_fee"] = his_settlement_detail->clearing_fee;
		data["trans_fee"] = his_settlement_detail->trans_fee;
		data["exe_trans_fee"] = his_settlement_detail->exe_trans_fee;
		data["paidin_com"] = his_settlement_detail->paidin_com;
		data["fee_amt"] = his_settlement_detail->fee_amt;
		data["biz_amt"] = his_settlement_detail->biz_amt;
		data["fund_bln"] = his_settlement_detail->fund_bln;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionSettlementHistoryRsp(data, error, request_id, is_last, string(pos_str));
};

void OptionApi::OnQueryOptionCombStrategyFileRsp(OptionCombStrategyFileDetail* comb_strategy_file_detail, ErrorInfo* error_info, int request_id, bool is_last)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = comb_strategy_file_detail->account_id;
		data["account_type"] = comb_strategy_file_detail->account_type;
		data["cust_orgid"] = comb_strategy_file_detail->cust_orgid;
		data["cust_branchid"] = comb_strategy_file_detail->cust_branchid;
		data["market"] = comb_strategy_file_detail->market;
		data["comb_strategy"] = comb_strategy_file_detail->comb_strategy;
		data["comb_strategy_name"] = comb_strategy_file_detail->comb_strategy_name;
		data["same_expdate"] = comb_strategy_file_detail->same_expdate;
		data["same_underlying"] = comb_strategy_file_detail->same_underlying;
		data["auto_split_day"] = comb_strategy_file_detail->auto_split_day;
		data["opt_underlying_codes"] = comb_strategy_file_detail->opt_underlying_codes;
		data["leg_count"] = comb_strategy_file_detail->leg_count;
		data["leg1_type"] = comb_strategy_file_detail->leg1_type;
		data["leg1_side"] = comb_strategy_file_detail->leg1_side;
		data["leg1_exeprc_seq"] = comb_strategy_file_detail->leg1_exeprc_seq;
		data["leg1_expdate_seq"] = comb_strategy_file_detail->leg1_expdate_seq;
		data["leg1_position"] = comb_strategy_file_detail->leg1_position;
		data["leg2_type"] = comb_strategy_file_detail->leg2_type;
		data["leg2_side"] = comb_strategy_file_detail->leg2_side;
		data["leg2_exeprc_seq"] = comb_strategy_file_detail->leg2_exeprc_seq;
		data["leg2_expdate_seq"] = comb_strategy_file_detail->leg2_expdate_seq;
		data["leg2_position"] = comb_strategy_file_detail->leg2_position;
		data["leg3_type"] = comb_strategy_file_detail->leg3_type;
		data["leg3_side"] = comb_strategy_file_detail->leg3_side;
		data["leg3_exeprc_seq"] = comb_strategy_file_detail->leg3_exeprc_seq;
		data["leg3_expdate_seq"] = comb_strategy_file_detail->leg3_expdate_seq;
		data["leg3_position"] = comb_strategy_file_detail->leg3_position;
		data["leg4_type"] = comb_strategy_file_detail->leg4_type;
		data["leg4_side"] = comb_strategy_file_detail->leg4_side;
		data["leg4_exeprc_seq"] = comb_strategy_file_detail->leg4_exeprc_seq;
		data["leg4_expdate_seq"] = comb_strategy_file_detail->leg4_expdate_seq;
		data["leg4_position"] = comb_strategy_file_detail->leg4_position;
	}
	dict error;
	{
		error["err_code"] = error_info->err_code;
		error["err_msg"] = toUtf(error_info->err_msg);
	}
	this->onQueryOptionCombStrategyFileRsp(data, error, request_id, is_last);
};


///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void OptionApi::setLogConfig(string log_path)
{
	this->api->SetLogConfig(log_path.c_str(), LogLevel_Info);
}

void OptionApi::createTraderApi()
{
	this->api = OptionTraderApi::CreateOptionTraderApi();
	this->api->RegisterSpi(this);
	this->active = true;
};

void OptionApi::release()
{
	this->api->Release();
};


int OptionApi::exit()
{
	this->api->Release();
	this->api = NULL;
	return 1;
};

string OptionApi::getApiVersion()
{
	string i = this->api->GetApiVersion();
	return i;
}

void OptionApi::setCriticalMsgLog(bool enable)
{
	this->api->SetCriticalMsgLog(enable);
};

void OptionApi::setLoginRetryCount(int login_retry_count)
{
	this->api->SetLoginRetryCount(login_retry_count);
};

void OptionApi::setLoginRetryInterval(int login_retry_interval)
{
	this->api->SetLoginRetryInterval(login_retry_interval);
};

void OptionApi::setReconnectConfig(int max_retry_count, int min_interval, int max_interval)
{
	this->api->SetReconnectConfig(max_retry_count, min_interval, max_interval);

};

dict OptionApi::getApiLastError()
{
	ErrorInfo* d = this->api->GetApiLastError();

	dict data;
	data["err_code"] = d->err_code;
	data["err_msg"] = toUtf(d->err_msg);
	return data;
};

int OptionApi::getCounterType()
{
	int i = this->api->GetCounterType();
	return i;
};

int OptionApi::login(const dict& req)
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

pybind11::list OptionApi::getSecuidInfo()
{
	SecuidInfo secuids[10];

	int count;
	int i = this->api->GetSecuidInfo(secuids, &count);

	pybind11::list info;

	for (int i = 0; i < count; i++)
	{
		SecuidInfo secuid = secuids[i];

		dict data;
		data["market"] = secuid.market;
		data["secuid"] = secuid.secuid;
		data["fund_id"] = secuid.fund_id;
		data["account_type"] = secuid.account_type;
		data["account_status"] = secuid.account_status;
		data["account_class"] = secuid.account_class;
		data["account_rights"] = secuid.account_rights;
		data["account_hgtright"] = secuid.account_hgtright;

		info.append(data);

	}
	return info;
};

int OptionApi::getApiLocalAddr(const dict& req)
{
	IpAddr myreq = IpAddr();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ip", myreq.ip);
	getInt(req, "port", &myreq.port);
	int i = this->api->GetApiLocalAddr(&myreq);
	return i;
};

int OptionApi::order(const dict& req, int request_id)
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

int OptionApi::batchOrder(const dict& req, int count, int request_id)
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

int OptionApi::cancelOrder(const dict& req, int request_id)
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

int OptionApi::batchCancelOrder(const dict& req, int count, int request_id)
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

int OptionApi::exercise(const dict& req, int request_id)
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

int OptionApi::cancelExercise(const dict& req, int request_id)
{
	CancelExerciseReq myreq = CancelExerciseReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "cl_order_id", myreq.cl_order_id);
	getString(req, "cl_cancel_id", myreq.cl_cancel_id);
	int i = this->api->CancelExercise(&myreq, request_id);
	return i;
};

int OptionApi::queryOrder(const dict& req, int request_id)
{
	QryByOrderIdReq myreq = QryByOrderIdReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "order_id", myreq.order_id);
	getString(req, "market", myreq.market);
	int i = this->api->QueryOrder(&myreq, request_id);
	return i;
};

int OptionApi::queryOrderByCode(const dict& req, int request_id)
{
	QryOrderByCodeReq myreq = QryOrderByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryOrderByCode(&myreq, request_id);
	return i;
};

int OptionApi::queryOrders(const dict& req, int request_id)
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

int OptionApi::queryTradeByCode(const dict& req, int request_id)
{
	QryTradeByCodeReq myreq = QryTradeByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	int i = this->api->QueryTradeByCode(&myreq, request_id);
	return i;
};

int OptionApi::queryTrades(const dict& req, int request_id)
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

int OptionApi::queryPosition(const dict& req, int request_id)
{
	QryByCodeReq myreq = QryByCodeReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "symbol", myreq.symbol);
	int i = this->api->QueryPosition(&myreq, request_id);
	return i;
};

int OptionApi::queryPositions(const dict& req, int request_id)
{
	QryPositionsReq myreq = QryPositionsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "pos_str", myreq.pos_str);
	getInt32_t(req, "query_num", &myreq.query_num);
	getString(req, "market", myreq.market);
	int i = this->api->QueryPositions(&myreq, request_id);
	return i;
};

int OptionApi::queryCash(const dict& req, int request_id)
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

int OptionApi::transferFundInAndOut(const dict& req, int request_id)
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

int OptionApi::queryExercises(const dict& req, int request_id)
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

int OptionApi::transferStock(const dict& req, int request_id)
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

int OptionApi::lockOrder(const dict& req, int request_id)
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

int OptionApi::queryLockOrders(const dict& req, int request_id)
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

int OptionApi::combOrder(const dict& req, int request_id)
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

int OptionApi::combExercise(const dict& req, int request_id)
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

int OptionApi::cancelCombExercise(const dict& req, int request_id)
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

int OptionApi::queryCombOrders(const dict& req, int request_id)
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

int OptionApi::queryCombExercises(const dict& req, int request_id)
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

int OptionApi::doMicroServiceReq(const dict& req, int request_id)
{
	MicroServiceReq myreq = MicroServiceReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "account_id", myreq.account_id);
	getString(req, "cust_orgid", myreq.cust_orgid);
	getString(req, "cust_branchid", myreq.cust_branchid);
	getString(req, "function_id", myreq.function_id);
	getString(req, "tar_sys", myreq.tar_sys);
	getInt32_t(req, "request_len", &myreq.request_len);

	char buf[4096];
	getString(req, "request_content", buf);
	myreq.request_content = buf;

	int i = this->api->DoMicroServiceReq(&myreq, request_id);
	return i;
};

int OptionApi::queryPositionLimits(int request_id, string symbol)
{
	int i = this->api->QueryPositionLimits(request_id, symbol.c_str());
	return i;
};

int OptionApi::queryAmountLimits(const dict& req, int request_id)
{
	QryAmountLimitsReq myreq = QryAmountLimitsReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	int i = this->api->QueryAmountLimits(&myreq, request_id);
	return i;
};

int OptionApi::querySplitCombMarginDifference(const dict& req, int request_id)
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

int OptionApi::queryExerciseAppointment(const dict& req, int request_id)
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

int OptionApi::queryOptionMaxOrderVolume(const dict& req, int request_id)
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

int OptionApi::queryOptionOrderHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionTradeHistory(const dict& req, int request_id)
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

int OptionApi::queryExerciseAppointmentHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionDeliveryHistory(const dict& req, int request_id)
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

int OptionApi::queryExerciseDeliveryHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionContractAssetHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionDeliveryNettingHistory(const dict& req, int request_id)
{
	QryOptionHisDeliveryNettingReq myreq = QryOptionHisDeliveryNettingReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt32_t(req, "begin_date", &myreq.begin_date);
	getInt32_t(req, "end_date", &myreq.end_date);
	int i = this->api->QueryOptionDeliveryNettingHistory(&myreq, request_id);
	return i;
};

int OptionApi::queryOptionCombPositionHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionSettlementHistory(const dict& req, int request_id)
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

int OptionApi::queryOptionCombStrategyFile(const dict& req, int request_id)
{
	QryOptionCombStrategyFileReq myreq = QryOptionCombStrategyFileReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "market", myreq.market);
	getInt16_t(req, "comb_strategy", &myreq.comb_strategy);
	int i = this->api->QueryOptionCombStrategyFile(&myreq, request_id);
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyOptionApi : public OptionApi
{
public:
	using OptionApi::OptionApi;

	void onDisconnect() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onDisconnect);
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
			PYBIND11_OVERLOAD(void, OptionApi, onError, error, request_id);
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
			PYBIND11_OVERLOAD(void, OptionApi, onRiskNotify, data);
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
			PYBIND11_OVERLOAD(void, OptionApi, onFailBackNotify, data);
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
			PYBIND11_OVERLOAD(void, OptionApi, onLogin, data, error);
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
			PYBIND11_OVERLOAD(void, OptionApi, onTradeReport, data);
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
			PYBIND11_OVERLOAD(void, OptionApi, onOrderStatus, data);
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
			PYBIND11_OVERLOAD(void, OptionApi, onOrderRsp, data, error, request_id, last);
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
			PYBIND11_OVERLOAD(void, OptionApi, onCancelRsp, data, error, request_id, last);
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
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOrderRsp, data, error, request_id, last, pos_str);
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
			PYBIND11_OVERLOAD(void, OptionApi, onQueryTradeRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPositionRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryPositionRsp, data, error, request_id, last);
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
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCashRsp, data, error, request_id);
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
			PYBIND11_OVERLOAD(void, OptionApi, onQueryJZJYAvailFundRsp, avail_balance, error, request_id);
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
			PYBIND11_OVERLOAD(void, OptionApi, onTransferFundInAndOutRsp, transfer_value, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onExerciseRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onExerciseRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCancelExerciseRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCancelExerciseRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onExerciseStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onExerciseStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryExerciseRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryContractInfoRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryContractInfoRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryStockPositionRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryStockPositionRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onTransferStockStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onTransferStockStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onTransferStockRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onTransferStockRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryTransferStockRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryTransferStockRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onLockOrderStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onLockOrderStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onLockOrderRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onLockOrderRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryLockOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryLockOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryLockPositionRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryLockPositionRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCombOrderStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCombOrderStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCombOrderRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCombOrderRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCombExerciseStatus(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCombExerciseStatus, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCombExerciseRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCombExerciseRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onCancelCombExerciseRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onCancelCombExerciseRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCombOrderRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCombOrderRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCombExerciseRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCombExerciseRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCombPositionRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCombPositionRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCombContractInfoRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCombContractInfoRsp, data, error, request_id, last);
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
			PYBIND11_OVERLOAD(void, OptionApi, onQueryTransferFundHistoryRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryCombPositionSubDetailRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryCombPositionSubDetailRsp, data, error, request_id, last);
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
			PYBIND11_OVERLOAD(void, OptionApi, onMicroServiceRsp, data, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryPositionLimitsRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryPositionLimitsRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryAmountLimitsRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryAmountLimitsRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQuerySplitCombMarginDifferenceRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQuerySplitCombMarginDifferenceRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryExerciseAppointmentRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseAppointmentRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryMarginRiskRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryMarginRiskRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionMaxOrderVolumeRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionMaxOrderVolumeRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryInquiryStockPositionRsp(const dict& data, const dict& error, int request_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryInquiryStockPositionRsp, data, error, request_id);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionOrderHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionOrderHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionTradeHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionTradeHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryExerciseAppointmentHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseAppointmentHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionDeliveryHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionDeliveryHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryExerciseDeliveryHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryExerciseDeliveryHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionContractAssetHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionContractAssetHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionDeliveryNettingHistoryRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionDeliveryNettingHistoryRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionCombPositionHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionCombPositionHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionSettlementHistoryRsp(const dict& data, const dict& error, int request_id, bool last, string pos_str) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionSettlementHistoryRsp, data, error, request_id, last, pos_str);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onQueryOptionCombStrategyFileRsp(const dict& data, const dict& error, int request_id, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, OptionApi, onQueryOptionCombStrategyFileRsp, data, error, request_id, last);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};


PYBIND11_MODULE(vnhfttd, m)
{
	class_<OptionApi, PyOptionApi> OptionApi(m, "OptionApi", module_local());
	OptionApi
		.def(init<>())
		.def("createTraderApi", &OptionApi::createTraderApi)
		.def("release", &OptionApi::release)
		.def("exit", &OptionApi::exit)
		.def("getApiVersion", &OptionApi::getApiVersion)
		.def("setLogConfig", &OptionApi::setLogConfig)
		.def("setCriticalMsgLog", &OptionApi::setCriticalMsgLog)
		.def("setLoginRetryCount", &OptionApi::setLoginRetryCount)
		.def("setLoginRetryInterval", &OptionApi::setLoginRetryInterval)
		.def("setReconnectConfig", &OptionApi::setReconnectConfig)
		.def("getApiLastError", &OptionApi::getApiLastError)

		.def("login", &OptionApi::login)
		.def("getCounterType", &OptionApi::getCounterType)
		.def("getSecuidInfo", &OptionApi::getSecuidInfo)
		.def("getApiLocalAddr", &OptionApi::getApiLocalAddr)
		.def("order", &OptionApi::order)
		.def("batchOrder", &OptionApi::batchOrder)
		.def("cancelOrder", &OptionApi::cancelOrder)
		.def("batchCancelOrder", &OptionApi::batchCancelOrder)
		.def("exercise", &OptionApi::exercise)
		.def("cancelExercise", &OptionApi::cancelExercise)
		.def("queryOrder", &OptionApi::queryOrder)
		.def("queryOrderByCode", &OptionApi::queryOrderByCode)
		.def("queryOrders", &OptionApi::queryOrders)
		.def("queryTradeByCode", &OptionApi::queryTradeByCode)
		.def("queryTrades", &OptionApi::queryTrades)
		.def("queryPosition", &OptionApi::queryPosition)
		.def("queryPositions", &OptionApi::queryPositions)
		.def("queryCash", &OptionApi::queryCash)
		.def("queryJZJYAvailFund", &OptionApi::queryJZJYAvailFund)
		.def("transferFundInAndOut", &OptionApi::transferFundInAndOut)
		.def("queryExercise", &OptionApi::queryExercise)
		.def("queryExercises", &OptionApi::queryExercises)
		.def("queryContractInfo", &OptionApi::queryContractInfo)
		.def("queryStockPositions", &OptionApi::queryStockPositions)
		.def("transferStock", &OptionApi::transferStock)
		.def("queryTransferStocks", &OptionApi::queryTransferStocks)
		.def("lockOrder", &OptionApi::lockOrder)
		.def("queryLockOrder", &OptionApi::queryLockOrder)
		.def("queryLockOrders", &OptionApi::queryLockOrders)
		.def("queryLockPositions", &OptionApi::queryLockPositions)
		.def("combOrder", &OptionApi::combOrder)
		.def("combExercise", &OptionApi::combExercise)
		.def("cancelCombExercise", &OptionApi::cancelCombExercise)
		.def("queryCombOrder", &OptionApi::queryCombOrder)
		.def("queryCombOrderByCode", &OptionApi::queryCombOrderByCode)
		.def("queryCombOrders", &OptionApi::queryCombOrders)
		.def("queryCombExercise", &OptionApi::queryCombExercise)
		.def("queryCombExercises", &OptionApi::queryCombExercises)
		.def("queryCombPositions", &OptionApi::queryCombPositions)
		.def("queryCombContractInfo", &OptionApi::queryCombContractInfo)
		.def("queryTransferFundHistory", &OptionApi::queryTransferFundHistory)
		.def("queryCombPositionSubDetails", &OptionApi::queryCombPositionSubDetails)
		.def("doMicroServiceReq", &OptionApi::doMicroServiceReq)
		.def("queryPositionLimits", &OptionApi::queryPositionLimits)
		.def("queryAmountLimits", &OptionApi::queryAmountLimits)
		.def("querySplitCombMarginDifference", &OptionApi::querySplitCombMarginDifference)
		.def("queryExerciseAppointment", &OptionApi::queryExerciseAppointment)
		.def("queryMarginRisk", &OptionApi::queryMarginRisk)
		.def("queryOptionMaxOrderVolume", &OptionApi::queryOptionMaxOrderVolume)
		.def("queryInquiryStockPosition", &OptionApi::queryInquiryStockPosition)
		.def("queryOptionOrderHistory", &OptionApi::queryOptionOrderHistory)
		.def("queryOptionTradeHistory", &OptionApi::queryOptionTradeHistory)
		.def("queryExerciseAppointmentHistory", &OptionApi::queryExerciseAppointmentHistory)
		.def("queryOptionDeliveryHistory", &OptionApi::queryOptionDeliveryHistory)
		.def("queryExerciseDeliveryHistory", &OptionApi::queryExerciseDeliveryHistory)
		.def("queryOptionContractAssetHistory", &OptionApi::queryOptionContractAssetHistory)
		.def("queryOptionDeliveryNettingHistory", &OptionApi::queryOptionDeliveryNettingHistory)
		.def("queryOptionCombPositionHistory", &OptionApi::queryOptionCombPositionHistory)
		.def("queryOptionSettlementHistory", &OptionApi::queryOptionSettlementHistory)
		.def("queryOptionCombStrategyFile", &OptionApi::queryOptionCombStrategyFile)

		.def("onDisconnect", &OptionApi::onDisconnect)
		.def("onError", &OptionApi::onError)
		.def("onRiskNotify", &OptionApi::onRiskNotify)
		.def("onFailBackNotify", &OptionApi::onFailBackNotify)
		.def("onLogin", &OptionApi::onLogin)
		.def("onTradeReport", &OptionApi::onTradeReport)
		.def("onOrderStatus", &OptionApi::onOrderStatus)
		.def("onOrderRsp", &OptionApi::onOrderRsp)
		.def("onCancelRsp", &OptionApi::onCancelRsp)
		.def("onQueryOrderRsp", &OptionApi::onQueryOrderRsp)
		.def("onQueryTradeRsp", &OptionApi::onQueryTradeRsp)
		.def("onQueryPositionRsp", &OptionApi::onQueryPositionRsp)
		.def("onQueryCashRsp", &OptionApi::onQueryCashRsp)
		.def("onQueryJZJYAvailFundRsp", &OptionApi::onQueryJZJYAvailFundRsp)
		.def("onTransferFundInAndOutRsp", &OptionApi::onTransferFundInAndOutRsp)
		.def("onExerciseRsp", &OptionApi::onExerciseRsp)
		.def("onCancelExerciseRsp", &OptionApi::onCancelExerciseRsp)
		.def("onExerciseStatus", &OptionApi::onExerciseStatus)
		.def("onQueryExerciseRsp", &OptionApi::onQueryExerciseRsp)
		.def("onQueryContractInfoRsp", &OptionApi::onQueryContractInfoRsp)
		.def("onQueryStockPositionRsp", &OptionApi::onQueryStockPositionRsp)
		.def("onTransferStockStatus", &OptionApi::onTransferStockStatus)
		.def("onTransferStockRsp", &OptionApi::onTransferStockRsp)
		.def("onQueryTransferStockRsp", &OptionApi::onQueryTransferStockRsp)
		.def("onLockOrderStatus", &OptionApi::onLockOrderStatus)
		.def("onLockOrderRsp", &OptionApi::onLockOrderRsp)
		.def("onQueryLockOrderRsp", &OptionApi::onQueryLockOrderRsp)
		.def("onQueryLockPositionRsp", &OptionApi::onQueryLockPositionRsp)
		.def("onCombOrderStatus", &OptionApi::onCombOrderStatus)
		.def("onCombOrderRsp", &OptionApi::onCombOrderRsp)
		.def("onCombExerciseStatus", &OptionApi::onCombExerciseStatus)
		.def("onCombExerciseRsp", &OptionApi::onCombExerciseRsp)
		.def("onCancelCombExerciseRsp", &OptionApi::onCancelCombExerciseRsp)
		.def("onQueryCombOrderRsp", &OptionApi::onQueryCombOrderRsp)
		.def("onQueryCombExerciseRsp", &OptionApi::onQueryCombExerciseRsp)
		.def("onQueryCombPositionRsp", &OptionApi::onQueryCombPositionRsp)
		.def("onQueryCombContractInfoRsp", &OptionApi::onQueryCombContractInfoRsp)
		.def("onQueryTransferFundHistoryRsp", &OptionApi::onQueryTransferFundHistoryRsp)
		.def("onQueryCombPositionSubDetailRsp", &OptionApi::onQueryCombPositionSubDetailRsp)
		.def("onMicroServiceRsp", &OptionApi::onMicroServiceRsp)
		.def("onQueryPositionLimitsRsp", &OptionApi::onQueryPositionLimitsRsp)
		.def("onQueryAmountLimitsRsp", &OptionApi::onQueryAmountLimitsRsp)
		.def("onQuerySplitCombMarginDifferenceRsp", &OptionApi::onQuerySplitCombMarginDifferenceRsp)
		.def("onQueryExerciseAppointmentRsp", &OptionApi::onQueryExerciseAppointmentRsp)
		.def("onQueryMarginRiskRsp", &OptionApi::onQueryMarginRiskRsp)
		.def("onQueryOptionMaxOrderVolumeRsp", &OptionApi::onQueryOptionMaxOrderVolumeRsp)
		.def("onQueryInquiryStockPositionRsp", &OptionApi::onQueryInquiryStockPositionRsp)
		.def("onQueryOptionOrderHistoryRsp", &OptionApi::onQueryOptionOrderHistoryRsp)
		.def("onQueryOptionTradeHistoryRsp", &OptionApi::onQueryOptionTradeHistoryRsp)
		.def("onQueryExerciseAppointmentHistoryRsp", &OptionApi::onQueryExerciseAppointmentHistoryRsp)
		.def("onQueryOptionDeliveryHistoryRsp", &OptionApi::onQueryOptionDeliveryHistoryRsp)
		.def("onQueryExerciseDeliveryHistoryRsp", &OptionApi::onQueryExerciseDeliveryHistoryRsp)
		.def("onQueryOptionContractAssetHistoryRsp", &OptionApi::onQueryOptionContractAssetHistoryRsp)
		.def("onQueryOptionDeliveryNettingHistoryRsp", &OptionApi::onQueryOptionDeliveryNettingHistoryRsp)
		.def("onQueryOptionCombPositionHistoryRsp", &OptionApi::onQueryOptionCombPositionHistoryRsp)
		.def("onQueryOptionSettlementHistoryRsp", &OptionApi::onQueryOptionSettlementHistoryRsp)
		.def("onQueryOptionCombStrategyFileRsp", &OptionApi::onQueryOptionCombStrategyFileRsp)
		;
}
