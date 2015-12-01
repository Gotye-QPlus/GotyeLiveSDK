//
//  GLLiveContext.h
//  GotyeLiveCore
//
//  Created by Nick on 15/10/29.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import "GLKeyValueObject.h"

@interface GLLiveContext : GLKeyValueObject

@property (nonatomic, copy) NSString * publisherAccount;    // 主讲人账号
@property (nonatomic, copy) NSString * share;               // 当前共享数据
@property (nonatomic, assign) NSInteger recordingStatus;     // 1-录制中 0-停录中
@property (nonatomic, copy) NSString * talkerAccount;       // 当前给麦人
@property (nonatomic, assign) NSInteger playUserCount;       // 当前播放视频人数

@end
