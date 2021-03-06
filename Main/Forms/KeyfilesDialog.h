/*
 Copyright (c) 2008 nemesis Developers Association. All rights reserved.

 Governed by the nemesis License 3.0 the full text of which is contained in
 the file License.txt included in nemesis binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Main_Forms_KeyfilesDialog
#define TC_HEADER_Main_Forms_KeyfilesDialog

#include "Forms.h"
#include "Main/Main.h"
#include "KeyfilesPanel.h"

namespace nemesis
{
	class KeyfilesDialog : public KeyfilesDialogBase
	{
	public:
		KeyfilesDialog (wxWindow* parent, shared_ptr <KeyfileList> keyfiles);
		shared_ptr <KeyfileList> GetKeyfiles () const { return mKeyfilesPanel->GetKeyfiles(); }

	protected:
		void OnCreateKeyfileButttonClick (wxCommandEvent& event);
		void OnKeyfilesHyperlinkClick (wxHyperlinkEvent& event);

		shared_ptr <KeyfileList> Keyfiles;
		KeyfilesPanel *mKeyfilesPanel;
	};
}

#endif // TC_HEADER_Main_Forms_KeyfilesDialog
