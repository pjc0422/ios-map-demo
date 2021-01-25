/*
 * Copyright (c) 2015 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */

#import <Foundation/Foundation.h>
//#import "GTrafficManager.h"

typedef enum
{
    PROVIDER_TYPE_B2B = 0,
    PROVIDER_TYPE_B2C,
    PROVIDER_TYPE_MAX
} PROVIDER_TYPE;

@class GTrafficManager;
@protocol GNetworkLayerDelegate;

/// data import error code constants.
static const int IMPORT_ERRORCODE_PARSE_ERROR = 4;
static const int IMPORT_ERRORCODE_DB_ERROR = 5;
static const int IMPORT_ERRORCODE_IO_ERROR = 6;

static NSString* const INFO_KEY_HOME_DIR = @"GMapHomeDir";
static NSString* session_url;
static NSString* session_token;


@protocol GImportStateDelegate <NSObject>

@required

/**
 * import 작업의 진행 정도 변경시 호출된다.
 *
 * @param handle
 *           native 객체에 대한 참조값
 * @param progress
 *           현재까지 저장된 지도 타일의 수
 * @param total
 *           전체 저장될 지도 타일의 수
 */
- (void)didUpdateProgress:(long)handle
                 progress:(int)progress
                    total:(int)total;

/**
 * import 작업 종료시 호출된다.
 *
 * @param handle
 *           native 객체에 대한 참조값
 * @param total
 *           저장된 지도 타일의 수
 *
 */
- (void)didFinish:(long)handle
            total:(int)total;

/**
 * import 작업 도중 에러 발생시 호출된다.
 *
 * @param handle
 *           native 객체에 대한 참조값
 * @param errorCode
 *           에러 코드.
 *           IMPORT_ERRORCODE_PARSE_ERROR : 타일 데이타 파싱 에러
 *           IMPORT_ERRORCODE_DB_ERROR : DB insert 실패
 *           IMPORT_ERRORCODE_DB_ERROR : 데이터파일 읽기 실패
 */
- (void)didError:(long)handle
       errorCode:(int)errorCode;

@end


@interface GMapShared : NSObject

@property (readonly, atomic) NSArray* listeners; 
@property (nonatomic) GTrafficManager* trafficManager;
@property (nonatomic) NSLock* links_lock;

+ (id)sharedInstance;

+ (NSString*)serverUrlValue;

+ (NSString*)serverUrlTmpl;

+ (NSString*)revisionInfoUrlValue;

+ (NSString*)revisionInfoUrlTmpl;

+ (int) getMapTileProtocolVersion;

/**
 * 지도타일 데이터를 저장하고 있는 database 의 revision 정보를 반환한다.
 *
 * @return revision 값.
 *
 * */
- (int)getTileDataRevision;

-(void)setTileDataRevision:(int) revision;

/**
 * 지도타일 데이터를 저장하고 있는 database 의 revision Date정보를 반환한다.
 *
 * @return revision 날짜값. ex) 20150702
 *
 * */
- (int)getTileDataRevisionDate;

/**
 * SDK 가 지원하는 지도타일 데이터 포맷의 revision 정보를 반환한다.
 *
 * @return format revision 값
 *
 * */
+ (int)getSupportedTileFormat;

/**
  지도 타일 스토리지 캐쉬 정책을 사용할지를 설정한다.
 캐쉬 정책을 사용하지 않은 경우 스토리지에서 삭제되지 않는다.
 캐쉬 정책을 사용하는 경우 내부 정책에 따라 캐쉬 제한 크기를 넘는 경우 스토리지에 저장하지 않는다.
 기본값은 캐쉬 정책을 사용으로 되어 있으며, 세부적인 캐쉬 정책에 대한 수정은 지원하지 않는다.
 
 @param enabled 타일 스토리지 캐쉬 정책 사용 여부. YES이면 사용. 그렇지 않은 경우 사용하지 않음
 */
// API 제거. cache 정책 적용 여부는 offline mode on/off 에 의해 함께 on/off 된다.
//-(void)setStorageCacheEnabled:(BOOL)enabled;

/**
 * 스트리밍 서버로 지도 data를 요청하지 않고 단말에 저장되어있는 data만을 사용하고자 하는 경우 {@code true}로 설정한다.
 * 기본값은 {@code false} 이다.
 *
 * @param 단말 data 만을 사용할 지 여부.
 *
 * */
- (void)setUseLocalDataOnly:(bool) localOnly;

/**
 * 단말 data 만 사용 설정값을 조회한다.
 * 기본값은 {@code false} 이다.
 *
 * @return 단말 data 만을 사용하도록 설정된 경우 true를 반환. Streaming 사용 시 false를 반환.
 *
 * */
- (bool)getUseLocalDataOnly;

/**
 * 지도 안티앨리어싱 적용 여부를 설정한다.
 * 기본값은 {@code true} 이다.
 *
 * @param 지도 안티앨리어싱 적용 여부.
 *
 * */
- (void)setUseAntiAliasing:(bool) antiAliasing;

/**
 * 지도 안티앨리어싱 적용 여부를 조회한다.
 * 기본값은 {@code true} 이다.
 *
 * @return 안티앨리어싱이 적용되도록 설정한 경우 true를 반환.
 *
 * */
- (bool)getUseAntiAliasing;

