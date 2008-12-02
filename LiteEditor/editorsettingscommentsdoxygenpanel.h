#ifndef __editorsettingscommentsdoxygenpanel__
#define __editorsettingscommentsdoxygenpanel__

/**
@file
Subclass of EditorSettingsCommentsDoxygenPanelBase, which is generated by wxFormBuilder.
*/

#include "editorsettingscommentsdoxygenpanelbase.h"
#include "treebooknodebase.h"

/** Implementing EditorSettingsCommentsDoxygenPanelBase */
class EditorSettingsCommentsDoxygenPanel
: public EditorSettingsCommentsDoxygenPanelBase
, public TreeBookNode<EditorSettingsCommentsDoxygenPanel>
{
	void DoSetPrefix();
	void OnUseAtPrefix(wxCommandEvent& event);
public:
	/** Constructor */
	EditorSettingsCommentsDoxygenPanel( wxWindow* parent );
	void Save(OptionsConfigPtr options);
};

#endif // __editorsettingscommentsdoxygenpanel__
