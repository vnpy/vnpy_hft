/**
 * @file    hft_trader_struct.h
 * @brief   交易业务数据和结构定义
 */

#ifndef _HFT_TRADER_STRUCT_H_
#define _HFT_TRADER_STRUCT_H_

#include "hft_trader_common.h"
#include "hft_trader_def.h"

namespace HFT {

// 金额类型，扩大一万倍
typedef int64_t Amt_t;

// 价格类型，扩大一万倍
typedef int64_t Price_t;

// 比例类型，扩大一万倍
typedef int64_t Ratio_t;

// 百分比类型，扩大一百倍
typedef int32_t Percent_t;

// 汇率类型，扩大一亿倍
typedef int64_t ExchangeRatio_t;


// 风控告警消息类型
struct RiskNotify {
    char16 secuid;        // 证券账户(股东代码)
    char32 alarm_score;   // 告警指数值
    char32 alarm_status;  // 告警状态
    char32 alarm_rule;    // 告警规则名称
    char32 alarm_time;    // 告警时间
    char256 alarm_msg;    // 告警内容详情
};

// 回切通知信息
struct FailBackNotify {
	char8 system_id;            // 系统编号
	char8 node_id;              // 节点编号
	char status;                // 节点状态，'0'-未启用，'1'-未回切，'2'-已回切
	char credit_node_flag;      // 信用节点标识，'0'-普通节点，'1'-信用节点
	char urgent_flag;           // 应急回切标志，'0'-常规回切，即夜市委托回切，'1'-应急回切
	char16 update_source;       // 更新来源，定时查询、手动修改、Kafka推送通知等
};

// 交易账户相关信息
struct AccountInfo {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char16 account_pwd;    // 交易账号密码
    char8 cust_orgid;      // 交易账号的机构编码
    char8 cust_branchid;   // 交易账号的分支编码
    char40 cl_system_id;   // 接入方系统标识，由服务端分配
};

// 登录请求相关信息
struct LoginReq {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char16 account_pwd;     // 交易账号密码
    char8 cust_orgid;       // 交易账号的机构编码
    char8 cust_branchid;    // 交易账号的分支编码
    char40 cl_system_id;    // 接入方系统标识，由服务端分配
    char32 svr_ip;          // 交易服务器ip地址
    int svr_port;           // 交易服务器端口
    char256 terminal_info;  // 交易终端信息，格式需满足交易所要求，格式请见接口说明文档
                            // windows平台GBK编码, Linux平台UTF8编码 
    int16_t inner_flag;     // 内部调用标志，参考 InnerCallFlag 定义，非必传，默认非内部调用   
};

// 资金账号对应的股东账号信息
struct SecuidInfo {
    char8 market;				// 市场，SH、SZ等，参考本文件中定义
    char16 secuid;				// 证券账户(股东代码)
	char32 fund_id;				// 资金账号
	int16_t account_type;       // 证券账户(股东代码)类型，参考AccountType定义
	char account_status;		// 证券账户(股东代码)状态，参考AccountStatus定义
	char account_class;         // 股东代码类别，参考AccountClass定义
	char64 account_rights;      // 股东代码权限集，单个权限参考AccountRightType定义
	char account_hgtright;      // 沪港通权限，参考SHHKAccountRight定义
};

// 登录应答数据
struct LoginRsp {
    char16 account_id;                  // 交易账号，目前是资金账号
    int16_t account_type;               // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                   // 交易账号的机构编码
    char8 cust_branchid;                // 交易账号的分支编码
    char16 cust_id;                     // 客户号
    char128 cust_name;                  // 客户姓名
    SecuidInfo secuid_array[10];        // 股东代码列表,上海A,深圳A,沪港通,深港通,股转
    char32 cif_account;                 // 一户通账号，微服务使用
    char32 user_code;                   // 用户代码，微服务使用
    char256 user_token;                 // 会话令牌，微服务使用
    char256 token_serial_no;            // 协议流水号，微服务使用
    char64 sm3_cipher;                  // SM3密文密码，微服务使用
    int sys_node_type;                  // 系统节点类型，微服务使用
    char clear_switch_flag;             // 清算切换标志，微服务使用，'0'-未切换；'1'-已切换
    char trade_switch_flag;             // 交易切换标志，微服务使用，'0'-未切换；'1'-已切换
    char8 sys_server_id;                // 系统服务器编号，微服务使用
    char operway;                       // 操作渠道，微服务使用
    int16_t sys_shbond_type;            // 上海债券数量单位标识，0-手，1-张
    SecuidInfo ext_secuid_array[10];    // 扩展的同客户号下其他股东账户信息
    char8 reg_branchid;                 // 系统登记的用户分支机构
};

// 下单的请求类型
// LOF 申购请求, volume 代表申购金额，扩大1w
// LOF 赎回请求, volume 代表赎回份额
// 关于单位：上海实时申赎LOF货币基金（5198XX）做特殊处理，将交易所原始的0.01元份额单位改为一元份额单位
struct OrderReq {
    char32 cl_order_id;			// 客户端订单id，用来引用一个普通订单，由用户自定义，不支持中文字符和不可见字符，可不传
    char32 symbol;				// 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
    int16_t order_type;			// 订单类型，参考OrderType定义，新股申购填限价
    int16_t side;				// 买卖方向，参考OrderSide定义
    int64_t volume;				// 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
    Price_t price;				// 订单委托价，限价单使用，扩大一万倍，默认币种为人民币，港股通时币种为港币
								// 市价及ETF申购、赎回，LOF申购、赎回此字段无意义，填写0
    int16_t order_flag;			// 委托属性，仅股票期权账号使用，参考OrderFlag定义
    uint16_t policy_id;			// 策略编号，仅支持低延时96/98,集中交易,顶点hts现货柜台
	int16_t share_property;		// 股份性质, 参考ContractBuyBackShareProperty定义，非必传，
								// 低延时V2柜台 债券转股回售业务用到，默认按ContractBuyBackShareProperty_1处理
};

// 下单的应答类型
struct OrderRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int32_t order_date;    // 柜台委托日期(夜市委托则返回下一个交易日)
    char32 order_id;       // 柜台订单id
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    char32 contract_id;    // 委托合同号，仅集中交易和君睿柜台支持应答中返回
    char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
};

// 撤单的请求类型
struct CancelReq {
    char32 order_id;        // 被撤的原订单id
    char32 cl_order_id;     // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
    char32 cl_cancel_id;    // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传

    // 以下字段是君睿低延时柜台需要传入原订单相关信息
    char32 symbol;          // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
    int16_t order_type;     // 订单类型，参考OrderType定义，新股申购填限价
    int16_t side;           // 买卖方向，参考OrderSide定义
    int64_t volume;         // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
    Price_t price;          // 订单委托价，限价单使用，扩大一万倍
};

// 一键撤单请求
struct BatchCancelAllReq {
    char16 cust_id;       // 客户号
    char32 secu_id;       // 股东号
    char32 symbol;        // 交易标的，格式为市场.证券ID或市场.合约ID，例如SH.600000或SHOP.10002003
    int32_t market;       // 市场，参考MarketType定义
};

// 撤单的应答类型
struct CancelRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 order_id;       // 被撤的柜台原订单id
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    char32 cl_cancel_id;   // 客户端撤单id，用来引用一个撤单订单，由用户自定义，原样返回
    char32 cancel_id;      // 柜台撤单订单id，集中交易柜台不支持
    char32 ex_order_id;    // 交易所订单id，仅君睿柜台支持
};

// 根据委托号查询请求
struct QryByOrderIdReq {
    char32 order_id;      // 柜台订单id
    char8 market;         // 市场，港股通需要填，深港通传SZHK，沪港通传SHHK，默认设置为空
						  // 顶点普通账号,低延时非一户两地账号不支持此字段入参。
};

// 根据标的代码查询请求
struct QryByCodeReq {
    char32 symbol;        // 标的代码，例如SH.600000，必填
};

// 根据标的代码查询委托列表请求
struct QryOrderByCodeReq {
    char32 symbol;        // 标的代码，例如SH.600000，必填
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// 查询当日订单列表请求
struct QryOrdersReq {
	char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;		// 查询的数量，最大支持500个
	int query_flag;			// 目前支持0表示查全部，默认设置为0，1-表示查可撤单委托，即可以发起撤单请求的普通委托
						    // 2-表示查普通委托，即不是撤单委托的普通委托，参考OrderQueryFlag定义
	char8 market;			// 市场，港股通需要填，深港通传SZHK，沪港通传SHHK，默认设置为空
};

// 订单明细数据
struct OrderDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 order_id;        // 柜台订单id，对于撤单是柜台撤单id
    char32 cl_order_id;     // 客户端订单id，对应到客户端的原订单id
    char32 orig_order_id;   // 仅撤单订单使用，是被撤的原订单id
    char32 symbol;          // 交易标的，格式为市场.证券ID或市场.合约ID
    int16_t order_status;   // 订单状态，参考OrderStatus定义
    int16_t order_type;     // 订单类型，参考OrderType定义
    int16_t side;           // 买卖方向，参考OrderSide定义
    int64_t volume;         // 订单数量，股票单位（股），债券单位（上海：手，深圳：张），可按需后台配置上海债券的单位
    Price_t price;          // 订单委托价，扩大一万倍，默认币种为人民币，港股通时币种为港币
    int64_t filled_volume;  // 订单累计已完成数量，查询有值，委托推送没有值（君睿和顶点股票有）
    Amt_t filled_turnover;  // 订单累计已完成金额，扩大一万倍，查询有值，委托推送没有值
    Price_t filled_price;   // 成交均价，扩大一万倍，查询有值，委托推送没有值（君睿和顶点股票有）
    int64_t cancel_volume;  // 撤单数量
    int16_t cancel_flag;    // 撤单标识，参考CancelFlag定义
    int32_t order_date;     // 订单日期，格式为YYYYMMDD
    int32_t order_time;     // 订单时间，格式为HHMMSSmmm，对于订单状态推送，是推送时间点
    int32_t err_code;       // 下单失败时的错误码
    char256 err_msg;        // 下单失败时的错误消息，Windows是GBK，Linux是UTF8
    char16 secuid;          // 证券账户(股东代码)
    char32 name;            // 证券名称 订单查询和委托推送共用结构体，此字段推送不需要，查询需要
    Amt_t freeze_amount;    // 冻结金额 订单查询和委托推送共用结构体，此字段推送不需要，查询需要
    char32 contract_id;     // 委托合同号
    char32 ex_order_id;     // 交易所订单id，仅君睿柜台支持
};


// 根据标的代码查询成交列表请求
struct QryTradeByCodeReq {
    char32 symbol;        // 标的代码，例如SH.600000，必填
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// 查询当日成交列表请求
struct QryTradesReq {
    char32 pos_str;				// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;			// 查询的数量，最大支持500个
    char8 market;				// 市场，默认是查上海和深圳市场的成交，查询港股通成交需传HK，
                                // 深港通传SZHK，沪港通传SHHK，传SH或SZ是查上海或深圳的成交，大小写不敏感
    bool filter_etf;			// 查询成交列表可控制是否过滤掉ETF申赎成交，仅君睿柜台需要此字段，
                                // 默认为false不过滤
    char32 counter_order_id;    // 柜台委托号，非必传
};

// 查询当日ETF申赎及成分股成交列表请求
struct QryETFTradesReq {
    char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;				// 查询的数量，最大支持500个
    char8 market;					// 市场，港股通需要填，深港通传SZHK，沪港通传SHHK，默认设置为空
    char32 counter_order_id;        // 柜台委托号，非必传
    char qry_direct;                // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义，默认倒序
};

// 成交明细数据
struct TradeDetail {
    char16 account_id;              // 交易账号，目前是资金账号
    int16_t account_type;           // 交易账号类型，参考AccountType定义
    char8 cust_orgid;               // 机构编码
    char8 cust_branchid;            // 分支编码
    char32 order_id;                // 柜台订单id，对于撤单是柜台原订单id
    char32 cl_order_id;             // 客户端订单id，对应到客户端的原订单id
    char32 symbol;                  // 交易标的，格式为市场.证券ID或市场.合约ID
    int16_t order_type;             // 订单类型，参考OrderType定义
    int16_t side;                   // 买卖方向，参考OrderSide定义
    int16_t report_type;            // 成交回报类型，参考TradeReportType定义
    char32 report_no;               // 成交编号
    int64_t volume;                 // 成交数量，当report_type不是TradeReportType_Normal时代表撤单或废单数量
    Price_t price;                  // 成交价格，扩大一万倍，默认币种为人民币，港股通时币种为港币
    Amt_t turnover;                 // 成交金额，扩大一万倍
    int32_t trade_date;             // 成交日期，格式为YYYYMMDD
    int32_t trade_time;             // 成交时间，格式为HHMMSSmmm
    int32_t err_code;               // 下单失败时的错误码
    char256 err_msg;                // 下单失败时的错误消息，Windows是GBK，Linux是UTF8
    char16 secuid;                  // 证券账户(股东代码)
    char32 name;                    // 证券名称
    char32 contract_id;             // 委托合同号
    char32 ex_report_no;            // ETF申赎的交易所成交编号，仅君睿柜台QueryETFTrades接口返回有效数据
    char32 ex_order_id;             // 交易所订单id，仅君睿柜台支持
    int16_t margin_amt_type;        // 上交所现金替代资金类型，参考FundResourcesType定义
    Price_t order_price;            // 委托价格，扩大一万倍，默认币种为人民币，港股通时币种为港币
                                    // 目前仅支持低延时，集中交易查询成交场景
    int64_t order_qty;              // 委托数量，目前仅支持低延时，集中交易查询成交场景
};

// 查询当日账户持仓列表请求
struct QryPositionsReq {
    char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;		// 查询的数量，最大支持500个
    char8 market;			// 市场，港股通需要填，深港通传SZHK，沪港通传SHHK，默认设置为空
};

// 仓位明细数据
struct PositionDetail {
    char16 account_id;              // 交易账号，目前是资金账号
    int16_t account_type;           // 交易账号类型，参考AccountType定义
    char8 cust_orgid;               // 机构编码
    char8 cust_branchid;            // 分支编码
    char32 symbol;                  // 持仓标的，格式为市场.证券ID或市场.合约ID
    int16_t side;                   // 持仓方向，参考PositionSide定义
    int64_t volume;                 // 总持仓量
    int64_t avail_volume;           // 可用持仓量
    int64_t init_volume;            // 日初持仓量
    Amt_t market_value;             // 仓位市值，扩大一万倍
    int64_t today_buy_volume;       // 今日买入成交数量，仅顶点柜台有效
    int64_t today_sell_volume;      // 今日卖出成交数量，仅顶点柜台有效
    char16 secuid;                  // 证券账户(股东代码)
    Price_t cost_price;             // 买入成本价，扩大一万倍
    Amt_t buy_cost;                 // 买入成本，扩大一万倍
    Price_t last_price;             // 最新价，扩大一万倍
    Amt_t income;                   // 浮动盈亏，扩大一万倍
    Amt_t total_income;             // 累计盈亏，扩大一万倍
    Amt_t profit_cost;              // 盈亏成本，扩大一万倍
    int64_t today_avail_pr_volume;  // 可申赎数量，仅君睿柜台
    int32_t market;                 // 市场，参考MarketType定义
    int32_t security_type;          // 证券类别，参考SecurityTypeDetail定义，仅君睿柜台
    int64_t freeze_volume;          // 冻结数量，仅顶点柜台有效
    char32 name;                    // 证券名称
    int32_t currency_type;          // 货币代码，参考CurrencyType定义
    int32_t security_type_apex;     // 证券类型，参考SecurityTypeAPEX定义，仅支持顶点柜台
    Price_t profit_price;           // 盈亏成本价，扩大一万倍，仅支持集中、低延时两融柜台
};

// 查资金请求
struct QryCashReq {
    char8 market;         // 市场，君睿柜台一户两地时使用，查对应市场的资金
                          // 传SH或SZ是查上海或深圳的资金，大小写不敏感，默认设置为空查两地汇总数据
};

// 资金明细数据
struct CashDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    Amt_t total_amount;     // 总资金量，扩大一万倍
    Amt_t avail_amount;     // 可用资金，扩大一万倍
    Amt_t total_asset;      // 总资产，扩大一万倍
    Amt_t market_value;     // 证券市值，扩大一万倍
    Amt_t init_amount;      // 日初资金，扩大一万倍，目前支持集中交易，低延时柜台
							// 注意一户两地账号查询单个市场时，此字段值是不区分市场，是资金账户层级的。
    Amt_t fetch_balance;    // 可取资金，扩大一万倍，目前支持集中交易，低延时柜台
};

// 集中交易可用资金
struct JZJYAvailFundDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    Amt_t avail_amount;    // 可用资金，扩大一万倍
};

// 资金划转请求
struct TransferFundReq {
    int transfer_side;     // 划转方向，请参考TransferFundSide
    Amt_t transfer_value;  // 划转金额，扩大一万倍，币种人民币
    char8 market;          // 市场，君睿柜台一户两地时使用，
                           // 传SH或SZ是集中柜台与快速柜台上海或深圳之间资金转入转出，大小写不敏感
                           // 默认设置为空
};

// 资金划转应答
struct TransferFundRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    Amt_t transfer_value;  // 实际划转金额，扩大一万倍，币种人民币
};

// 一户两地之间资金划转请求，仅君睿柜台支持
struct TransferFundSecuidReq {
    char8 fund_out_market;  // 资金转出的市场，传SH或SZ
    char8 fund_in_market;   // 资金转入的市场，传SH或SZ
    Amt_t transfer_value;   // 划转金额，扩大一万倍，币种人民币
};

// 一户两地之间资金划转应答，仅君睿柜台支持
struct TransferFundSecuidRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    Amt_t transfer_value;  // 实际划转金额，扩大一万倍，币种人民币
};

// ETF基本信息查询请求
struct QryETFsReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// ETF基本信息明细
struct ETFDetail {
    char16 account_id;       // 交易账号，目前是资金账号
    int16_t account_type;    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;        // 机构编码
    char8 cust_branchid;     // 分支编码
    char32 name;             // ETF名称
    char32 first_symbol;     // 一级市场代码，格式为市场.证券ID或市场.合约ID
    char32 second_symbol;    // 二级市场代码，格式为市场.证券ID或市场.合约ID
    int32_t trade_unit;      // 最小申赎份额
    Amt_t cash_component;    // 预估现金差额，扩大一万倍
    Ratio_t max_cash_ratio;  // 最大现金替代比例，扩大一万倍
    int32_t trade_state;     // 交易所申购赎回允许状态，参考ETFTradeState定义
    int32_t record_num;      // 股票篮子记录数
    int32_t trade_day;       // T日日期
    int32_t pre_trade_day;   // T-1日日期
    Amt_t nav_percu;         // T-1日申赎基准单位净值，扩大一万倍
    Amt_t nav;               // T-1日基金单位净值，扩大一万倍

