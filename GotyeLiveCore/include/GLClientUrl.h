//
//  GLClientUrl.h
//  GotyeLiveCore
//
//  Created by Nick on 15/10/29.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import "GLKeyValueObject.h"

@interface GLClientUrl : GLKeyValueObject


/**
 modeChatUrl格式{CLIENT_URL}/chat/index.html?token={authorization}
 modPublisherShareUrl格式{CLIENT_URL}/share/publisher.html?token={authorization}
 modVisitorShareUrl格式{CLIENT_URL}/share/visitor.html?token={authorization}
 educVisitorUrl格式{CLIENT_URL}/educOnline/{LIVE_ROLE.visitor}/{key}/enter
 其中LIVE_ROLE.visitor是观看端角色名称，key由观看端角色、用户ID、主播室ID唯一确定。
 **/

@property (nonatomic, copy) NSString * modChatUrl;              // H5聊天室地址
@property (nonatomic, copy) NSString * modPublisherShareUrl;    // 课件主播端地址
@property (nonatomic, copy) NSString * modVisitorShareUrl;      // 课件观看端地址
@property (nonatomic, copy) NSString * educVisitorUrl;          // 直播观看地址

@end
