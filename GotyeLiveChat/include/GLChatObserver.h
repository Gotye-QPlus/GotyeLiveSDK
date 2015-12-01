//
//  GLChatObserver.h
//  GotyeLiveChat
//
//  Created by Nick on 15/11/3.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GLChatMessage;

@protocol GLChatObserver <NSObject>

@optional

/**
 *  收到消息时的回调
 *
 *  @param msg      收到消息的具体内容
 *  @param roomId   收到消息的聊天室的ID
 */
- (void)chatClientDidReceiveMessage:(GLChatMessage *)msg room:(NSString *)roomId;

/**
 *  与服务器失去连接时的回调
 *  @param roomId   断开连接的聊天室的ID
 *
 */
- (void)chatClientDidDisconnect:(NSString *)roomId;

/**
 *  正在尝试重新连接服务器时的回调（当与服务器失去连接时，API会自动进行重连）。
 *  @param roomId   正在重连的聊天室的ID
 */
- (void)chatClientReconnecting:(NSString *)roomId;

/**
 *  重新登录成功时的回调
 *  @param roomId   重新登录成功的聊天室的ID
 */
- (void)chatClientReLoginSuccess:(NSString *)roomId;

/**
 *  重新登录失败时的回调（这种情况一般是由于密码错误或者token过期之类的原因，导致认证失败）。
 *
 *  @param error    重登失败的具体错误
 *  @param roomId   重登失败的聊天室的ID
 */
- (void)chatClientReLoginFailed:(NSError *)error room:(NSString *)roomId;

/**
 *  账号在别处登录，   本地被强制踢下线的回调
 *  @param roomId   被强制踢出的聊天室的ID
 */
- (void)chatClientDidForceLogout:(NSString *)roomId;

@end
