// vnctpmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnsip.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnLog(int32_t level, const char *source, const char *slog)
{
	if (this->logging)
	{
		cout << "onLog: source=" << source << ",  slog=" << slog << endl;
	}
};

void MdApi::OnLogin(int32_t chn, void* mdapi)
{
	gil_scoped_acquire acquire;
	this->onLogin(chn);
};

void MdApi::OnDisconnect(int32_t chn)
{
	gil_scoped_acquire acquire;
	this->onDisconnect(chn);
};

void MdApi::OnSubscribe(ErrMsg *errmsg)
{

	gil_scoped_acquire acquire;
	dict error;
	{
		error["channel"] = errmsg->channel;
		error["errcode"] = errmsg->errcode;
		error["errstr"] = toUtf(errmsg->errstr);
	}
	this->onSubscribe(error);
};

void MdApi::OnUnSubscribe(ErrMsg *errmsg)
{
	gil_scoped_acquire acquire;
	dict error;
	{
		error["channel"] = errmsg->channel;
		error["errcode"] = errmsg->errcode;
		error["errstr"] = toUtf(errmsg->errstr);
		error["mktype"] = errmsg->mktype;
		error["datatype"] = errmsg->datatype;
		error["usize"] = errmsg->usize;
	}
	this->onUnSubscribe(error);
};

void MdApi::OnDepthMarketData(MKtype mk_type, char *code, Stock_MarketData *dataL2)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["nTime"] = dataL2->nTime;
		data["nStatus"] = dataL2->nStatus;
		data["uPreClose"] = dataL2->uPreClose;
		data["uOpen"] = dataL2->uOpen;
		data["uHigh"] = dataL2->uHigh;
		data["uLow"] = dataL2->uLow;
		data["uMatch"] = dataL2->uMatch;
		data["uNumTrades"] = dataL2->uNumTrades;
		data["iVolume"] = dataL2->iVolume;
		data["iTurnover"] = dataL2->iTurnover;
		data["iTotalBidVol"] = dataL2->iTotalBidVol;
		data["iTotalAskVol"] = dataL2->iTotalAskVol;
		data["uWeightedAvgBidPrice"] = dataL2->uWeightedAvgBidPrice;
		data["uWeightedAvgAskPrice"] = dataL2->uWeightedAvgAskPrice;
		data["nIOPV"] = dataL2->nIOPV;
		data["nYieldToMaturity"] = dataL2->nYieldToMaturity;
		data["uHighLimited"] = dataL2->uHighLimited;
		data["uLowLimited"] = dataL2->uLowLimited;
		data["sPrefix"] = toUtf(dataL2->sPrefix);
		data["nSyl1"] = dataL2->nSyl1;
		data["nSyl2"] = dataL2->nSyl2;
		data["nSD2"] = dataL2->nSD2;
		data["sTradingPhraseCode"] = toUtf(dataL2->sTradingPhraseCode);
		data["nPreIOPV"] = dataL2->nPreIOPV;

		pybind11::list ask;
		pybind11::list bid;
		pybind11::list ask_qty;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(dataL2->uAskPrice[i]);
			bid.append(dataL2->uBidPrice[i]);
			ask_qty.append(dataL2->uAskVol[i]);
			bid_qty.append(dataL2->uBidVol[i]);
		}

		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;
	}
	this->onDepthMarketData(mk_type, code, data);
};

void MdApi::OnFastDepthMarketData(MKtype mk_type, char* code, StockMarketDataLF* dataLF)
{

};

void MdApi::OnMarketData(MKtype mk_type, char *code, StockMarketDataL1 *dataL1)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["nTime"] = dataL1->nTime;
		data["nStatus"] = dataL1->nStatus;
		data["uPreClose"] = dataL1->uPreClose;
		data["uOpen"] = dataL1->uOpen;
		data["uHigh"] = dataL1->uHigh;
		data["uLow"] = dataL1->uLow;
		data["uMatch"] = dataL1->uMatch;
		//data["uAskPrice"] = dataL1->uAskPrice;
		//data["uAskVol"] = dataL1->uAskVol;
		//data["uBidPrice"] = dataL1->uBidPrice;
		//data["uBidVol"] = dataL1->uBidVol;
		data["uNumTrades"] = dataL1->uNumTrades;
		data["iVolume"] = dataL1->iVolume;
		data["iTurnover"] = dataL1->iTurnover;
		data["uHighLimited"] = dataL1->uHighLimited;
		data["uLowLimited"] = dataL1->uLowLimited;
		data["sTradingPhraseCode"] = toUtf(dataL1->sTradingPhraseCode);
		data["nPreIOPV"] = dataL1->nPreIOPV;
		data["nIOPV"] = dataL1->nIOPV;

		pybind11::list ask;
		pybind11::list bid;
		pybind11::list ask_qty;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(dataL1->uAskPrice[i]);
			bid.append(dataL1->uBidPrice[i]);
			ask_qty.append(dataL1->uAskVol[i]);
			bid_qty.append(dataL1->uBidVol[i]);
		}

		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;
	}
	this->onMarketData(mk_type, code, data);
};

