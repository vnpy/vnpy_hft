/**
* @file    hft_ext_trader_struct.h
* @brief   扩展的交易业务数据和结构定义
*/

#ifndef _HFT_EXT_TRADER_STRUCT_H_
#define _HFT_EXT_TRADER_STRUCT_H_

#include "hft_trader_struct.h"

namespace HFT {

	//  基金转托管请求
	struct FundReDepositReq {
		int64_t ta_code;            // 基金公司, [jzjy: 8-深圳登记, 19-上海登记]
		char16 ta_account;          // 基金帐号
		char16 trans_account;       // 基金交易帐号
		char32 symbol;              // 基金代码
		int32_t agentid;            // 代理人编号[jzjy:填0， ]
		char16 other_dbt_id;        // 对方销售商编号[jzjy: 101-上海证券交易所，102-深圳证券交易所]
		char16 other_org_id;        // 对方机构席位代码	
		char32 other_account;       // 对方交易账号
		int64_t order_qty;          // 委托数量	
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
	};

	//  基金转托管应答
	struct FundReDepositRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char32 sno;                 // 流水号
		char32 symbol;              // 基金代码, 格式为市场.证券ID
		int64_t order_qty;          // 委托数量
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
	};

	// 要约收购业务委托请求
	struct TenderOfferOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char64 tenderer;                // 要约收购参与人编码
	};

	// 要约收购业务委托详情
	struct TenderOfferOrderDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int32_t order_date;             // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 counter_order_id;        // 柜台委托号
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;             // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;             // 交易所订单id，仅君睿柜台支持
	};

	// 查询要约收购信息请求
	struct QryTenderOfferInfoReq {
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		char32 pos_str;                 // 起始定位串，填""表示第一次从头开始查
		int32_t query_num;              // 查询数量，填0表示不指定
	};

	// 要约收购信息详情
	struct TenderOfferInfoDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 symbol;                  // 交易标的
		char32 name;                    // 证券名称
		char16 link_stk_code;           // 正股代码
		int32_t transfer_unit;          // 转让单位
		int64_t sg_qty;                 // 本次要约收购量
		int32_t begin_date;             // 要约收购开始日期
		int32_t end_date;               // 要约收购结束日期
		int64_t max_qty;                // 每笔限量
		Price_t sg_price;               // 要约收购价格
		int64_t buy_unit;               // 买数量单位
		int64_t sale_unit;              // 卖数量单位
		int32_t min_qty;                // 最小申报数量
		char transfer_type;             // 转让类型，参考TransferType定义
		char delist_flag;               // 停牌标志，参考DelistFlag定义
		char offer_period;              // 要约时段，参考OfferPeriod定义
		char32 pos_str;                 // 查询定位串
	};

	// 查询股转受限投资者可交易证券请求
	struct QryNEEQLimitedInvestorTradableStockReq {
		char32 market;                  // 交易市场，如 "SZ" 或者 "SH"
		char16 stk_code;                // 证券代码，非必传
		char32 pos_str;                 // 起始定位串，填""表示第一次从头开始查
		int32_t query_num;              // 查询数量，填0表示不指定
		char32 secuid;                  // 股东代码，非必传，默认由系统自动获取。
										// 用户可根据返回的北交所股东代码按需填写
	};

	// 股转受限投资者可交易证券详情
	struct NEEQLimitedInvestorTradableStockDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char32 name;                    // 证券名称
		char32 secuid;                  // 股东代码
		char32 pos_str;                 // 下次查询定位串
	};

	// 查询预受要约可委托数量请求
	struct QryPreOffereeUsableOrderQtyReq {
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int16_t share_nature;           // 证券性质，参考StockProperty定义
	};

	// 预受要约可委托数量详情
	struct PreOffereeUsableOrderQtyDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int64_t max_order_qty;          // 最大可委托数量
	};

	// 股转委托申报请求
	struct NEEQOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
	};

	// 股转委托申报应答
	struct NEEQOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 股转集中竞价申报请求（两网退市股票专用）
	struct NEEQDelistOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
	};

	// 股转集中竞价申报应答（两网退市股票专用）
	struct NEEQDelistOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 股转协议转让成交确认申报请求
	struct NEEQTransactionOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
		char8 target_pbu_id;            // 对方席位号，成交确认申报请求必传
		char16 target_account_id;       // 对方股东账号，成交确认申报请求必传
		char16 promise_sno;             // 约定号，成交确认申报请求必传
	};

	// 股转协议转让成交确认申报应答
	struct NEEQTransactionOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 股转摘牌协议转让成交确认申报请求
	struct NEEQDelistTransactionOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
		char8 target_pbu_id;            // 对方席位号，成交确认申报请求必传
		char16 target_account_id;       // 对方股东账号，成交确认申报请求必传
		char16 promise_sno;             // 约定号，成交确认申报请求必传
	};

	// 股转摘牌协议转让成交确认申报应答
	struct NEEQDelistTransactionOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 股转大宗交易成交确认申报请求
	struct NEEQBlockTradeOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
		char8 target_pbu_id;            // 对方席位号，成交确认申报请求必传
		char16 target_account_id;       // 对方股东账号，成交确认申报请求必传
		char16 promise_sno;             // 约定号，成交确认申报请求必传
	};

	// 股转大宗交易成交确认申报应答
	struct NEEQBlockTradeOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 股转要约收购业务申报请求
	struct NEEQTenderOfferOrderReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;                   // 买卖方向，参考OrderSide定义
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char32 secuid;                  // 股东代码，非必传，用户可根据返回的北交所股东代码按需填写入参
		int32_t share_nature;           // 股份性质，参考StockProperty定义，股转预受要约申报必传
	};

	// 股转要约收购业务申报应答
	struct NEEQTenderOfferOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};


	// 股转专用股份明细查询请求
	struct QueryNEEQSharesDetailReq {
		char32 symbol;                  // 标的代码，格式为市场.证券ID，低延时柜台账号必填
		int16_t share_nature;           // 证券性质，参考StockProperty定义，低延时柜台账号必填
		char qry_direct;                // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
		char32 pos_str;                 // 定位串，填""表示第一次从头开始查
		int32_t query_num;              // 查询数量，填0表示不指定
		char32 secuid;                  // 股东代码，非必传，默认由系统自动获取。
										// 用户可根据返回的北交所股东代码按需填写
	};

	// 股转专用股份明细详情
	struct QueryNEEQSharesDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 pos_str;                 // 定位串，下次查询索引号
		char16 cust_id;                 // 客户代码
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char32 stk_name;                // 证券名称
		int16_t currency_type;          // 币种，参考CurrencyType定义
		char16 secuid;                  // 证券账户(股东代码)
		char64 pbu_id;                  // 交易单元
		int64_t stk_bal;                // 股份余额
		int64_t stk_avl;                // 股份可用
		int16_t share_nature;           // 股份性质，参考StockProperty定义
		char128 share_nature_desc;      // 股份性质说明
		int64_t stk_buy;                // 股份买入解冻
		int64_t stk_sell;               // 股份卖出冻结
		int64_t stk_uncome_buy;         // 在途股份买入解冻
		int64_t stk_uncome_sell;        // 在途股份卖出冻结
		char16 seat;                    // 席位代码
		Price_t fix_price;              // 固定价格
	};

	// 股转市场公开发行认购结果查询请求
	struct QueryNEEQSubscriptionResultsOfIPOReq {
		char32 market;                  // 交易市场，如 "SZ" 或者 "SH"
		char16 stk_code;                // 认购代码，低延时柜台账号必填
		char16 link_stk_code;           // 正股代码，低延时柜台账号必填
		int32_t order_date;             // 委托日期，格式为YYYYMMDD，低延时柜台账号必填
		char32 pos_str;                 // 起始定位串，填""表示第一次从头开始查
		int32_t query_num;              // 查询数量，填0表示不指定
		char qry_direct;                // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
		char32 secuid;                  // 股东代码，非必传，默认由系统自动获取。
										// 用户可根据返回的北交所股东代码按需填写
	};

	// 股转市场公开发行认购结果详情
	struct NEEQSubscriptionResultsOfIPODetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 pos_str;                 // 定位串，下次查询索引号
		int32_t order_date;             // 委托日期
		char32 counter_order_id;        // 柜台委托号
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char16 link_stk_code;           // 正股代码
		char16 secuid;                  // 证券账户(股东代码)
		char16 cust_id;                 // 客户代码
		int32_t reg_date;               // 系统生成的认购日期
		int64_t reg_qty;                // 认购数量
		Price_t reg_price;              // 认购价格
		int16_t reg_result;             // 认购结果，参考SubscribeResult定义
		int32_t data_length;            // 组合个数，及以下二个为低延时柜台特有字段
		int64_t reg_qty2;               // 其他数量2，为正数时表示网下投资者申购时的最大申购倍数
		int32_t insert_date;            // 插入日期
	};


	// 要约收购人信息查询
	struct QryTenderOfferUser {
		char8 market;					// 根据市场过滤
		char16 code;					// 根据代码过滤
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询的数量，最大支持500个
	};

	// 要约收购人信息明细
	struct TenderOfferUserDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char32 symbol;					// 格式为市场.证券ID或市场.合约ID
		char32 tenderer_id;				// 要约收购参与人编码
		char64 tenderer_name;			// 收购人名称
		int64_t offering_price;			// 要约收购价格
		int64_t start_date;				// 收购起始日
		int64_t end_date;				// 收购截止日
	};

	// 大宗交易预委托请求
	struct BlockPreOrderReq {
		char32 symbol;              // 交易标的，格式为市场.证券代码
		int16_t side;               // 买卖方向，参考OrderSide定义
		int64_t volume;             // 订单数量，股票单位（股），债券单位（上海：手，深圳：张）
		Price_t price;              // 订单委托价，限价单使用，扩大一万倍，市价填写0
		char16 promise_sno;         // 约定号
		char8 target_pbu_id;        // 对方席位号
		char restrict_flag;         // 大宗减持标识，受限标志位，'0'-非受限股份，'1'-受限股份
		char16 contactor;           // 联系人，意向申报时必填，输入编码：Windows是GBK，Linux是UTF8
		char32 contactor_info;      // 联系人信息，意向申报时必填，输入编码：Windows是GBK，Linux是UTF8
	};

	// 大宗交易预委托应答
	struct BlockPreOrderRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char32 apply_sno;          // 申请编号
		int32_t apply_date;         // 申请日期YYYYMMDD
	};

	// 查询大宗交易预委托请求
	struct QryBlockPreOrderReq {
		int32_t begin_date;         // 开始日期YYYYMMDD，非必传
		int32_t end_date;           // 结束日期YYYYMMDD，非必传
		char8 market;               // 市场，如"SZ SH"，非必传
		char16 code;                // 代码，非必传
		int16_t apply_status;       // 申请状态，参考ApplyStatus定义，非必传
		char32 pos_str;             // 定位串，填""表示第一次从头开始查，仅低延时柜台支持
		int32_t query_num;          // 查询数量，仅低延时柜台支持

	};

	// 大宗交易预委托明细
	struct BlockPreOrderDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int32_t apply_date;         // 申请日期YYYYMMDD
		char32 apply_sno;          // 申请编号
		int32_t oper_date;          // 操作日期YYYYMMDD
		int32_t oper_time;          // 操作时间HHMMSSmmm
		char32 symbol;              // 交易标的，格式为市场.证券ID
		char32 name;                // 证券名称
		int16_t side;               // 买卖方向枚举
		Price_t price;              // 委托价格，扩大1万倍
		int64_t volume;             // 委托数量，股票(单位:股)，债券(上海:手，深圳:张)
		char32 order_id;            // 柜台委托号
		int32_t order_date;         // 柜台委托日期YYYYMMDD
		char16 promise_sno;         // 约定号
		char8 target_pbu_id;        // 对方席位号
		char32 secuid;              // 股东代码
		char restrict_flag;         // 大宗减持标识，受限标志位，'0'-非受限股份，'1'-受限股份
		int16_t apply_status;       // 申请状态，参考ApplyStatus定义
		int16_t deal_status;        // 执行状态，参考BlockDealStatus定义
		char32 contract_id;         // 合同序号
		char16 contactor;           // 联系人
		char32 contactor_info;      // 联系人信息
		char16 check_operator;      // 审批柜员
		char256 order_err_msg;      // 内部报错信息（非交易所返回）
	};

	// 撤销大宗交易预委托请求
	struct CancelBlockPreOrderReq {
		int32_t apply_date;         // 申请日期YYYYMMDD
		char32 apply_sno;          // 申请编号
	};

	// 撤销大宗交易预委托应答
	struct CancelBlockPreOrderRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int32_t apply_date;         // 申请日期YYYYMMDD
		char32 apply_sno;           // 申请编号
	};

	// 查询大宗交易预委托营业部权限请求
	struct QryBlockPreOrderDeptRightsReq {
		bool get_all;               // 是否返回当前已有权限的全部二级营业部信息
	};

	// 大宗交易预委托营业部权限明细
	struct BlockPreOrderDeptRightsDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码，登录账户的机构编码
		char8 cust_branchid;        // 分支编码，登录账户的分支编码
		char8 branch_id;            // 分支编码，是否有权限的分支编码，即二级营业部编码
		int32_t open_date;          // 权限开通日期
		bool privileged;            // 是否有权限
	};

	// 大宗交易通用委托请求
	struct BlockOrderReq {
		char32 symbol;              // 交易标的，格式为市场.证券代码
		uint16_t side;              // 买卖方向枚举
		uint64_t price;             // 委托价格，意向申报时非必填
		uint64_t volume;            // 委托数量，股票(单位:股)，债券(上海:手，深圳:张)，意向申报时非必填
		char16 promise_sno;         // 约定号，定价申报、成交申报时必填
		char8 target_pbu_id;        // 对方席位号，成交申报时必填
		char restrict_flag;         // 大宗减持标识，受限标志位，'0'-非受限股份，'1'-受限股份，必填
		char32 cl_order_id;         // 客户端自定义委托号
		char16 contactor;           // 联系人，意向申报时必填，输入编码：Windows是GBK，Linux是UTF8
		char32 contactor_info;      // 联系人信息，意向申报时必填，输入编码：Windows是GBK，Linux是UTF8
		int32_t price_property;		// 价格类型, BlockPriceProperty
		int32_t policy_id;			// 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台，非必传
	};

	// 大宗交易通用委托应答
	struct BlockOrderRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char32 order_id;            // 柜台委托号
		int32_t order_date;         // 柜台委托日期，夜市委托时于系统日期不同
		char32 contract_id;         // 委托合同号，仅集中交易和低延时支持应答中返回
		char32 cl_order_id;         // 客户端自定义委托号
	};

	// 大宗交易通用撤单请求
	struct CancelBlockOrderReq {
		char32 order_id;            // 被撤的原订单id
		char32 cl_order_id;         // 客户端订单id, 与委托一致， 必填，否则收不到，已撤成交状态推送
		char32 cl_cancel_id;        // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
	};

	// 大宗交易通用撤单应答
	struct CancelBlockOrderRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char32 order_id;            // 被撤的原订单id
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 cl_cancel_id;        // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
		char32 cancel_id;      		// 柜台撤单订单id，集中交易柜台不支持
    	char32 ex_order_id;    		// 交易所订单id，仅君睿柜台支持
	};

	// 查询大宗交易协议行情请求
	struct QryBlockMarketDataReq {
		char32 symbol;          // 交易标的，格式为市场.证券ID， 集中交易必传
		int16_t side;           // 买卖方向（意向买、意向卖、定价买、定价卖），非必传
		char16 promise_sno;     // 约定号，非必传
		char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;      // 查询数量
	};

	// 大宗交易协议行情明细
	struct BlockMarketDataDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char32 symbol;              // 交易标的，格式为市场.证券ID
		int16_t block_busi_type;    // 业务类型，参考OrderSide定义
		int64_t order_qty;          // 申报数量
		int64_t order_price;        // 申报价格，扩大1万倍
		int64_t order_time;         // 申报时间HHMMSSmmm
		char16 promise_sno;         // 约定号
		char16 serial_no;           // 申报合同序号
		char32 link_man;			// 联系人
	};

	// 沪港通公司行为申报请求
	struct HKCompanyBusinessApplyReq {
		char16 symbol;     				// 证券代码, Y, 
		char32 gxdm;     				// 公司行为代码, Y, 
		int32_t business_type;   		// 业务类型, Y, HKBusinessType,沪港通：63、64、65、66, 深港通:80、81、82 
		int32_t report_type;   			// 申报类型, Y, HKBusinessReportType,
		int32_t report_num;   			// 申报数量, N, 申报数量为负数时，为对非当日申报的数量进行撤单。申报类型为查询时此字段无效，不必填。
		char32 cancel_accept_sno;     	// 撤单受理编号, N, 仅限深港通市场当日已成委托撤单，为需要传入成交的业务流水号。
										// 当此字段有值时，申报数量必须为正数
	};

	// 沪港通公司行为申报请求应答
	struct HKCompanyBusinessApplyRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char32 apply_sno;     			//申报编号
		int32_t apply_date;    			//申报日期 
	};
	// 港股通昨日结算汇率查询请求
	struct QryHKYestDaySettSpotRateReq {
		char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;      // 查询数量
		char32 market;          // 交易市场，为空默认查深港通和沪港通
		int16_t bcurrency_type; // 本位币币种，参考CurrencyType定义
	};

	// 港股通昨日结算汇率数据
	struct HKYestDaySettSpotRateDetail {
		char16 account_id;				// 交易账号，目前是资金账号
		char8 cust_orgid;				// 机构编码
		char8 cust_branchid;			// 分支编码
		int16_t account_type;			// 交易账号类型，参考AccountType定义
		char32 market;					// 交易市场，如 "SZ" 或者 "SH"
		int16_t currency_type;			// 原币种，参考CurrencyType定义
		int16_t bcurrency_type;			// 本位币币种，参考CurrencyType定义
		int32_t last_date;				// 昨日结算日期
		ExchangeRatio_t last_buy_rate;  // 买入结算汇率，扩大1亿倍
		ExchangeRatio_t last_sale_rate; // 卖出结算汇率，扩大1亿倍
		char32 pos_str;					// 查询定位串
		int32_t total_num;				// 总记录数
		char32 server_id;				// 机器编码
	};

	// 港股通公司行为历史查询请求
	struct QryHKCompHisBehaviorReq {
		char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;          // 查询数量
		char32 market;              // 交易市场，为空默认查深港通和沪港通
		char16 stk_code;            // 证券代码，非必传
		int32_t apply_date;         // 申报日期，格式为YYYYMMDD，非必传
		int64_t apply_sno;          // 申报编号，非必传
		int16_t hk_busi_type;       // 港股通业务类型，参考HKBusinessType定义，非必传
		int16_t hk_report_type;     // 港股通申报类型，参考HKBusinessReportType定义，非必传
		char qry_direct;            // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认升序
	};

	//港股通公司行为历史明细数据
	struct HKCompHisBehaviorDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char32 apply_sno;           // 申报编号
		char32 market;              // 交易市场，如 "SZ" 或者 "SH"
		char32 cancel_sno;          // 撤单编号
		char32 biz_msgidr;          // 申报报文id 深港通新增，申报时的报文id
		int32_t busi_date;          // 业务日期，格式为YYYYMMDD
		char32 gxdm;                // 公司行为代码或公告编号
		int16_t hk_busi_type;       // 港股通业务类型
		char32 secuid;              // 证券账号（股东代码）
		char16 stk_code;            // 证券代码
		int16_t security_type;      // 证券类别，参考HKSecurityType定义
		int16_t circul_type;        // 流通类别，参考HKCirculationType定义
		int16_t rights_type;        // 权益类别，参考HKRightsType定义
		int32_t list_year;          // 挂牌年份
		int32_t rights_times;       // 权益次数
		int64_t order_qty;          // 申报数量，扩大一万倍
		Price_t order_price;        // 价格，扩大一万倍
		Amt_t order_amt;            // 金额，扩大一万倍
		char32 assist_code;         // 辅助代码
		char32 settle_sno;          // 清算编号
		int16_t rpt_status;         // 申报状态，参考HKReportStatus定义
		char32 accept_sno;          // 受理编号
		int64_t accept_time;        // 受理时间
		int32_t result_code;        // 结果代码
		char128 result_desc;        // 结果说明
		char256 remark;             // 备注
		int16_t hk_report_type;     // 港股通申报类型
		char32 isin;                // 股票ISIN码
		char32 announcement_sno;    // 公告编号
		char32 motion_sno;          // 议案编号
		int64_t approval_qty;       // 赞成数量
		int64_t oppose_qty;         // 反对数量
		int64_t waiver_qty;         // 弃权数量
		char32 pos_str;             // 查询定位串
		int32_t total_num;          // 数据库总条数
        char64 stk_name;            // 证券名称  
        int32_t sbqsrq;             // 申报起始日期
        int32_t sbjzrq;             // 申报截止日期
	};

	// 港股通登记日权益数量查询请求
	struct QryHKRegisDateRightsQtyReq {
		char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;          // 查询数量
		char32 market;              // 交易市场，为空默认查深港通和沪港通
		char16 stk_code;            // 证券代码，非必传
		int16_t hk_busi_type;       // 港股通业务类型，参考HKBusinessType定义，非必传
	};

	// 港股通登记日权益数量明细数据
	struct HKRegisDateRightsQtyDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		int16_t hk_busi_type;       // 港股通业务类型
		char16 stk_code;            // 证券代码
		int64_t stk_bal;            // 参考权益数量
		int32_t bonus_date;         // 除权日期
		char32 pos_str;             // 查询定位串
		int32_t total_num;          // 数据库总条数
	};

	// 查询港股通通知信息
	struct QryHKNoticeReq {
		char32 market;				// 交易市场，为空默认查深港通和沪港通，清算已切柜台现要求必传
		char32 code;				// 5位港股证券代码
		char32 gxdm;				// 公司行为代码或公告编号
		int32_t business_type;		// 业务类型, HKBusinessType
		int32_t notice_type;   		// 通知类型, HKNoticeType
		int32_t append_date;		// 申报日期，格式为YYYYMMDD
		char32 pos_str;				// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;			// 查询数量
		char4 ciftype;				// 分区号 
	};

	struct HKNoticeInfoDetail {
		char16 account_id;			  // 交易账号，目前是资金账号
		char8 cust_orgid;			  // 机构编码
		char8 cust_branchid;		  // 分支编码
		int16_t account_type;		  // 交易账号类型，参考AccountType定义
		char32 stkname;               // 证券名称
		char32 symbol;				  // 标的代码
		char32 gxdm;                  // 公司行为代码
		int32_t gqdjrq;               // 股权登记日期
		int32_t sbqsrq;               // 申报起始日期
		int32_t sbjzrq;               // 申报截止日期
		int32_t business_type;        // 业务类型,HKBusinessType
		int32_t notice_type;          // 通知类别,HKNoticeType
		int32_t notice_date;          // 通知日期
		char4 zqlb;                   // 证券类别
		char ltlx;                    // 流通类型
		char4 qylb;                   // 权益类别
		int32_t gpnf;                 // 挂牌年份
		int32_t qycs;                 // 权益次数
		int32_t hkgsffrq;             // 结算发放日期
		Price_t jg1;                  // 境内税前每股红利价格/每股收购价格
		Price_t jg2;                  // 境内税后每股红利价格
		int32_t bz;                   // 币种
		int64_t bl1;                  // 比率1，扩大1E10倍
		int64_t bl2;                  // 比率2，扩大1E10倍
		char4 lx1;                    // 类型1
		char4 lx2;                    // 类型2
		char32 fzdm2;                 // 辅助代码2,tzlb= h12时,此字段表示“议案编号
		char128 fjsm1;                // 附加说明1
		char128 fjsm2;                // 附加说明2
		char64 beiy;                  // 备用
		char reserve1;				  // 保留备用
		char reserve2;				  // 保留备用
		int32_t reserve3;             // 保留备用
		int32_t reserve4;             // 保留备用
		int64_t reserve5;             // 保留备用，扩大1W倍
		char128 reserve6;             // 保留备用
		char16 qybh;                  // 权益编号
		char4 gfxz;                   // 股份性质
		int32_t sszt;                 // 上市状态 参考SSZT
		int32_t zt;                   // 参数状态 参考HKNoticeZZ
		int64_t sl1;                  // 数量1，扩大1W倍
		int64_t sl2;                  // 数量2，扩大1W倍
		char32 pos_str;				  // 定位串
	};

	// 查询港股通公司行为和投票请求
	struct QryHKCorporateActionAndVoteReq {
		char32 market;					// 交易市场，深港通传SZHK，沪港通传SHHK
		char16 stk_code;				// 证券代码，非必传
		int16_t hk_busi_type;			// 港股通业务类型，参考HKBusinessType定义，非必传
		int16_t hk_report_type;			// 港股通申报类型，参考HKBusinessReportType定义，非必传
		char32 apply_sno;               // 申报编号，非必传
		int32_t apply_date;				// 申报日期，格式为YYYYMMDD，非必传
		char32 pos_str;                 // 起始定位串，填""表示第一次从头开始查
		int32_t query_num;              // 查询数量
	};

	// 港股通公司行为和投票详情
	struct HKCorporateActionAndVoteDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 apply_sno;               // 申报编号
		int32_t oper_date;              // 发生日期
		char32 symbol;                  // 交易标的
		char32 gxdm;					// 公司行为代码
		int16_t hk_busi_type;			// 港股通业务类型，参考HKBusinessType定义
		int16_t hk_report_type;			// 港股通申报类型，参考HKBusinessReportType定义
		int16_t security_type;			// 证券类别，参考HKSecurityType定义
		int64_t order_qty;				// 申报数量，扩大1万倍
		Price_t order_price;			// 申报价格
		Amt_t order_amt;				// 申报金额
		char32 settle_sno;				// 清算编号
		int16_t order_status;           // 委托状态，参考OrderStatus定义
		char32 isin;					// ISIN编码
		char32 note_proposal;           // 公告编号
		char32 voting_proposal;         // 议案编号
		int64_t affirmative_votes;      // 赞成数量
		int64_t negative_votes;         // 反对数量
		int64_t abstention_votes;       // 弃权数量
		char32 accept_sno;				// 受理编号
		int64_t accept_time;			// 受理时间
		char16  result_code;			// 结果代码
		char128 result_desc;			// 结果说明
		char32 cancel_orgin_sno;		// 撤单原编号，撤单委托对应的原委托编号
	};

	// ETF网下认购请求
	struct ETFOfflineSubscribeReq {
		char32 cl_order_id;             // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t side;                   // 买卖方向，参考OrderSide定义，网下现金认购、网下股票认购
		int64_t volume;                 // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
		Price_t price;                  // 订单委托价，扩大一万倍，网下现金认购必传
		uint16_t policy_id;             // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
		char8 stk_market;               // 成分股市场，网下股票认购必传
		char16 stk_code;                // 成分股代码，网下股票认购必传
	};

	// ETF网下认购应答
	struct ETFOfflineSubscribeRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 外围 ETF 认购查询股票可认购数量
	struct QryETFStkSubscribeAbleQty {
		char16 etf_symbol;              // ETF代码
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询数量

	};

	// 外围 ETF 认购查询股票可认购数量明细
	struct QryETFStkSubscribeAbleQtyRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char16 etf_symbol;              // ETF代码
		char16 stk_symbol;              // 成分股代码
		int64_t max_order_qty;			// 可认购数量

	};

	// 外围 ETF 认购信息查询
	struct QryETFSubscribeInfo {
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询的数量，最大支持500个
	};

	// 外围 ETF 认购信息明细
	struct QryETFSubscribeInfoRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char32 sno;       				// 委托序号, 
		int64_t sysdate;       			// 系统日期, 
		int64_t operdate;       		// 发生日期, 
		int64_t opertime;       		// 发生委托时间, 
		char16 ofcode;       			// 基准基金代码, 取一级市场基金代码,如'510051'
		char32 ofname;       			// 基准基金名称, 如'华夏上证50ETF'
		int32_t moneytype;       		// 货币代码, 
		int32_t market;       			// 交易市场, 
		char16 stkcode;       			// 证券代码, 
		char32 stkname;       			// 证券名称, 
		int32_t side;       			// 买卖方向,
		int64_t orderqty;       		// 证券发生数, 
		Price_t orderprice;       		// 委托价格, 
		Amt_t orderfrzamt;       		// 委托冻结金额, 
		int32_t cancelflag;       		// 撤销标志, ETFSubscribeCancelFlag
		int32_t status;       			// 处理状态, ETFSubscribeStatus
		char16 frzcode;       			// 股票认购冻结证券代码frzcode, 
		char32 frzname;       			// 股票认购冻结证券名称frzname, 
		int64_t orderdate;       		// 委托交易日期, 
		char32 ordersno;       			// 委托序号, 
		char8 seat;       				// 席位, 
		int64_t commissionrate;       	// 股票认购费用比例, 扩大1亿倍
		int64_t matchdate;       		// 成交日期, 对应uncommitclear中matchdate
		char32 matchsno;       			// 流水号, 对应uncommitclear中sno 
		int32_t marketstk;       		// 成分股市场, 
	};

	// 深圳场内LOF基金分红方式设置请求
	struct SZLOFDividendMethodSetReq {
		char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
		int16_t divid_method;           // 分红方式，参考FundDividMethod定义
	};

	// 深圳场内LOF基金分红方式设置应答
	struct SZLOFDividendMethodSetRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期
		char32 order_id;       // 柜台订单id
		char32 contract_id;    // 委托合同号，仅君睿柜台支持
		char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
	};

	// 私募认购/申购业务请求明细
	struct PrivateOfferingPurchaseReq {
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		int16_t share_class;		// 收费方式，参考OfShareClass
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		Amt_t order_amt;			// 委托金额,需扩大1W倍
		int32_t frozen_date;		// 资金冻结日期，格式为YYYYMMDD,预委托时操作日期
		int64_t frozen_no;			// 资金冻结流水号,预委托时冻结流水号
		int16_t pass_flag;			// 通过标识，参考PassFlag
		char16 ctrl_kinds;			// 控制类别，参考CtrlKinds
		char32 cl_order_id;			// 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        double order_qty;           // 委托数量,基金份额，有效小数位两位，使用老版本的用户特别注意原来扩大100倍字段已删除，
                                    // 由此不扩大倍数的字段代替，注意倍数关系做相应变化 
	};

	// 开方式基金交易接口应答
	struct OfOrderDetailRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台委托日期
		char32 order_id;       // 柜台委托编号
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
	};

	// 基金申购/认购业务
	struct FundPurchaseReq {
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		int16_t share_class;		// 收费方式，参考OfShareClass
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		int32_t order_type;			// 订单类别,限价，参考OrderType
		Amt_t order_amt;			// 委托金额,需扩大1W倍
		int32_t tsbz_type;			// 开放式基金特殊备注类型，参考OfSpecialRemarkType
		char256 tsbz;				// 客户定投计划编号,用户中心调用时传入
		int16_t pass_flag;			// 通过标识，参考PassFlag
		char16 ctrl_kinds;			// 控制类别，参考CtrlKinds
		char32 cl_order_id;			// 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        double order_qty;           // 委托数量,基金份额，有效小数位两位，使用老版本的用户特别注意原来扩大100倍字段已删除，
                                    // 由此不扩大倍数的字段代替，注意倍数关系做相应变化
	};

	// 开方式基金交易接口应答
	struct FundPurchaseRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台委托日期
		char32 order_id;       // 柜台委托编号
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int16_t night_status;  // 夜市委托标志, 参考OfNightStatus
	};

	// 基金赎回业务
	struct FundRedeemReq {
		char32 old_order_sno;		// 原申请单号
		int32_t old_order_date;		// 原申请日期，格式为YYYYMMDD
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		int16_t share_class;		// 收费方式，参考OfShareClass
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		int32_t order_type;			// 订单类别,限价，参考OrderType
		Amt_t order_amt;			// 委托金额,需扩大1W倍
		int16_t redeem_type;		// 巨额赎回标志，参考RedeemType
		int16_t pass_flag;			// 通过标识，参考PassFlag
		char16 ctrl_kinds;			// 控制类别，参考CtrlKinds
		char32 cl_order_id;			// 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        double order_qty;           // 委托数量,基金份额，有效小数位两位，使用老版本的用户特别注意原来扩大100倍字段已删除，
                                    // 由此不扩大倍数的字段代替，注意倍数关系做相应变化
	};

	// 基金撤销( 认购/ 申购/ 赎回) 业务
	struct FundOrderCancelReq {
		char32 order_sno;			// 委托单号
		int32_t order_date;			// 委托日期，格式为YYYYMMDD
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		char32 cl_order_id;			// 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
	};

	// 基金转换业务
	struct FundTransformReq
	{
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		int16_t share_class;		// 收费方式，参考OfShareClass
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		int32_t order_type;			// 订单类别,限价，参考OrderType
		Amt_t order_amt;			// 委托金额,需扩大1W倍
		int32_t redeem_type;		// 巨额赎回标志，参考RedeemType
		int32_t old_order_date;		// 原申请日期，格式为YYYYMMDD
		char32 old_order_sno;		// 原申请单号
		char8 other_security_id;	// 转换基金代码
        double order_qty;           // 委托数量,基金份额，有效小数位两位，使用老版本的用户特别注意原来扩大100倍字段已删除，
                                    // 由此不扩大倍数的字段代替，注意倍数关系做相应变化
	};

	// 开方式基金接口应答
	struct FundCommRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台委托日期
		char32 order_id;       // 柜台委托编号
	};

	// 基金分红方式设置业务(410806)
	struct FundSetBonusTypeReq {
		int64_t ta_code;			// 基金公司，参考Ta_Code
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		int16_t share_class;		// 收费方式，参考OfShareClass
		int32_t fund_order_side;	// 交易方向，参考FundOrderSide
		int32_t order_type;			// 订单类别,限价，参考OrderType
		int16_t divid_method;		// 分红方式,FundDividMethod
		Ratio_t divid_ratio;		// 分红比例/需扩大1w倍
	};

	// 基金分红方式查询应答明细
	struct FundBonusTypeDetail
	{
		char16 account_id;			// 交易账号，目前是资金账号
		int16_t account_type;		// 交易账号类型，参考AccountType定义
		char8 cust_orgid;			// 机构编码
		char8 cust_branchid;		// 分支编码

		int64_t ta_code;			// 基金公司，参考Ta_Code
		char16 ta_name;				// 基金公司名称
		char32 trans_account;		// 交易帐号
		char16 ta_account;			// 基金帐号
		char8 ofcode;				// 基金代码
		char16 ofname;				// 基金名称
		int32_t divid_method;		// 分红方式,FundDividMethod
		char32 dividmethodname;		// 分红方式名
		int32_t remark1;			//
		int64_t remark2;			//
	};

	// 开放式基金当日委托查询请求
	struct QryOfOrderReq
	{
		int64_t ta_code;				// 基金公司，参考Ta_Code
		char32 trans_account;			// 交易帐号
		char16 ta_account;				// 基金帐号
		char8 ofcode;					// 基金代码
		int16_t share_class;			// 收费方式，参考OfShareClass
		int32_t fund_order_side;		// 交易方向，参考FundOrderSide
		int32_t query_num;				// 查询条数
		int32_t tsbz_type;				// 开放式基金特殊备注类型，参考OfSpecialRemarkType
		char32 tsbz;					// 客户定投计划编号，用户中心调用时传入
		char32 post_str;				// 定位串
	};

	// 开放式基金当日委托明细
	struct QryOfOrderRspDetail
	{
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		int32_t predate;               // 预约的赎回日期，格式为YYYYMMDD
		char256 extstr2;               // 其他备注
		int32_t oper_date;             // 发生日期，格式为YYYYMMDD
		int32_t oper_time;             // 发生时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示  
		int32_t order_date;            // 委托日期，格式为YYYYMMDD
		char32 sno;                    // 委托流水号
		int32_t redeemtype;            // 巨额赎回标志
		int64_t tacode;                // 基金公司
		char16 taacc;                  // 基金帐号
		char32 tran_sacc;              // 交易帐号
		char8 ofcode;                  // 基金代码
		char64 ofname;                 // 基金名称
		int32_t share_class;           // 收费方式
		int32_t trdid;                 // 交易类型
		int32_t cancel_flag;           // 撤消标志
		int32_t order_status;          // 委托状态，参考FundOrderStatus定义
		char32 err_info;			   // 返回错误信息
		int32_t divid_method;          // 分红方式
		Amt_t orderamt;                // 委托金额，扩大1W倍
		char16 other_taacc;            // 对方基金帐号
		char32 other_transacc;         // 对方交易帐号
		char8 other_ofcode;            // 转换基金代码
		Amt_t back_fee;                // 后台收费，扩大1W倍
		int32_t old_oper_date;         // 原申请日期，格式为YYYYMMDD
		char32 old_sno;				   // 原申请单号   	

        // 以下两个字段代替上面两个已删除的数量类字段，倍数由原来扩大100倍改为不扩大倍数，注意做相应倍数处理
        double order_qty;              // 委托数量，有效小数位两位
        double matched_qty;            // 已成交数量，有效小数位两位
	};

	// 开放式基金持仓查询请求
	struct QryOfPositionReq
	{
		int64_t ta_code;				// 基金公司，参考Ta_Code
		char32 trans_account;			// 交易帐号
		char16 ta_account;				// 基金帐号
		char8 ofcode;					// 基金代码
		int16_t share_class;			// 收费方式，参考OfShareClass
		int32_t query_num;				// 查询条数
		char32 post_str;				// 定位串
	};

	// 开放式基金持仓明细
	struct QryOfPositionRspDetail
	{
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		int64_t tacode;                // 基金公司
		char32 tran_sacc;              // 交易帐号
		char8 ofcode;                  // 基金代码
		char16 ofname;                 // 基金名称
		int32_t share_class;           // 收费方式
		Amt_t of_last_bal;             // 基金昨日余额，扩大1w倍
		Amt_t of_bal;                  // 基金余额，扩大1w倍
		Price_t current_cost;          // 基金买入成本，扩大1w倍
		Amt_t last_cost;               // 基金买入总金额，扩大1w倍
		Amt_t profit;                  // 基金浮动盈亏，扩大1w倍
		Amt_t market_value;            // 基金证券市值，扩大1w倍
		Price_t nav;                   // 基金净值，扩大1w倍
		int32_t status;                // 基金状态，参考FundProdStatus定义
		int32_t otc_flag;              // 是否OTC产品，参考OtcFlag定义
		int32_t of_kind;               // 基金性质，参考OfKind定义
		int32_t ztg_flag;              // 可否转托管，参考ZtgFlag定义
		int32_t divid_method;          // 基金分红方式
		int32_t update_date;           // 净值更新日期

        // 以下三个字段代替上面三个已删除的数量类字段，倍数由原来扩大100倍改为不扩大倍数，注意做相应倍数处理
        double of_avl_qty;             // 基金可用数，有效小数位两位
        double of_trd_frz_qty;         // 基金交易冻结数，有效小数位两位
        double of_long_frz_qty;        // 基金长期冻结数，有效小数位两位
	};

	//基金确认信息查询 请求
	struct QryFundConfirmInfoReq {
		char32 pos_str;					// 定位串
		int32_t query_num;				// 查询数量
		int32_t begin_date;				// 起始日期，格式为YYYYMMDD
		int32_t end_date;				// 结束日期，格式为YYYYMMDD

		int64_t ta_code;				// 基金公司代码
		char16 ta_account;				// 基金账号
		char32 trans_account;			// 交易账号
		char8 ofcode;					// 基金代码
		int16_t share_class;			// 收费方式, 参考OfShareClass
		char qry_direct;				// 查询方向 0-向后 1-向前 首次值为1
		char tsbztype;					// 查询类型 [micro:A-基金组合编号 B-定投计划编号]
		char128 tsbz;					// 特殊备注消息 不传查tsbztype类型下的全部数据，传值时与tsbztype组合查询
		int32_t order_date;				// 原委托日期，格式为YYYYMMDD
		char32 order_sno;				// 原委托编号
		int32_t match_date;				// 确认日期，格式为YYYYMMDD
		char32 match_sno;				// 确认编号

	};

	//基金确认信息明细
	struct QryFundConfirmInfoRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		int32_t match_date;				// 成交日期
		char32 sno;						// 成交流水号
		int64_t ta_code;				// 基金公司代码
		char16 ta_account;				// 基金帐号
		char32 trans_account;			// 交易帐号
		char8 ofcode;					// 基金代码
		char32 ofname;					// 基金名称
		int32_t order_date;				// 委托日期
		char32 order_sno;				// 委托号
		char16 busitype;				// 业务类型
		char64 businame;				// 业务名称
		int16_t divid_method;			// 默认分红方式，参考FundDividMethod定义
		char32 divid_method_name;		// 默认分红方式说明
		int16_t redeem_type;			// 巨额赎回标志，参考RedeemType定义
		char32 redeem_type_name;		// 巨额赎回标志说明
		char operway;					// 操作方式，参考OperWay定义
		char32 operway_name;			// 操作方式说明
		Amt_t order_amt;				// 委托金额，扩大一万倍
		double order_qty;               // 委托数量，有效小数位两位
		double match_qty;               // 成交数量，有效小数位两位
		Amt_t match_amt;				// 成交金额，扩大一万倍
		Price_t nav;					// 基金单位净值，扩大一万倍
		char32 sendsn;					// 委托流水号（发至登记公司）
		char16 other_ta_account;		// 对方基金帐号
		char32 other_trans_account;		// 对方交易帐号
		char8 other_ofcode;				// 对方基金代码
		char4 errcode;					// 错误代码
		char32 errmsg;					// 错误名称
		Amt_t fee;					    // 所有费用之和，扩大一万倍
		Amt_t backfare;				    // 后端收费，扩大一万倍
		Amt_t feestamptax;			    // 印花税，扩大一万倍
		Amt_t agentfee;				    // 代理费，扩大一万倍
		Amt_t otherfee;				    // 其他费用，扩大一万倍
		Amt_t confirmed_amt;			// 资金发生数，扩大一万倍
		int64_t disc_ratio;				// 分红比例，扩大一亿倍
		char256 extstr2;				// 定投计划编号 
		double trans_qty;				// 目标转换份额，有效小数位两位
		int64_t total_num;				// 总记录数（如果查询有结果，返回记录数;如果无结果 返回0）
		int32_t trdid;                  // 业务类型

	};

	// 基金行情信息查询请求
	struct QryFundMarketDataReq {
		int64_t ta_code;				// 基金公司,0 表示查全部
		char8 ofcode;					// 基金代码, 填空标识查所有
		int32_t p_risk_level;			// 产品风险等级, 枚举见FundProdRiskLevel, 填空标识查所有
		char query_flag;        		// 查询方向 '0'=顺序 '1'=倒序
		int32_t query_num;    			// 查询数量
		char32 pos_str;     			// 定位串, 第一次填空   
	};

	// 基金行情信息查询应答
	struct QryFundMarketDataRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		int64_t ta_code;        		// 基金公司代码
		char32 ta_name;        			// 基金公司名称
		char8 ofcode;        			// 基金代码
		char32 ofname;        			// 基金简称
		int32_t status;        			// 基金状态, 枚举见 FundProdStatus
		char32 status_name;        		// 基金状态名称
		Price_t nav;        			// 基金净值
		Price_t face_price;        		// 基金面值, 低延时两融大集中, 特有字段
		int32_t update_date;        	// 净值更新日期
		char32 rpt_ta_code;        		// 基金发起人, 低延时两融大集中, 特有字段
		int32_t share_class;        	// 收费方式,
		char risk_level;        		// 风险级别
		char32 risk_level_name;         // 风险级别名称
		Amt_t p_buy_low;        		// 个人首次申购下限
		Amt_t d_buy_low;        		// 法人首次申购下限
		Amt_t p_min_amt;        		// 个人首次认购最低金额
		Amt_t d_min_amt;        		// 法人首次认购最低金额
		Amt_t p_add_min_amt;        	// 个人追加认购金额,个人追加申购最低金额
		Amt_t d_add_min_amt;        	// 法人追加认购金额,法人追加申购最低金额
		int32_t begin_date;        		// 认购开始日期
		int32_t end_date;        		// 认购结束日期
		int64_t fund_income;        	// 货币基金万份收益，扩大10万倍
		int64_t yield;        			// 货币基金七日年化收益率，扩大10万倍
		char price_flag;        		// 报价产品标志,[dyc:'0'非报价产品 '1'是报价产品]
		char fm_flag;        			// 资管产品标志,[dyc:'1'是资管产品 '0'非资管产品]
		char of_kind;        			// 基金类型
		int32_t contract;        		// 电子合同签订标志, 枚举见 FundContractSigFlag
		int32_t contract_type;        	// 合同类型, 枚举见 FundContractType
		int32_t p_risk_level;        	// 产品风险等级, 枚举见 FundProdRiskLevel
		int32_t prod_kind;        		// 产品投资分类, 枚举见 FundProdKind
		char prod_term;        			// 产品期限,[dyc:'1' 0-1年 '2' 0-5年 '3' 无期限]
		char prod_video;        		// 双录标识,[dyc:'0' 无需双录 '1' 需要双录]
		int32_t prod_other;        		// 亏损等级,FundProdDeficitLevel
		char p_ctrl_flag;        		// 产品控制类别,[dyc:'0' 无条件通过'1' 不匹配阻断'2' 有条件通过]
		char32 p_ctrl_kinds;        	// 内通条件,允许券商自定义
		char32 p_profe_invest;        	// 专业投资要求,支持复选，空代表无要求
		char p_min_level;        		// 最低拒绝等级,字典同产品等级
		char p_buy_flow;        		// 购买流程
		int64_t p_calm_hours;        	// 冷静期(小时)
		int64_t risk_ver;        		// 风险揭示版本
		int64_t p_per_limit;        	// 人数限制,0代表不限制
		int64_t redeem_days;        	// 赎回资金到帐天数,仅供客户参考，以实际到账时间为准。
        
        // 以下三个字段代替上面三个已删除的数量类字段，倍数由原来扩大100倍改为不扩大倍数，注意做相应倍数处理
        double redeem_top_qty;          // 赎回上限，有效小数位两位
        double redeem_low_qty;          // 赎回下限，有效小数位两位
        double min_hold_qty_new;        // 基金最低持有份额，有效小数位两位
	};

	// 基金开户请求
	struct CreatFundAccountReq {
		int64_t ta_code;				// 基金公司，Y
		char16 ta_account;				// 基金帐号, N, 空表示新基金帐户开户, 非空表示增加交易帐户
		char16 trans_account;			// 交易帐号, N	
		char16 name;					// 帐户姓名, Y
		char64 fullname;				// 帐户全名, Y
		int32_t account_flag;			// 帐户类别, Y, 枚举见 AccountFlag
		int32_t id_type;				// 证件类型, Y, 枚举见 IdentifyType
		char32 id_no;					// 证件号码, Y
		int32_t sex_type;				// 性别, Y, 1-男, 2-女
		char32 deputy_name;				// 法人姓名, N
		int32_t deputy_id_type;			// 法人证件类型, N
		char32 deputy_id_no;			// 法人证件号码, N
		char16 sh_secu_id;				// 上海证券帐户, N
		char16 sz_secu_id;				// 深圳证券帐户, N
		int32_t birth_day;				// 投资人生日, N
		char64 addr;					// 联系地址, Y
		char16 post_id;					// 邮政编码, Y
		char32 tel_no;					// 电话号码, Y
		char32 home_tel_no;				// 住宅电话, N
		char32 work_tel_no;				// 单位电话号码, N
		char32 fax;						// 传真, N
		char32  mobil_no;				// 手机号码, N
		char32 call;					// 传呼机, N
		char32 email;					// 电子邮件, N	
	};

	// 基金开户请求应答
	struct CreatFundAccountRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 sno;						// 委托序号
		int64_t ta_code;				// 基金公司
		char16 ta_account;				// 基金帐号
		char16 trans_account;			// 交易帐号
	};

	// 基金账户信息查询请求
	struct QryFundAccountInfoReq {
		int64_t ta_code;				// 基金公司,0 表示查全部
		int32_t query_num;    			// 查询数量
		char query_flag;        		// 查询方向 0倒序 1升序Y
		char32 pos_str;     			// 定位串, 第一次填空
	};

	// 基金账户信息查询应答
	struct QryFundAccountInfoRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int64_t ta_code;				// 基金公司
		char16 ta_account;				// 基金帐号
		char16 trans_account;			// 交易帐号
		char16 name;					// 帐户姓名
		char64 fullname;				// 帐户全名
		int32_t account_flag;			// 帐户类别, 枚举见 AccountFlag
		int32_t id_type;				// 证件类型, 枚举见 IdentifyType
		char32 id_no;					// 证件号码
		int32_t sex_type;				// 性别, 1-男, 2-女
		char32 deputy_name;				// 法人姓名
		int32_t deputy_id_type;			// 法人证件类型，参考IdentifyType定义
		char32 deputy_id_no;			// 法人证件号码
		char16 sh_secu_id;				// 上海证券帐户
		char16 sz_secu_id;				// 深圳证券帐户
		int32_t birth_day;				// 投资人生日
		char64 addr;					// 联系地址
		char16 post_id;					// 邮政编码
		char32 tel_no;					// 电话号码
		char32 home_tel_no;				// 住宅电话
		char32 work_tel_no;				// 单位电话号码
		char32 fax;						// 传真
		char32  mobil_no;				// 手机号码
		char32 call;					// 传呼机
		char32 email;					// 电子邮件
		int32_t open_date;				// 开户日期
		char status;        			// 帐户状态，参考FundAccountStatus定义
		char multi_flag;        		// 是否多渠道开户标志，参考MultiOpenFlag定义
	};

	// 新私募债委托处理请求
	struct NewPrivatePlacementBondOrderReq {
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 symbol;              // 交易标的，格式为市场.证券代码
		int16_t order_type;         // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;               // 买卖方向，参考OrderSide定义
		Price_t price;              // 委托价格
		int64_t volume;             // 委托数量，股票(单位:股)，债券(上海:手，深圳:张)
		uint16_t policy_id;	        // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台，非必传

		int32_t pricetype;          // 价格类型，参考NewPrivatePlacementBondPriceType定义
		int32_t extkind1;           // 交易类型，参考NewPrivatePlacementBondTradeType定义，(目前填1,指定对手报价)
	    char8 seat_tar;             // 对方交易员代码
	    char32 name_tar;            // 对方交易员名称，非必传
	    char32 tele_tar;            // 对方电话，非必传
	    char32 name_src;            // 本方联系人
	    char32 tele_src;            // 本方电话
	    char16 firmid;              // 约定号，非必传
		int32_t jsdate;             // 结算日期，非必传
		char16 jsspeed;             // 结算速度，非必传
		char16 jsplace;             // 结算场所，非必传
		char32 firstjysno;          // 一级交易商编号，非必传
		char32 ptjysno;             // 普通交易商编号，非必传
		int32_t xjdirection;        // 询价方向，参考NewPrivatePlacementBondChargeEnquiryDirect定义，非必传
		int32_t custtype;           // 是否要校验本方电话是否填写的标记，传1不校验，不传或0则校验必填
	};

	// 新私募债委托处理应答
	struct NewPrivatePlacementBondOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		int32_t order_date;    // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;       // 柜台订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 contract_id;    // 委托合同号，仅集中交易和低延时柜台支持应答中返回
		char32 ex_order_id;    // 交易所订单id，仅低延时柜台支持
	};

	// 新私募债委托撤单请求
	struct NewPrivatePlacementBondCancelOrderReq {
		char32 order_id;      // 被撤的原订单id
		int32_t order_date;   // 委托日期YYYYMMDD
		char32 cl_order_id;   // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
		char32 cl_cancel_id;  // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
	};

	// 新私募债委托撤单应答
	struct NewPrivatePlacementBondCancelOrderRsp {
		char16 account_id;     // 交易账号，目前是资金账号
		int16_t account_type;  // 交易账号类型，参考AccountType定义
		char8 cust_orgid;      // 机构编码
		char8 cust_branchid;   // 分支编码
		char32 order_id;       // 被撤的柜台原订单id
		char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		char32 cl_cancel_id;   // 客户端撤单id，用来引用一个撤单订单，由用户自定义，原样返回
		char32 cancel_id;      // 柜台撤单订单id
		char32 ex_order_id;    // 交易所订单id，仅低延时柜台支持
	};

	// 新私募债可撤委托查询请求
	struct QryNewPrivateBondAviCancelOrderReq {
		char32 order_sno;           // 委托序号, 不送查询全部，非必传
		int32_t order_date;         // 委托日期，格式为YYYYMMDD，非必传
		char32 market;              // 交易市场，如 "SZ" 或者 "SH"，非必传
		char16 stk_code;            // 证券代码，非必传
		char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;          // 查询数量
	};

	// 新私募债可撤委托明细数据
	struct NewPrivateBondAviCancelOrderDetail {
		char16 account_id;                  // 交易账号，目前是资金账号
		char8 cust_orgid;                   // 机构编码
		char8 cust_branchid;                // 分支编码
		int16_t account_type;               // 交易账号类型，参考AccountType定义
		char16 pos_str;                     // 定位串
		char16 server_id;                   // 服务器编号
		char32 order_sno;                   // 委托序号
		int32_t order_group;                // 委托批号
		char16 counter_order_id;            // 委托合同号
		int32_t order_date;                 // 委托日期
		int32_t oper_date;                  // 发生日期
		int32_t oper_time;                  // 委托时间，格式为HHMMSSmmm，首位为0不显示
		char16 cust_id;                     // 客户代码
		char128 cust_name;                  // 客户姓名
		char64 cust_orgname;                // 机构简称
		int16_t currency_type;              // 货币类型，参考CurrencyType定义
		char16 secuid;                      // 股东代码
		char32 symbol;                      // 证券代码，格式为市场.证券ID
		char16 stk_name;                    // 证券名称
		char16 seat;                        // 席位代码
		Price_t order_price;                // 委托价格
		int64_t bond_intr;                  // 国债利息，此处扩大一亿倍
		int16_t order_side;                 // 买卖方向，参考OrderSide定义
		int16_t order_status;               // 委托状态，参考OrderStatus定义
		int64_t order_qty;                  // 委托数量
		int64_t match_qty;                  // 成交数量
		int64_t cancel_qty;                 // 撤单数量
		Amt_t trade_fee;                    // 交易费用
		Amt_t order_frzamt;                 // 委托冻结金额
		Amt_t clear_amt;                    // 清算金额
		Amt_t match_amt;                    // 成交金额
		int16_t cancel_flag;                // 撤单标识，参考CancelFlag定义
		char16 seat_src;                    // 本方交易员
		char16 seat_tar;                    // 对方交易员
		char16 secuid_tar;                  // 对方股东账号
		char32 name_src;                    // 联系人
		char16 tele_src;                    // 联系人电话
		char16 firmid;                      // 约定号
		char8 settle_speed;                 // 结算速度
		char16 settle_place;                // 结算场所
		char32 primary_dealer_id;           // 一级交易商编号
		char32 general_dealer_id;           // 普通交易商编号
		int16_t enqury_direct;              // 询价方向，参考SolidChargeEnquiryDirect定义
		char32 name_tar;                    // 对方交易员名称
		char16 tele_tar;                    // 对方电话
		int16_t price_type;                 // 价格类型，参考SolidChargePriceType定义
		int32_t settle_date;                // 结算日期
		char256 remark;                     // 备注
		int16_t extkind1;                   // 转股回售类型，参考TransferSharesPutBackType定义
	};

	// 固收委托查询请求
	struct QrySolidChargeOrderReq {
		char32 order_sno;           // 委托序号, 不送查询全部，非必传
		char32 market;              // 交易市场，如 "SZ" 或者 "SH"，非必传
		char16 stk_code;            // 证券代码，非必传
		char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;          // 查询数量
	};

	// 固收委托明细数据
	struct SolidChargeOrderDetail {
		char16 account_id;                  // 交易账号，目前是资金账号
		char8 cust_orgid;                   // 机构编码
		char8 cust_branchid;                // 分支编码
		int16_t account_type;               // 交易账号类型，参考AccountType定义
		char16 pos_str;                     // 定位串
		char16 server_id;                   // 服务器编号
		char32 order_sno;                   // 委托序号
		int32_t order_group;                // 委托批号
		char16 counter_order_id;            // 委托合同号
		int32_t order_date;                 // 委托日期
		int32_t oper_date;                  // 发生日期
		int32_t oper_time;                  // 委托时间，格式为HHMMSSmmm，首位为0不显示
		char16 cust_id;                     // 客户代码
		char128 cust_name;                  // 客户姓名
		int16_t currency_type;              // 货币类型，参考CurrencyType定义
		char16 secuid;                      // 股东代码
		char32 symbol;                      // 证券代码，格式为市场.证券ID
		char16 stk_name;                    // 证券名称
		char16 seat;                        // 席位代码
		Price_t order_price;                // 委托价格
		int64_t bond_intr;                  // 国债利息，此处扩大一亿倍
		int16_t order_side;                 // 买卖方向，参考OrderSide定义
		int16_t order_status;               // 委托状态，参考OrderStatus定义
		int64_t order_qty;                  // 委托数量
		int64_t match_qty;                  // 成交数量
		int64_t cancel_qty;                 // 撤单数量
		Amt_t trade_fee;                    // 交易费用
		Amt_t order_frzamt;                 // 委托冻结金额
		Amt_t clear_amt;                    // 清算金额
		Amt_t match_amt;                    // 成交金额
		int16_t cancel_flag;                // 撤单标识，参考CancelFlag定义
		char64 cust_orgname;                // 机构简称
		char16 seat_src;                    // 本方交易员
		char16 seat_tar;                    // 对方交易员
		char16 secuid_tar;                  // 对方股东账号
		char32 name_src;                    // 联系人
		char16 tele_src;                    // 联系人电话
		char16 firmid;                      // 约定号
		char8 settle_speed;                 // 结算速度
		char16 settle_place;                // 结算场所
		char32 primary_dealer_id;           // 一级交易商编号
		char32 general_dealer_id;           // 普通交易商编号
		int16_t enqury_direct;              // 询价方向，参考SolidChargeEnquiryDirect定义
		char32 name_tar;                    // 对方交易员名称
		char16 tele_tar;                    // 对方电话
		int16_t price_type;                 // 价格类型，参考SolidChargePriceType定义
		int32_t settle_date;                // 结算日期
		char256 remark;                     // 备注
	};

	// 报价行情查询
	struct QryQuotationReq {
		int32_t orderside;          // 买卖方向,送空查所有类别
		char8 oppdealperid;		    // 对方交易员编号
	};

	// 报价行情明细信息
	struct QryQuotationDetail {
		char16 account_id;                  // 交易账号，目前是资金账号
		char8 cust_orgid;                   // 机构编码
		char8 cust_branchid;                // 分支编码
		int16_t account_type;               // 交易账号类型，参考AccountType定义
		char16 quoterefid;                  // 交易所报价请求编号
		char16 stkcode;                     // 质押券代码
		char16 stkname;                     // 质押券简称
		int32_t orderside;                  // 买卖类别
		int32_t side;                       // 回购方向,ReverseSide
		int64_t orderprice;                 // 回购利率，扩大一万倍，单位%
		int64_t orderqty;                   // 质押券数量
		int64_t pledgerate;                 // 折算比例，扩大一万倍，单位%
		int32_t ghdays;                     // 回购期限
		int32_t realdays;                   // 实际占款天数
		Amt_t matchamt;                     // 成交金额
		int32_t settleday1;                 // 首次结算日
		int32_t enddate;                    // 回购到期日
		int32_t settleday2;                 // 到期结算日
		Amt_t ghintr;                       // 回购利息
		Amt_t endamt;                       // 到期结算金额
		int64_t lastqty;                    // 质押券面总额，原值，不扩大
		int32_t hgxztype;                   // 到期续作类型,HgxzType
		char16 oldstkcode;                  // 原质押券代码
		Amt_t oldmatchamt;                  // 原成交金额
		int32_t matchdate;                  // 交易所成交日期
		int64_t matchid;                    // 交易所成交编号
		char8 thedealerid;                  // 本方交易商代码
		char32 oppdealername;               // 对方交易商简称
		char32 oppacctname;                 // 对方投资者账户名称
		char8 oppdealperid;                 // 对方交易员代码
		int32_t isstklist;                  // 质押券是否为列表,IsstkList
		char512 othertxt;                   // 备注
	};

	// 协议回购委托查询（沪深）
	struct QryNegotiatedRepurchaseOrderReq {
		int32_t begindate;			// 起始日期，格式为YYYYMMDD
		int32_t enddate;			// 结束日期，格式为YYYYMMDD
		int32_t ordersno;			// 委托序号，非必传
		int32_t orderside;			// 买卖方向，参考OrderSide定义，非必传
		char8 stkcode;              // 质押券代码，非必传
		char32 pos_str;				// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;			// 每页查询数量，最大支持500个
	};

	// 协议回购委托明细
	struct QryNegotiatedRepurchaseOrderDetail {
		char16 account_id;               // 交易账号，目前是资金账号
		char8 cust_orgid;                // 机构编码
		char8 cust_branchid;             // 分支编码
		int16_t account_type;            // 交易账号类型，参考AccountType
		int32_t orderdate;               // 委托日期
		int32_t ordersno;                // 委托序号
		char16 orderid;                  // 委托合同号
		int32_t opertime;                // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示 
		int32_t custid;                  // 客户代码
		char32 symbol;                   // 市场+代码
		char16 secuid;                   // 证券账号
		char16 rptsecuid;                // 报盘股东
		char16 stkname;                  // 质押券名称
		int64_t orderprice;              // 回购利率，扩大一万倍，单位%
		int64_t orderqty;                // 委托数量
		int64_t reportqty;               // 申报数量
		int64_t matchqty;                // 成交数量
		int64_t cancelqty;               // 撤单数量
		Amt_t tradefee;					 // 交易费用
		Amt_t orderfrzamt;				 // 委托冻结金额
		Amt_t clearamt;					 // 清算金额
		int32_t orderside;               // 买卖类别
		int64_t matchid;                 // 成交号码
		int32_t ghdays;                  // 回购期限
		int32_t realdays;                // 实际占款天数
		int32_t settleday1;              // 首日结算日
		int32_t enddate;                 // 到期日期
		int32_t settleday2;              // 到期结算日
		int64_t lastqty;                 // 券面总额，原值，不扩大
		int64_t pledgerate;              // 折算率，扩大一万倍，单位%
		Amt_t matchamt;					 // 成交金额
		Amt_t ghintr;					 // 购回利息
		Amt_t endamt;					 // 到期购回金额
		int32_t bb_matchdate;            // 回购成交日期
		int64_t bb_matchid;              // 回购成交号
		int32_t hgxztype;                // 回购续作标识,HgxzType
		char8 thedealerid;               // 本方交易商号
		char16 thedealname;              // 本方交易商名
		char8 thedealperid;              // 本方交易员号
		char16 thedealpname;             // 本方交易员名
		char16 investorid;               // 本方交易主体代码
		char16 investortype;             // 本方交易主体类型
		char8 theseat;                   // 本方席位
		char32 pawneename;               // 质权人名
		char8 oppdealerid;               // 对方交易商号
		char16 oppdealname;              // 对方交易商名
		char8 oppdealperid;              // 对方交易员号
		char16 oppdealpname;             // 对方交易员名
		char16 oppinvestorid;            // 对方交易主体代码
		char16 oppinvestortype;          // 对方交易主体类型
		char8 oppseat;                   // 对方席位
		char16 oppsecuid;                // 对方账号
		char256 othertxt;                // 特别备注
		int32_t cancelflag;              // 撤单标识
		int32_t orderstatus;             // 委托状态
		char16 bankorderid;              // 被撤合同号
		char64 errmsg;                   // 废单原因
		char64 trdmatchid;               // 初始交易编号
		int32_t stkprop;                 // 股份性质，参考ContractBuyBackShareProperty定义
	};


	struct NegotiatedRepurchaseDealperDetail
	{
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType
		char4 dealerid;             // 交易商代码
		char16 dealername;          // 交易商简称
		char8 dealperid;            // 交易员编号
		char32 dealpername;         // 交易员简称
		int32_t status;             // 状态DealperStatus
	};

	struct NegotiatedRepurchaseOrderCancelReq
	{
		char32 cl_order_id;			// 内部系统委托号
		int32_t cl_order_date;		// 内部系统日期 YYYYMMDD
		char32 cl_cancel_id;		// 内部系统撤单号
		char32 counter_id;			// 柜台委托号
		int32_t counter_date;		// 柜台委托日期
	};

	struct NegotiatedRepurchaseOrderCancelDetail
	{
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType
		char32 cl_order_id;			// 内部系统委托号
		int32_t cl_order_date;		// 内部系统日期 YYYYMMDD
		char32 cl_cancel_id;		// 内部系统撤单号
		char32 counter_id;			// 柜台委托号
		char32 cancel_uuid;			// 撤单uuid，避免风控无法唯一匹配撤单委托，由请求方生成
		char32 cancel_counter_id;   // 撤单柜台委托号
	};

	struct RejectNegotiatedRepurchaseReq
	{
		int32_t orderside;             // 申报类型
		int32_t side;                  // 回购方,ReverseSide
		int32_t matchdate;             // 成交日期
		int64_t matchid;               // 成交编号
		char8 stkcode;                 // 质押券代码
		char4 bankcode;                // 银行代码
		char quotestatus;              // 到期状态,QuoteStatus
		char16 quoterefid;             // 交易所报价请求编号
		int64_t orderprice;            // 回购利率
		int64_t orderqty;              // 委托数量
		int32_t enddate;               // 回购到期日期
		int64_t pledgerate;            // 折算率
		int32_t hgxztype;              // 回购续作标识HgxzType
		int32_t ghdays;                // 回购期限
		int32_t realdays;              // 实际占款天数
		int32_t settleday1;            // 首日结算日
		int32_t settleday2;            // 到期结算日
		int64_t matchamt;              // 成交金额
		int64_t ghintr;                // 购回利息
		int64_t endamt;                // 到期结算金额
		int64_t lastqty;               // 质押券面总额
		char4 oppocomponycode;         // 对交易商代码
		char16 oppocomponyname;        // 对交易商简称
		char8 oppotradercode;          // 对交易员代码
		char32 pawneename;             // 质权人名称
		char128 remark;                // 备注
		char32 cl_order_id;            // 内部系统委托号
		int32_t cl_order_date;         // 内部系统日期 YYYYMMDD
		char8 origcomponycode;		   // 发起方（本方）交易商代码
		char8 origtradercode;		   // 发起方（本方）交易员代码
	};

	struct NegotiatedRepurchaseRejectDetail
	{
		char16 account_id;             // 交易账号，目前是资金账号
		char8 cust_orgid;              // 机构编码
		char8 cust_branchid;           // 分支编码
		int16_t account_type;          // 交易账号类型，参考AccountType
		char32 cl_order_id;            // 内部系统委托号
		int32_t cl_order_date;         // 内部系统日期 YYYYMMDD
		char32 counter_order_id;       // 柜台委托号
		int32_t counter_date;          // 柜台委托日期，夜市委托时与系统日期不同
		char32 contract_id;           // 委托合同号，仅集中交易和低延时支持应答中返回
	};

	struct QryRepurchaseIndexDetail
	{
		char16 account_id;               // 交易账号，目前是资金账号
		char8 cust_orgid;                // 机构编码
		char8 cust_branchid;             // 分支编码
		int16_t account_type;            // 交易账号类型，参考AccountType
		int32_t custid;				     // 客户代码
		char32 custname;                 // 客户姓名
		int64_t shhbhg_fzrate;           // 沪市总负债率上限
		int64_t shzyhg_fzrate;           // 沪市质押负债率上限
		int64_t shxyhg_fzrate;           // 沪市协议负债率上限
		int64_t shhb_rate;               // 沪市当前总负债率，扩大1e8倍
		int64_t shzy_rate;               // 沪市当前质押负债率，扩大1e8倍
		int64_t shxy_rate;               // 沪市当前协议负债率，扩大1e8倍
		int64_t szhbhg_fzrate;           // 深市总负债率上限
		int64_t szzyhg_fzrate;           // 深市质押负债率上限
		int64_t szxyhg_fzrate;           // 深市协议负债率上限
		int64_t szhb_rate;               // 深市当前总负债率，扩大1e8倍
		int64_t szzy_rate;               // 深市当前质押负债率，扩大1e8倍
		int64_t szxy_rate;               // 深市当前协议负债率，扩大1e8倍
		int64_t zyhg_limitamt;           // 质押式回购未到期余额上限
		int64_t shzy_unpaidamt;          // 沪市质押式回购未到期余额
		int64_t szzy_unpaidamt;          // 深市质押式回购未到期余额
		int64_t shxy_unpaidamt;          // 沪市协议式回购未到期余额
		int64_t szxy_unpaidamt;          // 深市协议式回购未到期余额
		int64_t shbondassetdep;          // 沪市债券托管量
		int64_t szbondassetdep;          // 深市债券托管量
	};

	struct QryUnexpiredRepurchaseContractReq
	{
		char16 market;
		char8 stkcode;                 // 质押券代码
		int32_t status;                // 合约状态,ContractBuyBackContractStatus
	};

	struct QryUnexpiredRepurchaseContractDetail
	{
		char16 account_id;               // 交易账号，目前是资金账号
		char8 cust_orgid;                // 机构编码
		char8 cust_branchid;             // 分支编码
		int16_t account_type;            // 交易账号类型，参考AccountType
		int32_t orderdate;               // 委托日期
		char32 sno;                      // 流水号
		char16 orderid;                  // 委托合同号
		int32_t custid;                  // 客户代码
		int32_t matchdate;               // 成交日期
		char16 secuid;                   // 证券账号
		int32_t status;                  // 合约状态,ContractBuyBackContractStatus
		char32 symbol;                   // 代码
		char16 stkname;                  // 质押券名称
		int32_t bsstatus;                // 报送状态,ContractBuyBackBsStatus
		int64_t orderprice;              // 回购利率
		int64_t orderqty;                // 委托数量
		int64_t matchqty;                // 成交数量
		int32_t orderside;               // 买卖类别
		int64_t matchid;                 // 成交号码
		char16 bb_matchid;               // 回购成交号码
		int32_t ghdays;                  // 回购期限
		int32_t realdays;                // 实际占款天数
		int32_t settleday1;              // 首日结算日
		int32_t enddate;                 // 到期日期
		int32_t settleday2;              // 到期结算日
		int64_t lastqty;                 // 券面总额
		int64_t pledgerate;              // 折算率
		int64_t matchamt;                // 成交金额
		int64_t ghintr;                  // 购回利息
		int64_t endamt;                  // 到期购回金额
		int32_t bb_matchdate;            // 回购成交日期
		int32_t hgxztype;                // 回购续作标识HgxzType
		char8 thedealerid;               // 本方交易商号
		char32 thedealname;              // 本方交易商名
		char8 thedealperid;              // 本方交易员号
		char32 thedealpname;             // 本方交易员名
		char8 theseat;                   // 本方席位
		char16 pawneename;               // 质权人名
		char8 oppdealerid;               // 对方交易商号
		char32 oppdealname;              // 对方交易商名
		char8 oppdealperid;              // 对方交易员号
		char32 oppdealpname;             // 对方交易员名
		char8 oppseat;                   // 对方席位
		char16 oppsecuid;                // 对方账号
		char256 othertxt;                // 特别备注
		int32_t contracttype;            // 债权债务,ContractBuyBackContractType
	};

	// 未到期余额查询应答
	struct QryContractBuyBackUnexpiredAmtRsp {
		char16 account_id;               // 交易账号，目前是资金账号
		char8 cust_orgid;                // 机构编码
		char8 cust_branchid;             // 分支编码
		int16_t account_type;            // 交易账号类型，参考AccountType

		int64_t shzy_unpaidamt;   		 // 沪市质押式回购未到期余额
		int64_t szzy_unpaidamt;   		 // 深市质押式回购未到期余额
		int64_t shxy_unpaidamt;   		 // 沪市协议式回购未到期余额
		int64_t szxy_unpaidamt;   		 // 深市协议式回购未到期余额
	};

	// 交易所未结算协议回购查询接口
	struct QryContractBuyBackUnsettledInfoReq {
		char16 symbol;     				// 证券代码，送空查所有证券
		int32_t status;     			// 状态，ContractBuyBackUnsettledQueryStatus
	};


	// 交易所未结算协议回购查询接口应答
	struct QryContractBuyBackUnsettledInfoRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		int64_t bb_matchdate;    		// 成交日期,格式为：YYYYMMDD
		char32 bb_matchid;    			// 成交编号,质押式协议回购到期确认申报、到期续做申报、解除质押申报、换券申报、提前终止申报时上传此编号
		int64_t contracttype;   		// 债权债务,ContractBuyBackContractType
		int64_t orderprice;   			// 回购利率,单位：%，精度：3位
		int64_t enddate;   				// 回购到期日,格式为：YYYYMMDD
		int64_t settleday2;   			// 到期结算日,格式为：YYYYMMDD
		int64_t ghdays;   				// 回购期限,单位：天
		int64_t realdays;   			// 实际占款天数,单位：天
		char16 stkcode;   				// 质押券代码,
		char32 stkname;   				// 质押券简称,
		int64_t stkqty;   				// 质押券数量,单位：张
		int64_t lastqty;   				// 质押券面总额,单位：元
		int64_t pledgerate;   			// 折算比例
		int64_t matchamt;   			// 首次成交金额
		int64_t endamt;   				// 到期结算金额
		int64_t ghintr;   				// 参考应计利息
		int32_t unsettletype;   		// 未结算类型,ContractBuyBackUnsettledQueryType
		int32_t status;   				// 状态,ContractBuyBackUnsettledQueryStatus	
		char32 thedealerid;   			// 本方交易商代码,当为债务时：本方代表正回购方,对方代表逆回购方;当为债权时：本方代表逆回购方,对方代表正回购方
		char32 thedealname;   			// 本方交易商简称,
		char32 thedealperid;   			// 本方交易员代码,
		char32 theseat;   				// 本方交易单元,
		char32 thesecuid;   			// 本方证券账户,
		char32 oppdealerid;   			// 对方交易商代码,
		char32 oppdealname;   			// 对方交易商简称,
		char32 oppdealperid;   			// 对方交易员代码,
		char32 oppseat;   				// 对方交易单元,
		char32 oppsecuid;   			// 对方证券账户,
		char32 pawneename;   			// 质权人名称,
	};

	// 深圳债券协议回购转发成交请求查询请求
	struct QrySZBondContractBuyBackTransmitTradeReq {

		int32_t trdtype;    			// 申报类别, ContractBuyBackTradeType
		char16 stkcode;    				// 证券代码，送空查所有证券
		char32 memberid;    			// 逆回购方交易商代码
		char32 tradercode;    			// 逆回购方交易员代码,
		char32 investorid;    			// 逆回购方交易主体代码
		int32_t changetype;    			// 换券模式, ContractBuyBackChangeType
	};

	// 深圳债券协议回购转发成交请求查询应答
	struct QrySZBondContractBuyBackTransmitTradeRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		int64_t sysdate;       			// 接收日期,
		char32 execid;       			// 执行编号,
		char32 tradereportid;			// 客户成交申报编号,
		int32_t ownertype;       		// 订单所有者类型,ContractBuyBackOwnerType
		int32_t trdtype;       			// 成交申报业务类别,ContractBuyBackTradeType
		int32_t trdsubtype;       		// 成交申报子业务类别,ContractBuyBackSubTradeType
		char32 tradereportrefid;       	// 原客户成交申报编号,
		int64_t transacttime;       	// 回报时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示 
		int64_t pbuid;       			// 回报交易单元,
		int32_t side;       			// 买卖方向,ContractBuyBackOrderSide
		char32 memberid;       			// 正回购方交易商代码,
		char32 investorid;       		// 正回购方交易主体代码,
		int32_t investortype;       	// 正回购方交易主体类型,交易主体类型,ContractBuyBackInvestorType
		char512 investorname;       	// 正回购方客户名称,
		char32 tradercode;       		// 正回购方交易员代码,
		char32 cpmemberid;      		// 逆回购方交易商代码,
		char32 cpinvestorid;       		// 逆回购方交易主体代码,
		int32_t cpinvestortype;       	// 逆回购方交易主体类型,交易主体类型,ContractBuyBackInvestorType
		char32 cptradercode;       		// 逆回购方交易员代码,
		int64_t lastpx;       			// 年利率,单位为百分比（%）
		int64_t cashorderqty;       	// 金额,
		int64_t settlcurramt;       	// 结算金额,
		int64_t expirationdays;       	// 期限,
		char32 trdmatchid;       		// 初始交易编号,
		char16 stkcode;       			// 质押券代码,
		int64_t orderqty;       		// 质押券数量,
		int32_t shareproperty;       	// 质押券股份性质,ContractBuyBackShareProperty
		char16 newstkcode;       		// 解押券代码,
		int64_t neworderqty;       		// 解押券数量,
		int32_t newshareproperty;       // 解押券股份性质,ContractBuyBackShareProperty
		int32_t status;       			// 状态,ContractBuyBackTradeStatus
		char256 memo;					// 备注
		char4096 stkdetail;       		// 质押券明细,仅到期续作变更对手方时展示正回购当前质押券的信息。
										// 格式为：质押券代码|质押数量|质押券股份性质。多个质押券之间以“;”分割。
	};

	// 深圳债券协议回购可质押券查询
	struct QrySZBondContractBuyBackPledgeAvailableStkReq {
		char16 symbol;				    // 质押券代码
		int32_t stkprop;				// 股份性质, 参考ContractBuyBackShareProperty定义，非必传
	};

	// 深圳债券协议回购可质押券查询应答
	struct QrySZBondContractBuyBackPledgeAvailableStkRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		char16 symbol;     				// 证券代码
		char32 stkname;     			// 证券名称
		int64_t ticketprice;     		// 债券面值
		int64_t stkavl;     			// 可质押券数量
		int32_t stkprop;     			// 股份性质, ContractBuyBackShareProperty

	};

	// 深圳债券质押交易商信息查询
	/**
	* 当qrytype=‘0’时，出参为交易商代码(memberid)，交易商简称(membername)，交易商全称(memberfullname)；
	* 当qrytype=‘1’时，出参为交易商代码(memberid)，交易商简称(membername)，交易商全称(memberfullname)，
	*					交易员代码（tradercode），交易员名称（tradername），是否取缺省交易员（isdefaulttrader）；
	* 当qrytype=‘2’时，出参为交易商代码(memberid)，交易商简称(membername)，交易商全称(memberfullname)，
	*					交易主体代码（investorid），交易主体名称（investorname），交易主体类型（investortype）。
	*/
	struct QrySZBondContractBuyBackPledgeMemberReq {

		char qrytype;   				// 查询类型,Y,0-交易商；1-交易员；2-交易主体代码。
		char32 memberid;   				// 交易商代码,Y,
		char32 tradercode;   			// 交易员代码,Y,
		char isdefaulttrader;   		// 是否取缺省交易员,N,是否经纪业务缺省交易员 0-否；1-是
		char32 investorid;   			// 交易主体代码,Y,
		int32_t investortype;   		// 交易主体类型,N, ContractBuyBackInvestorType
	};

	struct QrySZBondContractBuyBackPledgeMemberRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		char32 memberid;  				// 交易商代码, 
		char256 membername;  			// 交易商简称, 
		char256 memberfullname;  		// 交易商全称, 
		char32 investorid;  			// 交易主体代码, 
		char512 investorname;  			// 交易主体名称, 
		char512 investorshortname;  	// 交易主体简称, 
		int32_t investortype;  			// 交易主体类型, ContractBuyBackInvestorType
		char32 tradercode;  			// 交易员代码, 
		char256 tradername;  			// 交易员名称, 
		char isdefaulttrader;  			// 是否取缺省交易员, 是否经纪业务缺省交易员 0-否；1-是
	};

	// 深圳债券质押本地未到期回购合约查询
	struct QrySZBondContractBuyBackPledgeUnexpiredReq {
		char16 symbol;   				// 质押券代码, 送空不判断
		char32 trdmatchid;   			// 初始交易编号, 交易编号，跨交易日唯一
		int32_t status;   				// 合约状态, ContractBuyBackContractStatus
		int32_t bsstatus;   			// 报送状态, ContractBuyBackBsStatus
		int32_t contracttype;   		// 债权债务, ContractBuyBackContractType
	};

	// 深圳债券质押本地未到期回购合约查询应答
	struct QrySZBondContractBuyBackPledgeUnexpiredRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		int64_t orderdate;   			// 委托日期, 
		char32 sno;   					// 流水号, 
		char32 orderid;   				// 委托合同号, 
		int64_t matchdate;   			// 到期日, 到期日可能为非交日日。
		int32_t market;   				// 市场, 
		int32_t status;   				// 合约状态, ContractBuyBackContractStatus
		int32_t bsstatus;   			// 报送状态, ContractBuyBackBsStatus
		int64_t orderprice;   			// 回购利率, 
		int32_t bsflag;   				// 买卖类别, 参考OrderSide定义
		char32 matchid;   				// 成交号码, 
		char32 mateno;   				// 初始交易编号, 交易编号，跨交易日唯一
		int64_t ghdays;   				// 回购期限, 
		int64_t realdays;   			// 实际占款天数, 
		int64_t settleday1;   			// 首日结算日, 
		int64_t enddate;   				// 到期日期, 
		int64_t settleday2;   			// 到期结算日, 若到期日为非交易日，则此日期为此非交易日的下一个交易日。
		int64_t extamt1;   				// 质押券总价值, 本合约所有质押券的面值总额+冻结本金+冻结利息
		int64_t pledgerate;   			// 折算率, 
		int64_t matchamt;   			// 成交金额, 
		int64_t ghintr;   				// 购回利息, 
		int64_t endamt;   				// 到期购回金额, 
		int64_t bb_matchdate;   		// 回购成交日期, 
		char32 bb_matchid;   			// 回购成交号, 
		int32_t hgxztype;   			// 回购续作标识, HgxzType
		char32 thedealerid;   			// 本方交易商号, 
		char256 thedealname;   			// 本方交易商名, 
		char32 thedealperid;   			// 本方交易员号, 
		char256 thedealpname;   		// 本方交易员名, 
		char32 theseat;   				// 本方席位, 
		char256 pawneename;   			// 质权人名, 
		char32 investorid;   			// 本方交易主体代码, 
		int32_t investortype;   		// 本方交易主体类型, ContractBuyBackInvestorType
		char32 oppdealerid;   			// 对方交易商号, 
		char256 oppdealname;   			// 对方交易商名, 
		char32 oppdealperid;   			// 对方交易员号, 
		char256 oppdealpname;   		// 对方交易员名, 
		char32 oppinvestorid;   		// 对方交易主体代码, 
		int32_t oppinvestortype;   		// 对方交易主体类型, ContractBuyBackInvestorType
		char32 oppseat;   				// 对方席位, 
		char32 oppsecuid;   			// 对方账号, 
		char256 othertxt;   			// 特别备注, 
		int32_t contracttype;   		// 债权债务, ContractBuyBackContractType
	};

	// 深圳债券协议回购质押券查询,
	struct QrySZBondContractBuyBackPledgeStkReq {

		char32 trdmatchid;   			// 初始交易编号, 跨交易日唯一
		char16 symbol;   				// 证券代码, 送空不判断
		int64_t orderdate;   			// 委托交易日期，格式为YYYYMMDD
		int32_t shareproperty;   		// 股份性质, ContractBuyBackShareProperty
		int32_t status;   				// 质押状态, ContractBuyBackPledgeStatus
	};

	// 深圳债券协议回购质押券查询,
	struct QrySZBondContractBuyBackPledgeStkRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		int16_t account_type;           // 交易账号类型，参考AccountType

		char32 serverid;   				// 机器编码, 
		int64_t orderdate;   			// 委托交易日期, 
		char32 trdmatchid;   			// 初始交易编号, 跨交易日唯一
		char busikind;   				// 业务类别, 1协议回购
		char16 symbol;   				// 证券代码, 
		char32 stkname;   				// 质押券名称, 
		int64_t zyqty;   				// 质押数量,换出后减少 
		int32_t shareproperty;   		// 股份性质, ContractBuyBackShareProperty
		int32_t status;   				// 质押状态, ContractBuyBackPledgeStatus
		int64_t remainvalue;   			// 面值总额, 
		int64_t frzprincipal;   		// 冻结本金, 
		int64_t frzinterest;   			// 冻结红利, 
	};

	// 深圳协议回购委托
	struct SZNegotiatedRepurchaseOrderReq {
		char8 bankcode;                  // 银行代码
		int32_t side;					 // 回购方向
		int64_t stkprice;				 // 回购利率
		int32_t ghdays;					 // 回购天数
		int64_t orderamt;				 // 成交金额
		int32_t orderside;				 // 买卖类别
		char32 symbol;				     // 标的
		int64_t stkqty;                  // 质押券数量
		char8 origcomponycode;			 // 发起方（本方）交易商代码
		char8 origtradercode;			 // 发起方（本方）交易员代码
		char8 oppocomponycode;			 // 对手方交易商代码
		char8 oppotradercode;			 // 对手方交易员代码
		char16 investorid;				 // 本方交易主体代码
		char16 oppoinvestorid;			 // 对手方交易主体代码
		int32_t acceptsubterm;			 // 是否同意补充条款,AcceptSubterm
		char8 seat;						 // 本方交易单元
		char16 secuname;				 // 本方客户姓名
		int32_t orderrestrictions;		 // 到期续作类型,HgxzType     
		char16 trdmatchid;				 // 初始交易编号
		char16 quoterefid;				 // 对手方成交申报编号
		char256 remark;					 // 备注,补充条款,填本公司对手方的客户代码
		int32_t stkprop;				 // 质押券股份性质,ContractBuyBackShareProperty
		char8 newstkcode;				 // 新质押券代码
		int64_t newstkqty;				 // 新质押券数量
		char4 newstkprop;				 // 新质押券股份性质,ContractBuyBackShareProperty
		char32 cl_order_id;				 // 内部系统委托号
		int32_t cl_order_date;			 // 内部系统日期 YYYYMMDD
		int32_t changetype;				 // 换券模式,ContractBuyBackChangeType
	};

	// 上海债券协议回购委托
	struct NegotiatedRepurchaseOrderReq {
		int32_t orderside;				 // 买卖类别
		int64_t orderprice;				 // 回购利率，扩大一万倍，单位%
		int64_t orderqty;				 // 委托数量
		char32 symbol;                   // 标的
		char8 bankcode;                  // 银行代码，非必传
		int32_t side;					 // 回购方,ReverseSide
		int32_t enddate;				 // 回购到期日期，格式为YYYYMMDD
		int64_t pledgerate;				 // 折算率，扩大一万倍，单位%
		int32_t hgxztype;				 // 回购续作标识,HgxzType
		char4 thedealerid;				 // 本方交易商号
		char8 thedealperid;				 // 本方交易员号
		char4 oppdealerid;				 // 对方交易商号
		char16 oppdealname;				 // 对方交易商名，非必传
		char8 oppdealperid;				 // 对方交易员号
		char32 oppdealpname;			 // 对方交易员名，非必传
		int64_t execid;					 // 成交编号
		int32_t tradedate;				 // 成交日期，格式为YYYYMMDD
		char quotestatus;			     // 到期状态,QuoteStatus
		Amt_t dqhgintr;					 // 到期回购利息，非必传，到期续作申报时需要填写
		char128 remark;					 // 备注，非必传，补充条款，填本公司对手方的客户代码
		int32_t ghdays;					 // 回购期限
		int32_t realdays;				 // 实际占款天数
		int32_t settleday1;				 // 首日结算日，格式为YYYYMMDD
		int32_t settleday2;				 // 到期结算日，格式为YYYYMMDD
		Amt_t matchamt;					 // 成交金额
		Amt_t ghintr;					 // 购回利息
		Amt_t endamt;					 // 到期结算金额
		int64_t lastqty;				 // 质押券面总额
		char16 quoterefid;				 // 交易所报单编号,非公开报价行情查询相关字段
		char32 pawneename;				 // 质权人名称
		char8 orignseat;				 // 发起方申报交易单元，非必传，衡泰填信息
		char32 orignsecuid;				 // 发起方投资者账户，非必传，衡泰填信息
		int32_t acceptsubterm;			 // 是否同意补充条款,AcceptSubterm
		char32 cl_order_id;				 // 内部系统委托号
		int32_t cl_order_date;			 // 内部系统日期 yyyymmdd
	};

	// 债券质押式回购实际占款天数查询
	struct QryBondContractBuyBackPledgeOccupyDays {
		char8 market;					// 市场
		char16 code;					// 证券代码
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询的数量，最大支持500个
	};

	// 债券质押式回购实际占款天数明细
	struct BondContractBuyBackPledgeOccupyDaysDetail {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char32 symbol;					// 格式为市场.证券ID或市场.合约ID
		int64_t order_date;				// 委托日期
		int64_t occupy_days;			// 占款天数
	};

	// 客户新标准券查询应答
	struct QryCustStandardNewBondRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int32_t market;     		// 交易市场
		int32_t stktype;     		// 证券类别
		int64_t bondmarket;     	// 一级质押标准券
		int64_t bondsecu;     		// 二级质押标准券
		int64_t bbback;     		// 标准券解冻
		int64_t bbfrz;     			// 标准券冻结
		int64_t bbavlmarket;     	// 一级标准券可用
		int64_t bbavlsecu;     		// 二级标准券可用
		int64_t llzbondmarket;      // 利率债一级标准券
		int64_t llzbondsecu;      	// 利率债二级标准券
		int64_t llzbbback;     		// 利率债二级标准券解冻
		int64_t llzbbfrz;      		// 利率债二级标准券冻结
		int64_t llzbbavlmarket;     // 一级利率债标准券可用
		int64_t llzbbavlsecu;      	// 二级利率债标准券可用
		int64_t xyzbondmarket;      // 信用债一级标准券
		int64_t xyzbondsecu;      	// 信用债二级标准券
		int64_t xyzbondthree;      	// 信用债三级标准券
		int64_t xyzbbback;      	// 信用债三级标准券解冻
		int64_t xyzbbfrz;      		// 信用债三级标准券冻结
		int64_t xyzbbavlmarket;     // 一级信用债标准券可用
		int64_t xyzbbavlsecu;      	// 二级信用债标准券可用
		int64_t xyzbbavlthree;      // 三级信用债标准券可用
	};

	// 当日逆回购成交查询
	struct QryBondReverseTradeListReq {
		char16 symbol;              // 交易标的代码,不送查询全部
		char32 order_sno;			// 委托序号, 不送查询全部
		char query_flag;        	// 查询方向 '0'=顺序 '1'=倒序
		int32_t query_num;    		// 查询数量
		char32 pos_str;     		// 定位串, 第一次填空   
	};

	// 当日逆回购成交信息
	struct QryBondReverseTradeListRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int64_t orderdate;      	// 委托日期
		char32 ordersno;      		// 委托序号
		int32_t moneytype;      	// 货币
		char16 symbol;      		// 证券名称
		char32 stkname;      		// 证券代码
		int64_t gh_days;      		// 回购天数
		int64_t orderprice;      	// 委托价格
		int64_t orderqty;      		// 委托数量
		int64_t orderfrzamt;     	// 冻结金额
		int64_t matchqty;      		// 成交数量
		int64_t matchamt;      		// 成交金额
		int64_t cancelqty;      	// 撤单数量
		int64_t avgmatchprice;   	// 成交价格
	};

	// 未到期回购查询
	struct QryUnexpiredBondReverseInfoReq {
		int32_t query_num;    		// 查询数量
		char32 pos_str;     		// 定位串, 第一次填空   
	};

	// 未到期回购查询应答
	struct QryUnexpiredBondReverseInfoRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int64_t orderdate;    		// 委托日期
		int64_t ordertime;    		// 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示  
		char32 sno;    				// 流水号
		char16 symbol;    			// 证券代码
		char32 stkname;    			// 证券名称
		int32_t moneytype;    		// 货币代码
		int32_t side;    			// 买卖方向
		Price_t orderprice;    		// 委托价格
		int64_t orderqty;    		// 委托数量
		Amt_t matchamt;    			// 成交金额
		int64_t matchdate;    		// 购回日期
		int32_t stktype;    		// 证券类别
		int64_t bb_matchdate;    	// 回购到期日期
		Amt_t bb_matchclearamt;		// 回购到期金额
		Price_t matchprice;    		// 成交价格
		int64_t gh_days;    		// 购回天数
		char32 secuid;              // 股东代码
	};

	// 债券交易通用委托请求
	struct BondOrderReq {
		char32 symbol;              // 交易标的，格式为市场.证券代码
		int16_t order_type;         // 订单类型，参考OrderType定义，新股申购填限价
		int16_t side;               // 买卖方向，参考OrderSide定义
		Price_t price;              // 委托价格
		int64_t volume;             // 委托数量，股票(单位:股)，债券(上海:手，深圳:张)
		uint16_t policy_id;	        // 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台，非必传
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
	};

	// 债券交易通用委托应答
	struct BondOrderRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int32_t order_date;         // 柜台订单日期(夜市委托则返回下一个交易日)
		char32 order_id;            // 柜台订单id
		char32 contract_id;         // 委托合同号，仅集中交易和低延时柜台支持应答中返回
		char32 ex_order_id;         // 交易所订单id，仅低延时柜台支持
		char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;      // 客户端订单日期
	};

	// 质押存量折算查询
	struct QryBondPledgeAvailableDiscountReq {
		int32_t query_num;    		// 查询数量
		char32 pos_str;     		// 定位串, 第一次填空   
	};

	// 质押存量折算查询应答
	struct QryBondPledgeAvailableDiscountRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		char16 symbol;     			// 证券代码
		int64_t exchrate;    		// 一级折合比例
		int64_t bondsecu;    		// 利率债二级标准券
		int64_t bondlastbal;    	// 上次余额
		int64_t bondbal;    		// 质押库余额
		int64_t bondavl;    		// 质押库可用
		int64_t bondbaln;    		// 质押库余额折算后市值
		int64_t bondavln;    		// 质押库可用折算后市值
		char32 issuer_no;    		// 发行人编号
		char32 issuer_name;    		// 发行人全称
		int64_t credit_bond_jzd;    // 信用债券入库集中度
	};

	// 客户总资产明细查询请求
	struct QryTotalAssetDetailReq {
		char16 account_id;          // 交易账号，目前是资金账号
		int16_t account_type;       // 交易账号类型，参考AccountType定义
	};

	// 客户总资产明细查询应答
	struct TotalAssetDetailRsp {
		char16 account_id;                // 交易账号，目前是资金账号
		int16_t account_type;             // 交易账号类型，参考AccountType定义
		char8 cust_orgid;                 // 机构编码
		char8 cust_branchid;              // 分支编码
		int16_t currency_type;            // 币种，参考CurrencyType定义
		Amt_t total_asset;                // 总资产
		Amt_t fund_total_asset;           // 现金总资产
		Amt_t stock_total_asset;          // 证券总资产
		Amt_t bond_total_asset;           // 债券总资产
		Amt_t offund_total_asset;         // 理财总资产
		Amt_t total_debt;                 // 总负债
		Amt_t bond_asset_rzgh;            // 国债正回购（融资购回）
		Amt_t rzcs_asset;                 // 协议融资资产
		Amt_t otc_gd_bank_asset;          // 光大理财
		Amt_t zy_debts;                   // 股票质押负债
		char32 func_source;               // 结果来源 普通：10602757，信用：10602772 OTC:337615 期货:10760001 期权：11761002
		Amt_t stock_asset_detail;         // 证券资产
		Amt_t zy_wy_mktvalue;             // 股票质押违约卖出市值
		Amt_t zy_mtkvalue;                // 应收股票质押市值
		Amt_t en_mktvalue;                // 应收约定购回市值
		Amt_t stock_asset_uncome;         // 待交收证券资产
		Amt_t bond_asset_detail;          // 债券资产
		Amt_t bond_asset_zy;              // 债券质押资产
		Amt_t xyzy_asset;                 // 协议债券质押资产
		Amt_t en_debts;	                  // 约定购回负债
		Amt_t total_credit_quota;         // 授信可用的额度
		Ratio_t credit_assure_scale;      // 维持担保比例
		Amt_t float_profit;               // 证券资产总浮动盈亏
		Amt_t fundassetstkwxxj;        // 网下现金认购资产
		Amt_t fundassetadjust_xsf;      // 新三板新股申购在途资金
		Amt_t fundassetadjust_qt;       // 配股配债在途资金
	};

	//留存业务客户资产总值查询
	struct QryRetainedTotalAssetsReq {
		int16_t currency_type;            // 币种，参考CurrencyType定义
	};

	//留存业务客户资产总值查询明细
	struct RetainedTotalAssetsRsp {
		char16 account_id;                // 交易账号，目前是资金账号
		int16_t account_type;             // 交易账号类型，参考AccountType定义
		char8 cust_orgid;                 // 机构编码
		char8 cust_branchid;              // 分支编码
		int16_t currency_type;            // 币种，参考CurrencyType定义
		Amt_t fund_asset_total;           // 总资产
		Amt_t fund_asset;                 // 资金
		Amt_t fund_asset_stk;             // 证券资产
		Amt_t fund_asset_of;              // 开放式基金资产
		Amt_t fund_asset_bond;            // 非交易所债券
		Amt_t fund_asset_rzgh;            // 融资
		Amt_t fund_asset_rqgh;            // 融券
		Amt_t fund_asset_stkzy;           // 质押资产
		Amt_t fund_asset_bjhg;            // 报价回购资产
		Amt_t fund_asset_szbjhg;          // 深圳报价回购资产
		Amt_t fund_asset_rzcs;            // 协议融资
		Amt_t fund_asset_rqcs;            // 协议融券
		Amt_t fund_asset_stkxyzy;         // 协议质押库资产
		Amt_t fund_asset_otcend;          // OTC到期,该部分到期后放到资金资产中
		int32_t custtype;                 // 客户类型，参考CustType定义
		char status;                      // 资金帐户状态，参考AccountStatus定义
	};

	//留存业务客户资产总值分类查询
	struct QryRetainedTotalAssetsTypeReq {
		int16_t currency_type;            // 币种，参考CurrencyType定义
	};

	//留存业务客户资产总值分类查询明细
	struct RetainedTotalAssetsTypeRsp {
		char16 account_id;                // 交易账号，目前是资金账号
		int16_t account_type;             // 交易账号类型，参考AccountType定义
		char8 cust_orgid;                 // 机构编码
		char8 cust_branchid;              // 分支编码
		int16_t currency_type;            // 币种，参考CurrencyType定义
		char4 status;                     // 资金帐户状态，参考AccountStatus定义
		Amt_t fund_asset_adjust_qt;       // 配股配债在途资金
		Amt_t fund_asset_adjust_hgt;      // 港股通在途资金
		int32_t custtype;                 // 客户类型，参考CustType定义
		Amt_t fund_asset_bal;             // 可用资金
		Amt_t fund_asset_avl;             // 到帐余额
		Amt_t fund_asset_total;           // 总资产
		Amt_t fund_asset_totalnew;        // 总资产新
		Amt_t fund_asset;                 // 资金资产
		Amt_t fund_asset_ggt;             // 港股通T+1日未交收资金
		Amt_t fund_asset_stktotal;        // 证券总资产
		Amt_t fund_asset_stk;             // 证券资产
		Amt_t fund_asset_bondtotal;       // 债券总资产
		Amt_t fund_asset_bond;            // 债券资产
		Amt_t fund_asset_rzgh;            // 国债正回购负值
		Amt_t fund_asset_rqgh;            // 国债逆回购
		Amt_t fund_asset_stkzy;           // 债券质押资产
		Amt_t fund_asset_rzcs;            // 协议融资负值
		Amt_t fund_asset_rqcs;            // 协议融券
		Amt_t fund_asset_stkxyzy;         // 协议债券质押资产
		Amt_t fund_asset_adjust;          // 待交收证券资产
		Amt_t fund_asset_oftotal;         // 理财总资产
		Amt_t fund_asset_of;              // 基金资产不包含现金管家,不提供OTC及多金
		Amt_t fund_asset_bjhgsh;          // 上海报价回购
		Amt_t fund_asset_bjhgsz;          // 深圳报价回购
		Amt_t fund_asset_ofuncome;        // 基金认申购定投未确认在途资金
		Amt_t fund_asset_xjgj;            // 现金管家
		Amt_t fund_asset_zfzz;            // 支付转账
		Amt_t fund_asset_jdlsec;          // 君得利二号
		Amt_t fund_asset_fjjj;            // 分级基金
		Amt_t fund_asset_curdayrqgh;      // 融券购回当日到期
		Amt_t fund_asset_curdayrzgh;      // 融资购回当日到期
		Amt_t fund_asset_otcend;          // OTC当日到期这部分延期到6月8号
		Amt_t debts_total;                // 总负债负值
		Amt_t zy_mtkvalue;                // 应收股票质押市值
		Amt_t zy_debts;                   // 股票质押负债负值
		Amt_t en_mktvalue;                // 应收约定购回市值
		Amt_t en_debts;                   // 约定购回负债负值
		Amt_t zywy_mkt_value;             // 股票质押违约卖出市值
		Amt_t fund_asset_matchrqgh;       // 国债逆回购当日成交
		Amt_t sumprofitamt;               // 证券资产总浮动盈亏
		Amt_t fund_asset_stkwxxj;         // 网下现金认购资产
		Amt_t fund_asset_adjust_xsf;      // 新三板新股申购在途资金
	};

	// 留存业务， 查询资金账户
	struct QueryRetainedFundReq {
		int16_t currency_type;            // 币种，参考CurrencyType定义
	};

	// 留存业务， 查询资金账户应答
	struct RetainedFundDetailRsp {
		char16 account_id;			// 交易账号，目前是资金账号
		int16_t account_type;		// 交易账号类型，参考AccountType定义
		char8 cust_orgid;			// 机构编码
		char8 cust_branchid;		// 分支编码

		int16_t currency_type;		// 货币
		Amt_t balance;				// 资金余额
		Amt_t fund_avl;				// 资金可用金额
		Amt_t fund_buy;				// 买入冻结
		Amt_t fund_sale;			// 卖出解冻
		Amt_t market_value;			// 资产总值
		Amt_t fund;					// 资金资产
		Amt_t stk_value;			// 市值
		Amt_t maxdraw;				// 可取金额
		char4 bank_code;			// 银行代码
		char32 bank_name;			// 银行名称
		Amt_t fund_bjhg_avl;		// 报价回购可用资金
	};

	// 留存业务， 查询持仓列表
	struct QueryRetainedPositionListReq {
		char8 market;					// 交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
		char16 stk_code;				// 证券代码，非必传
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询数量
	};

	// 留存业务， 查询持仓列表应答
	struct RetainedPositionDetailRsp {
		char16 account_id;				// 交易账号，目前是资金账号
		int16_t account_type;			// 交易账号类型，参考AccountType定义
		char8 cust_orgid;				// 机构编码
		char8 cust_branchid;			// 分支编码

		char32 symbol;        			// 交易标的，格式为市场.证券ID或市场
		char32 secuid;        			// 股东代码        
		char32 linkstk;       			// 关联代码，基础证券代码
		char32 stkname;       			// 证券名称     
		char64 stkfullname;   			// 证券全称，不存在时返stkname  
		int32_t currency_type;     		// 货币         
		int64_t stkbal;        			// 股份余额     
		int64_t stkavl;       			// 股份可用     
		Amt_t buycost;      			// 当前成本     
		Price_t costprice;    			// 成本价格     
		Amt_t mktval;       			// 市值         
		Amt_t income;       			// 盈亏         
		Amt_t proincome;    			// 累计盈亏     
		int64_t stkqty;       			// 当前拥股数   
		Price_t lastprice;    			// 最新价格     
		Price_t extlastprice; 			// 修正最新价格
		int32_t stktype;      			// 证券类型     
		int64_t stkdiff;      			// 可申赎数量   
		int64_t stkcantrans;  			// 股份可转     
		int64_t stklastbal;   			// 上日余额     
		int64_t stkfrz;       			// 股份冻结     
		int64_t stkunfrz;     			// 股份解冻     
		Price_t closeprice;   			// 昨日收盘     
		int32_t custtype;     			// 客户类型     
		char8 seat;         			// 席位代码     
		int64_t stkuncomebuy; 			// 股份买入未交收
		int64_t stkuncomesale;			// 股份卖出未交收
		int64_t stkbuy;       			// 股份买入解冻
		int64_t stksale;      			// 股份卖出冻结
		Amt_t bondintr;     			// 利息
	};

	// 留存业务， 查询委托列表
	struct QueryRetainedOrderListReq {
		char8 market;					// 交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
		char16 stk_code;				// 证券代码，非必传
		char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;				// 查询数量
	};

	// 留存业务， 查询委托列表应答
	struct RetainedOrderStatusDetailRsp {
		char16 account_id;				// 交易账号，目前是资金账号
		int16_t account_type;			// 交易账号类型，参考AccountType定义
		char8 cust_orgid;				// 机构编码
		char8 cust_branchid;			// 分支编码

		char32 symbol;        			// 交易标的，格式为市场.证券ID或市场
		int32_t retainedbstype;        	// 留存A类业务分类， RetainedBSType
		int64_t orderdate;        		// 委托日期      
		char32 ordersno;        		// 委托序号      
		int32_t currency_type;        	// 货币            
		char32 secuid;        			// 股东代码      
		int32_t side;        			// 买卖方向      
		int32_t order_type;        		// 买卖类别
		char32 orderid;        			// 申报合同序号  
		int64_t reporttime;        		// 报盘时间      
		int64_t opertime;        		// 委托时间         
		char32 stkname;        			// 证券名称       
		char64 stkfullname;        		// 证券全称,不存在时返stkname
		Price_t orderprice;        		// 委托价格      
		int64_t orderqty;        		// 委托数量      
		Amt_t orderfrzamt;        		// 冻结金额      
		int64_t matchqty;        		// 成交数量      
		Amt_t matchamt;        			// 成交金额      
		int64_t cancelqty;        		// 撤单数量      
		int32_t status;        			// 委托状态      
		char8 seat;        				// 交易席位      
		int32_t cancelflag;        		// 撤单标识      
		char64 remark;        			// 备注信息
		char32 bankfrzsno;        		// 银行冻结流水号
		char8 oppseat;        			// 对方席位
		Price_t matchprice;        		// 成交价格
		Amt_t fundavl;        			// 资金可用金额
		int64_t operdate;        		// 交易日期
		int32_t credit_type;        	// 信用交易类型
		int64_t extqty1;        		// 成交数量
	};

	// 留存业务 撤单委托查询请求
	struct QryRetainedCancelOrderListReq {
		int32_t order_date;					// 委托日期，格式为YYYYMMDD，非必传
		char32 symbol;						// 标的代码，格式为市场.证券ID，非必传
		int16_t currency_type;				// 币种，参考CurrencyType定义，非必传
		char32 counter_order_id;			// 柜台委托号，非必传
		char bjs_reject_flag;				// 北交所剔除标识，'0' 表示不剔除，'1'表示剔除北交所，默认 '0'
		char32 pos_str;						// 定位串，填""表示第一次从头开始查
		int32_t query_num;					// 查询数量，填0表示不指定
	};

	// 留存业务 撤单委托详情
	struct RetainedCancelOrderRecord {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 pos_str;                 // 定位串，下次查询索引号
		char32 counter_order_id;		// 柜台委托号
		char32 order_group;				// 委托批号
		char32 contract_id;				// 合同序号
		int32_t order_date;				// 委托日期，格式为YYYYMMDD
		int64_t order_time;				// 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
		char16 secuid;                  // 证券账户(股东代码)
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char32 stk_name;                // 证券名称
		int16_t order_side;				// 买卖方向，参考OrderSide定义
		Price_t order_price;			// 委托价格，扩大一万倍，默认币种为人民币，参考汇率字段有值时币种为港币
		int64_t order_qty;				// 委托数量
		int64_t match_qty;				// 成交数量
		Amt_t match_amt;				// 成交金额，扩大一万倍
		int16_t order_status;           // 委托状态，参考OrderStatus定义
		char64 creditdigest_name;		// 信用摘要名称
		ExchangeRatio_t refer_rate;     // 参考汇率，扩大一亿倍
	};

	// 留存业务 当日分笔成交查询请求
	struct QryRetainedTradeListReq {
		char32 symbol;						// 标的代码，格式为市场.证券ID，非必传
		char32 counter_order_id;			// 柜台委托号，非必传
		char32 pos_str;						// 定位串，填""表示第一次从头开始查
		int32_t query_num;					// 查询数量，填0表示不指定
	};

	// 留存业务 当日分笔成交详情
	struct RetainedTradeRecord {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 pos_str;                 // 定位串，下次查询索引号
		int32_t match_date;				// 成交日期，格式YYYYMMDD
		char16 secuid;                  // 证券账户(股东代码)
		int16_t order_side;				// 买卖方向，参考OrderSide定义
		char32 counter_order_id;		// 柜台委托号
		char32 contract_id;				// 合同序号
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char32 stk_name;                // 证券名称
		int64_t match_time;				// 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
		char32 match_id;				// 成交序号
		Price_t match_price;			// 成交价格，扩大一万倍
		int64_t match_qty;				// 成交数量
		Amt_t match_amt;				// 成交金额，扩大一万倍
		Price_t order_price;			// 委托价格，扩大一万倍
		int64_t order_qty;				// 委托数量
		char32 order_group;				// 委托批号
		int16_t currency_type;			// 币种，参考CurrencyType定义
		char oper_way;					// 操作方式，集中交易使用，参考OperWay定义
		char32 seat;					// 席位号
		char32 sno;						// 流水号
        int16_t match_type;             // 成交类型，参考TradeReportType定义
	};

	// 留存业务 当日汇总成交查询请求
	struct QryRetainedTradeListTotalReq {
		char32 symbol;						// 标的代码，格式为市场.证券ID，非必传
		int16_t currency_type;				// 币种，参考CurrencyType定义，非必传
		char32 counter_order_id;			// 柜台委托号，非必传
		char bjs_reject_flag;				// 北交所剔除标识，'0' 表示不剔除，'1'表示剔除北交所，默认 '0'
		char32 pos_str;						// 定位串，填""表示第一次从头开始查
		int32_t query_num;					// 查询数量，填0表示不指定
	};

	// 留存业务 当日汇总成交详情
	struct RetainedTradeTotalRecord {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码
		char32 pos_str;                 // 定位串，下次查询索引号
		int32_t match_date;				// 成交日期，格式YYYYMMDD
		char16 secuid;                  // 证券账户(股东代码)
		int16_t order_side;				// 买卖方向，参考OrderSide定义
		char32 counter_order_id;		// 柜台委托号
		char32 contract_id;				// 合同序号
		char32 symbol;                  // 标的代码，格式为市场.证券ID
		char32 stk_name;                // 证券名称
		int64_t match_time;				// 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
		char32 match_id;				// 成交序号
		Price_t match_price;			// 成交价格，扩大一万倍，默认币种为人民币，港股通查询时币种为港币
		int64_t match_qty;				// 成交数量
		Amt_t match_amt;				// 成交金额，扩大一万倍
		Price_t order_price;			// 委托价格，扩大一万倍，默认币种为人民币，港股通查询时币种为港币
		int64_t order_qty;				// 委托数量
		char32 order_group;				// 委托批号
		int16_t currency_type;			// 币种，参考CurrencyType定义
		char oper_way;					// 操作方式，集中交易使用，参考OperWay定义
		char32 seat;					// 席位号
		char32 sno;						// 流水号
		char128 remark;					// 备注
	};

	// 查询新股中签扣款顺序请求
	struct QryIPOLotteryDeductSeqReq {
		char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		int32_t query_num;          // 查询数量
	};

	// 新股中签扣款顺序明细数据
	struct IPOLotteryDeductSeqDetail {
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		int32_t busi_date;          // 业务日期，格式为YYYYMMDD
		char32 sno;                 // 流水号
		char16 cust_id;             // 客户代码
		int16_t currency_type;      // 货币类型，参考CurrencyType定义
		char32 symbol;              // 证券代码，格式为市场.证券ID
		char32 secuid;              // 证券账号（股东代码）
		int16_t security_type;      // 证券类别，参考SecurityTypeDetail定义
		int16_t share_nature;       // 股份性质，参考StockProperty定义
		char32 stk_name;            // 证券名称
		char16 busi_type;           // 业务类别
		int32_t order_date;         // 委托日期，格式为YYYYMMDD
		int64_t match_qty;          // 成交数量，扩大一万倍
		Price_t match_price;        // 成交价格
		char32 mate_no;             // 配售配号
		char32 ballot_no;           // 中签号码
		int16_t giveup_flag;        // 放弃标志，参考GiveupFlag定义
		int64_t hit_qty;            // 中签数量，扩大一万倍
		Amt_t pay_amt;              // 应缴款金额
		Amt_t settle_pay_amt;       // 已缴款金额
		int32_t pay_date;           // 缴款日期
		int64_t giveup_qty;         // 放弃数量，扩大一万倍
		Amt_t giveup_amt;           // 放弃金额
		int16_t giveup_status;      // 放弃状态，参考GiveupStatus定义
		int16_t giveup_able;        // 是否可放弃
		int32_t serial_no;          // 扣款顺序
		char32 pos_str;             // 查询定位串
		int32_t total_num;          // 数据库总条数
	};

	// 设置新股中签扣款顺序请求
	struct SetIPOLotteryDeductSeqReq {
		int32_t busi_date;          // 业务日期，格式为YYYYMMDD
		char32 sno;                 // 流水号
		int32_t serial_no;          // 扣款顺序
	};

	// 设置新股中签扣款顺序响应数据
	struct SetIPOLotteryDeductSeqRsp {
		char16 account_id;          // 交易账号，目前是资金账号
		char8 cust_orgid;           // 机构编码
		char8 cust_branchid;        // 分支编码
		int16_t account_type;       // 交易账号类型，参考AccountType定义
		char256 ret_msg;            // 执行信息
		int64_t msg_code;           // 信息代码
	};

	// 中签资金冻结后放弃认购请求
	struct IPOLotteryAbandonReq {
		char8 market;              // 市场，SH、SZ等，参考本文件中定义
		char32 symbol;             // 交易标的，格式为市场.证券ID或市场.合约ID
	};

	// 中签资金冻结后放弃认购应答
	struct IPOLotteryAbandonRsp {
		char16 account_id;         // 交易账号，目前是资金账号
		int16_t account_type;      // 交易账号类型，参考AccountType定义
		char8 cust_orgid;          // 机构编码
		char8 cust_branchid;       // 分支编码
		char32 sno;                // 流水号
	};

	// 港股通投票请求
	struct HKStockVoteReq {
		char16 symbol;     				// 证券代码, Y, 
		int32_t business_type;   		// 业务类型, Y, HKBusinessType, 沪港通：H62； 深港通：TPSB。 
		int32_t report_type;   			// 申报类型, Y, HKBusinessReportType, 沪港通：HSB，深港通：WT、CX
		char32 isin;                    // 股票ISIN编码，集中交易必填，低延时可不填
		char32 note_proposal;     		// 公告编号, Y,
		char32 voting_proposal;     	// 议案编号, Y,	
		int64_t affirmative_votes;		// 赞成数量，扩大100倍	Y	
		int64_t negative_votes;			// 反对数量，扩大100倍	Y	
		int64_t abstention_votes;		// 弃权数量，扩大100倍	Y
	};

	// 港股通投票请求应答
	struct HKStockVoteRsp {
		char16 account_id;              // 交易账号，目前是资金账号
		int16_t account_type;           // 交易账号类型，参考AccountType定义
		char8 cust_orgid;               // 机构编码
		char8 cust_branchid;            // 分支编码

		char32 apply_sno;     			// 申报编号
		int32_t apply_date;    			// 申报日期 
	};