    // 以下字段仅深圳ETF有效,为0表示没有限制
    int64_t creation_limituser;        // 单帐户当天累计可申购的基金份额上限
    int64_t redemption_limituser;      // 单帐户当天累计可赎回的基金份额上限
    int64_t net_creation_limituser;    // 单账户当天净申购的基金份额上限
    int64_t net_redemption_limituser;  // 单账户当天净赎回的基金份额上限
    int64_t creation_limit;            // 当天累计可申购的基金份额上限
    int64_t redemption_limit;          // 当天累计可赎回的基金份额上限
    int64_t net_creation_limit;        // 当天净申购的基金份额上限
    int64_t net_redemption_limit;      // 当天净赎回的基金份额上限
	int32_t etf_type;				   // 公司ETF分类，定义见ETFType

	Amt_t cash_component_t1;           //  T-1日现金差额，扩大一万倍
    int32_t internal_trade_state;      // 公司申购赎回允许状态，参考ETFTradeState定义
};

// ETF股票篮子信息查询请求
struct QryETFStocksReq {
	char32 first_symbol;  // ETF的一级市场代码，格式为市场.证券ID或市场.合约ID
	int sz_ksc_type;	  // 针对深圳跨市场ETF。传0查场外申赎信息，传1查场内申赎信息，低延时柜台此字段无效
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// ETF股票篮子明细
struct ETFStockDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    char32 first_symbol;      // ETF一级市场代码，格式为市场.证券ID或市场.合约ID
    char32 name;              // 证券名称
    char32 symbol;            // 证券代码，格式为市场.证券ID或市场.合约ID
    int32_t volume;           // 股份数量
    int16_t replace_flag;     // 现金替代标识，参考ETFReplaceFlag定义
    Ratio_t over_price_rate;  // 溢价比例，扩大一万倍
    Amt_t replace_amt;        // 现金替代金额，扩大一万倍
};

// 最大可委托数查询请求
struct QryMaxOrderQtyReq {
    char32 symbol;        // 交易标的，格式为市场.证券ID或市场.合约ID
    int16_t order_type;   // 订单类型，参考OrderType定义
    int16_t side;         // 买卖方向，参考OrderSide定义
    Price_t price;        // 订单委托价，限价单使用，扩大一万倍，市价填写0
};

// 最大可委托数量数据
struct MaxOrderQtyDetail {
    char16 account_id;       // 交易账号，目前是资金账号
    int16_t account_type;    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;        // 机构编码
    char8 cust_branchid;     // 分支编码
    int64_t max_qty;         // 最大可委托数量，最大限制100万
    int64_t actual_max_qty;  // 实际最大可委托数量，可能超过100万
    Amt_t max_pay_amt;       // 应偿还资金负债，仅君睿两融柜台支持
    int64_t max_pay_qty;     // 买券还券应补数量，仅君睿两融柜台支持
    int64_t sep_rem_qty;     // 专户余券，仅君睿两融柜台支持
};

// 新股可申购额度数据
struct IPOMaxPurchaseDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char8 market;          // 市场，SH、SZ等，参考本文件中定义
    int64_t max_qty;       // 申购额度
    int64_t stib_max_qty;  // 科创板申购额度
	char32 secuid;		   // 证券账户(股东代码)
};

// 查询新股新债请求
struct QueryIPOStockReq {
	int16_t query_flag;   // 查询标志，1：查询新股，2：查询新债，定义请参考IPOQueryFlag，必填
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// 新股数据
struct IPOStockDetail {
	char16 account_id;      // 交易账号，目前是资金账号
	int16_t account_type;   // 交易账号类型，参考AccountType定义
	char8 cust_orgid;       // 机构编码
	char8 cust_branchid;    // 分支编码
    char32 symbol;          // 格式为市场.证券ID或市场.合约ID
    char32 name;            // 证券名称
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    Price_t ipo_price;      // 发行价，扩大一万倍
    int64_t max_num;        // 最高交易数量
    int64_t min_num;        // 最低交易数量
    int32_t security_type;  // 证券类型，参考SecurityTypeDetail定义，仅君睿柜台支持
};

// 证券基本信息查询数据
struct SecurityBaseInfo {
    char32 symbol;						// 格式为市场.证券ID或市场.合约ID
    char32 name;						// 证券名称
    int32_t security_type;				// 证券类型，参考SecurityTypeDetail定义
    int32_t security_status;			// 证券状态，参考SecurityStatus定义
    Price_t price_tick;					// 证券价位，扩大一万倍
    Price_t limit_up;					// 涨停价格，扩大一万倍
    Price_t limit_down;					// 跌停价格，扩大一万倍
    int64_t max_qty;					// 最大数量
    int64_t min_qty;					// 最小数量
    Price_t buy_tick;					// 买入最小单位，扩大一万倍
    Price_t sale_tick;					// 卖出最小单位，扩大一万倍
    int32_t has_price_limit;			// 是否有涨幅控制1=True/Yes,0=False/No
    Percent_t limit_up_rate;			// 最大涨幅，扩大100倍
    int32_t is_registration;			// 是否注册制1=True/Yes,0=False/No
    Percent_t limit_down_rate;			// 最大跌幅，扩大100倍
	char trade_id;                      // 可交易类型，参考TradableType定义，目前仅集中交易，低延时V2柜台支持
};

// 根据市场查询请求
struct QryByMarketReq {
	char8 market;         // 市场，SH、SZ、SZHK、SHHK等，大小写不敏感
};

// 沪港通参考汇率数据
struct HKRateDetail {
    char8 market;				// 市场，SH、SZ等，参考本文件中定义
	ExchangeRatio_t buy_rate;   // 买入参考汇率，扩大一亿倍
	ExchangeRatio_t sale_rate;  // 卖出参考汇率，扩大一亿倍
	ExchangeRatio_t mid_rate;   // 中间参考汇率，扩大一亿倍
	ExchangeRatio_t set_rate;   // 结算汇率，扩大一亿倍
    int32_t sys_date;			// 更新日期
};

// 沪港通标的券数据
struct QryHKStock {
	char8 market;			// 市场，SH、SZ、SZHK、SHHK等，大小写不敏感
	char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;		// 查询的数量，最大支持500个
};

// 沪港通标的券数据
struct HKStockDetail {
    char32 symbol;          // 格式为市场.证券ID或市场.合约ID
    char32 name;            // 证券名称
	int16_t stktype;        // 证券类型，集中交易柜台账户有值，参考StkType定义
	int16_t currency_type;  // 货币类型，参考CurrencyType定义
	int32_t security_type;  // 证券种类，低延时柜台账户有值，参考SecurityTypeDetail定义
};

//  沪港通辅资金表资产数据
struct HKFundDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    Amt_t fund_uncomeavl;   // 港股在途可用资金，扩大一万倍
    Amt_t fund_buy;         // 港股资金买入冻结，扩大一万倍
    Amt_t fund_sale;        // 港股资金卖出解冻，扩大一万倍
    Amt_t fund_uncomebuy;   // 港股资金在途买入，扩大一万倍
    Amt_t fund_uncomesale;  // 港股资金在途卖出，扩大一万倍
};

// 查询沪港通最小价差
struct QryHKMinPriceUnitReq {
	char32 market;        // 交易市场，深港通传SZHK，沪港通传SHHK
	char16 code;          // 合约ID，非必传
	int64_t price;		  // 价格，非必传，合约ID传时必传
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个，注意集中交易柜台不支持分页。
};

// 沪港通最小价差数据
struct HKMinPriceUnitDetail {
	char16 account_id;     // 交易账号，目前是资金账号
	int16_t account_type;  // 交易账号类型，参考AccountType定义
	char8 cust_orgid;      // 机构编码
	char8 cust_branchid;   // 分支编码

    int16_t stktype;      // 证券类型，参考StkType定义
    Price_t begin_price;  // 区间起始价格，扩大一万倍
    Price_t end_price;    // 区间终止价格，扩大一万倍
    int32_t price_unit;   // 区间最小价格单位，数值的单位为厘即1/1000元
};

// 根据开始和结束日志的查询请求
struct QryByDateReq {
	int start_date;       // 开始日期，格式为YYYYMMDD，如20190415
	int end_date;         // 结束日期，格式为YYYYMMDD，如20190418
};

// 沪港通交易日历数据
struct HKTradeCalendarDetail {
    int32_t date;           // 日期
    int16_t business_flag;  // 交易日标识，0表示交易日，1表示非交易日
    int16_t commit_flag;    // 交收日标识，0表示交收日，1表示非交收日
};

// 担保品转入转出请求类型
struct CreditMortgageInOutReq {
    char32 cl_order_id;  // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 symbol;       // 交易标的，格式为市场.证券ID或市场.合约ID
    int16_t side;        // 买卖方向，参考OrderSide定义，
                         // 担保品转入传OrderSide_Margin_MortgageIn，
                         // 担保品转出传OrderSide_Margin_MortgageOut
    int32_t volume;      // 担保品划转数量
    char32 opp_fund_id;  // 对方资金账号，同客户号下的要转入或转出的对方资金账号，普通和信用互为对方，可不填
    char32 opp_secu_id;  // 对方股东代码，同客户号下的要转入或转出的对方股东代码，普通和信用互为对方，可不填
};

// 担保品转入转出应答类型
struct CreditMortgageInOutRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 cl_order_id;    // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;       // 柜台订单id
    char32 contract_id;    // 申报合同号，目前低延时两融支持，顶点两融柜台需求评估开发中。
};

// 现券还券请求类型
struct CreditStockBackReq {
    char32 cl_order_id;  // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 symbol;       // 交易标的，格式为市场.证券ID或市场.合约ID
    int32_t volume;      // 还券数量
};

// 现券还券应答类型
struct CreditStockBackRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 cl_order_id;    // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;       // 柜台订单id
    char32 contract_id;    // 申报合同号，目前低延时两融支持，顶点两融柜台需求评估开发中。
};

// 直接还款请求
struct CreditPayBackReq {
    Amt_t back_amt;       // 还款金额，扩大一万倍，精度0.01
    char32 cl_order_id;   // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
};

// 指定合约直接还款请求
struct CreditPayBackByOrderReq {
	char64 sno;           // 合约编号
	int order_date;       // 合约委托日期，格式为YYYYMMDD
	Amt_t back_amt;       // 还款金额，扩大一万倍，精度0.01
	char32 cl_order_id;   // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
	int32_t credit_type;  // 信用交易类型，枚举见CreditType，必传
};

// 直接还款应答类型
struct CreditPayBackRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    Amt_t real_back_amt;   // 实际还款金额，扩大一万倍，精度0.01
    char32 cl_order_id;    // 客户端订单id
};

// 查询信用标的券请求
struct QryCreditStockReq {
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个
};

// 信用标的券数据
struct CreditStockDetail {
    char16 account_id;         // 交易账号，目前是资金账号
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    char32 symbol;             // 标的券，格式为市场.证券ID或市场.合约ID
    char32 name;               // 证券名称
    int16_t currency_type;     // 货币类型，参考CurrencyType定义
    char credit_fund_ctrl;     // 融资允许，'0'-允许，'1'-禁止
    char credit_stk_ctrl;      // 融券允许，'0'-允许，'1'-禁止
    Ratio_t margin_rate_fund;  // 融资保证金比例，扩大一万倍
    Ratio_t margin_rate_stk;   // 融券保证金比例，扩大一万倍
    int32_t sep_rem_qty;       // 融券专户余券
};

// 信用资产数据
struct CreditAssetsDetail {
    char16 account_id;                     // 交易账号，目前是资金账号
    int16_t account_type;                  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                      // 机构编码
    char8 cust_branchid;                   // 分支编码
    int16_t currency_type;                 // 货币类型，参考CurrencyType定义
    Amt_t avail_balance;                   // 可用自有资金，即可买担保品资金，扩大一万倍
    Amt_t fetch_balance;                   // 可取资金，扩大一万倍
    Amt_t frozen_balance;                  // 冻结资金，扩大一万倍
    Amt_t stock_balance;                   // 证券市值，扩大一万倍
    Amt_t fund_balance;                    // 总资金，扩大一万倍
    Amt_t asset_balance;                   // 总资产，扩大一万倍
    Amt_t avail_margin;                    // 可用保证金，扩大一万倍
    Amt_t credit_quota;                    // 授信额度，扩大一万倍
    Amt_t finance_quota;                   // 可融资额度，扩大一万倍
    Amt_t shortsell_quota;                 // 可融券额度，扩大一万倍
    Ratio_t assure_ratio;                  // 维持担保比例，扩大一万倍
    Amt_t total_debt;                      // 总负债，扩大一万倍
    Amt_t fund_debt;                       // 融资负债金额，包含融资利息及费用，扩大一万倍
    Amt_t stock_debt;                      // 融券负债金额，包含融券利息及费用，扩大一万倍
    Amt_t fund_interest_fee;               // 融资利息及费用，扩大一万倍
    Amt_t stock_interest_fee;              // 融券利息及费用，扩大一万倍
    Amt_t shortsell_total_balance;         // 融券卖出总资金，扩大一万倍
    Amt_t shortsell_avail_balance;         // 融券卖出可用资金（仅君睿柜台），扩大一万倍
    Amt_t shortsell_frozen_balance;        // 融券卖出冻结资金（仅君睿柜台），扩大一万倍
    Amt_t enbuyback_avail_balance;         // 可买券还券资金，扩大一万倍
    Amt_t fund_margin_profit;              // 融资盈亏，扩大一万倍
    Amt_t stock_margin_profit;             // 融券盈亏，扩大一万倍
    Amt_t fund_interest;                   // 融资利息，扩大一万倍
    Amt_t stock_interest;                  // 融券利息，扩大一万倍
    Amt_t fund_margin_balance;             // 融资市值，扩大一万倍
    Amt_t stock_margin_balance;            // 融券市值，扩大一万倍
    Amt_t fund_floating_deficit;           // 融资浮亏，扩大一万倍
    Amt_t stock_floating_deficit;          // 融券浮亏，扩大一万倍
    Amt_t fund_margin_profit_conversion;   // 融资盈亏折算，扩大一万倍
    Amt_t stock_margin_profit_conversion;  // 融券盈亏折算，扩大一万倍
    Amt_t hbjj_bal;                        // 使用融券卖出资金购买货基的昨日存量（仅君睿柜台），扩大一万倍
};

// 查询信用融资合约请求
struct QryCreditFinanceReq {
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个
};

// 融资合约数据
struct CreditFinanceDetail {
    char16 account_id;         // 交易账号，目前是资金账号
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    char32 symbol;             // 交易标的，格式为市场.证券ID
    char32 name;               // 证券名称
    char32 sno;                // 合约编号
    int16_t currency_type;     // 货币类型
    int16_t life_status;       // 信用合约状态，参考ContractLifeStatus定义
    int32_t occur_date;        // 合约的发生日期
    Amt_t total_balance;       // 合约的总金额，扩大一万倍
    Amt_t cur_balance;         // 合约的当前未偿还金额，扩大一万倍
    Amt_t total_interest_fee;  // 合约的利息及费用总金额，扩大一万倍
    Amt_t cur_interest_fee;    // 合约的当前未偿还利息及费用金额，扩大一万倍
    Ratio_t interest_rate;     // 利率，扩大一万倍
    Amt_t repayable_balance;   // 可还款金额，扩大一万倍，精度0.01
    Amt_t f_deal_bal;          // 期初应付融资款余额，扩大一万倍
    Amt_t f_exp_cet_intr;      // 期初应付负债息费，扩大一万倍
    Amt_t credit_repay_unfrz;  // 当日归还负债金额，扩大一万倍
    Amt_t all_fee_unfrz;       // 当日归还负债息费，扩大一万倍
    int32_t market;            // 市场
    char32 pos_str;            // 定位串
    int32_t end_date;          // 到期日期
};

// 查询信用融券合约请求
struct QryCreditShortsellReq {
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个
};

// 融券合约数据类型
struct CreditShortsellDetail {
    char16 account_id;         // 交易账号，目前是资金账号
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    char32 symbol;             // 交易标的，格式为市场.证券ID
    char32 name;               // 证券名称
    char32 sno;                // 合约编号
    int16_t currency_type;     // 货币类型，参考CurrencyType定义
    int16_t life_status;       // 信用合约状态，参考ContractLifeStatus定义
    int32_t occur_date;        // 合约的发生日期
    int64_t total_qty;         // 合约的融券总数量
    int64_t cur_qty;           // 合约的当前未偿还融券数量
    Amt_t total_interest_fee;  // 合约的利息及费用总金额，扩大一万倍
    Amt_t cur_interest_fee;    // 合约的当前未偿还利息及费用金额，扩大一万倍
    Ratio_t interest_rate;     // 利率，扩大一万倍
    int64_t d_stk_bal;         // 期初应偿还融券总数
    int32_t market;            // 市场
    Amt_t all_fee_unfrz;       // 当日归还负债息费，扩大一万倍
    int64_t stk_repay_unfrz;   // 当日归还负债数量
    int32_t end_date;          // 负债截至日期
	Price_t init_cost_price;   // 初始成本价格
};

// 可还融资负债金额数据
struct CreditRepayAmountDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    Amt_t max_back_amt;    // 可还款金额，扩大一万倍，精度0.01
};

// 查询可还融券负债数量请求
struct QryCreditRepayStockReq {
	char32 market;			// 市场，如 "SZ" 或者 "SH"，非必传，默认查所有市场
	char16 code;			// 证券代码，例如600000，非必传，默认查全部
	char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;		// 查询的数量，最大支持500个，仅支持低延时柜台
};

// 可还融券负债数量明细
struct CreditRepayStockDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 symbol;         // 持仓标的，格式为市场.证券ID或市场.合约ID
    char32 name;           // 证券名称
    int64_t total_qty;     // 当前融券负债总数量，包含T日融券数量（T日不可偿还）、当前已还券总数量
    int64_t max_back_qty;  // 当前可还券数量
    int64_t returned_qty;  // 当前已还券总数量，包含T日和T日之前还券数量（包括现券还券、买券还券数量）
};

// 查询担保品券请求
struct QryCreditMortgageHoldReq {
    char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;    // 查询的数量，最大支持500个
};

// 担保品券数据
struct CreditMortgageHoldDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 symbol;          // 标的券，格式为市场.证券ID或市场.合约ID
    char32 name;            // 证券名称
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    Ratio_t pledge_rate;    // 折算率，扩大一万倍
};

// 查询可融券卖出数量请求
struct QryCreditSecuritySellQtyReq {
	char32 market;			// 市场，如 "SZ" 或者 "SH"，非必传，默认查所有市场
	char16 code;			// 证券代码，例如600000，非必传，默认查全部
	char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;		// 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// 查询可融券卖出数量的应答类型
struct CreditSecuritySellQtyRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 symbol;         // 证券代码，格式为市场.证券ID或市场.合约ID
    int64_t total_qty;     // 证券数量，指锁券的总数量
    int64_t avail_qty;     // 证券可用剩余数量，指锁券的可用数量
};