void MdApi::OnIndexData(MKtype mk_type, char *code, Stock_IndexData *stockindex)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["nTime"] = stockindex->nTime;
		data["nOpenIndex"] = stockindex->nOpenIndex;
		data["nHighIndex"] = stockindex->nHighIndex;
		data["nLowIndex"] = stockindex->nLowIndex;
		data["nLastIndex"] = stockindex->nLastIndex;
		data["iTotalVolume"] = stockindex->iTotalVolume;
		data["iTurnover"] = stockindex->iTurnover;
		data["nPreCloseIndex"] = stockindex->nPreCloseIndex;
	}
	this->onIndexData(mk_type, code, data);
};

void MdApi::OnSHOption(char* code, t_SHOP_MarketData* optiondata)
{
	cout << "OnSHOption" << endl;
};

void MdApi::OnSZOption(char* code, t_SZOP_MarketData* optiondata)
{
	cout << "OnSZOption" << endl;
};

void MdApi::OnOrderQueue(MKtype mk_type, char *code, StockOrderQueue *orderqueue)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["tHead"] = orderqueue->tHead;
		data["tItem"] = orderqueue->tItem;
	}
	this->onOrderQueue(mk_type, code, data);
};

void MdApi::OnSHOrder(char* code, t_SH_StockStepOrder* steporder)
{
};

void MdApi::OnSHTrade(char *code, t_SH_StockStepTrade *steptrade)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["nTradeIndex"] = steptrade->nTradeIndex;
		data["nTradeChannel"] = steptrade->nTradeChannel;
		data["nTradeTime"] = steptrade->nTradeTime;
		data["nTradePrice"] = steptrade->nTradePrice;
		data["iTradeQty"] = steptrade->iTradeQty;
		data["iTradeMoney"] = steptrade->iTradeMoney;
		data["iTradeBuyNo"] = steptrade->iTradeBuyNo;
		data["iTradeSellNo"] = steptrade->iTradeSellNo;
		data["cTradeBSflag"] = steptrade->cTradeBSflag;
		data["sRes"] = toUtf(steptrade->sRes);
	}
	this->onSHTrade(code, data);
};

void MdApi::OnSZTrade(char *code, T_SZ_STEPTRADE *steptrade)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["usChannelNo"] = steptrade->usChannelNo;
		data["i64ApplSeqNum"] = steptrade->i64ApplSeqNum;
		data["sMDStreamID"] = toUtf(steptrade->sMDStreamID);
		data["i64BidApplSeqNum"] = steptrade->i64BidApplSeqNum;
		data["i64OfferApplSeqNum"] = steptrade->i64OfferApplSeqNum;
		data["sSecurityID"] = toUtf(steptrade->sSecurityID);
		data["sSecurityIDSource"] = toUtf(steptrade->sSecurityIDSource);
		data["i64LastPx"] = steptrade->i64LastPx;
		data["i64LastQty"] = steptrade->i64LastQty;
		data["cExecType"] = steptrade->cExecType;
		data["i64TransactTime"] = steptrade->i64TransactTime;
		data["sExtendFields"] = toUtf(steptrade->sExtendFields);
	}
	this->onSZTrade(code, data);
};

void MdApi::OnSZOrder(char *code, T_SZ_STEPORDER *steporder)
{
	
	gil_scoped_acquire acquire;
	dict data;
	{
		data["usChannelNo"] = steporder->usChannelNo;
		data["i64ApplSeqNum"] = steporder->i64ApplSeqNum;
		data["sMDStreamID"] = toUtf(steporder->sMDStreamID);
		data["sSecurityID"] = toUtf(steporder->sSecurityID);
		data["sSecurityIDSource"] = toUtf(steporder->sSecurityIDSource);
		data["i64Price"] = steporder->i64Price;
		data["i64OrderQty"] = steporder->i64OrderQty;
		data["cSide"] = steporder->cSide;
		data["i64TransactTime"] = steporder->i64TransactTime;
		data["sExtendFields"] = toUtf(steporder->sExtendFields);
	}
	this->onSZOrder(code, data);
};

