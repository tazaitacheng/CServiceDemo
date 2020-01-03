//
//  CServiceSDK.h
//  IosSdk
//
//  Created by 何健 on 11/18/19.
//  Copyright © 2019 customerservice. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CServiceSDK : NSObject

+ (BOOL)initSDK:(NSString *)pdtId;

+ (void)showFeedbackView:(UIViewController *)vc;

+ (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