// 深圳固收债券报价申报委托请求
struct SZBondQuotationOrderReq {
    char32 cl_order_id;                 // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    int32_t cl_order_date;              // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    char32 symbol;                      // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
    int16_t side;                       // 买卖方向，参考OrderSide定义，目前仅支持106，107，112，113类型
    Price_t price;                      // 委托价格
    int64_t volume;                     // 委托数量
    char16 quotereqid;                  // 消息编号，非必传，仅询价成交填写。当询价成交报价申报时填写转发询价请求的QuoteReqID; 
    char128 remark;                     // 备注信息，必传，买卖方向为点击成交106，107时置为空
    int32_t pretradeanonymity;          // 是否匿名， 0=显名, 1=匿名，仅买卖方向为点击成交106，107时必传
    int32_t acceptsubterm;              // 是否同意补充条款， 0=不同意, 1=同意，仅买卖方向为询价成交112，113时必传
    char8 origcomponycode;              // 发起方（本方）交易商代码
    char16 origtradercode;              // 发起方（本方）交易员代码
    char16 originvestorid;              // 发起方（本方）本方交易主体代码
    char64 secuname;                    // 发起方（本方）客户名称，非必传，本方交易主体类型为3-机构经纪时，必传
    char8 oppocomponycode;              // 对手方交易商代码，非必传，买卖方向为询价成交112，113时，必传
    char16 oppotradercode;              // 对手方交易员代码，非必传，买卖方向为询价成交112，113时，必传
    char16 oppoinvestorid;              // 对手方交易主体代码，非必传，买卖方向为询价成交112，113时，必传
	int32_t settltype;                  // 结算方式,参考SettleType
	int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
};

