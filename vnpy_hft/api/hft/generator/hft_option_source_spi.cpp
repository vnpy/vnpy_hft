void OptionApi::OnDisconnect() 
{
	gil_scoped_acquire acquire;
	this->onDisconnect();
};

void OptionApi::OnError(ErrorInfo* error_info, int request_id = 0) 
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
		data["secuid"] = toUtf(risk_notify->secuid);
		data["alarm_score"] = toUtf(risk_notify->alarm_score);
		data["alarm_status"] = toUtf(risk_notify->alarm_status);
		data["alarm_rule"] = toUtf(risk_notify->alarm_rule);
		data["alarm_time"] = toUtf(risk_notify->alarm_time);
		data["alarm_msg"] = toUtf(risk_notify->alarm_msg);
	}
	this->onRiskNotify(data);
};

void OptionApi::OnFailBackNotify(FailBackNotify* failback_notify) 
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

void OptionApi::OnLogin(LoginRsp* rsp, ErrorInfo* error_info) 
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
		data["secuid_array"] = rsp->secuid_array;
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
		data["ext_secuid_array"] = rsp->ext_secuid_array;
		data["reg_branchid"] = toUtf(rsp->reg_branchid);
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

void OptionApi::OnOrderStatus(OrderDetail* order_detail) 
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

void OptionApi::OnOrderRsp(OrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last) 
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

void OptionApi::OnCancelRsp(CancelRsp* cancel_rsp, ErrorInfo* error_info, int request_id, bool is_last) 
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

void OptionApi::OnQueryOrderRsp(OrderDetail* order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) 
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

void OptionApi::OnQueryTradeRsp(TradeDetail* trade_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) 
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

void OptionApi::OnQueryPositionRsp(OptionPositionDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last) 
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
		data["secuid"] = toUtf(position_detail->secuid);
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
		data["account_id"] = toUtf(cash_detail->account_id);
		data["account_type"] = cash_detail->account_type;
		data["cust_orgid"] = toUtf(cash_detail->cust_orgid);
		data["cust_branchid"] = toUtf(cash_detail->cust_branchid);
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
		data["account_id"] = toUtf(exercise_rsp->account_id);
		data["account_type"] = exercise_rsp->account_type;
		data["cust_orgid"] = toUtf(exercise_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(exercise_rsp->cust_branchid);
		data["cl_order_id"] = toUtf(exercise_rsp->cl_order_id);
		data["order_id"] = toUtf(exercise_rsp->order_id);
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
		data["account_id"] = toUtf(cancel_rsp->account_id);
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = toUtf(cancel_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(cancel_rsp->cust_branchid);
		data["order_id"] = toUtf(cancel_rsp->order_id);
		data["cl_order_id"] = toUtf(cancel_rsp->cl_order_id);
		data["cl_cancel_id"] = toUtf(cancel_rsp->cl_cancel_id);
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
		data["account_id"] = toUtf(exercise->account_id);
		data["account_type"] = exercise->account_type;
		data["cust_orgid"] = toUtf(exercise->cust_orgid);
		data["cust_branchid"] = toUtf(exercise->cust_branchid);
		data["exercise_type"] = exercise->exercise_type;
		data["cl_order_id"] = toUtf(exercise->cl_order_id);
		data["order_id"] = toUtf(exercise->order_id);
		data["counter_order_date"] = exercise->counter_order_date;
		data["counter_order_time"] = exercise->counter_order_time;
		data["counter_cancel_time"] = exercise->counter_cancel_time;
		data["exercise_status"] = exercise->exercise_status;
		data["oper_status"] = exercise->oper_status;
		data["symbol"] = toUtf(exercise->symbol);
		data["volume"] = exercise->volume;
		data["cancel_volume"] = exercise->cancel_volume;
		data["err_code"] = exercise->err_code;
		data["err_msg"] = toUtf(exercise->err_msg);
	}
	this->onExerciseStatus(data);
};

