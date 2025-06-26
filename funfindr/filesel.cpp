#include "filesel.h"
#include <windows.h>
#include <iostream>

std::string filesel::sel()
{
    OPENFILENAME ofn;
    char *FilterSpec ="\0*.*";
    char *Title ="Open....";
    char szFileName[MAX_PATH];
    char szFileTitle[MAX_PATH];

    *szFileName = 0; *szFileTitle = 0;

    /* fill in non-variant fields of OPENFILENAME struct. */
    ofn.lStructSize       = sizeof(OPENFILENAME);
    ofn.hwndOwner         = GetFocus();
    ofn.lpstrFilter       = FilterSpec;
    ofn.lpstrCustomFilter = NULL;
    ofn.nMaxCustFilter    = 0;
    ofn.nFilterIndex      = 0;
    ofn.lpstrFile         = szFileName;
    ofn.nMaxFile          = MAX_PATH;
    ofn.lpstrInitialDir   = "."; // Initial directory.
    ofn.lpstrFileTitle    = szFileTitle;
    ofn.nMaxFileTitle     = MAX_PATH;
    ofn.lpstrTitle        = Title;
    ofn.lpstrDefExt   = 0;//I've set to null for demonstration

    ofn.Flags             = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;

    if (!GetOpenFileName ((LPOPENFILENAME)&ofn))
    {
        return ("NULL"); // Failed or cancelled
    }
    else
    {
      return szFileName;
    }
}
