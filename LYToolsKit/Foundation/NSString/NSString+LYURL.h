//
//  NSString+LYURL.h
//  LYToolsKit
//
//  Created by 似水灵修 on 2018/11/12.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kLYURLScheme;
extern NSString *const kLYURLHost;
extern NSString *const kLYURLPort;
extern NSString *const kLYURLParams;
extern NSString *const kLYURLQuerys;
extern NSString *const kLYURLPath;
extern NSString *const kLYURLFragment;

@interface NSString (LYURL)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
/**
 解析URL
 示例：http://host.name:8888/test/page/?keyA=valueA&keyB=valueB#top
 @param    kLYURLScheme     http
 @param    kLYURLHost          host.name
 @param    kLYURLPort          8888
 @param    kLYURLParams      {keyA: valueA, keyB: valueB}
 @param    kLYURLQuerys      [{keyA: valueA}, {keyB: valueB}]
 @param    kLYURLPath           /test/page
 @param    kLYURLFragment  top
 @return   NSDictionary
 */
- (NSDictionary *)ly_paramsFromURLString;
#pragma clang diagnostic pop

/**
 URL地址Reserved Characters与Unreserved Characters之外的字符做百分号编码。
 @code编码：
 1. UTF-8编码
 2. !*'();:@&=+$,/?%#[ ]
 */
- (instancetype)ly_stringAllAddingPercentEncoding;
/**
 处理特殊字符
 @code
 1. 编码中文、《》、（）、【】
 2. 空格替换为空字符
 */
- (instancetype)ly_stringAddingPercentEscapesChineseSpace;
/**
 根据 string构建 URL实例

 @param string URL String
 @return return URL实例
 */
+ (NSURL *)ly_URLWithString:(NSString *)string;
/** url拼接参数，跳过已经存在的参数值 */
+ (nullable instancetype)ly_stringURL:(NSString *)url appendNotExistParams:(nullable NSDictionary<NSString *, NSString *> *)params;
/** url拼接参数，覆盖已经存在的参数值 */
+ (nullable instancetype)ly_stringURL:(NSString *)url appendParams:(nullable NSDictionary<NSString *, NSString *> *)params;

@end

NS_ASSUME_NONNULL_END