void OptionApi::OnQueryExerciseRsp(ExerciseDetail* detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["exercise_type"] = detail->exercise_type;
		data["cl_order_id"] = toUtf(detail->cl_order_id);
		data["order_id"] = toUtf(detail->order_id);
		data["counter_order_date"] = detail->counter_order_date;
		data["counter_order_time"] = detail->counter_order_time;
		data["counter_cancel_time"] = detail->counter_cancel_time;
		data["exercise_status"] = detail->exercise_status;
		data["oper_status"] = detail->oper_status;
		data["symbol"] = toUtf(detail->symbol);
		data["volume"] = detail->volume;
		data["cancel_volume"] = detail->cancel_volume;
		data["err_code"] = detail->err_code;
		data["err_msg"] = toUtf(detail->err_msg);
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
		data["contract_id"] = toUtf(detail->contract_id);
		data["exch_contract_id"] = toUtf(detail->exch_contract_id);
		data["contract_name"] = toUtf(detail->contract_name);
		data["underlying_contract_id"] = toUtf(detail->underlying_contract_id);
		data["underlying_contract_name"] = toUtf(detail->underlying_contract_name);
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
	this->onQueryStockPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnTransferStockStatus(TransferStockDetail* transfer_detail) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(transfer_detail->account_id);
		data["account_type"] = transfer_detail->account_type;
		data["cust_orgid"] = toUtf(transfer_detail->cust_orgid);
		data["cust_branchid"] = toUtf(transfer_detail->cust_branchid);
		data["serial_number"] = toUtf(transfer_detail->serial_number);
		data["symbol"] = toUtf(transfer_detail->symbol);
		data["transact_date"] = transfer_detail->transact_date;
		data["transact_time"] = transfer_detail->transact_time;
		data["transfer_type"] = transfer_detail->transfer_type;
		data["transfer_side"] = transfer_detail->transfer_side;
		data["transfer_status"] = transfer_detail->transfer_status;
		data["yesterday_volume"] = transfer_detail->yesterday_volume;
		data["today_bs_volume"] = transfer_detail->today_bs_volume;
		data["today_pr_volume"] = transfer_detail->today_pr_volume;
		data["stock_cust_id"] = toUtf(transfer_detail->stock_cust_id);
		data["stock_secuid"] = toUtf(transfer_detail->stock_secuid);
		data["status_msg"] = toUtf(transfer_detail->status_msg);
	}
	this->onTransferStockStatus(data);
};

void OptionApi::OnTransferStockRsp(TransferStockRsp* transfer_rsp, ErrorInfo* error_info, int request_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(transfer_rsp->account_id);
		data["account_type"] = transfer_rsp->account_type;
		data["cust_orgid"] = toUtf(transfer_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(transfer_rsp->cust_branchid);
		data["symbol"] = toUtf(transfer_rsp->symbol);
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
		data["account_id"] = toUtf(transfer_detail->account_id);
		data["account_type"] = transfer_detail->account_type;
		data["cust_orgid"] = toUtf(transfer_detail->cust_orgid);
		data["cust_branchid"] = toUtf(transfer_detail->cust_branchid);
		data["serial_number"] = toUtf(transfer_detail->serial_number);
		data["symbol"] = toUtf(transfer_detail->symbol);
		data["transact_date"] = transfer_detail->transact_date;
		data["transact_time"] = transfer_detail->transact_time;
		data["transfer_type"] = transfer_detail->transfer_type;
		data["transfer_side"] = transfer_detail->transfer_side;
		data["transfer_status"] = transfer_detail->transfer_status;
		data["yesterday_volume"] = transfer_detail->yesterday_volume;
		data["today_bs_volume"] = transfer_detail->today_bs_volume;
		data["today_pr_volume"] = transfer_detail->today_pr_volume;
		data["stock_cust_id"] = toUtf(transfer_detail->stock_cust_id);
		data["stock_secuid"] = toUtf(transfer_detail->stock_secuid);
		data["status_msg"] = toUtf(transfer_detail->status_msg);
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
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["symbol"] = toUtf(order_detail->symbol);
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["order_id"] = toUtf(order_detail->order_id);
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["lock_type"] = order_detail->lock_type;
		data["lock_status"] = order_detail->lock_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
	}
	this->onLockOrderStatus(data);
};

