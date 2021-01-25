//
//  GMapLabelOption.h
//  gmaps
//
//  Created by kt on 2020/09/22.
//  Copyright © 2020 kt. All rights reserved.
//


#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, GMapLabelFocusMode) {
    NoneEffect = 0,
    MagnifactionEffect
};



@interface GMapLabelOption : NSObject

-(float) getRatio;
-(GMapLabelFocusMode) getFocusMode;

+(instancetype) initMode:(GMapLabelFocusMode) mode;
+(instancetype) initMode:(GMapLabelFocusMode) mode magnificationRatio:(NSInteger) ratio;
+(instancetype) initRatio:(NSInteger) ratio;
@end
