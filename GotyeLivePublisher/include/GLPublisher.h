//
//  GLPublisher.h
//  GotyeLiveSDK
//
//  Created by Nick on 15/11/26.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GLPublisherDelegate.h"

@class GLRoomSession;

/**
 *  摄像头状态枚举
 */
typedef NS_ENUM(NSInteger, GLCameraState) {
    /**
     *  前置摄像头
     */
    GLCameraStateFront,
    /**
     *  后置摄像头
     */
    GLCameraStateBack
};


/**
 *  发布端状态枚举
 */
typedef NS_ENUM(NSInteger, GLPublisherState) {
    /**
     *  初始化状态
     */
    GLPublisherStateNone,
    /**
     *  调用stop之后的状态
     */
    GLPublisherStateStopped,
    /**
     *  出现错误时的状态
     */
    GLPublisherStateError,
    /**
     *  正在开启预览
     */
    GLPublisherStatePreviewStarting,
    /**
     *  预览成功开启
     */
    GLPublisherStatePreviewStarted,
    /**
     *  正在开始发布
     */
    GLPublisherStatePublishing,
    /**
     *  发布成功
     */
    GLPublisherStatePublished,
    /**
     *  正在重连
     */
    GLPublisherStateReconnecting
};

/**
 *  错误码枚举
 */
typedef NS_ENUM(NSInteger, GLPublisherErrorCode) {
    /**
     *  token无效
     */
    GLPublisherErrorCodeInvalidToken = 401,
    /**
     *  当前账号已经有人登录了
     */
    GLPublisherErrorCodeOccupied = 1011,
    /**
     *  当前已经有人在直播了
     */
    GLPublisherErrorCodeAlreadyPublished = -101,
    /**
     *  获取直播Url出错
     */
    GLPublisherErrorCodeGetUploadUrlFailed = -102,
    /**
     *  获取当前直播状态出错
     */
    GLPublisherErrorCodeGetPublishStateFailed = -103,
    /**
     *  无法获取摄像头，请检查权限
     */
    GLPublisherErrorCodeNeedAccessForCamera = -104,
    /**
     *  网络断开
     */
    GLPublisherErrorCodeNetworkDisconnect = -105,
    /**
     *  当前状态无效
     */
    GLPublisherErrorCodeIllegalState = -106,
    /**
     *  用户未登录
     */
    GLPublisherErrorCodeNotLogin = -107,
};

#define GLPublisherKit   [GLPublisher sharedInstance]

/**
 *  视频发布模块
 */
@interface GLPublisher : NSObject

/**
 *  获取GLPublisher的单例
 *
 *  @return GLPublisher的单例
 */
+ (instancetype)sharedInstance;

/**
 *  初始化视频发布模块
 *
 *  @param roomSession 聊天室session，可在初始化GLCore之后获取到
 */
- (void)initWithSession:(GLRoomSession *)roomSession;

/**
 *  登录主播账号。需要验证roomSession
 *
 *  @param force   是否强制踢出当前登录账号
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void)loginWithForce:(BOOL)force success:(void(^)())success failure:(void(^)(NSError *error))failure;

/**
 *  退出主播账号登录
 */
- (void)logout;

/**
 *  开启视频预览，默认开启前置摄像头
 *
 *  @param superViewOfPreview 视频预览的视图
 *  @param success            成功回调
 *  @param failure            失败回调。失败原因一般是由于没有开启摄像头权限
 */
- (void)startPreview:(UIView *)superViewOfPreview success:(void(^)())success failure:(void(^)(NSError *error))failure;

/**
 *  用选定的摄像头开启视频预览
 *
 *  @param superViewOfPreview 视频预览的视图
 *  @param cameraState        选定的摄像头
 *  @param success            成功回调
 *  @param failure            失败回调
 */
- (void)startPreview:(UIView *)superViewOfPreview withCameraState:(GLCameraState)cameraState success:(void(^)())success failure:(void(^)(NSError *error))failure;

/**
 *  开始发布视频。需要验证roomSession
 */
- (void)publish;

/**
 *  停止发布视频
 */
- (void)unpublish;

/**
 *  退出主播账号登录，停止发布视频并停止预览
 */
- (void)stop;

/**
 *  切换摄像头
 */
- (void)toggleCamera;

/**
 *  视频发布状态回调
 */
@property (nonatomic, weak) id<GLPublisherDelegate> delegate;
/**
 *  摄像头状态，可以通过设置该变量的值来切换前后摄像头
 */
@property (nonatomic, assign) GLCameraState cameraState;
/**
 *  当前发布端的状态
 */
@property (nonatomic, assign) GLPublisherState state;
/**
 *  闪光灯状态。开启摄像头后，可通过设置该变量的值来尝试打开/关闭闪光灯
 */
@property (nonatomic, assign) BOOL torchOn;
/**
 *  摄像头的渲染视图，可以通过addView的方式将视图添加到需要渲染的位置
 */
@property (nonatomic, strong, readonly) UIView * previewView;
/**
 *  话筒状态
 */
@property (nonatomic, assign) BOOL mute;
/**
 *  默认情况下是640*480。这个值的修改，需要到下一次重新直播才会生效
 */
@property (nonatomic, assign) CGSize videoSize;
/**
 *  视频录制的帧率
 */
@property (nonatomic, readonly, assign) int fps;
/**
 *  视频录制的比特率
 */
@property (nonatomic, readonly, assign) int bitrate;

@end