// 查询账号交易权限请求
struct QrySecuidRightReq {
	char8 market;          // 市场，如"SZ SH"
	int16_t secuid_right;  // 权限类型，如创业板，参考SecuidRight定义
};

// 查询账号交易权限应答
struct QrySecuidRightRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char8 market;          // 市场，如"SZ SH"
    int16_t secuid_right;  // 权限类型，如创业板，参考SecuidRight定义
    bool sign_flag;        // 签署权限标志，true即有权限
};

// 期权资金明细数据
struct OptionCashDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    int16_t currency_type;    // 货币类型，参考CurrencyType定义
    Amt_t init_amount;        // 日初资金，扩大一万倍
    Amt_t total_amount;       // 总资金量，扩大一万倍
    Amt_t avail_amount;       // 可用资金，扩大一万倍
    Amt_t fetch_amount;       // 可取资金，扩大一万倍
    Amt_t frozen_amount;      // 冻结资金，权利金委托冻结，扩大一万倍
    Amt_t used_margin;        // 实时占用的保证金，包含未成交义务仓委托的冻结保证金，扩大一万倍
    Amt_t exercise_frozen;    // 行权冻结资金，扩大一万倍
    Amt_t deposit_amount;     // 入金金额，扩大一万倍
    Amt_t withdraw_amount;    // 出金金额，扩大一万倍
    Amt_t royalty_in;         // 权利金收入，扩大一万倍
    Amt_t royalty_out;        // 权利金支出，扩大一万倍
    Amt_t commission;         // 手续费，扩大一万倍
    Amt_t frozen_commission;  // 冻结手续费，扩大一万倍
};

// 期权持仓明细数据
struct OptionPositionDetail {
    char16 account_id;             // 交易账号，目前是资金账号
    int16_t account_type;          // 交易账号类型，参考AccountType定义
    char8 cust_orgid;              // 机构编码
    char8 cust_branchid;           // 分支编码
    char32 symbol;                 // 持仓标的，格式为市场.证券ID或市场.合约ID
    int16_t side;                  // 持仓方向，参考PositionSide定义
    int64_t init_volume;           // 日初持仓量，包含组合占用持仓
    int64_t init_avail_volume;     // 日初可用持仓量
    int64_t init_comb_volume;      // 日初已组合持仓量
    int64_t volume;                // 总持仓量，包含组合占用持仓
    int64_t avail_volume;          // 可用持仓量
    int64_t comb_volume;           // 已组合持仓量
    int64_t open_volume;           // 开仓数量
    int64_t close_volume;          // 平仓数量
    int64_t exercise_frozen;       // 行权冻结数量，包含合并行权冻结数量
    Amt_t buy_cost;                // 持仓成本，扩大一万倍
    char16 secuid;                 // 证券账户(股东代码)
    Amt_t margin;                  // 占用的保证金，扩大一万倍
    Amt_t frozen_margin;           // 冻结的保证金，扩大一万倍，仅支持泰琰柜台
    Amt_t commission;              // 手续费，扩大一万倍，仅支持泰琰柜台
    Amt_t frozen_commission;       // 冻结的手续费，扩大一万倍，仅支持泰琰柜台
    Amt_t exercise_frozen_amount;  // 行权冻结金额，扩大一万倍，仅支持泰琰柜台
    Amt_t frozen_amount;           // 冻结的资金，扩大一万倍，仅支持泰琰柜台
    Amt_t today_close_profit;      // 当日平仓盈亏，扩大一万倍
    Amt_t buy_quota_used;          // 买入占用额度，扩大一万倍
    Price_t last_price;            // 最新价，扩大一万倍
    int64_t underlying_multiple;   // 合约单位
};

// 行权的请求类型
struct ExerciseReq {
    char32 cl_order_id;     // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 symbol;          // 交易标的，格式为市场.证券ID或市场.合约ID
    int64_t volume;         // 数量
    int16_t exercise_type;  // 执行类型，参考ExerciseType定义，仅支持泰琰柜台
};

// 行权的响应类型
struct ExerciseRsp {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 cl_order_id;     // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;        // 柜台行权委托编号
    int16_t exercise_type;  // 执行类型，参考ExerciseType定义，仅支持泰琰柜台
};

// 撤销行权请求类型
struct CancelExerciseReq {
    char32 order_id;      // 柜台行权委托编号
    char32 cl_order_id;   // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
    char32 cl_cancel_id;  // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
};

// 撤销行权响应类型
struct CancelExerciseRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 order_id;       // 柜台行权委托编号
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    char32 cl_cancel_id;   // 客户端撤单id，用来引用一个撤单订单，由用户自定义，原样返回
};

// 查询行权委托列表请求
struct QryExercisesReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个
};

// 行权委托明细
struct ExerciseDetail {
    char16 account_id;            // 交易账号，目前是资金账号
    int16_t account_type;         // 交易账号类型，参考AccountType定义
    char8 cust_orgid;             // 机构编码
    char8 cust_branchid;          // 分支编码
    int16_t exercise_type;        // 执行类型，参考ExerciseType定义，仅支持泰琰柜台
    char32 cl_order_id;           // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;              // 柜台行权委托编号
    int32_t counter_order_date;   // 申报日期，格式为YYYYMMDD
    int32_t counter_order_time;   // 申报时间，格式为HHMMSSmmm
    int32_t counter_cancel_time;  // 撤销时间，格式为HHMMSSmmm
    int32_t exercise_status;      // 行权状态
    int32_t oper_status;          // 行权操作状态
    char32 symbol;                // 交易标的，格式为市场.证券ID或市场.合约ID
    int32_t volume;               // 成交数量
    int32_t cancel_volume;        // 交易所返回的撤单数量
    int32_t err_code;             // 行权失败时的错误码
    char256 err_msg;              // 行权失败时的错误消息，Windows是GBK，Linux是UTF8
};

// 期权合约信息
struct ContractInfo {
    char32 contract_id;                    // 合约代码，格式为市场.证券ID或市场.合约ID
    char32 exch_contract_id;               // 交易所合约代码，仅支持泰琰柜台
    char64 contract_name;                  // 合约名称
    char32 underlying_contract_id;         // 基础证券代码
    char32 underlying_contract_name;       // 基础证券名称
    int32_t underlying_multiplier;         // 合约基础商品乘数，仅支持泰琰柜台
    int32_t strike_mode;                   // 执行方式，参考StrikeModeType定义，仅支持泰琰柜台
    int32_t options_type;                  // 期权类型，参考OptionsType定义
    int32_t order_unit;                    // 申报单位，参考OrderUnitType定义，仅支持泰琰柜台
    int32_t buy_trading_unit;              // 买入交易单位
    int32_t sell_trading_unit;             // 卖出交易单位，仅支持泰琰柜台
    int32_t max_market_order_buy_volume;   // 市价单买最大下单量
    int32_t min_market_order_buy_volume;   // 市价单买最小下单量
    int32_t max_limit_order_buy_volume;    // 限价单买最大下单量
    int32_t min_limit_order_buy_volume;    // 限价单买最小下单量
    int32_t max_market_order_sell_volume;  // 市价单卖最大下单量，仅支持泰琰柜台
    int32_t min_market_order_sell_volume;  // 市价单卖最小下单量，仅支持泰琰柜台
    int32_t max_limit_order_sell_volume;   // 限价单卖最大下单量，仅支持泰琰柜台
    int32_t min_limit_order_sell_volume;   // 限价单卖最小下单量，仅支持泰琰柜台
    int32_t volume_multiplier;             // 数量乘数，仅支持泰琰柜台
    Price_t price_tick;                    // 最小变动价位，扩大一万倍
    int32_t contract_status;               // 合约状态，参考ContractStatus定义，仅支持泰琰柜台
    Price_t strike_price;                  // 执行价，扩大一万倍
    int32_t first_date;                    // 首交易日，仅支持泰琰柜台
    int32_t last_date;                     // 最后交易日
    int32_t strike_date;                   // 行权日
    int32_t expire_date;                   // 到期日，仅支持泰琰柜台
    int32_t deliv_date;                    // 交割日
    int32_t is_up_down_limit;              // 是否有涨跌幅限制，1表示是，0表示否，仅支持泰琰柜台
    Amt_t margin_unit;                     // 期权单位保证金，扩大一万倍
    Price_t pre_settlement_price;          // 合约前结算价，扩大一万倍
    Price_t pre_close_price;               // 合约前收盘价，扩大一万倍，仅支持泰琰柜台
    Price_t underlying_pre_close_price;    // 标的合约前收盘价，扩大一万倍
};

// 现货持仓划转请求类型
struct TransferStockReq {
    char32 symbol;          // 转移标的代码，格式为市场.证券ID或市场.合约ID
    int16_t transfer_type;  // 现货持仓转移类型，参考TransferPositionType定义
    int16_t transfer_side;  // 现货持仓转移方向，参考TransferStockPositionSide定义
    int64_t transfer_qty;   // 转移数量
};

// 现货持仓划转应答类型
struct TransferStockRsp {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 symbol;          // 转移标的代码，格式为市场.证券ID或市场.合约ID
    int16_t transfer_type;  // 现货持仓转移类型，参考TransferPositionType定义
    int16_t transfer_side;  // 现货持仓转移方向，参考TransferStockPositionSide定义
    int64_t transfer_qty;   // 转移数量
};

// 现货持仓划转明细数据
struct TransferStockDetail {
    char16 account_id;         // 交易账号，目前是资金账号
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    char32 serial_number;      // 转移流水号
    char32 symbol;             // 转移标的代码，格式为市场.证券ID或市场.合约ID
    int32_t transact_date;     // 处理日期，格式为YYYYMMDD
    int32_t transact_time;     // 处理时间，格式为HHMMSSmmm
    int16_t transfer_type;     // 仓位转移类型，参考TransferPositionType定义
    int16_t transfer_side;     // 仓位转移方向，参考TransferStockPositionSide定义
    int16_t transfer_status;   // 转移状态，请参考TransferStatus定义
    int64_t yesterday_volume;  // 昨日仓位量
    int64_t today_bs_volume;   // 今日买卖仓位量
    int64_t today_pr_volume;   // 今日申赎仓位量
    char32 stock_cust_id;      // 现货系统客户号
    char32 stock_secuid;       // 现货系统股东代码
    char64 status_msg;         // 转移状态信息
};

// 锁定现货委托请求类型
struct LockOrderReq {
    char32 cl_order_id;  // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
    char32 symbol;       // 现货锁定标的，格式为市场.证券ID或市场.合约ID
    int16_t lock_type;   // 现货锁定类型，参考LockStockType定义
    int64_t volume;      // 现货锁定数量
};

// 锁定现货委托应答类型
struct LockOrderRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int16_t lock_type;     // 现货锁定类型，参考LockStockType定义
    char32 order_id;       // 系统生成的锁定委托id
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
};

// 查询现货锁定委托列表请求
struct QryLockOrdersReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个
};

// 锁定现货委托明细数据
struct LockOrderDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 symbol;          // 锁定的标的代码，格式为市场.证券ID或市场.合约ID
    char32 cl_order_id;     // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;        // 柜台锁定委托编号
    int32_t order_date;     // 申报日期，格式为YYYYMMDD
    int32_t order_time;     // 申报时间，格式为HHMMSSmmm
    int32_t cancel_time;    // 撤销时间，格式为HHMMSSmmm
    int16_t lock_type;      // 锁定类型，参考LockStockType定义
    int16_t lock_status;    // 锁定状态，成功、失败，参考LockStockStatus定义
    int64_t volume;         // 委托数量
    int64_t cancel_volume;  // 撤销数量
    int32_t err_code;       // 委托失败时的错误码
    char256 err_msg;        // 委托失败时的错误消息，Windows是GBK，Linux是UTF8
};

// 组合委托请求类型
struct CombOrderReq {
    char32 cl_order_id;  // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
    char32 symbol;       // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
                            // 对于保证金开仓转备兑、备兑仓转普通，是单个合约代码
    int16_t comb_type;      // 组合报单类型，参考OptionCombineType定义
    int16_t comb_strategy;  // 组合策略类型，参考OptionCombineStrategy定义
    int64_t volume;         // 订单数量，单位：份
    char32 exch_comb_id;    // 交易所组合编码（拆分组合时必填），组合委托推送状态为成交时返回
};

// 组合委托应答类型
struct CombOrderRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int16_t comb_type;     // 组合报单类型，参考OptionCombineType定义
    char32 order_id;       // 系统生成的组合委托id
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
};

// 组合行权的请求类型
struct CombExerciseReq {
    char32 cl_order_id;  // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 call_symbol;  // 认购合约代码，格式为市场.合约ID，例如SHOP.10002421
    char32 put_symbol;   // 认沽合约代码，格式为市场.合约ID，例如SHOP.10002401
    int64_t volume;      // 数量
};

// 组合行权的响应类型
struct CombExerciseRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 cl_order_id;    // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;       // 柜台行权委托编号
};

// 撤销组合行权请求类型
struct CancelCombExerciseReq {
    char32 order_id;      // 柜台行权委托编号
    char32 cl_order_id;   // 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
    char32 cl_cancel_id;  // 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
};

// 撤销组合行权响应类型
struct CancelCombExerciseRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    char32 order_id;       // 柜台行权委托编号
    char32 cl_order_id;    // 客户端订单id，用来引用一个普通订单，由用户自定义，原样返回
    char32 cl_cancel_id;   // 客户端撤单id，用来引用一个撤单订单，由用户自定义，原样返回
};

// 查询当日组合委托列表请求
struct QryCombOrdersReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个
};

// 组合委托明细数据
struct CombOrderDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 symbol;          // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    char32 exch_comb_id;    // 交易所组合编码，拆分时使用
    int16_t comb_type;      // 组合报单类型，参考OptionCombineType定义
    int16_t comb_strategy;  // 组合策略类型，参考OptionCombineStrategy定义
    char32 cl_order_id;     // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;        // 柜台组合委托编号
    int32_t order_date;     // 申报日期，格式为YYYYMMDD
    int32_t order_time;     // 申报时间，格式为HHMMSSmmm
    int32_t cancel_time;    // 撤销时间，格式为HHMMSSmmm
    int16_t order_status;   // 组合委托状态，参考OrderStatus定义
    int16_t oper_status;    // 组合委托操作状态，参考ExerciseOperateStatus定义
    int64_t volume;         // 委托数量
    int64_t cancel_volume;  // 撤销数量
    int32_t err_code;       // 委托失败时的错误码
    char256 err_msg;        // 委托失败时的错误消息，Windows是GBK，Linux是UTF8
};

// 查询组合行权委托列表请求
struct QryCombExercisesReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个
};

// 组合行权明细数据
struct CombExerciseDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    char32 call_symbol;       // 认购合约代码，格式为市场.合约ID，例如SHOP.10002421
    char32 put_symbol;        // 认沽合约代码，格式为市场.合约ID，例如SHOP.10002401
    char32 cl_order_id;       // 客户端订单id，由用户自定义，用来引用一个普通订单
    char32 order_id;          // 柜台组合行权委托编号
    int32_t order_date;       // 申报日期，格式为YYYYMMDD
    int32_t order_time;       // 申报时间，格式为HHMMSSmmm
    int32_t cancel_time;      // 撤销时间，格式为HHMMSSmmm
    int16_t exercise_status;  // 合并行权状态，参考ExerciseStatus定义
    int16_t oper_status;      // 行权操作状态，参考ExerciseOperateStatus定义
    int64_t volume;           // 行权数量
    int64_t cancel_volume;    // 撤销数量
    int32_t err_code;         // 行权失败时的错误码
    char256 err_msg;          // 行权失败时的错误消息，Windows是GBK，Linux是UTF8
};

// 组合持仓明细数据
struct CombPositionDetail {
    char16 account_id;               // 交易账号，目前是资金账号
    int16_t account_type;            // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                // 机构编码
    char8 cust_branchid;             // 分支编码
    char32 symbol;                   // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    int16_t comb_strategy;           // 组合策略类型，参考OptionCombineStrategy定义
    int64_t volume;                  // 持仓总数量
    int64_t avail_volume;            // 持仓可用数量
    int64_t yesterday_volume;        // 昨日持仓量
    int64_t yesterday_avail_volume;  // 昨日可用持仓量，仅支持泰琰柜台
    int64_t today_volume;            // 今日买卖持仓量
    int64_t today_avail_volume;      // 今日买卖可用持仓量
    Amt_t margin;                    // 占用的保证金，扩大一万倍
    Amt_t frozen_margin;             // 冻结的保证金，扩大一万倍，仅支持泰琰柜台
    Amt_t commission;                // 手续费，扩大一万倍，仅支持泰琰柜台
    Amt_t frozen_commission;         // 冻结的手续费，扩大一万倍，仅支持泰琰柜台
    char16 secuid;                   // 股东代码
};

// 组合持仓二级明细
struct CombPositionSubDetail {
    char16 account_id;                           // 交易账号，目前是资金账号
    int16_t account_type;                        // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                            // 机构编码
    char8 cust_branchid;                         // 分支编码
    char32 symbol;                               // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    int16_t comb_strategy;                       // 组合策略类型，参考OptionCombineStrategy定义
    char32 exch_comb_id;                         // 交易所组合编码，拆分时使用
    int64_t volume;                              // 持仓总数量
    int64_t yesterday_volume;                    // 昨日持仓量
    int64_t today_volume;                        // 今日买卖持仓量
    int32_t comb_date;                           // 组合日期，格式为YYYYMMDD，仅支持泰琰柜台
    int32_t comb_time;                           // 组合时间，格式为HHMMSSmmm，仅支持泰琰柜台
    int16_t comb_status;                         // 组合状态，参考OptionCombineStatus定义，仅支持泰琰柜台
    char16 secuid;                               // 股东代码
    int32_t legs_num;                            // 成份合约个数，最多四条腿
    char32 leg1_symbol;                          // 第一腿合约代码，格式为市场.合约ID&合约ID
    int64_t leg1_yesterday_volume;               // 第一腿昨日组合数量
    int64_t leg1_today_volume;                   // 第一腿今日组合数量
    int16_t leg1_pos_side;                       // 第一腿持仓方向，参考PositionSide定义
    int16_t leg1_option_type;                    // 第一腿期权类型，参考OptionsType定义，仅支持泰琰柜台
    char32 leg2_symbol;                          // 第二腿合约代码，格式为市场.合约ID&合约ID
    int64_t leg2_yesterday_volume;               // 第二腿昨日组合数量
    int64_t leg2_today_volume;                   // 第二腿今日组合数量
    int16_t leg2_pos_side;                       // 第二腿持仓方向，参考PositionSide定义
    int16_t leg2_option_type;                    // 第二腿期权类型，参考OptionsType定义，仅支持泰琰柜台
    int64_t yesterday_split_frozen_volume;       // 拆分冻结的昨日组合数量，仅支持泰琰柜台
    int64_t today_split_frozen_volume;           // 拆分冻结的今日组合数量
    int64_t leg1_yesterday_split_frozen_volume;  // 拆分冻结的第一腿昨日组合数量，仅支持泰琰柜台
    int64_t leg1_today_split_frozen_volume;      // 拆分冻结的第一腿今日组合数量，仅支持泰琰柜台
    int64_t leg2_yesterday_split_frozen_volume;  // 拆分冻结的第二腿昨日组合数量，仅支持泰琰柜台
    int64_t leg2_today_split_frozen_volume;      // 拆分冻结的第二腿今日组合数量，仅支持泰琰柜台
};

