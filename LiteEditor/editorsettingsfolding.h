#ifndef __editorsettingsfolding__
#define __editorsettingsfolding__

/**
@file
Subclass of EditorSettingsFoldingBase, which is generated by wxFormBuilder.
*/

#include "editorsettingsfoldingbase.h"
#include "treebooknodebase.h"

/** Implementing EditorSettingsFoldingBase */
class EditorSettingsFolding
: public EditorSettingsFoldingBase
, public TreeBookNode<EditorSettingsFolding>
{
public:
	/** Constructor */
	EditorSettingsFolding( wxWindow* parent );
	void Save(OptionsConfigPtr options);
};

#endif // __editorsettingsfolding__
