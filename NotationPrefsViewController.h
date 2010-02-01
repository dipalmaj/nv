//
//  NotationPrefsViewController.h
//  Notation
//
//  Created by Zachary Schneirov on 4/1/06.
//  Copyright 2006 Zachary Schneirov. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class NotationPrefs;
@class PassphrasePicker;
@class PassphraseChanger;
@class SyncResponseFetcher;

@interface FileKindListView : NSTableView {
    IBOutlet NSPopUpButton *storageFormatPopupButton;
}
@end

@interface NotationPrefsViewController : NSObject {
    IBOutlet NSTableView *allowedExtensionsTable;
    IBOutlet NSTableView *allowedTypesTable;
	IBOutlet NSButton *enableEncryptionButton;
    IBOutlet NSButton *changePasswordButton;
    IBOutlet NSStepper *keyLengthStepper;
    IBOutlet NSTextField *keyLengthField, *fileAttributesHelpText;
    IBOutlet NSButton *newExtensionButton;
    IBOutlet NSButton *newTypeButton;
    IBOutlet NSTextField *syncAccountField;
    IBOutlet NSTextField *syncPasswordField;
    IBOutlet NSButton *removeExtensionButton;
    IBOutlet NSButton *removeTypeButton;
    IBOutlet NSButton *confirmFileDeletionButton;
	IBOutlet NSButton *secureTextEntryButton;
	IBOutlet NSButton *removeFromKeychainButton;
    IBOutlet NSPopUpButton *storageFormatPopupButton;
    IBOutlet NSMatrix *passwordSettingsMatrix;
    IBOutlet NSWindow *webOptionsWindow;
	IBOutlet NSButton *enabledSyncButton;
	IBOutlet NSImageView *verifyStatusImageView;
	IBOutlet NSTextField *verifyStatusField;
	IBOutlet NSPopUpButton *syncingFrequency;
	IBOutlet NSImageView *syncEncAlertView;
	IBOutlet NSTextField *syncEncAlertField;
    
    IBOutlet NSView *view;

	BOOL didAwakeFromNib;
    
	NSInvocation *postStorageFormatInvocation;
	int notesStorageFormatInProgress;
    NotationPrefs *notationPrefs;
	
	PassphrasePicker *picker;
	PassphraseChanger *changer;

	BOOL verificationAttempted;
	SyncResponseFetcher *loginVerifier;
	
	NSString *disableEncryptionString, *enableEncryptionString;
}

- (NSView*)view;
- (void)setSyncControlsState:(BOOL)syncState;
- (void)setEncryptionControlsState:(BOOL)encryptionState;
- (void)setSeparateFileControlsState:(BOOL)separateFileControlsState;
- (void)initializeControls;

- (IBAction)addedExtension:(id)sender;
- (IBAction)addedType:(id)sender;
- (IBAction)changedKeyLength:(id)sender;
- (IBAction)changedKeychainSettings:(id)sender;
- (IBAction)changedFileDeletionWarningSettings:(id)sender;
- (IBAction)changedFileStorageFormat:(id)sender;
- (IBAction)changePassphrase:(id)sender;
- (IBAction)changedSecureTextEntry:(id)sender;
- (IBAction)removeFromKeychain:(id)sender;
- (void)updateRemoveKeychainItemStatus;
- (void)notesStorageFormatDidChange;
- (int)notesStorageFormatInProgress;
- (void)runQueuedStorageFormatChangeInvocation;
- (IBAction)visitSimplenoteSite:(id)sender;
- (IBAction)removedExtension:(id)sender;
- (IBAction)removedType:(id)sender;

- (IBAction)toggledSyncing:(id)sender;
- (IBAction)syncFrequencyChange:(id)sender;

- (void)startVerifyingAfterDelay;
- (void)startLoginVerifier;
- (void)cancelLoginVerifier;
- (void)setVerificationStatus:(int)status withString:(NSString*)aString;

- (void)encryptionFormatMismatchSheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode 
								contextInfo:(void *)contextInfo;
- (IBAction)toggledEncryption:(id)sender;
- (void)enableEncryption;
- (void)_disableEncryption;
- (void)disableEncryptionWithWarning:(BOOL)warning;
@end