// 组合期权合约信息
struct CombContractInfo {
    char32 contract_id;       // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    int16_t comb_strategy;    // 组合策略类型，参考OptionCombineStrategy定义
    char32 leg1_contract_id;  // 成分一合约代码，格式为市场.证券ID或市场.合约ID
    char64 leg1_name;         // 成分一合约名称
    int16_t leg1_side;        // 策略要求的成分一合约多空方向，参考PositionSide定义
    char32 leg2_contract_id;  // 成分二合约代码，格式为市场.证券ID或市场.合约ID
    char64 leg2_name;         // 成分二合约名称
    int16_t leg2_side;        // 策略要求的成分二合约多空方向，参考PositionSide定义
};

// 查询锁券信息请求
struct QryLockSecurityReq {
	int start_date;       // 开始日期，格式为YYYYMMDD，如20190415
	int end_date;         // 结束日期，格式为YYYYMMDD，如20190418
	char8 market;         // 根据市场过滤，可不填，默认设置为空
	char16 code;          // 根据代码过滤，可不填，默认设置为空
	char64 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个，低延时账号无回切此字段值有效，其他情况无效。
};

// 锁券明细
struct LockSecurityDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    int32_t sys_date;         // 系统日期
	char32 sno;               // 锁券流水号
    char32 symbol;            // 标的代码，格式为市场.证券ID
    char32 name;              // 证券名称
    int16_t lock_type;        // 锁券收费类型，参考LockChargeType定义
    Ratio_t used_fee_rate;    // 融券费率，扩大一万倍
    Ratio_t unused_fee_rate;  // 管理费率，扩大一万倍
    int32_t lock_qty;         // 锁券数量
    int32_t used_qty;         // 已使用数量
    int32_t back_qty;         // 回收数量
    int32_t begin_date;       // 开始日期
    int32_t back_date;        // 归还日期
    int32_t end_date;         // 结束日期
    int16_t hs_status;        // 回收状态，参考 RecycleStatus 定义，目前仅支持低延时柜台
    int16_t wy_status;        // 违约状态，参考 ViolationStatus 定义，目前仅支持低延时柜台
};

// 资金划转流水明细数据
struct TransferFundDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char32 serial_number;     // 转移流水号
    int32_t transact_date;    // 处理日期YYYYMMDD
    int32_t transact_time;    // 处理时间HHMMSSmmm
    Amt_t transfer_value;     // 转移金额，扩大一万倍
    int16_t transfer_side;    // 转入/转出，请参考TransferFundSide
    int16_t transfer_status;  // 转移状态，请参考TransferStatus
    char256 remark;           // 备注
};

// 投资者限仓详情
struct PositionLimitsDetail {
    char16 account_id;                       // 交易账号，目前是资金账号
    int16_t account_type;                    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                        // 机构编码
    char8 cust_branchid;                     // 分支编码
    char32 symbol;                           // 组合合约代码，格式为市场.合约ID，例如SHOP.10002421
    int64_t avail_total_limit;               // 可用总持仓限额
    int64_t avail_long_limit;                // 可用多头持仓限额
    int64_t avail_today_open_limit;          // 可用开仓限额
    int64_t avail_today_buy_open_limit;      // 可用买入开仓限额
    int64_t avail_today_sell_open_limit;     // 可用卖出开仓限额
    int64_t avail_today_covered_open_limit;  // 可用备兑开仓限额
    int64_t avail_long_call_limit;           // 可用认购多头持仓限额
    int64_t avail_long_put_limit;            // 可用认沽多头持仓限额
    int64_t avail_long_underlying_limit;     // 可用标的多头持仓限额
    int64_t avail_short_underlying_limit;    // 可用标的空头持仓限额
    int64_t total_limit;                     // 总持仓限额
    int64_t long_limit;                      // 多头持仓限额
    int64_t today_open_limit;                // 开仓限额
    int64_t today_buy_open_limit;            // 买入开仓限额
    int64_t today_sell_open_limit;           // 卖出开仓限额
    int64_t today_covered_open_limit;        // 备兑开仓限额
    int64_t long_call_limit;                 // 认购多头持仓限额
    int64_t long_put_limit;                  // 认沽多头持仓限额
    int64_t long_underlying_limit;           // 标的多头持仓限额
    int64_t short_underlying_limit;          // 标的空头持仓限额
};

// 查询投资者限额请求
struct QryAmountLimitsReq {
    char8 market;                   // 市场，如"SZOP SHOP"
};

// 投资者限额详情
struct AmountLimitsDetail {
    char16 account_id;              // 交易账号，目前是资金账号
    int16_t account_type;           // 交易账号类型，参考AccountType定义
    char8 cust_orgid;               // 机构编码
    char8 cust_branchid;            // 分支编码
    Amt_t long_amount_limit;        // 多头金额限额，扩大一万倍
    Amt_t avail_long_amount_limit;  // 可用多头金额限额，扩大一万倍
    char8 market;                   // 市场，如"SZOP SHOP"
};

// 查询拆分组合合约后保证金差额变动请求
struct QrySplitCombMarginDiffReq {
    char32 contract_id;          // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    int16_t comb_strategy;       // 组合策略类型，参考OptionCombineStrategy定义
    int64_t volume;              // 报单数量
    char32 exch_comb_id;         // 交易所组合编码（拆分组合时必填），组合委托推送状态为成交时返回
};

// 拆分组合合约后保证金差额变动详情
struct SplitCombMarginDiffDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 contract_id;               // 组合合约代码，格式为市场.合约ID&合约ID，例如SHOP.10002421&10002401
    char32 exch_comb_id;              // 交易所组合编码（拆分组合时必填），组合委托推送状态为成交时返回
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义
    int64_t volume;                   // 报单数量
    Amt_t left_leg_pos_margin;        // 左腿合约占用保证金，扩大一万倍
    Amt_t left_leg_pos_live_margin;   // 左腿合约占用实时保证金，扩大一万倍
    Amt_t right_leg_pos_margin;       // 右腿合约占用保证金，扩大一万倍
    Amt_t right_leg_pos_live_margin;  // 右腿合约占用实时保证金，扩大一万倍
    Amt_t comb_pos_margin;            // 组合仓位占用保证金，扩大一万倍
    Amt_t comb_pos_live_margin;       // 组合仓位占用实时保证金，扩大一万倍
    Amt_t margin_difference;          // 保证金差额（组合合约拆分前后保证金的差额），扩大一万倍
    Amt_t margin_live_difference;     // 保证金实时差额（组合合约拆分前后保证金的差额），扩大一万倍
};

// 查询投资者行权指派明细请求
struct QryExerciseAppointmentReq {
    char8 market;                  // 市场，如"SZOP SHOP"，非必传
    char32 contract_id;            // 合约代码，格式为市场.合约ID，例如SHOP.10002421，非必传
};

// 投资者行权指派明细详情
struct ExerciseAppointmentDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 contract_id;               // 合约代码，格式为市场.合约ID，例如SHOP.10002421
    int32_t counter_order_date;       // 行权申报日期，格式为YYYYMMDD
    char16 secuid;                    // 证券账户（股东代码）
    int32_t options_type;             // 期权类型，参考OptionsType定义
    int64_t option_unit;              // 合约单位
    char32 underlying_contract_id;    // 基础证券代码
    int64_t volume;                   // 行权数量
    Price_t exercise_price;           // 行权价，扩大一万倍
    int32_t exercise_side;            // 行权方向，参考ExerciseSide定义
    int32_t cover_flag;               // 备兑标志，参考CoverFlag定义
};

// 查询期权最大可委托数请求
struct QryOptionMaxOrderVolumeReq {
    char32 contract_id;             // 合约代码，合约代码，格式为市场.合约ID，例如SHOP.10002421
    int16_t side;                   // 买卖方向，参考OrderSide定义
    int16_t order_type;             // 订单类型，参考OrderType定义，新股申购填限价
    int16_t order_flag;             // 委托属性，仅股票期权账号使用，参考OrderFlag定义
    Price_t price;                  // 订单委托价，限价单使用，扩大一万倍，市价填写0
};

// 期权最大可委托数详情
struct OptionMaxOrderVolumeDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int64_t max_volume;               // 最大可委托数
};

// 查询股票期权历史委托请求
struct QryOptionHisOrderReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 股票期权历史委托详情
struct OptionHisOrderDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t trade_date;               // 交易日期
    int32_t order_date;               // 委托日期
    int64_t order_time;               // 委托时间
    char32 contract_id;               // 合同号
    int32_t status;                   // 委托状态
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 secuid;                    // 股东账号
    char32 option_account;            // 期权合约账号
    int32_t option_security_type;     // 期权证券业务，参考OptionSecurityType定义
    char32 option_num;                // 合约编码
    char64 option_code;               // 合约代码
    char64 option_name;               // 合约简称
    char32 comb_num;                  // 组合编码
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义
    char32 leg1_num;                  // 成分一合约编码
    char32 leg2_num;                  // 成分二合约编码
    char32 leg3_num;                  // 成分三合约编码
    char32 leg4_num;                  // 成分四合约编码
    int16_t currency_type;            // 货币类型，参考CurrencyType定义
    int64_t price;                    // 委托价格，扩大一万倍
    int32_t qty;                      // 委托数量
    int64_t order_amt;                // 委托金额，扩大一万倍
    int64_t order_frozen_amt;         // 委托冻结金额，扩大一万倍
    int64_t order_unfrozen_amt;       // 委托解冻金额，扩大一万倍
    int32_t offer_qty;                // 申报数量
    int64_t offer_time;               // 申报时间
    int64_t cancel_qty;               // 撤单数量
    int64_t match_qty;                // 成交数量
    int64_t match_amt;                // 成交金额，扩大一万倍
    int32_t cancel_flag;              // 撤单标志，参考CancelFlag定义
    char32 underlying_code;           // 标的证券代码
    char32 underlying_name;           // 标的证券名称
    int64_t underlying_frozen_qty;    // 标的证券冻结数量
    int64_t underlying_unfrozen_qty;  // 标的证券解冻数量
    int64_t underlying_cancel_qty;    // 标的证券已撤单数量
    int32_t leg1_side;                // 成分一持仓方向，参考PositionSide定义
    int32_t leg2_side;                // 成分二持仓方向
    int32_t leg3_side;                // 成分三持仓方向
    int32_t leg4_side;                // 成分四持仓方向
    char64 leg1_name;                 // 成分一合约简称
    char64 leg2_name;                 // 成分二合约简称
    char64 leg3_name;                 // 成分三合约简称
    char64 leg4_name;                 // 成分四合约简称
};

// 查询股票期权历史成交请求
struct QryOptionHisTradeReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 股票期权历史成交详情
struct OptionHisTradeDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t trade_date;               // 交易日期
    int64_t trade_time;               // 成交时间，格式为HHMMSSmmmuuu
    int32_t order_date;               // 委托日期
    char32 counter_order_id;          // 柜台订单id
    char32 contract_id;               // 合同号
    char32 match_id;                  // 成交编号
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 secuid;                    // 股东账号
    char32 option_account;            // 期权合约账号
    int32_t option_security_type;     // 期权证券业务，参考OptionSecurityType定义
    int32_t option_security_action;   // 期权证券业务行为，参考OptionSecurityAction定义
    char32 option_num;                // 合约编码
    char64 option_name;               // 合约简称
    char32 comb_num;                  // 组合编码
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义
    char32 leg1_num;                  // 成分一合约编码
    char32 leg2_num;                  // 成分二合约编码
    char32 leg3_num;                  // 成分三合约编码
    char32 leg4_num;                  // 成分四合约编码
    int16_t currency_type;            // 货币类型，参考CurrencyType定义
    char32 underlying_code;           // 标的证券代码
    char32 underlying_name;           // 标的证券名称
    int64_t price;                    // 委托价格，扩大一万倍
    int32_t qty;                      // 委托数量
    int64_t order_frozen_amt;         // 委托冻结金额，扩大一万倍
    int64_t match_price;              // 成交价格，扩大一万倍
    int64_t match_qty;                // 成交数量
    int64_t match_amt;                // 成交金额，扩大一万倍
    int32_t leg1_side;                // 成分一持仓方向，参考PositionSide
    int32_t leg2_side;                // 成分二持仓方向
    int32_t leg3_side;                // 成分三持仓方向
    int32_t leg4_side;                // 成分四持仓方向
    char64 leg1_name;                 // 成分一合约简称
    char64 leg2_name;                 // 成分二合约简称
    char64 leg3_name;                 // 成分三合约简称
    char64 leg4_name;                 // 成分四合约简称
};

// 查询股票期权历史行权指派明细请求
struct QryHisExerciseAppointmentReq {
    int16_t currency_type;            // 币种，参考CurrencyType定义
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 股票期权历史行权指派明细
struct HisExerciseAppointmentDetail {
    char16 account_id;               // 交易账号，目前是资金账号
    int16_t account_type;            // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                // 机构编码
    char8 cust_branchid;             // 分支编码
    int32_t counter_order_date;      // 柜台行权报单日期YYYMMDD
    int16_t currency_type;           // 币种，参考CurrencyType定义
    char8 market;                    // 市场，如"SZOP SHOP"
    char32 secuid;                   // 股东账号
    char32 option_account;           // 期权合约账号
    char32 option_num;               // 合约编码
    char64 option_name;              // 合约简称
    int32_t options_type;            // 期权类型，参考OptionsType定义
    char32 underlying_code;          // 标的证券代码
    int32_t cover_flag;              // 备兑标志，参考CoverFlag定义
    int64_t volume;                  // 行权数量
    int64_t underlying_volume;       // 标的证券收付数量
    int64_t exercise_amt;            // 行权收付金额，扩大一万倍
    int64_t exercise_price;          // 行权价，扩大一万倍
    int32_t exercise_side;           // 行权方向，参考ExerciseSide定义
    int64_t comb_volume;             // 组合行权数量
};

// 查询股票期权历史交收明细请求
struct QryOptionHisDeliveryReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 股票期权历史交收明细
struct OptionHisDeliveryDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int64_t settlement_id;            // 清算序号
    int32_t settlement_date;          // 清算日期
    char32 counter_order_id;          // 柜台订单id
    char32 contract_id;               // 合同号
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 option_account;            // 期权合约账号
    int32_t option_security_type;     // 期权证券业务，参考OptionSecurityType定义
    int32_t option_security_action;   // 期权证券业务行为，参考OptionSecurityAction定义
    char32 option_num;                // 合约编码
    char64 option_name;               // 合约简称
    char32 comb_num;                  // 组合编码
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义
    char32 leg1_num;                  // 成分一合约编码
    char32 leg2_num;                  // 成分二合约编码
    char32 leg3_num;                  // 成分三合约编码
    char32 leg4_num;                  // 成分四合约编码
    int16_t currency_type;            // 货币类型，参考CurrencyType定义
    char32 underlying_code;           // 标的证券代码
    char32 underlying_name;           // 标的证券名称
    int64_t price;                    // 委托价格，扩大一万倍
    int32_t qty;                      // 委托数量
    int64_t order_amt;                // 委托金额，扩大一万倍
    int64_t match_price;              // 成交价格，扩大一万倍
    int64_t match_qty;                // 成交数量
    int64_t match_amt;                // 成交金额，扩大一万倍
    int32_t match_cnt;                // 成交笔数
    int64_t stamp_duty;               // 印花税，扩大一万倍
    int64_t handle_fee;               // 经手费，扩大一万倍
    int64_t secu_regu_fee;            // 证管费，扩大一万倍
    int64_t trd_regu_fee;             // 交易规费，扩大一万倍
    int64_t clearing_fee;             // 清算费，扩大一万倍
    int64_t exch_trans_fee;           // 交易所过户费，扩大一万倍
    int64_t trans_fee;                // 过户费，扩大一万倍
    int64_t exe_trans_fee;            // 行权过户费，扩大一万倍
    int64_t paidin_com;               // 实收佣金，扩大一万倍
    int64_t settlement_amt;           // 清算金额，金额扩大一万倍
    int32_t leg1_side;                // 成分一持仓方向，参考PositionSide定义
    int32_t leg2_side;                // 成分二持仓方向
    int32_t leg3_side;                // 成分三持仓方向
    int32_t leg4_side;                // 成分四持仓方向
    char64 leg1_name;                 // 成分一合约简称
    char64 leg2_name;                 // 成分二合约简称
    char64 leg3_name;                 // 成分三合约简称
    char64 leg4_name;                 // 成分四合约简称
};

// 查询历史行权交收流水明细请求
struct QryHisExerciseDeliveryReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 历史行权交收流水明细
struct HisExerciseDeliveryyDetail {
    char16 account_id;                 // 交易账号，目前是资金账号
    int16_t account_type;              // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                  // 机构编码
    char8 cust_branchid;               // 分支编码
    int64_t serial_number;             // 流水序号
    int32_t settlement_date;           // 清算日期
    int64_t occur_time;                // 发生时间，格式为HHMMSSmmmuuu
    char8 market;                      // 市场，如"SZOP SHOP"
    int16_t currency_type;             // 货币类型，参考CurrencyType定义
    char32 option_account;             // 期权合约账号
    int32_t option_security_type;      // 期权证券业务，参考OptionSecurityType定义
    int32_t option_security_action;    // 期权证券业务行为，参考OptionSecurityAction定义
    int64_t biz_amt;                   // 业务金额，扩大一万倍
    int64_t fund_bln;                  // 资金当前余额，扩大一万倍
    int64_t fund_avl;                  // 资金当前可用，扩大一万倍
    int64_t frozen_margin;             // 冻结保证金，扩大一万倍
    int64_t unfrozen_margin;           // 解冻保证金，扩大一万倍
    char32 underlying_code;            // 标的证券代码
    int64_t underlying_volume;         // 交收标的数量
    int64_t stamp_duty;                // 印花税，扩大一万倍
    int64_t handle_fee;                // 经手费，扩大一万倍
    int64_t secu_regu_fee;             // 证管费，扩大一万倍
    int64_t trd_regu_fee;              // 交易规费，扩大一万倍
    int64_t clearing_fee;              // 清算费，扩大一万倍
    int64_t venture_fee;               // 风险金，扩大一万倍
    int64_t trans_fee;                 // 过户费，扩大一万倍
    int64_t exe_trans_fee;             // 行权过户费，扩大一万倍
    int64_t paidin_com;                // 净手续费，扩大一万倍
    int64_t fee_amt;                   // 总费用，扩大一万倍
    int64_t volume;                    // 行权数量
    int64_t comb_volume;               // 组合行权数量
    int32_t biz_code;                  // 业务代码
};