// 深圳固收债券报价回复申报委托请求
struct SZBondQuotationReplyOrderReq {
    char32 cl_order_id;                 // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    int32_t cl_order_date;              // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    char32 symbol;                      // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
    int16_t side;                       // 买卖方向，参考OrderSide定义,目前仅支持108，109，114，115类型
    int16_t noquotecount;               // 报价消息个数，与noquotestr串中消息组个数对应,请填写[1~100]任意整数
    char1024 noquotestr;                // 报价消息串格式为“报价消息编号|报价价格|报价数量”，组组间以英文分号“;”分隔，组内字段以“|”分隔。
                                        // 填写格式如下：M000000001|1.0000|100;M000000002|2.0000|200;...
                                        // 报价消息串内每组数据的报价消息编号、报价价格、报价数量均不可为空，且报价消息编号不可重复。
    char8 origcomponycode;              // 发起方（本方）交易商代码
    char16 origtradercode;              // 发起方（本方）交易员代码
    char16 originvestorid;              // 发起方（本方）本方交易主体代码
    char64 secuname;                    // 发起方（本方）客户名称，非必传，本方交易主体类型为3-机构经纪时，必传
	int32_t settltype;                  // 结算方式,参考SettleType
	int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
};

// 深圳固收债券询价请求申报委托请求
struct SZBondInquiryOrderReq {
    char32 cl_order_id;                 // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    int32_t cl_order_date;              // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    char32 symbol;                      // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
    int16_t side;                       // 买卖方向，参考OrderSide定义,目前仅支持110，111类型
    int64_t volume;                     // 委托数量
    char128 remark;                     // 备注信息
    int32_t pretradeanonymity;          // 是否匿名， 0=显名, 1=匿名
    int32_t oppdatacount;               // 对手方个数，仅询价成交询价请求申报时填写，且一笔询价请求中对手方个数最多允许申报20个。
                                        // 与对手方交易单元字段oppdatastr个数对应。
    char512 oppdatastr;                 // 对手方交易信息，仅询价成交询价请求申报时填写；当询价成交询价请求申报时填写对方交易信息串。
                                        // 对手方交易信息串填写时,多个对手方交易信息以英文分号“;”分隔,每组对手方交易商|对手方交易主体类型|对手方交易主体代码之间以“|”分隔。
                                        // 例如：000612|04|3600000005;000612|03|3600000006;...
                                        // 对手方交易主体代码填全空格，代表对指定交易商代码、指定交易主体类型的全部交易主体代码进行询价。
                                        // 对手方交易信息组内每组数据的对手方交易商代码和交易主体类型不可为空，且不可重复：
                                        // 当对手方交易主体代码为空时，则对手方交易商代码、对手方交易主体类型为主键不可重复。
                                        // 当对手方交易主体代码不为空时，则对手方交易商代码、对手方交易主体类型、对手方交易主体代码为主键不可重复。
                                        // 目前对手方交易主体代码必须填空，否则会被废单。
    char16 linkman;                     // 本方联系人，非必传
    char32 linkway;                     // 本方联系方式，非必传
    char8 origcomponycode;              // 发起方（本方）交易商代码
    char16 origtradercode;              // 发起方（本方）交易员代码
    char16 originvestorid;              // 发起方（本方）本方交易主体代码
    char64 secuname;                    // 发起方（本方）客户名称，非必传，本方交易主体类型为3-机构经纪时，必传
	int32_t settltype;                  // 结算方式,参考SettleType
	int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
};

