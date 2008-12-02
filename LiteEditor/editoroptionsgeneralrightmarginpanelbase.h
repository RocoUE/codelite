///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 21 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __editoroptionsgeneralrightmarginpanelbase__
#define __editoroptionsgeneralrightmarginpanelbase__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class EditorOptionsGeneralRightMarginPanelBase
///////////////////////////////////////////////////////////////////////////////
class EditorOptionsGeneralRightMarginPanelBase : public wxPanel
{
	private:

	protected:
		wxRadioButton* m_radioBtnRMDisabled;
		wxRadioButton* m_radioBtnRMLine;
		wxRadioButton* m_radioBtnRMBackground;
		wxStaticText* m_staticText1;
		wxSpinCtrl* m_rightMarginColumn;
		wxStaticText* m_staticText2;
		wxColourPickerCtrl* m_rightMarginColour;

		// Virtual event handlers, overide them in your derived class
		virtual void OnRightMarginIndicator( wxCommandEvent& event ){ event.Skip(); }


	public:
		EditorOptionsGeneralRightMarginPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 263,143 ), long style = wxTAB_TRAVERSAL );
		~EditorOptionsGeneralRightMarginPanelBase();

};

#endif //__editoroptionsgeneralrightmarginpanelbase__
