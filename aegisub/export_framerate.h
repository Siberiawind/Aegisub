// Copyright (c) 2005, Rodrigo Braz Monteiro
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// -----------------------------------------------------------------------------
//
// AEGISUB
//
// Website: http://aegisub.cellosoft.com
// Contact: mailto:zeratul@cellosoft.com
//


#pragma once


///////////
// Headers
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include "ass_export_filter.h"
#include "vfr.h"


//////////////
// Prototypes
class AssOverrideParameter;
class AssDialogue;


//////////////////////////////
// Transform Framerate filter
class AssTransformFramerateFilter : public AssExportFilter {
private:
	static AssTransformFramerateFilter instance;
	FrameRate *Input,*Output;
	FrameRate t1,t2;

	wxTextCtrl *InputFramerate;
	wxTextCtrl *OutputFramerate;
	wxRadioButton *RadioOutputCFR;
	wxRadioButton *RadioOutputVFR;

	AssTransformFramerateFilter();
	void TransformFrameRate(AssFile *subs);
	static void TransformTimeTags(wxString name,int n,AssOverrideParameter *curParam,void *_curDiag);
	void Init();

public:
	void ProcessSubs(AssFile *subs, wxWindow *export_dialog);
	wxWindow *GetConfigDialogWindow(wxWindow *parent);
	void LoadSettings(bool IsDefault);
};


//////////////////
// Linedata class
class LineData {
public:
	AssDialogue *line;
	int k;
	int kf;
	int ko;
};


///////
// IDs
enum {
	Get_Input_From_Video = 2000
};
