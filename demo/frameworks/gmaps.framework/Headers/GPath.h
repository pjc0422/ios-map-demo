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
#import "GImage.h"
@protocol GCoord;

/**
 * @class GPath
 *  GPath 는 지도상에 일정한 폭(면적)을 갖는 라인을 그리기 위한 클래스이며 2개 이상의 연속된 점들로 구성되어있다. GOverlay 구현 클래스
 */
@interface GPath : GOverlay

/**
 *  선의 두께. 지정하지 않을 경우 기본값은 1. 1 미만인 경우 NSInvalidArgumentException 발생
 */
@property (nonatomic, assign) int strokeWidth;

/**
 *  버퍼 너비(미터 단위). 0 미만인 경우 NSInvalidArgumentException 발생
 */
@property (nonatomic, assign) double bufferWidth;

/**
 *  선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *strokeColor;

/**
 *  면의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *fillColor;

/**
 *  선의 끝점에 화살표 추가 여부. 기본값은 false.
 */
@property (nonatomic, assign) bool hasArrow;

/**
 *  선의 끝점에 캡 추가 여부. 기본값은 true.
 */
@property (nonatomic, assign) bool hasLineCap;

/**
 *  선을 이루는 점의 목록. GCoord array. 
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *points;

/**
 * @breif 연결된 선의 총 길이를 구하는 함수.
 */
-(double) getLength ;

/**
 *  점의 목록을 이용하여 GPath 객체를 생성한다.
 * @return 생성된 GPath 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GPath *path = [GPath pathWithPoints:points BufferWidth:10];
 * [mapView addOverlay:path];
 * @endcode
 */
+ (instancetype)pathWithPoints:(NSArray *)points BufferWidth:(double)width;

/**
 *  생성옵션을 이용한 GPath 생성자
 * @param options GPath 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * bufferWidth      |   (int)
 * strokeWidth      |   (int)
 * strokeColor      |   (NSString *UIColor *)
 * fillColor        |   (NSString *UIColor *)
 * hasArrow         |   (bool)
 * points           |   (NSArray *)
 * @return 생성된 GPath 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우<br/>
 *                                    <code>strokeWidth</code>가 1 미만일 경우<br/>
 *                                    <code>bufferWidth</code>가 지정되지 않거나 0보다 작거나 같을 경우 exception발생<br/>
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * GUtmk *c4 = [[GUtmk alloc]initWithX:958540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, c4, nil];
 * NSDictionary *options = @{
 *                      @"strokeColor":[UIColor redColor],
 *                           @"points":points,
 *                       @"bufferWidth:@10
 *                         };
 * GPath *path = [GPath pathWithOptions:options];
 * [mapView addOverlay:path];
 * @endcode
 */
+ (instancetype)pathWithOptions:(NSDictionary *)options;


@end