void OptionApi::OnLockOrderRsp(LockOrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["lock_type"] = order_rsp->lock_type;
		data["order_id"] = toUtf(order_rsp->order_id);
		data["cl_order_id"] = toUtf(order_rsp->cl_order_id);
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
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["symbol"] = toUtf(order_detail->symbol);
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["order_id"] = toUtf(order_detail->order_id);
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["lock_type"] = order_detail->lock_type;
		data["lock_status"] = order_detail->lock_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
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
	this->onQueryLockPositionRsp(data, error, request_id, is_last);
};

void OptionApi::OnCombOrderStatus(CombOrderDetail* order_detail) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["symbol"] = toUtf(order_detail->symbol);
		data["exch_comb_id"] = toUtf(order_detail->exch_comb_id);
		data["comb_type"] = order_detail->comb_type;
		data["comb_strategy"] = order_detail->comb_strategy;
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["order_id"] = toUtf(order_detail->order_id);
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["order_status"] = order_detail->order_status;
		data["oper_status"] = order_detail->oper_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
	}
	this->onCombOrderStatus(data);
};

void OptionApi::OnCombOrderRsp(CombOrderRsp* order_rsp, ErrorInfo* error_info, int request_id, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(order_rsp->account_id);
		data["account_type"] = order_rsp->account_type;
		data["cust_orgid"] = toUtf(order_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(order_rsp->cust_branchid);
		data["comb_type"] = order_rsp->comb_type;
		data["order_id"] = toUtf(order_rsp->order_id);
		data["cl_order_id"] = toUtf(order_rsp->cl_order_id);
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
		data["account_id"] = toUtf(exercise->account_id);
		data["account_type"] = exercise->account_type;
		data["cust_orgid"] = toUtf(exercise->cust_orgid);
		data["cust_branchid"] = toUtf(exercise->cust_branchid);
		data["call_symbol"] = toUtf(exercise->call_symbol);
		data["put_symbol"] = toUtf(exercise->put_symbol);
		data["cl_order_id"] = toUtf(exercise->cl_order_id);
		data["order_id"] = toUtf(exercise->order_id);
		data["order_date"] = exercise->order_date;
		data["order_time"] = exercise->order_time;
		data["cancel_time"] = exercise->cancel_time;
		data["exercise_status"] = exercise->exercise_status;
		data["oper_status"] = exercise->oper_status;
		data["volume"] = exercise->volume;
		data["cancel_volume"] = exercise->cancel_volume;
		data["err_code"] = exercise->err_code;
		data["err_msg"] = toUtf(exercise->err_msg);
	}
	this->onCombExerciseStatus(data);
};