void MdApi::OnSHBaseInfo(char *code, T_SH_BaseInfo *baseinfodata)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["szStkCode"] = toUtf(baseinfodata->szStkCode);
		// data["szISIN"] = baseinfodata->szISIN;
		data["uUpdateTime"] = baseinfodata->uUpdateTime;
		data["szStkNameZN"] = toUtf(baseinfodata->szStkNameZN);
		data["szStkNameEn"] = toUtf(baseinfodata->szStkNameEn);
		data["szUnderlyingCode"] = toUtf(baseinfodata->szUnderlyingCode);
		data["szMktClass"] = toUtf(baseinfodata->szMktClass);
		data["szStkClass"] = toUtf(baseinfodata->szStkClass);
		data["szStkSubClass"] = toUtf(baseinfodata->szStkSubClass);
		data["szCurrency"] = toUtf(baseinfodata->szCurrency);
		data["i64FaceValue"] = baseinfodata->i64FaceValue;
		data["i64MatchQty"] = baseinfodata->i64MatchQty;
		data["szLastDate"] = toUtf(baseinfodata->szLastDate);
		data["uListingData"] = baseinfodata->uListingData;
		data["uProductSETId"] = baseinfodata->uProductSETId;
		data["i64BuyNumUnit"] = baseinfodata->i64BuyNumUnit;
		data["i64SellNumUnit"] = baseinfodata->i64SellNumUnit;
		data["i64DecalaredLowestNum"] = baseinfodata->i64DecalaredLowestNum;
		data["i64DecalaredHightestNum"] = baseinfodata->i64DecalaredHightestNum;
		data["i64PreClosePrice"] = baseinfodata->i64PreClosePrice;
		data["i64PriceLevel"] = baseinfodata->i64PriceLevel;
		data["cPriceLimitsType"] = baseinfodata->cPriceLimitsType;
		data["i64UpLimitsPrice"] = baseinfodata->i64UpLimitsPrice;
		data["i64LowerLimitPrice"] = baseinfodata->i64LowerLimitPrice;
		data["i64DividendRatio"] = baseinfodata->i64DividendRatio;
		data["i64DividendAmount"] = baseinfodata->i64DividendAmount;
		data["cFinaSubjectFlag"] = baseinfodata->cFinaSubjectFlag;
		data["cMarginSubjectFlag"] = baseinfodata->cMarginSubjectFlag;
		data["szProdStatusFlag"] = toUtf(baseinfodata->szProdStatusFlag);
		data["i64MPDecalaredLowestNum"] = baseinfodata->i64MPDecalaredLowestNum;
		data["i64MPDecalaredHightestNum"] = baseinfodata->i64MPDecalaredHightestNum;
		data["szStkNameZNLong"] = toUtf(baseinfodata->szStkNameZNLong);
		data["szNote"] = toUtf(baseinfodata->szNote);
	}
	this->onSHBaseInfo(code, data);
};

