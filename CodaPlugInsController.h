//
//  CodaPluginsController.h
//  
//
//  Updated by Evadne Wu at Iridia Productions, 2010
//  
//  Original by Gus Mueller at Flying Meat Software
//  http://code.google.com/p/flycode/source/browse/trunk/JSCocoaCodaLoader/CodaPlugInsController.h
//
//  Consult Panic’s canonical documentation while in doubt
//  http://www.panic.com/coda/developer/howto/plugins.php





#import <Cocoa/Cocoa.h>










# pragma mark Initializing the Plugin

@class CodaPlugInsController;
@protocol MNCodaPluginInitializing

	//	A principal class of the bundle will be created, and sent the initWithPlugInController:bundle: message on Coda launch.

	- (id) initWithPlugInController:(CodaPlugInsController *)aController bundle:(NSBundle *)yourBundle;
	- (NSString *) name;

@end










# pragma mark -
# pragma mark Coda Plugins Controller

@class CodaTextView;
@interface CodaPlugInsController : NSObject  {

	NSMutableArray *plugins;
	NSMutableDictionary *loadedMenuItemsDict;

}


	# pragma mark Versions

	- (NSString *) apiVersion;
	- (NSString *) codaVersion:(id)sender;


	# pragma mark Registering Menu Item(s)

	- (void) registerActionWithTitle:(NSString *)title target:(id)target selector:(SEL)selector;
	- (void) registerActionWithTitle:(NSString *)title underSubmenuWithTitle:(NSString *)submenuTitle target:(id)target selector:(SEL)selector representedObject:(id)repOb keyEquivalent:(NSString *)keyEquivalent pluginName:(NSString *)aName;


	# pragma mark Text, Responding to the User & Text Manipulation

	- (CodaTextView *) focusedTextView:(id)sender;
	- (CodaTextView *) makeUntitledDocument;
	- (void) displayHTMLString:(NSString *)html;

	
	# pragma mark File Operation

	- (void) saveAll;

@end










# pragma mark -
# pragma mark Coda Text View

@class StudioPlainTextEditor;
@interface CodaTextView : NSObject {

	StudioPlainTextEditor *editor;

}


	# pragma mark Introspection
	
	- (NSStringEncoding) encoding;
	- (NSString *) lineEnding;
	- (int) tabWidth;
	- (BOOL) usesTabs;
	
	- (unsigned int) startOfLine;
	- (NSString *) currentLine;
	- (unsigned int) currentLineNumber;
	- (NSRange) rangeOfCurrentLine;

	- (NSRange) currentWordRange;
	- (NSRange) previousWordRange;
	
	- (NSString *) string;
	- (NSString *) stringWithRange:(NSRange)range;
	
	
	# pragma mark Text Manipulation
	
	- (void) insertText:(NSString *)inText;
	- (void) replaceCharactersInRange:(NSRange)aRange withString:(NSString *)aString;
	
	
	# pragma mark Selection Manipulation
	
	- (NSRange) selectedRange;
	- (void) setSelectedRange:(NSRange)range;
	- (NSString *) selectedText;
	- (void) deleteSelection;
	
	
	# pragma mark Undo & Redo

	- (void) beginUndoGrouping;
	- (void) endUndoGrouping;
	
	
	# pragma mark Associated File
	
	- (NSString *) path;
	- (void) save;
	- (BOOL) saveToPath:(NSString *)aPath;
	
	
	# pragma mark Site
	
	- (NSString *) siteLocalPath;
	- (NSString *) siteRemotePath;
	- (NSString *) siteLocalURL;
	- (NSString *) siteURL;
	- (NSString *) siteNickname;
	
	
	# pragma mark Misc
	
	- (NSWindow *) window;


@end









