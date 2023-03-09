/**
 * @file    hft_trader_def.h
 * @brief   常量定义
 */

#ifndef _HFT_TRADER_DEF_H_
#define _HFT_TRADER_DEF_H_

namespace HFT {

// 市场类型名字，与行情保持一致
#define MARKET_SH "SH"				// 上海交易所
#define MARKET_SZ "SZ"				// 深圳交易所
#define MARKET_CFFEX "CFFEX"		// 中金所
#define MARKET_CZCE "CZCE"			// 郑商所
#define MARKET_DCE "DCE"			// 大商所
#define MARKET_SHFE "SHFE"			// 上期所
#define MARKET_HK "HK"				// 香港交易所
#define MARKET_SGE "SGE"			// 金交所
#define MARKET_CFETS "CFETS"		// 外汇交易中心
#define MARKET_SHOP "SHOP"			// 上海交易所期权
#define MARKET_SZOP "SZOP"			// 深圳交易所期权
#define MARKET_SZHK "SZHK"			// 深港通
#define MARKET_SHHK "SHHK"			// 沪港通
#define MARKET_NEEQ  "NEEQ"			// 股转市场、全国中小企业股份转让系统、北交所
#define MARKET_SSEB "SSEB"			// 上海交易所B股
#define MARKET_SZSEB "SZSEB"        // 深圳交易所B股
#define MARKET_SSECF "SSECF"        // 上交所封闭式基金
#define MARKET_SZSECF "SZSECF"       // 深交所封闭式基金
#define MARKET_HKEEC "HKEEC"           // H股全流通

// 整型的市场类型
enum MarketType {
    Market_SSE = 1,         // 上海交易所
    Market_SZSE = 2,        // 深圳交易所
    Market_SSE_OP = 10,     // 上海交易所期权，为了与行情保持一致
    Market_SZSE_OP = 11,    // 深圳交易所期权，为了与行情保持一致
    Market_HKE_SSE = 12,    // 香港联合交易所，上海交易所，沪港通
    Market_HKE_SZSE = 13,   // 香港联合交易所，深圳交易所，深港通
    Market_SHFE_INE = 14,   // 上期能源交易所
    Market_NEEQ = 15,       // 北交所、股转市场、全国中小企业股份转让系统
	Market_SSE_B = 16,      // 上海交易所B股
	Market_SZSE_B = 17,     // 深圳交易所B股
    Market_SSE_CF = 21,     // 上交所封闭式基金
    Market_SZSE_CF = 22,    // 深交所封闭式基金
    Market_HKE_EC = 23,     // H股全流通
};

// 订单状态定义
enum OrderStatus {
    OrderStatus_PendingNew = 1,         // 订单待报
    OrderStatus_New = 2,                // 订单已报
    OrderStatus_PartiallyFilled = 3,    // 订单部分成交
    OrderStatus_Filled = 4,             // 订单全部成交
    OrderStatus_PendingCancel = 5,      // 撤单待报
    OrderStatus_Canceling = 6,          // 已报待撤
    OrderStatus_CancelFilled = 7,       // 订单已撤销
    OrderStatus_PartiallyCanceled = 8,  // 部成部撤
    OrderStatus_Rejected = 9,           // 订单已拒绝
    OrderStatus_CancelRejected = 10,    // 撤单废单
	OrderStatus_CanceledPartial = 11,              // 部分撤单
    OrderStatus_SolidChargeNoApply = 13,           // 固收未报
    OrderStatus_SolidChargeApplying = 14,          // 固收正报
    OrderStatus_SolidChargeApplied = 15,           // 固收已报
    OrderStatus_SolidChargeSuccess = 16,           // 固收已成
    OrderStatus_SolidChargeCanceling = 17,         // 固收待撤
    OrderStatus_SolidChargeCanceled = 18,          // 固收已撤
    OrderStatus_SolidChargeAbandon = 19,           // 固收作废
};

// 订单类型定义
enum OrderType {
	OrderType_Placeholder = 0,		// 默认值
    OrderType_LMT = 1,				// 限价委托
    OrderType_BOC = 2,				// 对手方最优价格，深圳/北京证券交易所
    OrderType_BOP = 3,				// 本方最优价格，深圳/北京证券交易所
    OrderType_B5TC = 4,				// 最优五档剩余转撤销，上海/深圳/北京证券交易所
    OrderType_B5TL = 5,				// 最优五档剩余转限价，上海/北京证券交易所
    OrderType_IOC = 6,				// 即时成交剩余转撤销，上海/深圳证券交易所，科创板股票暂不支持
    OrderType_AON = 7,				// 全额成交或撤销，上海/深圳证券交易所，科创板股票暂不支持
    OrderType_ALMT = 9,				// 竞价限价，香港证券交易所
    OrderType_ELMT = 10,			// 增强限价，香港证券交易所
    OrderType_OLMT = 11,			// 零股限价，香港证券交易所
    OrderType_MTL = 14,				// 市价剩余转限价，上海证券交易所，科创板股票暂不支持
    OrderType_LAON = 15,			// 限价全额成交或撤销，上海/深圳证券交易所，科创板股票暂不支持
};

// 买卖方向定义
enum OrderSide {
	OrderSide_Placeholder = 0,              // 未定义、无意义
    OrderSide_Bid = 1,                      // 证券、基金、债券普通买入
    OrderSide_Ask = 2,                      // 证券、基金、债券普通卖出
    OrderSide_Buy_Open = 3,                 // 期权买入开仓
    OrderSide_Buy_Close = 4,                // 期权买入平仓
    OrderSide_Sell_Open = 5,                // 期权卖出开仓
    OrderSide_Sell_Close = 6,               // 期权卖出平仓
    OrderSide_Margin_Bid = 13,              // 证券、基金、债券融资买入
    OrderSide_Margin_Ask = 14,              // 证券、基金、债券融券卖出
    OrderSide_Covered_Open = 15,            // 期权备兑开仓
    OrderSide_Covered_Close = 16,           // 期权备兑平仓
    OrderSide_ETF_Create = 17,              // ETF申购
    OrderSide_ETF_Redeem = 18,              // ETF赎回
    OrderSide_Reverse_Repurchase = 19,      // 逆回购
    OrderSide_Margin_EnBuyBack = 20,        // 买券还券
    OrderSide_Margin_EnSellBack = 21,       // 卖券还款
    OrderSide_Margin_StockBack = 22,        // 现券还券
    OrderSide_Margin_PayBack = 23,          // 直接还款
    OrderSide_Margin_MortgageIn = 24,       // 担保品转入
    OrderSide_Margin_MortgageOut = 25,      // 担保品转出
    OrderSide_Repurchase = 26,              // 正回购
    OrderSide_IPO_Bid = 27,                 // 新股新债申购
    OrderSide_AHFPT_Bid = 28,               // 盘后定价买入，包括大宗盘后交易定价买入（仅深交所）
    OrderSide_AHFPT_Ask = 29,               // 盘后定价卖出，包括大宗盘后交易定价卖出（仅深交所）
    OrderSide_Margin_MoreStockTrans = 30,   // 余券划转
    OrderSide_Allotment_Shares = 31,        // 配股认购
    OrderSide_Appoint_Contract_Repay = 32,  // 指定合约还款
    OrderSide_ETF_Create_OTC = 33,          // ETF实物申购
    OrderSide_ETF_Redeem_OTC = 34,          // ETF实物赎回
    OrderSide_Bond_Swap = 35,               // 债券转股
    OrderSide_Bond_Sell_Back = 36,          // 债券回售
    OrderSide_Pledge_In = 37,               // 质押式回购入库
    OrderSide_Pledge_Out = 38,              // 质押式回购出库
    OrderSide_LOF_Create = 39,              // LOF申购
    OrderSide_LOF_Redeem = 40,              // LOF赎回
    OrderSide_Tender_Offer = 41,            // 预受要约
    OrderSide_Dis_Tender_Offer = 42,        // 解除预受要约
    OrderSide_Bid_Confirm = 43,             // 买成确认，包括股转买成确认、大宗协议交易定价申报买成确认（仅深交所）
    OrderSide_Ask_Confirm = 44,             // 卖成确认，包括股转卖成确认、大宗协议交易定价申报卖成确认（仅深交所）
    OrderSide_Block_Intent_Bid = 45,        // 大宗协议交易意向买入
    OrderSide_Block_Intent_Ask = 46,        // 大宗协议交易意向卖出
    OrderSide_FPT_Bid = 47,                 // 定价买入，包括股转、大宗协议交易定价买入（仅深交所）
    OrderSide_FPT_Ask = 48,                 // 定价卖出，包括股转、大宗协议交易定价卖出（仅深交所）
    OrderSide_Block_Matching_Bid = 49,      // 大宗协议交易成交申报买入，即配对成交买入
    OrderSide_Block_Matching_Ask = 50,      // 大宗协议交易成交申报卖出，即配对成交卖出
    OrderSide_Inquire = 51,                 // 询价，股转
    OrderSide_NEEQ_Create = 52,             // 申购，股转
    OrderSide_Bond_OutRight_RepoIn = 53,    // 买断式回购融资
    OrderSide_Bond_OutRight_RepoOut = 54,   // 买断式回购融券
    OrderSide_Transfer_Custody = 55,        // 转托管
    OrderSide_Bond_Distribution = 56,       // 债券分销
	OrderSide_LOF_Subscribe = 57,	        // lof/ETF场内认购
	OrderSide_Negotiated_Repurchase_SH_14 = 58,      // 初始成交申报--协议回购仅集中交易支持
	OrderSide_Negotiated_Repurchase_SH_15 = 59,      // 初始成交确认
	OrderSide_Negotiated_Repurchase_SH_16 = 60,      // 初始成交拒绝
	OrderSide_Negotiated_Repurchase_SH_17 = 61,      // 到期购回确认
	OrderSide_Negotiated_Repurchase_SH_18 = 62,      // 到期续作申报
	OrderSide_Negotiated_Repurchase_SH_19 = 63,      // 到期续作确认
	OrderSide_Negotiated_Repurchase_SH_1B = 64,      // 到期续作拒绝
	OrderSide_Negotiated_Repurchase_SH_1E = 65,      // 换券申报申报
	OrderSide_Negotiated_Repurchase_SH_1F = 66,      // 换券申报确认
	OrderSide_Negotiated_Repurchase_SH_1G = 67,      // 换券申报拒绝
	OrderSide_Negotiated_Repurchase_SH_1H = 68,      // 提前终止申报(正)
	OrderSide_Negotiated_Repurchase_SH_1J = 69,      // 提前终止确认(逆)
	OrderSide_Negotiated_Repurchase_SH_1K = 70,      // 提前终止拒绝
	OrderSide_Negotiated_Repurchase_SH_1L = 71,      // 解除质押申报(正)
	OrderSide_Negotiated_Repurchase_SH_1M = 72,      // 解除质押确认(逆)
	OrderSide_Negotiated_Repurchase_SH_1N = 73,      // 解除质押拒绝
	OrderSide_Negotiated_Repurchase_SH_1P = 74,      // 正回购意向
	OrderSide_Negotiated_Repurchase_SH_1Q = 75,      // 逆回购意向
	OrderSide_Negotiated_Repurchase_SH_1R = 76,      // 提前终止申报(逆)
	OrderSide_Negotiated_Repurchase_SH_1S = 77,      // 提前终止确认(正)
	OrderSide_Negotiated_Repurchase_SH_1T = 78,      // 解除质押申报(逆)
	OrderSide_Negotiated_Repurchase_SH_1U = 79,      // 解除质押确认(正)
	OrderSide_Negotiated_Repurchase_SZ_34 = 80,      // 初始成交申报
	OrderSide_Negotiated_Repurchase_SZ_38 = 81,      // 到期续作申报
	OrderSide_Negotiated_Repurchase_SZ_3E = 82,      // 换券申报
	OrderSide_Negotiated_Repurchase_SZ_3H = 83,      // 提前购回申报
	OrderSide_Negotiated_Repurchase_SZ_3L = 84,      // 解除质押申报
	OrderSide_Negotiated_Repurchase_SZ_35 = 85,      // 初始成交确认
	OrderSide_Negotiated_Repurchase_SZ_36 = 86,      // 初始成交拒绝
	OrderSide_Negotiated_Repurchase_SZ_37 = 87,      // 到期购回确认
	OrderSide_Negotiated_Repurchase_SZ_39 = 88,      // 到期续作确认
	OrderSide_Negotiated_Repurchase_SZ_3C = 89,      // 到期续作拒绝
	OrderSide_Negotiated_Repurchase_SZ_3F = 90,      // 换券申报确认
	OrderSide_Negotiated_Repurchase_SZ_3G = 91,      // 换券申报拒绝
	OrderSide_Negotiated_Repurchase_SZ_3J = 92,      // 提前购回确认
	OrderSide_Negotiated_Repurchase_SZ_3K = 93,      // 提前购回拒绝
	OrderSide_Negotiated_Repurchase_SZ_3M = 94,      // 解除质押确认
	OrderSide_Negotiated_Repurchase_SZ_3N = 95,      // 解除质押拒绝--协议回购仅集中交易支持
    OrderSide_Offline_Cash_Subscribe = 96,           // 网下现金认购
    OrderSide_Offline_Stock_Subscribe = 97,          // 网下股票认购
    OrderSide_Online_Stock_Subscribe = 98,           // 网上股票认购
    OrderSide_Bond_Negotiated_Trade_Bid = 100,                 // 协商成交买                             
    OrderSide_Bond_Negotiated_Trade_Ask = 101,                 // 协商成交卖                             
    OrderSide_Bond_Negotiated_Trade_Confirm_Bid = 102,         // 协商成交确认买
    OrderSide_Bond_Negotiated_Trade_Reject_Bid = 103,          // 协商成交拒绝买                         
    OrderSide_Bond_Negotiated_Trade_Confirm_Ask = 104,         // 协商成交确认卖                         
    OrderSide_Bond_Negotiated_Trade_Reject_Ask = 105,          // 协商成交拒绝卖                         
    OrderSide_Bond_Click_Trade_Quotation_Bid = 106,            // 点击成交报价买                         
    OrderSide_Bond_Click_Trade_Quotation_Ask = 107,            // 点击成交报价卖                         
    OrderSide_Bond_Click_Trade_Quotation_Reply_Bid = 108,      // 点击成交报价回复买                     
    OrderSide_Bond_Click_Trade_Quotation_Reply_Ask = 109,      // 点击成交报价回复卖                     
    OrderSide_Bond_Inquiry_Trade_Inquiry_Seed_Bid = 110,       // 询价成交询价请求买                     
    OrderSide_Bond_Inquiry_Trade_Inquiry_Seed_Ask = 111,       // 询价成交询价请求卖                     
    OrderSide_Bond_Inquiry_Trade_Quotation_Bid = 112,          // 询价成交报价买                         
    OrderSide_Bond_Inquiry_Trade_Quotation_Ask = 113,          // 询价成交报价卖                         
    OrderSide_Bond_Inquiry_Trade_Quotation_Reply_Bid = 114,    // 询价成交报价回复买                     
    OrderSide_Bond_Inquiry_Trade_Quotation_Reply_Ask = 115,    // 询价成交报价回复卖                     
    OrderSide_Bond_Auctions_Trade_Subscribe_Order = 116,       // 竞买成交竞买预约申报                   
    OrderSide_Bond_Auctions_Trade_Send_Order = 117,            // 竞买成交竞买发起申报                   
    OrderSide_Bond_Auctions_Trade_Reply_Order = 118,           // 竞买成交竞买应价申报
    OrderSide_Bond_QuoteRepo_Order = 119,                      // 报价回购
    OrderSide_Bond_Quote_Continue = 120,                       // 报价续做
    OrderSide_Bond_Putback_Resale_Order = 121,                 // 债券回售转售申报
    OrderSide_Bond_Putback_Resale_Confirm = 122,               // 债券回售转售确认
    OrderSide_Bond_Putback_Resale_Reject = 123,                // 债券回售转售拒绝
};

// 持仓类型
enum PositionSide {
    PositionSide_Long = 1,           // 多仓
    PositionSide_Short = 2,          // 空仓
    PositionSide_Short_Covered = 3,  // 备兑空仓
};

// 成交回报类型定义
enum TradeReportType {
    TradeReportType_Normal = 1,         // 普通回报
    TradeReportType_Cancel = 2,         // 撤单回报
    TradeReportType_Abolish = 3,        // 普通废单回报
    TradeReportType_InsideCancel = 4,   // 内部撤单回报，还未到交易所便被撤下来
    TradeReportType_CancelAbolish = 5,  // 撤单废单回报
};

// 资金账户类型定义
enum AccountType {
    AccountType_Stock = 1,    // 股票
    AccountType_Futures = 2,  // 期货
    AccountType_Options = 3,  // 股票期权
    AccountType_Margin = 4,   // 融资融券
};

// 货币类型
enum CurrencyType {
    CurrencyType_CNY = 1,  // 人民币
    CurrencyType_HKD = 2,  // 港币
    CurrencyType_USD = 3,  // 美元
};

// 撤单标识
enum CancelFlag {
    CancelFlag_False = 1,  // 假，不是撤单
    CancelFlag_True = 2,   // 真，是撤单
};

// ETF申购赎回允许状态
enum ETFTradeState {
    ETFTradeState_PurchaseAndRedeem = 1,       // 场内场外全部允许申购和赎回
    ETFTradeState_Forbidden = 2,               // 场内场外全部不允许申购和赎回
    ETFTradeState_OnlyPurchase = 3,            // 场内场外全部允许申购、不允许赎回
    ETFTradeState_OnlyRedeem = 4,              // 场内场外全部允许赎回、不允许申购
    ETFTradeState_InsideCreateAndRedeem = 5,   // 场内允许申购和赎回
    ETFTradeState_OutsideCreateAndRedeem = 6,  // 场外允许申购和赎回
    ETFTradeState_InsideOnlyCreate = 7,        // 场内允许申购、不允许赎回
    ETFTradeState_InsideOnlyRedeem = 8,        // 场内允许赎回、不允许申购
    ETFTradeState_OutsideOnlyCreate = 9,       // 场外允许申购、不允许赎回
    ETFTradeState_OutsideOnlyRedeem = 10,      // 场外允许赎回、不允许申购
};

// ETF现金替代标识
enum ETFReplaceFlag {
    ETFReplaceFlag_Forbidden = 1,      // 禁止现金替代
    ETFReplaceFlag_Allow = 2,          // 允许现金替代
    ETFReplaceFlag_Must = 3,           // 必须现金替代
    ETFReplaceFlag_NotSHRefund = 4,    // 对于跨市场ETF，表示非沪市股票退补现金替代，此时对应的溢价比例和现金金额部分不能为空
    ETFReplaceFlag_NotSHMust = 5,      // 对于跨市场ETF，表示非沪市股票必须现金替代，对应的现金金额部分不为空。
    ETFReplaceFlag_NotSHSZRefund = 6,  // 非沪深市场成分股退补现金替代，一般是上海跨境ETF对应的成分股
    ETFReplaceFlag_NotSHSZMust = 7,    // 非沪深市场成分股必须现金替代，一般是上海跨境ETF对应的停牌成分股和上海货币ETF-xxxxx1对应值。
    ETFReplaceFlag_BackFill = 8,       // 退补现金替代
	ETFReplaceFlag_HK_BackFill = 9,    // 港市退补现金替代（仅适用于跨沪深港ETF产品）
	ETFReplaceFlag_HK_Must = 10,	   // 港市必须现金替代（仅适用于跨沪深港ETF产品）
};

// 证券类型
enum StkType {
    StkType_Stock = 1,       // 股票
    StkType_Bond = 2,        // 债券
    StkType_Index = 3,       // 指数
    StkType_Future = 4,      // 期货
    StkType_Options = 5,     // 期权
    StkType_Fund = 6,        // 基金
    StkType_Repurchase = 7,  // 回购
    StkType_Warrant = 8,     // 权证
    StkType_STIB = 9,        // 科创板股票
	StkType_TRST = 10,       // 信托
	StkType_BWRT = 11,       // 篮子权证
	StkType_ETF = 12,        // ETF
};

// 证券类型详细--低延时和集中交易柜台
enum SecurityTypeDetail {
    SecurityTypeDetail_Default = 0,    // 默认类型
    SecurityTypeDetail_ZBAG = 1,       // 主板A股
    SecurityTypeDetail_ZXBG = 2,       // 中小板股票
    SecurityTypeDetail_CYBG = 3,       // 创业板股票
    SecurityTypeDetail_ZBBG = 4,       // 主板B股
    SecurityTypeDetail_GZ = 5,         // 国债（含地方债）
    SecurityTypeDetail_QYZ = 6,        // 企业债
    SecurityTypeDetail_GSZ = 7,        // 公司债
    SecurityTypeDetail_KZZ = 8,        // 可转债
    SecurityTypeDetail_SMZ = 9,        // 私募债
    SecurityTypeDetail_KJHSMZ = 10,    // 可交换私募债
    SecurityTypeDetail_ZQGSCJZ = 11,   // 证券公司次级债
    SecurityTypeDetail_ZYSHG = 12,     // 质押式回购
    SecurityTypeDetail_ZCZCZQ = 13,    // 资产支持证券
    SecurityTypeDetail_GPETF = 14,     // 股票ETF
    SecurityTypeDetail_KSCGPETF = 15,  // 跨市场股票ETF
    SecurityTypeDetail_KJETF = 16,     // 跨境ETF
    SecurityTypeDetail_SWZQETF = 17,   // 实物债券ETF
    SecurityTypeDetail_XJZQETF = 18,   // 现金债券ETF
    SecurityTypeDetail_HJETF = 19,     // 黄金ETF
    SecurityTypeDetail_HBETF = 20,     // 货币ETF
    SecurityTypeDetail_GGETF = 21,     // 杠杆ETF
    SecurityTypeDetail_SPQHETF = 22,   // 商品期货ETF
    SecurityTypeDetail_BZLOF = 23,     // 标准LOF
    SecurityTypeDetail_FJZJJ = 24,     // 分级子基金
    SecurityTypeDetail_FBSJJ = 25,     // 封闭式基金
    SecurityTypeDetail_JSSJJ = 26,     // 仅申赎基金
    SecurityTypeDetail_PSQZ = 27,      // 配售权证
    SecurityTypeDetail_QZ = 28,        // 权证
    SecurityTypeDetail_GGQQ = 29,      // 个股期权
    SecurityTypeDetail_ETFQQ = 30,     // ETF期权
    SecurityTypeDetail_ZGCP = 31,      // 资管产品
    SecurityTypeDetail_BJHG = 32,      // 报价回购
    SecurityTypeDetail_YXG = 33,       // 优先股
    SecurityTypeDetail_ZQGSDQZ = 34,   // 证券公司短期债
    SecurityTypeDetail_KJHGSZ = 35,    // 可交换公司债
    SecurityTypeDetail_ZQFX = 36,      // 债券分销
    SecurityTypeDetail_GZFX = 37,      // 国债分销
    SecurityTypeDetail_QTZQ = 38,      // 其他债券
    SecurityTypeDetail_KSC = 39,       // 跨市场/跨境资金
    SecurityTypeDetail_QTJJ = 40,      // 其他基金
    SecurityTypeDetail_GJBGP = 41,     // 国际版股票
    SecurityTypeDetail_QTGP = 42,      // 其他股票
    SecurityTypeDetail_MDSZQHG = 43,   // 买断式债券回购
    SecurityTypeDetail_CYBKZZ = 44,    // 创业板可转债
    SecurityTypeDetail_CTPZ = 45,      // 存托凭证
    SecurityTypeDetail_HLTCDR = 46,    // 沪伦通CDR
    SecurityTypeDetail_CXQYGP = 47,    // 创新企业股票
    SecurityTypeDetail_ZYDM = 48,      // 质押代码
    SecurityTypeDetail_SSSSHBJJ = 49,  // 实时申赎货币基金
    SecurityTypeDetail_XGXZFX = 50,    // 新股新债发行
    SecurityTypeDetail_KCB = 51,       // 科创板
    SecurityTypeDetail_KCBCDR = 53,    // 科创板CDR
    SecurityTypeDetail_GKYXG = 54,     // 公开优先股
    SecurityTypeDetail_FGKYXG = 55,    // 非公开优先股
	
