//
//  GLCore.h
//  GotyeLiveCore
//
//  Created by Nick on 15/10/28.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "GLKeyValueObject.h"
#import "GLAuthToken.h"
#import "GLClientUrl.h"
#import "GLLiveContext.h"
#import "GLCoreErrorCode.h"

#define GLCoreKit   [GLCore sharedInstance]

@class GLRoomSession;

@interface GLCore : NSObject

/**
 *  当前房间的session信息，调用auth接口后会初始化roomSession的值
 */
@property (nonatomic, strong, readonly) GLRoomSession * roomSession;

/**
 *  获取GLCore的单实例
 *
 *  @return GLCore的单实例
 */
+ (instancetype)sharedInstance;

/**
 *  初始化API
 *
 *  @param accessSecret 开发者账号的Access Secret
 *  @param companyId    开发者账号中的公司唯一标识
 */
- (void)initWithAccessSecret:(NSString *)accessSecret companyId:(NSString *)companyId;

/**
 *  认证聊天室ID
 *
 *  @param roomId         聊天室ID
 *  @param password       聊天室密码（主播密码、助理密码或者普通用户密码）
 *  @param bindAccount    绑定账号，绑定账号相同生成的token，在登录时会互踢。不要绑定账号传nil
 *  @param nickname       希望在聊天室中显示的昵称
 *  @param isCustomRoomId 是否是第三方房间号
 *  @param success        成功回调
 *  @param failure        失败回调
 */
- (void)authRoomId:(NSString *)roomId
          password:(NSString *)password
       bindAccount:(NSString *)bindAccount
          nickname:(NSString *)nickname
    isCustomRoomId:(BOOL)isCustomRoomId
           success:(void (^)(GLAuthToken * authToken))success
           failure:(void (^)(NSError *error))failure;

/**
 *  清除验证信息。退出房间时调用
 */
- (void)clearAuthorization;

/**
 *  生成客户端播放地址
 *
 *  @param success  成功回调
 *  @param failure  失败回调
 */
- (void)getClientUrlsOnSuccess:(void(^)(GLClientUrl *clientUrl))success failure:(void(^)(NSError *error))failure;

/**
 *  查询直播上下文信息
 *
 *  @param success  成功回调
 *  @param failure  失败回调
 */
- (void)getLiveContextOnSuccess:(void(^)(GLLiveContext *liveContext))success failure:(void(^)(NSError *error))failure;

@end