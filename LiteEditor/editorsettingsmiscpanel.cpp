#include "editorsettingsmiscpanel.h"
#include "generalinfo.h"
#include "frame.h"
#include "manager.h"
#include "pluginmanager.h"
#include "wx/wxprec.h"
#include <wx/fontmap.h>

EditorSettingsMiscPanel::EditorSettingsMiscPanel( wxWindow* parent )
: EditorSettingsMiscBasePanel( parent )
, TreeBookNode<EditorSettingsMiscPanel>()
{
	GeneralInfo info = Frame::Get()->GetFrameGeneralInfo();
	OptionsConfigPtr options = EditorConfigST::Get()->GetOptions();
	if (options->GetIconsSize() == 16) {
		m_toolbarIconSize->SetSelection(0);
	} else {
		m_toolbarIconSize->SetSelection(1);
	}

	m_useSingleToolbar->SetValue(!PluginManager::Get()->AllowToolbar());

	wxArrayString astrEncodings;
	wxFontEncoding fontEnc;
	int iCurrSelId = 0;
	size_t iEncCnt = wxFontMapper::GetSupportedEncodingsCount();
	for (size_t i = 0; i < iEncCnt; i++) {
		fontEnc = wxFontMapper::GetEncoding(i);
		if (wxFONTENCODING_SYSTEM == fontEnc) { // skip system, it is changed to UTF-8 in optionsconfig
			continue;
		}
		astrEncodings.Add(wxFontMapper::GetEncodingName(fontEnc));
		if (fontEnc == options->GetFileFontEncoding()) {
			iCurrSelId = i;
		}
	}

	m_fileEncoding->Append(astrEncodings);
	m_fileEncoding->SetSelection(iCurrSelId);

	long single_instance(1);
	EditorConfigST::Get()->GetLongValue(wxT("SingleInstance"), single_instance);
	m_singleAppInstance->SetValue(single_instance ? true : false);

	long check(1);
	EditorConfigST::Get()->GetLongValue(wxT("CheckNewVersion"), check);
	m_versionCheckOnStartup->SetValue(check ? true : false);

	check = 1;
	EditorConfigST::Get()->GetLongValue(wxT("ShowFullPathInFrameTitle"), check);
	m_fullFilePath->SetValue(check ? true : false);

	bool showSplash = info.GetFlags() & CL_SHOW_SPLASH ? true : false;
	m_showSplashScreen->SetValue(showSplash);

	long max_items(10);
	EditorConfigST::Get()->GetLongValue(wxT("MaxItemsInFindReplaceDialog"), max_items);
	m_maxItemsFindReplace->SetValue(max_items);

}

void EditorSettingsMiscPanel::OnClearButtonClick( wxCommandEvent& )
{
	ManagerST::Get()->ClearFileHistory();
}

void EditorSettingsMiscPanel::Save(OptionsConfigPtr options)
{

	if (m_showSplashScreen->IsChecked()) {
		Frame::Get()->SetFrameFlag(true, CL_SHOW_SPLASH);
	} else {
		Frame::Get()->SetFrameFlag(false, CL_SHOW_SPLASH);
	}

	EditorConfigST::Get()->SaveLongValue(wxT("SingleInstance"), m_singleAppInstance->IsChecked() ? 1 : 0);
	EditorConfigST::Get()->SaveLongValue(wxT("CheckNewVersion"), m_versionCheckOnStartup->IsChecked() ? 1 : 0);
	EditorConfigST::Get()->SaveLongValue(wxT("ShowFullPathInFrameTitle"), m_fullFilePath->IsChecked() ? 1 : 0);

	bool oldUseSingleToolbar = !PluginManager::Get()->AllowToolbar();
	EditorConfigST::Get()->SaveLongValue(wxT("UseSingleToolbar"), m_useSingleToolbar->IsChecked() ? 1 : 0);

	int value = m_maxItemsFindReplace->GetValue();
	if(value < 1 || value > 50) {
		value = 10;
	}

	EditorConfigST::Get()->SaveLongValue(wxT("MaxItemsInFindReplaceDialog"), value);


	//check to see of the icon size was modified
	int oldIconSize(24);

	OptionsConfigPtr oldOptions = EditorConfigST::Get()->GetOptions();
	if (oldOptions) {
		oldIconSize = oldOptions->GetIconsSize();
	}

	int iconSize(24);
	if (m_toolbarIconSize->GetSelection() == 0) {
		iconSize = 16;
	}
	options->SetIconsSize(iconSize);

	// save file font encoding
	options->SetFileFontEncoding(m_fileEncoding->GetStringSelection());

	if (oldIconSize != iconSize || oldUseSingleToolbar != m_useSingleToolbar->IsChecked()) {
		EditorConfigST::Get()->SaveLongValue(wxT("LoadSavedPrespective"), 0);
		//notify the user
		wxMessageBox(_("Some of the changes made requires restart of CodeLite"), wxT("CodeLite"), wxICON_INFORMATION|wxOK);
	} else {
		EditorConfigST::Get()->SaveLongValue(wxT("LoadSavedPrespective"), 1);
	}
}
