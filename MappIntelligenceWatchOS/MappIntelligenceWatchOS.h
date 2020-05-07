//
//  MappIntelligenceWatchOS.h
//  MappIntelligenceWatchOS
//
//  Created by Stefan Stevanovic on 3/24/20.
//  Copyright © 2020 Mapp Digital US, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, logWatchOSLevel) {
  allWatchOSLogs = 1,     // All logs of the above.
  debugWatchOSLogs = 2,   // The lowest priority that you would normally log, and purely
               // informational in nature.
  warningWatchOSLogs = 3, // Something is missing and might fail if not corrected
  errorWatchOSLogs = 4,   // Something has failed.
  faultWatchOSLogs = 5,   // A failure in a key system.
  infoWatchOSLogs = 6, // Informational logs for updating configuration or migrating from
            // older versions of the library.
  noneOfWatchOSLogs = 7  // None of the logs.
};
@interface MappIntelligenceWatchOS : NSObject

@property (nonatomic, readwrite) NSTimeInterval requestTimeout;
@property (nonatomic, readwrite) logWatchOSLevel logLevelWatchOS;
/**
 MappIntelignece instance
 @brief Method for gets a singleton instance of MappInteligence.
 <pre><code>
 MappIntelligenceWatchOS *mappIntelligenceWatchOS = [MappIntelligenceWatchOS shared];
 </code></pre>
 @return MappIntelligence an Instance Type of MappIntelligence.
 */
+ (nullable instancetype)shared;

- (void)initWithConfiguration:(NSArray *_Nonnull)trackIDs
                    onTrackdomain:(NSString *_Nonnull)trackDomain;
- (void)trackPageWith:(NSString *_Nullable)name;
- (void)reset;

@end