void OptionApi::OnCombExerciseRsp(CombExerciseRsp* exercise_rsp, ErrorInfo* error_info, int request_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(exercise_rsp->account_id);
		data["account_type"] = exercise_rsp->account_type;
		data["cust_orgid"] = toUtf(exercise_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(exercise_rsp->cust_branchid);
		data["cl_order_id"] = toUtf(exercise_rsp->cl_order_id);
		data["order_id"] = toUtf(exercise_rsp->order_id);
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
		data["account_id"] = toUtf(cancel_rsp->account_id);
		data["account_type"] = cancel_rsp->account_type;
		data["cust_orgid"] = toUtf(cancel_rsp->cust_orgid);
		data["cust_branchid"] = toUtf(cancel_rsp->cust_branchid);
		data["order_id"] = toUtf(cancel_rsp->order_id);
		data["cl_order_id"] = toUtf(cancel_rsp->cl_order_id);
		data["cl_cancel_id"] = toUtf(cancel_rsp->cl_cancel_id);
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
		data["account_id"] = toUtf(order_detail->account_id);
		data["account_type"] = order_detail->account_type;
		data["cust_orgid"] = toUtf(order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(order_detail->cust_branchid);
		data["symbol"] = toUtf(order_detail->symbol);
		data["exch_comb_id"] = toUtf(order_detail->exch_comb_id);
		data["comb_type"] = order_detail->comb_type;
		data["comb_strategy"] = order_detail->comb_strategy;
		data["cl_order_id"] = toUtf(order_detail->cl_order_id);
		data["order_id"] = toUtf(order_detail->order_id);
		data["order_date"] = order_detail->order_date;
		data["order_time"] = order_detail->order_time;
		data["cancel_time"] = order_detail->cancel_time;
		data["order_status"] = order_detail->order_status;
		data["oper_status"] = order_detail->oper_status;
		data["volume"] = order_detail->volume;
		data["cancel_volume"] = order_detail->cancel_volume;
		data["err_code"] = order_detail->err_code;
		data["err_msg"] = toUtf(order_detail->err_msg);
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
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
		data["call_symbol"] = toUtf(detail->call_symbol);
		data["put_symbol"] = toUtf(detail->put_symbol);
		data["cl_order_id"] = toUtf(detail->cl_order_id);
		data["order_id"] = toUtf(detail->order_id);
		data["order_date"] = detail->order_date;
		data["order_time"] = detail->order_time;
		data["cancel_time"] = detail->cancel_time;
		data["exercise_status"] = detail->exercise_status;
		data["oper_status"] = detail->oper_status;
		data["volume"] = detail->volume;
		data["cancel_volume"] = detail->cancel_volume;
		data["err_code"] = detail->err_code;
		data["err_msg"] = toUtf(detail->err_msg);
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
		data["account_id"] = toUtf(position_detail->account_id);
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = toUtf(position_detail->cust_orgid);
		data["cust_branchid"] = toUtf(position_detail->cust_branchid);
		data["symbol"] = toUtf(position_detail->symbol);
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
		data["secuid"] = toUtf(position_detail->secuid);
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
		data["contract_id"] = toUtf(detail->contract_id);
		data["comb_strategy"] = detail->comb_strategy;
		data["leg1_contract_id"] = toUtf(detail->leg1_contract_id);
		data["leg1_name"] = toUtf(detail->leg1_name);
		data["leg1_side"] = detail->leg1_side;
		data["leg2_contract_id"] = toUtf(detail->leg2_contract_id);
		data["leg2_name"] = toUtf(detail->leg2_name);
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

void OptionApi::OnQueryCombPositionSubDetailRsp(CombPositionSubDetail* position_detail, ErrorInfo* error_info, int request_id, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(position_detail->account_id);
		data["account_type"] = position_detail->account_type;
		data["cust_orgid"] = toUtf(position_detail->cust_orgid);
		data["cust_branchid"] = toUtf(position_detail->cust_branchid);
		data["symbol"] = toUtf(position_detail->symbol);
		data["comb_strategy"] = position_detail->comb_strategy;
		data["exch_comb_id"] = toUtf(position_detail->exch_comb_id);
		data["volume"] = position_detail->volume;
		data["yesterday_volume"] = position_detail->yesterday_volume;
		data["today_volume"] = position_detail->today_volume;
		data["comb_date"] = position_detail->comb_date;
		data["comb_time"] = position_detail->comb_time;
		data["comb_status"] = position_detail->comb_status;
		data["secuid"] = toUtf(position_detail->secuid);
		data["legs_num"] = position_detail->legs_num;
		data["leg1_symbol"] = toUtf(position_detail->leg1_symbol);
		data["leg1_yesterday_volume"] = position_detail->leg1_yesterday_volume;
		data["leg1_today_volume"] = position_detail->leg1_today_volume;
		data["leg1_pos_side"] = position_detail->leg1_pos_side;
		data["leg1_option_type"] = position_detail->leg1_option_type;
		data["leg2_symbol"] = toUtf(position_detail->leg2_symbol);
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

void OptionApi::OnQueryPositionLimitsRsp(PositionLimitsDetail* limit_detail, ErrorInfo* error_info, int request_id, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(limit_detail->account_id);
		data["account_type"] = limit_detail->account_type;
		data["cust_orgid"] = toUtf(limit_detail->cust_orgid);
		data["cust_branchid"] = toUtf(limit_detail->cust_branchid);
		data["symbol"] = toUtf(limit_detail->symbol);
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
		data["account_id"] = toUtf(limit_detail->account_id);
		data["account_type"] = limit_detail->account_type;
		data["cust_orgid"] = toUtf(limit_detail->cust_orgid);
		data["cust_branchid"] = toUtf(limit_detail->cust_branchid);
		data["long_amount_limit"] = limit_detail->long_amount_limit;
		data["avail_long_amount_limit"] = limit_detail->avail_long_amount_limit;
		data["market"] = toUtf(limit_detail->market);
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
		data["account_id"] = toUtf(margin_diff_detail->account_id);
		data["account_type"] = margin_diff_detail->account_type;
		data["cust_orgid"] = toUtf(margin_diff_detail->cust_orgid);
		data["cust_branchid"] = toUtf(margin_diff_detail->cust_branchid);
		data["market"] = toUtf(margin_diff_detail->market);
		data["contract_id"] = toUtf(margin_diff_detail->contract_id);
		data["exch_comb_id"] = toUtf(margin_diff_detail->exch_comb_id);
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
		data["account_id"] = toUtf(appointment_detail->account_id);
		data["account_type"] = appointment_detail->account_type;
		data["cust_orgid"] = toUtf(appointment_detail->cust_orgid);
		data["cust_branchid"] = toUtf(appointment_detail->cust_branchid);
		data["market"] = toUtf(appointment_detail->market);
		data["contract_id"] = toUtf(appointment_detail->contract_id);
		data["counter_order_date"] = appointment_detail->counter_order_date;
		data["secuid"] = toUtf(appointment_detail->secuid);
		data["options_type"] = appointment_detail->options_type;
		data["option_unit"] = appointment_detail->option_unit;
		data["underlying_contract_id"] = toUtf(appointment_detail->underlying_contract_id);
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
		data["account_id"] = toUtf(detail->account_id);
		data["account_type"] = detail->account_type;
		data["cust_orgid"] = toUtf(detail->cust_orgid);
		data["cust_branchid"] = toUtf(detail->cust_branchid);
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
		data["account_id"] = toUtf(max_order_detail->account_id);
		data["account_type"] = max_order_detail->account_type;
		data["cust_orgid"] = toUtf(max_order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(max_order_detail->cust_branchid);
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
	this->onQueryInquiryStockPositionRsp(data, error, request_id);
};

void OptionApi::OnQueryOptionOrderHistoryRsp(OptionHisOrderDetail* his_order_detail, ErrorInfo* error_info, int request_id, bool is_last, const char* pos_str) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["account_id"] = toUtf(his_order_detail->account_id);
		data["account_type"] = his_order_detail->account_type;
		data["cust_orgid"] = toUtf(his_order_detail->cust_orgid);
		data["cust_branchid"] = toUtf(his_order_detail->cust_branchid);
		data["trade_date"] = his_order_detail->trade_date;
		data["order_date"] = his_order_detail->order_date;
		data["order_time"] = his_order_detail->order_time;
		data["contract_id"] = toUtf(his_order_detail->contract_id);
		data["status"] = his_order_detail->status;
		data["market"] = toUtf(his_order_detail->market);
		data["secuid"] = toUtf(his_order_detail->secuid);
		data["option_account"] = toUtf(his_order_detail->option_account);
		data["option_security_type"] = his_order_detail->option_security_type;
		data["option_num"] = toUtf(his_order_detail->option_num);
		data["option_code"] = toUtf(his_order_detail->option_code);
		data["option_name"] = toUtf(his_order_detail->option_name);
		data["comb_num"] = toUtf(his_order_detail->comb_num);
		data["comb_strategy"] = his_order_detail->comb_strategy;
		data["leg1_num"] = toUtf(his_order_detail->leg1_num);
		data["leg2_num"] = toUtf(his_order_detail->leg2_num);
		data["leg3_num"] = toUtf(his_order_detail->leg3_num);
		data["leg4_num"] = toUtf(his_order_detail->leg4_num);
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
		data["underlying_code"] = toUtf(his_order_detail->underlying_code);
		data["underlying_name"] = toUtf(his_order_detail->underlying_name);
		data["underlying_frozen_qty"] = his_order_detail->underlying_frozen_qty;
		data["underlying_unfrozen_qty"] = his_order_detail->underlying_unfrozen_qty;
		data["underlying_cancel_qty"] = his_order_detail->underlying_cancel_qty;
		data["leg1_side"] = his_order_detail->leg1_side;
		data["leg2_side"] = his_order_detail->leg2_side;
		data["leg3_side"] = his_order_detail->leg3_side;
		data["leg4_side"] = his_order_detail->leg4_side;
		data["leg1_name"] = toUtf(his_order_detail->leg1_name);
		data["leg2_name"] = toUtf(his_order_detail->leg2_name);
		data["leg3_name"] = toUtf(his_order_detail->leg3_name);
		data["leg4_name"] = toUtf(his_order_detail->leg4_name);
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
		data["account_id"] = toUtf(his_trade_detail->account_id);
		data["account_type"] = his_trade_detail->account_type;
		data["cust_orgid"] = toUtf(his_trade_detail->cust_orgid);
		data["cust_branchid"] = toUtf(his_trade_detail->cust_branchid);
		data["trade_date"] = his_trade_detail->trade_date;
		data["trade_time"] = his_trade_detail->trade_time;
		data["order_date"] = his_trade_detail->order_date;
		data["counter_order_id"] = toUtf(his_trade_detail->counter_order_id);
		data["contract_id"] = toUtf(his_trade_detail->contract_id);
		data["match_id"] = toUtf(his_trade_detail->match_id);
		data["market"] = toUtf(his_trade_detail->market);
		data["secuid"] = toUtf(his_trade_detail->secuid);
		data["option_account"] = toUtf(his_trade_detail->option_account);
		data["option_security_type"] = his_trade_detail->option_security_type;
		data["option_security_action"] = his_trade_detail->option_security_action;
		data["option_num"] = toUtf(his_trade_detail->option_num);
		data["option_name"] = toUtf(his_trade_detail->option_name);
		data["comb_num"] = toUtf(his_trade_detail->comb_num);
		data["comb_strategy"] = his_trade_detail->comb_strategy;
		data["leg1_num"] = toUtf(his_trade_detail->leg1_num);
		data["leg2_num"] = toUtf(his_trade_detail->leg2_num);
		data["leg3_num"] = toUtf(his_trade_detail->leg3_num);
		data["leg4_num"] = toUtf(his_trade_detail->leg4_num);
		data["currency_type"] = his_trade_detail->currency_type;
		data["underlying_code"] = toUtf(his_trade_detail->underlying_code);
		data["underlying_name"] = toUtf(his_trade_detail->underlying_name);
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
		data["leg1_name"] = toUtf(his_trade_detail->leg1_name);
		data["leg2_name"] = toUtf(his_trade_detail->leg2_name);
		data["leg3_name"] = toUtf(his_trade_detail->leg3_name);
		data["leg4_name"] = toUtf(his_trade_detail->leg4_name);
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
		data["account_id"] = toUtf(his_appointment_detail->account_id);
		data["account_type"] = his_appointment_detail->account_type;
		data["cust_orgid"] = toUtf(his_appointment_detail->cust_orgid);
		data["cust_branchid"] = toUtf(his_appointment_detail->cust_branchid);
		data["counter_order_date"] = his_appointment_detail->counter_order_date;
		data["currency_type"] = his_appointment_detail->currency_type;
		data["market"] = toUtf(his_appointment_detail->market);
		data["secuid"] = toUtf(his_appointment_detail->secuid);
		data["option_account"] = toUtf(his_appointment_detail->option_account);
		data["option_num"] = toUtf(his_appointment_detail->option_num);
		data["option_name"] = toUtf(his_appointment_detail->option_name);
		data["options_type"] = his_appointment_detail->options_type;
		data["underlying_code"] = toUtf(his_appointment_detail->underlying_code);
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
		data["account_id"] = toUtf(his_delivery_detail->account_id);
		data["account_type"] = his_delivery_detail->account_type;
		data["cust_orgid"] = toUtf(his_delivery_detail->cust_orgid);
		data["cust_branchid"] = toUtf(his_delivery_detail->cust_branchid);
		data["settlement_id"] = his_delivery_detail->settlement_id;
		data["settlement_date"] = his_delivery_detail->settlement_date;
		data["counter_order_id"] = toUtf(his_delivery_detail->counter_order_id);
		data["contract_id"] = toUtf(his_delivery_detail->contract_id);
		data["market"] = toUtf(his_delivery_detail->market);
		data["option_account"] = toUtf(his_delivery_detail->option_account);
		data["option_security_type"] = his_delivery_detail->option_security_type;
		data["option_security_action"] = his_delivery_detail->option_security_action;
		data["option_num"] = toUtf(his_delivery_detail->option_num);
		data["option_name"] = toUtf(his_delivery_detail->option_name);
		data["comb_num"] = toUtf(his_delivery_detail->comb_num);
		data["comb_strategy"] = his_delivery_detail->comb_strategy;
		data["leg1_num"] = toUtf(his_delivery_detail->leg1_num);
		data["leg2_num"] = toUtf(his_delivery_detail->leg2_num);
		data["leg3_num"] = toUtf(his_delivery_detail->leg3_num);
		data["leg4_num"] = toUtf(his_delivery_detail->leg4_num);
		data["currency_type"] = his_delivery_detail->currency_type;
		data["underlying_code"] = toUtf(his_delivery_detail->underlying_code);
		data["underlying_name"] = toUtf(his_delivery_detail->underlying_name);
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
		data["leg1_name"] = toUtf(his_delivery_detail->leg1_name);
		data["leg2_name"] = toUtf(his_delivery_detail->leg2_name);
		data["leg3_name"] = toUtf(his_delivery_detail->leg3_name);
		data["leg4_name"] = toUtf(his_delivery_detail->leg4_name);
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
		data["account_id"] = toUtf(exercise_delivery_detail->account_id);
		data["account_type"] = exercise_delivery_detail->account_type;
		data["cust_orgid"] = toUtf(exercise_delivery_detail->cust_orgid);
		data["cust_branchid"] = toUtf(exercise_delivery_detail->cust_branchid);
		data["serial_number"] = exercise_delivery_detail->serial_number;
		data["settlement_date"] = exercise_delivery_detail->settlement_date;
		data["occur_time"] = exercise_delivery_detail->occur_time;
		data["market"] = toUtf(exercise_delivery_detail->market);
		data["currency_type"] = exercise_delivery_detail->currency_type;
		data["option_account"] = toUtf(exercise_delivery_detail->option_account);
		data["option_security_type"] = exercise_delivery_detail->option_security_type;
		data["option_security_action"] = exercise_delivery_detail->option_security_action;
		data["biz_amt"] = exercise_delivery_detail->biz_amt;
		data["fund_bln"] = exercise_delivery_detail->fund_bln;
		data["fund_avl"] = exercise_delivery_detail->fund_avl;
		data["frozen_margin"] = exercise_delivery_detail->frozen_margin;
		data["unfrozen_margin"] = exercise_delivery_detail->unfrozen_margin;
		data["underlying_code"] = toUtf(exercise_delivery_detail->underlying_code);
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
		data["account_id"] = toUtf(contract_asset_detail->account_id);
		data["account_type"] = contract_asset_detail->account_type;
		data["cust_orgid"] = toUtf(contract_asset_detail->cust_orgid);
		data["cust_branchid"] = toUtf(contract_asset_detail->cust_branchid);
		data["occur_date"] = contract_asset_detail->occur_date;
		data["market"] = toUtf(contract_asset_detail->market);
		data["currency_type"] = contract_asset_detail->currency_type;
		data["option_account"] = toUtf(contract_asset_detail->option_account);
		data["option_num"] = toUtf(contract_asset_detail->option_num);
		data["option_code"] = toUtf(contract_asset_detail->option_code);
		data["option_name"] = toUtf(contract_asset_detail->option_name);
		data["options_type"] = contract_asset_detail->options_type;
		data["option_side"] = contract_asset_detail->option_side;
		data["cover_flag"] = contract_asset_detail->cover_flag;
		data["underlying_code"] = toUtf(contract_asset_detail->underlying_code);
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
		data["account_id"] = toUtf(delivery_netting_detail->account_id);
		data["account_type"] = delivery_netting_detail->account_type;
		data["cust_orgid"] = toUtf(delivery_netting_detail->cust_orgid);
		data["cust_branchid"] = toUtf(delivery_netting_detail->cust_branchid);
		data["settlement_date"] = delivery_netting_detail->settlement_date;
		data["market"] = toUtf(delivery_netting_detail->market);
		data["option_account"] = toUtf(delivery_netting_detail->option_account);
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
		data["account_id"] = toUtf(comb_position_detail->account_id);
		data["account_type"] = comb_position_detail->account_type;
		data["cust_orgid"] = toUtf(comb_position_detail->cust_orgid);
		data["cust_branchid"] = toUtf(comb_position_detail->cust_branchid);
		data["occur_date"] = comb_position_detail->occur_date;
		data["market"] = toUtf(comb_position_detail->market);
		data["currency_type"] = comb_position_detail->currency_type;
		data["secuid"] = toUtf(comb_position_detail->secuid);
		data["option_account"] = toUtf(comb_position_detail->option_account);
		data["comb_num"] = toUtf(comb_position_detail->comb_num);
		data["comb_strategy"] = comb_position_detail->comb_strategy;
		data["comb_strategy_name"] = toUtf(comb_position_detail->comb_strategy_name);
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
		data["leg1_num"] = toUtf(comb_position_detail->leg1_num);
		data["leg1_type"] = comb_position_detail->leg1_type;
		data["leg1_side"] = comb_position_detail->leg1_side;
		data["leg1_position"] = comb_position_detail->leg1_position;
		data["leg2_num"] = toUtf(comb_position_detail->leg2_num);
		data["leg2_type"] = comb_position_detail->leg2_type;
		data["leg2_side"] = comb_position_detail->leg2_side;
		data["leg2_position"] = comb_position_detail->leg2_position;
		data["leg3_num"] = toUtf(comb_position_detail->leg3_num);
		data["leg3_type"] = comb_position_detail->leg3_type;
		data["leg3_side"] = comb_position_detail->leg3_side;
		data["leg3_position"] = comb_position_detail->leg3_position;
		data["leg4_num"] = toUtf(comb_position_detail->leg4_num);
		data["leg4_type"] = comb_position_detail->leg4_type;
		data["leg4_side"] = comb_position_detail->leg4_side;
		data["leg4_position"] = comb_position_detail->leg4_position;
		data["leg1_name"] = toUtf(comb_position_detail->leg1_name);
		data["leg2_name"] = toUtf(comb_position_detail->leg2_name);
		data["leg3_name"] = toUtf(comb_position_detail->leg3_name);
		data["leg4_name"] = toUtf(comb_position_detail->leg4_name);
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
		data["account_id"] = toUtf(his_settlement_detail->account_id);
		data["account_type"] = his_settlement_detail->account_type;
		data["cust_orgid"] = toUtf(his_settlement_detail->cust_orgid);
		data["cust_branchid"] = toUtf(his_settlement_detail->cust_branchid);
		data["settlement_date"] = his_settlement_detail->settlement_date;
		data["trade_date"] = his_settlement_detail->trade_date;
		data["trade_time"] = his_settlement_detail->trade_time;
		data["counter_order_id"] = toUtf(his_settlement_detail->counter_order_id);
		data["market"] = toUtf(his_settlement_detail->market);
		data["currency_type"] = his_settlement_detail->currency_type;
		data["option_account"] = toUtf(his_settlement_detail->option_account);
		data["option_security_type"] = his_settlement_detail->option_security_type;
		data["option_security_action"] = his_settlement_detail->option_security_action;
		data["option_num"] = toUtf(his_settlement_detail->option_num);
		data["option_name"] = toUtf(his_settlement_detail->option_name);
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
		data["account_id"] = toUtf(comb_strategy_file_detail->account_id);
		data["account_type"] = comb_strategy_file_detail->account_type;
		data["cust_orgid"] = toUtf(comb_strategy_file_detail->cust_orgid);
		data["cust_branchid"] = toUtf(comb_strategy_file_detail->cust_branchid);
		data["market"] = toUtf(comb_strategy_file_detail->market);
		data["comb_strategy"] = comb_strategy_file_detail->comb_strategy;
		data["comb_strategy_name"] = toUtf(comb_strategy_file_detail->comb_strategy_name);
		data["same_expdate"] = comb_strategy_file_detail->same_expdate;
		data["same_underlying"] = comb_strategy_file_detail->same_underlying;
		data["auto_split_day"] = toUtf(comb_strategy_file_detail->auto_split_day);
		data["opt_underlying_codes"] = toUtf(comb_strategy_file_detail->opt_underlying_codes);
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