	SecurityTypeDetail_GZHG = 56,	   // 国债回购
	SecurityTypeDetail_QZHG = 57,	   // 企债回购
	SecurityTypeDetail_ZQZG = 58,	   // 债券转股
	SecurityTypeDetail_SWGZ = 59,	   // 实物国债
	SecurityTypeDetail_SWQZ = 60,	   // 实物企债
	SecurityTypeDetail_GZZY = 61,	   // 国债质押
	SecurityTypeDetail_QZZY = 62,	   // 企债质押
	SecurityTypeDetail_BZZQ = 63,	   // 标准券
	SecurityTypeDetail_GPJH = 64,	   // 挂牌集合
	SecurityTypeDetail_YATP = 65,	   // 议案投票
	SecurityTypeDetail_FJY = 66,       // 非交易, 定向可转债
	SecurityTypeDetail_XYHG = 67,      // 协议回购
	SecurityTypeDetail_YYSG = 68,      // 要约收购
	SecurityTypeDetail_ZDJY = 69,      // 指定交易
	SecurityTypeDetail_CWRSS = 70,     // 场外认申赎
	SecurityTypeDetail_ZZRSS = 71,     // 中证认申赎
	SecurityTypeDetail_BZHG = 72,      // B转H股
	SecurityTypeDetail_ZQETF = 73,     // 债券ETF
	SecurityTypeDetail_GPLX = 74,      // 挂牌连续
	SecurityTypeDetail_GPZS = 75,      // 挂牌做市
	SecurityTypeDetail_GZYFX = 76,     // 国债预发行
	SecurityTypeDetail_GPGKFX = 77,    // 挂牌公开发行
	SecurityTypeDetail_CWLC = 78,      // 场外理财

