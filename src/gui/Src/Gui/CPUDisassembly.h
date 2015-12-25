#ifndef CPUDISASSEMBLY_H
#define CPUDISASSEMBLY_H

#include "Disassembly.h"
#include "GotoDialog.h"
#include "SourceViewerManager.h"

// Needed forward declaration for parent container class
class CPUWidget;

class CPUDisassembly : public Disassembly
{
    Q_OBJECT

public:
    explicit CPUDisassembly(CPUWidget* parent);

    // Mouse management
    void contextMenuEvent(QContextMenuEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

    // Context menu management
    void setupRightClickContextMenu();
    void addFollowReferenceMenuItem(QString name, dsint value, QMenu* menu, bool isReferences);
    void setupFollowReferenceMenu(dsint wVA, QMenu* menu, bool isReferences);
    void setHwBpAt(duint va, int slot);

    void copySelectionSlot(bool copyBytes);

signals:
    void displayReferencesWidget();
    void displaySourceManagerWidget();
    void showPatches();
    void decompileAt(dsint start, dsint end);
    void displaySnowmanWidget();

public slots:
    void toggleInt3BPActionSlot();
    void toggleHwBpActionSlot();
    void setHwBpOnSlot0ActionSlot();
    void setHwBpOnSlot1ActionSlot();
    void setHwBpOnSlot2ActionSlot();
    void setHwBpOnSlot3ActionSlot();
    void setNewOriginHereActionSlot();
    void gotoOriginSlot();
    void setLabelSlot();
    void setLabelAddressSlot();
    void setCommentSlot();
    void setBookmarkSlot();
    void toggleFunctionSlot();
    void assembleSlot();
    void gotoExpressionSlot();
    void gotoFileOffsetSlot();
    void gotoStartSlot();
    void gotoEndSlot();
    void followActionSlot();
    void gotoPreviousSlot();
    void gotoNextSlot();
    void findReferencesSlot();
    void findConstantSlot();
    void findStringsSlot();
    void findCallsSlot();
    void findPatternSlot();
    void selectionGetSlot(SELECTIONDATA* selection);
    void selectionSetSlot(const SELECTIONDATA* selection);
    void enableHighlightingModeSlot();
    void binaryEditSlot();
    void binaryFillSlot();
    void binaryFillNopsSlot();
    void binaryCopySlot();
    void binaryPasteSlot();
    void binaryPasteIgnoreSizeSlot();
    void undoSelectionSlot();
    void showPatchesSlot();
    void yaraSlot();
    void copySelectionSlot();
    void copySelectionNoBytesSlot();
    void copyAddressSlot();
    void copyRvaSlot();
    void copyDisassemblySlot();
    void findCommandSlot();
    void openSourceSlot();
    void decompileSelectionSlot();
    void decompileFunctionSlot();
    void displayWarningSlot(QString title, QString text);

protected:
    void paintEvent(QPaintEvent* event);

private:
    // Menus
    QMenu* mHwSlotSelectMenu;
    QMenu* mPluginMenu;

    // Actions
    QAction* mReferenceSelectedAddressAction;
    QAction* mFindCommandRegion;
    QAction* mFindConstantRegion;
    QAction* mFindStringsRegion;
    QAction* mFindCallsRegion;

    QAction* mFindCommandModule;
    QAction* mFindConstantModule;
    QAction* mFindStringsModule;
    QAction* mFindCallsModule;

    QAction* mFindCommandAll;
    QAction* mFindConstantAll;
    QAction* mFindStringsAll;
    QAction* mFindCallsAll;


    // Goto dialog specific
    GotoDialog* mGoto;

    // Parent CPU window
    CPUWidget* mParentCPUWindow;

    MenuBuilder* mMenuBuilder;

};

#endif // CPUDISASSEMBLY_H