void MdApi::OnSZBaseInfo(char *code, t_SZ_BaseInfo *baseinfodata)
{
	gil_scoped_acquire acquire;
	dict data;

	{
		data["sSecurityID"] = toUtf(baseinfodata->tBase.sSecurityID);
		data["sSecurityIDSource"] = toUtf(baseinfodata->tBase.sSecurityIDSource);
		data["sSymbol"] = toUtf(baseinfodata->tBase.sSymbol);
		data["sEnglishName"] = toUtf(baseinfodata->tBase.sEnglishName);
		data["sISIN"] = toUtf(baseinfodata->tBase.sISIN);
		data["sUnderlyingSecurityID"] = toUtf(baseinfodata->tBase.sUnderlyingSecurityID);
		data["sUnderlyingSecurityIDSource"] = toUtf(baseinfodata->tBase.sUnderlyingSecurityIDSource);
		data["uListDate"] = baseinfodata->tBase.uListDate;
		data["usSecurityType"] = baseinfodata->tBase.usSecurityType;
		data["sCurrency"] = toUtf(baseinfodata->tBase.sCurrency);
		data["i64QtyUnit"] = baseinfodata->tBase.i64QtyUnit;
		data["cDayTrading"] = baseinfodata->tBase.cDayTrading;
		data["i64PrevClosePx"] = baseinfodata->tBase.i64PrevClosePx;
		data["usSecurityStatus"] = baseinfodata->tBase.usSecurityStatus;
		data["i64OutstandingShare"] = baseinfodata->tBase.i64OutstandingShare;
		data["i64PublicFloatShareQuantity"] = baseinfodata->tBase.i64PublicFloatShareQuantity;
		data["i64ParValue"] = baseinfodata->tBase.i64ParValue;
		data["cGageFlag"] = baseinfodata->tBase.cGageFlag;
		data["nGageRatio"] = baseinfodata->tBase.nGageRatio;
		data["cCrdBuyUnderlying"] = baseinfodata->tBase.cCrdBuyUnderlying;
		data["cCrdSellUnderlying"] = baseinfodata->tBase.cCrdSellUnderlying;
		data["nPriceCheckMode"] = baseinfodata->tBase.nPriceCheckMode;
		data["cPledgeFlag"] = baseinfodata->tBase.cPledgeFlag;
		data["i64ContractMultiplier"] = baseinfodata->tBase.i64ContractMultiplier;
		data["sRegularShare"] = toUtf(baseinfodata->tBase.sRegularShare);
		data["cQualificationFlag"] = baseinfodata->tBase.cQualificationFlag;
		data["sSecurityID"] = toUtf(baseinfodata->tCashParams.sSecurityID);
		data["sSecurityIDSource"] = toUtf(baseinfodata->tCashParams.sSecurityIDSource);
		data["i64BuyQtyUpperLimit"] = baseinfodata->tCashParams.i64BuyQtyUpperLimit;
		data["i64SellQtyUpperLimit"] = baseinfodata->tCashParams.i64SellQtyUpperLimit;
		data["i64BuyQtyUnit"] = baseinfodata->tCashParams.i64BuyQtyUnit;
		data["i64SellQtyUnit"] = baseinfodata->tCashParams.i64SellQtyUnit;
		data["i64PriceTick"] = baseinfodata->tCashParams.i64PriceTick;
	}
	this->onSZBaseInfo(code, data);
};

void MdApi::OnSHOptionBaseInfo(char* code, t_SHOP_BaseInfo* baseinfodata)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["sSecurityID"] = toUtf(baseinfodata->sSecurityID);
		data["sContractID"] = toUtf(baseinfodata->sContractID);
		data["sContractSymbol"] = toUtf(baseinfodata->sContractSymbol);
		data["sUnderlyingSecurityID"] = toUtf(baseinfodata->sUnderlyingSecurityID);
		data["sUnderlyingSymbol"] = toUtf(baseinfodata->sUnderlyingSymbol);
		data["sUnderlyingType"] = toUtf(baseinfodata->sUnderlyingType);
		data["cOptionType"] = baseinfodata->cOptionType;
		data["cCallOrPut"] = baseinfodata->cCallOrPut;
		data["uContractMultiplierUnit"] = baseinfodata->uContractMultiplierUnit;
		data["uExercisePrice"] = baseinfodata->uExercisePrice;
		data["sStartDate"] = toUtf(baseinfodata->sStartDate);
		data["sEndDate"] = toUtf(baseinfodata->sEndDate);
		data["sExerciseDate"] = toUtf(baseinfodata->sExerciseDate);
		data["sDeliveryDate"] = toUtf(baseinfodata->sDeliveryDate);
		data["sExpireDate"] = toUtf(baseinfodata->sExpireDate);
		data["cUpdateVersion"] = baseinfodata->cUpdateVersion;
		data["iTotalLongPosition"] = baseinfodata->iTotalLongPosition;
		data["uSecurityClosePx"] = baseinfodata->uSecurityClosePx;
		data["uSettlPrice"] = baseinfodata->uSettlPrice;
		data["uUnderlyingClosePx"] = baseinfodata->uUnderlyingClosePx;
		data["cPriceLimitType"] = baseinfodata->cPriceLimitType;
		data["uDailyPriceUpLimit"] = baseinfodata->uDailyPriceUpLimit;
		data["uDailyPriceDownLimit"] = baseinfodata->uDailyPriceDownLimit;
		data["uMarginUnit"] = baseinfodata->uMarginUnit;
		data["nMarginRatioParam1"] = baseinfodata->nMarginRatioParam1;
		data["nMarginRatioParam2"] = baseinfodata->nMarginRatioParam2;
		data["uRoundLot"] = baseinfodata->uRoundLot;
		data["uLmtOrdMinFloor"] = baseinfodata->uLmtOrdMinFloor;
		data["uLmtOrdMaxFloor"] = baseinfodata->uLmtOrdMaxFloor;
		data["uMktOrdMinFloor"] = baseinfodata->uMktOrdMinFloor;
		data["uMktOrdMaxFloor"] = baseinfodata->uMktOrdMaxFloor;
		data["uTickSize"] = baseinfodata->uTickSize;
		data["sSecurityStatusFlag"] = toUtf(baseinfodata->sSecurityStatusFlag);
	}
	this->onSHOptionBaseInfo(code, data);
};