// 深圳固收债券当日委托查询请求
struct QuerySZBondOrderReq {
    char8 market;                       // 交易市场，SH、SZ等，参考本文件中定义
    char32 order_id;                    // 柜台订单id，非必传
    char256 side;                       // 买卖方向，参考OrderSide定义，非必传，多送时，每个买卖方向间以英文逗号分隔
    int32_t cancelflag;                 // 撤单标识，参考CancelFlag定义，非必传
    char32 stkcode;                     // 质押券代码
    char qry_direct;                    // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
    char32 pos_str;                     // 定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串, 格式如下：orderdate|ordersno
    int32_t query_num;                  // 查询条数
};

// 深圳固收债券当日委托明细
struct SZBondOrderDetail {
    char16 account_id;                 // 交易账号，目前是资金账号
    int16_t account_type;              // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                  // 机构编码
    char8 cust_branchid;               // 分支编码
    int32_t orderdate;                 // 委托日期
    int64_t opertime;                  // 委托时间  
    char32 order_id;                   // 柜台订单id，对于撤单是柜台撤单id
    char32 cl_order_id;                // 客户端订单id，对应到客户端的原订单id
    char32 contract_id;                // 委托合同号
    char16 cust_id;                    // 客户代码
    char32 secuid;                     // 证券账号 
    char32 rptsecuid;                  // 报盘股东
    char32 stkcode;                    // 交易标的
    char32 stkname;                    // 证券名称
    int64_t orderprice;                // 委托价格，竞买成交(买卖类别为：竞买成交竞买预约申报和竞买成交竞买发起申报时：存放价格下限
    int64_t orderqty;                  // 委托数量  
    int64_t reportqty;                 // 申报数量  
    int64_t matchprice;                // 成交价格
    int64_t matchqty;                  // 成交数量
    int64_t cancelqty;                 // 撤单数量
    int64_t tradefee;                  // 交易费用
    int64_t orderfrzamt;               // 委托冻结金额
    int64_t clearamt;                  // 清算金额
    int32_t bsflag;                    // 买卖标识，参考OrderSide定义
    char32 matchid;                    // 成交号码 交易所成交编号 
    char32 thedealerid;                // 本方交易商号  
    char256 thedealname;               // 本方交易商名  
    char32 thedealperid;               // 本方交易员号  
    char256 thedealpname;              // 本方交易员名  
    char16 theinvestorid;              // 本方交易主体代码  
    int32_t theinvestortype;           // 本方交易主体类型 
    char32 theseat;                    // 本方席位  
    char256 thesecuname;               // 本方投资者账户名称 
    char32 oppdealerid;                // 对手方交易商号  
    char256 oppdealname;               // 对手方交易商名  
    char32 oppdealperid;               // 对手方交易员号  
    char256 oppdealpname;              // 对手方交易员名  
    char16 oppinvestorid;              // 对手方交易主体代码  
    int32_t oppinvestortype;           // 对手方交易主体类型 
    char32 oppseat;                    // 对手方席位  
    int32_t cancelflag;                // 撤单标识，参考CancelFlag定义
    int32_t orderstatus;               // 委托状态，参考OrderStatus定义
    char32 oldorderid;                 // 被撤合同号
    char128 errmsg;                    // 废单原因
    char16 confirmid;                  // 约定号
    char4096 quotestr;                 // 附加信息 当报价回复申报时填为报价消息串;当询价请求申报时为对手方交易信息串
    char256 remark;                    // 备注
    int32_t pretradeanonymity;         // 是否匿名 Y 0=显名, 1=匿名 
    int32_t privatequote;              // 私有报价 0=私有报价（Private Quote）;1=公开报价（Public Quote）
    int32_t settltype;                 // 结算方式 参考SettleType定义
    int32_t settlperiod;               // 结算周期 参考SettlePeriod定义
    int32_t recnum;                    // 接口记录号 
    int32_t maxfloor;                  // 可显示数量，竞买成交
                                       // (买卖类别为：竞买成交竞买预约申报、竞买成交竞买发起申报和竞买成交应价申报)时：存放竞买成交方式
    char32 pos_str;                    // 定位串 格式如下：orderdate|ordersno
};