    SecurityTypeDetail_HKStock = 52,            // 港股
    SecurityTypeDetail_GrowthCDR = 1000,        // 创业板存托凭证
    SecurityTypeDetail_GrowthIEStock = 1001,    // 创业板创新企业股票 
    SecurityTypeDetail_StktGPZS = 1002,         // 股转挂牌做市 
    SecurityTypeDetail_StktGPFX = 1003,         // 股转挂牌公开发行 
    SecurityTypeDetail_StktGPLXJJ = 1004,       // 股转挂牌连续竞价 
    SecurityTypeDetail_StktGPJJ = 1005,         // 股转挂牌集合竞价 
    SecurityTypeDetail_StktYYSG = 1006,         // 股转要约收购 
    SecurityTypeDetail_StktFGKYXG = 1007,       // 非公开优先股 
    SecurityTypeDetail_StktZPZQ = 1008,         // 股转摘牌证券 
};

// 证券类型--顶点现货和顶点两融柜台
enum SecurityTypeAPEX {
    SecurityTypeAPEX_Default = 0,      // 默认类型
    SecurityTypeAPEX_A0 = 1,           // A股
    SecurityTypeAPEX_A1 = 2,           // 配股
    SecurityTypeAPEX_A2 = 3,           // 转配
    SecurityTypeAPEX_A3 = 4,           // A股发行
    SecurityTypeAPEX_A4 = 5,           // A股配售
    SecurityTypeAPEX_A6SSGP = 6,       // 深市股票
    SecurityTypeAPEX_A7 = 7,           // A股增发
    SecurityTypeAPEX_A8 = 8,           // 权证
    SecurityTypeAPEX_A9QZXQ = 9,       // 权证行权
    SecurityTypeAPEX_AC = 10,          // A退警示
    SecurityTypeAPEX_AD = 11,          // A退整理
    SecurityTypeAPEX_AF = 12,          // 非公优A
    SecurityTypeAPEX_AG = 13,          // 公开优A
    SecurityTypeAPEX_AK = 14,          // 科创板
    SecurityTypeAPEX_E0 = 15,          // ETF基金
    SecurityTypeAPEX_E1 = 16,          // ETF资金
    SecurityTypeAPEX_E3 = 17,          // ETF发行
    SecurityTypeAPEX_E4 = 18,          // ETF申赎
    SecurityTypeAPEX_EH = 19,          // 货币ETF
    SecurityTypeAPEX_EZ = 20,          // 债券ETF
    SecurityTypeAPEX_F0 = 21,          // 指定
    SecurityTypeAPEX_F1 = 22,          // 撤指
    SecurityTypeAPEX_F2 = 23,          // 指数
    SecurityTypeAPEX_F3MMFW = 24,      // 密码服务
    SecurityTypeAPEX_F4 = 25,          // 配售市值
    SecurityTypeAPEX_F5 = 26,          // 投票
    SecurityTypeAPEX_F6 = 27,          // 权证创设
    SecurityTypeAPEX_F7 = 28,          // 预受要约
    SecurityTypeAPEX_F8 = 29,          // 质押券
    SecurityTypeAPEX_H0HG = 30,        // 回购
    SecurityTypeAPEX_H1 = 31,          // 企债回购
    SecurityTypeAPEX_H2 = 32,          // 买断回购
    SecurityTypeAPEX_H3 = 33,          // 帐户回购
    SecurityTypeAPEX_H4 = 34,          // 报价回购
    SecurityTypeAPEX_J0 = 35,          // 基金通
    SecurityTypeAPEX_J1 = 36,          // 货币基金
    SecurityTypeAPEX_J3 = 37,          // 基金认购
    SecurityTypeAPEX_J4 = 38,          // 基金转托
    SecurityTypeAPEX_J5 = 39,          // 基金分红
    SecurityTypeAPEX_J6 = 40,          // 基金转换
    SecurityTypeAPEX_L0 = 41,          // LOF基金
    SecurityTypeAPEX_L3 = 42,          // LOF认购
    SecurityTypeAPEX_NA = 43,          // 创新证券
    SecurityTypeAPEX_RA = 44,          // A股CDR
    SecurityTypeAPEX_RK = 45,          // 科创板CDR
    SecurityTypeAPEX_RL = 46,          // 沪伦通
    SecurityTypeAPEX_T0 = 47,          // 投资基金
    SecurityTypeAPEX_T3 = 48,          // 基金发行
    SecurityTypeAPEX_T7 = 49,          // 基金增发
    SecurityTypeAPEX_Z0 = 50,          // 现券国债
    SecurityTypeAPEX_Z1 = 51,          // 记帐国债
    SecurityTypeAPEX_Z2 = 52,          // 专资转让
    SecurityTypeAPEX_Z3 = 53,          // 债券发行
    SecurityTypeAPEX_Z4 = 54,          // 企业债券
    SecurityTypeAPEX_Z5 = 55,          // 转债
    SecurityTypeAPEX_Z6PZ = 56,        // 配债
    SecurityTypeAPEX_Z7ZQZF = 57,      // 债券增发
    SecurityTypeAPEX_Z8 = 58,          // 转债转股
    SecurityTypeAPEX_Z9 = 59,          // 转债回售
    SecurityTypeAPEX_ZA = 60,          // 公司债
    SecurityTypeAPEX_ZB = 61,          // 适当性债
    SecurityTypeAPEX_ZC = 62,          // 私募债
    SecurityTypeAPEX_ZD = 63,          // 转债发行
    SecurityTypeAPEX_ZE = 64,          // 非公发债
    SecurityTypeAPEX_ZF = 65,          // 风警债券
    SecurityTypeAPEX_ZI = 66,          // 定向转债
    SecurityTypeAPEX_A5 = 67,          // 配售放弃
    SecurityTypeAPEX_A6HSGP = 68,      // 沪市股票
    SecurityTypeAPEX_A9GPZ = 69,       // 股配债
    SecurityTypeAPEX_C0 = 70,          // 创业板
    SecurityTypeAPEX_C1 = 71,          // 创业配股
    SecurityTypeAPEX_C3 = 72,          // 创业发行
    SecurityTypeAPEX_C4 = 73,          // 创业配售
    SecurityTypeAPEX_C7 = 74,          // 创业增发
    SecurityTypeAPEX_CD = 75,          // 创退整理
    SecurityTypeAPEX_CR = 76,          // 注册创业
    SecurityTypeAPEX_CT = 77,          // 注退整理
    SecurityTypeAPEX_F3JJJZ = 78,      // 基金净值
    SecurityTypeAPEX_H0GZHG = 79,      // 国债回购
    SecurityTypeAPEX_NC = 80,          // 创业创新
    SecurityTypeAPEX_RC = 81,          // 注创CDR
    SecurityTypeAPEX_Z6SCZZ = 82,      // 深创转债
    SecurityTypeAPEX_Z7ZQPS = 83,      // 债券配售
    SecurityTypeAPEX_ZS = 84,          // 双创债
    SecurityTypeAPEX_RZRQ_A3 = 85,             // 首发申购
    SecurityTypeAPEX_RZRQ_A4 = 86,             // 市值配售
    SecurityTypeAPEX_RZRQ_E0 = 87,             // 单市ETF
    SecurityTypeAPEX_RZRQ_E3 = 88,             // ETF认购
    SecurityTypeAPEX_RZRQ_EA = 89,             // 跨市ETF
    SecurityTypeAPEX_RZRQ_EB = 90,             // 跨境ETF
    SecurityTypeAPEX_RZRQ_EC = 91,             // 黄金ETF
    SecurityTypeAPEX_RZRQ_F0 = 92,             // 指定撤指
    SecurityTypeAPEX_RZRQ_F1 = 93,             // 标准券
    SecurityTypeAPEX_RZRQ_F7 = 94,             // 要约收购
    SecurityTypeAPEX_RZRQ_H5 = 95,             // 协议回购
    SecurityTypeAPEX_RZRQ_J1 = 96,             // 实时申赎货币
    SecurityTypeAPEX_RZRQ_RA = 97,             // CDR证券
    SecurityTypeAPEX_RZRQ_RL = 98,             // 沪伦通DR
    SecurityTypeAPEX_RZRQ_Z1 = 99,             // 国债
    SecurityTypeAPEX_RZRQ_Z2GSPTZ = 100,       // 固收平台债
    SecurityTypeAPEX_RZRQ_Z5 = 101,            // 可转债
    SecurityTypeAPEX_RZRQ_Z6 = 102,            // 转债配售
    SecurityTypeAPEX_RZRQ_ZG = 103,            // 国债预发
    SecurityTypeAPEX_RZRQ_A0 = 104,            // 股票
    SecurityTypeAPEX_RZRQ_AB = 105,            // 股权激励
    SecurityTypeAPEX_RZRQ_NC = 106,            // 注册创业创新企业
    SecurityTypeAPEX_RZRQ_T3 = 107,            // 投资基金发行
    SecurityTypeAPEX_RZRQ_Z2ZCZCZQ = 108,      // 资产支持证券
    SecurityTypeAPEX_RZRQ_ZC = 109,            // 创债发行
    SecurityTypeAPEX_RZRQ_ZZ = 110,            // 资管份额
    SecurityTypeAPEX_ZJ = 111,                 // 可交换债
};

// 证券类型详细--华锐ATP柜台
enum SecurityTypeDetailATP {
    kSecurityTypeDetailATP_Default = 0,    // 默认类型
    kSecurityTypeDetailATP_ZBAG = 1,       // 主板A股
    kSecurityTypeDetailATP_ZXBG = 2,       // 中小板股票
    kSecurityTypeDetailATP_CYBG = 3,       // 创业板股票
    kSecurityTypeDetailATP_ZBBG = 4,       // 主板B股
    kSecurityTypeDetailATP_GZ = 5,         // 国债（含地方债）
    kSecurityTypeDetailATP_QYZ = 6,        // 企业债
    kSecurityTypeDetailATP_GSZ = 7,        // 公司债
    kSecurityTypeDetailATP_KZZ = 8,        // 可转债
    kSecurityTypeDetailATP_SMZ = 9,        // 私募债
    kSecurityTypeDetailATP_KJHSMZ = 10,    // 可交换私募债
    kSecurityTypeDetailATP_ZQGSCJZ = 11,   // 证券公司次级债
    kSecurityTypeDetailATP_ZYSHG = 12,     // 质押式回购
    kSecurityTypeDetailATP_ZCZCZQ = 13,    // 资产支持证券
    kSecurityTypeDetailATP_GPETF = 14,     // 股票ETF
    kSecurityTypeDetailATP_KSCGPETF = 15,  // 跨市场股票ETF
    kSecurityTypeDetailATP_KJETF = 16,     // 跨境ETF
    kSecurityTypeDetailATP_SWZQETF = 17,   // 实物债券ETF
    kSecurityTypeDetailATP_XJZQETF = 18,   // 现金债券ETF
    kSecurityTypeDetailATP_HJETF = 19,     // 黄金ETF
    kSecurityTypeDetailATP_HBETF = 20,     // 货币ETF
    kSecurityTypeDetailATP_GGETF = 21,     // 杠杆ETF
    kSecurityTypeDetailATP_SPQHETF = 22,   // 商品期货ETF
    kSecurityTypeDetailATP_BZLOF = 23,     // 标准LOF
    kSecurityTypeDetailATP_FJZJJ = 24,     // 分级子基金
    kSecurityTypeDetailATP_FBSJJ = 25,     // 封闭式基金
    kSecurityTypeDetailATP_JSSJJ = 26,     // 仅申赎基金
    kSecurityTypeDetailATP_PSQZ = 27,      // 配售权证
    kSecurityTypeDetailATP_QZ = 28,        // 权证
    kSecurityTypeDetailATP_GGQQ = 29,      // 个股期权
    kSecurityTypeDetailATP_ETFQQ = 30,     // ETF期权
    kSecurityTypeDetailATP_ZGCP = 31,      // 资管产品
    kSecurityTypeDetailATP_BJHG = 32,      // 报价回购
    kSecurityTypeDetailATP_YXG = 33,       // 优先股
    kSecurityTypeDetailATP_ZQGSDQZ = 34,   // 证券公司短期债
    kSecurityTypeDetailATP_KJHGSZ = 35,    // 可交换公司债
    kSecurityTypeDetailATP_ZQFX = 36,      // 债券分销
    kSecurityTypeDetailATP_GZFX = 37,      // 国债分销
    kSecurityTypeDetailATP_QTZQ = 38,      // 其他债券
    kSecurityTypeDetailATP_KSC = 39,       // 跨市场/跨境资金
    kSecurityTypeDetailATP_QTJJ = 40,      // 其他基金
    kSecurityTypeDetailATP_GJBGP = 41,     // 国际版股票
    kSecurityTypeDetailATP_QTGP = 42,      // 其他股票
    kSecurityTypeDetailATP_MDSZQHG = 43,   // 买断式债券回购
    kSecurityTypeDetailATP_CYBKZZ = 44,    // 创业板可转债
    kSecurityTypeDetailATP_CTPZ = 45,      // 存托凭证
    kSecurityTypeDetailATP_HLTCDR = 46,    // 沪伦通CDR
    kSecurityTypeDetailATP_CXQYGP = 47,    // 创新企业股票
    kSecurityTypeDetailATP_ZYDM = 48,      // 质押代码
    kSecurityTypeDetailATP_SSSSHBJJ = 49,  // 实时申赎货币基金
    kSecurityTypeDetailATP_XGXZFX = 50,    // 新股新债发行
    kSecurityTypeDetailATP_KCB = 51,       // 科创板
    kSecurityTypeDetailATP_HK = 52,        // 港股
    kSecurityTypeDetailATP_KCBCDR = 53,    // 科创板CDR
    kSecurityTypeDetailATP_QQGP = 54,         // 期权股票
    kSecurityTypeDetailATP_QQETF = 55,        // 期权ETF
    kSecurityTypeDetailATP_ZCZCYBGP = 56,     // 注册制创业板股票
    kSecurityTypeDetailATP_ZCZCXQYGP = 57,    // 注册制创新企业股票
    kSecurityTypeDetailATP_ZCZCTPZ = 58,      // 注册制存托凭证
    kSecurityTypeDetailATP_CYBCXQYGP = 59,    // 创业板创新企业股票
    kSecurityTypeDetailATP_ZCZCYBCXQYGP = 60, // 注册制创业板创新企业股票
    kSecurityTypeDetailATP_CYBCTPZ = 61,      // 创业板存托凭证
    kSecurityTypeDetailATP_ZCZCYBCTPZ = 62,   // 注册制创业板存托凭证
    kSecurityTypeDetailATP_KCBETF = 63,       // 科创板ETF
    kSecurityTypeDetailATP_KCBLOF = 64,       // 科创板相关LOF
    kSecurityTypeDetailATP_JCSSJJ = 65,       // 基础设施基金
    kSecurityTypeDetailATP_DXKZZ = 66,        // 定向可转债
    kSecurityTypeDetailATP_KCBKZZ = 67,       // 科创板可转债
};

// 证券状态
enum SecurityStatus {
    SecurityStatus_Normal = 0,               // 正常
    SecurityStatus_Suspend = 1,              // 停牌
    SecurityStatus_NearExpireDate = 2,       // 临近到期日
    SecurityStatus_Adjustment = 3,           // 最近5个交易日内发生调整
    SecurityStatus_ExcludeRight = 4,         // 除权
    SecurityStatus_ExcludeDividend = 5,      // 除息
    SecurityStatus_Caution = 6,              // 风险警示
    SecurityStatus_IPOFirstDay = 7,          // 上市首日
    SecurityStatus_Delisting = 8,            // 退市整理期
    SecurityStatus_TransferByAgreement = 9,  // 退市后协议转让
};

// 柜台类型
enum CounterType {
    CounterType_JZJY = 1,             // 集中交易柜台
    CounterType_APEX_MARGIN = 2,      // 顶点两融HTS柜台
    CounterType_APEX = 3,             // 顶点股票快速柜台
    CounterType_NGTP = 4,             // 98机构域股票快速柜台
    CounterType_DYC = 5,              // 97机构域股票快速柜台
    CounterType_DYC_MARGIN = 6,       // 低延时两融96域快速节点
    CounterType_DYC_JZJY = 8,         // 低延时现货96域
    CounterType_DYC_JZJY_MARGIN = 9,  // 低延时两融96域
    CounterType_DYC_OPTIONS = 10,     // 低延时期权快速柜台
    CounterType_DYC_ATP = 11,         // 快速订单系统（华锐超极速）
    CounterType_TYKSGT_OPTIONS = 23,  // 泰琰期权快速柜台
    CounterType_XCGT = 25,            // 低延时信创快速柜台
    CounterType_PTGT_OPTIONS = 27,    // 金证期权普通柜台
};

// 常用股东权限类型
enum SecuidRight {
    SecuidRight_Delisting = 1,               // 退市整理
    SecuidRight_Caution = 2,                 // 风险警示
    SecuidRight_Gem = 3,                     // 创业板
    SecuidRight_KeChuangPlate_Normal = 4,    // 科创版权限_普通账号
    SecuidRight_KeChuangPlate_Credit = 5,    // 科创版权限_信用账号
    SecuidRight_Repo = 6,                    // 债券回购-正回购
    SecuidRight_Reverse_Repo = 7,            // 债券回购-逆回购
    SecuidRight_SHHK_Trade = 8,              // 沪港通
    SecuidRight_SZHK_Trade = 9,              // 深港通
    SecuidRight_ETF_Redemption_Normal = 10,  // 普通ETF申赎
    SecuidRight_Hulun_Trade = 11,            // 沪伦通交易
};

// 柜台间资金划转方向
enum TransferFundSide {
    TransferFundSide_In = 1,   // 资金转入，从集中交易柜台转入到快速柜台
    TransferFundSide_Out = 2,  // 资金转出，从快速柜台转出到集中交易柜台
};

// 委托属性
enum OrderFlag {
    OrderFlag_Security_Normal = 1,            // 证券普通交易
    OrderFlag_Security_CashLoan = 2,          // 证券融资交易
    OrderFlag_Security_SecurityLoan = 3,      // 证券融券交易
    OrderFlag_Future_Option_Speculation = 4,  // 期货/期权投机
    OrderFlag_Future_Option_Hedge = 5,        // 期货/期权套期保值
    OrderFlag_Future_Option_Arbitrage = 6,    // 期货/期权套利
    OrderFlag_Option_Covered = 7,             // 期权备兑交易
};

// 委托查询标志位
enum OrderQueryFlag {
    OrderQueryFlag_All = 0,         // 查询所有委托
    OrderQueryFlag_Cancelable = 1,  // 查询可撤单委托，即可以发起撤单请求的普通委托
    OrderQueryFlag_NonCancel = 2,   // 查询普通委托，即不是撤单委托的普通委托
};

// 新发行证券查询标志位
enum IPOQueryFlag {
    IPOQueryFlag_NewStock = 1,  // 查询新股信息
    IPOQueryFlag_NewBond = 2,   // 查询新债信息
};

// 行权执行类型定义
enum ExerciseType {
    ExerciseType_Execute = 1,  // 执行
};

// 行权操作状态类型定义
enum ExerciseOperateStatus {
    ExerciseOperateStatus_InsertSubmitted = 1,  // 已经提交
    ExerciseOperateStatus_CancelSubmitted = 2,  // 撤单已经提交
    ExerciseOperateStatus_Accepted = 3,         // 已经接受
    ExerciseOperateStatus_InsertRejected = 4,   // 报单已经被拒绝
    ExerciseOperateStatus_CancelRejected = 5,   // 撤单已经被拒绝
    ExerciseOperateStatus_UnSubmitted = 6,      // 未提交
};

// 行权状态类型定义
enum ExerciseStatus {
    ExerciseStatus_SendStock = 1,    // 发往现货系统
    ExerciseStatus_RepealStock = 2,  // 冲正现货系统
    ExerciseStatus_SendOffer = 3,    // 发往报盘
    ExerciseStatus_Fail = 4,         // 行权失败
    ExerciseStatus_Accepted = 5,     // 交易所已接收
    ExerciseStatus_Cancelled = 6,    // 行权已撤销
};

// 执行方式
enum StrikeModeType {
    StrikeModeType_Continental = 1,  // 欧式
    StrikeModeType_American = 2,     // 美式
    StrikeModeType_Bermuda = 3,      // 百慕大
};

// 期权类型
enum OptionsType {
    OptionsType_CallOptions = 1,  // 看涨
    OptionsType_PutOptions = 2,   // 看跌
};

// 申报单位
enum OrderUnitType {
    OrderUnitType_Shou = 1,   // 手
    OrderUnitType_Gu = 2,     // 股
    OrderUnitType_Fen = 3,    // 份
    OrderUnitType_Zhang = 4,  // 张
};

// 转移状态
enum TransferStatus {
    TransferStatus_TransferHandling = 1,  // 转移正在处理
    TransferStatus_TransferSuccess = 2,   // 转移成功
    TransferStatus_TransferFail = 3,      // 转移失败
};

// 现货持仓转划转型
enum TransferPositionType {
    TransferPositionType_All = 1,      // 任意仓
    TransferPositionType_History = 2,  // 昨仓
    TransferPositionType_TodayBS = 3,  // 今买卖仓
    TransferPositionType_TodayPR = 4,  // 今申赎仓
};

// 现货持仓划转方向
enum TransferStockPositionSide {
    TransferStockPositionSide_In = 1,                    // 蓝补
    TransferStockPositionSide_Out = 2,                   // 红冲
    TransferStockPositionSide_MoveIn = 3,                // 调入
    TransferStockPositionSide_MoveOut = 4,               // 调出
    TransferStockPositionSide_Lock = 5,                  // 备兑锁定
    TransferStockPositionSide_Unlock = 6,                // 备兑解锁
    TransferStockPositionSide_ExerciseFreeze = 7,        // 行权冻结
    TransferStockPositionSide_ExerciseUnfreeze = 8,      // 行权失败解冻
    TransferStockPositionSide_CoveredCloseUnfreeze = 9,  // 备兑平仓释放
};

// 期权现货锁定类型
enum LockStockType {
    LockStockType_Lock = 1,    // 锁定
    LockStockType_Unlock = 2,  // 解锁
};

// 期权现货锁定状态
enum LockStockStatus {
    LockStockStatus_SendStock = 1,    // 发往现货系统
    LockStockStatus_RepealStock = 2,  // 发往现货系统冲正
    LockStockStatus_SendOffer = 3,    // 锁定/解锁被期权系统接收后往期权报盘发送
    LockStockStatus_Fail = 4,         // 锁定/解锁失败
    LockStockStatus_Success = 5,      // 锁定/解锁成功
    LockStockStatus_ForceCancel = 6,  // 强制撤销，锁定委托被管理员撤销，用在期权报盘工作异常的特殊场景
};

// 期权合约状态定义，目前仅深圳期权有
// 每个状态位使用整数的bit位表示，如果bit位为1，表示为此状态，一个合约可能处于多个状态
enum ContractStatus {
    ContractStatus_Suspend = 0x00000001,          // 停牌
    ContractStatus_LongTermSuspend = 0x00000002,  // 长期停牌
    ContractStatus_CircuitBreaker = 0x00000040,   // 熔断机制
    //   bit位为1: 不接受新订单申报
    //   bit位为0: 接受新订单申报
    ContractStatus_RestrictLongOpen = 0x00000080,     // 限制买入开仓
    ContractStatus_RestrictShortOpen = 0x00000100,    // 限制卖出（不包括备兑）开仓
    ContractStatus_RestrictCoveredOpen = 0x00000200,  // 限制备兑开仓
    ContractStatus_VolatilityInterrupt = 0x00000400,  // 波动性中断
    ContractStatus_TempSuspend = 0x00000800,          // 临时停牌
    ContractStatus_ContinuousSuspend = 0x00001000,    // 连续停牌
    ContractStatus_RestrictExercise = 0x00002000,     // 限制行权
    ContractStatus_RestrictMakerQuote = 0x00004000,   // 限制做市商报价
};

// 组合报单类型
enum OptionCombineType {
    OptionCombineType_Combine = 1,     // 组合
    OptionCombineType_Split = 2,       // 拆分
    OptionCombineType_ForceSplit = 3,  // 强拆
};

// 组合策略类型
enum OptionCombineStrategy {
    OptionCombineStrategy_CNSJC = 1,  // 认购牛市价差策略
    OptionCombineStrategy_CXSJC = 2,  // 认购熊市价差策略
    OptionCombineStrategy_PXSJC = 3,  // 认沽熊市价差策略
    OptionCombineStrategy_PNSJC = 4,  // 认沽牛市价差策略
    OptionCombineStrategy_KS = 5,     // 跨式空头
    OptionCombineStrategy_KKS = 6,    // 宽跨式空头
    OptionCombineStrategy_ZBD = 7,    // 保证金开仓转备兑
};

// 期权组合状态
enum OptionCombineStatus {
    OptionCombineStatus_Combined = 1,  // 组合
    OptionCombineStatus_Splitted = 2,  // 拆分完成
};

// 行权方向
enum ExerciseSide {
    ExerciseSide_Active = 1,     // 主动行权
    ExerciseSide_Passive = 2,    // 被动行权
};

// 备兑标志
enum CoverFlag {
    CoverFlag_Covered = 1,       // 备兑
    CoverFlag_Uncovered = 2,     // 非备兑
};

// 期权证券业务
enum OptionSecurityType {
    OptionSecurityType_Placeholder = 0,
    OptionSecurityType_Buy_Open = 1,                   // 买入开仓
    OptionSecurityType_Sell_Close = 2,                 // 卖出平仓
    OptionSecurityType_Sell_Open = 3,                  // 卖出开仓
    OptionSecurityType_Buy_Close = 4,                  // 买入平仓
    OptionSecurityType_Covered_Open = 5,               // 备兑开仓
    OptionSecurityType_Covered_Close = 6,              // 备兑平仓
    OptionSecurityType_Call_Exercise = 7,              // 认购行权
    OptionSecurityType_Put_Exercise = 8,               // 认沽行权
    OptionSecurityType_Security_Lock = 9,              // 证券锁定（股票期权）
    OptionSecurityType_Security_Unlock = 10,           // 证券解锁（股票期权）
    OptionSecurityType_Contract_Hedge = 11,            // 合约对冲
    OptionSecurityType_Underlying_Netting_Receipt = 12,      // 标的净额实收
    OptionSecurityType_Underlying_Netting_Payment = 13,      // 标的净额实付
    OptionSecurityType_Cash_Settlement_Receipt = 14,         // 现金结算实收
    OptionSecurityType_Cash_Settlement_payment = 15,         // 现金结算实付
    OptionSecurityType_Exercise_Disposal_Declaration = 16,   // 期权行权处置申报
    OptionSecurityType_Disposal_Declaration_Return = 17,     // 期权处置申报返还
    OptionSecurityType_Transfer_In_Disposal = 18,            // 划入处置
    OptionSecurityType_Transfer_Out_Disposal = 19,           // 划出处置
    OptionSecurityType_Call_Auto_Exercise = 20,              // 认购自动行权
    OptionSecurityType_Put_Auto_Exercise = 21,               // 认沽自动行权
    OptionSecurityType_Margin_Query = 22,                    // 保证金查询
    OptionSecurityType_Advance_Security = 23,                // 垫券
    OptionSecurityType_Return_Security = 24,                 // 还券
    OptionSecurityType_Discharge_Customer = 25,              // 待清偿扣划客户
    OptionSecurityType_Discharge_Self = 26,                  // 待清偿扣划自营
    OptionSecurityType_Comb_Exercise = 27,                   // 行权指令合并申报
    OptionSecurityType_Covered_To_Uncovered = 28,            // 备兑转非备兑
    OptionSecurityType_Comb_Strategy = 29,                   // 构建组合策略
    OptionSecurityType_Split_Strategy = 30,                  // 解除组合策略
    OptionSecurityType_General_RFQ = 31,                     // 普通询价
    OptionSecurityType_Position_Profit = 32,                 // 累积持仓盈亏
    OptionSecurityType_Exercise_Profit = 33,                 // 行权平仓盈亏
    OptionSecurityType_Security_Delivery = 34,               // 证券交收
    OptionSecurityType_Trading_Fee_Concession = 35,          // 交易经手费优惠
};

// 期权证券业务行为
enum OptionSecurityAction {
    OptionSecurityAction_Placeholder = 0,
    OptionSecurityAction_Buy_Call_Open = 1,                  // 买入认购开仓
    OptionSecurityAction_Sell_Call_Close = 2,                // 卖出认购平仓
    OptionSecurityAction_Buy_Put_Open = 3,                   // 买入认沽开仓
    OptionSecurityAction_Sell_Put_Close = 4,                 // 卖出认沽平仓
    OptionSecurityAction_Sell_Call_Open = 5,                 // 卖出认购开仓
    OptionSecurityAction_Buy_Call_Close = 6,                 // 买入认购平仓
    OptionSecurityAction_Sell_Put_Open = 7,                  // 卖出认沽开仓
    OptionSecurityAction_Buy_Put_Close = 8,                  // 买入认沽平仓
    OptionSecurityAction_Covered_Call_Open = 9,              // 备兑认购开仓
    OptionSecurityAction_Covered_Call_Close = 10,            // 备兑认购平仓
    OptionSecurityAction_Call_Exercise = 11,                 // 认购行权行权方
    OptionSecurityAction_Call_Exercise_Short_Uncovered = 12, // 认购行权被行权方（非备兑）
    OptionSecurityAction_Put_Exercise = 13,                  // 认沽行权行权方
    OptionSecurityAction_Put_Exercise_Short = 14,            // 认沽行权被行权方
    OptionSecurityAction_Call_Exercise_Short_Covered = 15,   // 认购行权被行权方（备兑） 
    OptionSecurityAction_Buy_Sterilisation = 16,             // 买入冲销
    OptionSecurityAction_Uncovered_Hedge = 17,               // 非备兑对冲
    OptionSecurityAction_Covered_Hedge = 18,                 // 备兑对冲
    OptionSecurityAction_Covered_To_Uncovered = 19,          // 备兑转非备兑（义务仓）
    OptionSecurityAction_Uncovered_To_Covered = 20,          // 非备兑转备兑（备兑仓）
    OptionSecurityAction_Netting_Receipt = 21,               // 证券净额实收
    OptionSecurityAction_Netting_Payment = 22,               // 证券净额实付
    OptionSecurityAction_Cash_Settlement_Payment = 23,       // 现金结算实付
    OptionSecurityAction_Cash_Settlement_Receipt = 24,       // 现金结算实收
    OptionSecurityAction_Exercise_Disposal_Declaration = 25, // 期权行权处置申报
    OptionSecurityAction_Disposal_Declaration_Return = 26,   // 期权处置申报返还
    OptionSecurityAction_Put_Exercise_E_Cash_Receipt = 27,   // 认沽行权E日现金结算实收
    OptionSecurityAction_Put_Exercise_E_Cash_Payment = 28,   // 认沽行权E日现金结算实付
};

// 期权业务代码
enum OptionBusinessCode {
    OptionBusinessCode_Placeholder = 0,
    OptionBusinessCode_Call_Exercise_Delivery = 1,            // 认购期权行权方资券交收
    OptionBusinessCode_Call_Exercise_Short_Delivery = 2,      // 认购期权被行权方资券交收(非备兑)
    OptionBusinessCode_Put_Exercise_Delivery = 3,             // 认沽期权行权方资券交收
    OptionBusinessCode_Put_Exercise_Short_Delivery = 4,       // 认沽期权被行权方资券交收
    OptionBusinessCode_Security_Netting_Shall = 5,            // 行权证券净额应收付
    OptionBusinessCode_Security_Netting_Actual = 6,           // 行权证券净额实收付
    OptionBusinessCode_Cash_Settlement = 7,                   // 行权现金结算
    OptionBusinessCode_Debt_Deduct_Security = 8,              // 行权欠款扣券
    OptionBusinessCode_Covered_Lock = 9,                      // 备兑期权证券锁定
    OptionBusinessCode_Disposal_Payment = 10,                 // 证券转处置还款还券
    OptionBusinessCode_Disposal_In = 11,                      // 证券转处置划入
    OptionBusinessCode_Disposal_Advance = 12,                 // 证券转处置垫资
    OptionBusinessCode_Sell_Security_Fund_In = 13,            // 卖券资金划入
    OptionBusinessCode_Sell_Security_Payment = 14,            // 卖券归还券商垫资
    OptionBusinessCode_E_Margin_Unfreeze = 15,                // E日未指派行权保证金释放
    OptionBusinessCode_Penalty_Interest = 16,                 // 扣缴罚息
    OptionBusinessCode_Freeze_Amt = 17,                       // 认购行权方冻结行权金额
    OptionBusinessCode_Freeze_Underlying = 18,                // 认沽权方冻结行权标的
    OptionBusinessCode_E_Fee_Receipt = 19,                    // E日行权费用收取
    OptionBusinessCode_Call_Exercise_Short_Covered = 20,      // 认购期权被行权方(备兑)
    OptionBusinessCode_E1_Fee_Receipt = 21,                   // E+1日行权费用收取
    OptionBusinessCode_Maintenance_Margin_Adjustment = 22,    // 维持保证金调整
    OptionBusinessCode_Lock_Fund_Unfreeze = 23,               // 行权锁定金额释放
    OptionBusinessCode_Lock_Margin_Unfreeze_Call = 24,        // 行权锁定保证金释放(认购)
    OptionBusinessCode_Lock_Margin_Unfreeze_Put = 25,         // 行权锁定保证金释放(认沽)
    OptionBusinessCode_Advance_Payment = 26,                  // 单账户垫资还款
    OptionBusinessCode_Disposal_Repay_Debt = 27,              // 证券转处置还负债
    OptionBusinessCode_Penalty_Interest_Relief = 28,          // 单账户垫资罚息减免
    OptionBusinessCode_Clearing_Fee_Unfreeze = 29,            // 行权结算费解冻
    OptionBusinessCode_Trans_Fee_Unfreeze = 30,               // 行权过户费解冻
    OptionBusinessCode_Clearing_Fee_Delivery = 31,            // 行权结算费交收
    OptionBusinessCode_Trans_Fee_Delivery = 32,               // 行权过户费交收
};

// 期权组合策略合约到期日限制
enum SameExpiryDate {
    SameExpiryDate_Placeholder = 0,
    SameExpiryDate_Same = 1,              // 相同同到期日
    SameExpiryDate_Diff = 2,              // 不同到期日
    SameExpiryDate_None = 3,              // 到期日无要求
};

// 期权组合策略合约标的限制
enum SameUnderlying {
    SameUnderlying_Placeholder = 0,
    SameUnderlying_Same = 1,           // 相同标的
    SameUnderlying_Diff = 2,           // 不同标的
    SameUnderlying_None = 3,           // 标的无要求              
};

// 展期审批状态
enum ApprovalStatus {
    ApprovalStatus_NoCheck = 1,    // 未审批
    ApprovalStatus_CheckSucc = 2,  // 审批通过
    ApprovalStatus_CheckFail = 3,  // 审批不过
    ApprovalStatus_Expired = 4,    // 过期作废
    ApprovalStatus_Cancelled = 5,  // 已撤单
    ApprovalStatus_Extended = 6,   // 已展期处理
};

// 申请状态
enum ApplyStatus {
    ApplyStatus_NotApproved = 1,  // 未审批
    ApplyStatus_Approval = 2,     // 审批通过
    ApplyStatus_Reject = 3,       // 审批拒绝
    ApplyStatus_Cancelled = 4,    // 已撤销
    ApplyStatus_Expired = 5,      // 已过期
};

// 投票意向
enum VotingPreference {
    VotingPreference_Default = 1,  // 默认
    VotingPreference_Agree = 2,    // 同意
    VotingPreference_Reject = 3,   // 反对
    VotingPreference_Waiver = 4,   // 弃权
};

// 收费模式
enum LockChargeType {
    LockChargeType_SegmentMode = 1,  // 分段模式
    LockChargeType_PricingMode = 2,  // 定价模式
};

// 首次进入模式
enum FirstInMode {
    FirstInMode_ManualLockEnter = 1,  // 人工锁券合同录入
    FirstInMode_PreApproveEnter = 2,  // 预约审批录入
    FirstInMode_MatchReceive = 3,     // 撮合确认到达
};

// 锁券状态
enum LockStatus {
    LockStatus_UnAssigned = '0',   // 有未分配
    LockStatus_Assigned = '1',     // 已分配
    LockStatus_Outstanding = '2',  // 过期未偿还
    LockStatus_kRepaid = '3',      // 过期已偿还
};

// 合约状态
enum ContractLifeStatus {
    ContractLifeStatus_UnRepay = 0,      // 未偿还
    ContractLifeStatus_Repay = 1,        // 已偿还
    ContractLifeStatus_OutStanding = 2,  // 合约未平仓
};

// 密码类型
enum PasswordType {
    PasswordType_Fund = 1,   // 资金密码
    PasswordType_Trade = 2,  // 交易密码
};

// 创业板标识
enum CYBFlag {
    CYBFlag_False = '0',  // 否，不是创业板
    CYBFlag_True = '1',   // 真，是创业板
};

// 科创板标识
enum KCBFlag {
    KCBFlag_False = '0',  // 否，不是科创板
    KCBFlag_True = '1',   // 真，是科创板
};

// 资质状态
enum QualificationStatus {
    QualificationStatus_False = '0',  // 否，无资质
    QualificationStatus_True = '1',   // 真，有资质
};

// 约券审批状态
enum ReserveStkApprovalStatus {
    ReserveStkApprovalStatus_NoCheck = '0',      // 未复核
    ReserveStkApprovalStatus_CheckSucc = '1',    // 复核通过
    ReserveStkApprovalStatus_CheckCancel = '2',  // 复核取消
    ReserveStkApprovalStatus_CheckLock = '3',    // 复核锁定
};

// 预约状态
enum BookingStatus {
    BookingStatus_Init = '0',      // 初始
    BookingStatus_valid = '1',     // 有效
    BookingStatus_Cancel = '2',    // 撤回
    BookingStatus_Reject = '3',    // 审批拒绝
    BookingStatus_Expired = '4',   // 过期失效
    BookingStatus_Checking = '5',  // 审批中
};

// 审批选项
enum ApprovalOptions {
    ApprovalOptions_NotEnoughAndGiveUp = '0',       // 直锁不足放弃
    ApprovalOptions_TransferPreLock = '1',          // 直转锁券预锁
    ApprovalOptions_TransferInfuseIntention = '2',  // 直转融入意向
    ApprovalOptions_FirstLockRestPreLock = '3',     // 先锁剩转预锁
    ApprovalOptions_FirstLockRestIntention = '4',   // 先锁剩转意向
    ApprovalOptions_DoNothing = '9',                // 什么都不做
};

// 银行证券业务类型
enum BankSecBizType {
    BankSecBizType_BankToSecurity = '1',           // 银行转证券
    BankSecBizType_SecurityToBank = '2',           // 证券转银行
    BankSecBizType_QrySecBalance = '3',            // 查证券余额
    BankSecBizType_QryBankBalance = '4',           // 查银行余额
    BankSecBizType_BankToSecurity_Reversal = '5',  // 冲正银行转证券
    BankSecBizType_SecurityToBank_Reversal = '6',  // 冲正证券转银行
    BankSecBizType_OpenAccount = '7',              // 开户
    BankSecBizType_CloseAccount = '8',             // 销户（券商）
    BankSecBizType_TransferAdjust = 'M',           // 转帐调整
};

// 银行证券业务处理状态
enum BankSecBizStatus {
    BankSecBizStatus_Accepted = '0',            // 已受理
    BankSecBizStatus_Submitted = '1',           // 已报
    BankSecBizStatus_Success = '2',             // 成功
    BankSecBizStatus_Failed = '3',              // 失败
    BankSecBizStatus_Timeout = '4',             // 超时
    BankSecBizStatus_Reversing = '5',           // 待冲正
    BankSecBizStatus_Reversed = '6',            // 已冲正
    BankSecBizStatus_AdjustToSuccess = '7',     // 调整为成功
    BankSecBizStatus_AdjustToFailed = '8',      // 调整为失败
    BankSecBizStatus_WaitReversalResult = '9',  // 等待冲正结果
};

// 银行证券冲正标志
enum BankSecStrikeFlag {
    BankSecStrikeFlag_ReverseByBill = '0',          // 流水冲正（实时）
    BankSecStrikeFlag_AdjustByBill = '1',           // 流水调整（事后）
    BankSecStrikeFlag_NoReportAfterReversal = '5',  // 已发冲正未回报
    BankSecStrikeFlag_ReportedAfterReversal = '6',  // 已发冲正已回报
    BankSecStrikeFlag_AdjustToSuccess = '7',        // 调整为成功
    BankSecStrikeFlag_AdjustToFailed = '8',         // 调整为失败
};

// 查询方向
enum QueryDirection {
    QueryDirection_Backward = '0',  // 向后查，倒序
    QueryDirection_Forward = '1',   // 向前查，升序
};

// 信用方向
enum CreditDirect {
    CreditDirect_MarginBuy = '0',   // 证券融资交易
    CreditDirect_MarginSell = '1',  // 证券融券交易
};

// 信用交易类型
enum CreditType {
	CreditType_Placeholder = 0,
	CreditType_Normal = 1,        // 普通交易
	CreditType_CashLoan = 2,      // 融资交易
	CreditType_SecurityLoan = 3,  // 融券交易
};

// 负债发生方向
enum DebtsOccurDirect {
	DebtsOccurDirect_Placeholder = ' ',   // 未定义
    DebtsOccurDirect_Increase = '1',      // 增加
    DebtsOccurDirect_Repay = '2',         // 偿还
    DebtsOccurDirect_ReliefAdjust = '3',  // 减免调整
};

// 负债类型
enum CreditDebtsType {
	CreditDebtsType_Placeholder = ' ',            // 未定义
    CreditDebtsType_UnUsedFee = '1',              // 锁券占用费
    CreditDebtsType_OverUnUsedFee = '2',          // 逾期锁券占用费
    CreditDebtsType_PuniOverUnUsedFee = '3',      // 逾期锁券占用费罚息
    CreditDebtsType_ViolateFee = '4',             // 锁券违约费
    CreditDebtsType_OverViolateFee = '5',         // 锁券逾期违约费
    CreditDebtsType_PuniOverViolateFee = '6',     // 锁券逾期违约罚息
    CreditDebtsType_FundDebts = 'a',              // 融资负债本金
    CreditDebtsType_StkMarketValue = 'b',         // 融券负债市值
    CreditDebtsType_FundFee = 'c',                // 融资利息
    CreditDebtsType_StkFee = 'd',                 // 融券费用
    CreditDebtsType_FundOverFee = 'e',            // 融资逾期利息
    CreditDebtsType_StkOverFee = 'f',             // 融券逾期费用
    CreditDebtsType_PuniFundOverFee = 'g',        // 融资逾期利息罚息
    CreditDebtsType_PuniStkOverFee = 'h',         // 融券逾期费用罚息
    CreditDebtsType_StkOverRights = 'i',          // 融券逾期权益
    CreditDebtsType_PuniStkOverRights = 'j',      // 融券逾期权益罚息
    CreditDebtsType_PuniFundOverDebts = 'k',      // 融资逾期负债罚息
    CreditDebtsType_PuniStkOverDebts = 'l',       // 融券逾期负债罚息
    CreditDebtsType_FundProFee = 'm',             // 融资承诺费
    CreditDebtsType_StkProFee = 'n',              // 融券承诺费
    CreditDebtsType_FundManageFee = 'o',          // 融资管理费
    CreditDebtsType_StkManageFee = 'p',           // 融券管理费
    CreditDebtsType_FundOverManageFee = 'q',      // 融资逾期管理费
    CreditDebtsType_StkOverManageFee = 'r',       // 融券逾期管理费
    CreditDebtsType_PuniFundOverManageFee = 's',  // 融资逾期管理费罚息
    CreditDebtsType_PuniStkOverManageFee = 't',   // 融券逾期管理费罚息
    CreditDebtsType_StkDividendRight = 'u',       // 融券红利权益
    CreditDebtsType_StkDividendStkRight = 'v',    // 融券红股权益
};

// 负债偿还方式
enum RepayWay {
    RepayWay_Placeholder = ' ',                 // 未定义
    RepayWay_RegularDeduct = '0',               // 定期扣收
    RepayWay_DirectRepay = '1',                 // 直接还款
    RepayWay_SellRepay = '2',                   // 卖券还款
    RepayWay_CloseDeduct = '3',                 // 平仓扣收
    RepayWay_BuySecuRepay = '5',                // 买券还券
    RepayWay_RightsDeduct = '6',                // 权益扣收
    RepayWay_MarginSellFinishedRepay = '7',     // 融券了结偿还
    RepayWay_MarginSellProfitRepay = '8',       // 融券盈利偿还
    RepayWay_ContractExpiredDeduct = '9',       // 合同到期扣收
    RepayWay_CashRepaySecu = 'A',               // 现金替代还券
    RepayWay_DebtsForceRepay = 'B',             // 合约强制还款
    RepayWay_ClearForceRepay = 'C',             // 清偿强制还款
    RepayWay_OverDueDeduct = 'Y',               // 每日逾期息费扣收
    RepayWay_NoSense = '*',                     // 无意义
    RepayWay_SubAdjust = 'Z',                   // 免息调整
};

// 回收状态
enum RecycleStatus {
    RecycleStatus_NoRecycle = 0,            // 未回收
    RecycleStatus_PartRecycle = 1,          // 部分回收
    RecycleStatus_FullRecycle = 2,          // 完全回收
};

// 回收类型
enum RecycleType {
    RecycleType_ManualRecycle = 0,          // 人工回收
    RecycleType_AutoRecycle = 1,            // 自动回收
};

// 违约状态
enum ViolationStatus {
    ViolationStatus_Normal = 0,             // 正常
    ViolationStatus_Violated = 1,           // 违约
};

// 处理标识
enum DealFlag {
    DealFlag_NoDeal = 0,                    // 未处理
    DealFlag_DealSucc = 1,                  // 已处理，处理成功
    DealFlag_DealFail = 2,                  // 处理失败
    DealFlag_Dealing = 3,                   // 处理中
};

// ETF公司内部分类
enum ETFType {
	ETFType_Placeholder = 0,
	ETFType_SingleMarket = 1,   // 单市场
	ETFType_CrossCountry = 2,   // 跨境
	ETFType_CrossMarket = 3,    // 跨市场
	ETFType_CurrencyETF = 4,    // 货币ETF
	ETFType_GoldETF = 5,        // 黄金ETF
	ETFType_BearerBondETF = 6,  // 单市场实物债券ETF
	ETFType_CashBondETF = 7,    // 现金债券ETF
    ETFType_LocalMarket = 8,    // 本市场ETF
    ETFType_CrossMarket_ByFundBusiSys = 9,    // 跨市场ETF（通过基金业务系统）
    ETFType_RealTimeMoneyFund = 10,    // 实时申赎货币基金
    ETFType_Stock = 11,                // 股票ETF
    ETFType_Lever = 12,                // 杠杆ETF
    ETFType_CommodityFutures = 13,     // 商品期货ETF
};

// 结算模式
enum SettleMode {
    SettleMode_Placeholder = 0,
    SettleMode_DVP = 1,             // 券款对付
    SettleMode_PAD = 2,             // 见券付款
    SettleMode_DAP = 3,             // 见款付券
    SettleMode_FOP = 4,             // 纯券过户
    SettleMode_BVB = 5,             // 券券对付
    SettleMode_BVP = 6,             // 券费对付
    SettleMode_BVBF = 7,            // 返券付费解券
    SettleMode_OTH = 9,             // 其他
};

// 报价方式
enum QuoteMode {
    QuoteMode_Error = 0,            // 错误报价
    QuoteMode_Both = 1,             // 双边报价
    QuoteMode_Buy = 2,              // 买报价
    QuoteMode_Sell = 3,             // 卖报价
    QuoteMode_Cancel = 4,           // 撤销报价
};

// 成交方式
enum MatchMode {
    MatchMode_MakeMarket = 0,       // 做市报价
    MatchMode_BothSide = 1,         // 双边报价
    MatchMode_Dialogue = 2,         // 对话报价
    MatchMode_Other = 3,            // 其他
};

// 转让类型
enum TransferType {
    TransferType_Other = '0',       // 其他类型
};

// 停牌标志
enum DelistFlag {
    DelistFlag_Normal = '0',        // 正常
    DelistFlag_Delisted = '1',      // 停牌
};

// 要约时段
enum OfferPeriod {
    OfferPeriod_Normal = '0',       // 要约正常期间
    OfferPeriod_CutOff = '1',       // 要约截止期间
    OfferPeriod_Pause = '2',        // 要约中止期间
    OfferPeriod_Finish = '3',       // 要约结束
    OfferPeriod_Delist = '4',       // 要约停牌
};

// 股东身份
enum ShareHolderRole {
    ShareHolderRole_A = 'A',        // A股股东
    ShareHolderRole_B = 'B',        // B股股东
    ShareHolderRole_C = 'C',        // 优先股股东
    ShareHolderRole_D = 'D',        // 恢复表决权的优先股股东
};

// 基金交易类别
enum FundOrderSide {
	FundOrderSide_240001 = 240001,	   //基金帐户开户
	FundOrderSide_240002 = 240002,	   //基金帐户销户
	FundOrderSide_240003 = 240003,	   //基金帐户修改
	FundOrderSide_240004 = 240004,	   //基金帐户冻结
	FundOrderSide_240005 = 240005,	   //基金帐户解冻
	FundOrderSide_240006 = 240006,	   //基金帐户挂失
	FundOrderSide_240007 = 240007,	   //基金帐户解挂
	FundOrderSide_240008 = 240008,	   //增加交易帐户
	FundOrderSide_240009 = 240009,	   //撤销交易帐户
	FundOrderSide_240010 = 240010,	   //开户指定
	FundOrderSide_240020 = 240020,	   //认购申请
	FundOrderSide_240021 = 240021,	   //预约认购
	FundOrderSide_240022 = 240022,	   //申购申请
	FundOrderSide_240023 = 240023,	   //预约申购
	FundOrderSide_240024 = 240024,	   //赎回申请
	FundOrderSide_240025 = 240025,	   //预约赎回
	FundOrderSide_240026 = 240026,	   //转托管
	FundOrderSide_240027 = 240027,	   //转托管入
	FundOrderSide_240028 = 240028,	   //转托管出
	FundOrderSide_240029 = 240029,	   //分红方式设置
	FundOrderSide_240031 = 240031,	   //份额外部冻结
	FundOrderSide_240032 = 240032,	   //份额外部解冻
	FundOrderSide_240033 = 240033,	   //非交易过户
	FundOrderSide_240034 = 240034,	   //非交易过户入
	FundOrderSide_240035 = 240035,	   //非交易过户出
	FundOrderSide_240036 = 240036,	   //基金转换
	FundOrderSide_240037 = 240037,	   //基金转换入
	FundOrderSide_240038 = 240038,	   //基金转换出
	FundOrderSide_240039 = 240039,	   //定期定额申购申请
	FundOrderSide_240052 = 240052,	   //撤单
	FundOrderSide_240053 = 240053,	   //预约撤单
	FundOrderSide_240058 = 240058,	   //变更交易帐号
	FundOrderSide_240059 = 240059,	   //定时定额开通
	FundOrderSide_240060 = 240060,	   //定时定额撤消
	FundOrderSide_240061 = 240061,	   //定时定额申购修改
	FundOrderSide_240063 = 240063,	   //定时定额赎回申请
	FundOrderSide_240080 = 240080,	   //基金确权
	FundOrderSide_240093 = 240093,	   //帐户内部冻结
	FundOrderSide_240094 = 240094,	   //帐户内部解冻
	FundOrderSide_240095 = 240095,	   //份额内部冻结
	FundOrderSide_240096 = 240096,	   //份额内部解冻
	FundOrderSide_240097 = 240097,	   //份额内部红冲
	FundOrderSide_240098 = 240098,	   //份额内部蓝补
	FundOrderSide_240099 = 240099,	   //内部撤单
	FundOrderSide_240101 = 240101,	   //基金帐户开户确认
	FundOrderSide_240102 = 240102,	   //基金帐户销户确认
	FundOrderSide_240103 = 240103,	   //基金帐户修改确认
	FundOrderSide_240104 = 240104,	   //基金帐户冻结确认
	FundOrderSide_240105 = 240105,	   //基金帐户解冻确认
	FundOrderSide_240106 = 240106,	   //基金帐户挂失确认
	FundOrderSide_240107 = 240107,	   //基金帐户解挂确认
	FundOrderSide_240108 = 240108,	   //增加交易帐户确认
	FundOrderSide_240109 = 240109,	   //撤销交易帐户确认
	FundOrderSide_240110 = 240110,	   //开户指定确认
	FundOrderSide_240120 = 240120,	   //认购确认
	FundOrderSide_240121 = 240121,	   //预约认购确认
	FundOrderSide_240122 = 240122,	   //申购确认
	FundOrderSide_240123 = 240123,	   //预约申购确认
	FundOrderSide_240124 = 240124,	   //赎回确认
	FundOrderSide_240125 = 240125,	   //预约赎回确认
	FundOrderSide_240126 = 240126,	   //转托管确认
	FundOrderSide_240127 = 240127,	   //转托管入确认
	FundOrderSide_240128 = 240128,	   //转托管出确认
	FundOrderSide_240129 = 240129,	   //分红方式设置确认
	FundOrderSide_240130 = 240130,	   //认购结果
	FundOrderSide_240131 = 240131,	   //基金份额冻结确认
	FundOrderSide_240132 = 240132,	   //基金份额解冻确认
	FundOrderSide_240133 = 240133,	   //非交易过户确认
	FundOrderSide_240134 = 240134,	   //非交易过户入确认
	FundOrderSide_240135 = 240135,	   //非交易过户出确认
	FundOrderSide_240136 = 240136,	   //基金转换转出确认
	FundOrderSide_240137 = 240137,	   //基金转换转入确认
	FundOrderSide_240138 = 240138,	   //基金转换转出确认
	FundOrderSide_240139 = 240139,	   //定期定额申购确认
	FundOrderSide_240140 = 240140,	   //退款
	FundOrderSide_240141 = 240141,	   //补款
	FundOrderSide_240142 = 240142,	   //强行赎回
	FundOrderSide_240143 = 240143,	   //分红
	FundOrderSide_240144 = 240144,	   //强行调增
	FundOrderSide_240145 = 240145,	   //强行调减
	FundOrderSide_240146 = 240146,	   //配号
	FundOrderSide_240149 = 240149,	   //募集失败
	FundOrderSide_240150 = 240150,	   //基金清盘
	FundOrderSide_240151 = 240151,	   //基金终止
	FundOrderSide_240152 = 240152,	   //撤单确认
	FundOrderSide_240153 = 240153,	   //预约撤单确认
	FundOrderSide_240157 = 240157,	   //红利解冻
	FundOrderSide_240158 = 240158,	   //变更交易帐号确认
	FundOrderSide_240159 = 240159,	   //定额申购开通确认
	FundOrderSide_240160 = 240160,	   //定额申购撤消确认
	FundOrderSide_240161 = 240161,	   //定额申购修改确认
	FundOrderSide_240176 = 240176,	   //基金投顾费用扣收
	FundOrderSide_240177 = 240177,	   //基金投顾费用冻结
	FundOrderSide_240178 = 240178,	   //基金投顾费用解冻
	FundOrderSide_240180 = 240180,	   //基金确权确认
	FundOrderSide_240199 = 240199,	   //内部撤单确认
	FundOrderSide_240301 = 240301,	   //基金帐户开户失败
	FundOrderSide_240302 = 240302,	   //基金帐户销户失败
	FundOrderSide_240303 = 240303,	   //基金帐户修改失败
	FundOrderSide_240304 = 240304,	   //基金帐户冻结失败
	FundOrderSide_240305 = 240305,	   //基金帐户解冻失败
	FundOrderSide_240306 = 240306,	   //基金帐户挂失失败
	FundOrderSide_240307 = 240307,	   //基金帐户解挂失败
	FundOrderSide_240308 = 240308,	   //增加交易帐户失败
	FundOrderSide_240309 = 240309,	   //撤销交易帐户失败
	FundOrderSide_240310 = 240310,	   //开户指定失败
	FundOrderSide_240311 = 240311,	   //非居民账户设置
	FundOrderSide_240312 = 240312,	   //非居民账户删除
	FundOrderSide_240320 = 240320,	   //认购失败
	FundOrderSide_240321 = 240321,	   //预约认购失败
	FundOrderSide_240322 = 240322,	   //申购失败
	FundOrderSide_240323 = 240323,	   //预约申购失败
	FundOrderSide_240324 = 240324,	   //赎回申请失败
	FundOrderSide_240325 = 240325,	   //预约赎回失败
	FundOrderSide_240326 = 240326,	   //转托管失败
	FundOrderSide_240327 = 240327,	   //转托管入失败
	FundOrderSide_240328 = 240328,	   //转托管出失败
	FundOrderSide_240329 = 240329,	   //设置分红方式失败
	FundOrderSide_240330 = 240330,	   //认购成立失败
	FundOrderSide_240331 = 240331,	   //份额冻结失败
	FundOrderSide_240332 = 240332,	   //份额解冻失败
	FundOrderSide_240333 = 240333,	   //非交易过户失败
	FundOrderSide_240334 = 240334,	   //非交易过户入失败
	FundOrderSide_240335 = 240335,	   //非交易过户出失败
	FundOrderSide_240336 = 240336,	   //转换失败
	FundOrderSide_240337 = 240337,	   //转换入失败
	FundOrderSide_240338 = 240338,	   //转换出失败
	FundOrderSide_240339 = 240339,	   //定时定额投资失败
	FundOrderSide_240352 = 240352,	   //撤单失败
	FundOrderSide_240353 = 240353,	   //预约撤单失败
	FundOrderSide_240359 = 240359,	   //定额申购开通失败
	FundOrderSide_240360 = 240360,	   //定额申购撤消失败
	FundOrderSide_240361 = 240361,	   //定额申购修改失败
	FundOrderSide_240380 = 240380,	   //基金确权失败
	FundOrderSide_240399 = 240399,	   //内部撤单失败
	FundOrderSide_240401 = 240401,	   //增加基金公司参数
	FundOrderSide_240402 = 240402,	   //修改基金公司参数
	FundOrderSide_240403 = 240403,	   //删除基金公司参数
	FundOrderSide_240404 = 240404,	   //增加基金信息参数
	FundOrderSide_240405 = 240405,	   //修改基金信息参数
	FundOrderSide_240406 = 240406,	   //删除基金信息参数
	FundOrderSide_240407 = 240407,	   //增加基金交易类型
	FundOrderSide_240408 = 240408,	   //修改基金交易类型
	FundOrderSide_240409 = 240409,	   //删除基金交易类型
	FundOrderSide_240410 = 240410,	   //增加基金错误代码
	FundOrderSide_240411 = 240411,	   //修改基金错误代码
	FundOrderSide_240412 = 240412,	   //删除基金错误代码
	FundOrderSide_240413 = 240413,	   //增加公司折扣库
	FundOrderSide_240414 = 240414,	   //修改公司折扣库
	FundOrderSide_240415 = 240415,	   //删除公司折扣库
	FundOrderSide_240416 = 240416,	   //增加公司折扣模板
	FundOrderSide_240417 = 240417,	   //修改公司折扣模板
	FundOrderSide_240418 = 240418,	   //删除公司折扣模板
	FundOrderSide_240419 = 240419,	   //增加基金总量控制
	FundOrderSide_240420 = 240420,	   //修改基金总量控制
	FundOrderSide_240421 = 240421,	   //删除基金总量控制
	FundOrderSide_240422 = 240422,	   //增加基金费率参数
	FundOrderSide_240423 = 240423,	   //修改基金费率参数
	FundOrderSide_240424 = 240424,	   //删除基金费率参数
	FundOrderSide_240425 = 240425,	   //修改基金赎回交收
	FundOrderSide_240427 = 240427,	   //增加基金销售机构
	FundOrderSide_240428 = 240428,	   //修改基金销售机构
	FundOrderSide_240429 = 240429,	   //删除基金销售机构
	FundOrderSide_240430 = 240430,	   //增加基金销售人员
	FundOrderSide_240431 = 240431,	   //修改基金销售人员
	FundOrderSide_240432 = 240432,	   //删除基金销售人员
	FundOrderSide_240433 = 240433,	   //增加分数等级关系
	FundOrderSide_240434 = 240434,	   //修改分数等级关系
	FundOrderSide_240435 = 240435,	   //删除分数等级关系
	FundOrderSide_240436 = 240436,	   //增加客户问卷结果
	FundOrderSide_240437 = 240437,	   //修改客户问卷结果
	FundOrderSide_240438 = 240438,	   //删除客户问卷结果
	FundOrderSide_240439 = 240439,	   //增加交易限制结果
	FundOrderSide_240440 = 240440,	   //修改交易限制结果
	FundOrderSide_240441 = 240441,	   //删除交易限制结果
	FundOrderSide_240442 = 240442,	   //基金成本设置
	FundOrderSide_240443 = 240443,	   //电子签名约定书签
	FundOrderSide_240444 = 240444,	   //电子签名约定书取
	FundOrderSide_240445 = 240445,	   //风险揭示书签署
	FundOrderSide_240446 = 240446,	   //风险揭示书修改
	FundOrderSide_240447 = 240447,	   //风险揭示书取消
	FundOrderSide_240448 = 240448,	   //电子合同签署
	FundOrderSide_240449 = 240449,	   //电子合同补正
	FundOrderSide_240450 = 240450,	   //电子合同取消
	FundOrderSide_240451 = 240451,	   //下载电子合同
	FundOrderSide_240452 = 240452,	   //基金场内代码增加
	FundOrderSide_240453 = 240453,	   //基金场内代码删除
	FundOrderSide_240454 = 240454,	   //基金场内代码修改
	FundOrderSide_240455 = 240455,	   //基金资金结算方式
	FundOrderSide_240456 = 240456,	   //基金资金结算方式
	FundOrderSide_240457 = 240457,	   //基金资金结算方式
	FundOrderSide_240458 = 240458,	   //君得惠重新确认
	FundOrderSide_240459 = 240459,	   //基金现金账户签约
	FundOrderSide_240460 = 240460,	   //基金现金账户解约
	FundOrderSide_240461 = 240461,	   //基金现金账户修改
	FundOrderSide_240464 = 240464,	   //基金现金产品增加
	FundOrderSide_240465 = 240465,	   //基金现金产品修改
	FundOrderSide_240466 = 240466,	   //基金现金产品删除
	FundOrderSide_240467 = 240467,	   //基金现金解约处理
	FundOrderSide_240468 = 240468,	   //赎回可用导入审查
	FundOrderSide_240469 = 240469,	   //赎回可用应急处理
	FundOrderSide_240470 = 240470,	   //基金风险提示签署
	FundOrderSide_240471 = 240471,	   //参与集合理财计划
	FundOrderSide_240472 = 240472,	   //退出集合理财计划
	FundOrderSide_240473 = 240473,	   //基金现金异常处理
	FundOrderSide_240474 = 240474,	   //基金公司接口模板
	FundOrderSide_240475 = 240475,	   //基金公司接口模板
	FundOrderSide_240476 = 240476,	   //基金公司接口模板
	FundOrderSide_240477 = 240477,	   //接口模板字典参数
	FundOrderSide_240478 = 240478,	   //接口模板字典参数
	FundOrderSide_240479 = 240479,	   //接口模板字典参数
	FundOrderSide_240480 = 240480,	   //接口模板文件字典
	FundOrderSide_240481 = 240481,	   //接口模板文件字典
	FundOrderSide_240482 = 240482,	   //接口模板文件字典
	FundOrderSide_240483 = 240483,	   //基金公司文件路径
	FundOrderSide_240484 = 240484,	   //基金公司文件路径
	FundOrderSide_240485 = 240485,	   //基金公司文件路径
	FundOrderSide_240486 = 240486,	   //基金其他信息设置
	FundOrderSide_240487 = 240487,	   //现金产品预约取款
	FundOrderSide_240488 = 240488,	   //现金产品预约修改
	FundOrderSide_240489 = 240489,	   //现金产品预约取消
	FundOrderSide_240490 = 240490,	   //基金定投处理
	FundOrderSide_240491 = 240491,	   //基金配股代码增加
	FundOrderSide_240492 = 240492,	   //基金配股代码修改
	FundOrderSide_240493 = 240493,	   //基金配股代码删除
	FundOrderSide_240494 = 240494,	   //基金折算率增加
	FundOrderSide_240495 = 240495,	   //基金折算率修改
	FundOrderSide_240496 = 240496,	   //基金折算率删除
	FundOrderSide_240497 = 240497,	   //基金预约处理
	FundOrderSide_240498 = 240498,	   //基金申赎总额增加
	FundOrderSide_240499 = 240499,	   //基金申赎总额修改
	FundOrderSide_240500 = 240500,	   //基金申赎总额删除
	FundOrderSide_240501 = 240501,	   //基金资金拨入
	FundOrderSide_240502 = 240502,	   //基金资金拨出
	FundOrderSide_240503 = 240503,	   //基金撤单拨入
	FundOrderSide_240504 = 240504,	   //基金废单拨入
	FundOrderSide_240505 = 240505,	   //基金杂费拨出
	FundOrderSide_240506 = 240506,	   //基金杂费拨入
	FundOrderSide_240507 = 240507,	   //基金红利拨入
	FundOrderSide_240508 = 240508,	   //基金认购拨出
	FundOrderSide_240509 = 240509,	   //基金申购拨出
	FundOrderSide_240510 = 240510,	   //定时定额申购拨出
	FundOrderSide_240511 = 240511,	   //基金赎回拨入
	FundOrderSide_240512 = 240512,	   //基金强行赎回拨入
	FundOrderSide_240513 = 240513,	   //基金认购失败拨入
	FundOrderSide_240514 = 240514,	   //基金申购失败拨入
	FundOrderSide_240515 = 240515,	   //定时定额失败拨入
	FundOrderSide_240517 = 240517,	   //基金终止拨入
	FundOrderSide_240518 = 240518,	   //基金募集失败拨入
	FundOrderSide_240521 = 240521,	   //基金红股
	FundOrderSide_240522 = 240522,	   //基金份额强增
	FundOrderSide_240523 = 240523,	   //基金份额强减
	FundOrderSide_240524 = 240524,	   //基金转托管出
	FundOrderSide_240525 = 240525,	   //基金转托管入
	FundOrderSide_240526 = 240526,	   //基金转换转出
	FundOrderSide_240527 = 240527,	   //基金转换转入
	FundOrderSide_240528 = 240528,	   //基金非交易过户出
	FundOrderSide_240529 = 240529,	   //基金非交易过户入
	FundOrderSide_240530 = 240530,	   //基金认购结果
	FundOrderSide_240531 = 240531,	   //基金申购确认
	FundOrderSide_240532 = 240532,	   //基金定投申购确认
	FundOrderSide_240533 = 240533,	   //基金分红方式确认
	FundOrderSide_240534 = 240534,	   //基金认购确认
	FundOrderSide_240535 = 240535,	   //定时定额赎回拨入
	FundOrderSide_240540 = 240540,	   //基金T+0转出
	FundOrderSide_240541 = 240541,	   //基金T+0转入
	FundOrderSide_240542 = 240542,	   //基金T+0转出取消
	FundOrderSide_240543 = 240543,	   //基金T+0转入取消
	FundOrderSide_240544 = 240544,	   //现金产品解约撤销
	FundOrderSide_240600 = 240600,	   //资管转让专户增加
	FundOrderSide_240601 = 240601,	   //资管转让专户修改
	FundOrderSide_240602 = 240602,	   //资管转让专户删除
	FundOrderSide_240603 = 240603,	   //资管专户限额调整
	FundOrderSide_240604 = 240604,	   //客户转让限额设置
	FundOrderSide_240605 = 240605,	   //专户赎回业务处理
	FundOrderSide_240606 = 240606,	   //客户转让解冻处理
	FundOrderSide_240607 = 240607,	   //预约产品交易增加
	FundOrderSide_240608 = 240608,	   //预约产品交易修改
	FundOrderSide_240609 = 240609,	   //预约产品交易删除
	FundOrderSide_240612 = 240612,	   //产品转让限额设置
	FundOrderSide_240613 = 240613,	   //产品转让限额修改
	FundOrderSide_240614 = 240614,	   //产品转让限额删除
	FundOrderSide_240615 = 240615,	   //设置快速取现权限
	FundOrderSide_240616 = 240616,	   //资管增加专户确认
	FundOrderSide_240617 = 240617,	   //资管增加专户作废
	FundOrderSide_240618 = 240618,	   //资管修改专户确认
	FundOrderSide_240619 = 240619,	   //资管修改专户作废
	FundOrderSide_240620 = 240620,	   //资管删除专户确认
	FundOrderSide_240621 = 240621,	   //资管删除专户作废
	FundOrderSide_240630 = 240630,	   //基金报价产品增加
	FundOrderSide_240631 = 240631,	   //基金报价产品修改
	FundOrderSide_240632 = 240632,	   //基金报价产品删除
	FundOrderSide_240633 = 240633,	   //基金报价产品审查
	FundOrderSide_240634 = 240634,	   //基金纸质合同签署
	FundOrderSide_240635 = 240635,	   //设置T+0对账标志
	FundOrderSide_240636 = 240636,	   //基金理财产品预约
	FundOrderSide_240637 = 240637,	   //同步核心表至全局
	FundOrderSide_240638 = 240638,	   //同步全局基金机构
	FundOrderSide_240639 = 240639,	   //修改集合理财计划
	FundOrderSide_240640 = 240640,	   //增加基金补充风险
	FundOrderSide_240641 = 240641,	   //删除基金补充风险
	FundOrderSide_240642 = 240642,	   //修改基金补充风险
	FundOrderSide_240643 = 240643,	   //增加补充风险揭示
	FundOrderSide_240644 = 240644,	   //删除补充风险揭示
	FundOrderSide_240645 = 240645,	   //修改补充风险揭示
	FundOrderSide_240646 = 240646,	   //基金双录签署
	FundOrderSide_240647 = 240647,	   //基金双录修改
	FundOrderSide_240648 = 240648,	   //基金双录删除
	FundOrderSide_240649 = 240649,	   //基金双录批量作废
	FundOrderSide_240650 = 240650,	   //投资者身份设置
	FundOrderSide_240651 = 240651,	   //私募资金冻结
	FundOrderSide_240652 = 240652,	   //私募资金冻结取消
	FundOrderSide_240660 = 240660,	   //OTC双录签署
	FundOrderSide_240661 = 240661,	   //OTC双录修改
	FundOrderSide_240662 = 240662,	   //OTC双录删除
	FundOrderSide_240663 = 240663,	   //OTC双录批量作废
	FundOrderSide_240700 = 240700,	   //基金赎回剩余交收
	FundOrderSide_240701 = 240701,	   //允许外围系统开户
	FundOrderSide_240702 = 240702,	   //允许外围系统修改
	FundOrderSide_240703 = 240703,	   //基金产品揭示签署
	FundOrderSide_240720 = 240720,	   //华安T0账户签约
	FundOrderSide_240721 = 240721,	   //华安T0账户解约
	FundOrderSide_240722 = 240722,	   //华安T0账户修改
	FundOrderSide_240723 = 240723,	   //华安T0解约撤单
	FundOrderSide_240724 = 240724,	   //华安T0预约增加
	FundOrderSide_240725 = 240725,	   //华安T0预约修改
	FundOrderSide_240726 = 240726,	   //华安T0预约取消
	FundOrderSide_240727 = 240727,	   //T0快取限额增加
	FundOrderSide_240728 = 240728,	   //T0快取限额修改
	FundOrderSide_240729 = 240729,	   //T0快取限额删除
	FundOrderSide_240730 = 240730,	   //T0快取限额设置
	FundOrderSide_240731 = 240731,	   //华安T0产品增加
	FundOrderSide_240732 = 240732,	   //华安T0产品修改
	FundOrderSide_240733 = 240733,	   //华安T0产品删除
	FundOrderSide_240749 = 240749,	   //基金赎回交收申请
	FundOrderSide_240750 = 240750,	   //基金赎回交收复核
	FundOrderSide_240751 = 240751,	   //基金赎回交收复核
	FundOrderSide_240898 = 240898	   //快速过户申请
};

// 收费方式
enum OfShareClass
{
	OfShareClass_Placeholder = 0,		//未定义
	OfShareClass_ALL = 1,				//所有
	OfShareClass_Front = 2,				//前收费
	OfShareClass_Back = 3,				//后收费
	OfShareClass_Front_Back = 4,		//前端＋后端
};

// 开放式基金特殊备注类型
enum OfSpecialRemarkType {
	OfSpecialRemarkType_Combination_Number = 1,		// 基金组合编号
	OfSpecialRemarkType_Fixed_Plan = 2,				// 32位定投计划编号
};

// 通过标识
enum PassFlag {
	PassFlag_UnconditionalPass = 1,       // 无条件通过
	PassFlag_MatchPass = 2,               // 匹配通过
	PassFlag_ConditionalPass = 3,         // 有条件通过
	PassFlag_SpecialInvesExemptPass = 4   // 专投豁免通过
};

// 夜市委托标志
enum OfNightStatus {
	OfNightStatus_False = 1,			// 正常委托
	OfNightStatus_True = 2				// 夜市委托
};

// 策略类型
enum FundTacticsKind {
	FundTacticsKind_Placeholder = 0,
	FundTacticsKind_10 = 10,             // 最近价自动补篮
	FundTacticsKind_11 = 11,             // 盘口价自动补篮
	FundTacticsKind_12 = 12,             // 一档价自动补篮
	FundTacticsKind_13 = 13,             // 二档价自动补篮
	FundTacticsKind_14 = 14,             // 三档价自动补篮
	FundTacticsKind_15 = 15,             // 四档价自动补篮
	FundTacticsKind_16 = 16,             // 五档价自动补篮
	FundTacticsKind_20 = 20,             // 最近价非自动补篮
	FundTacticsKind_21 = 21,             // 盘口价非自动补篮
	FundTacticsKind_22 = 22,             // 一档价非自动补篮
	FundTacticsKind_23 = 23,             // 二档价非自动补篮
	FundTacticsKind_24 = 24,             // 三档价非自动补篮
	FundTacticsKind_25 = 25,             // 四档价非自动补篮
	FundTacticsKind_26 = 26              // 五档价非自动补篮
};

// 价格类型
enum FundPriceFlag {
	FundPriceFlag_Latest = 1,			// 最近价
	FundPriceFlag_Dish = 2,				// 盘口价
	FundPriceFlag_G1 = 3,				// 一档价
	FundPriceFlag_G2 = 4,				// 二档价
	FundPriceFlag_G3 = 5,				// 三档价
	FundPriceFlag_G4 = 6,				// 四档价
	FundPriceFlag_G5 = 7				// 五档价
};

// 基金公司
enum Ta_Code {
	Ta_Code_SZ = 8,						// 深圳登记
	TA_Code_SH = 19						// 上海登记
};

// 基金产品投资分类
enum FundProdKind {
	FundProdKind_Placeholder = 0,
	FundProdKind_1 = 1,					// '1' 债券、货币市场基金、债券基金等固定收益类, 低风险投资品种
	FundProdKind_2 = 2,					// '2' 股票、混合型基金、偏股型基金、股票型基金等权益类, 中低风险投资品种
	FundProdKind_3 = 3,					// '3' 期货、融资融券, 中风险投资品种
	FundProdKind_4 = 4,					// '4' 复杂或高风险金融产品, 中高风险投资品种
	FundProdKind_5 = 5,					// '5' 复杂或高风险金融产品, 高风险投资品种
	FundProdKind_9 = 9,					// '9' 其他产品
};

// 基金产品状态
enum FundProdStatus {
	FundProdStatus_0 = 0,				// '0’正常开放，
	FundProdStatus_1 = 1,				// ’1’认购时期，
	FundProdStatus_2 = 2,				// ’2’发行 成功，
	FundProdStatus_3 = 3,				// ’3’发行失败，
	FundProdStatus_4 = 4,				// '4’基金停止交易’,
	FundProdStatus_5 = 5,				// '5’停止申购，
	FundProdStatus_6 = 6,				// ’6’停止 赎回，
	FundProdStatus_7 = 7,				// '7’权益登记，
	FundProdStatus_8 = 8,				// ’8’红利发放，
	FundProdStatus_9 = 9,				// ’9’基金封闭，
	FundProdStatus_10 = 10				// ’a’基金终止’	
};

// 基金产品风险等级
enum FundProdRiskLevel {
	FundProdRiskLevel_Placeholder = 0,
	FundProdRiskLevel_1 = 1,			// 1低风险
	FundProdRiskLevel_2 = 2,			// 2中低风险
	FundProdRiskLevel_3 = 3,			// 3中风险
	FundProdRiskLevel_4 = 4,			// 4中高风险
	FundProdRiskLevel_5 = 5,			// 5高风险
};

// 基金亏损等级
enum FundProdDeficitLevel {
	FundProdDeficitLevel_Placeholder = 0,
	FundProdDeficitLevel_1 = 1,			// 本金保障或造成本金损失可能性极低
	FundProdDeficitLevel_2 = 2,			// 尽可能保证本金安全
	FundProdDeficitLevel_3 = 3,			// 可能造成一定甚至较大损失
	FundProdDeficitLevel_4 = 4,			// 可能造成超过本金的损失
};

// 基金合同类型
enum FundContractType {
	FundContractType_0 = 0,				// '0'无合同
	FundContractType_1 = 1,				// '1'纸质合同
	FundContractType_2 = 2,				// '2'电子合同

};

// 基金电子合同签订标志
enum FundContractSigFlag {
	FundContractSigFlag_0 = 0,			// '0'不需要签订
	FundContractSigFlag_1 = 1,			// '1'需要签订普通电子合同
	FundContractSigFlag_2 = 2,			// ‘2’需要签订数字签名电子合同

};

// 巨额赎回标志
enum RedeemType {
	RedeemType0 = 0,					// 取消
	RedeemType1 = 1						// 顺延
};

// 分红方式
enum FundDividMethod {
	FundDividMethod_Placeholder = 0,	// 未定义或者无意义
	FundDividMethod_Reinvestment = 1,	// 红利转投
	FundDividMethod_Cash = 2			// 现金分红
};

// 控制类别 
enum CtrlKinds {
	CtrlKinds_0 = '1',					// 直接还款
	CtrlKinds_1 = '2'					// 转账转出
};

// 账户类别
enum AccountFlag {
	AccountFlagGeneral = 1,			// 普通账户
	AccountFlagOrganiz = 2,			// 机构账户
	AccountFlagSelfManage = 3,		// 自营账户
	AccountFlagMarketing = 4,		// 做市商账户
};

// 证件类型
enum IdentifyType {
	IdentifyType_0 = 0,            // 身份证
	IdentifyType_1 = 1,            // 护照
	IdentifyType_2 = 2,            // 营业执照
	IdentifyType_3 = 3,            // 军官证
	IdentifyType_4 = 4,            // 港澳身份证
	IdentifyType_5 = 5,            // 台胞证
	IdentifyType_6 = 6,            // 其他
	IdentifyType_7 = 7,            // 组织机构编码证
};

// 深港通、深港通 业务类型
enum HKBusinessType {
	HKBusinessType_Placeholder = 0,
	HKBusinessType_H62 = 62,				// 沪港通：H62：投票业务
	HKBusinessType_H63 = 63,				// 沪港通：H63：公司收购
	HKBusinessType_H64 = 64,				// 沪港通：H64：公开配售
	HKBusinessType_H65 = 65,				// 沪港通：H65：供股
	HKBusinessType_H66 = 66,				// 沪港通：H66：红利股票选择权
	