void MdApi::OnSZOptionBaseInfo(char* code, t_SZOP_BaseInfo* baseinfodata) 
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["sSecurityID"] = toUtf(baseinfodata->tBase.sSecurityID);
		data["sSecurityIDSource"] = toUtf(baseinfodata->tBase.sSecurityIDSource);
		data["sSymbol"] = toUtf(baseinfodata->tBase.sSymbol);
		data["sEnglishName"] = toUtf(baseinfodata->tBase.sEnglishName);
		data["sISIN"] = toUtf(baseinfodata->tBase.sISIN);
		data["sUnderlyingSecurityID"] = toUtf(baseinfodata->tBase.sUnderlyingSecurityID);
		data["sUnderlyingSecurityIDSource"] = toUtf(baseinfodata->tBase.sUnderlyingSecurityIDSource);
		data["uListDate"] = baseinfodata->tBase.uListDate;
		data["usSecurityType"] = baseinfodata->tBase.usSecurityType;
		data["sCurrency"] = toUtf(baseinfodata->tBase.sCurrency);
		data["i64QtyUnit"] = baseinfodata->tBase.i64QtyUnit;
		data["cDayTrading"] = baseinfodata->tBase.cDayTrading;
		data["i64PrevClosePx"] = baseinfodata->tBase.i64PrevClosePx;
		data["usSecurityStatus"] = baseinfodata->tBase.usSecurityStatus;
		data["i64OutstandingShare"] = baseinfodata->tBase.i64OutstandingShare;
		data["i64PublicFloatShareQuantity"] = baseinfodata->tBase.i64PublicFloatShareQuantity;
		data["i64ParValue"] = baseinfodata->tBase.i64ParValue;
		data["cGageFlag"] = baseinfodata->tBase.cGageFlag;
		data["nGageRatio"] = baseinfodata->tBase.nGageRatio;
		data["cCrdBuyUnderlying"] = baseinfodata->tBase.cCrdBuyUnderlying;
		data["cCrdSellUnderlying"] = baseinfodata->tBase.cCrdSellUnderlying;
		data["nPriceCheckMode"] = baseinfodata->tBase.nPriceCheckMode;
		data["cPledgeFlag"] = baseinfodata->tBase.cPledgeFlag;
		data["i64ContractMultiplier"] = baseinfodata->tBase.i64ContractMultiplier;
		data["sRegularShare"] = toUtf(baseinfodata->tBase.sRegularShare);
		data["cQualificationFlag"] = baseinfodata->tBase.cQualificationFlag;
		data["sSecurityID"] = toUtf(baseinfodata->tDeParmas.sSecurityID);
		data["sSecurityIDSource"] = baseinfodata->tDeParmas.sSecurityIDSource;
		data["i64BuyQtyUpperLimit"] = baseinfodata->tDeParmas.i64BuyQtyUpperLimit;
		data["i64SellQtyUpperLimit"] = baseinfodata->tDeParmas.i64SellQtyUpperLimit;
		data["i64BuyQtyUnit"] = baseinfodata->tDeParmas.i64BuyQtyUnit;
		data["i64SellQtyUnit"] = baseinfodata->tDeParmas.i64SellQtyUnit;
		data["i64PriceTick"] = baseinfodata->tDeParmas.i64PriceTick;
	}
	this->onSZOptionBaseInfo(code, data);
};