// 查询对账单历史合约资产请求
struct QryOptionHisContractAssetReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 对账单历史合约资产明细
struct OptionHisContractAssetDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t occur_date;               // 发生日期
    char8 market;                     // 市场，如"SZOP SHOP"
    int16_t currency_type;            // 货币类型，参考CurrencyType定义
    char32 option_account;            // 期权合约账号
    char32 option_num;                // 合约编码
    char64 option_code;               // 合约代码
    char64 option_name;               // 合约简称
    int32_t options_type;             // 期权类型，参考OptionsType定义
    int32_t option_side;              // 持仓方向，参考PositionSide定义
    int32_t cover_flag;               // 备兑标志，参考CoverFlag定义
    char32 underlying_code;           // 标的证券代码
    int64_t option_prebln;            // 合约昨日余额，扩大一万倍
    int64_t option_bln;               // 合约余额，扩大一万倍
    int64_t option_avl;               // 合约可用数量
    int64_t option_margin;            // 合约维持保证金，扩大一万倍
    int64_t comb_volume;              // 组合合约数量
};

// 查询历史交收金额汇总轧差请求
struct QryOptionHisDeliveryNettingReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
};

// 历史交收金额汇总轧差明细
struct OptionHisDeliveryNettingDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t settlement_date;          // 清算日期
    char8 market;                     // 市场，如"SZOP SHOP"
    char32 option_account;            // 期权合约账号
    int64_t stamp_duty;               // 印花税，扩大一万倍
    int64_t handle_fee;               // 经手费，扩大一万倍
    int64_t secu_regu_fee;            // 证管费，扩大一万倍
    int64_t trd_regu_fee;             // 交易规费，扩大一万倍
    int64_t clearing_fee;             // 清算费，扩大一万倍
    int64_t exch_trans_fee;           // 交易所过户费，扩大一万倍
    int64_t trans_fee;                // 过户费，扩大一万倍
    int64_t exe_trans_fee;            // 行权过户费，扩大一万倍
    int64_t paidin_com;               // 实收佣金，扩大一万倍
    int64_t settlement_amt;           // 清算金额，扩大一万倍
};

// 查询历史组合持仓明细请求
struct QryOptionHisCombPositionReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次查询传 1，后续查询使用上次查询返回的最后一条的定位串字段的值加 1
    int32_t query_num;                // 查询数量
};

// 历史组合持仓明细
struct OptionHisCombPositionDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t occur_date;               // 发生日期
    char8 market;                     // 市场，如"SZOP SHOP"
    int16_t currency_type;            // 货币类型，参考CurrencyType定义
    char32 secuid;                    // 股东账号
    char32 option_account;            // 期权合约账号
    char32 comb_num;                  // 组合编码
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义
    char32 comb_strategy_name;        // 组合策略名称
    int64_t comb_prebln;              // 组合持仓昨日余额，扩大一万倍
    int64_t comb_bln;                 // 组合持仓余额，扩大一万倍
    int64_t comb_avl;                 // 组合持仓可用，扩大一万倍
    int64_t comb_trade_frz;           // 组合持仓交易冻结，扩大一万倍
    int64_t comb_trade_ufz;           // 组合持仓交易解冻，扩大一万倍
    int64_t comb_trade_otd;           // 组合持仓交易在途，扩大一万倍
    int64_t comb_trade_bln;           // 组合持仓交易轧差，扩大一万倍
    int64_t comb_clearing_frz;        // 组合持仓清算冻结，扩大一万倍
    int64_t comb_clearing_ufz;        // 组合持仓清算解冻，扩大一万倍
    int64_t comb_clearing_otd;        // 组合持仓清算在途，扩大一万倍
    int64_t comb_margin_unit;         // 组合单位保证金，扩大一万倍
    int64_t comb_margin;              // 组合占用保证金，扩大一万倍
    int32_t leg_count;                // 成分合约个数
    char32 leg1_num;                  // 成分一合约编码
    int32_t leg1_type;                // 成分一合约类型，参考OptionsType定义
    int32_t leg1_side;                // 成分一持仓方向，参考PositionSide定义
    int64_t leg1_position;            // 成分一持仓数量
    char32 leg2_num;                  // 成分二合约编码
    int32_t leg2_type;                // 成分二合约类型，参考OptionsType定义
    int32_t leg2_side;                // 成分二持仓方向，参考PositionSide定义
    int64_t leg2_position;            // 成分二持仓数量
    char32 leg3_num;                  // 成分三合约编码
    int32_t leg3_type;                // 成分三合约类型，参考OptionsType定义
    int32_t leg3_side;                // 成分三持仓方向，参考PositionSide定义
    int64_t leg3_position;            // 成分三持仓数量
    char32 leg4_num;                  // 成分四合约编码
    int32_t leg4_type;                // 成分四合约类型，参考OptionsType定义
    int32_t leg4_side;                // 成分四持仓方向，参考PositionSide定义
    int64_t leg4_position;            // 成分四持仓数量
    char64 leg1_name;                 // 成分一合约简称
    char64 leg2_name;                 // 成分二合约简称
    char64 leg3_name;                 // 成分三合约简称
    char64 leg4_name;                 // 成分四合约简称
};

// 期权历史交割单查询请求
struct QryOptionHisSettlementReq {
    int32_t begin_date;               // 起始日期，格式为YYYYMMDD
    int32_t end_date;                 // 终止日期，格式为YYYYMMDD
    char32 pos_str;                   // 定位串，第一次可不传，后续查询使用上次查询返回的最后一条的定位串字段的值
    int32_t query_num;                // 查询数量
};

// 期权历史交割单明细
struct OptionHisSettlementDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    int32_t settlement_date;          // 清算日期
    int32_t trade_date;               // 交易日期
    int64_t trade_time;               // 成交时间，格式为HHMMSSmmmuuu
    char32 counter_order_id;          // 柜台订单id
    char8 market;                     // 市场枚举
    int32_t currency_type;            // 货币类型，参考CurrencyType定义
    char32 option_account;            // 期权合约账号
    int32_t option_security_type;     // 期权证券业务，参考OptionSecurityType定义
    int32_t option_security_action;   // 期权证券业务行为，参考OptionSecurityAction定义
    char32 option_num;                // 合约编码
    char64 option_name;               // 合约简称
    int32_t option_side;              // 持仓方向，参考PositionSide定义
    int64_t match_price;              // 成交价格，扩大一万倍
    int64_t match_qty;                // 成交数量
    int64_t match_amt;                // 成交金额，扩大一万倍
    int64_t option_bln;               // 合约余额，扩大一万倍
    int64_t handle_fee;               // 经手费，扩大一万倍
    int64_t clearing_fee;             // 结算费，扩大一万倍
    int64_t trans_fee;                // 过户费，扩大一万倍
    int64_t exe_trans_fee;            // 行权过户费，扩大一万倍
    int64_t paidin_com;               // 净佣金，扩大一万倍
    int64_t fee_amt;                  // 总费用，扩大一万倍
    int64_t biz_amt;                  // 发生金额，扩大一万倍
    int64_t fund_bln;                 // 资金余额，扩大一万倍
};

// 期权组合策略文件查询请求
struct QryOptionCombStrategyFileReq {
    char8 market;                     // 市场，如"SZOP SHOP"，非必传
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy定义，非必传
};

// 期权组合策略文件明细
struct OptionCombStrategyFileDetail {
    char16 account_id;                // 交易账号，目前是资金账号
    int16_t account_type;             // 交易账号类型，参考AccountType定义
    char8 cust_orgid;                 // 机构编码
    char8 cust_branchid;              // 分支编码
    char8 market;                     // 市场枚举
    int16_t comb_strategy;            // 组合策略类型，参考OptionCombineStrategy
    char32 comb_strategy_name;        // 组合策略名称
    int16_t same_expdate;             // 到期日是否相同，参考SameExpiryDate定义
    int16_t same_underlying;          // 标的是否相同，参考SameUnderlying定义
    char32 auto_split_day;            // 自动解除组合日，0为到期日解除，1为E-1日解除，依次类推
    char1024 opt_underlying_codes;    // 适用标的证券代码，“,”分隔，@表示适用所有标的证券
    int32_t leg_count;                // 成分合约个数
    int32_t leg1_type;                // 成分一合约类型，参考OptionsType
    int32_t leg1_side;                // 成分一持仓方向，参考PositionSide
    int32_t leg1_exeprc_seq;          // 成分一行权价高低顺序，从1开始，行权价从高到低
    int32_t leg1_expdate_seq;         // 成分一合约到期日顺序，从1开始，到期日从近期到远期，仅same_expdate不同时有效
    int64_t leg1_position;            // 成分一持仓数量
    int32_t leg2_type;                // 成分二合约类型，参考OptionsType
    int32_t leg2_side;                // 成分二持仓方向，参考PositionSide
    int32_t leg2_exeprc_seq;          // 成分二行权价高低顺序，从1开始，行权价从高到低
    int32_t leg2_expdate_seq;         // 成分二合约到期日顺序，从1开始，到期日从近期到远期，仅same_expdate不同时有效
    int64_t leg2_position;            // 成分二持仓数量
    int32_t leg3_type;                // 成分三合约类型，参考OptionsType
    int32_t leg3_side;                // 成分三持仓方向，参考PositionSide
    int32_t leg3_exeprc_seq;          // 成分三行权价高低顺序，从1开始，行权价从高到低
    int32_t leg3_expdate_seq;         // 成分三合约到期日顺序，从1开始，到期日从近期到远期，仅same_expdate不同时有效
    int64_t leg3_position;            // 成分三持仓数量
    int32_t leg4_type;                // 成分四合约类型，参考OptionsType
    int32_t leg4_side;                // 成分四持仓方向，参考PositionSide
    int32_t leg4_exeprc_seq;          // 成分四行权价高低顺序，从1开始，行权价从高到低
    int32_t leg4_expdate_seq;         // 成分四合约到期日顺序，从1开始，到期日从近期到远期，仅same_expdate不同时有效
    int64_t leg4_position;            // 成分四持仓数量
};

// 微服务通用请求
struct MicroServiceReq {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 function_id;     // 功能号
    char16 tar_sys;         // 目标系统
    char* request_content;  // 请求参数，JSON格式
    int32_t request_len;    // 请求参数数据长度
};

// 微服务通用应答
struct MicroServiceRsp {
    char16 account_id;           // 交易账号，目前是资金账号
    int16_t account_type;        // 交易账号类型，参考AccountType定义
    char8 cust_orgid;            // 机构编码
    char8 cust_branchid;         // 分支编码
    bool call_status;            // 调用结果，成功：true，失败：false
    char16 error_code;           // 错误码
    char256 error_info;          // 错误信息
    char512 error_extra;         // 详细错误信息
    char* response_list_first;   // 返回第一结果集，JSON数组字符串，格式为[{},{},{}]
    int32_t first_list_len;      // 返回第一结果集长度
    char* response_list_second;  // 返回第二结果集，JSON数组字符串，格式为[{},{},{}]
    int32_t second_list_len;     // 返回第二结果集长度
};

// 查询银行账号余额请求
struct BankBalanceReq {
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char4 bank_code;        // 银行代码
};

// 查询银行账号余额应答
struct BankBalanceDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char status;           // 处理结果，'0'已受理，'1'已报，'2'成功，更多请参考BankSecBizStatus定义
    int64_t sno;           // 流水号
    Amt_t fund_bal;        // 银行余额，扩大一万倍
};

// 查询三方存管银行列表请求
struct QueryBankInfoReq {
    int32_t currency_type;  // 货币代码，参考CurrencyType定义，非必传
};

// 三方存管银行列表明细
struct BankInfoDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char16 cust_id;         // 客户代码
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char4 bank_code;        // 银行代码
    char64 bank_name;       // 银行名称
    char64 bankid;          // 银行账号
    char bankpwdflag;       // 密码标识，'0'不需要密码，'1'需要密码
    char qrybankfund;       // 允许查余额，'0'不允许，'1'允许
    char status;            // 存管状态，'0'正常，'1'销户，'2'待银行确认，'4'冻结
    char banktype;          // 银行类型，'0'银证转账银行，'1'三方银行
    char sourcetype;        // 发起方向，'0'证券发起，'1'银行发起，'2'双向发起
    char custodystate;      // 补充存管状态，O:普通 y:非透明移行 z:小额休眠
    char custodyflag;       // 存管状态，'0'未预指定，'1'已预指定
    char confirmflag;       // 确认状态，'0'未确认，'1'已确认
};

// 银证转帐请求
struct BankSecTransferReq {
    int currency_type;   // 货币代码，参考CurrencyType定义
    char4 bank_code;     // 银行代码
    char busi_type;      // 转账方向，'1'银行转证券，'2'证券转银行
    Amt_t fund_effect;   // 转账金额，扩大一万倍
    char16 gm_fund_pwd;  // 资金密码，明文方式
    char16 bank_pwd;     // 银行密码，明文方式
};

// 银证转账应答
struct BankSecTransferRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    int64_t sno;           // 流水号
    char busi_type;        // 业务类型，'1'银行转证券，'2'证券转银行，更多请参考BankSecBizType定义
    Amt_t fund_effect;     // 转账金额，扩大一万倍，银行转证券为转入，值为正，否则为负。
    Amt_t fund_bal;        // 银行余额，扩大一万倍
    char status;           // 处理结果，'0'已受理，'1'已报，'2'成功，更多请参考BankSecBizStatus定义
};

// 查询当日银证转账请求
struct QryBankSecTransferReq {
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    int64_t sno;            // 转账流水号，不送查全部
};

// 当日银证转账数据
struct BankSecTransferDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    int32_t oper_date;      // 转账日期
    int64_t oper_time;      // 转账时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char16 cust_id;         // 客户代码
    char4 bank_code;        // 银行代码
    char32 bank_name;       // 银行名称
    char busi_type;         // 业务类型，'1'银行转证券，'2'证券转银行，更多请参考BankSecBizType定义
    int64_t sno;            // 流水号
    Amt_t fund_effect;      // 转账金额，扩大一万倍
    Amt_t fund_bal;         // 银行余额，扩大一万倍
    char128 remark;         // 备注
    char status;            // 处理结果，'0'已受理，'1'已报，'2'成功，更多请参考BankSecBizStatus定义
    char16 bank_msg_id;     // 外部信息代码
    char128 bank_msg;       // 外部信息内容
    int64_t syserr_id;      // 错误代码，上游系统已不维护此字段，可参考上面两个字段代替，为兼容性保留
};

// 查询银证转账历史请求
struct QryHisBankSecTransferReq {
    int32_t begin_date;     // 起始日期，格式为YYYYMMDD
    int32_t end_date;       // 结束日期，格式为YYYYMMDD
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char qry_direct;        // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
    int32_t query_num;      // 请求行数
    char32 pos_str;         // 定位串，第一次填空
};

// 银证转账历史数据
struct HisBankSecTransferDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char32 pos_str;         // 定位串
    int32_t sys_date;       // 系统日期
    int32_t oper_date;      // 转账日期
    int64_t oper_time;      // 转账时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int64_t sno;            // 流水号
    char16 fund_id;         // 资金账号
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char16 cust_id;         // 客户代码
    char32 cust_name;       // 客户姓名
    char4 bank_code;        // 银行代码
    char32 bank_name;       // 银行名称
    char busi_type;         // 业务类型，'1'银行转证券，'2'证券转银行，更多请参考BankSecBizType定义
    Amt_t fund_effect;      // 转账金额，扩大一万倍
    Amt_t fund_bal;         // 银行余额，扩大一万倍
    char128 remark;         // 备注
    char status;            // 处理结果，'0'已受理，'1'已报，'2'成功，更多请参考BankSecBizStatus定义
    char source_type;       // 发起方向，'0'证券发起，'1'银行发起，'2'双向发起
    char strike_flag;       // 冲正标志，请参考BankSecStrikeFlag定义
    char16 bank_msg_id;     // 外部信息代码
    char128 bank_msg;       // 外部信息内容
    int64_t syserr_id;      // 错误代码
};

// 主辅资金账号之间可用资金划转请求
struct FundAccountTransferReq {
    char8 in_orgid;         // 转入资金账号的机构代码
    char16 in_fund_id;      // 转入资金账号
    char8 out_orgid;        // 转出资金账号的机构代码
    char16 out_fund_id;     // 转出资金账号
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    Amt_t fund_effect;      // 发生金额，扩大一万倍
    char128 remark;         // 备注
};

// 主辅资金账号之间可用资金划转应答
struct FundAccountTransferRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int16_t account_type;  // 交易账号类型，参考AccountType定义
};

// 查询当日主辅资金账号之间资金划转请求
struct QryFundAccountTransferReq {
    char8 brh_id;    // 机构分支
    char16 fund_id;  // 资金账号
};

// 主辅资金划转明细数据
struct FundAccountTransferDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    int32_t sys_date;       // 系统日期
    int32_t oper_date;      // 转账日期
    int64_t oper_time;      // 转账时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    char32 bank_name;       // 银行名称
    char16 digest_id;       // 摘要代码 12103 转入 12103 转出
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    Amt_t fund_effect;      // 转账金额，扩大一万倍
    char128 remark;         // 备注
};

// 查询历史委托请求
struct QryHisOrderReq {
    char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;   // 查询数量
    int32_t begin_date;  // 起始日期，格式为YYYYMMDD
    int32_t end_date;    // 结束日期，格式为YYYYMMDD
    char8 market;        // 交易市场，交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
    char16 stk_code;     // 证券代码，非必传
    char32 order_id;     // 委托编号，非必传
    int32_t order_date;  // 委托日期，非必传
    char qry_direct;     // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 历史委托明细数据
struct HisOrderDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char32 symbol;          // 标的代码，格式为市场.证券ID
    int32_t oper_date;      // 操作日期
    int32_t order_date;     // 委托日期
    char32 trd_flow_id;     // 委托流水号
    char16 cust_id;         // 客户代码
    int16_t currency_type;  // 货币代码，参考CurrencyType定义
    char32 secuid;          // 股东号
    int16_t order_side;     // 委托方向，参考OrderSide定义
    char32 order_id;        // 委托编号
    char32 stk_name;        // 证券名称
    Price_t order_price;    // 委托价格，扩大一万倍
    int64_t order_qty;      // 委托数量
    int64_t oper_time;      // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    Amt_t order_frz_amt;    // 委托金额，扩大一万倍
    int64_t match_qty;      // 成交数量
    Price_t match_price;    // 成交价格，扩大一万倍
    Amt_t match_amt;        // 成交金额，扩大一万倍
    int64_t cancel_qty;     // 撤单数量
    int32_t order_status;   // 委托状态
    char16 seat;            // 委托席位
    char oper_way;          // 操作方式，参考OperWay定义
    int16_t cancel_flag;    // 撤单标志
    int64_t extqty1;        // 对手方资金账号
    char128 remark;         // 备注
    int32_t total_num;      // 数据总条数
	int16_t order_type;     // 订单类型，参考OrderType定义
};

