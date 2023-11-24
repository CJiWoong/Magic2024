# Name of the installer
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
Outfile "MagicSetup_2.7(2019MWin64).exe"

# Default section
Section

# Execute MagicSetup_2.6(2019Win64).exe
ExecWait '"MagicSetup_2.6(2019Win64).exe"'

# Execute MagicRegister.exe
ExecWait '"MagicRegister.exe"'

DetailPrint "Copying magic.cuix to C:\Program Files\Magic"
SetOutPath "C:\Program Files\Magic"
File /r "magic.cuix"
DetailPrint "Copy completed"

SectionEnd
