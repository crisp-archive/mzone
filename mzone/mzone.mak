# Microsoft Developer Studio Generated NMAKE File, Based on mzone.dsp
!IF "$(CFG)" == ""
CFG=mzone - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mzone - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mzone - Win32 Release" && "$(CFG)" != "mzone - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mzone.mak" CFG="mzone - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mzone - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mzone - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "mzone - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mzone.exe" "$(OUTDIR)\mzone.bsc"


CLEAN :
	-@erase "$(INTDIR)\Calculate.obj"
	-@erase "$(INTDIR)\Calculate.sbr"
	-@erase "$(INTDIR)\Convert.obj"
	-@erase "$(INTDIR)\Convert.sbr"
	-@erase "$(INTDIR)\Document.obj"
	-@erase "$(INTDIR)\Document.sbr"
	-@erase "$(INTDIR)\Factorial.obj"
	-@erase "$(INTDIR)\Factorial.sbr"
	-@erase "$(INTDIR)\Input.obj"
	-@erase "$(INTDIR)\Input.sbr"
	-@erase "$(INTDIR)\Language.obj"
	-@erase "$(INTDIR)\Language.sbr"
	-@erase "$(INTDIR)\MathAss.obj"
	-@erase "$(INTDIR)\MathAss.sbr"
	-@erase "$(INTDIR)\MathProc.obj"
	-@erase "$(INTDIR)\MathProc.sbr"
	-@erase "$(INTDIR)\Message.obj"
	-@erase "$(INTDIR)\Message.sbr"
	-@erase "$(INTDIR)\mzone.obj"
	-@erase "$(INTDIR)\mzone.pch"
	-@erase "$(INTDIR)\mzone.sbr"
	-@erase "$(INTDIR)\Plug_In.obj"
	-@erase "$(INTDIR)\Plug_In.sbr"
	-@erase "$(INTDIR)\Program.obj"
	-@erase "$(INTDIR)\Program.sbr"
	-@erase "$(INTDIR)\SpeedTest.obj"
	-@erase "$(INTDIR)\SpeedTest.sbr"
	-@erase "$(INTDIR)\Stat.obj"
	-@erase "$(INTDIR)\Stat.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mzone.bsc"
	-@erase "$(OUTDIR)\mzone.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mzone.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mzone.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Calculate.sbr" \
	"$(INTDIR)\Convert.sbr" \
	"$(INTDIR)\Document.sbr" \
	"$(INTDIR)\Factorial.sbr" \
	"$(INTDIR)\Input.sbr" \
	"$(INTDIR)\Language.sbr" \
	"$(INTDIR)\MathAss.sbr" \
	"$(INTDIR)\MathProc.sbr" \
	"$(INTDIR)\Message.sbr" \
	"$(INTDIR)\Plug_In.sbr" \
	"$(INTDIR)\Program.sbr" \
	"$(INTDIR)\SpeedTest.sbr" \
	"$(INTDIR)\Stat.sbr" \
	"$(INTDIR)\mzone.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\mzone.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\mzone.pdb" /machine:I386 /out:"$(OUTDIR)\mzone.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Calculate.obj" \
	"$(INTDIR)\Convert.obj" \
	"$(INTDIR)\Document.obj" \
	"$(INTDIR)\Factorial.obj" \
	"$(INTDIR)\Input.obj" \
	"$(INTDIR)\Language.obj" \
	"$(INTDIR)\MathAss.obj" \
	"$(INTDIR)\MathProc.obj" \
	"$(INTDIR)\Message.obj" \
	"$(INTDIR)\Plug_In.obj" \
	"$(INTDIR)\Program.obj" \
	"$(INTDIR)\SpeedTest.obj" \
	"$(INTDIR)\Stat.obj" \
	"$(INTDIR)\mzone.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\mzone.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mzone.exe"


CLEAN :
	-@erase "$(INTDIR)\Calculate.obj"
	-@erase "$(INTDIR)\Convert.obj"
	-@erase "$(INTDIR)\Document.obj"
	-@erase "$(INTDIR)\Factorial.obj"
	-@erase "$(INTDIR)\Input.obj"
	-@erase "$(INTDIR)\Language.obj"
	-@erase "$(INTDIR)\MathAss.obj"
	-@erase "$(INTDIR)\MathProc.obj"
	-@erase "$(INTDIR)\Message.obj"
	-@erase "$(INTDIR)\mzone.obj"
	-@erase "$(INTDIR)\mzone.pch"
	-@erase "$(INTDIR)\Plug_In.obj"
	-@erase "$(INTDIR)\Program.obj"
	-@erase "$(INTDIR)\SpeedTest.obj"
	-@erase "$(INTDIR)\Stat.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mzone.exe"
	-@erase "$(OUTDIR)\mzone.ilk"
	-@erase "$(OUTDIR)\mzone.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\mzone.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mzone.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\mzone.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mzone.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Calculate.obj" \
	"$(INTDIR)\Convert.obj" \
	"$(INTDIR)\Document.obj" \
	"$(INTDIR)\Factorial.obj" \
	"$(INTDIR)\Input.obj" \
	"$(INTDIR)\Language.obj" \
	"$(INTDIR)\MathAss.obj" \
	"$(INTDIR)\MathProc.obj" \
	"$(INTDIR)\Message.obj" \
	"$(INTDIR)\Plug_In.obj" \
	"$(INTDIR)\Program.obj" \
	"$(INTDIR)\SpeedTest.obj" \
	"$(INTDIR)\Stat.obj" \
	"$(INTDIR)\mzone.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\mzone.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mzone.dep")
!INCLUDE "mzone.dep"
!ELSE 
!MESSAGE Warning: cannot find "mzone.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mzone - Win32 Release" || "$(CFG)" == "mzone - Win32 Debug"
SOURCE=.\Calculate.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Calculate.obj"	"$(INTDIR)\Calculate.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Calculate.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Convert.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Convert.obj"	"$(INTDIR)\Convert.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Convert.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Document.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Document.obj"	"$(INTDIR)\Document.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Document.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Factorial.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Factorial.obj"	"$(INTDIR)\Factorial.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Factorial.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Input.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Input.obj"	"$(INTDIR)\Input.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Input.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Language.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Language.obj"	"$(INTDIR)\Language.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Language.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\MathAss.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\MathAss.obj"	"$(INTDIR)\MathAss.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\MathAss.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\MathProc.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\MathProc.obj"	"$(INTDIR)\MathProc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\MathProc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Message.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Message.obj"	"$(INTDIR)\Message.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Message.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Plug_In.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Plug_In.obj"	"$(INTDIR)\Plug_In.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Plug_In.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Program.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Program.obj"	"$(INTDIR)\Program.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Program.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\SpeedTest.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\SpeedTest.obj"	"$(INTDIR)\SpeedTest.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\SpeedTest.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\Stat.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\Stat.obj"	"$(INTDIR)\Stat.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\Stat.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\mzone.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"


"$(INTDIR)\mzone.obj"	"$(INTDIR)\mzone.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"


"$(INTDIR)\mzone.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mzone.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "mzone - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mzone.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\mzone.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mzone - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\mzone.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mzone.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