// 深圳固收当日委托扩展信息查询请求
struct QuerySZBondOrderExtendInfoReq {
    char8 market;                       // 交易市场，SH、SZ等，参考本文件中定义
    char32 order_id;                    // 柜台订单id，非必传
    char256 side;                       // 买卖方向，参考OrderSide定义，非必传，多送时，每个买卖方向间以英文逗号分隔
    int32_t cancelflag;                 // 撤单标识，参考CancelFlag定义，非必传
    char32 stkcode;                     // 质押券代码
	char qry_direct;                    // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认倒序
    char32 pos_str;                     // 定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串, 格式如下：orderdate|ordersno
    int32_t query_num;                  // 查询条数
};


// 深圳固收当日委托扩展信息明细
struct SZBondOrderExtendInfoDetail {
    char16 account_id;                 // 交易账号，目前是资金账号
    int16_t account_type;              // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                  // 机构编码
    char8 cust_branchid;               // 分支编码
    int32_t orderdate;                 // 委托日期
    char32 order_id;                   // 柜台订单id，对于撤单是柜台撤单id
    char32 cl_order_id;                // 客户端订单id，对应到客户端的原订单id
    char32 contract_id;                // 委托合同号
    int32_t bsflag;                    // 买卖标识，参考OrderSide定义
    char128 busistr;                   // 业务串 [询价成交]询价请求：对手方交易商编号; [询价成交]报价回复：报价消息编号
    int64_t orderqty;                  // 委托数量 [询价成交]报价回复：报价数量，对应busistr报价消息编号，为一组数据
    int64_t orderprice;                // 委托价格 [询价成交]报价回复：报价价格，对应busistr报价消息编号，为一组数据
    int32_t investtype;                // 交易主体类型 [询价成交]询价请求：对手方交易主体类型，和busistr对手方交易商编号，为一组数据
    char16 investorid;                 // 交易主体代码 目前为空
                                       // [询价成交]询价请求：对手方交易主体代码，和busistr对手方交易商编号，为一组数据
    char32 tradercode;                 // 交易员代码 目前为空
                                       // [询价成交]询价请求：对手方交易员代码，和busistr对手方交易商编号，为一组数据
    char32 pos_str;                    // 定位串 格式如下：orderdate|ordersno
};


// 深圳固收债券历史委托查询请求
struct QuerySZBondHisOrderReq {
    int32_t begin_date;                 // 起始日期，格式为YYYYMMDD
    int32_t end_date;                   // 终止日期，格式为YYYYMMDD
    char8 market;                       // 交易市场，SH、SZ等，参考本文件中定义
    char32 order_id;                    // 柜台订单id，非必传
    char256 side;                       // 买卖方向，参考OrderSide定义，非必传，多送时，每个买卖方向间以英文逗号分隔
    int32_t cancelflag;                 // 撤单标识，参考CancelFlag定义，非必传
    char32 stkcode;                     // 质押券代码
    char qry_direct;                    // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认倒序
    char32 pos_str;                     // 定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串, 格式如下：orderdate|ordersno
    int32_t query_num;                  // 查询条数
};

// 深圳固收债券历史委托查询明细
struct SZBondHisOrderDetail {
    char16 account_id;                 // 交易账号，目前是资金账号
    int16_t account_type;              // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                  // 机构编码
    char8 cust_branchid;               // 分支编码
    int32_t orderdate;                 // 委托日期
    int64_t opertime;                  // 委托时间  
    char32 order_id;                   // 柜台订单id，对于撤单是柜台撤单id
    char32 contract_id;                // 委托合同号
    char16 cust_id;                    // 客户代码
    char32 secuid;                     // 证券账号 
    char32 rptsecuid;                  // 报盘股东
    char32 stkcode;                    // 交易标的
    char32 stkname;                    // 证券名称
    int64_t orderprice;                // 委托价格，竞买成交(买卖类别为：竞买成交竞买预约申报和竞买成交竞买发起申报时：存放价格下限
    int64_t orderqty;                  // 委托数量  
    int64_t reportqty;                 // 申报数量  
    int64_t matchprice;                // 成交价格
    int64_t matchqty;                  // 成交数量
    int64_t cancelqty;                 // 撤单数量
    int64_t tradefee;                  // 交易费用
    int64_t orderfrzamt;               // 委托冻结金额
    int64_t clearamt;                  // 清算金额
    int32_t bsflag;                    // 买卖标识，参考OrderSide定义
    char32 matchid;                    // 成交号码 交易所成交编号 
    char32 thedealerid;                // 本方交易商号  
    char256 thedealname;               // 本方交易商名  
    char32 thedealperid;               // 本方交易员号  
    char256 thedealpname;              // 本方交易员名  
    char16 theinvestorid;              // 本方交易主体代码  
    int32_t theinvestortype;           // 本方交易主体类型 
    char32 theseat;                    // 本方席位  
    char256 thesecuname;               // 本方投资者账户名称 
    char32 oppdealerid;                // 对手方交易商号  
    char256 oppdealname;               // 对手方交易商名  
    char32 oppdealperid;               // 对手方交易员号  
    char256 oppdealpname;              // 对手方交易员名  
    char16 oppinvestorid;              // 对手方交易主体代码  
    int32_t oppinvestortype;           // 对手方交易主体类型 
    char32 oppseat;                    // 对手方席位  
    int32_t cancelflag;                // 撤单标识，参考CancelFlag定义
    int32_t orderstatus;               // 委托状态，参考OrderStatus定义
    char32 oldorderid;                 // 被撤合同号
    char128 errmsg;                    // 废单原因
    char16 confirmid;                  // 约定号
    char4096 quotestr;                 // 附加信息 当报价回复申报时填为报价消息串;当询价请求申报时为对手方交易信息串
    char256 remark;                    // 备注
    int32_t pretradeanonymity;         // 是否匿名 Y 0=显名, 1=匿名 
    int32_t privatequote;              // 私有报价 0=私有报价（Private Quote）;1=公开报价（Public Quote）
    int32_t settltype;                 // 结算方式 参考SettleType定义
    int32_t settlperiod;               // 结算周期 参考SettlePeriod定义
    int32_t recnum;                    // 接口记录号 
    int32_t maxfloor;                  // 可显示数量，竞买成交
                                       // (买卖类别为：竞买成交竞买预约申报、竞买成交竞买发起申报和竞买成交应价申报)时：存放竞买成交方式
    char32 pos_str;                    // 定位串 格式如下：orderdate|ordersno
};


// 深圳固收市场竞买预约信息查询请求
struct QuerySZBondMarketBidAppointmentReq {
    char8 market;                       // 交易市场，SH、SZ等，参考本文件中定义
    char32 secondaryorderid;            // 竞买场次编号，非必传，为空查询所有
    char32 stkcode;                     // 交易标的，非必传，为空查询所有
    int64_t tradebegindate;             // 竞买查询开始日，非必传，为-1查询所有
    int64_t tradeenddate;               // 竞买查询结束日，非必传，为-1查询所有
    int32_t bidexecinsttype;            // 竞买成交方式，非必传，参考 BiddingMatchType 定义
    int64_t lowlimitprice;              // 价格下限，非必传，为-1查询所有
    int64_t highlimitprice;             // 价格上限，非必传，为-1查询所有
    char8 componycode;                  // 交易商代码，非必传，为空查询所有
    int32_t investortype;               // 交易主体类型，非必传，为空查询所有 参考 ContractBuyBackInvestorType 定义
 	char qry_direct;                    // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认倒序
    char32 pos_str;                     // 定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串, 格式如下：serverid|bidid|securityid
    int32_t query_num;                  // 查询条数
};


// 深圳固收市场竞买预约信息明细
struct SZBondMarketBidAppointmentDetail {
    char16 account_id;                 // 交易账号，目前是资金账号
    int16_t account_type;              // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                  // 机构编码
    char8 cust_branchid;               // 分支编码
    char32 serverid;                   // 机器编码  
    char32 bidid;                      // 竞买场次编号
    char32 stkcode;                    // 证券代码
    char32 stkname;                    // 证券名称  
    int32_t tradedate;                 // 竞买交易日期  
    int64_t qty;                       // 竞买预约数量
    int64_t minqty;                    // 最低成交数量
    int32_t bidexecinsttype;           // 竞买成交方式 参考 BiddingMatchType 定义
    int32_t anonymityflag;             // 是否匿名 0=显名, 1=匿名
    char8 memberid;                    // 交易商代码，若匿名，则此字段为空  
    int32_t investortype;              // 交易主体类型 参考 ContractBuyBackInvestorType 定义
    int64_t lowlimitprice;             // 价格下限
    int64_t highlimitprice;            // 价格上限
    int32_t settltype;                 // 结算方式 参考SettleType定义
    int32_t settlperiod;               // 结算周期 参考SettlePeriod定义
    char32 pos_str;                    // 定位串
};


// 深圳固收客户竞买预约信息查询请求
struct QuerySZBondCustomerBidAppointmentReq {
    char8 market;                       // 交易市场，SH、SZ等，参考本文件中定义
    char256 side;                       // 买卖方向，参考OrderSide定义，非必传，多送时，每个买卖方向间以英文逗号分隔
    char32 secondaryorderid;            // 竞买场次编号，非必传，为空查询所有
    char32 stkcode;                     // 交易标的，非必传，为空查询所有
    int64_t tradebegindate;             // 竞买查询开始日非必传，为-1查询所有
    int64_t tradeenddate;               // 竞买查询结束日，非必传，为-1查询所有
    int32_t bidexecinsttype;            // 竞买成交方式，非必传，参考 BiddingMatchType 定义
    int64_t lowlimitprice;              // 价格下限，非必传，为-1查询所有
    int64_t highlimitprice;             // 价格上限，非必传，为-1查询所有
};

// 深圳固收客户竞买预约信息明细
struct  SZBondCustomerBidAppointmentDetail {
    char16 account_id;                  // 交易账号，目前是资金账号
    int16_t account_type;               // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                   // 机构编码
    char8 cust_branchid;                // 分支编码
    char32 serverid;                    // 机器编码
    int32_t orderdate;                  // 委托日期
    int64_t opertime;                   // 委托时间  
    char32 order_id;                    // 柜台订单id，对于撤单是柜台撤单id
    char32 contract_id;                 // 委托合同号
    char16 cust_id;                     // 客户代码
    char32 secuid;                      // 证券账号 
    char32 rptsecuid;                   // 报盘股东
    char32 stkcode;                     // 交易标的
    char32 stkname;                     // 证券名称
    int64_t orderqty;                   // 预约数量
    int32_t canceldate;                 // 撤单日期
    char32 cancelorderid;               // 撤单订单编号 填撤单订单编号
    int64_t cancelqty;                  // 撤单数量
    char32 bidid;                       // 竞买场次编号
    int32_t tradedate;                  // 竞买交易日期
    int64_t minqty;                     // 最低成交数量
    int32_t bidexecinsttype;            // 竞买成交方式
    int64_t highlimitprice;             // 价格上限
    int64_t lowlimitprice;              // 价格下限
    int32_t settltype;                  // 结算方式 参考SettleType定义
    int32_t settlperiod;                // 结算周期 参考SettlePeriod定义
    int32_t bondside;                   // 买卖方向，参考OrderSide定义
    int32_t pretradeanonymity;          // 是否匿名 0=显名, 1=匿名
    char32 matchid;                     // 成交号码 交易所成交编号
    char32 jysorderid;                  // 交易所订单编号 跨交易日不重复
    char32 thedealerid;                 // 本方交易商号
    char256 thedealname;                // 本方交易商名
    char32 thedealperid;                // 本方交易员号
    char256 thedealpname;               // 本方交易员名
    char16 theinvestorid;               // 本方交易主体代码
    int32_t theinvestortype;            // 本方交易主体类型 参考 ContractBuyBackInvestorType 定义
    char32 theseat;                     // 本方席位
    char256 thesecuname;                // 本方投资者账户名称
    int32_t orderstatus;                // 委托状态，参考OrderStatus定义
    char256 remark;                     // 备注
};


// 深圳固收债券-历史成交明细查询请求
struct QueryBondHistoryTradingDetailsReq {
    char8 market;              // 市场，非必传
    char16 stkcode;            // 证券代码，非必传
    char32 ordersno;           // 委托序号，非必传
    char256 orderside;         // 买卖类别，参考OrderSide定义，送空不判，多送时，每个买卖类别间以英文逗号分隔，非必传
    int32_t matchtype;    	   // 成交类型，非必传，参考TradeReportType定义
    char8 bankcode;            // 银行代码，非必传
    char qry_direct;           // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认倒序
    char32 matchsno;           // 成交流水号，非必传
    int32_t begindate;         // 开始日期
	int32_t enddate;           // 结束日期
	int32_t query_num;         // 查询数量	
    char32 pos_str;            // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串	
};

//深圳固收债券-历史成交明细数据
struct BondHistoryTradingDetail{
	char16 account_id;                  // 交易账号，目前是资金账号
	char8 cust_orgid;                   // 机构编码
	char8 cust_branchid;                // 分支编码
	int16_t account_type;               // 交易账号类型，参考AccountType定义
	char16 pos_str;                     // 定位串
    int32_t trddate;                    // 成交日期
    char64 matchcode;                   // 成交编号
    char16 secuid;                      // 股东代码
    char256 orderside;                  // 买卖类别
    char32 orderid;                     // 申报合同序号
    char32 ordersno;                    // 委托序号
    char16 stkname;                     // 证券名称
    char16 stkcode;                     // 证券代码
    int32_t stktype;                    // 证券类别
    int64_t matchtime;                  // 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示 
    Price_t matchprice;                 // 成交价格
    int64_t matchqty;                   // 成交数量
    Price_t matchamt;                   // 成交金额
    int32_t matchtype;                  // 成交类型
    int64_t orderqty;                   // 委托数量
    Price_t orderprice;                 // 委托价格 
    char8 thedealerid;                  // 本方交易商代码
    char8 thedealperid;                 // 本方交易员代码
    char16 theinvestorid;               // 本方交易主体代码
    int32_t theinvestortype;            // 本方交易主体类型 
    char8 oppdealerid;                  // 对方交易商代码
    char8 oppdealperid;                 // 对方交易员代码
    char16 oppinvestorid;               // 对方交易主体代码
    int32_t oppinvestortype;            // 对方交易主体类型
    char8 oppseat;                      // 对手方席位
    char16 netaddr;                     // MAC地址
    char32 ordergroup;                  // 委托批号
    int32_t moneytype;                  // 货币
    int32_t operway;                    // 委托方式 
    char8 seat;                         // 交易席位
    char32 sno;                         // 成交流水号
    int32_t creditdigestid;             // 信用交易摘要
    char256 remark;                     // 备注信息 
};

// 深圳固收债券-申报委托撤单请求
struct SZBondOrderCancelReq {
	char32 cl_order_id;			// 内部系统委托号
	int32_t cl_order_date;		// 内部系统日期 YYYYMMDD
	char32 cl_cancel_id;		// 内部系统撤单号
    int32_t orderdate;          // 委托日期
    char32 ordersno;            // 委托序号
};

//深圳固收债券-申报委托撤单应答
struct SZBondOrderCancelDetail{
	char16 account_id;                  // 交易账号，目前是资金账号
	char8 cust_orgid;                   // 机构编码
	char8 cust_branchid;                // 分支编码
	int16_t account_type;               // 交易账号类型，参考AccountType定义
	char32 cl_order_id;					// 内部系统委托号
	int32_t cl_order_date;				// 内部系统日期 YYYYMMDD
	char32 cl_cancel_id;				// 内部系统撤单号
	char32 cancel_uuid;					// 撤单uuid，避免风控无法唯一匹配撤单委托，由请求方生成
    int32_t orderdate;                  // 原委托日期
    char32 ordersno;                    // 原委托序号
	char32 orderid;                     // 原委托合同号
};

// 深圳固收债券-转发询价查询请求 
struct QuerySZBondForwardInquiryReq {
    char8 market;                     // 交易市场，N
    char16 stkcode;                     // 证券代码，N
    int32_t applid;                     // 应用标识，N，目前仅414 - 债券现券交易询价申报R  
    int32_t orderside;                  // 买卖方向，N，1 买，2 卖
    char8 seat;                         // 申报交易单元，N，转发交易单元
    char32 clordid;                     // 客户订单编号，N
    char32 quotereqid;                  // 询价请求编号，N
    int32_t status;                     // 消息状态，N，0 需确认，1 已失效，2 已撤销，3 通知
    int32_t quoterequeststatus;         // 询价请求状态，N，送-1表示查全部，0已接受，4已撤销，7已超时，8已成交
};

// 深圳固收债券-转发询价查询应答 
struct SZBondForwardInquiryDetail {
	char16 account_id;                    // 交易账号，目前是资金账号
	char8 cust_orgid;                     // 机构编码
	char8 cust_branchid;                  // 分支编码
	int16_t account_type;                 // 交易账号类型，参考AccountType定义
	int32_t serverid;                     // 机器编码
    int32_t sysdate;                      // 发生日期
    int64_t systime;                      // 发生时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示 
    int32_t applid;                       // 应用标识
    char32 quotereqid;                    // 询价请求编号
    char32 clordid;                    	  // 客户订单编号
    char32 execid;                        // 执行编号
    int32_t quotetype;                    // 报价类型,1表示可交易的报价
    int32_t ownertype;                    // 订单所有者类型
    char16 stkcode;                       // 证券代码
    char16 stkname;                       // 证券名称
    char8 seat;                           // 席位代码
    int64_t orderqty;                     // 订单数量
    int32_t orderside;                    // 买卖方向
    Price_t price;                        // 价格
    int32_t quoterequesttranstype;        // 询价请求事务类型,0新订单，1撤销
    int32_t quoterequesttype;             // 询价请求类型，101提交，102转发
    int32_t quoterequeststatus;           // 询价请求状态
    int32_t privatequote;                 // 私有报价，0私有报价，1公开报价
    int32_t quotepricetype;               // 报价价格类型，1百分比，2每股
    char256 memo;                         // 备注
    char8 thedealerid;                    // 发起方交易商代码
    char8 thetradercode;                  // 发起方交易员代码
    char16 theinvestorid;                 // 发起方交易主体代码
    int32_t theinvestortype;              // 发起方交易主体类型
    char32 thesecuname;                   // 发起方投资者账户名称
    char8 oppdealerid;                    // 对手方交易商号
    int32_t oppinvestortype;              // 对手方交易主体类型
    int32_t settltype;                    // 结算方式
    int32_t settlperiod;                  // 结算周期,0=T+0: 1=T+1: 2=T+2: 3=T+3
    int32_t status;                       // 消息状态
    char256 text;                         // Free Text
};

// 深圳固收债券-转发报价查询请求
struct QuerySZBondForwardQuotationReq {  
    char8 market;                       // 交易市场，N
    char16 stkcode;                       // 证券代码，N
    int32_t applid;                       // 应用标识，N
    int32_t orderside;                    // 买卖方向，N，1买，2卖
    char32 quoteid;                       // 报价消息编号，N
    char8 seat;                           // 申报交易单元，Y
    char32 clordid;                       // 客户订单编号，N
    int32_t status;                       // 消息状态，N
    char32 quotereqid;                    // 询价请求编号，N
};

// 深圳固收债券-转发报价查询应答
struct SZBondForwardQuotationDetail {
	char16 account_id;                    // 交易账号，目前是资金账号
	char8 cust_orgid;                     // 机构编码
	char8 cust_branchid;                  // 分支编码
	int16_t account_type;                 // 交易账号类型，参考AccountType定义
    int32_t serverid;                     // 机器编码
    int32_t sysdate;                      // 发生日期
    int64_t systime;                      // 发生时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示 
    int32_t applid;                       // 应用标识
    char32 clordid;                       // 客户订单编号
    int32_t ownertype;                    // 订单所有者类型
    char32 quotereqid;                    // 询价请求编号
    char32 quoteid;                       // 报价消息编号
    int32_t quotetype;                    // 报价类型
    char16 stkcode;                       // 证券代码
    char16 stkname;                       // 证券名称
    char8 seat;                           // 席位代码
    int64_t bidsize;                      // 买数量
    Price_t bidpx;                        // 买价格
    int64_t offersize;                    // 卖数量
    Price_t offerpx;                      // 卖价格
    int32_t orderside;                    // 买卖方向
    char32 orderid;                       // 交易所订单编号
    char32 execid;                        // 执行编号
    int32_t pricetype;                    // 价格类型
    char256 memo;                         // 备注
    char8 thedealerid;                    // 发起方交易商代码
    char8 thetradercode;                  // 发起方交易员代码
    char16 theinvestorid;                 // 发起方交易主体代码
    int32_t theinvestortype;              // 发起方交易主体类型
    char32 thesecuname;                   // 发起方投资者账户名称
    char8 oppdealerid;                    // 对手方交易商号
    char16 oppdealperid;                  // 对手方交易员号
    char8 oppinvestorid;                  // 对手方交易主体代码
    int32_t oppinvestortype;              // 对手方交易主体类型
    int32_t settltype;                    // 结算方式
    int32_t settlperiod;                  // 结算周期
    int64_t maxfloor;                     // 可显示数量
    int64_t minqty;                       // 最低成交数量
    char32 ordersno;                      // 回复的委托序号
    int32_t status;                       // 消息状态
    char256 text;                         // Free Text
};

// 深圳固收债券-点击成交逐笔委托行情查询请求
struct QuerySZBondPerOrderInfoOfClickDealReq {
    char32 stkcode;                     // 证券代码，Y，空查询全部 
    int32_t orderside;                  // 买卖方向，N，1买，2卖
    char32 quoteid;                     // 报价消息编号，N
    char8 memberid;                     // 交易商代码，N
    char16 tradecode;                   // 交易员代码，N
	char32 pos_str;                    	// 定位串，填""表示第一次从头开始查, 默认查询500条
};

// 深圳固收债券-点击成交逐笔委托行情查询应答
struct SZBondPerOrderInfoOfClickDealDetail {
	char16 account_id;                    // 交易账号，目前是资金账号
	char8 cust_orgid;                     // 机构编码
	char8 cust_branchid;                  // 分支编码
	int16_t account_type;                 // 交易账号类型，参考AccountType定义
    int64_t JLH;                          // 记录号  
    char32 stkcode;                       // 证券代码 
    char32 stkname;                       // 证券名称
    Price_t price;                        // 申报价格  
    int64_t orderqty;                     // 申报数量 
    int32_t orderside;                    // 买卖方向，1买，2卖
    char32 BJJLH;                      	  // 报价消息编号
    char8 JYSDM;                          // 交易商代码
    int32_t JYZTLX;                       // 交易主体类型
    char8 JYZTDM;                         // 交易主体代码
    char32 KHMC;                          // 客户名称
    char16 JYYDM;                         // 交易员代码 
    int32_t JSZQ;                         // 结算周期  
    int32_t JSFZ;                         // 结算方式  
    char256 BZ;                           // 备注  
    char32 RECNO;                         // 序号
};

// 深圳固收债券-交易业务参考信息查询请求
struct QuerySZBondTradingBusinessReferenceInfoReq {
    int32_t busitype;                     // 业务类型，Y，0现券交易业务，1通用质押式回购业务
    char32 stkcode;                       // 证券代码，Y
    char8 market;                       // 交易市场，Y，2-深圳A
    int32_t tradingtype;                  // 交易方式，N
};

