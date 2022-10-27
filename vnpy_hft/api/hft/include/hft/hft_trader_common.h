/**
 * @file    hft_trader_common.h
 * @brief   公共类型和数据定义
 */

#ifndef _HFT_TRADER_COMMON_H_
#define _HFT_TRADER_COMMON_H_

#ifdef _WIN32
#ifdef HFTSDK_EXPORTS
#define HFT_TRADER_EXPORT __declspec(dllexport)
#else
#define HFT_TRADER_EXPORT __declspec(dllimport)
#endif
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#define HFT_TRADER_EXPORT __global
#elif (defined(__GNUC__) && __GNUC__ >= 4) || defined(__INTEL_COMPILER)
#define HFT_TRADER_EXPORT __attribute__((visibility("default")))
#else
#define HFT_TRADER_EXPORT
#endif
#endif

#if defined(__osf__)
#include <inttypes.h>
#elif _MSC_VER && _MSC_VER < 1600
#ifndef int8_t
typedef signed char int8_t;
#endif
#ifndef int16_t
typedef short int16_t;
#endif
#ifndef int32_t
typedef int int32_t;
#endif
#ifndef int64_t
typedef long long int64_t;
#endif
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif
#ifndef uint16_t
typedef unsigned short uint16_t;
#endif
#ifndef uint32_t
typedef unsigned int uint32_t;
#endif
#ifndef uint64_t
typedef unsigned long long uint64_t;
#endif
#else
#include <stdint.h>
#endif  // _MSC_VER

#ifdef SWIG
#undef HFT_TRADER_EXPORT
#define HFT_TRADER_EXPORT
#endif

#include <stddef.h>

namespace HFT {

typedef char char4[5];
typedef char char8[9];
typedef char char16[17]; 
typedef char char32[33];
typedef char char40[41];
typedef char char64[65];
typedef char char128[129];
typedef char char256[257];
typedef char char512[513];
typedef char char1024[1025];
typedef char char2048[2049];
typedef char char4096[4097];

// 响应的错误消息
struct ErrorInfo {
    int32_t err_code;   // 错误码
    char256 err_msg;    // 错误消息，Windows是GBK，Linux是UTF8

    ErrorInfo() : err_code(0) {
        err_msg[0] = 0;
    }
};

// IP和端口信息
struct IpAddr {
    char40 ip;      // ip地址
    int port;       // 端口

    IpAddr() : port(0) {
        ip[0] = 0;
    }
};

// 日志级别
enum LogLevel {
    LogLevel_Debug,     // 调试级别
    LogLevel_Info,      // 信息级别
    LogLevel_Warn,      // 警告级别
    LogLevel_Error,     // 错误级别
    LogLevel_Critical,  // 致命级别
    LogLevel_Off,       // 关闭日志
};

}   // namespace HFT

#endif  // _HFT_TRADER_COMMON_H_