// 查询历史成交请求
struct QryHisTradeReq {
    char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;   // 查询数量
    char32 market;       // 交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
    char32 stk_code;     // 证券代码，非必传
    int32_t begin_date;  // 起始日期，格式为YYYYMMDD
    int32_t end_date;    // 结束日期，格式为YYYYMMDD
    char qry_direct;     // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 历史成交明细数据
struct HisTradeDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char32 symbol;          // 标的代码，格式为市场.证券ID
    char32 busi_flow_id;    // 业务流水号
    char16 cust_id;         // 客户代码
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char32 secuid;          // 股东代码
    char16 main_seat;       // 托管席位
    char16 trd_seat;        // 交易席位
    int16_t stk_property;   // 股份性质，集中清算使用，参考StockProperty定义
    char16 busi_type;       // 业务类别
    char32 busi_name;       // 业务名称
    char32 stk_name;        // 证券名称
    int32_t order_date;     // 委托日期
    char32 apply_code;      // 委托编号
    char32 match_code;      // 成交编号
    char32 match_time;      // 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    Amt_t match_amt;        // 成交金额，扩大一万倍
    int64_t match_qty;      // 成交数量
    Price_t match_price;    // 成交价格，扩大一万倍
    int64_t order_qty;      // 委托数量
    Price_t order_price;    // 委托价格，扩大一万倍
    Amt_t intr_amt;         // 利息金额，扩大一万倍
    char4 stk_type;         // 证券类别
    int16_t order_side;     // 委托方向，参考OrderSide定义
    int32_t oper_date;      // 操作日期
    int32_t match_date;     // 成交日期
    int64_t stk_bal;        // 股份余额
    int32_t total_num;      // 总记录数
	int16_t order_type;     // 订单类型，参考OrderType定义
};

// 查询交割单请求--微服务简化版
struct QryDeliveryOrderReq {
    char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;		// 查询数量
    char qry_direct;		// 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
    int32_t begin_date;		// 起始日期，格式YYYYMMDD
    int32_t end_date;		// 结束日期，格式YYYYMMDD
    char32 market;			// 交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
	char16 stk_code;		// 证券代码，非必传
};

// 交割单明细数据--微服务简化版
struct DeliveryOrderDetail {
    char16 account_id;					// 交易账号，目前是资金账号
    char8 cust_orgid;					// 机构编码
    char8 cust_branchid;				// 分支编码
    int16_t account_type;				// 交易账号类型，参考AccountType定义
    char32 symbol;						// 标的代码，格式为市场.证券ID
    int32_t biz_date;					// 交收日期
    char32 sno;							// 流水号
    char16 busi_type;					// 业务类别
    char32 busi_name;					// 业务名称
    int32_t currency_type;				// 货币代码，参考CurrencyType定义
    char32 stk_name;					// 证券名称
    char32 secuid;						// 股东代码
    char16 main_seat;					// 托管席位
    char16 ta_code;						// ta内部代码
    char32 tran_sacct;					// 交易账号
    char16 ta_acct;						// 基金账号
    int32_t order_date;					// 委托日期
    int64_t order_time;					// 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int16_t order_side;					// 买卖方向，参考OrderSide定义，上游系统将逐步放弃对此字段的维护，
										// 请尽早用busi_type代替。
    char32 apply_code;					// 委托编号
    int64_t order_qty;					// 委托数量
    Price_t order_price;				// 委托价格，扩大一万倍
    int64_t match_time;					// 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int64_t match_qty;					// 成交数量
    Price_t match_price;				// 成交价格，扩大一万倍
    Amt_t match_amt;					// 成交金额，扩大一万倍
    Amt_t fun_deffect;					// 发生金额，扩大一万倍
    Amt_t fund_bal;						// 剩余金额，扩大一万倍
    int64_t stk_effect;					// 股份发生数
    Amt_t stk_bal;						// 股份余额，扩大一万倍
    Amt_t fee_seat;						// 总佣金，扩大一万倍
    Amt_t fee_yjf;						// 净佣金，扩大一万倍
    Amt_t fee_yhs;						// 印花税，扩大一万倍
    Amt_t fee_jsf;						// 经手费，扩大一万倍
    Amt_t fee_ghf;						// 过户费，扩大一万倍
    Amt_t fee_zgf;						// 证管费，扩大一万倍
    Amt_t fee_sxf;						// 手续费，扩大一万倍
    Amt_t fee_qsf;						// 结算费，扩大一万倍
    Amt_t fee_jggf;						// 监管规费，扩大一万倍
    Amt_t fee_other;					// 其他费，扩大一万倍
    Amt_t fee_jsxf;						// 标准手续费，扩大一万倍
    Amt_t fee_jygf;						// 交易规费，扩大一万倍
    Amt_t fee_front;					// 前台费用，扩大一万倍
    int32_t total_num;					// 数据总条数
	ExchangeRatio_t clear_exch_rate;    // 实际汇率
};

// 查询对账单请求--微服务简化版
struct QryStateOrderReq {
    char32 pos_str;					// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;				// 查询数量
    char8 market;					// 交易市场，支持多市场查询，例如"SZ,SZHK"等，非必传
    int32_t begin_date;				// 起始日期，格式为YYYYMMDD
    int32_t end_date;				// 结束日期，格式为YYYYMMDD
    char qry_direct;				// 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
	char16 stk_code;				// 证券代码，非必传
	int16_t currency_type;			// 币种，参考CurrencyType定义，非必传
};

// 对账单明细数据--微服务简化版
struct StateOrderDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char32 symbol;          // 交易标的，格式为市场.证券ID
    int32_t biz_date;       // 业务日期
    int32_t clear_date;     // 清算日期
    char32 sno;             // 流水号
    char16 busi_type;       // 业务类别
    char32 busi_name;       // 业务名称
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char32 stk_name;        // 证券名称
    char32 secuid;          // 股东代码
    char16 main_seat;       // 托管席位
    char16 ta_code;         // ta内部代码
    char32 trans_acct;      // 交易账号
    char16 ta_acct;         // 基金账号
    int32_t order_date;     // 委托日期
    int32_t order_time;     // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int16_t order_side;     // 买卖方向，参考OrderSide定义
    char32 apply_code;      // 委托编号，未清算账号返回的是合同号，已清算账号返回的是委托号
    int64_t order_qty;      // 委托数量
    Price_t order_price;    // 委托价格，扩大一万倍
    int32_t match_time;     // 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    int64_t match_qty;      // 成交数量
    Price_t match_price;    // 成交价格，扩大一万倍
    Amt_t match_amt;        // 成交金额，扩大一万倍
    Amt_t fund_effect;      // 发生金额，扩大一万倍
    Amt_t fund_bal;         // 剩余金额，扩大一万倍
    int64_t stkeff_ect;     // 股份发生数
    Amt_t stk_bal;          // 股份余额，扩大一万倍
    int32_t total_num;      // 数据总条数
};

// 查询交割单(分笔)请求--集中交易，新增集中清算版
struct QueryExchangeListsReq {
	char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;   // 查询数量
	char qry_direct;     // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
	int32_t begin_date;  // 起始日期，格式YYYYMMDD
	int32_t end_date;    // 结束日期，格式YYYYMMDD
};

// 交割单(分笔)明细数据--集中交易，新增集中清算版
struct ExchangeDetail {
	char16 account_id;      // 交易账号，目前是资金账号
	char8 cust_orgid;       // 机构编码
	char8 cust_branchid;    // 分支编码
	int16_t account_type;   // 交易账号类型，参考AccountType定义
	char32 pos_str;         // 定位串
	int32_t clear_date;     // 清算日期
	int32_t biz_date;       // 交收日期
	int32_t order_date;     // 委托日期
	int64_t order_time;     // 委托时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
	int32_t digest_id;      // 摘要代码
	char128 digest_name;    // 摘要代码说明
	int32_t currency_type;  // 货币代码，参考CurrencyType定义
	char32 symbol;          // 标的代码，格式为市场.证券ID
	char32 secuid;          // 股东代码
	char128 cust_name;      // 客户姓名
	char32 order_id;        // 委托编号，合同序号
	char32 sno;             // 流水号 仅集中清算支持
	char32 stk_name;        // 证券名称
	int16_t order_side;     // 买卖方向，参考OrderSide定义
	int64_t match_time;     // 成交时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
	char32 match_code;      // 成交编号 
	int64_t match_times;	// 成交笔数 仅集中交易支持
	int64_t match_qty;      // 成交数量
	Price_t match_price;    // 成交价格，扩大一万倍
	Amt_t match_amt;        // 成交金额，扩大一万倍
	Amt_t clear_amt;        // 清算金额，扩大一万倍
	Amt_t fee_yhs;          // 印花税，扩大一万倍
	Amt_t fee_jsxf;         // 标准手续费，扩大一万倍
	Amt_t fee_sxf;          // 手续费，扩大一万倍
	Amt_t fee_ghf;          // 过户费，扩大一万倍
	Amt_t fee_qsf;          // 清算费，扩大一万倍
	Amt_t fee_jygf;         // 交易规费，扩大一万倍
	Amt_t fee_front;        // 前台费用，扩大一万倍
	Amt_t fee_jsf;          // 经手费，扩大一万倍
	Amt_t fee_zgf;          // 证管费，扩大一万倍
	Amt_t fee_other;        // 其他费，扩大一万倍
	Amt_t fund_bal;         // 资金本次金额，扩大一万倍
	Amt_t stk_bal;          // 股份本次余额，扩大一万倍
	int64_t order_qty;      // 委托数量
	Price_t order_price;    // 委托价格，扩大一万倍
	char source_type;	    // 发起方 '0'-券商，'1'-银行，'2'-双向 仅集中交易支持
	char4 bank_code;        // 外部银行 仅集中交易支持
	char32 bank_id;         // 外部账户 仅集中交易支持
	char32 counter_order_id;// 柜台委托号 
};

// 修改密码请求
struct ModifyPasswordReq {
    char32 old_password;    // 旧密码
    char32 new_password;    // 新密码
    int16_t password_type;  // 密码类型，参考PasswordType定义
};

// 修改密码应答
struct ModifyPasswordRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
};

// 查询配号信息请求 400000201409
struct QueryPHXXReq {
    int64_t query_index;  // 起始行号
    int64_t query_num;    // 查询数量
    char16 stk_code;      // 证券代码，非必传
    char32 secuid;        // 股东代码，非必传
    int32_t begin_date;   // 起始日期，格式为YYYYMMDD，至多T-1日才可能查到数据
    int32_t end_date;     // 结束日期，格式为YYYYMMDD，不能小于起始日期
    char qry_direct;      // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 配号信息明细
struct QueryPHXXRecord {
    char16 account_id;         // 交易账号，目前是资金账号
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    int32_t busi_date;         // 配号日期
    char8 market;              // 市场，如"SZ SH"
    char32 secuid;             // 股东代码
    char32 stk_name;           // 证券名称
    char16 stk_code;           // 证券代码
    int64_t match_qty;         // 成交数量
    char32 mate_no;            // 配售配号
    int16_t currency_type;     // 货币类型，参考CurrencyType定义
    char16 busi_type;          // 业务类型
    char16 link_stk_code;      // 正股代码
    int64_t next_query_index;  // 下次查询索引号
    int64_t total_num;         // 数据总条数
	char issue_stk_type;	   // 品种类型，参考IssueStkType定义
	int32_t order_date;        // 委托日期
};

// 查询中签信息请求 400000201410
struct QueryZQXXReq {
    int64_t query_index;  // 起始行号
    int64_t query_num;    // 查询数量
    char16 stk_code;      // 证券代码，非必传
    char32 secuid;        // 股东代码，非必传
    int32_t begin_date;   // 起始日期，格式为YYYYMMDD，至多T-1日才可能查到数据
    int32_t end_date;     // 结束日期，格式为YYYYMMDD，不能小于起始日期
    char qry_direct;      // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
	char32  market;       // 交易市场，例如"SZ,SZHK"等，非必传
};

// 中签信息明细
struct QueryZQXXRecord {
    char16 account_id;         // 交易账号，目前是资金账号
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    int32_t busi_date;         // 中签日期
    char8 market;              // 市场，SH、SZ等，参考本文件中定义
    char32 secuid;             // 股东代码
    char32 stk_name;           // 证券名称
    char16 stk_code;           // 证券代码
    char4 stk_type;            // 证券类别
    int64_t hit_qty;           // 中签数量
    Price_t match_price;       // 成交价格，扩大一万倍
    int32_t order_date;        // 委托日期
    char32 order_id;           // 委托编号
    char32 mate_no;            // 配售编号
    int16_t currency_type;     // 货币类型，参考CurrencyType定义
    char16 busi_type;          // 业务类型
    int64_t next_query_index;  // 下次查询索引号
    int64_t total_num;         // 数据总条数
	char issue_stk_type;	   // 品种类型，参考IssueStkType定义
};

// 查询锁券合同请求
struct QryLockSecurityContractReq {
    char32 pos_str;     // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;  // 查询的数量，最大支持500个
    char32 symbol;      // 是否根据标的代码查询，格式为市场.证券ID，可不传
    char16 status;      // 是否根据锁券状态组合查询，可不传，目前传值对低延时返回结果无影响，可忽略此字段。
};

// 锁券合同详情
struct LockSecurityContractDetail {
    char16 account_id;         // 交易账号，目前是资金账号
    int16_t account_type;      // 交易账号类型，参考AccountType定义
    char8 cust_orgid;          // 机构编码
    char8 cust_branchid;       // 分支编码
    int32_t sys_date;          // 系统日期
    int32_t begin_date;        // 生效日期
    int32_t close_date;        // 截止日期
    char32 symbol;             // 标的代码，格式为市场.证券ID
    char32 name;               // 证券名称
    char status;               // 锁券状态，低延时柜台无维护，仅供参考。
    char16 secuid;             // 股东号
    int16_t lock_charge_type;  // 锁券收费类型，参考LockChargeType定义
    int16_t first_in_mode;     // 首次进入模式
    int64_t reserve_qty;       // 待分配数量
    int64_t stk_bal;           // 股份锁定总余额
    int64_t stk_avl;           // 股份可用数
    int64_t stk_used_qty;      // 已使用数量
    int64_t stk_sale;          // 当日股份卖出冻结
    int64_t stk_sale_frz;      // 当日卖出占用
    int64_t stk_repay;         // 日间偿还成交
    Ratio_t used_fee_rate;     // 锁券已使用费率，扩大一万倍
    Amt_t used_fee;            // 锁券已使用费，扩大一万倍
    Ratio_t unused_fee_rate;   // 锁券占用费率，扩大一万倍
    Amt_t unused_fee;          // 锁券占用费，扩大一万倍
    Amt_t over_used_fee;       // 逾期锁券使用费，扩大一万倍
    Amt_t over_unused_fee;     // 逾期锁券占用费，扩大一万倍
    Amt_t puni_used_fee;       // 逾期锁券使用费罚息，扩大一万倍
    Amt_t puni_unused_fee;     // 逾期锁券占用费罚息，扩大一万倍
    Ratio_t violate_fee_rate;  // 违约费率，扩大一万倍
    Amt_t violate_fee;         // 违约费，扩大一万倍
    Amt_t over_violate_fee;    // 逾期违约费，扩大一万倍
    Amt_t puni_violate_fee;    // 逾期违约罚息，扩大一万倍
    char16 cust_id;            // 客户代码
};

// 信用合同详情
struct CreditContractDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    Ratio_t f_credit_rate;    // 融资年利率，扩大一万倍
    Amt_t f_year_mg_fee;      // 融资管理费率，扩大一万倍
    Amt_t f_year_sr_fee;      // 融资承诺费率，扩大一万倍
    Ratio_t d_credit_rate;    // 融券年利率，扩大一万倍
    Amt_t d_year_mg_fee;      // 融券管理费率，扩大一万倍
    Amt_t d_year_sr_fee;      // 融券承诺费率，扩大一万倍
    int32_t cancel_date;      // 合同实际终止日期，格式为YYYYMMDD
    int16_t currency_type;    // 货币类型，参考CurrencyType定义
    int32_t contract_limit;   // 合同期限
    int32_t contract_status;  // 合约状态，参考CreditContractStatus定义
    int32_t begin_date;       // 起始日期
    int32_t end_date;         // 结束日期
    Ratio_t f_prate;          // 融资罚息年利率，扩大一万倍
    Ratio_t d_prate;          // 融券罚息年利率，扩大一万倍
	char32 contract_id;       // 合同编号，目前低延时两融支持
};

// 查询融资融券合约汇总信息请求
struct QryCreditDebtsCollectReq {
    char32 pos_str;     // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;  // 查询的数量，最大支持500个
    char32 symbol;      // 是否根据标的代码查询，格式为市场.证券ID，可不传
};

// 融资融券合约汇总信息详情
struct CreditDebtsCollectDetail {
	char16 account_id;			// 交易账号，目前是资金账号
	int16_t account_type;		// 交易账号类型，参考AccountType定义
	char8 cust_orgid;			// 机构编码
	char8 cust_branchid;		// 分支编码
	int16_t currency_type;		// 货币类型，参考CurrencyType定义
	char32 symbol;				// 标的代码，格式为市场.证券ID
	char32 name;				// 证券名称
	Amt_t match_amt;			// 成交金额，扩大一万倍
	int64_t match_qty;			// 成交数量
	Amt_t credit_repay;			// T日之前归还金额，扩大一万倍
	int64_t stk_repay;			// T日之前归还数量
	Amt_t credit_repay_unfrz;	// T日归还金额，扩大一万倍
	int64_t stk_repay_unfrz;	// T日归还数量
	Amt_t credit_bal;			// 剩余融资金额，扩大一万倍
	int64_t stk_bal;			// 剩余融券数量
	Price_t last_price;			// 最新价，扩大一万倍
	Amt_t market_value;			// 剩余负债市值，扩大一万倍
	Amt_t credit_avl;			// 剩余融券卖出资金，扩大一万倍
	Amt_t debts_profit;			// 浮动盈亏，扩大一万倍
	Amt_t adjust_profit;		// 矫正盈亏，扩大一万倍
	Amt_t credit_fee;			// 融资利息或融券费用，扩大一万倍
	int64_t stk_debts_avl;		// 当日可偿还融券数量 
};

// 查询融资融券信用数据请求
struct QryCreditDataReq {
    char32 symbol;       // 标的代码查询，格式为市场.证券ID
    char credit_direct;  // 信用方向，'0'融资，'1'融券，参考CreditDirect定义
};