// 深圳固收债券-交易业务参考信息查询应答
struct SZBondTradingBusinessReferenceInfoDetail {
	char16 account_id;                        // 交易账号，目前是资金账号
	char8 cust_orgid;                         // 机构编码
	char8 cust_branchid;                      // 分支编码
	int16_t account_type;                     // 交易账号类型，参考AccountType定义
    int32_t serverid;                         // 机器编码
    int32_t busitype;                         // 业务类型
    char32 stkcode;                           // 证券代码
    int32_t tradingtype;                      // 交易方式
    int64_t pricetick;                        // 价格挡位
    Price_t priceupperlimit;                  // 涨停价
    Price_t pricelowerlimit;                  // 跌停价
    int64_t buyqtyupperlimit;                 // 买数量上限
    int64_t sellqtyupperlimit;                // 卖数量上限
    int64_t buyqtylowerlimit;                 // 买数量下限
    int64_t sellqtylowerlimit;                // 卖数量下限
    int64_t buyqtyunit;                       // 买数量单位
    int64_t sellqtyunit;                      // 卖数量单位
    int32_t upddate;                          // 更新日期
};


    // 深圳固收债券协商成交申报请求
    struct SZBondNegotiatedTradeOrderReq {
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
        char32 symbol;              // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
        int16_t side;               // 买卖方向，参考OrderSide定义
        Price_t price;              // 委托价格
        int64_t volume;             // 委托数量，千元面额
        bool acceptsubterm;         // 是否同意补充条款, 非必传, 买卖方向为100,101时必填 
        char8 origcomponycode;      // 发起方（本方）交易商代码
        char16 origtradercode;      // 发起方（本方）交易员代码
        char8 oppocomponycode;      // 对手方交易商代码
        char16 oppotradercode;      // 对手方交易员代码
        char16 originvestorid;      // 本方交易主体代码
        char16 oppoinvestorid;      // 对手方交易主体代码
        char8 seat;                 // 本方交易单元
        char64 secuname;            // 本方客户姓名, 非必传, 本方交易主体类型为3-机构经纪时，必传
        char16 quoterefid;          // 对手方成交申报编号, 非必传, 确认、拒绝申报时填写转发成交申报的客户成交申报编号，其他置空
        char16 confirmid;           // 约定号, 经纪业务, 协商成交买和协商成交卖填对手方客户代码，
                                    // 若对手方客户代码超过8位的，截取客户代码后8位;协商成交确认和拒绝填写对应转发消息中约定号
        char128 remark;             // 备注, 非必传
		int32_t settltype;                  // 结算方式,参考SettleType
		int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
    };

    // 深圳固收债券竞买成交出价委托请求
    struct SZBondAuctionsTradeSendOrderReq {
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
        char32 symbol;              // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
        int16_t side;               // 买卖方向，参考OrderSide定义, 目前仅支持116-117类型
        int32_t tradedate;          // 竞买日, 格式为YYYYMMDD, 非必传, 仅买卖方向为116时必填
        char32 secondaryorderid;    // 竞买场次编号, 非必传, 仅买卖方向为117时填写
                                    // 竞买场次编号必须为当日有效的竞买场次编号
        int16_t bidexecinsttype;    // 竞买成交方式, 参考BiddingMatchType定义
        Price_t lowlimitprice;      // 价格下限
        Price_t highlimitprice;     // 价格上限
        int64_t volume;             // 委托数量，千元面额
        int64_t minvolume;          // 最低成交数量，千元面额
        char8 bankcode;             // 银行代码，非必传, 三方交易时送
        char128 remark;             // 备注
        bool pretradeanonymity;     // 是否匿名 
        bool acceptsubterm;         // 是否同意补充条款
        char8 origcomponycode;      // 发起方（本方）交易商代码
        char16 origtradercode;      // 发起方（本方）交易员代码
        char16 originvestorid;      // 发起方（本方）交易主体代码
        char64 secuname;            // 发起方（本方）客户名称, 非必传, 本方交易主体类型为3-机构经纪时，必传
		int32_t settltype;                  // 结算方式,参考SettleType
		int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
    };

    // 深圳固收债券竞买成交应价委托请求
    struct SZBondAuctionsTradeReplyOrderReq {
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
        char32 symbol;              // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
        int16_t side;               // 买卖方向，参考OrderSide定义, 目前仅支持118类型
        char32 secondaryorderid;    // 竞买场次编号 必须为当日有效的竞买场次编号
        int16_t bidexecinsttype;    // 竞买成交方式, 参考BiddingMatchType定义
        Price_t price;              // 应价价格
        int64_t volume;             // 委托数量，千元面额
        bool pretradeanonymity;     // 是否匿名, 应价申报是否匿名字段的填写将影响逐笔行情交易商、
                                    // 交易主体类型字段展示
        bool acceptsubterm;         // 是否同意补充条款
        char8 bankcode;             // 银行代码，非必传, 三方交易时送
        char128 remark;             // 备注
        char8 origcomponycode;      // 发起方（本方）交易商代码
        char16 origtradercode;      // 发起方（本方）交易员代码
        char16 originvestorid;      // 发起方（本方）交易主体代码
        char64 secuname;            // 发起方（本方）客户名称, 非必传, 本方交易主体类型为3-机构经纪时，必传
		int32_t settltype;                  // 结算方式,参考SettleType
		int32_t settlperiod;                // 结算周期,参考SettlePeriod,必传;若结算方式为103，则结算周期取值固定为1（T+1），否则填0（T+0）
    };

    // 深圳固收债券回售转售申报请求
    struct SZBondPutBackResaleOrderReq {
        char32 cl_order_id;                 // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;              // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
        char32 symbol;                      // 交易标的，格式为市场.证券代码, 目前仅支持深圳市场
        int16_t side;                       // 买卖方向，参考OrderSide定义，目前仅支持121，122，123类型
        Price_t price;                      // 委托价格
        int64_t volume;                     // 委托数量
        int32_t acceptsubterm;              // 是否同意补充条款, 0=不同意, 1=同意，仅买卖方向为债券回售转售申报121时填写
        char8 oppseat;                      // 对手方交易单元
        char16 quoterefid;                  // 转发成交申报编号, 确认、拒绝申报时填写转发成交申报的客户成交申报编号，其他置空
        char16 confirmid;                   // 约定号, 买卖类别为“债券回售转售申报”填对手方客户代码，若对手方客户代码超过8位的，截取客户代码后8位
                                            // “债券回售转售确认和拒绝”填写对应转发消息中约定号
    };

    // 固收债券历史委托扩展信息查询请求
    struct QryBondHisOrderExtInfoReq {
        char32 market;              // 交易市场，如 "SZ" 或者 "SH"，非必传
        char16 stk_code;            // 证券代码，非必传
        int32_t begin_date;			// 起始日期，格式为YYYYMMDD
        int32_t end_date;			// 结束日期，格式为YYYYMMDD
        char32 order_sno;           // 委托序号, 非必传
        int16_t order_side;         // 买卖方向，参考OrderSide定义, 非必传
        int16_t cancel_flag;        // 撤单标识，参考CancelFlag定义, 非必传
        char qry_direct;            // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
        char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
        int32_t query_num;          // 查询数量
    };

    // 固收债券历史委托扩展信息明细数据
    struct BondHisOrderExtInfoDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char16 pos_str;                     // 定位串
        int32_t order_date;                 // 委托日期
        char32 order_sno;                   // 委托序号
        int16_t order_side;                 // 买卖方向，参考OrderSide定义
        char128 busi_str;                   // 业务串
        int64_t order_qty;                  // 委托数量
        Price_t order_price;                // 委托价格
        int16_t investor_type;              // 交易主体类型, 参考ContractBuyBackInvestorType定义
        char16 investor_id;                 // 交易主体代码 目前为空
        char16 trader_code;                 // 交易员代码 目前为空
    };

    // 深圳固收债券协商成交申报查询请求
    struct QrySZBondNegotiatedTradeOrderReq {
        char16 stk_code;            // 证券代码，非必传
        char8 memberid;             // 接收方交易商代码 非必传
        char16 tradercode;          // 接收方交易员代码 非必传
        char16 investorid;          // 接收方交易主体代码 非必传
        int16_t busiside;           // 业务方向 非必传 参考BusiDirection定义, 目前仅支持1-2
		char256 applyid;            // 应用标识 必传,参考StrBondApplyId定义, 目前仅支持411,430,41A;可复选,多个选项以英文逗号隔开
    };

    // 深圳固收债券协商成交申报明细数据
    struct SZBondNegotiatedTradeOrderDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char32 symbol;                      // 标的代码，格式为市场.证券ID
        char32 stk_name;                     // 证券名称  
        char16 serverid;                    // 机器编码  
        int32_t sysdate;                    // 接收日期  
        char32 execid;                      // 执行编号  
        char16 tradereportid;               // 客户成交申报编号  
        int16_t applid;                     // 应用标识 参考BondApplyId定义
        int16_t ownertype;                  // 订单所有者类型 参考ContractBuyBackOwnerType定义 
        char16 tradereportrefid;            // 原客户成交申报编号  
        int64_t transacttime;               // 回报时间 格式为HHMMSSmmm，首位为0不显示 
        char16 pbuid;                       // 回报交易单元  
        char16 seat;                        // 申报方交易单元  
        int16_t busiside;                   // 业务方向 参考BusiDirection定义 
        char8 memberid;                     // 发起方交易商代码  
        char16 investorid;                  // 发起方交易主体代码  
        int16_t investortype;               // 发起方交易主体类型 参考ContractBuyBackInvestorType定义 
        char256 investorname;               // 发起方客户名称  
        char16 tradercode;                  // 发起方交易员代码  
        char8 cpmemberid;                   // 接收方交易商代码  
        char16 cpinvestorid;                // 接收方交易主体代码  
        int16_t cpinvestortype;             // 接收方交易主体类型 参考ContractBuyBackInvestorType定义 
        char16 cptradercode;                // 接收方交易员代码  
        char8 cpseat;                       // 接收方席位  
        Price_t lastpx;                     // 委托价格  
        int64_t orderqty;                   // 委托数量  
        char16 confirmid;                   // 约定号  
        int16_t cashmargin;                 // 信用标识 参考CashMarginFlag定义 
        int16_t settltype;                  // 结算方式 参考SettleType定义 
        int16_t settlperiod;                // 结算周期 参考SettlePeriod定义 
        int16_t scbondstatus;               // 申报状态 参考SCBondStatus定义 
        char512 remark;                     // 备注 
    };

    // 深圳固收债券当日成交明细查询请求
    struct QrySZBondTradeListReq {
        char32 market;              // 交易市场，如 "SZ" 或者 "SH"，非必传
        char16 stk_code;            // 证券代码，非必传
        char32 order_sno;           // 委托序号, 非必传
        int16_t orderside;          // 买卖方向，参考OrderSide定义, 非必传
        int16_t matchtype;          // 成交类型, 非必传 参考TradeReportType定义   
        int32_t matchdate;          // 成交日期，非必传, 格式为YYYYMMDD
        char16 matchsno;            // 成交流水号, 非必传
        char qry_direct;            // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
        char32 pos_str;             // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
        int32_t query_num;          // 查询数量
    };

    // 深圳固收债券当日成交明细数据
    struct SZBondTradeListDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char32 pos_str;                     // 定位串  
        char32 symbol;                      // 标的代码，格式为市场.证券ID
        char32 stk_name;                    // 证券名称 
        char16 order_sno;                   // 委托序号 　 
        int32_t matchdate;                  // 成交日期, 格式为YYYYMMDD
        char16 matchcode;                   // 成交编号 　 
        char16 secuid;                      // 股东代码 　 
        int16_t orderside;                  // 买卖方向 参考OrderSide定义 
        char16 orderid;                     // 申报合同序号 　 
        int32_t stktype;                    // 证券类别 参考SecurityTypeDetail定义 
        int64_t matchtime;                  // 成交时间, 格式为HHMMSSmmm, 首位为0不显示  
        Price_t matchprice;                 // 成交价格 　 
        int64_t matchqty;                   // 成交数量 　 
        Amt_t matchamt;                     // 成交金额 　 
        int16_t matchtype;                  // 成交类型 参考TradeReportType定义 
        int64_t orderqty;                   // 委托数量  
        Price_t orderprice;                 // 委托价格  
        char8 thedealerid;                  // 本方交易商代码  
        char16 thedealperid;                // 本方交易员代码  
        char16 theinvestorid;               // 本方交易主体代码  
        int16_t theinvestortype;            // 本方交易主体类型 参考ContractBuyBackInvestorType定义 
        char8 oppdealerid;                  // 对方交易商代码  
        char16 oppdealperid;                // 对方交易员代码  
        char16 oppinvestorid;               // 对方交易主体代码  
        int16_t oppinvestortype;            // 对方交易主体类型 参考ContractBuyBackInvestorType定义 
        char8 oppseat;                      // 对手方席位  
        char16 netaddr;                     // MAC地址  
        char16 ordergroup;                  // 委托批号  
        int16_t moneytype;                  // 货币 参考CurrencyType定义 
        char operway;                       // 委托方式 参考OperWay定义 
        char8 seat;                         // 交易席位  
        char16 matchsno;                    // 成交流水号  
        int16_t creditdigestid;             // 信用交易摘要 参考CreditDigestID定义 
        char512 remark;                     // 备注信息  
    };

    // 固收债券竞买成交历史预约信息查询请求
    struct QryBondAuctionsTradeHisAppointmentReq {
        char32 market;                      // 交易市场，参考MarketType定义，目前支持1-2两种类型
        char16 secondaryorderid;            // 竞买场次编号，非必传 
        char16 stk_code;                    // 证券代码，非必传 
        int32_t begin_date;                 // 查询开始日，非必传，格式为YYYYMMDD  
        int32_t end_date;                   // 查询结束日，非必传，格式为YYYYMMDD 
        int16_t bidexecinsttype;            // 竞买成交方式，非必传，参考BiddingMatchType定义
        Price_t lowlimitprice;              // 价格下限，非必传 
        Price_t highlimitprice;             // 价格上限，非必传
        char qry_direct;                    // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
        char32 pos_str;                     // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
        int32_t query_num;                  // 查询数量
    };

    // 固收债券竞买成交历史预约信息明细数据
    struct BondAuctionsTradeHisAppointmentDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char32 pos_str;                     // 定位串  
        char32 symbol;                      // 标的代码，格式为市场.证券ID
        char32 stk_name;                    // 证券名称  
        int32_t order_date;                 // 委托日期，格式为YYYYMMDD 
        char16 order_sno;                   // 委托序号  
        char16 serverid;                    // 机器编码  
        char16 orderid;                     // 委托合同号  
        int64_t opertime;                   // 委托时间  
        int32_t backupdate;                 // 归档日期，格式为YYYYMMDD
        char16 custid;                      // 客户代码  
        char8 orgid;                        // 营业部  
        char8 brhid;                        // 分支  
        char16 fundid;                      // 资金账号  
        char16 secuid;                      // 证券账号  
        char16 rptsecuid;                   // 报盘股东  
        int64_t orderqty;                   // 预约数量  
        int32_t canceldate;                 // 撤单日期  
        char16 cancelorderid;               // 撤单订单编号 填撤单订单编号 
        int64_t cancelqty;                  // 撤单数量  
        char32 bidid;                       // 竞买场次编号  
        int32_t tradedate;                  // 竞买交易日期  
        int64_t qty;                        // 竞买预约数量, 扩大100倍 
        int64_t minqty;                     // 最低成交数量，扩大100倍  
        int16_t bidexecinsttype;            // 竞买成交方式 参考BiddingMatchType定义 
        Price_t highlimitprice;             // 价格上限  
        Price_t lowlimitprice;              // 价格下限  
        int16_t settltype;                  // 结算方式 参考SettleType定义 
        int16_t settlperiod;                // 结算周期 参考SettlePeriod定义 
        int16_t bondside;                   // 买卖方向 参考OrderSide定义 
        bool pretradeanonymity;             // 是否匿名 false:显名 true:匿名
        char32 matchid;                     // 成交号码 交易所成交编号 
        char32 jysorderid;                  // 交易所订单编号 跨交易日不重复 
        char8 thedealerid;                  // 本方交易商号  
        char256 thedealname;                // 本方交易商名  
        char16 thedealperid;                // 本方交易员号  
        char256 thedealpname;               // 本方交易员名  
        char16 theinvestorid;               // 本方交易主体代码  
        int16_t theinvestortype;            // 本方交易主体类型 参考ContractBuyBackInvestorType定义 
        char8 theseat;                      // 本方席位  
        char64 thesecuname;                 // 本方投资者账户名称  
        int16_t orderstatus;                // 申报状态 参考OrderStatus定义 
        char1024 remark;                    // 备注   
    };

    // 深圳固收债券竞买成交逐笔应价行情查询请求
    struct QrySZBondAuctionsTradeBidMarketOrderReq {
        char32 secondaryorderid;            // 竞买场次编号，非必传 
        char16 stk_code;                    // 证券代码，非必传 
		char32 pos_str;                    	// 定位串，填""表示第一次从头开始查, 默认查询500条
    };

    // 深圳固收债券竞买成交逐笔应价行情明细数据
    struct SZBondAuctionsTradeBidMarketOrderDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char32 recordno;                    // 记录号  
        char16 stk_code;                     // 证券代码  
        char32 stk_name;                     // 证券名称  
        Price_t price;                      // 申报价格 　 
        int64_t qty;                        // 申报数量 　 
        int16_t busiside;                   // 业务方向 参考BusiDirection定义 
        char32 secondaryorderid;            // 竞买场次编号  
        char8 memberid;                     // 交易商代码 　 
        int16_t investortype;               // 交易主体类型 参考ContractBuyBackInvestorType定义 
        char16 investorid;                  // 交易主体代码  
        char256 custname;                   // 客户名称  
        char16 tradecode;                   // 交易员代码  
        int16_t settlperiod;                // 结算周期 参考SettlePeriod定义 
        int16_t settltype;                  // 结算方式 参考SettleType定义 
        int16_t bidtranstype;               // 竞买业务类别 参考BidTransType定义 
        int16_t bidexecinsttype;            // 竞买成交方式 参考BiddingMatchType定义 
        int64_t minqty;                     // 最低成交数量，扩大100倍  
        Price_t highlimitprice;             // 价格上限  
        Price_t lowlimitprice;              // 价格下限  
		int16_t ishaveyjsb;                 // 是否有竞买应价申报 1:有应价申报,0:无应价申报
        char512 remark;                     // 备注  
        char16 sno;                         // 序号  
    };

    // 客户风险测评信息查询请求
    struct QryCustRiskAssessmentInfoReq {
	    char paper_type;                    // 试卷类型，参考PaperType定义
	};
    // 客户风险测评信息明细数据
    struct CustRiskAssessmentInfoDetail {
	    char16 account_id;                  // 交易账号，目前是资金账号
	    int16_t account_type;               // 交易账号类型，参考AccountType定义
	    char8 cust_orgid;                   // 机构编码
	    char8 cust_branchid;                // 分支编码
	    char paper_type;                    // 试卷类别，参考PaperType定义
	    char organ_flag;                    // 机构标志，参考OrganizationFlag定义
	    int32_t paper_score;                // 试卷得分
	    int16_t corp_risk_level;            // 客户风险等级，参考CustRiskLevel定义
	    char32 cif_account;                 // 一户通客户账户
	    char op_entrust_way;                // 委托方式，参考OperWay定义
	    int32_t curr_date;                  // 当前日期，格式为YYYYMMDD
	    int64_t curr_time;                  // 当前时间，格式为HHMMSSmmm，首位为0不显示  
	    char2048 paper_answer;              // 试卷答案
	    int32_t corp_begin_date;            // 客户风险测评日，格式为YYYYMMDD
	    int32_t corp_end_date;              // 客户风险到期日，格式为YYYYMMDD
	    char64 cert_sn;                     // 证书序号
	    char auth_product_type;             // 认证产品类别，参考AuthProductType定义
	    char128 remark;                     // 备注
	    bool gt_first_flag;                 // 是否首次
	    char16 gt_version;                  // 版本
	};


    // 市场券约券下单请求
    struct QytSubscribeOrderReq {
        char32 symbol;							  // 标的代码，格式为市场.证券ID
        char client_type;					      // 客户类型,参考QytClientType
        char limit_type;						  // 期限类型,参考QytLimitType
        char en_type;							  // 委托方式,参考QytEnType
        int64_t order_qty;						  // 委托数量
        int64_t min_qty;						  // 最小数量
        int32_t time_limit;					      // 期限
        int32_t min_time_limit;					  // 最小期限
        Ratio_t admin_rate;					      // 管理费率,小数点后最多两位;扩大1W倍,单位%
        Ratio_t rate;							  // 利率,小数点后最多两位;扩大1W倍,单位%
        int32_t valid_endtime;					  // 有效截至日期yyyymmdd
    };

    // 市场券约券下单应答明细
    struct QytSubscribeOrderDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 entrust_no;                        // 委托编号
    };

    // 券池券单查询
    struct QCQueryVoucherReq {
        int16_t qc_type;						 // 券池类型,参考QCType;Y
        char32 pos_str;                          // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，若数据足够固定返回100条
        char128 stkcodes;						 // 证券代码集合,'|'分割;格式:000001|600000 N
    };

    // 券池券单查询应答明细
    struct QCQueryVoucherDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        int16_t qc_type;						  // 券池类型,参考QCType;
        char32 drop_id;							  // 投放投放流水号
        char32 symbol;							  // 证券标的
        int32_t start_date;						  // 起始日yyyyMMdd
        int32_t limit_date;						  // 到期日yyyyMMdd
        int32_t res_limit;						  // 期限
        Ratio_t floor_rate;						  // 费率下限,扩大1W倍,单位%
        Ratio_t upper_rate;						  // 费率上限,扩大1W倍,单位%
        char32 related_custid;					  // 关联客户号
        int32_t apply_date;						  // 申报日期（融入确认单）yyyyMMdd
        char32 contract_id;						  // 约定号（融入确认单）
        char32 apply_id;						  // 融入申报编号
        int32_t total_left_qty;                   // 总可用数量
    };

    // 券池券单汇总查询
    struct QCQueryVoucherSummaryReq {
        int16_t qc_type;						 // 券池类型,参考QCType;Y
        char32 pos_str;                          // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，若数据足够固定返回100条
        char16 market;							 // 交易市场，如 "SZ" 或者 "SH";N
        char16 stk_code;						 // 证券代码;N
    };

    // 券池券单汇总查询应答明细
    struct QCQueryVoucherSummaryDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 symbol;							  // 证券标的
        int32_t actual_left_qty;				  // 实际可用数量
        int32_t start_date;						  // 最早起始日yyyyMMdd
        Ratio_t floor_rate;						  // 费率下限,扩大1W倍,单位%
    };

    // 券源通约券委托查询请求
    struct QueryQytSubscribeOrderListReq {
        char32 pos_str;                            // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条，非必传
        int64_t begin_date;                        // 委托开始时间 YYYYMMDD，非必传
        int64_t end_date;                          // 委托截止时间 YYYYMMDD，非必传
        char16 code;                               // 证券代码，非必传
        char32 entrust_status_list;                // 委托状态集合，参考QytEntrustStatus定义，非必传，多个状态间用','分隔
        char32 order_id;                           // 委托单号，非必传
    };

    // 券源通约券委托详情
    struct QytSubscribeOrderRecord {
        char16 account_id;                         // 交易账号，目前是资金账号
        char8 cust_orgid;                          // 机构编码
        char8 cust_branchid;                       // 分支编码
        int16_t account_type;                      // 交易账号类型，参考AccountType定义
        int32_t order_date;                        // 委托日期YYYYMMDD
        int32_t order_time;                        // 委托时间HHMMSS
        char32 stk_name;                           // 证券名称
        char32 stk_code;                           // 证券代码
        int32_t time_limit;                        // 期限  
        int64_t rate;                              // 利率（融券费率），扩大一万倍，单位%
        int64_t order_qty;                         // 委托数量  
        int64_t match_qty;                         // 成交数量
        int16_t entrust_status;                    // 委托状态 参考QytEntrustStatus定义  
        int16_t other_status;                      // 其他状态 参考QytOthStatus定义 
        char order_type;                           // 申报（委托）方式 参考QytEnType定义
        char32 order_id;                           // 委托单号  
        int64_t valid_start_time;                  // 委托生效时间YYYYMMDDHHMMSS
        int64_t valid_end_time;                    // 委托截止时间YYYYMMDDHHMMSS
        char limit_type;                           // 期限类型 参考QytLimitType定义
        int32_t min_time_limit;                    // 最小期限
        int64_t admin_rate;                        // 管理费率，扩大一万倍，单位%
        int64_t min_qty;                           // 最小数量
    };

    // 券源通约券委托撤单请求
    struct CancelQytSubscribeOrderReq {
        char32 order_id;                           // 被撤的原订单id
    };

    // 券源通约券委托撤单应答
    struct CancelQytSubscribeOrderRsp {
        char16 account_id;                         // 交易账号，目前是资金账号
        char8 cust_orgid;                          // 机构编码
        char8 cust_branchid;                       // 分支编码
        int16_t account_type;                      // 交易账号类型，参考AccountType定义
        char256 data;                              // 撤单成功输出文案
    };

    // 券源通约券委托成交查询请求
    struct QueryQytSubscribeTradeListReq {
        char32 pos_str;                            // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条，非必传
        int64_t begin_date;                        // 成交开始时间 YYYYMMDD，非必传
        int64_t end_date;                          // 成交截止时间 YYYYMMDD，非必传
        char16 code;                               // 证券代码，非必传
        char32 entrust_status_list;                // 委托状态集合，参考QytEntrustStatus定义，非必传，多个状态间用','分隔
        char32 order_id;                           // 委托单号，非必传
    };

    // 券源通约券委托成交详情
    struct QytSubscribeTradeDetail {
        char16 account_id;                         // 交易账号，目前是资金账号
        char8 cust_orgid;                          // 机构编码
        char8 cust_branchid;                       // 分支编码
        int16_t account_type;                      // 交易账号类型，参考AccountType定义
        int32_t match_date;                        // 成交日期YYYYMMDD
        int32_t match_time;                        // 成交时间HHMMSS
        char32 stk_name;                           // 证券名称
        char32 stk_code;                           // 证券代码
        int32_t time_limit;                        // 期限
        int64_t rate;                              // 利率（融券费率），扩大一万倍，单位%
        int64_t match_qty;                         // 成交数量
        int16_t allot_status;                      // 调拨状态 参考QytAllotStatus定义
        char32 match_id;                           // 成交单号
        char limit_type;                           // 期限类型 参考QytLimitType定义
        char side;                                 // 委托方向 参考QytDirection定义
        char32 order_id;                           // 委托单号
    };

    // 券源通展期前置判断请求
    struct QytExtensionPreJudgeReq {
        char32 symbol;                              // 标的代码，格式为市场.证券ID  
        int32_t sys_date;                           // 系统日期，格式为YYYYMMDD
        char32 sno;                                 // 流水号
        int32_t old_end_date;                       // 原到期日，格式为YYYYMMDD
    };
    
    // 券源通展期前置判断应答消息
    struct QytExtensionPreJudgeRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char128 prompt_msg;                         // 提示信息 备注：校验通过，这个字段不返回任何值
    };
    
    // 券源通展期申请委托请求
    struct QytExtensionOrderReq {
        char32 secuid;                              // 股东代码，非必传
        char cust_type;                             // 客户类型，参考QytClientType定义
        char32 symbol;                              // 标的代码，格式为市场.证券ID  
        int32_t sys_date;                           // 系统日期，格式为YYYYMMDD
        char32 sno;                                 // 流水号
        int32_t old_end_date;                       // 原到期日，格式为YYYYMMDD
        Ratio_t admin_rate;                         // 展期管理费率，扩大一万倍，单位% 
        Ratio_t fee_rate;                           // 展期费率，扩大一万倍，单位%
        int16_t directed_type;                      // 定向标志，参考QytDirectedType定义
        int16_t wy_status;                          // 违约状态，参考ViolationStatus定义
        int64_t qty;                                // 展期数量
        int32_t new_end_date;                       // 展期新到期日，格式为YYYYMMDD
		char limit_type;                            // 自动展期期限类型，参考QytLimitType定义，非必填
													// 默认和原合约期限类型一致
    };
    
    // 券源通展期申请委托应答
    struct QytExtensionOrderRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 order_id;                            // 委托编号
    };
    
    // 券源通展期申请查询请求
    struct QryQytExtensionOrderListReq {
        char32 pos_str;                             // 起始定位串，填""表示第一次从头开始查 默认是页码，从1开始，固定每页100行 
        int32_t begin_date;                         // 开始日期YYYYMMDD
        int32_t end_date;                           // 结束日期YYYYMMDD
        char16 stk_code;                            // 证券代码，非必传
        char32 entrust_status_list;                 // 委托状态列表，参考QytEntrustStatus定义，查询全部填写1,2,5,6
    };
    
    // 券源通展期申请明细
    struct QytExtensionOrderDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 pos_str;                             // 查询定位串
        int64_t oper_time;                          // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
        char32 stk_name;                            // 证券名称 
        char16 stk_code;                            // 证券代码
        int32_t apply_period;                       // 申请期限
        Ratio_t fee_rate;                           // 申请费率，扩大一万倍，单位%
        int64_t qty;                                // 展期数量
        int16_t entrust_status;                     // 展期状态，参考QytEntrustStatus定义
        char32 order_id;                            // 委托编号
        int32_t new_end_date;                       // 展期新到期日，格式为YYYYMMDD
        int32_t old_end_date;                       // 原到期日，格式为YYYYMMDD
        int32_t sys_date;                           // 系统日期，格式为YYYYMMDD
        char32 sno;                                 // 流水号
        char32 contract_no;                         // 合约编号
        int16_t other_status;                       // 其他状态，参考QytOtherStatus定义
        int16_t proc_status;                        // 处理状态，参考QytProcessStatus定义
        char channel;                               // 渠道，参考QytChannelType定义
		char limit_type;                            // 自动展期期限类型，参考QytLimitType定义
    };
    
    // 券源通展期申请撤销请求
    struct CancelQytExtensionOrderReq {
        char32 order_id;                            // 委托编号
    };
    
    // 券源通展期申请撤销应答
    struct CancelQytExtensionOrderRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char128 prompt_msg;                         // 提示信息
    };

	// 查询约券合约请求
	struct QCQueryAppointmentContractReq {
		int32_t query_num;						 // 查询条数
		char hy_status;                          // 合约状态,Y, 参考QC_Ehyzt
		char32 stkcode;                          // 证券代码 N
		char128 pos_str;                         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
		char32 market;                           // 交易市场;一户两地账户必传,非一户两地建议传值用以兼容一户两地,如"SZ"或者"SH"
	};

	// 查询约券合约应答明细
	struct QCQueryAppointmentContractDetail {
		char16 account_id;                        // 交易账号，目前是资金账号
		char8 cust_orgid;                         // 机构编码
		char8 cust_branchid;                      // 分支编码
		int16_t account_type;                     // 交易账号类型，参考AccountType定义
		char32 symbol;							  // 证券标的
		char32 stkname;                           // 证券简称
        int32_t sys_date;                         // 系统日期
		char32 sno;	                              // 合约流水号
		char hy_status;                           // 合约状态，参考QC_Ehyzt
		int32_t lock_qty;                         // 锁定数量
		int32_t sale_frz_qty;                     // 日间卖出冻结
		int32_t used_qty;                         // 已使用数量
		int32_t back_qty;                         // 回收数量
		char ext_type;                            // 展期申请标记;参考QC_Ezqsqfs
		int32_t begin_date;                       // 锁定日期,起始日;yyyyMMdd;下同
		int32_t back_date;                        // 归还日期（到期日-1）保证为交易日
		int32_t end_date;                         // 到期日期
		int32_t real_date;                        // 了结日期
		int32_t last_date;                        // 最后计息日期
		char have_extend;                         // 展期审批,参考QC_HaveExtend
		Ratio_t used_fee_rate;					  // 融券费率,扩大1W倍,单位%
		Ratio_t unused_fee_rate;				  // 约券管理费率,扩大1W倍,单位%
		Amt_t used_fee;							  // 使用费，扩大一万倍
		Amt_t unused_fee;						  // 约券管理费，扩大一万倍
		char special_book_type;                   // 特殊预约标志，参考QC_Etsyybz
		char128 pos_str;                          // 查询定位串
	};

    // 券池客户合约定价信息查询请求
    struct QCQueryCustContractPriceInfoReq {
        char32 pos_str;                            // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条
    };

    // 券池客户合约定价信息详情
    struct QCQueryCustContractPriceInfoDeatil {
        char16 account_id;                         // 交易账号，目前是资金账号
        char8 cust_orgid;                          // 机构编码
        char8 cust_branchid;                       // 分支编码
        int16_t account_type;                      // 交易账号类型，参考AccountType定义
        char16 cust_id;                            // 客户代码
        char32 stk_code;                           // 证券代码
        char64 stk_name;                           // 证券名称
        int32_t sys_date;                          // 系统日期
        char32 sno;                                // 合约流水号
        int32_t end_date;                          // 到期日期
        int64_t unused_qty;                        // 当前股数
        Ratio_t used_fee_rate;                     // 融券费率，扩大1W倍，单位%
        Ratio_t unused_fee_rate;                   // 约券管理费率，扩大1W倍，单位%
        char ext_type;                             // 自动展期（展期申请标记），参考QC_Ezqsqfs
        char have_extend;                          // 展期审批，展期审批，参考QC_HaveExtend
        Ratio_t down_pricing_fee;                  // 当日参考费率，扩大1W倍，单位%
        int32_t current_date;                      // 更新日期（当日日期）
    };

    // 券源通预告申报请求
    struct QytForecastOrderReq {
        char32 symbol;							  // 标的代码，格式为市场.证券ID
        char client_type;					      // 客户类型,参考QytClientType
        char limit_type;						  // 期限类型,参考QytLimitType
        int64_t order_qty;						  // 委托数量
        int64_t min_qty;						  // 最小数量
        int32_t time_limit;					      // 期限
        int32_t min_time_limit;					  // 最小期限
        Ratio_t admin_rate;					      // 管理费率,小数点后最多两位;扩大1W倍,单位%
        Ratio_t rate;							  // 利率,小数点后最多两位;扩大1W倍,单位%
        int32_t valid_endtime;					  // 有效截至日期yyyymmdd
    };

    // 券源通预告申报应答明细
    struct QytForecastOrderDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 entrust_no;                        // 委托编号
    };

    // 券源通定向申报请求
    struct QytDirectOrderReq {
        char32 symbol;							  // 标的代码，格式为市场.证券ID
        char client_type;					      // 客户类型,参考QytClientType
        char limit_type;						  // 期限类型,参考QytLimitType
        int64_t order_qty;						  // 委托数量
        int64_t min_qty;						  // 最小数量
        int32_t time_limit;					      // 期限
        int32_t min_time_limit;					  // 最小期限
        Ratio_t admin_rate;					      // 管理费率,小数点后最多两位;扩大1W倍,单位%
        Ratio_t rate;							  // 利率,小数点后最多两位;扩大1W倍,单位%
        int32_t valid_endtime;					  // 有效截至日期yyyymmdd
        char32 qd_id;                             // 关联定向券源id
        char32 dxzrt_id;                          // 定向转融通单号
    };

    // 券源通定向申报应答明细
    struct QytDirectOrderDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 entrust_no;                        // 委托编号
    };


    // 券源通标准篮子申报请求
    struct QytBasketOrderReq {
        char client_type;                         // 客户类型,参考QytClientType
        int32_t valid_endtime;                    // 有效截至日期yyyymmdd
        int32_t time_limit;                       // 使用期限（最小为3，最大为182）
        Ratio_t rate;                             // 约券费率,小数点后最多两位;扩大1W倍,单位%
        int64_t amount;                           // 篮子申报分数（最小为1，最大为1000）
        Ratio_t admin_rate;                       // 约券管理费率,小数点后最多两位;扩大1W倍,单位%
        char64 bsk_name;                          // 篮子名称（只能由汉字英文字母和数字组成）
        char32 bsk_code;                          // 篮子代码
        char limit_type;                          // 期限类型,参考QytLimitType
    };

    // 券源通标准篮子申报应答
    struct QytBasketOrderDetail {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 id;                                // 主键id
        int32_t trade_day;                        // 交易日YYYYMMDD
        char32 entrust_no;                        // 委托编号
        Ratio_t min_satisfy = 4;                  // 最低满足比例，扩大一万倍
        Ratio_t deal_amount_ratio = 5;            // 当前满足比例，扩大一万倍
        int64_t amount;                           // 委托份数
        char direction;                           // 委托方向，参考QytDirection定义
        char en_type;                             // 委托方式,参考QytBEnType
        int64_t entrust_time;                     // 委托时间YYYYMMDDHHMMSS
        int16_t entrust_status;                   // 委托状态，参考QytEntrustStatus定义  
        int16_t other_status;                     // 其他状态，参考QytOthStatus定义 
        int16_t allot_status;                     // 调拨状态，参考QytAllotStatus定义
        char64 bsk_name;                          // 篮子名称
        char32 bsk_code;                          // 篮子代码
        char bsk_type;                            // 篮子类型，参考QytBskType定义
        Ratio_t admin_rate;                       // 管理费率(6.0表示6.0%)，扩大一万倍
        Ratio_t rate;                             // 费率（6.0表示6.0%），扩大一万倍
        int32_t time_limit;                       // 期限
        char limit_type;                          // 期限类型，参考QytLimitType
        int64_t deal_amount;                      // 已成交份数
        Ratio_t score;                            // 分数值，扩大一万倍
        char32 client_id;                         // 客户代码
        char128 client_name;                      // 客户姓名
        char client_type;                         // 客户类型，参考QytClientType
        char32 busin_account;                     // 资金账号
        char32 stock_account;                     // 股东代码（上海）
        char32 stock_account_sz;                  // 信用股东账户（深圳）
        char32 branch_no;                         // 机构代码
        int64_t valid_start_time;                 // 有效开始时间YYYYMMDDHHMMSS
        int64_t valid_end_time;                   // 有效截至时间YYYYMMDDHHMMSS
        int64_t cancel_time;                      // 撤单时间YYYYMMDDHHMMSS
        int64_t invalid_time;                     // 失效时间YYYYMMDDHHMMSS
        int64_t deal_time;                        // 最近一次触发成交成交时间YYYYMMDDHHMMSS
        int32_t new_end_date;                     // 展期申请新到期日YYYYMMDD
        char channel;                             // 渠道，参考QytChannelType定义
        char512 remark;                           // 备注
    };

    // 券源通篮子申报撤单请求
    struct CancelQytBasketOrderReq {
        char32 entrust_no;                        // 被撤的原订单id
    };

    // 券源通篮子申报撤单应答
    struct CancelQytBasketOrderRsp {
        char16 account_id;                         // 交易账号，目前是资金账号
        char8 cust_orgid;                          // 机构编码
        char8 cust_branchid;                       // 分支编码
        int16_t account_type;                      // 交易账号类型，参考AccountType定义
        char256 data;                              // 撤单成功输出文案
    };


    // 券源通篮子申报查询请求
    struct QueryQytBasketOrderReq {
        char32 pos_str;                            // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条，非必传
        int64_t begin_date;                        // 委托开始时间 YYYYMMDD，非必传
        int64_t end_date;                          // 委托截止时间 YYYYMMDD，非必传
        char32 direction_list;                     // 委托方向集合，参考QytDirection定义，必传
                                                   // 标准篮子传g，定制篮子传h,全部篮子g,h；多个状态间用','分隔 
        char32 entrust_status_list;                // 委托状态集合，参考QytEntrustStatus定义，非必传，多个状态间用','分隔
        char32 entrust_no;                         // 委托单号（查询单个篮子母单时可以只传委托单号），非必传
    };

    // 券源通篮子申报查询应答明细
    struct QytBasketOrderRecord {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        int64_t no_deal_amount;                   // 未成交数量
        int64_t cancel_amount;                    // 撤单数量
        char64 branch_name;                       // 机构名称
        Ratio_t weighted_cost_rate;               // 加权成本费率，扩大一万倍
        char32 id;                                // 主键id
        int32_t trade_day;                        // 交易日YYYYMMDD
        char32 entrust_no;                        // 委托编号
        Ratio_t min_satisfy = 4;                  // 最低满足比例，扩大一万倍
        Ratio_t deal_amount_ratio = 5;            // 当前满足比例，扩大一万倍
        int64_t amount;                           // 委托份数
        char direction;                           // 委托方向，参考QytDirection定义
        char en_type;                             // 委托方式,参考QytBEnType
        int64_t entrust_time;                     // 委托时间YYYYMMDDHHMMSS
        int16_t entrust_status;                   // 委托状态，参考QytEntrustStatus定义  
        int16_t other_status;                     // 其他状态，参考QytOthStatus定义 
        int16_t allot_status;                     // 调拨状态，参考QytAllotStatus定义
        char64 bsk_name;                          // 篮子名称
        char32 bsk_code;                          // 篮子代码
        char bsk_type;                            // 篮子类型，参考QytBskType定义
        Ratio_t admin_rate;                       // 管理费率(6.0表示6.0%)，扩大一万倍
        Ratio_t rate;                             // 费率（6.0表示6.0%），扩大一万倍
        int32_t time_limit;                       // 期限
        char limit_type;                          // 期限类型，参考QytLimitType
        int64_t deal_amount;                      // 已成交份数
        Ratio_t score;                            // 分数值，扩大一万倍
        char32 client_id;                         // 客户代码
        char128 client_name;                      // 客户姓名
        char client_type;                         // 客户类型，参考QytClientType
        char32 busin_account;                     // 资金账号
        char32 stock_account;                     // 股东代码（上海）
        char32 stock_account_sz;                  // 信用股东账户（深圳）
        char32 branch_no;                         // 机构代码
        int64_t valid_start_time;                 // 有效开始时间YYYYMMDDHHMMSS
        int64_t valid_end_time;                   // 有效截至时间YYYYMMDDHHMMSS
        int64_t cancel_time;                      // 撤单时间YYYYMMDDHHMMSS
        int64_t invalid_time;                     // 失效时间YYYYMMDDHHMMSS
        int64_t deal_time;                        // 最近一次触发成交成交时间YYYYMMDDHHMMSS
        int32_t new_end_date;                     // 展期申请新到期日YYYYMMDD
        char channel;                             // 渠道，参考QytChannelType定义
        char512 remark;                           // 备注
    };

    // 券源通标准篮子申报详情请求
    struct QueryQytBasketOrderDetailReq {
        char32 basket_entrust_no;              // 关联篮子委托单号，必传
        char direction;                        // 委托方向，参考QytDirection定义，固定传标准篮子，必传
        char32 stock_code;                     // 证券代码（查询单个标准篮子子单时使用），非必传
        char32 pos_str;                        // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条，非必传
    };

    // 标准篮子申报详情明细
    struct QytBasketOrderDetailRecord {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 id;                                // 主键id
        int32_t trade_day;                        // 交易日YYYYMMDD
        char32 entrust_no;                        // 关联委托表的委托单号
        char direction;                           // 委托方向，参考QytDirection定义
        int64_t amount;                           // 成交数量
        int64_t deal_time;                        // 成交时间YYYYMMDDHHMMSS
        char deal_type;                           // 成交类型，参考QytDealType定义
        char64 stock_name;                        // 证券名称
        char32 stock_code;                        // 证券代码
        char stock_type;                          // 证券类型，参考QytStockType定义
        Ratio_t rate;                             // 费率（6.0表示6.0%），扩大一万倍
        Ratio_t admin_rate;                       // 管理费率(6.0表示6.0%)，扩大一万倍
        int64_t time_limit;                       // 期限
        char32 deal_no;                           // 成交单号
        char s_info_type_code;                    // 分类代码，参考QytSInfoTypeCode定义
        char32 allot_no;                          // 调拨单号
        char32 stk_id;                            // 券池id
        int64_t turn_amount;                      // 调拨到账数量
        char32 client_id;                         // 客户代码
        char128 client_name;                      // 客户姓名
        char32 busin_account;                     // 资金账号
        char32 stock_account;                     // 股东代码
        char32 branch_no;                         // 机构代码
        char32 market;			                  // 交易市场，如 "SZ" 或者 "SH"
        char32 pool_no;                           // 券池id-标签
        char32 pool_name;                         // 券池名称
        char32 ls_no;                             // 撮合流水编号
        int16_t allot_status;                     // 调拨状态，参考QytAllotStatus定义
        int16_t other_status;                     // 其他状态，参考QytOthStatus定义
        char32 confirm_user;                     // 确认人
        int64_t confirm_time;                     // 确认时间YYYYMMDDHHMMSS
        char512 remark;                           // 备注
        char32 basket_entrust_no;                 // 关联篮子委托单号
        Amt_t price;                              // 股价，扩大一万倍
        int32_t new_start_date;                   // 新合约起始日期YYYYMMDD
        int32_t new_end_date;                     // 成交到期日YYYYMMDD
        int16_t process_status;                   // 处理状态，参考QytProcessStatus定义
        int64_t process_time;                     // 处理时间YYYYMMDDHHMMSS
        int64_t delay_amount;                     // 实际展期数量
        int64_t recovery_amount;                  // 处理日回收数量
        char limit_type;                          // 期限类型，参考QytLimitType定义
        char32 dxzrt_id;                          // 定向转融通单号C30
        int32_t sys_date;                         // 系统日期YYYYMMDD
        char32 sno;                               // 原合约流水号
        char special_book;                        // 特殊预约标志，参考QytSpecialBook定义
        char64 branch_name;                       // 机构名称
        int64_t deal_amount;                      // 成交数量，同amount
    };

    // 券源通定制篮子申报详情请求
    struct QueryQytCustBasketOrderDetailReq {
        char32 basket_entrust_no;              // 关联篮子委托单号，必传
        char direction;                        // 委托方向，参考QytDirection定义，固定传定制篮子，必传
        char32 stock_code;                     // 证券代码（查询单个标准篮子子单时使用），非必传
        char32 pos_str;                        // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串，固定返回100条，非必传
    };

    // 定制篮子申报详情明细
    struct QytCustBasketOrderDetailRecord {
        char16 account_id;                        // 交易账号，目前是资金账号
        char8 cust_orgid;                         // 机构编码
        char8 cust_branchid;                      // 分支编码
        int16_t account_type;                     // 交易账号类型，参考AccountType定义
        char32 id;                                // 主键id
        char32 entrust_no;                        // 定制篮子子单委托编号
        int64_t amount;                           // 委托数量
        char64 stock_name;                        // 证券名称
        char32 stock_code;                        // 证券代码
        int64_t entrust_time;                     // 委托时间YYYYMMDDHHMMSS
        int16_t entrust_status;                   // 委托状态，参考QytEntrustStatus定义
        int64_t deal_amount;                      // 成交数量
        int64_t arrival_amount;                   // 到账数量
        int16_t other_status;                     // 其他状态，参考QytOthStatus定义 
    };


	// 资产总值分类查询请求
    struct QryTotalFundAssetDetailReq {
        int16_t currency_type;      // 货币类型，参考CurrencyType定义，非必传
                                    // 默认查所有，仅集中交易柜台支持
        char32 market;              // 交易市场，如 "SZ" 或者 "SH"，非必传
                                    // 默认查单市场，仅支持低延时一户两地分市场管理
    };
    
    // 资产总值分类明细数据
    struct TotalFundAssetDetail {
        char16 account_id;                  // 交易账号，目前是资金账号
        char8 cust_orgid;                   // 机构编码
        char8 cust_branchid;                // 分支编码
        int16_t account_type;               // 交易账号类型，参考AccountType定义
        char128 cust_name;                  // 客户姓名
        int16_t currency_type;              // 货币类型，参考CurrencyType定义
        Amt_t fundassettotal;               // 总资产  
        Amt_t fundassettotalnew;            // 总资产新  
        Amt_t fundasset;                    // 资金资产  
        Amt_t fundassetbal;                 // 资金余额  
        Amt_t fundassetavl;                 // 资金可用 
        Amt_t fundassetggt;                 // 港股通T+1日未交收资金  
        Amt_t fundassetstktotal;            // 证券总资产  
        Amt_t fundassetstk;                 // 证券资产  
        Amt_t fundassetbondtotal;           // 债券总资产  
        Amt_t fundassetbond;                // 债券资产  
        Amt_t fundassetrzgh;                // 国债正回购  
        Amt_t fundassetrqgh;                // 负值国债逆回购  
        Amt_t fundassetstkzy;               // 债券质押资产  
        Amt_t fundassetrzcs;                // 协议融资  
        Amt_t fundassetrqcs;                // 负值协议融券  
        Amt_t fundassetstkxyzy;             // 协议债券质押资产  
        Amt_t fundassetadjust;              // 待交收证券资产  
        Amt_t fundassetoftotal;             // 理财总资产  
        Amt_t fundassetof;                  // 基金资产 不包含现金管家，不提供OTC 及多金
        Amt_t fundassetbjhgsh;              // 上海报价回购  
        Amt_t fundassetbjhgsz;              // 深圳报价回购  
        Amt_t fundassetofuncome;            // 基金认申购定投未确认在途资金  
        Amt_t fundassetxjgj;                // 现金管家  
        Amt_t fundassetzfzz;                // 支付转账  
        Amt_t fundassetjdlsec;              // 君得利二号  
        Amt_t fundassetfjjj;                // 分级基金  
        Amt_t fundassetcurdayrqgh;          // 融券购回当日到期  
        Amt_t fundassetcurdayrzgh;          // 融资购回当日到期  
        Amt_t fundassetotcend;              // OTC当日到期 这部分延期到6月8号 
        Amt_t debtstotal;                   // 总负债  
        Amt_t zy_mtkvalue;                  // 负值应收股票质押市值  
        Amt_t zy_debts;                     // 股票质押负债  
        Amt_t en_mktvalue;                  // 负值应收约定购回市值  
        Amt_t en_debts;                     // 约定购回负债  
        Amt_t zywymktvalue;                 // 负值股票质押违约卖出市值  
        Amt_t fundassetmatchrqgh;           // 国债逆回购当日成交  
        Amt_t sumprofitamt;                 // 证券资产总浮动盈亏  
        Amt_t fundassetstkwxxj;             // 网下现金认购资产 该资产从资金资产挪到股票资产新三板新股申购 
        Amt_t fundassetadjust_xsf;          // 在途资金  
        Amt_t fundassetadjust_qt;           // 配股配债在途资金  
        Amt_t fundassetadjust_hgt;          // 港股通在途资金  
        Amt_t fundassetadjust_b2h;          // b转H在途资金  
    };

	//  基金确认信息查询
	struct QueryFundConfirmInfoReq {
		char32 pos_str;            // 定位串,填""表示第一次从头开始查
		int32_t query_num;         // 查询数量
		int32_t enddate;           //结束日期N,0表示无结束日期
		int32_t strdate;           //开始日期N,0表示无开始日期
		int64_t tacode;            //基金公司N,0表示查全部
		char16 taacc;              //基金帐号N
		char32 transacc;           //交易帐号N
		char16 ofcode;             //基金代码N
		int16_t share_class;	   //收费方式N，参考OfShareClass
		int32_t matchdate;         //确认日期N送0查全部，如果以下三者同时传值要求matchdate必须在strdate和enddate之间
		int32_t matchsno;          //确认编号N送0查全部
		int32_t orderdate;         //原委托日期N送0查全部
		int32_t ordersno;          //原委托编号N送0查全部，部分非客户主动发起的业务，如强增、分红等无委托编号，数据库中默认为0。
		char tsbztype;             //查询类型N, A：基金组合编号，B：定投计划编号
		char qryflag;              //查询方向Y, '0'=顺序 '1'=倒序
		char256 tsbz;              //特殊备注信息N不传查tsbztype类型下的全部数据，传值时与tsbztype组合查询。
	};

	struct QueryFundConfirmInfoDetail {
		char16 account_id;                  // 交易账号，目前是资金账号
		char8 cust_orgid;                   // 机构编码
		char8 cust_branchid;                // 分支编码
		int16_t account_type;               // 交易账号类型，参考AccountType定义

		char32 poststr;                     //定位串
		double transqty;                    //转入确认份额,Trdid=240136基金转换出确认，有效小数位两位
		int32_t matchdate;                  //成交日期　
		int32_t sno;                        //成交流水号　
		int64_t discratio;                  //费用折扣率，扩大一亿倍
		int64_t tacode;                     //基金公司　
		char16 taacc;                       //基金帐号　
		char32 transacc;                    //交易帐号　
		char16 ofcode;                      //基金代码　
		char32 ofname;                      //基金名称　
		int32_t orderdate;                  //委托日期　
		int32_t ordersno;                   //委托号　
		int32_t trdid;                      //交易类型，参考FundOrderSide
		char32 trdidname;                   //交易类型名
		int16_t divid_method;		        //分红方式,FundDividMethod
		Amt_t orderamt;                     //委托金额，扩大一万倍
		double orderqty;                    //委托数量，有效小数位两位
		double matchqty;                    //成交份数，有效小数位两位
		Amt_t matchamt;                     //成交金额，扩大一万倍
		Amt_t nav;                          //基金净值，扩大一万倍
		char16 othertaacc;                  //对方基金帐号　
		char32 othertransacc;               //对方交易帐号　
		char16 otherofcode;                 //转换基金代码　
		char8 errcode;                      //错误代码
		Amt_t fee;                          //费用之和，扩大一万倍
		Amt_t backfare;                     //后端收费，扩大一万倍
		Amt_t feestamptax;                  //印花税，扩大一万倍
		Amt_t agentfee;                     //代理费，扩大一万倍
		Amt_t otherfee;                     //其他费用，扩大一万倍
		Amt_t confirmedamt;                 //确认金额，扩大一万倍
		char64 errmsg;                      //错误信息
		char256 extstr2;                    //其他备注如果tsbztype和tsbz传值时，返回tsbz类型下所有tsbztype条件查询的值，否则查询所有
	};

	//外围基金交收信息查询410960
	struct QueryFundSettleMentReq {
		char32 pos_str;            // 定位串,填""表示第一次从头开始查
		int32_t query_num;         // 查询数量
		int32_t enddate;           //结束日期N,0表示无结束日期
		int32_t strdate;           //开始日期N,0表示无开始日期
		int32_t settledate;        //清算日期N
		int64_t tacode;            //基金公司N,0表示查全部
		char16 taacc;              //基金帐号N
		char32 transacc;           //交易帐号N
		char16 ofcode;             //基金代码Y
		int16_t share_class;	   //收费方式N，参考OfShareClass
		int32_t orderdate;         //原委托日期N送0查全部
		int32_t ordersno;          //原委托编号N送0查全部，部分非客户主动发起的业务，如强增、分红等无委托编号，数据库中默认为0。
		char qryflag;              //查询方向Y, '0'=顺序 '1'=倒序
	};

	struct QueryFundSettleMentDetail {
		char16 account_id;                  // 交易账号，目前是资金账号
		char8 cust_orgid;                   // 机构编码
		char8 cust_branchid;                // 分支编码
		int16_t account_type;               // 交易账号类型，参考AccountType定义

		char32 poststr;                     //定位串
		int32_t bizdate;                    //交收日期
		int32_t sno;                        //资金流水号
		char128 remark;                     //备注
		int64_t tacode;                     //基金公司
		char16 taacc;                       //基金帐号
		char32 transacc;                    //交易帐号
		char16 ofcode;                      //基金代码
		char32 ofname;                      //基金名称
		int32_t orderdate;                  //委托日期
		int32_t ordersno;                   //委托号
		int32_t trdid;                      //交易类型，参考FundOrderSide
		char32 trdidname;                   //交易类型名
		Amt_t fee;                          //费用之和
		Amt_t backfee;                      //后端收费
		Amt_t feestamptax;                  //印花税
		Amt_t agentfee;                     //代理费
		Amt_t otherfee;                     //其他费用
		Amt_t confirmedamt;                 //确认金额
	};

	//基金历史交易查询
	struct QueryFundHisTransacReq {
		char32 pos_str;            // 定位串,填""表示第一次从头开始查
		int32_t query_num;         // 查询数量
		int32_t enddate;           //结束日期N,0表示无结束日期
		int32_t strdate;           //开始日期N,0表示无开始日期
		int32_t trdid;             //交易类型N，参考FundOrderSide,0表示查全部
		int64_t tacode;            //基金公司N,0表示查全部
		char16 taacc;              //基金帐号N
		char32 transacc;           //交易帐号N
		char16 ofcode;             //基金代码Y
		int16_t share_class;	   //收费方式N，参考OfShareClass
		char tsbztype;             //查询类型N, A：基金组合编号，B：定投计划编号
		char qryflag;              //查询方向Y, '0'=顺序 '1'=倒序
		char256 tsbz;              //特殊备注信息N不传查tsbztype类型下的全部数据，传值时与tsbztype组合查询。
	};

	struct QueryFundHisTransacDetail {
		char16 account_id;                    // 交易账号，目前是资金账号
		char8 cust_orgid;                     // 机构编码
		char8 cust_branchid;                  // 分支编码
		int16_t account_type;                 // 交易账号类型，参考AccountType定义
	
		char32 poststr;                       //定位串
		int32_t predate;                      //预约的赎回日期，格式为YYYYMMDD
		int32_t operdate;                     //发生日期，格式为YYYYMMDD
		int32_t opertime;                     //发生时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
		int32_t orderdate;                    //委托日期，格式为YYYYMMDD
		int32_t sno;                          //委托流水号
		Amt_t backfee;                        //后台收费
		char redeemtype;                      //巨额赎回标志，参考RedeemType
		int32_t oldoperdate;                  //原申请日期，格式为YYYYMMDD
		char32 oldsn;                         //原申请单号
		int64_t tacode;                       //基金公司
		char16 taacc;                         //基金帐号
		char32 transacc;                      //交易帐号
		char16 ofcode;                        //基金代码
		char32 ofname;                        //基金名称
		int16_t shareclass;                   //收费方式，参考OfShareClass
		int32_t trdid;                        //交易类型，参考FundOrderSide
		char32 trdidname;                     //交易类型名称前台解析
		int32_t cancel_flag;				  //撤消标志
		int32_t order_status;				  //委托状态，参考FundOrderStatus定义
		char32 entrustname;                   //委托状态名称前台解析
		char32 errinfo;                       //返回错误信息
		int16_t dividmethod;                  //分红方式，参考FundDividMethod定义
		Amt_t orderamt;                       //委托金额
		char16 othertaacc;                    //对方基金帐号
		char32 othertransacc;                 //对方交易帐号
		char16 otherofcode;                   //转换基金代码
        
        // 以下两个字段代替上面两个已删除的数量类字段，倍数由原来扩大1w倍改为不扩大倍数，注意做相应倍数处理
        double orderqtynew;                    //委托数量，有效小数位两位
        double havematchqtynew;                //已成交数量，有效小数位两位
	};

	//基金产品风险揭示书签署410882
	struct SignFundRiskGgreementReq {
		int64_t tacode;            //基金公司内部代码Y
		char16 ofcode;             //基金代码Y
	};

	struct SignFundRiskGgreementRsp {
		char16 account_id;                    // 交易账号，目前是资金账号
		char8 cust_orgid;                     // 机构编码
		char8 cust_branchid;                  // 分支编码
		int16_t account_type;                 // 交易账号类型，参考AccountType定义
		int32_t sysdate;                      // 日期
		char32 sno;                           // 操作流水号
	};

	// 资金横向划转请求
	struct LateralTransferOrderReq {
	    char8 branch_no_out;                        // 转出营业部编码  
	    char16 cust_id_out;                         // 转出客户代码，非必传，默认同一一户通下当前客户号  
	    char32 account_id_out;                      // 转出资金账号  
	    char16 account_pwd_out;                     // 转出资金密码  
	    char8 branch_no_in;                         // 转入营业部编码  
	    char32 account_id_in;                       // 转入资金账号  
	    Amt_t transfer_value;                       // 划转金额，扩大一万倍，币种人民币 
	};
	// 资金横向划转应答
	struct LateralTransferOrderRsp {
	    char16 account_id;                          // 交易账号，目前是资金账号
	    char8 cust_orgid;                           // 机构编码
	    char8 cust_branchid;                        // 分支编码
	    int16_t account_type;                       // 交易账号类型，参考AccountType定义
	    char32 serial_no;                           // 横向划转流水序号
	};
	
	// 查询横向划转流水请求
	struct QueryLateralTransferFlowReq {
	    char16 branch_no_out;                       // 转出营业部编码
	    char16 branch_no_in;                        // 转入营业部编码
	};
	// 横向划转流水明细
	struct LateralTransferFlowDetail {
	    char16 account_id;                          // 交易账号，目前是资金账号
	    char8 cust_orgid;                           // 机构编码
	    char8 cust_branchid;                        // 分支编码
	    int16_t account_type;                       // 交易账号类型，参考AccountType定义
	    char32 account_id_out;                      // 转出资金账号  
	    char32 account_id_in;                       // 转入资金账号  
	    char32 serial_no;                           // 横向划转流水序号  
	    int16_t deal_status;                        // 横向划转处理状态，参考LTDealStatus定义  
	    Amt_t transfer_value;                       // 划转金额  
	    int32_t deal_date;                          // 发生日期，格式为YYYYMMDD
	    int64_t deal_time;                          // 发生时间，格式为HHMMSSmmm，首位为0不显示
	    int16_t lt_digest_code;                     // 横向划转业务摘要，参考LTBusiDigestCode定义  
	    int16_t currency_type;                      // 货币类型，参考CurrencyType定义
	    char256 remark;                             // 备注  
	};

