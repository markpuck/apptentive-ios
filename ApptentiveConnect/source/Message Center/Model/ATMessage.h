//
//  ATMessage.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 10/6/12.
//  Copyright (c) 2012 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "ATJSONModel.h"

typedef enum {
	ATPendingMessageStateComposing,
	ATPendingMessageStateSending,
	ATPendingMessageStateConfirmed
} ATPendingMessageState;

@class ATMessageDisplayType, ATMessageSender;

@interface ATMessage : NSManagedObject <ATJSONModel>

@property (nonatomic, retain) NSString *apptentiveID;
@property (nonatomic, retain) NSNumber *clientCreationTime;
@property (nonatomic, retain) NSString *clientCreationTimezone;
@property (nonatomic, retain) NSNumber *clientCreationUTCOffset;
@property (nonatomic, retain) NSNumber *creationTime;
@property (nonatomic, retain) NSString *pendingMessageID;
@property (nonatomic, retain) NSNumber *pendingState;
@property (nonatomic, retain) NSNumber *priority;
@property (nonatomic, retain) NSNumber *seenByUser;
@property (nonatomic, retain) NSNumber *sentByUser;
@property (nonatomic, retain) ATMessageSender *sender;
@property (nonatomic, retain) NSSet *displayTypes;

+ (ATMessage *)findMessageWithID:(NSString *)apptentiveID;
+ (ATMessage *)findMessageWithPendingID:(NSString *)pendingID;
+ (NSTimeInterval)timeIntervalForServerTime:(NSNumber *)timestamp;
+ (NSNumber *)serverFormatForTimeInterval:(NSTimeInterval)timestamp;

- (void)setup;
- (void)updateClientCreationTime;
@end

@interface ATMessage (CoreDataGeneratedAccessors)

- (void)addDisplayTypesObject:(ATMessageDisplayType *)value;
- (void)removeDisplayTypesObject:(ATMessageDisplayType *)value;
- (void)addDisplayTypes:(NSSet *)values;
- (void)removeDisplayTypes:(NSSet *)values;

@end