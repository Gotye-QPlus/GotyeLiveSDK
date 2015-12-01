//
//  GLChatErrorCode.h
//  GotyeLiveChat
//
//  Created by Nick on 15/11/3.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#ifndef GLChatErrorCode_h
#define GLChatErrorCode_h

typedef enum
{
    GLChatErrorCodeFail = 300,                 // 失败
    GLChatErrorCodeInvalidToken = 401,         // 无效token
    GLChatErrorCodeInvalidRole = 403,          // 无效角色,只有聊天室role可以登陆
    GLChatErrorCodeSystemError = 500,          // 系统异常
    GLChatErrorCodePermissionDenied = 1001,    // 无操作权限
    GLChatErrorCodeDisableSpeak = 1003,        // 已被禁言
    GLChatErrorCodeContentIsNull = 1005,       // 消息内容和附加字段都为空
    GLChatErrorCodeInvalidTargetID = 1007,     // 无效TARGET_ID
    GLChatErrorCodeForbidden = 1009,           // 已经被禁止登陆
    
    GLChatErrorCodeParseError = -101,           //数据解析出错
    GLChatErrorCodeNetworkError = -102,         //网络错误
    GLChatErrorCodeNotLogin = -103,             //当前没有登录
    GLChatErrorCodeAlreadyLogin = -104,
}GLChatErrorCode;

#endif /* GLChatErrorCode_h */