// 券源通意向登记请求
struct QytIntenRegistraReq{
	char32 symbol;				                // 证券代码, 格式为市场.证券id
	char client_type;					        // 客户类型,参考QytClientType
	char stock_type;					        // 证券类型,参考QytStockType
	char limit_type;						    // 期限类型,参考QytLimitType
	char strategy;								// 融券策略,参考QytStrategy
	int64_t order_qty;						    // 委托数量
	int64_t min_qty;						    // 最小数量
	Ratio_t rate;							    // 融券费率,小数点后最多两位;扩大1W倍,单位%
	int32_t time_limit;					        // 期限
	int32_t valid_starttime;					// 最早用券日期
	int32_t valid_endtime;					    // 最晚用券日期
	char16 mobile;                              // 联系电话(11位)
};

// 券源通意向登记应答明细
struct QytIntenRegistraRsp {
	char16 account_id;                        // 交易账号，目前是资金账号
	char8 cust_orgid;                         // 机构编码
	char8 cust_branchid;                      // 分支编码
	int16_t account_type;                     // 交易账号类型，参考AccountType定义
	char32 entrust_no;                        // 委托编号
};

// 券源通意向登记查询请求
struct QytQueryIntenRegistraReq{
	char32 pos_str;                             // 起始定位串，填""表示第一次从头开始查 默认是页码，从1开始，固定每页100行 
	int32_t begin_date;                         // 开始日期YYYYMMDD
	int32_t end_date;                           // 结束日期YYYYMMDD
	char16 stk_code;                            // 证券代码，非必传
	char32 entrust_status_list;                 // 委托状态列表，参考QytEntrustStatus定义，查询全部列举所有,逗号分割
	char32 other_status_list;                   // 其他状态列表，参考QytOtherStatus定义，查询全部列举所有,逗号分割
};

