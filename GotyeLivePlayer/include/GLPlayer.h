//
//  GotyeLivePlayer.h
//  GLPlayer
//
//  Created by Nick on 15/11/11.
//  Copyright © 2015年 AiLiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GLPlayerDelegate.h"

#define GLPlayerKit     [GLPlayer sharedInstance]

typedef NS_ENUM(NSInteger, GLPlayerErrorCode) {
    GLPlayerErrorCodeInvalidToken =             401,
    GLPlayerErrorCodeLiveNotStarttedYet =       500,
    GLPlayerErrorCodeIllegalState =             501,
    GLPlayerErrorCodeNetworkDisconnect =        101,
    GLPlayerErrorCodeGetLiveStateFailed =       102,
    GLPlayerErrorCodeGetLiveUrlFailed =         103
};

/**
 *  播放器的状态
 */
typedef NS_ENUM(NSInteger, GLPlayerState) {
    /**
     *  初始化时的默认状态
     */
    GLPlayerStateNone,
    /**
     *  播放器已停止
     */
    GLPlayerStateStopped,
    /**
     *  播放器发生错误
     */
    GLPlayerStateError,
    /**
     *  正在重新尝试播放视频
     */
    GLPlayerStateReConnecting,
    /**
     *  正在第一次尝试播放视频
     */
    GLPlayerStateStarting,
    /**
     *  成功开始播放视频
     */
    GLPlayerStateStarted,
};

@class GLRoomSession;

@interface GLPlayer : NSObject

/**
 *  获取GLPlayer的单例
 *
 *  @return GLPlayer的单例
 */
+ (instancetype)sharedInstance;

/**
 *  初始化播放器模块
 *
 *  @param roomSession 聊天室session，可在初始化GLCore之后获取到
 */
- (void)initWithSession:(GLRoomSession *)roomSession;

/**
 *  播放视频。需要验证roomSession
 *
 *  @param playView 显示视频的view。视频的渲染视图将会以子view的方式显示在playView上，并且大小跟playView一样
 */
- (void)playWithView:(UIView *)playView;

/**
 *  停止播放视频
 */
- (void)stop;

/**
 *  当前视频是否静音。可以通过setter函数改变当前的静音状态
 */
@property (nonatomic, assign) BOOL mute;
/**
 *  视频的渲染视图。如果在调用play接口时，传入的view参数为nil，那么这个属性也为nil。
 *  可以将videoView添加到任意的父view上。
 */
@property (nonatomic, strong, readonly) UIView * videoView;
/**
 *  当调用play接口时，有可能直播还未开始，这时候会返回错误。如果没有调用stop接口，当直播开始并且autoPlay的值为YES时，视频会自动开始播放。
 *  默认情况下autoPlay的值为YES。
 */
@property (nonatomic, assign) BOOL autoPlay;
/**
 *  播放器状态的监听对象
 */
@property (nonatomic, weak) id<GLPlayerDelegate> delegate;
/**
 *  当前播放器的状态
 */
@property (nonatomic, assign, readonly) GLPlayerState state;

@end