// 融资融券信用数据详情
struct CreditDataDetail {
    char16 account_id;             // 交易账号，目前是资金账号
    int16_t account_type;          // 交易账号类型，参考AccountType定义
    char8 cust_orgid;              // 机构编码
    char8 cust_branchid;           // 分支编码
    int16_t currency_type;         // 货币类型，参考CurrencyType定义
    char32 symbol;                 // 标的代码，格式为市场.证券ID
    char32 name;                   // 证券名称
    char credit_direct;            // 信用方向，'0'融资，'1'融券，参考CreditDirect定义
    Amt_t margin_avl;              // 保证金可用余额，扩大一万倍
    Amt_t credit_bal;              // 融资/融券授信额度，扩大一万倍
    Amt_t credit_avl;              // 融资/融券可用的额度，扩大一万倍
    Ratio_t margin_rate;           // 融资/融券保证金比例，扩大一万倍
    Amt_t debts_bal;               // 应付融资款/应付融券市值，扩大一万倍
    Amt_t max_amt;                 // 最大融资/融券金额，扩大一万倍
    Amt_t fund_avl;                // 资金可用数，扩大一万倍
    Amt_t credit_fund_avl;         // 融券卖出资金，扩大一万倍
    Amt_t g_dis_market_avl;        // 担保证券的折算价值，扩大一万倍
    Amt_t mar_stk_val;             // ∑(充抵保证金的证券市值(不含融资买入数量)*折算率)，扩大一万倍
    Amt_t total_dis_f_mk_val;      // ∑融资的市值*折算率，扩大一万倍
    Amt_t mar_fund_profit;         // ∑融资盈亏*折算率，扩大一万倍
    Amt_t mar_stk_profit;          // ∑融券盈亏*折算率，扩大一万倍
    Amt_t total_rate_f_debts_bal;  // ∑融资金额*融资保证金比例，扩大一万倍
    Amt_t mar_fund_margin;         // 已占用融资保证金，扩大一万倍
    Amt_t mar_fund_margin_frz;     // 委托冻结融资保证金，扩大一万倍
    Amt_t total_rate_d_sale_bal;   // ∑融券市值*融券保证金比例，扩大一万倍
    Amt_t mar_stk_margin;          // 已占用融券保证金，扩大一万倍
    Amt_t mar_stk_margin_frz;      // 委托冻结融券保证金，扩大一万倍
    Amt_t total_fee;               // 利息和费用总和，扩大一万倍
};

// 查询信用预到期合约请求
struct QryPreMaturityDebtsReq {
    char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;   // 查询的数量，最大支持500个
    int32_t begin_date;  // 开始日期，格式为YYYYMMDD，可不传
    int32_t end_date;    // 结束日期，格式为YYYYMMDD，可不传
    char32 symbol;       // 标的代码，格式为市场.证券ID，可不传
};

// 信用预到期合约详情
struct PreMaturityDebtsDetail {
    char16 account_id;       // 交易账号，目前是资金账号
    int16_t account_type;    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;        // 机构编码
    char8 cust_branchid;     // 分支编码
    char32 symbol;           // 标的代码，格式为市场.证券ID
    char32 name;             // 证券名称
    char16 secuid;           // 股东号
    int16_t currency_type;   // 货币类型，参考CurrencyType定义
    char credit_direct;      // 信用方向，'0'融资，'1'融券，参考CreditDirect定义
    int16_t life_status;     // 信用合约状态，参考ContractLifeStatus定义
    int32_t sys_date;        // 负债发生的系统日期，格式为YYYYMMDD
    char32 sno;              // 合约编号
    char32 order_id;         // 委托序号
    int32_t order_date;      // 委托日期，格式为YYYYMMDD
    int64_t match_qty;       // 成交数量
    Amt_t match_amt;         // 成交金额，扩大一万倍
    Amt_t leave_amt;         // 剩余金额，扩大一万倍
    int64_t leave_qty;       // 剩余数量
    Amt_t all_fee;           // 息费总和，扩大一万倍
    int16_t apply_status;    // 申请状态，参考ApplyStatus定义
    int32_t apply_date;      // 申请日期，格式为YYYYMMDD
    char32 apply_sno;        // 申请编号
    int32_t apply_end_date;  // 申请时的合约到期日，格式为YYYYMMDD
    int32_t oper_date;       // 操作日期，格式为YYYYMMDD
    int32_t oper_time;       // 操作时间，格式为HHMMSSmmm
    char128 chk_remark;      // 复核意见
};

// 信用预到期合约展期请求
struct ExtendPreMaturityDebtsReq {
    int32_t sys_date;  // 负债发生的系统日期，格式为YYYYMMDD
    char32 sno;        // 合约编号
};

// 信用预到期合约展期应答
struct ExtendPreMaturityDebtsRsp {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int32_t apply_date;    // 申请日期，格式为YYYYMMDD
    char32 apply_sno;      // 申请流水号
};

// 查询信用预到期合约展期请求
struct QryPreMaturityDebtsExtensionReq {
    char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;   // 查询的数量，最大支持500个
    int32_t begin_date;  // 开始日期，格式为YYYYMMDD，可不传，低延时为开始日期，顶点两融为发生日期，定值查询
    int32_t end_date;    // 结束日期，格式为YYYYMMDD，可不传，仅低延时支持
    char32 symbol;       // 标的代码，格式为市场.证券ID，低延时支持，取前半部分市场以获取股东代码用。
};

// 信用预到期合约展期详情
struct PreMaturityDebtsExtensionDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    char32 symbol;          // 标的代码，格式为市场.证券ID
    char32 name;            // 证券名称
    char16 secuid;          // 股东号
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    char credit_direct;     // 信用方向，'0'融资，'1'融券，参考CreditDirect定义
    int16_t life_status;    // 信用合约状态，参考ContractLifeStatus定义
    int16_t apply_status;   // 申请状态，参考ApplyStatus定义
    int32_t sys_date;       // 系统日期，格式为YYYYMMDD
    int32_t apply_date;     // 申请日期，格式为YYYYMMDD
    char32 apply_sno;       // 申请编号
    char32 sno;             // 合约编号
    int32_t order_date;     // 委托日期，格式为YYYYMMDD
    char32 order_id;        // 委托序号
    int64_t match_qty;      // 成交数量
    Amt_t match_amt;        // 成交金额，扩大一万倍
    Amt_t leave_amt;        // 剩余金额，扩大一万倍
    Amt_t leave_value;      // 剩余市值，扩大一万倍
    char128 chk_remark;     // 复核意见
    char256 cfm_ans;        // 备注
    int64_t leave_qty;      // 剩余数量，低延时暂时未启用
};

// 查询网络投票议案请求
struct QryVoteProposalReq {
    char32 symbol;       // 基础证券代码，格式为市场.证券ID
    char32 vote_symbol;  // 投票代码，格式为市场.证券ID
};

// 网络投票议案详情
struct VoteProposalDetail {
    char16 account_id;              // 交易账号，目前是资金账号
    int16_t account_type;           // 交易账号类型，参考AccountType定义
    char8 cust_orgid;               // 机构编码
    char8 cust_branchid;            // 分支编码
    char32 symbol;                  // 标的代码，格式为市场.证券ID
    char32 name;                    // 证券名称
    char32 vote_symbol;             // 投票代码，格式为市场.证券ID
    char32 vote_name;               // 投票简称
    int32_t begin_date;             // 股东大会开始日，格式为YYYYMMDD
    int32_t end_date;               // 股东大会结束日，格式为YYYYMMDD
    char40 meeting_type;            // 股东大会类型
    char512 meeting_desc;           // 股东大会名称
    char32 meeting_seq;             // 股东大会编码
    char16 voting_proposal_code;    // 投票议案编号
    char1024 voting_prososal_desc;  // 投票议案名称
    char voting_proposal_type;      // 议案类型  L-累积议案 P-普通议案
    int64_t cum_voting_chosen_num;  // 累计投票应选数
    char64 share_holder_role;       // 股东身份
    char128 proposal_relation;      // 议案关系
    char32 share_class;             // 股份类别
	int32_t reg_date;				// 股权登记日，格式为YYYYMMDD
};

// 查询信用投票可投票数请求
struct QryCreditVoteCountReq {
    char32 symbol;           // 标的代码，格式为市场.证券ID 证券代码必填
    char32 meeting_seq;      // 股东大会编号，必填
    char16 voting_proposal;  // 投票议案编号，必填
};

// 查询信用投票可投票数应答
struct CreditVoteCountDetail {
    char16 account_id;       // 交易账号，目前是资金账号
    int16_t account_type;    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;        // 机构编码
    char8 cust_branchid;     // 分支编码
    char32 symbol;           // 标的代码，格式为市场.证券ID
    char16 voting_proposal;  // 投票议案编号
    int64_t rest_qty;        // 可投票数
    char32 stk_name;         // 证券简称
};

// 查询信用投票结果请求
struct QryCreditVoteReq {
    char32 pos_str;          // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;       // 查询的数量，最大支持500个
    char16 code;             // 是否根据证券代码查询，可不传
    char16 voting_proposal;  // 是否根据投票议案编号查询，可不传
};

// 信用投票结果
struct CreditVoteDetail {
    char16 account_id;          // 交易账号，目前是资金账号
    int16_t account_type;       // 交易账号类型，参考AccountType定义
    char8 cust_orgid;           // 机构编码
    char8 cust_branchid;        // 分支编码
    char32 symbol;              // 投票代码，格式为市场.证券ID
    char16 secuid;              // 证券账户(股东代码)
    int32_t sys_date;           // 系统日期，格式为YYYYMMDD
    int32_t oper_date;          // 发生日期，格式为YYYYMMDD
    int32_t oper_time;          // 发生时间，格式HHMMSSmmm，首位为0不显示
    char16 link_symbol;         // 关联标的代码，格式为市场.证券ID
    char16 voting_proposal;     // 投票议案
    int16_t voting_preference;  // 投票意向，参考VotingPreference定义
    Amt_t stk_bal;              // 股份余额，扩大一万倍
    char32 stk_name;            // 证券简称
    char32 link_stk_name;       // 关联证券简称
    char32 meeting_seq;             // 股东大会编码
    char512 meeting_desc;           // 股东大会名称
    char voting_proposal_type;      // 议案类型  L-累积议案 P-普通议案
    char1024 voting_prososal_desc;  // 投票议案名称
	char32 key_error_code;			// 关键错误码
	char512 key_error_msg;			// 订单拒绝原因描述
};

// 查询网络投票客户权益请求
struct QryNetVoteRightsReq {
    char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;      // 查询数量 必填
    char32  market;         // 交易市场，支持多市场查询，例如"SZ,SZHK"等，后续版本非必传
    char16 stk_code;        // 证券代码，必传，后续版本非必传
};

// 网络投票客户权益明细
struct NetVoteRightsDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    char16 cust_id;           // 客户代码
    char32 secuid;            // 股东代码
    char32 symbol;            // 证券代码，格式为市场.证券ID
    char32 name;              // 证券名称
    char32 meeting_seq;       // 股东大会编码
    int32_t reg_date;         // 股权登记日，格式为YYYYMMDD
    char16 voting_proposal;   // 投票议案编号
    char128 voting_relation;  // 议案关系
    int32_t total_num;        // 数据总条数
};

// 查询网络投票结果请求
struct QryNetVoteResultReq {
	char32 pos_str;			// 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;		// 查询数量 必填
	int32_t begin_date;		// 起始日期，格式为YYYYMMDD 必填
	int32_t end_date;		// 截止日期，格式为YYYYMMDD 必填
	char32  market;			// 交易市场，交易已切支持多市场查询，例如"SZ,SZHK"等，非必传
							// 交易未切只支持单市场查询，例如"SZ"或者"SH"等，必传
	char16 vote_code;		// 证券代码，非必传
};

// 网络投票结果明细
struct NetVoteResultDetail {
    char16 account_id;       // 交易账号，目前是资金账号
    int16_t account_type;    // 交易账号类型，参考AccountType定义
    char8 cust_orgid;        // 机构编码
    char8 cust_branchid;     // 分支编码
    int32_t busi_date;       // 业务日期，格式为YYYYMMDD
    char32 contract_id;      // 合同序号
    char32 vote_symbol;      // 标的代码，格式为市场.证券ID
    char32 meeting_seq;      // 股东大会编码
    char16 cust_id;          // 客户代码
    char16 fund_id;          // 资金账号
    char32 secuid;           // 股东代码
    int64_t vote_qty;        // 投票结果(日终)
    int64_t cur_vote_qty;    // 投票结果(实时)
    char16 voting_proposal;  // 投票议案编号
    char128 vote_info;       // 议案信息
    char vote_type;          // 议案类型 L-累积议案 P-普通议案
    int32_t total_num;       // 数据总条数
    char32 vote_name;        // 证券名称
};

// 查询网络投票可投票数量请求
struct QryNetVoteCountReq {
    char32 secuid;           // 股东代码
    char32 symbol;           // 证券代码，格式为市场.证券ID
	char32 vote_code;        // 投票代码      
	int32_t reg_date;        // 投票股权登记日，格式为YYYYMMDD
};

// 网络投票可投票数量明细
struct NetVoteCountDetail {
    char16 account_id;     // 交易账号，目前是资金账号
    int16_t account_type;  // 交易账号类型，参考AccountType定义
    char8 cust_orgid;      // 机构编码
    char8 cust_branchid;   // 分支编码
    int64_t vote_qty;      // 可投票数量
};

// 查询当日负债流水请求
struct QryCreditDebtsFlowReq {
	char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;      // 查询的数量
	int16_t currency_type;  // 货币类型，参考CurrencyType定义
};

// 负债流水明细
struct CreditDebtsFlowDetail {
    char16 account_id;        // 交易账号，目前是资金账号
    int16_t account_type;     // 交易账号类型，参考AccountType定义
    char8 cust_orgid;         // 机构编码
    char8 cust_branchid;      // 分支编码
    int16_t currency_type;    // 货币类型，参考CurrencyType定义
    char debt_type;           // 负债类型，参考CreditDebtsType定义
    char effect_direct;       // 发生方向，参考DebtsOccurDirect定义
    char repay_way;           // 偿还方式，参考RepayWay定义
    char16 stk_code;          // 证券代码
    char32 stk_name;          // 证券简称
    char32 details_sno;       // 流水号
    int32_t relate_sys_date;  // 负债发生日期
    char32 relate_sno;        // 委托号
    int32_t market_id;        // 交易市场，参考MarketType定义
    Amt_t fund_effect;        // 负债资金金额，扩大一万倍
    int64_t stk_effect;       // 负债股份数量
};

// 查询当日资金流水请求
struct QryCreditAssetFlowReq {
	char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;      // 查询的数量
};

// 资金流水明细
struct CreditAssetFlowDetail {
    char16 account_id;          // 交易账号，目前是资金账号
    int16_t account_type;       // 交易账号类型，参考AccountType定义
    char8 cust_orgid;           // 机构编码
    char8 cust_branchid;        // 分支编码
    int32_t biz_date;           // 系统日期
    char32 details_sno;         // 资金流水号
    int32_t oper_date;          // 发生日期，格式为YYYYMMDD
    int32_t oper_time;          // 发生时间，格式为HHMMSSmmm，首位为0不显示
    int32_t digest_id;          // 摘要代码ID
    char128 digest_name;        // 摘要代码名称
    int16_t currency_type;      // 货币类型，参考CurrencyType定义
    char32 secuid;              // 股东代码
    int32_t market_id;          // 交易市场，参考MarketType定义
    Amt_t fund_effect;          // 资金发生金额，金额扩大一万倍
    Amt_t fund_bal;             // 资金本次余额，金额扩大一万倍
    int64_t stk_bal;            // 股份本次余额
    char16 stk_code;            // 证券代码
    char32 stk_name;            // 证券简称
    char16 busi_type;           // 业务类型，目前仅低延时柜台有此字段
    int16_t side;               // 买卖方向，参考OrderSide定义，
    Price_t match_price;        // 成交价格，价格扩大一万倍
    int64_t match_qty;          // 成交数量
    Amt_t match_amt;            // 成交金额，金额扩大一万倍
    char32 order_id;            // 柜台订单id，目前仅低延时柜台有此字段
    char32 pos_str;             // 定位串
};

// 查询信用客户融资融券合约请求
struct QueryCreditDebtsReq {
    char credit_direct;     // 信用方向，'0'融资，'1'融券，参考CreditDirect定义，非必传
    char qry_direct;        // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
    int32_t sys_date;       // 系统日期，格式为YYYYMMDD，非必传
    char32 sno;             // 合约编号，非必传
    int16_t currency_type;  // 货币类型，请参考CurrencyType，非必传
    char32 symbol;          // 标的代码，格式为市场.证券ID，非必传
    char32 pos_str;         // 定位串
    int32_t query_num;      // 指定查询返回数量
};

// 查询信用客户融资融券合约明细
struct CreditDebtsDetail {
    char16 account_id;            // 交易账号，目前是资金账号
    int16_t account_type;         // 交易账号类型，参考AccountType定义
    char8 cust_orgid;             // 机构编码
    char8 cust_branchid;          // 分支编码
    int32_t sys_date;             // 负债发生系统日期
    int32_t end_date;             // 负债截止日期
    char32 sno;                   // 合约编号
    int16_t currency_type;        // 币种
    char32 symbol;                // 标的代码，格式为市场.证券ID
    char32 security_symbol;       // 证券简称
    int32_t order_date;           // 合约委托日期
    int64_t order_id;             // 合约委托序号
    char16 secuid;                // 证券账户(股东代码)
    int16_t life_status;          // 合约状态
    int64_t d_stk_bal;            // 融资数量(当前融资数量)||应偿还融券总数量
    Amt_t f_deal_bal;             // 应付融资款余额 || 融券未偿还金额，金额扩大一万倍
    Amt_t f_deal_avl;             // 应付融资款的当前数 || 当前融券未偿还金额，金额扩大一万倍
    Price_t init_cost_price;      // 初始成本价格，价格扩大一万倍
    Price_t prof_cost_price;      // 盈亏成本价格，价格扩大一万倍
    Amt_t profit_cost;            // 浮动盈亏，金额扩大一万倍
    int64_t stk_repay_unfrz;      // 当日归还数量
    Amt_t fee_unfrz;              // 当日息费偿还总额，金额扩大一万倍
    Amt_t over_due_fee_unfrz;     // 融资逾期利息或融券逾期费用当日偿还部分，金额扩大一万倍
    Amt_t puni_fee_unfrz;         // 逾期息费罚息当日偿还部分，金额扩大一万倍
    Amt_t over_due_rights_unfrz;  // 融券逾期权益当日偿还部分，金额扩大一万倍
    Amt_t puni_rights_unfrz;      // 逾期权益罚息当日偿还部分，金额扩大一万倍
    Amt_t puni_debts_unfrz;       // 逾期本金罚息当日偿还部分，金额扩大一万倍
    Amt_t all_fee_unfrz;          // 偿还息费总额，金额扩大一万倍
    Amt_t relese_amt;             // 累计已释放金额（毛），金额扩大一万倍
    Amt_t relese_amt_unfrz;       // 当日已释放金额（毛），金额扩大一万倍
    Amt_t credit_repay_unfrz;     // 当日归还金额，金额扩大一万倍
    Amt_t f_exp_cet_intr;         // 融资利息及费用，金额扩大一万倍
    Amt_t f_debt_qty;             // 融资股份余额
    int64_t d_stk_avl;            // 应偿还融券当前数量
    Price_t last_price;           // 最新价，价格扩大一万倍
    Amt_t mkt_val;                // 最新市值，金额扩大一万倍
    Amt_t buy_cost;               // 融券成本，金额扩大一万倍
    Amt_t exp_cet_intr;           // 融券费用，金额扩大一万倍
    char32 pos_str;               // 定位串
    char credit_direct;           // 信用方向，'0'融资，'1'融券，参考CreditDirect定义
    int64_t match_qty;            // 成交数量
    int64_t stk_repay;            // T日之前归还数量
    Amt_t clear_amt;              // 清算金额，扩大一万倍
    Amt_t credit_repay;           // T日之前归还金额，扩大一万倍
};