// 券源通意向登记查询应答明细
struct QytQueryIntenRegistraRsp {
	char16 account_id;                        // 交易账号，目前是资金账号
	char8 cust_orgid;                         // 机构编码
	char8 cust_branchid;                      // 分支编码
	int16_t account_type;                     // 交易账号类型，参考AccountType定义
	char32 pos_str;                           // 查询定位串
	int64_t oper_time;                        // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
	char32 stk_name;                          // 证券名称  
	char16 stk_code;                          // 证券代码  
	int32_t time_limit;                       // 申请期限  
	Ratio_t rate;                             // 申请费率,扩大1万倍
	int64_t order_qty;                        // 申请股数  
	int64_t min_qty;						  // 最小数量
	int16_t entrust_status;                   // 委托状态,参考QytEntrustStatus
	int16_t other_status;                     // 其他状态,参考QytOtherStatus
	char strategy;                            // 融券策略,参考QytStrategy
	char limit_type;                          // 期限类型,参考QytLimitType
	char32 entrust_no;                        // 委托编号  
	int32_t valid_start_date;                 // 委托生效日期,YYYYMMDD
	int64_t valid_start_time;                 // 委托生效时间,格式HHMMSSmmm，首位为0不显示
	int32_t valid_end_date;                   // 委托截止日期,YYYYMMDD
	int64_t valid_end_time;                   // 委托截止时间,格式HHMMSSmmm，首位为0不显示
	char16 mobile;                            // 联系电话(11位的手机号)
};

    // 券源通提前了结前置判断请求
    struct QytSettleEarlyPreJudgeReq {
        char32 symbol;                              // 标的代码，格式为市场.证券ID  
        int64_t qty;                                // 提前了结股数  
        double rate;                                // 原合约融券费率，有效小数位4位
        int32_t sys_date;                           // 原合约日期，格式为YYYYMMDD
        int32_t old_end_date;                       // 原合约到期日，格式为YYYYMMDD
        char32 sno;                                 // 原合约流水号 
    };
    // 券源通提前了结前置判断应答
    struct QytSettleEarlyPreJudgeRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char current_flag;                          // 当前时间在15:00前或者后的标志，参考AfterCloseFlag定义  
        int32_t repay_date;                         // 提前归还日期，格式为YYYYMMDD
        int32_t new_end_date;                       // 更改后到期日，格式为YYYYMMDD
        Amt_t admin_cost;                           // 提前了结管理费  
        int32_t time_limit;                         // 提前了结天数  
        double early_rate;                          // 提前了结费率，有效小数位6位 
        int64_t qty;                                // 提前了结股数  
        Amt_t price;                                // 昨收股价  
        int64_t ratio_rate;                         // 提前了结系数，扩大一万倍  
    };
    
    // 券源通提前了结申请请求
    struct QytSettleEarlyOrderReq {
        int32_t repay_date;                         // 提前归还日期，格式为YYYYMMDD
        int32_t new_end_date;                       // 更改后到期日，格式为YYYYMMDD
        int32_t time_limit;                         // 提前了结天数 
        Amt_t admin_cost;                           // 提前了结管理费 
        Amt_t price;                                // 昨收股价 
        int64_t ratio_rate;                         // 提前了结系数，扩大一万倍
        char current_flag;                          // 当前时间在15:00前或者后的标志，参考AfterCloseFlag定义
        char32 symbol;                              // 标的代码，格式为市场.证券ID  
        int64_t qty;                                // 提前了结股数 
        double rate;                                // 原合约融券费率，有效小数位4位
        int32_t sys_date;                           // 原合约日期，格式为YYYYMMDD
        int32_t old_end_date;                       // 原合约到期日，格式为YYYYMMDD
        char32 sno;                                 // 原合约流水号 
        char16 branch_no;                           // 机构代码（取原合约的机构代码）
    };
    // 券源通提前了结申请应答
    struct QytSettleEarlyOrderRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 order_id;                            // 申请单号
    };
    
    // 券源通提前了结查询请求
    struct QryQytSettleEarlyOrdersReq {
        char32 pos_str;                             // 起始定位串，填""表示第一次从头开始查 默认是页码，从1开始
        int32_t query_num;                          // 每页记录数，传0时默认查所有，开始日期和结束日期必填，且间隔不超过90天
        int32_t begin_date;                         // 开始日期YYYYMMDD，非必传，和结束日期须成对出现
        int32_t end_date;                           // 结束日期YYYYMMDD，非必传，和结束日期须成对出现，间隔不大于90天
        char16 stk_code;                            // 证券代码，非必传
    };
    // 券源通提前了结申请明细
    struct QytSettleEarlyOrderDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 pos_str;                             // 查询定位串
        int64_t order_time;                         // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
        char32 stk_name;                            // 证券名称 
        char16 stk_code;                            // 证券代码
        int32_t repay_date;                         // 提前归还日期，格式为YYYYMMDD
        int32_t new_end_date;                       // 提前了结到期日，格式为YYYYMMDD
        int32_t old_end_date;                       // 原合约到期日，格式为YYYYMMDD
        int32_t time_limit;                         // 提前了结天数 
        double rate;                                // 利率（融券费率）有效小数位6位
        int64_t ratio_rate;                         // 提前了结系数，扩大一万倍
        Amt_t admin_cost;                           // 提前了结管理费 
        int64_t qty;                                // 提前了结股数  
        char32 sno;                                 // 原合约流水号  
        char32 order_id;                            // 申请单号
        int32_t sys_date;                           // 原合约日期，格式为YYYYMMDD
        int16_t entrust_status;                     // 委托状态，参考QytEntrustStatus定义
        int16_t other_status;                       // 其他状态，参考QytOtherStatus定义
        int16_t approve_status;                     // 审批状态，参考FrontApprovalStatus定义
        int32_t belong_date;                        // 审批归属日期，格式为YYYYMMDD
    };
    
    // 券源通提前了结撤单请求
    struct CancelQytSettleEarlyOrderReq {
        char32 order_id;                            // 委托编号
    };
    // 券源通提前了结撤单应答 
    struct CancelQytSettleEarlyOrderRsp {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char128 prompt_msg;                         // 提示信息，撤单成功输出文案，撤单失败不返回任何文案
    };

	// 深圳报价回购合约查询请求
	struct QrySZQuoteRepoContractReq {
		char status;                                // 合约状态,不输入查全部,参考SZQuoteRepoStatus
		int32_t orderdate;                          // 委托日期
		char32 orderid;                             // 申报合同序号
		char16 prodcode;                            // 产品代码N
	};

	struct QrySZQuoteRepoContractDetail {
		char16 account_id;                          // 交易账号，目前是资金账号
		char8 cust_orgid;                 			// 机构编码
		char8 cust_branchid;              			// 分支编码
		int16_t account_type;             			// 交易账号类型，参考AccountType定义
		int32_t orderdate;                			// 委托日期
		char32 orderid;                   			// 申报合同序号
		char16 stkcode;                   			// 证券代码
		char16 prodcode;                  			// 产品代码6位的证券代码+3位购回天数+3位期号
		char createmethod;                			// 合约生成方式,参考QuoteRepoCreateMethod
		char contflag;                    			// 自动续约标志,参考QuoteRepoContFlag
		char yystatus;                    			// 提前购回预约状态,参考QuoteRepoYyStatus
		char status;                    			// 合约状态,参考SZQuoteRepoStatus
		Ratio_t lastrate;                 			// 到期利率
		Ratio_t callrate;                 			// 提前终止利率
		Amt_t matchamt;                   			// 成交金额
		int64_t matchqty;                 			// 成交数量
		int32_t gh_days;                  			// 购回天数
		char32 matchcode;                 			// 成交编号
		int32_t matchdate;                			// 成交日期
		int32_t enddate;                  			// 预计到期日期
		char32 stkname;                   			// 证券名称
		int64_t backqty;                  			// 累计己购回数量
		int64_t backqty_real;             			// 当天购回数量
		int64_t contqty;                  			// 可续约数量
		int32_t intbegindate;             			// 计息开始日
		int32_t intenddate;               			// 计息结束日
		Amt_t fundintpay;                 			// 累计已支付利息
		int32_t yydate;                   			// 预约操作日期
	};

	// 深圳报价回购委托请求
	struct SZQuoteRepoOrderReq {
		char32 symbol;							    // 证券代码
		char32 cl_order_id;                         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;                      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
		char32 secuid;                              // 股东代码,可选填
		char32 prodcode;                            // 产品编码
		int32_t orderqty;                           // 委托数量
		int32_t orderside;                          // 买卖方向
		char autoflag;                              // 自动续作,报价回购是否自动续作1是, 0否
	};

	struct SZQuoteRepoOrderRsp {
		char16 account_id;                          // 交易账号，目前是资金账号
		char8 cust_orgid;                 			// 机构编码
		char8 cust_branchid;              			// 分支编码
		int16_t account_type;             			// 交易账号类型，参考AccountType定义
		char32 cl_order_id;                         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;                      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
		char32 ordersno;                            // 委托序号
		char32 orderid;                             // 申报合同序号
		Amt_t orderprice;                           // 柜台返回的实际委托价格
		int32_t orderqty;                           // 柜台返回的实际委托数量
		Amt_t orderamt;                             // 柜台返回的实际委托金额
		Amt_t fundeffect;                           // 委托发生金额
		int32_t stkeffect;                          // 委托股份发生数
		int32_t orderdate;                          // 委托日期
	};

	// 深圳报价回购不再续做请求 410491
	struct SZQuoteRepoNoContinueReq {
		char32 matchcode;                           // 成交编号Y
		int32_t matchdate;                          // 成交日期Y
	};

	// 深圳报价回购不再续做应答
	struct SZQuoteRepoNoContinueRsp {
		char16 account_id;                          // 交易账号，目前是资金账号
		char8 cust_orgid;                 			// 机构编码
		char8 cust_branchid;              			// 分支编码
		int16_t account_type;             			// 交易账号类型，参考AccountType定义;无额外应答信息
	};

	// 深圳报价回购提前购回委托请求 410492
	struct SZQuoteRepoEarlyRepurchaseOrderReq {
		char32 cl_order_id;                         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;                      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
		int32_t brkqty;                             // 提前购回数量Y
		char32 matchcode;                           // 原合约成交编号Y
		int32_t matchdate;                          // 原合约成交日期Y
	};

	// 深圳报价回购提前购回委托应答
	struct SZQuoteRepoEarlyRepurchaseOrderRsp {
		char16 account_id;               // 交易账号，目前是资金账号
		char8 cust_orgid;                // 机构编码
		char8 cust_branchid;             // 分支编码
		int16_t account_type;            // 交易账号类型，参考AccountType
		char32 cl_order_id;              // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
		int32_t cl_order_date;           // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
		int32_t orderdate;               // 委托日期
		char32 ordersno;                 // 委托序号
	};

	// 深圳报价回购提前购回预约请求 410493
	struct SZQuoteRepoEarlyRepurchaseBookReq {
		char32 matchcode;                           // 成交编号Y
		int32_t matchdate;                          // 成交日期Y
		char16 prodcode;                            // 产品编码
		char32 symbol;							    // 证券代码
		char32 secuid;                              // 股东代码,可选填
	};

	// 深圳报价回购提前购回预约应答
	struct SZQuoteRepoEarlyRepurchaseBookRsp {
		char16 account_id;                          // 交易账号，目前是资金账号
		char8 cust_orgid;                 			// 机构编码
		char8 cust_branchid;              			// 分支编码
		int16_t account_type;             			// 交易账号类型，参考AccountType定义;无额外应答信息
	};

	// 深圳报价回购合约不再续做查询请求
	struct QrySZQuoteRepoNoContinueContractReq {
		
	};

	struct QrySZQuoteRepoNoContinueContractDetail {
		char16 account_id;                          // 交易账号，目前是资金账号
		char8 cust_orgid;                 			// 机构编码
		char8 cust_branchid;              			// 分支编码
		int16_t account_type;             			// 交易账号类型，参考AccountType定义;
		int32_t orderdate;                          // 委托日期
		char16 stkcode;                             // 证券代码
		char16 prodcode;                            // 产品代码6位的证券代码+3位购回天数+3位期号
		char32 matchcode;                           // 成交编号
		int32_t matchdate;                          // 成交日期
		char createmethod;                          // 合约生成方式,参考QuoteRepoCreateMethod
		char contflag;                              // 自动续约标志,参考QuoteRepoContFlag
		Ratio_t lastrate;                           // 到期利率
		Ratio_t callrate;                           // 提前终止利率
		Amt_t matchamt;                             // 成交金额,
		int64_t matchqty;                           // 成交数量
		char128 prodname;                           // 产品名称
	};
	
    // 报价回购利率额度查询请求
    struct QryQuoteRepoInteRateLimitReq {
        char32 symbol;                              // 标的代码，格式为市场.证券ID，非必传
    };
    // 报价回购利率额度明细
    struct QuoteRepoInteRateLimitDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 symbol;                              // 标的代码，格式为市场.证券ID
        char32 stk_name;                            // 证券名称 
        int64_t due_price;                          // 到期利率，扩大一万倍，单位%
        int64_t inter_price;                        // 提前终止利率，扩大一万倍，单位%
        bool oneday_flag;                           // 1天期品种标志 true-是 false-否
        int64_t gh_days;                            // 购回天数  
        Amt_t today_avl;                            // 当日可用额度  
        int32_t upd_date;                           // 更新日期  
        int16_t continue_flag;                      // 续作标识，参考ContinueFlag定义
    };
    
    // 深圳报价回购产品信息查询请求
    struct QrySZQuoteRepoProdInfoReq {
        int32_t gh_days;                // 产品购回天数，非必传
        char16 prod_code;               // 产品编码，非必传
    };
    // 深圳报价回购产品信息明细
    struct SZQuoteRepoProdInfoDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char16 prod_code;                           // 产品编码 6位的证券代码+3位购回天数+3位期号
        char16 prod_name;                           // 产品名称  
        bool is_valid;                              // 产品是否有效 false.否, true.是
        char32 symbol;                              // 标的代码 格式为市场.证券代码
        int64_t gh_days;                            // 购回天数  
        int32_t begin_date;                         // 发行日期，格式为YYYYMMDD 
        int32_t end_date;                           // 到期日期，格式为YYYYMMDD 
        int64_t last_rate;                          // 到期年收益率，扩大一亿倍
        int64_t call_rate;                                 // 提前终止收益率，扩大一亿倍
        int16_t buy_flag;                                  // 交易标志，参考QuoteRepoBuyFlag定义 
        bool auto_buy_flag;                                // 自动续作标志，false-不自动续作,true-自动续作
        int32_t next_begin_date;                    // 下轮发行日期，格式为YYYYMMDD 
        int16_t prod_mode;                                 // 产品模式，参考QuoteRepoProdMode定义
        int16_t special_prod;                              // 特殊产品，参考SpecialProd定义
        Amt_t bond_avl_amt;                                // 可用额度  
        int64_t min_qty;                                   // 申报下限  
        int64_t max_qty;                                   // 申报上限  
        bool spec_kind;                                        // 特殊控制产品，false-无特殊控制 true-有特殊控
        bool orgctrl_flag;                                     // 机构控制标记，false-无机构控制 true-有机构控
        char512 org_list;                                  // 机构控制列表，存放机构列表，逗号分隔符 
        bool operway_limit;                         // 当期使用委托方式限制标识，false-无限制 true-有限制
    };
    
    // 深圳报价回购委托查询请求
    struct QrySZQuoteRepoOrdersReq {
        char32 secuid;                              // 股东代码，非必传
    };
    // 深圳报价回购委托明细
    struct SZQuoteRepoOrderDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        char32 counter_order_id;                    // 柜台委托号
        char16 order_group;                         // 委托批号  
        char16 contract_id;                         // 合同序号  
        int32_t order_date;                         // 委托日期，格式为YYYYMMDD 
        int64_t oper_time;                          // 委托时间，格式为HHMMSSmmm，首位为0不显示
        char32 secuid;                              // 股东代码  
        char32 symbol;                              // 标的代码，格式为市场.证券ID
        char32 stk_name;                            // 证券名称  
        int16_t order_side;                         // 买卖标识，参考OrderSide定义  
        int64_t order_price;                        // 到期利率，扩大一万倍，单位%
        int64_t order_qty;                          // 委托数量  
        int64_t match_qty;                          // 成交数量  
        Amt_t match_amt;                            // 成交金额  
        int16_t order_status;                       // 委托状态，参考OrderStatus定义
        Amt_t order_frz_amt;                        // 冻结金额  
        Amt_t clear_amt;                            // 清算金额  
        char operway;                               // 委托方式，参考OperWay定义
        char16 prod_code;                           // 产品编码 6位的证券代码+3位购回天数+3位期号
        char128 prod_name;                          // 产品名称  
        int64_t cancel_qty;                         // 撤单数量  
        int16_t cancel_flag;                        // 撤单标志 参考CancelFlag定义 
        char16 net_addr;                            // MAC地址  
        char16 seat;                                // 交易席位  
        char16 agent_id;                            // 代理人      
    };

    // 上海报价回购委托请求
    struct SHQuoteRepoOrderReq {
        char32 symbol;              // 交易标的，格式为市场.证券代码
        int16_t side;               // 买卖方向，参考OrderSide定义，报价回购，报价续做
        Ratio_t price;              // 到期利率，扩大一万倍
        int64_t volume;             // 委托数量，股票(单位:股)，债券(上海:手，深圳:张)
        char autoflag;              // 自动续作，报价回购是否自动续作，0续作原期限，1不续作，2续作1天期
        Ratio_t interprice;         // 提前终止利率，扩大一万倍
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    };

    // 上海报价回购委托应答
    struct SHQuoteRepoOrderRsp {
        char16 account_id;          // 交易账号，目前是资金账号
        int16_t account_type;       // 交易账号类型，参考AccountType定义
        char8 cust_orgid;           // 机构编码
        char8 cust_branchid;        // 分支编码
        char32 order_id;            // 柜台订单id
        char32 contract_id;         // 委托合同号，仅集中交易和低延时柜台支持应答中返回
        char32 order_group;		    // 委托批号
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期
    };

    // 上海报价回购不再续做请求
    struct SHQuoteRepoNoContinueReq {
        int32_t order_date;         // 委托日期，格式为YYYYMMDD
        char32 sno;                 // 流水号
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    };

    // 上海报价回购不再续做应答
    struct SHQuoteRepoNoContinueRsp {
        char16 account_id;          // 交易账号，目前是资金账号
        int16_t account_type;       // 交易账号类型，参考AccountType定义
        char8 cust_orgid;           // 机构编码
        char8 cust_branchid;        // 分支编码
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期
    };
    
    // 上海报价回购提前购回委托请求
    struct SHQuoteRepoEarlyRepurchaseOrderReq {
        int32_t order_date;         // 委托日期，格式为YYYYMMDD
        char32 sno;                 // 流水号
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    };

    // 上海报价回购提前购回委托应答
    struct SHQuoteRepoEarlyRepurchaseOrderRsp {
        char16 account_id;          // 交易账号，目前是资金账号
        int16_t account_type;       // 交易账号类型，参考AccountType定义
        char8 cust_orgid;           // 机构编码
        char8 cust_branchid;        // 分支编码
        char32 order_id;            // 柜台订单id
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期
    };

    // 上海报价回购提前购回预约请求
    struct SHQuoteRepoEarlyRepurchaseBookReq {
        int32_t order_date;         // 委托日期，格式为YYYYMMDD
        char32 sno;                 // 流水号
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期，格式为YYYYMMDD，原样返回，非必传
    };

    // 上海报价回购提前购回预约应答
    struct SHQuoteRepoEarlyRepurchaseBookRsp {
        char16 account_id;          // 交易账号，目前是资金账号
        int16_t account_type;       // 交易账号类型，参考AccountType定义
        char8 cust_orgid;           // 机构编码
        char8 cust_branchid;        // 分支编码
        char32 cl_order_id;         // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
        int32_t cl_order_date;      // 客户端订单日期
    };

    // 上海报价回购合约查询请求
    struct QrySHQuoteRepoContractReq {
        int16_t status;                             // 合约状态，参考SHQuoteRepoStatus定义，非必传
    };
    // 上海报价回购合约明细
    struct SHQuoteRepoContractDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        int32_t order_date;                         // 委托日期，格式为YYYYMMDD 
        char16 sno;                                 // 流水号  
        int16_t order_side;                         // 买卖标识，参考OrderSide定义  
        int64_t due_price;                          // 到期利率，扩大一万倍，单位%
        int64_t inter_price;                        // 提前终止利率，扩大一万倍，单位%
        bool inter_bsflag;                          // 提前终止标志 false 未被提前终止 true 已被提前终止
        Amt_t match_amt;                            // 成交金额
        int64_t match_qty;                          // 成交数量
        int64_t gh_days;                            // 购回天数
        char32 match_code;                          // 成交编号  
        int16_t lastyy_status;                      // 上日预约状态，参考QuoteRepoBookStatus定义
        int32_t match_date;                         // 预计到期日期，格式为YYYYMMDD 
        char16 stk_code;                            // 证券代码
        char32 stk_name;                            // 证券名称
        char32 secuid;                              // 股东代码
        bool auto_flag;                             // 自动续约标志 false 不自动续约, true 自动续约
        int32_t first_date;                         // 初始日期，格式为YYYYMMDD 
    };
    
    // 上海报价回购业务查询请求
    struct QrySHQuoteRepoBusinessReq {
    };
    // 上海报价回购业务明细
    struct SHQuoteRepoBusinessDetail {
        char16 account_id;                          // 交易账号，目前是资金账号
        char8 cust_orgid;                           // 机构编码
        char8 cust_branchid;                        // 分支编码
        int16_t account_type;                       // 交易账号类型，参考AccountType定义
        int32_t order_date;                         // 委托日期，格式为YYYYMMDD  
        char32 counter_order_id;                    // 柜台委托号
        char16 cust_id;                             // 客户代码  
        char32 cust_name;                           // 客户姓名  
        int16_t currency_type;                      // 货币类型，参考CurrencyType定义
        char32 secuid;                              // 股东代码  
        int16_t order_side;                         // 买卖标识，参考OrderSide定义  
        char32 contract_id;                         // 申报合同序号  
        int64_t report_time;                        // 报盘时间，格式为HHMMSSmmm，首位为0不显示  
        char32 symbol;                              // 标的代码，格式为市场.证券ID
        char32 stk_name;                            // 证券名称 
        int64_t order_price;                        // 年收益率 扩大一万倍，单位% 
        int64_t bond_intr;                          // 提前购回年收益率 扩大一万倍，单位% 
        int64_t order_qty;                          // 委托数量  
        int64_t oper_time;                          // 操作时间，格式为HHMMSSmmm，首位为0不显示
        Amt_t order_frz_amt;                        // 冻结金额
        int64_t match_qty;                          // 成交数量
        Amt_t match_amt;                            // 成交金额
        int64_t cancel_qty;                         // 撤单数量
        int32_t order_status;                       // 委托状态，参考OrderStatus定义
        char16 seat;                                // 交易席位
        int16_t cancel_flag;                        // 撤单标志 参考CancelFlag定义 
        char16 net_addr;                            // MAC地址 
        Price_t match_price;                        // 成交价格  
        int32_t oper_date;                          // 操作日期，格式为YYYYMMDD
        char operway;                               // 委托方式
        Amt_t fund_avl;                             // 资金可用
        char64 remark;                              // 备注  
        int32_t credit_type;                        // 信用交易类型
        char16 credit_digestid;                     // 信用交易摘要
        char16 prod_code;                           // 产品编码
        char128 prod_name;                          // 产品名称
        Amt_t clear_amt;                            // 清算金额
    };

    // 股转发行证券信息查询请求
    struct QueryNEEQIPOStockReq {
        char8 stk_code;                 // 证券代码，非必传
        char sub_pur_stat;              // 认申购状态 非必传，参考SubscribePurchaseStatus定义
        int32_t order_date;             // 委托日期，格式为YYYYMMDD
        char32 pos_str;                 // 定位串，填""表示第一次从头开始查
        int32_t query_num;              // 查询数量
        char32 secuid;                  // 股东代码，非必传，默认由系统自动获取。
                                        // 用户可根据返回的北交所股东代码按需填写
    };

    // 股转发行证券信息详情
    struct NEEQIPOStockDetail {
        char16 account_id;              // 交易账号，目前是资金账号
        int16_t account_type;           // 交易账号类型，参考AccountType定义
        char8 cust_orgid;               // 机构编码
        char8 cust_branchid;            // 分支编码
        char32 symbol;                  // 标的代码，格式为市场.证券ID
        char16 underlying_code;         // 正股代码  
        int32_t sub_start_date;         // 认购起始日期，格式为YYYYMMDD
        int32_t sub_end_date;           // 认购结束日期，格式为YYYYMMDD
        int64_t sub_min_qty;            // 最小询价数量  
        int64_t sub_max_qty;            // 最大询价数量  
        Price_t sub_min_price;          // 认购下限价格  
        Price_t sub_max_price;          // 认购上限价格  
        int64_t sub_pur_unit;           // 认申购单元  
        int32_t pur_date;               // 申购日期，格式为YYYYMMDD
        int64_t pur_min_qty;            // 最小申购数量  
        int64_t pur_max_qty;            // 最大申购数量  
        Price_t pur_min_price;          // 申购下限价格  
        Price_t pur_max_price;          // 申购上限价格  
        int64_t issued_total_qty;       // 总发行量  
        char32 stk_name;                // 证券简称  
        char sub_pur_stat;              // 认申购状态，参考SubscribePurchaseStatus定义
        int32_t update_date;            // 更新日期，格式为YYYYMMDD
        int64_t sub_confirm_min_qty;    // 询价确认最小申购数量  
        int64_t sub_confirm_max_qty;    // 询价确认最大申购数量  
        int16_t sub_confirm_result;     // 询价确认结果，参考SubscribeResult定义
        int16_t sub_order_status;       // 委托状态，参考SubPurOrderStatus定义
        int16_t neeq_issue_type;        // 新三板发行方式，参考NEEQIssueType定义
    };
 

}  // namespace HFT

#endif  // _HFT_EXT_TRADER_STRUCT_H_

