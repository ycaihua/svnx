//----------------------------------------------------------------------------------------
//	MyWorkingCopyController.h - Controller of the working copy browser
//
//	Copyright © Chris, 2007 - 2010.  All rights reserved.
//----------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

@class MyWorkingCopy, MySvnFilesArrayController, DrawerLogView, RepoItem;

/*" Controller of the working copy browser "*/
@interface MyWorkingCopyController : NSResponder
{
	IBOutlet MyWorkingCopy*				document;
	IBOutlet MySvnFilesArrayController*	svnFilesAC;

	IBOutlet id				window;
	IBOutlet id				splitView;
	IBOutlet id				progressIndicator;
	IBOutlet NSControl*		statusView;
	IBOutlet id				tableResult;
	IBOutlet id				outliner;

	IBOutlet NSControl*		modeView;
	IBOutlet NSPopUpButton*	filterView;

	IBOutlet id				commitPanel;
	IBOutlet id				commitPanelText;
	IBOutlet id				toolbar;
	IBOutlet NSDrawer*		sidebar;

	IBOutlet DrawerLogView *drawerLogView;

	IBOutlet NSPanel		*renamePanel;
	IBOutlet NSTextField	*renamePanelTextField;

	IBOutlet NSWindow*		mergeSheet;

	IBOutlet NSWindow*		switchPanel;
	IBOutlet NSTextField	*switchPanelSourceTextField;
	IBOutlet NSTextField	*switchPanelDestinationTextField;
	IBOutlet NSButton		*switchPanelRelocateButton;

	IBOutlet NSWindow*		updateSheet;
	BOOL					updateInited;

	BOOL					svnStatusPending;
	BOOL					suppressAutoRefresh;

	BOOL					isDisplayingErrorSheet;
	BOOL					outlineInited;		// has initialised outline view
	BOOL					fPrefsChanged;

	float					fTreeWidth;
	NSMutableArray*			fTreeExpanded;		// expanded paths in tree view
	NSArray*				savedSelection;		// used by save/restoreSelection
	NSMutableDictionary*	fDialogPrefs;
}

+ (void) presetDocumentName: name;

- (IBAction) changeFilter:         (id) sender;
- (IBAction) performAction:        (id) sender;
- (IBAction) revealInFinder:       (id) sender;
- (IBAction) refresh:              (id) sender;
- (IBAction) svnUpdate:            (id) sender;
- (IBAction) diffBase:             (id) sender;
- (IBAction) diffPrev:             (id) sender;
- (IBAction) diffSheet:            (id) sender;
- (IBAction) openRepository:       (id) sender;
- (IBAction) toggleSidebar:        (id) sender;
- (IBAction) changeMode:           (id) sender;
- (IBAction) renamePanelValidate:  (id) sender;
- (IBAction) switchPanelValidate:  (id) sender;
- (IBAction) commitPanelValidate:  (id) sender;
- (IBAction) commitPanelCancel:    (id) sender;
- (int)      currentMode;
- (void)     setCurrentMode: (int) mode;
- (void)     setStatusMessage: (NSString*) message;

- (void) keyDown: (NSEvent*) theEvent;
- (void) saveSelection;
- (void) restoreSelection;
- (void) selectionChanged;
- (void) calcTreeExpanded;
- (void) selectTreePath: (NSString*) treePath;

- (void) doubleClickInTableView: (id) sender;
- (void) adjustOutlineView;
- (void) openOutlineView;
- (void) closeOutlineView;
- (void) fetchSvnStatus;
- (void) fetchSvnInfo;
- (void) fetchSvnStatusVerboseReceiveDataFinished;

- (void) svnError: (NSString*) errorString;
- (void) startProgressIndicator;
- (void) stopProgressIndicator;

- (MyWorkingCopy*) document;
- (NSWindow*) window;
- (void) requestMergeFrom:              (RepoItem*) repositoryPathObj;
- (void) requestSwitchToRepositoryPath: (RepoItem*) repositoryPathObj;
- (void) requestSvnRenameSelectedItemTo:           (NSString*) destination;
- (void) requestSvnMoveSelectedItemsToDestination: (NSString*) destination;
- (void) requestSvnCopySelectedItemsToDestination: (NSString*) destination;

@end	// MyWorkingCopyController

