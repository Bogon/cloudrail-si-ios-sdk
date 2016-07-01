//
//  PointsOfInterestProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 20/06/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRPOI.h"

/**
 * An interface that provides data about points of interest for a specified location. Results can be
 * filtered by categories or an individual search term.
 */
@protocol CRPointsOfInterestProtocol <NSObject>

/**
 * Returns a list of POIs that are close to the passed location and filters them by certain criteria.
 *
 * @param latitude   The latitude of the target location.
 * @param longitude  The longitude of the target location.
 * @param radius     The search radius in metres.
 * @param searchTerm Optional search term that has to be matched.
 * @param categories Optional list of categories. Available categories can be found in the main documentation.
 * @return A list of POIs for the target location.
 * @throws IllegalArgumentException Is thrown if latitude, longitude or radius is null, latitude or
 *                                  longitude is invalid, radius is greater than 40,000 metres or
 *                                  one of the passed categories is unknown.
 * @throws AuthenticationException  Is thrown if the passed credentials are invalid or authorization
 *                                  fails for whatever reason.
 * @throws HttpException            Is thrown if the communication with a services fails.
 *                                  More detail is provided in the error message.
 */
-(nonnull NSMutableArray<CRPOI *> *) nearbyPoisWithLatitude:(nonnull NSNumber *)latitude
                                                  longitude:(nonnull NSNumber *)longitude
                                                     radius:(nonnull NSNumber *)radius
                                                 searchTerm:(nullable NSString *)searchTerm
                                                 categories:(nullable NSMutableArray<NSString *> *)categories;

@end
