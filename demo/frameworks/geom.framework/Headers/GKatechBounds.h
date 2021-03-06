//
//  GKatechBounds.h
//  geom
//
//  Created by gisdev on 2015. 4. 1..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import "GBounds.h"

@class GKatech;

@interface GKatechBounds : NSObject<GBounds>

#ifdef ONLY_FOR_DOXYGEN
/**
 @breif GKatechBounds 를 정의하는 좌측하단좌표
 */
@property GKatech *min;

/**
 @breif GKatechBounds 를 정의하는 우측상단좌표
 */
@property GKatech *max;
#endif

/**
  주어진 좌표로 객체를 초기화 한다.
 
 @param min Bounds를 구성하는 좌측하단 좌표
 @param max Bounds를 구성하는 우측상단 좌표
 @return GKatechBounds 객체
 */
- (instancetype)initWithMin:(GKatech *)min max:(GKatech *)max;
- (GKatech *)getMin;
- (GKatech *)getMax;

/**
  Bounds 의 좌측하단 x 좌표를 반환한다.
 
 @return 좌측하단 x 좌표
 */
- (double)left;

/**
  Bounds 의 우측상단 x 좌표를 반환한다.
 
 @return 우측상단 x 좌표
 */
- (double)right;

/**
  Bounds 의 좌측하단 y 좌표를 반환한다.
 
 @retrun 좌측하단 y 좌표
 */
- (double)bottom;

/**
  Bounds 의 우측상단 y 좌표를 반환한다.
 
 @return 우측상단 y 좌표
 */
- (double)top;

/**
  Bounds 의 너비를 반환한다.
 
 @return 너비, 미터단위
 */
- (double)width;

/**
  Bounds 의 높이를 반환하다.
 
 @return 높이, 미터단위
 */
- (double)height;

/**
  Bounds 의 중심좌표를 반환한다.
 
 @return 중심점
 */
- (GKatech *)center;

/**
  다른 bounds 와 겹치는지 여부를 판단한다.
 
 @param bounds 다른 bounds
 @return 겹치는 경우 YES, 겹치지 않는 경우 NO
 */
- (BOOL)intersectsBounds:(id<GBounds>)bounds;

/**
  현재 bounds 가 좌표를 포함하는지 여부를 판단한다.
 
 @param coord 좌표
 @return 현재 Bounds 가 좌표를 포함하면 YES, 포함하지 않으면 NO
 */
- (BOOL)containsCoord:(id<GCoord>)coord;

/**
  현재 Bounds 가 다른 bounds 를 포함하는지 여부를 판단한다.
 
 @param bounds bounds
 @return 다른 bounds 를 포함하면 YES, 포함하지 않으면 NO
 */
- (BOOL)containsBounds:(id<GBounds>)bounds;

/**
  현재 Bounds 영역이 다른 bounds 영역과 겹치는 영역을 반환한다.
 
 @param bounds bounds
 @return 겹치는 영역. 겹치는 영역이 없으면 nil 을 반환한다.
 */
- (GKatechBounds *)intersectionWithBounds:(id<GBounds>)bounds;

/**
  현재 Bounds 영역과 다른 bounds 영역을 모두 포함하는 bounds 를 반환한다.
 현재 Bounds 영역이 다른 bounds 영역을 완전히 포함하는 경우 현재 Bounds 객체를 그대로 반환한다.
 
 @param bounds bounds
 @return 두 bounds 를 모두 포함하는 영역
 */
- (GKatechBounds *)unionWithBounds:(id<GBounds>)bounds;

/**
  현재 Bounds 영역에서 width,height 만큼 확장된 bounds 를 반환한다.
 
 @param width 가로길이, 미터단위
 @param height 가로길이, 미터단위
 @return 확장된 bounds
 */
- (GKatechBounds *)expandWithWidth:(double)width height:(double)height;

/**
  bounds 로 부터 UTMK 좌표계로 이루어진 GKatechBounds 객체를 생성한다. 만일 bounds 객체의 클래스가 GKatechBounds 이면 bounds 객체를 그대로 반환한다.
 
 @param bounds GBounds 객체
 @return GKatechBounds 객체
 */
+ (GKatechBounds *)valueOf:(id<GBounds>) bounds;


@end