void MdApi::OnFuturesBaseInfo(MKtype mk_type, char* code, T_Instrument_BaseInfo* baseinfodata)
{
	gil_scoped_acquire acquire;
	dict data;

	{
		data["sInstrumentID"] = toUtf(baseinfodata->sInstrumentID);
		data["sExchangeID"] = toUtf(baseinfodata->sExchangeID);
		data["sInstrumentName"] = toUtf(baseinfodata->sInstrumentName);
		data["sExchangeInstID"] = toUtf(baseinfodata->sExchangeInstID);
		data["sProductID"] = toUtf(baseinfodata->sProductID);
		data["cProductClass"] = baseinfodata->cProductClass;
		data["nDeliveryYear"] = baseinfodata->nDeliveryYear;
		data["nDeliveryMonth"] = baseinfodata->nDeliveryMonth;
		data["nMaxMarketOrderVolume"] = baseinfodata->nMaxMarketOrderVolume;
		data["nMinMarketOrderVolume"] = baseinfodata->nMinMarketOrderVolume;
		data["nMaxLimitOrderVolume"] = baseinfodata->nMaxLimitOrderVolume;
		data["nMinLimitOrderVolume"] = baseinfodata->nMinLimitOrderVolume;
		data["nVolumeMultiple"] = baseinfodata->nVolumeMultiple;
		data["i64PriceTick"] = baseinfodata->i64PriceTick;
		data["nCreateDate"] = baseinfodata->nCreateDate;
		data["nOpenDate"] = baseinfodata->nOpenDate;
		data["nExpireDate"] = baseinfodata->nExpireDate;
		data["nStartDelivDate"] = baseinfodata->nStartDelivDate;
		data["nEndDelivDate"] = baseinfodata->nEndDelivDate;
		data["cInstLifePhase"] = baseinfodata->cInstLifePhase;
		data["nIsTrading"] = baseinfodata->nIsTrading;
		data["cPositionType"] = baseinfodata->cPositionType;
		data["cPositionDateType"] = baseinfodata->cPositionDateType;
		data["i64LongMarginRatio"] = baseinfodata->i64LongMarginRatio;
		data["i64ShortMarginRatio"] = baseinfodata->i64ShortMarginRatio;
		data["cMaxMarginSideAlgorithm"] = baseinfodata->cMaxMarginSideAlgorithm;
		data["sUnderlyingInstrID"] = baseinfodata->sUnderlyingInstrID;
		data["i64StrikePrice"] = baseinfodata->i64StrikePrice;
		data["cOptionsType"] = baseinfodata->cOptionsType;
		data["i64UnderlyingMultiple"] = baseinfodata->i64UnderlyingMultiple;
		data["cCombinationType"] = baseinfodata->cCombinationType;
		data["i64UplimitPrice"] = baseinfodata->i64UplimitPrice;
		data["i64LowlimitPrice"] = baseinfodata->i64LowlimitPrice;
	}
	this->onFuturesBaseInfo(int(mk_type), code, data);
};

void MdApi::OnKline(MKtype mk_type, char *code, T_Kline *kline)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["uDay"] = kline->uDay;
		data["nTime"] = kline->nTime;
		data["nPreClose"] = kline->nPreClose;
		data["nValOpen"] = kline->nValOpen;
		data["nValHigh"] = kline->nValHigh;
		data["nValLow"] = kline->nValLow;
		data["nValClose"] = kline->nValClose;
		data["i64Volume"] = kline->i64Volume;
		data["i64ValTotal"] = kline->i64ValTotal;
		data["i64TotalVol"] = kline->i64TotalVol;
		data["i64TotalTurnOver"] = kline->i64TotalTurnOver;
		data["nTurover"] = kline->nTurover;
		data["nValIncrease"] = kline->nValIncrease;
	}
	this->onKline(mk_type, code, data);
};

void MdApi::OnFuturesData(MKtype mk_type, char* code, Futures_MarketData* futuresdata)
{
	gil_scoped_acquire acquire;
	dict data;

	{
		data["nTime"] = futuresdata->nTime;
		data["nStatus"] = futuresdata->nStatus;
		data["iPreOpenInterest"] = futuresdata->iPreOpenInterest;
		data["uPreClose"] = futuresdata->uPreClose;
		data["uPreSettlePrice"] = futuresdata->uPreSettlePrice;
		data["uOpen"] = futuresdata->uOpen;
		data["uHigh"] = futuresdata->uHigh;
		data["uLow"] = futuresdata->uLow;
		data["uMatch"] = futuresdata->uMatch;
		data["iVolume"] = futuresdata->iVolume;
		data["iTurnover"] = futuresdata->iTurnover;
		data["iOpenInterest"] = futuresdata->iOpenInterest;
		data["uClose"] = futuresdata->uClose;
		data["uSettlePrice"] = futuresdata->uSettlePrice;
		data["uHighLimited"] = futuresdata->uHighLimited;
		data["uLowLimited"] = futuresdata->uLowLimited;
		data["nPreDelta"] = futuresdata->nPreDelta;
		data["nCurrDelta"] = futuresdata->nCurrDelta;
		data["sTradingStatus"] = futuresdata->sTradingStatus;
		data["sRevs"] = futuresdata->sRevs;
		data["nTradingDay"] = futuresdata->nTradingDay;
		data["nActionDay"] = futuresdata->nActionDay;

		pybind11::list ask;
		pybind11::list bid;
		pybind11::list ask_qty;
		pybind11::list bid_qty;

		for (int i = 0; i < 5; i++)
		{
			ask.append(futuresdata->uAskPrice[i]);
			bid.append(futuresdata->uBidPrice[i]);
			ask_qty.append(futuresdata->uAskVol[i]);
			bid_qty.append(futuresdata->uBidVol[i]);
		}

		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;
	}
	this->onFuturesData(int(mk_type), code, data);
};