/**
 * 지도 타일 데이터 파일을 import 한다.
 *
 * @param filePath
 *          import 할 지도 타일 데이터파일 절대경로
 * @return native 객체의 참조값. 이 값을 cancelImport() 호출시에 전달한다.
 */
- (long)importTileData:(NSString *)filePath;

/**
 * 진행 중인 데이터 파일 import 작업을 중단한다.
 *
 * @param handle
 */
- (void)cancelImport:(long)handle;

/**
 * dataFile import 시 import 상태 변경 이벤트가 발생될 때 호출될 {@code listener} 를 추가한다.
 *
 * @param listener
 *            {@link OnImportStateChangeListener} 객체.
 *
 * */
- (void)addImportStateDeletgate:(id<GImportStateDelegate>) delegate;

/**
 * 설정된 import 상태 변경 이벤트 {@code listener}를 헤제한다.
 *
 * @param listener
 *            {@link OnImportStateChangeListener} 객체.
 * */
- (void)removeImportStateDelegate:(id<GImportStateDelegate>) delegate;

/**
 * 기존 타일 데이터 파일을 새로운 파일로 대체한다.
 * 내부적으로 file move 가 수행되므로, 이 메소드의 성공적인 실행 이후에 파라미터로 전달된 경로의 파일은 존재하지 않게 된다.
 *
 * @param filePath
 *          대체할 타일 데이터 파일의 절대 경로
 *
 * @return 대체 작업의 성공 여부. 성공인 경우 true를 반환한다.
 *
 * */
- (bool)replaceTileData:(NSString *)filePath;

/**
 * 타일 데이터를 모두 삭제한다.
 *
 * @return 삭제 작업 성공 여부. 성공인 경우 true.
 * */
- (bool)clearTileData;

- (const NSString *)getDataDirPath;

- (const NSString *)getTempDirPath;

/**
 * 타일서버 URL 을 지정한다.
 * 실제 요청 URL 은 타일서버 URL 템플릿의 첫번째 %s 를 치환한 문자열을 사용한다.
 * 타일서버 URL 템플릿의 기본값은 http://%s/%d/%d/%d/%d 이기 때문에 URL 템플릿으로 기본값을 사용할 경우
 * 타일서버 URL 은 http:// 을 제외한 값을 사용해야 한다.
 * 예. [mapShared setServerUrl:@"map.olleh.com/tile"]
 * @param serverUrl 타일서버 URL
 */
+ (void)setServerUrl:(NSString*)serverUrl;

/**
 * 타일서버 URL 템플릿을 지정한다. 기본값은 http://%s/%d/%d/%d/%d 이다.
 * @param serverUrlTmpl 타일서버 URL 템플릿
 */
+ (void)setServerUrlTmpl:(NSString*)serverUrlTmpl;

/**
 * URL 템플릿에 타일서버 URL 을 적용한 실제 요청 URL을 반환한다.
 * @return 타일서버 실제 요청 URL
 */
- (NSString*)getResolvedServerUrl;

/**
 * 리비전정보 URL 을 지정한다.
 * 실제 요청 URL 은 리비전정보 URL 템플릿의 첫번째 %s 를 치환한 문자열을 사용한다.
 * 리비전정보 URL 템플릿의 기본값은 http://%s 이기 때문에 기본값을 사용할 경우
 * http:// 를 제외한 값을 사용해야 한다.
 * @param revisionInfoUrl
 * @return 현재 MapOptions 객체
 */
+ (void)setRevisionInfoUrl:(NSString*)revisionInfoUrl;

/**
 * 리비전정보 URL 템플릿을 지정한다.
 * @param revisionInfoUrlTmpl 리비전정보 URL 템플릿
 */
+ (void)setRevisionInfoUrlTmpl:(NSString*)revisionInfoUrlTmpl;

/**
 * 리비전정보 URL 템플릿에 URL 을 적용한 실제 요청 리비전정보 URL 을 반환한다.
 * @return 실제 요청 리비전정보 URL
 */
- (NSString*)getResolvedRevisionInfoUrl;

/**
 * SDK version을 조회한다.
 * @return SDK version
 */
+ (NSString*)getSDKVersion;
/**
 * SDK의 인증 키값을 체크
 * param bundle MainBundle 인증key값을 확인 하기 위한 용도
 * @return 사용 가능여부 return
 */
+ (bool) authKeyRegist:(NSBundle *)bundle;
/**
 * SDK의 인증 키값을 체크
 * param bundle MainBundle 인증key값을 확인 하기 위한 용도
 * @return 사용 가능여부 return
 */
+(bool) authKeyRegist:(NSBundle *)bundle withKey:(NSString*) key ;
/**
 * SDK의 인증 키값을 체크
 * param bundle MainBundle 인증key값을 확인 하기 위한 용도
 * param key Key
 * param url tileInfoUrl
 * @return 사용 가능여부 return
 */
+(bool) authKeyRegist:(NSBundle *)bundle withKey:(NSString*) key withUrl:(NSString*) url withToken:(NSString*) token;

-(GTrafficManager*)getTrafficManager;
-(void)setNetworkLayerDelegate:(id<GNetworkLayerDelegate>)delegate;
+(NSString *)getSessionUrl;
+(NSString *)getSessionToken;
+(PROVIDER_TYPE)getProviderTarget;
@end
