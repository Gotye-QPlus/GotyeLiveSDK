//
//  GLChatMessage.h
//  GotyeLiveChat
//
//  Created by Nick on 15/11/3.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    GLChatMessageStatusDefault,     //默认状态。收到的消息以及本地创建的没有进行发送的消息都为该状态
    GLChatMessageStatusSending,     //正在发送中
    GLChatMessageStatusSent,        //已发送
    GLChatMessageStatusSendFailed   //发送失败
}GLChatMessageStatus;

//由于服务器不对type进行判断，开发者可自行定义消息的枚举类型。
typedef enum
{
    GLChatMessageTypeText = 1,      //文本消息
    GLChatMessageTypeNotify = 3     //通知消息
}GLChatMessageType;

@interface GLChatMessage : NSObject

@property (nonatomic, copy) NSString * recvId;                  // 接收者ID。当消息是聊天室消息时，该值为空
@property (nonatomic, copy) NSString * recvName;                //接收者昵称。当消息是聊天室消息时，该值为空
@property (nonatomic, copy) NSString * text;                    //消息的具体内容
@property (nonatomic, copy) NSString * sendId;                  //发送者ID
@property (nonatomic, copy) NSString * sendName;                //发送者昵称
@property (nonatomic, assign) NSString * extra;                 //消息额外字段
@property (nonatomic, assign) NSInteger type;                   //消息类型
@property (nonatomic, assign) GLChatMessageStatus status;       //消息状态

@end
