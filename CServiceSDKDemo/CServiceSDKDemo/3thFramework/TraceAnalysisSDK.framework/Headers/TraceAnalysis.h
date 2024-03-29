//
//  TraceAnalysis.h

//
//  Created by samliu on 2017/7/4.
//  Copyright © 2017年 samliu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TraceNetGlobalZoneDefine.h"

@interface TraceAnalysis : NSObject

/**
 SDK初始化
 
 @param productId 分配的产品编号
 @param channelId 渠道编号
 @param appId     "id" + Apple ID
 */
+ (void)initWithProductId:(NSString *)productId ChannelId:(NSString *)channelId AppID:(NSString *)appId;

/**
 SDK初始化
 
 @param productId 分配的产品编号
 @param channelId 渠道编号
 @param appId "id" + Apple ID
 @param zone 发行区域（中国大陆/海外）
 */
+ (void)initWithProductId:(NSString *)productId ChannelId:(NSString *)channelId AppID:(NSString *)appId zone:(TraceAnalsisGlobalZone)zone;

/**
 * This method is called when the user refuses to obtain privacy information.
 */
+ (void)disableAccessPrivacyInformation;

/**
 获取SDK版本
 
 @return 版本号
 */
+ (NSString *)SDKVersion;

/**
 获取统计包token
 
 @return 统计包token
 */
+ (NSString *)staToken;

+ (NSString *)getOpenId;

/**
 设置扩展参数
 
 @param ext 扩展参数
 */
+ (void)setExt:(NSDictionary *)ext;


/**
 追加扩展参数
 
 @param addExt 需要追加的扩展参数，如与已有的扩展参数冲突，则覆盖冲突部分
 */
+ (void)addExt:(NSDictionary *)addExt;

/**
 keyValue 打点
 以即时发送的方式，实现数据上报一些重要性很高的数据
 @param key   键
 @param value 值，可以是string，array，dictionary
 */
+ (void)logWithKey:(NSString *)key value:(id)value;

/**
 keyValue 打点
 以即时发送的方式，实现数据上报
 主要用于上传一些针对异常情况的打点，例如网络异常，或程序try-catch异常等内容重复率比较大，重要性较低的数据
 @param key   键
 @param value 值，可以是string，array，dictionary
 */
+ (void)logExceptionWithKey:(NSString *)key value:(id)value;

/**
 计数打点
 
 @param key key
 */
+ (void)countWithKey:(NSString *)key;

/**
 自定义keyValue 打点
 
 @param key   键
 @param value 值
 */
+ (void)customLogWithKey:(NSString *)key value:(NSString *)value;

/**
 GAP 打点
 */
+ (void)GAPLog;

/**
 游客登录 上报
 
 @param playerId 游戏用户ID
 */
+ (void)guestLoginWithGameId:(NSString *)playerId;

/**
 Facebook登录 上报
 
 @param playerId  游戏用户ID
 @param openId    openId
 @param openToken openToken
 */
+ (void)facebookLoginWithGameId:(NSString *)playerId
                         OpenId:(NSString *)openId
                      OpenToken:(NSString *)openToken;

/**
 twitter登录 上报
 
 @param playerId 游戏用户ID
 @param twitterId 推特用户id
 @param twitterUserName 推特用户Name
 @param twitterAuthToken 推特用户Token
 */
+ (void)twitterLoginWithPlayerId:(NSString *)playerId
                       twitterId:(int64_t)twitterId
                 twitterUserName:(NSString *)twitterUserName
                twitterAuthToken:(NSString *)twitterAuthToken;

/**
 平台登录 上报
 
 @param playerId 游戏用户ID
 @param portalId 平台Id
 */
+ (void)portalLoginWithPlayerId:(NSString *)playerId
                       portalId:(NSString *)portalId;

/**
 内购 上报（已废弃，请使用 LogZFWithPlayerId:receiptDataString: ）
 
 @param playerId 分配的player编号
 @param gameId 分配的游戏编号
 @param receiptDataString 内购收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogZFWithPlayerId:(NSString *)playerId gameId:(NSString *)gameId receiptDataString:(NSString *)receiptDataString __deprecated_msg("Method deprecated. Use `LogZFWithPlayerId:receiptDataString:`");

/**
 内购支付 上报
 
 @param playerId          游戏用户ID
 @param receiptDataString 内购收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogZFWithPlayerId:(NSString *)playerId receiptDataString:(NSString *)receiptDataString;

+ (void)LogZFWithPlayerId:(NSString *)playerId receiptDataString:(NSString *)receiptDataString extraMap:(NSDictionary *)extraMap;

/**
 内购支付 上报
 
 @param playerId          游戏用户ID
 @param gameAccountServer 游戏区/服ID
 @param receiptDataString 内购收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogZFWithPlayerId:(NSString *)playerId gameAccountServer:(NSString *)gameAccountServer receiptDataString:(NSString *)receiptDataString;

+ (void)LogZFWithPlayerId:(NSString *)playerId gameAccountServer:(NSString *)gameAccountServer receiptDataString:(NSString *)receiptDataString extraMap:(NSDictionary *)extraMap;

/**
 第三方支付 上报
 
 @param playerId          游戏用户ID
 @param thirdparty        第三方支付平台名称
 @param receiptDataString 第三方支付平台单据
 */
+ (void)ThirdpartyLogZFWithPlayerId:(NSString *)playerId thirdparty:(NSString *)thirdparty receiptDataString:(NSString *)receiptDataString;

/**
 第三方支付 上报
 
 @param playerId          游戏用户ID
 @param gameAccountServer 游戏区/服ID
 @param thirdparty        第三方支付平台名称
 @param receiptDataString 第三方支付平台单据
 */
+ (void)ThirdpartyLogZFWithPlayerId:(NSString *)playerId gameAccountServer:(NSString *)gameAccountServer thirdparty:(NSString *)thirdparty receiptDataString:(NSString *)receiptDataString;

#pragma mark 打点不存数据库且立刻上报服务器

+ (void)logUploadWithKey:(NSString *)key value:(id)value;

@end