void MdApi::OnEtfExtData(MKtype mk_type, char *code, T_ETFEXTENDS *etfextdata)
{
	gil_scoped_acquire acquire;
	dict data;
	{
		data["nTime"] = etfextdata->nTime;
		data["nIOPV"] = etfextdata->nIOPV;
		data["nEtfBuyNum"] = etfextdata->nEtfBuyNum;
		data["i64EtfBuyAmount"] = etfextdata->i64EtfBuyAmount;
		data["i64EtfBuyMoney"] = etfextdata->i64EtfBuyMoney;
		data["nEtfSellNum"] = etfextdata->nEtfSellNum;
		data["i64EtfSellAmount"] = etfextdata->i64EtfSellAmount;
		data["i64EtfSellMoney"] = etfextdata->i64EtfSellMoney;
		data["nWithDrawBuyNum"] = etfextdata->nWithDrawBuyNum;
		data["i64WithDrawBuyAmount"] = etfextdata->i64WithDrawBuyAmount;
		data["i64WithDrawBuyMoney"] = etfextdata->i64WithDrawBuyMoney;
		data["nWithDrawSellNum"] = etfextdata->nWithDrawSellNum;
		data["i64WithDrawSellAmount"] = etfextdata->i64WithDrawSellAmount;
		data["i64WithDrawSellMoney"] = etfextdata->i64WithDrawSellMoney;
	}
	this->onEtfExtData(mk_type, code, data);
};



///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------
int MdApi::initialize(string sjson, bool logging)
{
	this->logging = logging;
	this->api = CSipMdApi::Register(this);

	int i = this->api->Initialize(sjson.c_str());
	this->active = true;

	return i;
};

int MdApi::login()
{
	int i = this->api->Login();
	return i;
};
int MdApi::stop()
{
	int i = this->api->Stop();
	return i;
};

void MdApi::release()
{
	this->api->Release();
};

string MdApi::getVersion()
{
	return this->api->GetVersion();
}

