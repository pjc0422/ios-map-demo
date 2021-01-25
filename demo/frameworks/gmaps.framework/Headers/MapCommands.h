//
//  MapCommands.h
//  OllehMapSDK
//
//  Created by ik on 2015. 1. 2..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "GViewpointChange.h"
#import <geom/geom.h>

@interface PivotCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) CGPoint pivot;

+ (instancetype)pivot:(CGPoint)pivot;

@end



@interface ZoomByCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float delta;

+ (instancetype)delta:(float)delta;

@end

@interface ZoomToCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float zoom;

+ (instancetype)zoom:(float)zoom;

@end

@interface RotateByCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float delta;

+ (instancetype)delta:(float)delta;

@end

@interface RotateToCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float rotation;

+ (instancetype)rotation:(float)rotation;

@end

@interface TiltByCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float delta;

+ (instancetype)delta:(float)delta;

@end

@interface TiltToCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) float tilt;

+ (instancetype)tilt:(float)tilt;

@end

@interface PanByCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) double dx;
@property (nonatomic) double dy;

+ (instancetype)x:(double)dx y:(double)dy;

@end

@interface PanToCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) id<GCoord> center;

+ (instancetype)center:(id<GCoord>)center;

@end

@interface FitBoundsCommand : NSObject <GViewpointChangeCommand>

@property (nonatomic) id<GBounds> bounds;
@property (nonatomic) int padding;

+ (instancetype)bounds:(id<GBounds>)bounds padding:(int)padding;

@end;