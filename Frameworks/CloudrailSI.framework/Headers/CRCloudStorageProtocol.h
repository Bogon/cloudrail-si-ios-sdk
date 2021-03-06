//
//  CloudStorage.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 11/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRCloudMetaData.h"
#import "CRAuthenticatingProtocol.h"
#import "CRPersistableProtocol.h"
#import "CRSpaceAllocation.h"

/**
 * A common interface for cloud storage services, abstracts to the level of paths consistently for all services.
 */
@protocol CRCloudStorageProtocol <CRAuthenticatingProtocol,CRPersistableProtocol>

/**
 *  Basic contructor method for any CRCloudStorageProtocol conforming class
 *
 *  @param clientId     The client identifier (or key) of the corresponding service.
 *  @param clientSecret The client secret (or secret) of the corresponding service.
 *  @param redirectUri  The redirect url used to capture the response from the service.
 *  @param state        Value used to identify diferent states on the server side. Unused in iOS version of CloudRail SDK
 *
 *  @return instancetype  id<CRCloudStorageProtocol> Initialized instance of a CRCloudStorage service using the values from the parameters.
 */
-(nonnull instancetype)initWithClientId:(nonnull NSString *)clientId
                           clientSecret:(nonnull NSString *)clientSecret
                            redirectUri:(nonnull NSString *)redirectUri
                                  state:(nonnull NSString *)state;
/**
 *  Downloads a file from a cloud storage
 * @param filePath The path to the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @return A stream from which the file can be read
 */
-(nonnull NSInputStream *)downloadFileWithPath:(nonnull NSString *)filePath;

/**
 *  Uploads a file to a cloud storage
 * @param filePath The path where to store the file from the root folder and including the name, e.g /myFolder/myFile.jpg
 * @param stream A stream from which the file can bwe read
 * @param size The size in bytes of the data that can be read from the stream
 */
-(void) uploadFileToPath:(nonnull NSString *)filePath
              withStream:(nonnull NSInputStream *)stream
                    size:(long)size
               overwrite:(BOOL)overwrite;
/**
 *  Moves a file in the cloud storage
 * @param sourcePath The path to the file which should be moved from the root folder and including the name
 * @param destinationPath The path to move the file to from the root folder and including the name
 */
-(void)moveFileFromPath:(nonnull NSString *)sourcePath
      toDestinationPath:(nonnull NSString *)destinationPath;

/**
 *  Deletes a file from the cloud storage
 * @param filePath The path to the file to be deleted from the root folder and including the name
 */
-(void)deleteFileWithPath:(nonnull NSString *)filePath;

/**
 *  Copies a file from one path in the cloud storage to another
 * @param sourcePath The path of the origin file from the root folder and including the name
 * @param destinationPath The path of the destination file from the root folder and including the name
 */
-(void)copyFileFromPath:(nonnull NSString *)sourcePath
      toDestinationPath:(nonnull NSString *)destinationPath;

/**
 *  Creates a folder at the given path
 * @param folderPath The path to the folder from the root folder and including the name, e.g. /myNewFolder
 */
-(void)createFolderWithPath:(nonnull NSString*)folderPath;

/**
 *  Gets metadata about the file/folder
 * @param filePath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
-(nonnull CRCloudMetaData *)metadataOfFileWithPath:(nonnull NSString *)filePath;

/**
 *  Gets the metadata of this folder's children
 * @param folderPath The path to the file from the root folder and including the name
 * @return A container for metadata
 */
-(nonnull NSMutableArray<CRCloudMetaData *> *)childrenOfFolderWithPath:(nonnull NSString *)folderPath;

/**
 * Creates a share link and the permission is only to 'view' and download the file/folder
 *
 * @param path the path to the file/folder which the link to will be created
 * @return The url as a String
 */
-(nonnull NSString *) shareLinkForFileWithPath:(nonnull NSString *) path;

/**
 *
 * @return The total space in bytes and the used space
 */
-(nonnull CRSpaceAllocation *) spaceAllocation;
@end