// 股票集中度查询
struct StkConcentrationReq {
	char64 query_index;   // 起始行号，填""表示从头开始查
	int32_t query_num;    // 查询数量，填0表示不指定
	char16 symbol;		  // 证券代码，格式为市场.证券ID，填空查所有
	char8 market;         // 市场，如"SZ SH"
};

// 股票集中度明细
struct StkConcentrationDetail {
	int32_t market_id;			// 交易市场，参考MarketType定义
	char16 symbol;          	// 证券代码，格式为市场.证券ID
	char32 name;          		// 证券名称
	int64_t keep_rate_begin;  	// 维保控制起始值，扩大一万倍
	int64_t keep_rate_end;  	// 维保控制结束值，扩大一万倍
	int64_t debt_begin;			// 总负债起始值，扩大一万倍
	int64_t debt_end;			// 总负债结束值，扩大一万倍
	int64_t ctrl_rate;			// 控制比例，扩大一万倍
};

// 查询股票期权保证金风险度明细
struct MarginRiskDetail {
    char16 account_id;          // 交易账号，目前是资金账号
    int16_t account_type;       // 交易账号类型，参考AccountType定义
    char8 cust_orgid;           // 机构编码
    char8 cust_branchid;        // 分支编码
    Ratio_t rt_risk_rate;       // 实时公司风险率，扩大一万倍
};

// 查询沪港通历史委托明细请求
struct QryHKHisOrderReq {
    char32 pos_str;      // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;   // 查询数量
    int32_t begin_date;  // 起始日期，格式为YYYYMMDD
    int32_t end_date;    // 结束日期，格式为YYYYMMDD
    char32 market;       // 交易市场，为空默认查深港通和沪港通
    char32 secuid;       // 股东代码，非必传
    char16 stk_code;     // 证券代码，非必传
    char32 order_id;     // 委托编号，非必传
    char4 bank_code;     // 银行代码，非必传
    char qry_direct;     // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 沪港通历史委托明细数据
struct HKHisOrderDetail {
    char16 account_id;				// 交易账号，目前是资金账号
    char8 cust_orgid;				// 机构编码
    char8 cust_branchid;			// 分支编码
    int16_t account_type;			// 交易账号类型，参考AccountType定义
    int32_t sys_date;				// 系统日期，格式为YYYYMMDD
    char32 trd_flow_id;				// 流水号
    char32 order_id;				// 委托编号
    int32_t order_status;			// 委托状态
    int16_t currency_type;			// 货币代码，参考CurrencyType定义
    char32 symbol;					// 标的代码，格式为市场.证券ID
    char32 secuid;					// 股东代码
    int64_t order_qty;				// 委托数量
    Price_t order_price;			// 委托价格，扩大一万倍
    Amt_t order_frz_amt;			// 委托金额，扩大一万倍
    Amt_t trade_fee;				// 交易费用，扩大一万倍
    Amt_t settle_fee;				// 结算费用，扩大一万倍
    Price_t net_price;				// 债券净价，扩大一万倍。
    Ratio_t return_rate;			// 到期收益率
    Amt_t total_bond_intr;			// 债券总应计利息，扩大一万倍。
    int32_t settle_days;			// 交收天数
    int32_t end_order_date;			// 到期交易日期
    int32_t settle_date;			// 结算日期
    int16_t settle_mode;			// 结算模式，参考SettleMode定义
    int16_t price_type;				// 报价方式，参考QuoteMode定义
    int16_t match_type;				// 成交方式，参考MatchMode定义
    char32 stk_name;				// 证券名称
    int32_t oper_date;				// 操作日期
    int64_t oper_time;				// 操作时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    Price_t match_price;			// 成交价格，扩大一万倍
    int64_t match_qty;				// 成交数量
    int64_t cancel_qty;				// 撤单数量
    int16_t order_side;				// 买卖方向，参考OrderSide定义
    char32 contract_sno;			// 约定合约号
	ExchangeRatio_t refer_rate;     // 参考汇率，扩大一亿倍
    char32 pos_str;					// 查询定位串
    int32_t total_num;				// 数据总条数
    char32 main_seat;				// 托管席位
    Amt_t match_amt;				// 成交金额
    char256 remark;					// 备注
    int64_t report_time;			// 报盘时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
    char16 cust_id;					// 客户代码
    char128 cust_name;				// 客户姓名
};

// 查询可取资金请求
struct QueryWithdrawCashReq {
	char8 market;           // 市场，君睿柜台一户两地时使用，查对应市场的可取资金
							// 传SH或SZ是查上海或深圳的可取资金，大小写不敏感，默认设置为空查两地汇总的可取资金
};

// 可取资金明细数据
struct WithdrawCashRecord {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    int16_t currency_type;  // 货币类型，参考CurrencyType定义
    Amt_t total_asset;      // 资产总值，扩大一万倍
    Amt_t fund_bal;         // 资金余额，扩大一万倍
    Amt_t fund_avl;         // 可用余额，扩大一万倍
    Amt_t fetch_bal;        // 可取余额，扩大一万倍
};

// 根据定位串查询请求
struct QryTradeListTotalReq {
	char32 pos_str;       // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
	int32_t query_num;    // 查询的数量，最大支持500个

	char32 order_id;      // 柜台订单id,选填
	char8 market;		  // 市场，港股通必填，深港通传SZHK，沪港通传SHHK，A股选填
	char32 stkcode;       // 标的代码，例如600000,选填
};

// 查询网络投票委托请求
struct QryNetVoteOrderReq {
    char32 market;                  // 交易市场，如 "SZ" 或者 "SH"
    char32 meeting_seq;             // 股东大会编码，非必传
    char16 voting_proposal_code;    // 投票议案编号，非必传
    char16 stock_code;              // 证券代码，证券ID，非必传
    char32 pos_str;					// 定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;				// 每页查询数量，最大支持500个
};

// 网络投票委托详情
struct NetVoteOrderDetail {
    char16 account_id;              // 交易账号，目前是资金账号
    int16_t account_type;           // 交易账号类型，参考AccountType定义
    char8 cust_orgid;               // 机构编码
    char8 cust_branchid;            // 分支编码
    int64_t order_id;               // 委托序号
    int64_t order_group;            // 批量委托批号
    char32 contract_id;             // 合同序号
    int32_t order_date;             // 委托日期
    char16 cust_id;                 // 客户代码
    char128 cust_name;              // 客户姓名
    int32_t currency_type;          // 货币代码，参考CurrencyType定义
    char32 symbol;                  // 标的代码，格式为市场.证券ID
    char32 name;                    // 证券名称
    char16 seat;                    // 报盘席位
    int16_t stktype;                // 证券类型，参考StkType定义
    int16_t side;                   // 买卖方向，参考OrderSide定义
    char32 meeting_seq;             // 股东大会编码
    char16 voting_proposal_code;    // 投票议案编号
    int64_t voting_preference;      // 投票数量，对于非累积投票制，为投票意向，1代表同意，2代表反对，3代表弃权；
                                    // 对于累积投票制，为投票票数。其中港结算为汇总选举票数。
    char8 voting_segment;           // 分段统计段号（预留）
    int64_t total_qty;              // 总股份数量
    int32_t counter_order_time;     // 申报时间，格式为HHMMSSmmm
    int16_t order_status;           // 订单状态，参考OrderStatus定义
    char32 secuid;                  // 股东代码
    char256 remark;                 // 备注
};

// ETF 认购 撤单的请求
struct ETFSubscriptCancelReq {
	int32_t		order_date;         // 委托日期，格式为YYYYMMDD
	char32		order_id;			// dyc_v2 柜台委托号, jzjy 流水号 sno
	char32		cl_order_id;		// 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
	char32		cl_cancel_id;		// 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
};

// ETF 认购 撤单的应答
struct ETFSubscriptCancelRsp {
	char16 account_id;				// 交易账号，目前是资金账号
	int16_t account_type;			// 交易账号类型，参考AccountType定义
	char8 cust_orgid;				// 机构编码
	char8 cust_branchid;			// 分支编码

	int32_t		order_date;         // 委托日期，格式为YYYYMMDD
	char32		order_id;			// dyc_v2 柜台委托号, jzjy 流水号 sno
	char32		cl_order_id;		// 客户端订单id，用来引用一个普通订单，由用户自定义，可不传
	char32		cl_cancel_id;		// 客户端撤单id，用来引用一个撤单订单，由用户自定义，可不传
};

// 网络投票委托请求
struct NetVoteOrderReq {
    char32 symbol;              // 投票代码，格式为市场.证券ID
	char16 link_stk_code;       // 正股代码
    int64_t order_qty;          // 申报数量，扩大100倍，累计议案必填，普通议案填0
	int32_t reg_date;			// 投票股权登记日，格式为YYYYMMDD
    char32 meeting_seq;         // 股东大会编号
    char16 voting_proposal;     // 投票议案编号
    int16_t voting_preference;  // 投票意向，参考VotingPreference定义
                                // 普通议案必填同意，反对，弃权三者之一，
                                // 累计议案低延时账号可不填，集中交易账号填同意。
	char8 voting_segment;       // 分段统计段号（预留），非必填
};

// 网络投票委托应答
struct NetVoteOrderRsp {
    char16 account_id;      // 交易账号，目前是资金账号
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
	char32 contract_id;		// 申报合同号
    int64_t order_sno;      // 客户订单号
	int16_t order_status;   // 订单状态，参考OrderStatus定义
	int64_t report_time;    // 回报时间，精确到毫秒，格式HHMMSSmmm，首位为0不显示
	char16 cust_id;			// 客户代码
	char32 secuid;			// 股东代码
	char32 symbol;          // 投票代码，格式为市场.证券ID
	char16 reject_code;		// 拒绝代码
	char128 reject_msg;		// 拒绝原因
	int32_t order_group;    // 委托批号，集中交易柜台特有
};

// 信用投票委托请求
struct CreditNetVoteOrderReq {
	char32 symbol;              // 投票代码，格式为市场.证券ID
	char16 link_stk_code;       // 正股代码
	int32_t reg_date;			// 投票股权登记日，格式为YYYYMMDD
	int16_t currency_type;      // 币种，参考CurrencyType定义
	int64_t order_qty;          // 申报数量，扩大100倍，累计议案必填，普通议案填0
	char32 meeting_seq;         // 股东大会编号
	char16 voting_proposal;     // 投票议案编号
	int16_t voting_preference;  // 投票意向，参考VotingPreference定义
								// 普通议案必填同意，反对，弃权三者之一，
								// 累计议案低延时账号可不填，集中交易账号填同意。
};

// 信用投票委托应答
struct CreditNetVoteOrderRsp {
	char16 account_id;			// 交易账号，目前是资金账号
	int16_t account_type;		// 交易账号类型，参考AccountType定义
	char8 cust_orgid;			// 机构编码
	char8 cust_branchid;		// 分支编码
	char16 reject_code;			// 拒绝代码
	char128 reject_msg;			// 拒绝原因
	char8 level;				// 等级
	char16 cust_id;				// 客户代码
	char32 secuid;				// 股东代码
	char32 symbol;              // 投票代码，格式为市场.证券ID
};

// 客户资金查询请求，微服务渠道 
struct QueryMSCashReq {
    char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;      // 查询数量
    char qry_direct;        // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 客户资金明细记录
struct MSCashDetail {
    char16 account_id;      // 交易账号，目前是资金账号
    char8 cust_orgid;       // 机构编码
    char8 cust_branchid;    // 分支编码
    int16_t account_type;   // 交易账号类型，参考AccountType定义
    char32 pos_str;         // 定位串
    int32_t busidate;       // 业务日期，格式为YYYYMMDD 
    char32 custid;          // 结算单元  
    char32 fundunit;        // 资金单元  
    int32_t currency_type;  // 货币代码，参考CurrencyType定义
    char64 subjectcode;     // 科目代码  
    char64 settbody;        // 结算主体  
    char32 orgid;           // 部门编号  
    char32 brhid;           // 机构分支  
    char8 trdsysid;         // 投资系统  
    char32 coreid;          // 核心号  
    char32 fundid;          // 资金账号  
    char256 subjectname;    // 科目名称 
    Amt_t startbal;         // 期初余额  
    Amt_t endbal;           // 期末余额  
    Amt_t fundrealcommit;   // 实际交收金额
    Amt_t awardamt;         // 利息积数  
    Amt_t punishamt;        // 罚息积数  
    int64_t totalnum;       // 总记录数
};

// 客户持仓查询请求，微服务渠道 
struct QueryMSPositionsReq {
    char32 pos_str;         // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;      // 查询数量
    char qry_direct;        // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 客户持仓明细记录
struct MSPositionsDetail {
    char16 account_id;                  // 交易账号，目前是资金账号
    char8 cust_orgid;                   // 机构编码
    char8 cust_branchid;                // 分支编码
    int16_t account_type;               // 交易账号类型，参考AccountType定义
    char32 pos_str;                     // 定位串
    int32_t busidate;                   // 业务日期，格式为YYYYMMDD   
    char32 custid;                      // 结算单元  
    char32 fundunit;                    // 资金单元  
    char32 stkholdunit;                 // 持仓单元  
    char32 secuid;                      // 股东代码  
    char16 mainseat;                    // 托管席位  
    char32 symbol;                      // 标的代码，格式为市场.证券ID
    int16_t direction;                  // 持仓方向，参考PositionSide定义 
    int16_t investtype;                 // 投资类型，参考InvestType定义
    char32 stkid;                       // 证券内码  
    int16_t stkproperty;                // 股份性质，参考StockProperty定义 
    char64 subjectcode;                 // 科目代码  
    char32 settbody;                    // 结算主体  
    char8 trdsysid;                     // 投资系统  
    char32 coreid;                      // 核心号  
    int32_t currency_type;              // 货币代码，参考CurrencyType定义
    char64 schemeid;                    // 方案编号  
    char256 subjectname;                // 科目名称  
    Amt_t startbal;                     // 期初余额  
    Amt_t endbal;                       // 期末余额  
    Amt_t startcost;                    // 期初成本
    Amt_t endcost;                      // 期末成本
    Amt_t startcostwithfee;             // 期初成本(费用)
    Amt_t endcostwithfee;               // 期末成本(费用)
    Amt_t starttradefee;                // 期初交易费用
    Amt_t endtradefee;                  // 期末交易费用
    Amt_t startprofit;                  // 期初实现盈亏
    Amt_t endprofit;                    // 期末实现盈亏
    Amt_t startprofitwithfee;           // 期初盈亏金额
    Amt_t endprofitwithfee;             // 期末盈亏金额
    Amt_t startintrcost;                // 期初利息成本
    Amt_t endintrcost;                  // 期末利息成本
    Amt_t startintrprofit;              // 期初利息盈亏
    Amt_t endintrprofit;                // 期末利息盈亏
    char16 tacode;                      // TA内部代码  
    char32 transacct;                   // 交易账号  
    char16 taacct;                      // 基金账号  
    char32 linkstkid;                   // 关联代码  
    int32_t extint;                     // int扩展  
    Amt_t extamt;                       // amt扩展  
    char8 extchar;                      // char扩展  
    char256 extstr;                     // str扩展  
    int64_t totalnum;                   // 总记录数
};

// 信用负债流水查询请求，微服务渠道
struct QueryMSCreditDebtsFlowReq {
    int32_t begin_date;             // 起始日期，格式为YYYYMMDD
    int32_t end_date;               // 终止日期，格式为YYYYMMDD
    char32 market;                  // 市场，如 "SZ" 或者 "SH"，非必传，默认查所有市场
    char16 code;                    // 证券代码，例如600000，非必传，默认查全部
    char32 pos_str;                 // 查询定位串，第一次查询传入空，后续查询使用前一次查询返回的定位串
    int32_t query_num;              // 查询数量
    char qry_direct;                // 查询方向，'0'倒序 '1'升序，参考QueryDirection定义
};

// 信用负债流水明细记录
struct MSCreditDebtsFlowDetail {
    char16 account_id;                  // 交易账号，目前是资金账号
    char8 cust_orgid;                   // 机构编码
    char8 cust_branchid;                // 分支编码
    int16_t account_type;               // 交易账号类型，参考AccountType定义
    char32 pos_str;                     // 定位串
    int32_t busidate;                   // 业务日期，格式为YYYYMMDD   
    int32_t operdate;                   // 操作日期，格式为YYYYMMDD  
    int32_t sysdate;                    // 交收日期，格式为YYYYMMDD   
    char32 logno;                       // 流水号  
    char32 custid;                      // 客户代码  
    char creditdebtstype;               // 负债类型，参考CreditDebtsType定义
    bool lifekind;                      // 偿还时负债状况 false:未过期 true:已过期
    char direct;                        // 发生方向，费用方向，参考DebtsOccurDirect定义
    char paykind;                       // 偿还方式，参考RepayWay定义
    Amt_t fundeffect;                   // 负债资金发生数  
    Amt_t fundbal;                      // 负债资金余额  
    Amt_t stkeffect;                    // 负债股份发生数  
    Amt_t stkbal;                       // 负债股份余额  
    int32_t reladate;                   // 关联负债日期，格式为YYYYMMDD 
    char32 relasno;                     // 关联负债流水号  
    char32 symbol;                      // 交易标的，格式为市场.证券ID或市场.合约ID
    char512 remark;                     // 备注  
    int32_t bizdate;                    // 对应的资金股份流水表日期，格式为YYYYMMDD  
    char32 logassetsno;                 // 对应的资金股份流水号  
    int64_t totalnum;                   // 总记录数
};




}  // namespace HFT

#endif  // _HFT_TRADER_STRUCT_H_