	HKBusinessType_SGBG = 80,				// 深港通：SGBG: 收购保管 
	HKBusinessType_QPSB = 81,				// 深港通：QPSB：红利选择权申报
	HKBusinessType_PGRG = 82,				// 深港通：PGRG：公开配售申报和供股 申报
    HKBusinessType_TPSB = 83,               // 深港通：TPSB：投票申报
};

// 深港通、深港通 申报类型
enum HKBusinessReportType {
	HKBusinessReportType_Placeholder = 0,
	HKBusinessReportType_HCX = 1,			// 沪港通：HCX：业务查询
	HKBusinessReportType_HSB = 2,			// 沪港通：HSB：业务申报(H62 只有 HSB 类型)

	HKBusinessReportType_WT = 11,			// 深港通：WT：委托
	HKBusinessReportType_CX = 12,			// 深港通：CX：查询
	HKBusinessReportType_CD = 13,			// 深港通：CD：撤单
};

// ETF 认购状态
enum ETFSubscribeStatus {
	ETFSubscribeStatus_unSubscribe = 0,			// '0':未认购,
	ETFSubscribeStatus_Subscribed = 1,			// '1':已认购,
	ETFSubscribeStatus_Cancelled = 2,			// '2':已撤销,
	ETFSubscribeStatus_Expired = 3,				// '3':已作废,
	ETFSubscribeStatus_Accept = 4,				// '4':已处理
};

// ETF 认购撤单状态
enum ETFSubscribeCancelFlag {
	ETFSubscribeCancelFlag_Placeholder = 0,
	ETFSubscribeCancelFlag_Normal = 1,			// 'F':正常,
	ETFSubscribeCancelFlag_Cancelled = 2,		// 'T':撤单
};

// ETF 成分股来源
enum ETFStkSourceType {
	ETFStkSourceType_Placeholder = 0,			// 0:无视
	ETFStkSourceType_SelfManage = 1,			// 1:自营
	ETFStkSourceType_StockMaket = 2,			// 2:证金
};


// 大宗减持标识
enum BlockRestrictFlag {
    BlockRestrictFlag_False = '0',  // 非受限股份
    BlockRestrictFlag_True = '1',   // 受限股份
};

// 权限标志
enum PermissionFlag {
    PermissionFlag_False = 0,           // 未开通，不允许
    PermissionFlag_True = 1             // 已开通，允许
};

// 认购结果
enum SubscribeResult {
    SubscribeResult_Allow = 0,          // 可以参与申购
    SubscribeResult_Deny = 1,           // 禁止参与申购
    SubscribeResult_Must = 2,           // 必须参与申购
	SubscribeResult_NotIn = 3           // 未参与询价
};

// 大宗交易标志
enum BlockFlag {
    kBlockFlag_False = 0,   // 非大宗交易
    kBlockFlag_True = 1,    // 大宗交易
};

// 大宗交易，执行状态
enum BlockDealStatus {
	BlockDealStatus_Placeholder = 0,
	BlockDealStatus_NotApproved = 1,		// 未执行
	BlockDealStatus_Approval = 2,			// 执行申报结果
	BlockDealStatus_Fail = 3,				// 执行失败
};

// 大宗交易盘后定价, 价格类型
enum BlockPriceProperty {
	BlockPriceProperty_Placeholder = 0,
	BlockPriceProperty_Close = 1,			// 收盘价
	BlockPriceProperty_Avg = 2,				// 加权平均价
};


// 注册指令类型
enum DesignationTransType {
    DesignationTransType_Placeholder = 0,
    DesignationTransType_New = 1,          // 新注册请求
    DesignationTransType_Cancel = 3,       // 注册撤销
};

// 沪深港通通知类型
enum HKNoticeType {
	HKNoticeType_H01 = 1,				  //H01:权益登记通知信息
	HKNoticeType_H06 = 6,				  //H06:投票公告信息
	HKNoticeType_H12 = 2,				  //H12:投票议案信息
	HKNoticeType_H10 = 10,				  //H10:股份分拆合并信息
	HKNoticeType_H07 = 7,				  //H07:现金收购通知信息
	HKNoticeType_H08 = 8,				  //H08:股份收购通知信息
	HKNoticeType_H09 = 9,				  //H09：现金加股份收购信息
	HKNoticeType_H13 = 13,				  //H13：公开配售
	HKNoticeType_H14 = 14,				  //H14：供股通知信息
};

// 港股通上市状态
enum SSZT {
	SSZT_Y = 1,			 // 已上市
	SSZT_N = 2,			 // 未上市
};

// 港股通参数状态
enum HKNoticeZZ {
	HKNoticeZZ_Y = 1,			  // 生效
	HKNoticeZZ_N = 2,			  // 终止/取消
};

// 港股通删除标志
enum HKNoticeDelete {
	HKNoticeDelete_Y = 1,			  // 被删除
	HKNoticeDelete_N = 2,			  // 未删除,可用
};

// 港股通证券类别
enum HKSecurityType {
    HKSecurityType_Placeholder = 0,
    HKSecurityType_PT = 1,                      // 港股通普通股
    HKSecurityType_PG = 2,                      // 港股通供股/公开配售
    HKSecurityType_PZ = 3,                      // 港股通权证
};

// 港股通流通类别
enum HKCirculationType {
    HKCirculationType_Placeholder = 0,
    HKCirculationType_0 = 1,                    // 港股通 0：无限售流通股
    HKCirculationType_N = 2,                    // 港股通 N: 限售或非流通
};

// 港股通权益类别
enum HKRightsType {
    HKRightsType_Placeholder = 0,
    HKRightsType_HL = 1,                        // 港股通 HL：红利
    HKRightsType_S = 2,                         // 港股通 S：送股/派送权证
    HKRightsType_P = 3,                         // 港股通 P：配股
    HKRightsType_GG = 4,                        // 港股通 GG：公司收购
};

// 港股通申报状态
enum HKReportStatus {
    HKReportStatus_0 = 0,                       // 未报，待发
    HKReportStatus_1 = 1,                       // 待报，已发
    HKReportStatus_2 = 2,                       // 已确认
    HKReportStatus_3 = 3,                       // 成功
    HKReportStatus_4 = 4,                       // 失败
    HKReportStatus_5 = 5,                       // 已成待撤
    HKReportStatus_6 = 6,                       // 已撤
};

// 放弃标志
enum GiveupFlag {
    GiveupFlag_Yes = 0,                        // 0-放弃
    GiveupFlag_No = 1,                         // 1-不放弃
};

// 放弃状态
enum GiveupStatus {
    GiveupStatus_Yes = 0,                        // 0-已放弃
    GiveupStatus_No = 1,                         // 1-未放弃
};

// 固收询价方向
enum SolidChargeEnquiryDirect {
    SolidChargeEnquiryDirect_I = 0,			// 0:我方主动询价
    SolidChargeEnquiryDirect_O = 1,			// 1:对方主动询价
};

// 固收价格类型
enum SolidChargePriceType {
    SolidChargePriceType_Net = 0,			    // 0:净价
    SolidChargePriceType_All = 1,			    // 1:全价
};

// 新私募债委托价格类型
enum NewPrivatePlacementBondPriceType {
    NewPrivatePlacementBondPriceType_Net = 0,    // 0:净价
    NewPrivatePlacementBondPriceType_All = 1,    // 1:全价
};

// 新私募债委托交易类型
enum NewPrivatePlacementBondTradeType {
    NewPrivatePlacementBondTradeType_Placeholder = 0,
    NewPrivatePlacementBondTradeType_CounterPrice = 1,  // 指定对手报价
    NewPrivatePlacementBondTradeType_Inquire = 2,       // 询价
};

// 新私募债委托询价方向
enum NewPrivatePlacementBondChargeEnquiryDirect {
	NewPrivatePlacementBondChargeEnquiryDirect_Placeholder = 0,
    NewPrivatePlacementBondChargeEnquiryDirect_I = 1,			// 我方主动询价
    NewPrivatePlacementBondChargeEnquiryDirect_O = 2,			// 对方主动询价
};

// 转股回售类型
enum TransferSharesPutBackType {
    TransferSharesPutBackType_Placeholder = 0,
    TransferSharesPutBackType_4 = 4,			        // 4:可交换公司债券换股
    TransferSharesPutBackType_5 = 5,			        // 5:创新创业债转股
    TransferSharesPutBackType_6 = 6,			        // 6:债券回售
};

// 交易所未结算协议回购查询类型
enum ContractBuyBackUnsettledQueryType {
	ContractBuyBackUnsettledQueryType_Placeholder = 0,	
	ContractBuyBackUnsettledQueryType_1 = 1,   		//1 到期结算
	ContractBuyBackUnsettledQueryType_2 = 2,   		//2 到期续做
	ContractBuyBackUnsettledQueryType_3 = 3,   		//3 解除质押
	ContractBuyBackUnsettledQueryType_4 = 4,   		//4 换券申报
	ContractBuyBackUnsettledQueryType_5 = 5,   		//5 提前终止
};

// 交易所未结算协议回购查询状态
enum ContractBuyBackUnsettledQueryStatus {
	ContractBuyBackUnsettledQueryStatus_Placeholder = 0,
	ContractBuyBackUnsettledQueryStatus_Today = 3,   	 	  //'3' 当日到期
	ContractBuyBackUnsettledQueryStatus_Unexpired = 4,   	//'4' 未到期
	ContractBuyBackUnsettledQueryStatus_Expired = 5,     	//'5' 已到期
};

// 协议回购债权债务
enum ContractBuyBackContractType {
	ContractBuyBackContractType_Placeholder = 0,
	ContractBuyBackContractType_Debts = 1,					  //'0'债务（正回购）
	ContractBuyBackContractType_Claims = 2,					  //'1'债权（逆回购）
};

// 协议回购交易合约状态
enum ContractBuyBackContractStatus {
	ContractBuyBackContractStatus_Placeholder = 0,			//无效值	
	ContractBuyBackContractStatus_1 = 1,					//‘0’ 未处理 
	ContractBuyBackContractStatus_2 = 2,					//‘1’处理完毕 
	ContractBuyBackContractStatus_3 = 3,					//‘2’买断回购履约 
	ContractBuyBackContractStatus_4 = 4,					//‘3’买断回购不履约
};

// 协议回购交易买卖方向
enum ContractBuyBackOrderSide {
	ContractBuyBackOrderSide_Placeholder = 0,
	ContractBuyBackOrderSide_Reverse_Repurchase = 1,		//1=逆回购方
	ContractBuyBackOrderSide_Repurchase = 2,				//2=正回购方
};

// 协议回购交易类型
enum ContractBuyBackTradeType {
	ContractBuyBackTradeType_Placeholder = 0,
	ContractBuyBackTradeType_1031 = 1,			//债券质押式协议回购初始交易,
	ContractBuyBackTradeType_1032 = 2,			//债券质押式协议回购到期购回,
	ContractBuyBackTradeType_1033 = 3,			//债券质押式协议回购到期续做,
	ContractBuyBackTradeType_1034 = 4,			//债券质押式协议回购提前购回,
	ContractBuyBackTradeType_1035 = 5,			//债券质押式协议回购解除质押,
	ContractBuyBackTradeType_1036 = 6,			//债券质押式协议回购质押券变更
};

// 协议回购子交易类型
enum ContractBuyBackSubTradeType {
	ContractBuyBackSubTradeType_Placeholder = 0,
	ContractBuyBackSubTradeType_10 = 10,		//10=不变更续做对手方
	ContractBuyBackSubTradeType_11 = 11,		//11=变更续做对手方
};

// 协议回购交易状态
enum ContractBuyBackTradeStatus {
	ContractBuyBackTradeStatus_Placeholder = 0,	//无效值	
	ContractBuyBackTradeStatus_1 = 1,				//0 需确认：逆回购方接收到正回购方成交申报转发来的消息   
	ContractBuyBackTradeStatus_2 = 2,				//1 已回复：逆回购方已回复转发来的正回购方申报消息     
};

// 协议回购交易报送状态
enum ContractBuyBackBsStatus {
	ContractBuyBackBsStatus_Placeholder = 0,		//无效值	
	ContractBuyBackBsStatus_1 = 1, 				//0初始,
	ContractBuyBackBsStatus_2 = 2, 				//1提前已申报,
	ContractBuyBackBsStatus_3 = 3, 				//2解质已申报,
	ContractBuyBackBsStatus_4 = 4, 				//3换券已申报,
	ContractBuyBackBsStatus_5 = 5, 				//4续作已申报, 
	ContractBuyBackBsStatus_6 = 6, 				//5到期已申报
};

// 质押券股份性质
enum ContractBuyBackShareProperty {
	ContractBuyBackShareProperty_Placeholder = 0,	// 定义或者无意义
	ContractBuyBackShareProperty_1 = 1,				// 00无限售流通股
	ContractBuyBackShareProperty_2 = 2,				// 01首发后限售股
};

// 质押券股份性质
enum ContractBuyBackPledgeStatus {
	ContractBuyBackPledgeStatus_Placeholder = 0,	//无效值
	ContractBuyBackPledgeStatus_free = 1,			//0=已解押
	ContractBuyBackPledgeStatus_Pledged = 2,		//1=质押
};

// 换券模式
enum ContractBuyBackChangeType {
	ContractBuyBackChangeType_Placeholder = 0,		//无效值
	ContractBuyBackChangeType_1 = 1,				//仅换出金额
	ContractBuyBackChangeType_2 = 2,				//仅换出债券
	ContractBuyBackChangeType_3 = 3,				//质押解押债券
	ContractBuyBackChangeType_4 = 4,				//仅换入债券
};

// 订单所有者类型
enum ContractBuyBackOwnerType {
	ContractBuyBackOwnerType_Placeholder = 0,		// 无效值	
	ContractBuyBackOwnerType_Personal = 1,			//1=个人投资者发起 
	ContractBuyBackOwnerType_Member = 102,			//102=会员发起 
	ContractBuyBackOwnerType_Organiz = 103,		    //103=机构投资者发起 
	ContractBuyBackOwnerType_SelfManage = 104,		//104=自营交易发起
};

// 交易主体类型
enum ContractBuyBackInvestorType {
	ContractBuyBackInvestorType_Placeholder = 0,		// 未定义或无意义
	ContractBuyBackInvestorType_SelfManage = 1,		    //01=自营
	ContractBuyBackInvestorType_AssetManage = 2,		//02=资管
	ContractBuyBackInvestorType_Organiz = 3,			//03=机构经纪
	ContractBuyBackInvestorType_Personal = 4,			//04=个人经纪
};

// 到期回购续作类型
enum HgxzType {
	HgxzType_Placeholder = 0,
	HgxzType_N = 1,								// 'N'表示非第三方续做
	HgxzType_Y = 2,							    // 'Y'表示第三方续做，到期续做行情时有效
};

// 质押券是否为列表
enum IsstkList {
	IsstkList_Placeholder = 0,
	IsstkList_0 = 1,								// 0表示单个质押券
	IsstkList_1 = 2,							    // 1表示多个质押券的列表，我们公司目前不支持质押券列表，如果为列表，前端应提示并禁止操作
};

// 协议回购交易员状态
enum DealperStatus {
	DealperStatus_Placeholder = 0,
	DealperStatus_0 = 1,								// 0 未激活
	DealperStatus_1 = 2,							    // 1 激活
};

// 协议回购 回购方向
enum ReverseSide {
	ReverseSide_Placeholder = 0,
	ReverseSide_1 = 1,				//1=正回购
	ReverseSide_2 = 2,				//2=逆回购
};

// 是否同意补充条款
enum AcceptSubterm {
	AcceptSubterm_Placeholder = 0,
	AcceptSubterm_0 = 1,   // 0不同意
	AcceptSubterm_1 = 2,   // 1同意
};

// 品种类型
enum IssueStkType {
	IssueStkType_Placeholder = ' ', // 默认值，未定义
    IssueStkType_Stock = '0',       // 股票
    IssueStkType_Bond = '1',        // 债券
    IssueStkType_Other = '3',       // 其他
};

// 委托方式
enum OperWay {
    OperWay_Placeholder = ' ',  // 未定义
    OperWay_0 = '0',            // 自助委托
    OperWay_1 = '1',            // 电话委托
    OperWay_2 = '2',            // 驻留委托
    OperWay_3 = '3',            // 远程委托
    OperWay_4 = '4',            // 柜台委托
    OperWay_5 = '5',            // 漫游委托
    OperWay_6 = '6',            // 分支委托
    OperWay_7 = '7',            // 网上委托
    OperWay_8 = '8',            // 其他电话
    OperWay_9 = '9',            // 其他网上
    OperWay_A = 'A',            // 一户通WEB
    OperWay_B = 'B',            // 套利业务
    OperWay_C = 'C',            // 程序化交易
    OperWay_D = 'D',            // 一户通PAD
    OperWay_E = 'E',            // 一户通手机
    OperWay_F = 'F',            // 浏览委托
    OperWay_G = 'G',            // 一户通商城
    OperWay_H = 'H',            // 宏汇量化
    OperWay_I = 'I',            // 一户通95521
    OperWay_J = 'J',            // 一户通预留1
    OperWay_K = 'K',            // 一户通预留2
    OperWay_L = 'L',            // PB委托
    OperWay_M = 'M',            // 手机证券
    OperWay_N = 'N',            // WebApp
    OperWay_O = 'O',            // 合规监测
    OperWay_P = 'P',            // STS交易系统
    OperWay_Q = 'Q',            // 顶点快速交易系统
    OperWay_R = 'R',            // 信用柜台
    OperWay_S = 'S',            // 信用套利
    OperWay_T = 'T',            // 公募基金
    OperWay_U = 'U',            // 商城天汇宝专用
    OperWay_V = 'V',            // VTM
    OperWay_W = 'W',            // WOFE/QFII业务专用
    OperWay_Y = 'Y',            // 综合柜台
    OperWay_Z = 'Z',            // 全连接企业数字化运作平台
    OperWay_a = 'a',            // 客服中心
    OperWay_b = 'b',            // 网上商城
    OperWay_c = 'c',            // 综合终端
    OperWay_d = 'd',            // 信用业务管理系统
    OperWay_e = 'e',            // 创元ETF
    OperWay_g = 'g',            // 国联安基金
    OperWay_j = 'j',            // 新网厅
    OperWay_m = 'm',            // 银行ATM
    OperWay_n = 'n',            // 因诺PB
    OperWay_o = 'o',            // 定制化PB
    OperWay_p = 'p',            // 银行POS
    OperWay_q = 'q',            // 安诚数盈
    OperWay_r = 'r',            // 中证金通交易通软件
    OperWay_s = 's',            // 银华基金云创系统
    OperWay_t = 't',            // 银行电话
    OperWay_u = 'u',            // 银行柜台
    OperWay_v = 'v',            // 赛辉ETF
    OperWay_w = 'w',            // 申毅投资交易系统
    OperWay_x = 'x',            // 国泰君安量化交易平台
    OperWay_y = 'y',            // 单仕利软件
    OperWay_z = 'z',            // 博弘ETF
};

// 股份性质
enum StockProperty {
    StockProperty_Placeholder = 0,		// 未定义
    StockProperty_00 = 1,               // 无限售流通股
    StockProperty_01 = 2,               // (深)IPO后限售股,(股)挂牌后个人类限售股
    StockProperty_02 = 3,               // (深)股权激励限售股,(股)股权激励限售股
    StockProperty_03 = 4,               // (股)挂牌后机构类限售股
    StockProperty_04 = 5,               // (股)高管锁定股
    StockProperty_05 = 6,               // (深)IPO前限售股,(股)挂牌前个人类限售股
    StockProperty_06 = 7,               // (股)挂牌前机构类限售股
    StockProperty_07 = 8,               // (深)首发后可出借限售股,(股)特别表决权限售股
    StockProperty_10 = 9,               // (深)发起人国家股
    StockProperty_11 = 10,              // (深)发起人国有法人股
    StockProperty_12 = 11,              // (深)发起人境内法人股
    StockProperty_13 = 12,              // (深)发起人外资法人股
    StockProperty_14 = 13,              // (深)发起人自然人股
    StockProperty_22 = 14,              // (深)定向法人境内法人股
    StockProperty_24 = 15,              // (深)定向法人自然人股
    StockProperty_0A = 16,              // (沪)股改股份
    StockProperty_0B = 17,              // (沪)首次公开发行前股份
    StockProperty_0C = 18,              // (沪)股权激励股份
    StockProperty_0D = 19,              // (沪)网下发行新股
    StockProperty_0E = 20,              // (沪)其他限售股份
    StockProperty_0F = 21,              // (沪)非公开发行股份(受减持控制)
    StockProperty_0G = 22,              // (沪)特别表决权股份
    StockProperty_0H = 23,              // (沪)科创板战略投资者配售股份
    StockProperty_0J = 24,              // (沪)限售或非流通
    StockProperty_0K = 25,              // (沪)非公开发行股份(不受减持控制)
    StockProperty_0M = 26,              // (沪)限售或非流通
    StockProperty_0N = 27,              // (沪)限售或非流通
    StockProperty_0Q = 28,              // (沪)限售或非流通
    StockProperty_0T = 29,              // (沪)限售或非流通
    StockProperty_0Z = 30,              // (沪)限售或非流通
};

// 账户状态
enum AccountStatus {
	AccountStatus_Placeholder = ' ',		// 未定义
	AccountStatus_0 = '0',					// 正常
	AccountStatus_1 = '1',					// 冻结
	AccountStatus_2 = '2',					// 挂失
	AccountStatus_3 = '3',					// 密码锁定
	AccountStatus_4 = '4',					// 审查锁定
	AccountStatus_5 = '5',					// 系统锁定
	AccountStatus_6 = '6',					// 待银行确认
	AccountStatus_7 = '7',					// 受控
	AccountStatus_8 = '8',					// 休眠冻结
	AccountStatus_9 = '9',					// 休眠激活
	AccountStatus_A = 'A',					// 未审查
	AccountStatus_B = 'B',					// 禁止登录(未激活)
	AccountStatus_C = 'C',					// 待回访
	AccountStatus_D = 'D',					// 待销户
	AccountStatus_E = 'E',					// 已回访未审查
	AccountStatus_Cancellation = '*',		// 销户
};

// 股东代码类别
enum AccountClass {
    AccountClass_Placeholder = ' ',             // 未定义
    AccountClass_0 = '0',                       // 股东账户
    AccountClass_1 = '1',                       // 基金账户
    AccountClass_H = 'H',                       // H股全流通账户
};

// 股东账户权限类型
enum AccountRightType {
    AccountRightType_Placeholder = ' ',                 // 未定义
    AccountRightType_1 = '1',                           // 债券协议回购
    AccountRightType_3 = '3',                           // 沪伦通交易
    AccountRightType_4 = '4',                           // 三方正回购
    AccountRightType_5 = '5',                           // 三方逆回购
    AccountRightType_6 = '6',                           // 沪科创板普通权限
    AccountRightType_7 = '7',                           // 沪科创板信用权限 
    AccountRightType_8 = '8',                           // 特定债券权限
    AccountRightType_9 = '9',                           // 创业板核准制普通权限
    AccountRightType_a = 'a',                           // 创业板注册制普通权限
    AccountRightType_b = 'b',                           // 质押指定
    AccountRightType_c = 'c',                           // 逆回购指定 
    AccountRightType_d = 'd',                           // 私募债权限
    AccountRightType_f = 'f',                           // 港股通权限
    AccountRightType_g = 'g',                           // 优先股转让权限
};

// 沪港通权限
enum SHHKAccountRight {
    SHHKAccountRight_Placeholder = ' ',                 // 未定义
    SHHKAccountRight_0 = '0',                           // 卖出
    SHHKAccountRight_1 = '1',                           // 买入卖出
};

// 集中交易客户类型
enum CustType {
	kCustType_0 = 0,                        // 客户
	kCustType_1 = 1,                        // 代理人
	kCustType_2 = 2,                        // 经纪人
	kCustType_3 = 3,                        // 联名卡经理人
	kCustType_4 = 4,                        // 基金投顾客户
	kCustType_5 = 5,                        // H股流通客户
};

// 留存A类业务分类
enum RetainedBSType {
	RetainedBSType_Placeholder = 0,
	RetainedBSType_1 = 1,				// 1：股票质押式回购
	RetainedBSType_2 = 2,				// 2：约定回购
	RetainedBSType_3 = 3,				// 3：现金管家
	RetainedBSType_4 = 4,				// 4：报价回购
	RetainedBSType_5 = 5,				// 5：上海固收指定对手方和转股回售
	RetainedBSType_6 = 6,				// 6：地方债批量委托
	RetainedBSType_7 = 7,				// 7：B股委托
};

// 协议回购到期状态
enum QuoteStatus {
	QuoteStatus_3 = '3',				// 3：当日到期
	QuoteStatus_4 = '4',				// 4：未到期
	QuoteStatus_5 = '5',				// 5：已到期
};

// 竞买成交方式
enum BiddingMatchType {
    BiddingMatchType_Placeholder = 0,
    BiddingMatchType_1 = 1,                // 1=单一主体中标
    BiddingMatchType_2 = 2,                // 2=多主体单一价格中标；
    BiddingMatchType_3 = 3,                // 3=多主体多重价格中标
};

// 债券应用标识
enum BondApplyId {
    BondApplyId_Placeholder = 0,      // 未定义
	BondApplyId_410 = 410,            // 债券现券交易匹配成交申报
	BondApplyId_411 = 411,            // 债券现券交易协商成交申报
	BondApplyId_412 = 412,            // 债券现券交易点击成交报价申报
	BondApplyId_413 = 413,            // 债券现券交易点击成交报价回复申报
	BondApplyId_414 = 414,            // 债券现券交易询价申报
	BondApplyId_415 = 415,            // 债券现券交易询价成交报价申报
	BondApplyId_416 = 416,            // 债券现券交易询价成交报价回复申报
	BondApplyId_417 = 417,            // 债券现券交易竞买成交申报
	BondApplyId_430 = 430,            // 债券转让业务回售转售申报
};

// 债券应用标识
enum StrBondApplyId {
#define StrBondApplyId_Placeholder = "0"      // 未定义
#define StrBondApplyId_410 = "410"            // 债券现券交易匹配成交申报
#define StrBondApplyId_411 = "411"            // 债券现券交易协商成交申报
#define StrBondApplyId_412 = "412"            // 债券现券交易点击成交报价申报
#define StrBondApplyId_413 = "413"            // 债券现券交易点击成交报价回复申报
#define StrBondApplyId_414 = "414"            // 债券现券交易询价申报
#define StrBondApplyId_415 = "415"            // 债券现券交易询价成交报价申报
#define StrBondApplyId_416 = "416"            // 债券现券交易询价成交报价回复申报
#define StrBondApplyId_417 = "417"            // 债券现券交易竞买成交申报
#define StrBondApplyId_430 = "430"            // 债券转让业务回售转售申报
#define StrBondApplyId_41A = "41A"            // 41A债券现券交易协商成交之合并申报
};

// 信用标识
enum CashMarginFlag {
    CashMarginFlag_Placeholder = 0,                // 未定义
    CashMarginFlag_Cash = 1,                       // 1= Cash，普通交易 
    CashMarginFlag_Open = 2,                       // 2= Open，融资融券开仓
    CashMarginFlag_Close = 3,                      // 3= Close 融资融券平仓
};

// 结算方式
enum SettleType {
    SettleType_Placeholder = 0,                    // 未定义
    SettleType_103 = 103,                          // 103=多边净额
    SettleType_104 = 104,                          // 104=逐笔全额
};

// 结算周期
enum SettlePeriod {
    SettlePeriod_Placeholder = 0,                      // 未定义
    SettlePeriod_0 = 1,                                // T+0 
    SettlePeriod_1 = 2,                                // T+1
    SettlePeriod_2 = 3,                                // T+2
    SettlePeriod_3 = 4,                                // T+3
};

// 是否匿名
enum AnonymityType {
    AnonymityType_false = 0,              // 显名
    AnonymityType_true = 1,               // 匿名
};

// 固收债券申报状态
enum SCBondStatus {
    SCBondStatus_Placeholder = 0,                      // 未定义
    SCBondStatus_Need_Confirm = 1,                     // '0' 需确认：接收方接收到发起方成交申报转发来的消息
    SCBondStatus_Replyed = 2,                          // '1' 已回复：接收方已回复转发来的发起方申报消息 
    SCBondStatus_Canceled = 3,                         // '2' 已撤销：接收方接收到未回复的成交申报撤单消息时，修改原转发的需展示的消息
    SCBondStatus_Reject = 4,                           // '4' 拒绝：发起方接收到接收方的拒绝消息
};

// 竞买业务类别
enum BidTransType {
    BidTransType_Placeholder = 0,                      // 未定义
    BidTransType_Subscribe = 1,                        // 1=竞买预约申报
    BidTransType_Send = 2,                             // 2=竞买发起申报
    BidTransType_Reply = 3,                            // 3=竞买应价申报
};

// 业务方向
enum BusiDirection {
    BusiDirection_Placeholder = 0,                     // 未定义
    BusiDirection_Bid = 1,                             // 买
    BusiDirection_Ask = 2,                             // 卖
    BusiDirection_Borrow = 10,                         // 借入
    BusiDirection_Lend = 11,                           // 出借
    BusiDirection_Purchase = 12,                       // 申购
    BusiDirection_Redemption = 13,                     // 赎回
};

// 信用交易摘要
enum CreditDigestID {
    CreditDigestID_Placeholder = 0,    // 未定义
    CreditDigestID_a = 1,              // 普通买入
    CreditDigestID_b = 2,              // 融资买入
    CreditDigestID_c = 3,              // 普通卖出
    CreditDigestID_d = 4,              // 融券卖出
    CreditDigestID_e = 5,              // 买券还券
    CreditDigestID_f = 6,              // 现券还券
    CreditDigestID_g = 7,              // 余券划转
    CreditDigestID_h = 8,              // 担保物转入
    CreditDigestID_i = 9,              // 担保物转出
    CreditDigestID_j = 10,             // 追加融资平仓
    CreditDigestID_k = 11,             // 追加融券平仓
    CreditDigestID_l = 12,             // 清偿融资平仓
    CreditDigestID_m = 13,             // 清偿融券平仓
    CreditDigestID_n = 14,             // 合约融资平仓
    CreditDigestID_o = 15,             // 合约融券平仓
    CreditDigestID_p = 16,             // 追加强制卖出
    CreditDigestID_q = 17,             // 清偿强制卖出
    CreditDigestID_r = 18,             // 合约强制卖出
    CreditDigestID_s = 19,             // 清偿现券还券
    CreditDigestID_t = 20,             // 合约现券还券
    CreditDigestID_u = 21,             // 卖券还款
};

// 投资类型
enum InvestType {
    InvestType_Placeholder = 0,        // 未定义
    InvestType_1 = 1,                  // 交易性
    InvestType_2 = 2,                  // 可供出售
    InvestType_3 = 3,                  // 持有至到期
    InvestType_4 = 4,                  // 贷款和应收款项
};

// 上交所现金替代资金类型
enum FundResourcesType {
    FundResourcesType_Placeholder = 0,                     // 0=非上交所现金替代资金类型
    FundResourcesType_SH = 1,                              // 1=沪市资金
    FundResourcesType_SZ = 2,                              // 2=深市资金
    FundResourcesType_HK = 3,                              // 3=港市资金
    FundResourcesType_Not = 9,                             // 9=非沪港深资金
};

// 接入系统角色
enum SystemRole {
	SystemRole_Acct = 0,                // 账号接入
	SystemRole_Sys = 1,                 // 系统接入
};

// 试卷类别
enum PaperType {
    PaperType_Placeholder = ' ',               // 未定义
    PaperType_1 = '1',                         // 客户风险测评试卷
    PaperType_2 = '2',                         // 融资融券首次征信试卷
    PaperType_3 = '3',                         // 融资融券再次征信试卷
    PaperType_4 = '4',                         // 债券投资基本知识问卷
    PaperType_5 = '5',                         // 私募债券业务基本知识问卷
    PaperType_6 = '6',                         // 约定购回征信试卷
    PaperType_7 = '7',                         // 银行理财账户风险测评试卷
    PaperType_A = 'A',                         // 股指期货基础测评试卷
    PaperType_B = 'B',                         // 股指期货综合评估试卷
    PaperType_a = 'a',                         // 客户历史存量试卷A
    PaperType_b = 'b',                         // 客户历史存量试卷B
    PaperType_c = 'c',                         // 客户历史存量试卷C
    PaperType_d = 'd',                         // 牛熊宝专项计划投资者适当性综合评估
    PaperType_e = 'e',                         // 牛熊宝专项计划产品认知度评估
    PaperType_f = 'f',                         // 牛熊宝专项计划客户风险承受度评估
    PaperType_z = 'z',                         // 创业板信息调查问卷
};

// 机构标志
enum OrganizationFlag {
    OrganizationFlag_Placeholder = ' ',        // 未定义
    OrganizationFlag_Individual = '0',         // 个人
    OrganizationFlag_Organ = '1',              // 机构
    OrganizationFlag_SelfSupport = '2',        // 自营
};

// 客户风险等级
enum CustRiskLevel {
    CustRiskLevel_Default = 0,          // 默认型
    CustRiskLevel_Conservative = 1,     // 保守型
    CustRiskLevel_Cautious = 2,         // 谨慎型
    CustRiskLevel_Steady = 3,           // 稳健型
    CustRiskLevel_Positive = 4,         // 积极型
    CustRiskLevel_Radicalness = 5,      // 激进型
};

// 认证产品类别
enum AuthProductType {
    AuthProductType_Placeholder = ' ',  // 未定义
    AuthProductType_0 = '0',            // 机器特征码
    AuthProductType_1 = '1',            // UKEY数字证书
    AuthProductType_2 = '2',            // 动态密码
    AuthProductType_3 = '3',            // CA证书
    AuthProductType_4 = '4',            // 短信密码
    AuthProductType_5 = '5',            // 手机软口令
    AuthProductType_7 = '7',            // 证书+短信密码
    AuthProductType_A = 'A',            // 校验码
    AuthProductType_B = 'B',            // 通讯密码
    AuthProductType_a = 'a',            // UKEY+短信
    AuthProductType_b = 'b',            // 高级软证书+短信
    AuthProductType_c = 'c',            // 低级软证书+短信
    AuthProductType_Z = 'Z',            // 无
};

// 客户类型
enum QytClientType {
    QytClientType_Personal = '0',                            // 个人
    QytClientType_Organ = '1',                               // 机构
    QytClientType_OpenPlat = '2',                            // 开放平台
    QytClientType_CustManager = '3',                         // 客户经理
};

// 期限类型
enum QytLimitType {
    QytLimitType_28OK = '1',                          // 接受28天展期
    QytLimitType_28NO = '2',                          // 不接受28天展期
    QytLimitType_Roll = '4',                          // 连续滚动
    QytLimitType_NotAuto = '9',                       // 无(不自动展期)
};

// 委托方式
enum QytEnType {
    QytEnType_Auction = '1',         // 仅竞拍
    QytEnType_Realtime = '2',        // 仅实时
    QytEnType_rta = '3',             // 实时不成余转竞拍
    QytEnType_db = '4',              // 定向新约
    QytEnType_yb = '5',              // 预告融入
    QytEnType_bb = '6',              // 标准篮子买入
    QytEnType_dbb = '7',             // 定制篮子买入
    QytEnType_zq = '8',              // 展期
    QytEnType_yqzq = '9',            // 逾期展期
    QytEnType_dzq = 'a',             // 定向展期
    QytEnType_bbzq = 'b',            // 篮子展期
};

// 篮子委托方式
enum QytBEnType {
    QytBEnType_Auction = '1',         // 仅竞拍
    QytBEnType_khzq = '4',            // 客户展期
    QytBEnType_zdzq = '5',            // 自动展期
    QytBEnType_glyzq = '6',           // 管理员展期
};

// 篮子类型
enum QytBskType {
    QytBskType_Std = '1',             // 标准篮子
    QytBskType_Cust = '2',            // 定制篮子
};

// 成交类型
enum QytDealType {
    QytDealType_RT = '1',        // 实时券
    QytDealType_QC = '3',        // 券池成交
    QytDealType_TZ = '4',        // 台账成交
    QytDealType_SP = '5',        // 审批成交（callback展期）
    QytDealType_QT = '9',        // 其他
};

//券池直锁方式
enum Ezsfs {
    Ezsfs_ALL = 0,                    // -1查全部
	Ezsfs_Bidding = 1,                // 0-竞价券池
    Ezsfs_Realtime = 2,               // 1-实时券池   
};

//券池券单类型
enum Eqdlx1 {
	//：0表示所有，1-普通，2-定向，3-预告，7-兜底；
	Eqdlx1_All = '0',
	Eqdlx1_Normal = '1',
	Eqdlx1_Direct = '2',
	Eqdlx1_Forecast = '3',
	Eqdlx1_Backup = '7',
};

//券池首次投放类型
enum Esctflx {
	//1-核销投放，2-虚拟投放
	Esctflx_Hx = '1',
	Esctflx_Xn = '2',
};

//券池类型
enum QCType {
    //1实时券,2竞价券,3预告券,4约定券
    QCType_Placeholder = 0,               // 未定义
    QCType_Realtime = 1,
    QCType_Bidding = 2,
    QCType_Forecast = 3,
    QCType_Appoint = 4,
};

// 定向标志
enum QytDirectedType {
    QytDirectedType_Placeholder = 0,               // 未定义
    QytDirectedType_Normal = 1,                    // 1-普通
    QytDirectedType_Directed = 2,                  // 2-定向
};

// 委托状态
enum QytEntrustStatus {
    QytEntrustStatus_Placeholder = 0,              // 未定义
    QytEntrustStatus_New = 1,                      // 1-已报
    QytEntrustStatus_Canceled = 2,                 // 2-已撤
    QytEntrustStatus_PartiallyFilled = 3,          // 3-部成
    QytEntrustStatus_PartiallyCanceled = 4,        // 4-部成已撤
    QytEntrustStatus_Filled = 5,                   // 5-已成
    QytEntrustStatus_Terminated = 6,               // 6-终止
};

// 其他状态
enum QytOtherStatus {
    QytOtherStatus_Disabled = 0,                // 失效
    QytOtherStatus_Init = 1,                    // 初始状态
    QytOtherStatus_MatchLock = 2,               // 撮合锁定
    QytOtherStatus_MatchUnlock = 3,             // 撮合释放
};

// 处理状态
enum QytProcessStatus {
    QytProcessStatus_Init = 0,                   // 未处理
    QytProcessStatus_Success = 1,                // 已处理 
    QytProcessStatus_Failed = 2,                 // 处理失败
    QytProcessStatus_Terminated = 9,             // 终止
};

// 调拨状态
enum QytAllotStatus {
    QytAllotStatus_Placeholder = 0,            // 未定义或者无意义
    QytAllotStatus_Init = 1,                   // 未调拨
    QytAllotStatus_Success = 3,                // 已到账 
    QytAllotStatus_Failed = 4,                 // 调拨失败
    QytAllotStatus_Terminated = 5,             // 调拨终止
};

// 委托方向
enum QytDirection {
    QytDirection_Placeholder = ' ',            // 未定义
    QytDirection_Bid = 'b',                    // 买入
    QytDirection_by = 'c',                     // 融入意向
    QytDirection_s = 'd',                      // 融出
    QytDirection_db = 'e',                     // 定向新约
    QytDirection_yb = 'f',                     // 预告融入
    QytDirection_bb = 'g',                     // 标准篮子买入
    QytDirection_dbb = 'h',                    // 定制篮子买入
    QytDirection_zq = 'i',                     // 展期
    QytDirection_yqzq = 'j',                   // 逾期展期
    QytDirection_dzq = 'k',                    // 定向展期
    QytDirection_bbzq = 'm',                   // 篮子展期
};

// 渠道类型
enum QytChannelType {
    QytChannelType_Placeholder = ' ',              // 未定义
    QytChannelType_JR = '4',                       // 君融
    QytChannelType_FY = '7',                       // 富易
    QytChannelType_JH = 'M',                       // 君弘
    QytChannelType_SFJR = 'S',                     // 三方接入
    QytChannelType_KFPT = 'W',                     // 开放平台
    QytChannelType_XTFQ = 'X',                     // 系统发起
};


//QC合约状态
enum QC_Ehyzt {
    //'1'已了结; '2'未了结; '3'未了结已逾期
	QC_Ehyzt_Ylj = '1',
	QC_Ehyzt_Wlj = '2',
	QC_Ehyzt_WljYyq = '3',
};

//QC展期申请标记
enum QC_Ezqsqfs {
	//3-仅限本期、4-连续滚动、9-无(不自动展期)
	QC_Ezqsqfs_Jxbq = '3',
	QC_Ezqsqfs_Lxgd = '4',
	QC_Ezqsqfs_Bzd = '9',
};

// QC展期审批
enum QC_HaveExtend {
    //0-其它；1-审批通过；2-申请中；A(10)-已展期(只对查询约券合约请求--KHD0001生效)
    QC_HaveExtend_0 = '0',
    QC_HaveExtend_1 = '1',
    QC_HaveExtend_2 = '2',
    QC_HaveExtend_A = 'A',
};

// QC特殊预约标志
enum QC_Etsyybz {
    //1无视利率，2普通
	QC_Etsyybz_Wsl = '1',
	QC_Etsyybz_Pt = '2',
};

// 横向划转处理状态
enum LTDealStatus {
    LTDealStatus_Init = 0,                  // 0：未处理
    LTDealStatus_Dealing = 1,               // 1：处理中
    LTDealStatus_Success = 2,               // 2：成功
    LTDealStatus_Failed = 3,                // 3：失败
};

// 横向划转业务摘要代码
enum LTBusiDigestCode {
    LTBusiDigestCode_Placeholder = 0,           // 未定义或无意义
    LTBusiDigestCode_0101 = 101,                // 证转证
    LTBusiDigestCode_0102 = 102,                // 证转信
    LTBusiDigestCode_0103 = 103,                // 证转投顾
    LTBusiDigestCode_0104 = 104,                // 证转衍
    LTBusiDigestCode_0105 = 105,                // 证转贵
    LTBusiDigestCode_0201 = 201,                // 信转证
    LTBusiDigestCode_0202 = 202,                // 信转信
    LTBusiDigestCode_0203 = 203,                // 信转投顾
    LTBusiDigestCode_0204 = 204,                // 信转衍
    LTBusiDigestCode_0205 = 205,                // 信转贵
    LTBusiDigestCode_0301 = 301,                // 投顾转证
    LTBusiDigestCode_0302 = 302,                // 投顾转信
    LTBusiDigestCode_0303 = 303,                // 投顾转投顾
    LTBusiDigestCode_0304 = 304,                // 投顾转衍
    LTBusiDigestCode_0305 = 305,                // 投顾转贵
    LTBusiDigestCode_0401 = 401,                // 衍转证
    LTBusiDigestCode_0402 = 402,                // 衍转信
    LTBusiDigestCode_0403 = 403,                // 衍转投顾
    LTBusiDigestCode_0404 = 404,                // 衍转衍
    LTBusiDigestCode_0405 = 405,                // 衍转贵
    LTBusiDigestCode_0501 = 501,                // 贵转证
    LTBusiDigestCode_0502 = 502,                // 贵转信
    LTBusiDigestCode_0503 = 503,                // 贵转投顾
    LTBusiDigestCode_0504 = 504,                // 贵转衍
    LTBusiDigestCode_0505 = 505,                // 贵转贵
};

// 可交易类型
enum TradableType {
    TradableType_Placeholder = 0,              // 未定义或无意义
    TradableType_0 = '0',                      // 可正常交易
    TradableType_1 = '1',                      // 缴款
    TradableType_2 = '2',                      // 申购
    TradableType_3 = '3',                      // 增发申购
    TradableType_4 = '4',                      // 配号
    TradableType_7 = '7',                      // 配售
    TradableType_8 = '8',                      // 配售配号
    TradableType_9 = '9',                      // 跨系统转托管
    TradableType_A = 'A',                      // 设置分红方式
    TradableType_B = 'B',                      // ETF认购
    TradableType_C = 'C',                      // ETF申购
    TradableType_D = 'D',                      // 基金金额认购
    TradableType_E = 'E',                      // 行权
    TradableType_F = 'F',                      // 基金转换
    TradableType_G = 'G',                      // 质押
    TradableType_H = 'H',                      // 转债回售
    TradableType_J = 'J',                      // 发行询价
    TradableType_K = 'K',                      // 发行申购
    TradableType_X = 'X',                      // 现金替代
};

// 信用合同状态
enum CreditContractStatus {
    CreditContractStatus_Placeholder = 0,       // 未定义或无意义
    CreditContractStatus_Normal = 1,            // 正常
    CreditContractStatus_NotStarted = 2,        // 未启用
    CreditContractStatus_Stoped = 3,            // 终止
};

// 基金账户状态
enum FundAccountStatus {
    FundAccountStatus_Placeholder = ' ',        // 未定义
    FundAccountStatus_0 = '0',                  // 正常
    FundAccountStatus_1 = '1',                  // 冻结
    FundAccountStatus_2 = '2',                  // 挂失
    FundAccountStatus_4 = '4',                  // 交易帐户待销户
    FundAccountStatus_5 = '5',                  // 基金帐户待销户
    FundAccountStatus_6 = '6',                  // 交易帐户销户
    FundAccountStatus_7 = '7',                  // 基金帐户销户
    FundAccountStatus_8 = '8',                  // 冻结挂失中
    FundAccountStatus_9 = '9',                  // 解冻解挂中
    FundAccountStatus_a = 'a',                  // 内部冻结
    FundAccountStatus_b = 'b',                  // 基金开户未确认
    FundAccountStatus_c = 'c',                  // 交易帐户开户未确认
    FundAccountStatus_d = 'd',                  // 帐户修改未确认
    FundAccountStatus_e = 'e',                  // 开户失败
    FundAccountStatus_f = 'f',                  // 变更交易账户未确认
};

// 证券类型
enum QytStockType {
    QytStockType_Placeholder = ' ',        //未定义或无意义
    QytStockType_1 = '1',                  //实时券（针对意向登记的代表已上市） 
    QytStockType_2 = '2',                  //竞拍券（针对意向登记的代表未上市）
    QytStockType_3 = '3',                  //外部券
    QytStockType_4 = '4',                  //篮子券（针对标准篮子）
};

// 分类代码
enum QytSInfoTypeCode {
    QytSInfoTypeCode_Placeholder = ' ',        //未定义或无意义
    QytSInfoTypeCode_a001050w01 = '1',         //审批制 
    QytSInfoTypeCode_a001050w02 = '2',         //核准制
    QytSInfoTypeCode_a001050w03 = '3',         //注册制
};

// 融券策略（仅针对融券意向）
enum QytStrategy {
    QytStrategy_Placeholder = ' ',         //未定义或无意义
    QytStrategy_0 = '0',                   //融券策略（仅针对融券意向）	0	其他
    QytStrategy_1 = '1',                   //融券策略（仅针对融券意向）	1	趋势交易
    QytStrategy_2 = '2',                   //融券策略（仅针对融券意向）	2	融券对冲
    QytStrategy_3 = '3',                   //融券策略（仅针对融券意向）	3	套利交易
};

// 收盘前或收盘后标志(当前时间在15:00前或者后的标志)
enum AfterCloseFlag {
    AfterCloseFlag_Placeholder = ' ',   // 未定义或无意义
    AfterCloseFlag_False = '0',         // 收盘前
    AfterCloseFlag_True = '1',          // 收盘后
};

// 审批状态(前端状态)
enum FrontApprovalStatus {
    FrontApprovalStatus_Placeholder = 0,    // 未定义或无意义
    FrontApprovalStatus_Checking = 1,       // 审批中
    FrontApprovalStatus_CheckSucc = 2,      // 审批通过
    FrontApprovalStatus_CheckFail = 3,      // 审批拒绝
    FrontApprovalStatus_Cancelled = 4,      // 已撤单
};

// 是否多渠道开户标志
enum MultiOpenFlag {
    MultiOpenFlag_Placeholder = ' ',    // 未定义或无意义
    MultiOpenFlag_False = '0',          // 否
    MultiOpenFlag_True = '1',           // 是
};

// 基金委托状态定义
enum FundOrderStatus {
    FundOrderStatus_Placeholder = 0,        // 定义或无意义
    FundOrderStatus_NoApply = 1,            // 未报
    FundOrderStatus_PendingNew = 2,         // 待报
    FundOrderStatus_New = 3,                // 已报
    FundOrderStatus_Canceling = 4,          // 已报待撤
    FundOrderStatus_CancelFilled = 7,       // 已撤
    FundOrderStatus_PartiallyFilled = 8,    // 部成
    FundOrderStatus_Filled = 9,             // 已成
    FundOrderStatus_Rejected = 10,          // 废单
    FundOrderStatus_Applying = 11,          // 正报
    FundOrderStatus_Replyed = 12,           // 已回
};

// 内部调用标识
enum InnerCallFlag {
    InnerCallFlag_False = 0,                // 非内部调用
    InnerCallFlag_True = 1,                 // 内部调用
};

// 续作标识(报价回购)
enum ContinueFlag {
	ContinueFlag_Placeholder = 0,	// 未定义或无意义
	ContinueFlag_0 = 1,	            // 不允许续做
	ContinueFlag_1 = 2,	            // 只能续做原期
	ContinueFlag_2 = 3,	            // 可续做原期或一天期
};

// 交易标志(报价回购)
enum QuoteRepoBuyFlag {
	QuoteRepoBuyFlag_Placeholder = 0,	// 未定义或无意义
	QuoteRepoBuyFlag_0 = 1,	            // 允许交易
	QuoteRepoBuyFlag_1 = 2,	            // 禁止交易
	QuoteRepoBuyFlag_2 = 3,	            // 禁止初始交易
	QuoteRepoBuyFlag_3 = 4,	            // 禁止提前购回
};

// 产品模式(报价回购)
enum QuoteRepoProdMode {
	QuoteRepoProdMode_Placeholder = 0,	// 未定义或无意义--作为查询入参时，代表查所有
	QuoteRepoProdMode_0 = 1,	        // 分期模式
	QuoteRepoProdMode_1 = 2,	        // 长期模式
};

// 特殊产品(报价回购)
enum SpecialProd {
	SpecialProd_Placeholder = 0,	// 未定义或无意义--作为查询入参时，代表查所有
	SpecialProd_0 = 1,	            // 非特殊产品
	SpecialProd_1 = 2,	            // 是特殊产品
};

// 合约状态(上海报价回购)
enum SHQuoteRepoStatus {
	SHQuoteRepoStatus_Placeholder = 0,	    // 未定义或无意义--作为查询入参时，代表查所有
	SHQuoteRepoStatus_0 = 1,	            // 未完成(在途待交收)
	SHQuoteRepoStatus_1 = 2,	            // 已完成(到期)
	SHQuoteRepoStatus_2 = 3,	            // 已完成(提前终止)
};

// 预约状态(报价回购)
enum QuoteRepoBookStatus {
	QuoteRepoBookStatus_Placeholder = 0,	// 未定义或无意义
	QuoteRepoBookStatus_0 = 1,	            // 无预约
	QuoteRepoBookStatus_1 = 2,	            // 预约等待
	QuoteRepoBookStatus_2 = 3,	            // 允许预约
	QuoteRepoBookStatus_3 = 4,	            // 拒绝预约
};


// 深圳合约状态,'0' 己成,'1' 正常 '2' 己了结,'3' 己结束
enum SZQuoteRepoStatus {
	SZQuoteRepoStatus_0 = '0',           // 己成
	SZQuoteRepoStatus_1 = '1',           // 正常
	SZQuoteRepoStatus_2 = '2',           // 己了结
	SZQuoteRepoStatus_3 = '3',           // 己结束
};

//合约生成方式0:正常,1:预约生成,2:续作生成
enum QuoteRepoCreateMethod {
	QuoteRepoCreateMethod_Placeholder = ' ', // 未定义或无意义
    QuoteRepoCreateMethod_0 = '0',           // 己成
	QuoteRepoCreateMethod_1 = '1',           // 预约生成
	QuoteRepoCreateMethod_2 = '2',           // 续作生成
};

//自动续约标志'1'自动续约'0'不自动续约
enum QuoteRepoContFlag {
    QuoteRepoContFlag_0 = '0',               //不自动续约
    QuoteRepoContFlag_1 = '1',               //自动续约
};

//提前购回预约状态'0'-无预约'2'-已预约
enum QuoteRepoYyStatus {
    QuoteRepoYyStatus_0 = '0',               //无预约
    QuoteRepoYyStatus_2 = '2',               //已预约
};

// 认申购状态 J:认购阶段 K:申购阶段
enum SubscribePurchaseStatus {
    SubscribePurchaseStatus_Placeholder = ' ',      // 未定义或无意义
    SubscribePurchaseStatus_Sub = 'J',              // 认购阶段
    SubscribePurchaseStatus_Pur = 'K',              // 申购阶段
};

// 认申购委托状态
enum SubPurOrderStatus {
    SubPurOrderStatus_No = 0,                           // 未申报
    SubPurOrderStatus_Yes = 1,                          // 已申报
};

// 新三板发行方式
enum NEEQIssueType {
    NEEQIssueType_Placeholder = 0,              // 未定义或无意义
    NEEQIssueType_Quoto = 1,                        // 询价发行
    NEEQIssueType_Fix = 2,                      // 定价发行
    NEEQIssueType_Auction = 3,                 // 竞价发行
};

}  // namespace HFT

#endif  //_HFT_TRADER_DEF_H_