int MdApi::exit()
{
	this->api->Stop();
	this->api->Register(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

int MdApi::subscribeDepthMarketData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeDepthMarketData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeMarketData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeMarketData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeIndexData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeIndexData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeDepthMarketData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeDepthMarketData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeMarketData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeMarketData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeIndexData(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeIndexData((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeOrderQueue(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeOrderQueue((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeOrderQueue(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeOrderQueue((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeStepTrade(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeStepTrade((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeStepTrade(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeStepTrade((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeStepOrder(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeStepOrder((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeStepOrder(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeStepOrder((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeBaseInfo(int mk_type)
{
	int i = this->api->SubscribeBaseInfo((MKtype)mk_type);
	return i;
};

int MdApi::unSubscribeBaseInfo(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeBaseInfo((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeKline(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeKline((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeKline(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeKline((MKtype)mk_type, myreq, 1);
	return i;
};

int32_t MdApi::subscribeFutures(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeFutures((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeFutures(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeFutures((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::subscribeEtfExt(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeEtfExt((MKtype)mk_type, myreq, 1);
	return i;
};

int MdApi::unSubscribeEtfExt(int mk_type, string code)
{
	char* buffer = (char*)code.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeEtfExt((MKtype)mk_type, myreq, 1);
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyMdApi : public MdApi
{
public:
    using MdApi::MdApi;
    
	void onLog(int level, string source, string slog) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onLog, level, source, slog);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onLogin(int chn) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onLogin, chn);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onDisconnect(int chn) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onDisconnect, chn);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSubscribe(const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSubscribe, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onUnSubscribe(const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onUnSubscribe, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onDepthMarketData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onDepthMarketData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFastDepthMarketData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFastDepthMarketData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onMarketData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onMarketData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onIndexData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onIndexData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSHOption(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSHOption, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSZOption(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSZOption, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onOrderQueue(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onOrderQueue, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSHTrade(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSHTrade, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSHOrder(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSHOrder, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSZTrade(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSZTrade, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSZOrder(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSZOrder, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSHBaseInfo(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSHBaseInfo, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSZBaseInfo(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSZBaseInfo, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};
	
	void onSHOptionBaseInfo(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSHOptionBaseInfo, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSZOptionBaseInfo(string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onSZOptionBaseInfo, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFuturesBaseInfo(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFuturesBaseInfo, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onKline(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onKline, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFuturesData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFuturesData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onEtfExtData(int mk_type, string code, const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onEtfExtData, mk_type, code, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};


};


PYBIND11_MODULE(vnsip, m)
{
    class_<MdApi, PyMdApi> MdApi(m, "MdApi", module_local());
    MdApi
        .def(init<>())
		.def("initialize", &MdApi::initialize)
		.def("login", &MdApi::login)
		.def("stop", &MdApi::stop)
		.def("release", &MdApi::release)
		.def("getVersion", &MdApi::getVersion)
		.def("exit", &MdApi::exit)
		.def("subscribeDepthMarketData", &MdApi::subscribeDepthMarketData)
		.def("subscribeMarketData", &MdApi::subscribeMarketData)
		.def("subscribeIndexData", &MdApi::subscribeIndexData)
		.def("unSubscribeDepthMarketData", &MdApi::unSubscribeDepthMarketData)
		.def("unSubscribeMarketData", &MdApi::unSubscribeMarketData)
		.def("unSubscribeIndexData", &MdApi::unSubscribeIndexData)
		.def("subscribeOrderQueue", &MdApi::subscribeOrderQueue)
		.def("unSubscribeOrderQueue", &MdApi::unSubscribeOrderQueue)
		.def("subscribeStepTrade", &MdApi::subscribeStepTrade)
		.def("unSubscribeStepTrade", &MdApi::unSubscribeStepTrade)
		.def("subscribeStepOrder", &MdApi::subscribeStepOrder)
		.def("unSubscribeStepOrder", &MdApi::unSubscribeStepOrder)
		.def("subscribeBaseInfo", &MdApi::subscribeBaseInfo)
		.def("unSubscribeBaseInfo", &MdApi::unSubscribeBaseInfo)
		.def("subscribeKline", &MdApi::subscribeKline)
		.def("unSubscribeKline", &MdApi::unSubscribeKline)
		.def("subscribeFutures", &MdApi::subscribeFutures)
		.def("unSubscribeFutures", &MdApi::unSubscribeFutures)
		.def("subscribeEtfExt", &MdApi::subscribeEtfExt)
		.def("unSubscribeEtfExt", &MdApi::unSubscribeEtfExt)

		.def("onLog", &MdApi::onLog)
		.def("onLogin", &MdApi::onLogin)
		.def("onDisconnect", &MdApi::onDisconnect)
		.def("onSubscribe", &MdApi::onSubscribe)
		.def("onUnSubscribe", &MdApi::onUnSubscribe)
		.def("onDepthMarketData", &MdApi::onDepthMarketData)
		.def("onFastDepthMarketData", &MdApi::onFastDepthMarketData)
		.def("onMarketData", &MdApi::onMarketData)
		.def("onIndexData", &MdApi::onIndexData)
		.def("onSHOption", &MdApi::onSHOption)
		.def("onSZOption", &MdApi::onSZOption)
		.def("onOrderQueue", &MdApi::onOrderQueue)
		.def("onSHTrade", &MdApi::onSHTrade)
		.def("onSHOrder", &MdApi::onSHOrder)
		.def("onSZTrade", &MdApi::onSZTrade)
		.def("onSZOrder", &MdApi::onSZOrder)
		.def("onSHBaseInfo", &MdApi::onSHBaseInfo)
		.def("onSZBaseInfo", &MdApi::onSZBaseInfo)
		.def("onSHOptionBaseInfo", &MdApi::onSHOptionBaseInfo)
		.def("onSZOptionBaseInfo", &MdApi::onSZOptionBaseInfo)
		.def("onFuturesBaseInfo", &MdApi::onFuturesBaseInfo)
		.def("onKline", &MdApi::onKline)
		.def("onFuturesData", &MdApi::onFuturesData)
		.def("onEtfExtData", &MdApi::onEtfExtData)
		;
}
