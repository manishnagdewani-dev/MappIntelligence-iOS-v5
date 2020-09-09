//
//  Webrekk.h
//  Webrekk
//
//  Created by Stefan Stevanovic on 1/3/20.
//  Copyright © 2020 Mapp Digital US, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PageViewEvent.h"

@class MappIntelligence;

typedef NS_ENUM(NSInteger, logLevel) {
  all = 1,     // All logs of the above.
  debug = 2,   // The lowest priority that you would normally log, and purely
               // informational in nature.
  warning = 3, // Something is missing and might fail if not corrected
  error = 4,   // Something has failed.
  fault = 5,   // A failure in a key system.
  info = 6, // Informational logs for updating configuration or migrating from
            // older versions of the library.
  none = 7  // None of the logs.
};

@interface MappIntelligence : NSObject {
}

@property (nonatomic, readwrite) NSTimeInterval requestTimeout;
@property (nonatomic, readwrite) logLevel logLevel;
@property (nonatomic, readwrite) BOOL batchSupportEnabled;
@property (nonatomic, readwrite) NSInteger batchSupportSize;
/**
 MappIntelignece instance
 @brief Method to get a singleton instance of MappIntelligence
 <pre><code>
 let mappInteligenceSingleton = MappIntelligence.shared()
 </code></pre>
 @return MappIntelligence an Instance Type of MappIntelligence.
 */
+ (nullable instancetype)shared;
+ (NSString *_Nonnull)version;
+ (NSString *_Nonnull)getUrl;
+ (NSString *_Nonnull)getId;

#if !TARGET_OS_WATCH
/**
@brief Method to collect the name of the current UIViewController and use it as page name in Mapp Intelligence
<pre><code>
MappIntelligence.shared()?.trackPage(self)
</code></pre>
@return Error in case of a failure. Returns nil if no error was detected.
*/
- (NSError *_Nullable)trackPage:(UIViewController *_Nullable)controller;
#endif
/**
@brief Method to specify a custom page name for the analyses in Mapp Intelligence.
@param name - String value of the page name.
<pre><code>
MappIntelligence.shared()?.trackPageWith("testString")
</code></pre>
@return Error that can happen while tracking. Returns nil if no error was detected.
*/
- (NSError *_Nullable)trackPageWith:(NSString *_Nullable)name;
/**
@brief Method to track additional page information.
@param event - page event which can contain details, groups and seach term.
<pre><code>
MappIntelligence.shared()?.trackPage(with: PageViewEvent(PageProperties([20: ["cp20Override", "cp21Override", "cp22Override"]], andWithGroup: [10: ["test"]], andWithSearch: "testSearchTerm")))
</code></pre>
@return Error that can happen while tracking. Returns nil if no error was detected.
*/
- (NSError *_Nullable)trackPageWithEvent:(PageViewEvent  *_Nullable)event;

/**
@brief Method to initialize tracking. Please specify your track domain and trackID.
@param trackIDs - Array of your trackIDs. The information can be provided by your account manager.
@param trackDomain - String value of your track domain. The information can be provided by your account manager.
<pre><code>
MappIntelligence.shared()?.initWithConfiguration([12345678, 8783291721], onTrackdomain: "www.mappIntelligence-trackDomain.com")
</code></pre>
*/
- (void)initWithConfiguration:(NSArray *_Nonnull)trackIDs
                    onTrackdomain:(NSString *_Nonnull)trackDomain;
/**
@brief Method to reset the MappIntelligence singleton. This method will set the default empty values for trackID and track domain. Please ensure to provide new trackIDs and track domain.
<pre><code>
MappIntelligence.shared()?.reset()
</code></pre>
*/
- (void)reset;
/**
@brief Method to opt-out of tracking. In case of opt-out, no data will be sent to Mapp Intelligence anymore.
@param status - opt-out if true, false enables tracking.
@param value - If set to true, all track requests currently stored in the database will be sent to MappIntelligence. If set to false, opt-out of tracking will be executed immediately and remaining data in the database will be lost.
<pre><code>
MappIntelligence.shared()?.optOut(with: false, andSendCurrentData: false)
</code></pre>
 */
- (void)optOutWith:(BOOL) status andSendCurrentData:(BOOL) value;

//testable methods
- (void) printAllRequestFromDatabase;
- (void) removeRequestFromDatabaseWithID: (int)ID;

@end
