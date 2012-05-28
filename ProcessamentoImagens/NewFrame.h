#ifndef NEWFRAME_H
#define NEWFRAME_H

//(*Headers(NewFrame)
#include <wx/frame.h>
//*)

class NewFrame: public wxFrame
{
	public:

		NewFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewFrame();

		//(*Declarations(NewFrame)
		//*)

	protected:

		//(*Identifiers(NewFrame)
		//*)

	private:

		//(*Handlers(NewFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
