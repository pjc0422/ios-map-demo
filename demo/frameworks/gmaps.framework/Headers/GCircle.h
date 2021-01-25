/*
 * Copyright (c) 2014 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */
#import <UIKit/UIKit.h>

#import "GOverlay.h"
@protocol GCoord;


@interface GCircle : GOverlay
/**
 *  선의 두께. 지정하지 않을 경우 기본값은 1.
 * @note throw NSInvalidArgumentException: `strokeWidth`가 0 이하일 경우
 */
@property (nonatomic, assign) int strokeWidth;

/**
 *  선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *strokeColor;

/**
 *  선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *fillColor;


/**
 원의 중심점 좌표
 */
@property (nonatomic) id<GCoord> origin;


/**
 원의 반경(m)
 */
@property (nonatomic) int radius;

/**
 원의 중심점과 반지름을 이용하여 GCircle 객체를 생성한다.
 
     GCircle *circle = [GCircle circleWithOrigin:[[GUtmk alloc]initWithX:955640.0 y:1940258.0] Radius:1000];
     circle.fillColor = [UIColor colorWithRed:0.0 green:0.0 blue:1.0 alpha:0.1];
     circle.strokeColor = [UIColor blueColor];
     circle.strokeWidth = 1;
     [mapView addOverlay: circle];

 @param origin 원의 중심점 좌표
 @param radius 원의 반경(m)
 @return `GCircle`
 @note throw NSInvalidArgumentException: radius가 0 이하일 경우
 */
+ (instancetype)circleWithOrigin:(id<GCoord>)origin Radius:(int)radius;

/**
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * strokeWidth      |   (int)
 * strokeColor      |   (NSString *UIColor *)
 * fillColor        |   (NSString *UIColor *)
 * origin           |   (id<GCoord>)
 * radius           |   (int)
 */

/**
 생성옵션을 이용한 `GPolygon` 생성자
 
     GUtmk *origin = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
     GUtmk *origin = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
     UIColor *fillColor = [UIColor colorWithRed:0.0 green:0.0 blue:1.0 alpha:0.1]
     NSDictionary *options = @{@"origin": origin, @"fillColor": fillColor, @"strokeColor": [UIColor blueColor]};
     GCircle *circle = [GCircle circleWithOptions:options];
     [mapView addOverlay:circle];

 @param options `GPolygon` 생성 옵션
 @return `GCircle`
 */
+ (instancetype)circleWithOptions:(NSDictionary *)options;
@end
