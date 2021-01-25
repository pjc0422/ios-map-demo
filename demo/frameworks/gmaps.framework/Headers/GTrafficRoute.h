//
//  GTrafficRoute.h
//  gmaps
//
//  Created by KT on 2020/02/17.
//  Copyright © 2020 kt. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "GOverlay.h"
#import "GImage.h"
#import "GTrafficLink.h"
@protocol GCoord;


//0=정보없음, 1=원활, 2=서행, 3=지체, 4=정체
typedef NS_ENUM (NSUInteger, GTrafficColorMode) {
    GTrafficPath = 1,
    GNormalPath,
    GDisabledPath,
};

@interface GTrafficRoute : GOverlay


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
// remove
//@property (nonatomic, assign) UIColor *fillColor;
/**
 *  중단점 이후의 선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *passedStrokeColor;

/**
 *  중단점 이후의 면의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *passedFillColor;

/**
 *  선의 끝점에 화살표 추가 여부. 기본값은 false.
 */
@property (nonatomic, assign) bool hasArrow;

/**
 *  선 위에 주기적인 이미지 표출 여부. 기본값은 false.
 */
@property (nonatomic, assign) bool hasPeriodicImage;

/**
 *  주기적인 이미지 표출 간격. m단위이며 기본값은 100m.
 */
@property (nonatomic, assign) int period;
/**
 *  중단점. 지도좌표 기준
 */
@property (nonatomic) id<GCoord> splitCoord;
/**
 *  선 위에 주기적으로 그려지는 이미지.
 */
@property (nonatomic) GImage *periodicImage;
/**
 *  선을 이루는 점의 목록. GCoord array.
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
// remove
//@property (nonatomic, copy) NSArray *points;
@property (nonatomic, copy) NSArray *links;
/**
 *  교통정보 선의 기본선
 */
@property (nonatomic) float course;

/**
 
 */
@property (nonatomic) GTrafficColorMode colorMode;
/**
 
 */
@property (nonatomic) UIColor* disabledColor;
/**
 
 */
@property (nonatomic) UIColor* normalColor;
/**
 * startIndex default = 0
 */
@property (nonatomic) NSNumber* startIndex;


- (void)setSplitCoord:(id<GCoord>)splitCoord course:(float)course;

- (void)setSplitCoord:(id<GCoord>)splitCoord course:(float)course fulldistance:(float)fulldistance driveddistance:(float)driveddistance;

-(void) setSplitCoord:(id<GCoord>)splitCoord linkIndex:(NSNumber*) index;

-(void) setLinkColorInfo:(int) linkIndex color:(UIColor*) color;

/**
 key : index    (int)
 value : color  (UIColor)
 */
-(void) setLinksColorInfo:(NSDictionary*) colorInfo;

- (void)bringToFront;
/**
 *  [bringToFront] 로 변경된 z-index 를 기본값으로 초기화한다.
 */
- (void)resetZIndex;

/**
 *  점의 목록을 이용하여 GRoute 객체를 생성한다.
 * @return 생성된 GRoute 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GRoute *route = [GRoute routeWithPoints:points BufferWidth:10];
 * [mapView addOverlay:route];
 * @endcode
 */
+ (instancetype)routeWithPoints:(NSArray *)links BufferWidth:(double)width;

/**
 *  생성옵션을 이용한 GRoute 생성자
 * @param options GRoute 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * bufferWidth      |   (double)
 * strokeWidth      |   (int)
 * strokeColor      |   (NSString *UIColor *)
 * fillColor        |   (NSString *UIColor *)
 * passedStrokeColor|   (NSString *UIColor *)
 * passedFillColor  |   (NSString *UIColor *)
 * hasArrow         |   (bool)
 * hasPeriodicImage |   (bool)
 * periodicImage    |   (GImage *)
 * period           |   (int)
 * links            |   (NSArray *)
 * @return 생성된 GRoute 객체
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
 * GRoute *route = [GRoute routeWithOptions:options];
 * [mapView addOverlay:route];
 * @endcode
 */
+ (instancetype)routeWithOptions:(NSDictionary *)options;

@end
